/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * /Claims/loader/table_parquet_writer.h
 *
 *  Created on: Dec 9, 2017
 *      Author: zzh
 *       Email: 358088534@qq.com
 *
 * Description:
 *
 */
#include <string>
#include <vector>
#include "snappy.h"
#include "./table_parquet_writer.h"
#include "../common/error_no.h"
#include "../common/error_define.h"
using namespace claims::common;
namespace claims {
namespace loader {
class BufferBuilder {
 public:
  BufferBuilder(uint8_t* dst_buffer, int dst_len)
      : buffer_(dst_buffer), capacity_(dst_len), size_(0) {}

  BufferBuilder(char* dst_buffer, int dst_len)
      : buffer_(reinterpret_cast<uint8_t*>(dst_buffer)),
        capacity_(dst_len),
        size_(0) {}

  inline void Append(const void* buffer, int len) __attribute__((nonnull)) {
    //    DCHECK_LE(size_ + len, capacity_);
    memcpy(buffer_ + size_, buffer, len);
    size_ += len;
  }

  template <typename T>
  inline void Append(const T& v) {
    Append(&v, sizeof(T));
  }

  int capacity() const { return capacity_; }
  int size() const { return size_; }

 private:
  uint8_t* buffer_;
  int capacity_;
  int size_;
};
const parquet::Type::type GINGKO_TO_PARQUET_TYPES[] = {
    parquet::Type::INT32,                 // Small_int
    parquet::Type::INT32,                 // Int
    parquet::Type::INT64,                 // Unsigned_long
    parquet::Type::FLOAT,                 // Float
    parquet::Type::DOUBLE,                // Double
    parquet::Type::BYTE_ARRAY,            // String, varchar
    parquet::Type::BYTE_ARRAY,            // Date
    parquet::Type::BYTE_ARRAY,            // Time
    parquet::Type::BYTE_ARRAY,            // DateTime
    parquet::Type::FIXED_LEN_BYTE_ARRAY,  // Decimal
    parquet::Type::INT32,                 // BOOL
    parquet::Type::INT32,                 // Unsigned_small_int
};

TableParquetWriter::TableParquetWriter(const TableDescriptor* table,
                                       common::FileHandleImp* file_handles_parq)
    : table_(table),
      file_handles_parq_(file_handles_parq),
      thrift_serializer_(new ThriftSerializer(true, 1024)),
      current_row_group_(nullptr),
      row_count_(0),
      file_pos_(0),
      meta_length_(0),
      file_size_estimate_(0),
      mem_pool_(MEM_POOL_SIZE),
      schema_(table_->getSchema()) {
  WriteFileHeader();
  Init();
  AddRowGroup();
}
TableParquetWriter::~TableParquetWriter() {
  delete thrift_serializer_;
  delete schema_;
  mem_pool_.purge_memory();
  file_metadata_.row_groups.clear();
  for (auto it : columns_) {
    delete it;
  }
  columns_.clear();
}
RetCode TableParquetWriter::Init() {
  RetCode ret = rSuccess;
  file_metadata_.version = 1;
  file_metadata_.__set_created_by("Gingko");
  int size = table_->getAttributes().size();
  columns_.resize(size);
  for (int i = 0; i < size; i++) {
    BaseColumnWriter* writer = nullptr;
    column_type* attr_type = table_->getAttributes()[i].attrType;
    switch (table_->getAttributes()[i].attrType->type) {
      case data_type::t_int:
      case data_type::t_boolean:
        writer = new ColumnWriter<int>(this, i,
                                       *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_float:
        writer = new ColumnWriter<float>(this, i,
                                         *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_double:
        writer = new ColumnWriter<double>(this, i,
                                          *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_string:
        writer = new ColumnWriter<char*>(this, i,
                                         *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_u_long:
        writer = new ColumnWriter<unsigned long>(
            this, i, *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_date:
        writer = new ColumnWriter<date>(this, i,
                                        *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_time:
        writer = new ColumnWriter<time_duration>(
            this, i, *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_datetime:
        writer = new ColumnWriter<ptime>(this, i,
                                         *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_decimal:
        writer = new ColumnWriter<Decimal>(
            this, i, *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_smallInt:
        writer = new ColumnWriter<short>(this, i,
                                         *table_->getAttributes()[i].attrType);
        break;
      case data_type::t_u_smallInt:
        writer = new ColumnWriter<unsigned short>(
            this, i, *table_->getAttributes()[i].attrType);
        break;
    }
    columns_[i] = writer;
  }
  // create schema tree with a single root
  file_metadata_.schema.resize(columns_.size() + 1);
  file_metadata_.schema[0].__set_num_children(columns_.size());
  file_metadata_.schema[0].name = "schema";
  for (int i = 0; i < size; ++i) {
    parquet::SchemaElement& node = file_metadata_.schema[i + 1];
    column_type* attr_type = table_->getAttributes()[i].attrType;
    node.__set_type(GINGKO_TO_PARQUET_TYPES[attr_type->type]);
    node.__set_repetition_type(FieldRepetitionType::OPTIONAL);
    node.__set_type_length(attr_type->get_length());
  }
  return ret;
}
RetCode TableParquetWriter::AddRowGroup() {
  RetCode ret = rSuccess;
  if (current_row_group_ != nullptr) {
    if ((ret = FlushCurrentRowGroup()) != rSuccess) {
      LOG(ERROR) << " Flush current row group fail" << endl;
      return ret;
    }
  }
  file_metadata_.row_groups.push_back(RowGroup());
  current_row_group_ =
      &file_metadata_.row_groups[file_metadata_.row_groups.size() - 1];
  current_row_group_->columns.resize(columns_.size());
  for (int i = 0; i < columns_.size(); i++) {
    ColumnMetaData metadata;
    metadata.type =
        GINGKO_TO_PARQUET_TYPES[table_->getAttributes()[i].attrType->type];
    // snappy
    metadata.codec = 1;
    current_row_group_->columns[i].__set_meta_data(metadata);
  }

  LOG(INFO) << file_handles_parq_->get_file_name()
            << "   Add rowgroup, the row group size is "
            << file_metadata_.row_groups.size();
  return ret;
}

RetCode TableParquetWriter::Finalize() {
  RetCode ret = rSuccess;
  file_metadata_.num_rows = row_count_;
  if ((ret = FlushCurrentRowGroup()) != rSuccess) {
    LOG(ERROR) << file_handles_parq_->get_file_name()
               << "FLush current row group error in finalize!\n";
    return ret;
  }
  if ((ret = WriteFileFooter()) != rSuccess) {
    LOG(ERROR) << file_handles_parq_->get_file_name()
               << "Write File Footer error in finalize!\n";
    return ret;
  }
  total_file_length_ = file_pos_;
  return ret;
}

RetCode TableParquetWriter::AppendRows(BlockStreamBase* blk) {
  RetCode ret = rSuccess;
  BlockStreamBase::BlockStreamTraverseIterator* tuple_it = NULL;
  tuple_it = blk->createIterator();
  void* tuple = nullptr;
  while ((tuple = tuple_it->nextTuple()) != 0) {
    row_count_++;
    for (int i = 0; i < columns_.size(); i++) {
      void* value = schema_->getColumnAddess(i, tuple);
      if ((ret = columns_[i]->AppendRow(value)) != rSuccess) {
        LOG(ERROR) << "col_writer" << i << "Append Row fail!\n";
        return ret;
      }
    }
  }

  if (file_size_estimate_ > ROW_GROUP_SIZE) {
    if ((ret = FlushCurrentRowGroup()) != rSuccess) {
      LOG(ERROR) << "FLush Row Group!\n";
      return ret;
    }
    if ((ret = AddRowGroup()) != rSuccess) {
      LOG(ERROR) << "Add row group fails!\n";
      return ret;
    }
    file_size_estimate_ = 0;
  }
  delete tuple_it;
  return ret;
}

RetCode TableParquetWriter::WriteFileHeader() {
  RetCode ret = rSuccess;
  if (file_pos_ != 0) {
    LOG(ERROR) << "file_pos must equals 0 when write file header" << endl;
    assert(false);
  }
  ret = file_handles_parq_->AppendNoCompress(PARQUET_VERSION_NUMBER,
                                             sizeof(PARQUET_VERSION_NUMBER));
  file_pos_ += sizeof(PARQUET_VERSION_NUMBER);
  file_size_estimate_ += sizeof(PARQUET_VERSION_NUMBER);
  LOG(INFO) << file_handles_parq_->get_file_name() << "    write file header"
            << endl;
  return ret;
}

RetCode TableParquetWriter::WriteFileFooter() {
  RetCode ret = rSuccess;
  uint32_t file_metadata_len = 0;
  uint8_t* buffer = nullptr;
  meta_start_ = file_pos_;
  if ((ret = thrift_serializer_->Serialize(&file_metadata_, &file_metadata_len,
                                           &buffer)) != rSuccess) {
    LOG(ERROR) << "write file foot serialize error." << endl;
    return ret;
  }
  if ((ret = file_handles_parq_->AppendNoCompress(buffer, file_metadata_len)) !=
      rSuccess) {
    LOG(ERROR) << "write file foot serialize error in append." << endl;
    return ret;
  }
  meta_length_ = file_metadata_len;
  file_pos_ += meta_length_;
  //  file_metadata_.printTo(std::cout);
  if ((ret = file_handles_parq_->AppendNoCompress(
           PARQUET_VERSION_NUMBER, sizeof(PARQUET_VERSION_NUMBER))) !=
      rSuccess) {
    LOG(ERROR) << "write file foot PARQUET_VERSION_NUMBER error." << endl;
    return ret;
  }
  file_pos_ += sizeof(PARQUET_VERSION_NUMBER);
  LOG(INFO) << file_handles_parq_->get_file_name() << "write file footer"
            << endl;
  return ret;
}

RetCode TableParquetWriter::FlushCurrentRowGroup() {
  RetCode ret = rSuccess;
  if (current_row_group_ == nullptr) return rSuccess;
  int size = columns_.size();
  for (int i = 0; i < size; i++) {
    int64_t data_page_offset = 0;
    int64_t dict_page_offset = 0;
    if ((ret = columns_[i]->Flush(&file_pos_, &data_page_offset,
                                  &dict_page_offset)) != rSuccess)
      return ret;
    ColumnChunk& col_chunk = current_row_group_->columns[i];
    ColumnMetaData& col_metadata = col_chunk.meta_data;
    col_metadata.data_page_offset = data_page_offset;
    if (dict_page_offset >= 0) {
      col_metadata.__set_dictionary_page_offset(dict_page_offset);
    }
    BaseColumnWriter* col_writer = columns_[i];
    col_metadata.num_values = col_writer->num_values_;
    col_metadata.total_compressed_size =
        col_writer->total_compressed_byte_size_;
    col_metadata.total_uncompressed_size =
        col_writer->total_uncompressed_byte_size_;
    current_row_group_->total_byte_size +=
        col_writer->total_compressed_byte_size_;
    current_row_group_->num_rows = col_writer->num_values_;
    current_row_group_->columns[i].file_offset = file_pos_;
    col_metadata.encodings.clear();
    for (Encoding::type encoding : col_writer->column_encodings_) {
      col_metadata.encodings.push_back(encoding);
    }
    vector<PageEncodingStats> encoding_stats;
    //    Add dictionary page encoding stats
    for (const auto& entry : col_writer->dict_encoding_stats_) {
      PageEncodingStats dict_enc_stat;
      dict_enc_stat.page_type = PageType::DICTIONARY_PAGE;
      dict_enc_stat.encoding = entry.first;
      dict_enc_stat.count = entry.second;
      encoding_stats.push_back(dict_enc_stat);
    }
    //    Add data page encoding stats
    for (const auto& entry : col_writer->data_encoding_stats_) {
      PageEncodingStats data_enc_stat;
      data_enc_stat.page_type = PageType::DATA_PAGE;
      data_enc_stat.encoding = entry.first;
      data_enc_stat.count = entry.second;
      encoding_stats.push_back(data_enc_stat);
    }
    col_metadata.__set_encoding_stats(encoding_stats);
    col_writer->Reset();
  }
  current_row_group_ = nullptr;
  return ret;
}

template <typename T>
void ColumnWriter<T>::Reset() {
  num_data_pages_ = 0;
  current_page_ = nullptr;
  num_values_ = 0;
  total_compressed_byte_size_ = 0;
  total_uncompressed_byte_size_ = 0;
  // only row_id or t_string type is plain encoding
  //  if (col_index_ == 0 || column_type_.type == 5) {
  current_encoding_ = Encoding::PLAIN;
  next_page_encoding_ = Encoding::PLAIN;
  //  } else {
  //    current_encoding_ = Encoding::PLAIN_DICTIONARY;
  //    next_page_encoding_ = Encoding::PLAIN_DICTIONARY;
  //    delete dict_encoder_;
  //    dict_encoder_ =
  //        new DictEncoder<T>(&mem_pool_for_char_, column_type_.get_length());
  //  }
  column_encodings_.clear();
  dict_encoding_stats_.clear();
  data_encoding_stats_.clear();
}

template <typename T>
RetCode ColumnWriter<T>::AppendRow(void* value) {
  RetCode ret = rSuccess;
  ++num_values_;
  if (current_page_ == nullptr) NewPage();
  while (true) {
    if (ProcessValue(value)) {
      break;  // Succesfully appended, don't need to retry.
    }
    if ((ret = FinalizeCurrentPage()) != rSuccess) {
      LOG(ERROR) << "Append row fail in process value stage!" << endl;
    }
    NewPage();
  }
  ++current_page_->header.data_page_header.num_values;
  return ret;
}
template <typename T>
void ColumnWriter<T>::NewPage() {
  if (num_data_pages_ < pages_.size()) {
    // Reuse an existing page
    current_page_ = &pages_[num_data_pages_++];
    current_page_->header.data_page_header.num_values = 0;
    current_page_->header.compressed_page_size = 0;
    current_page_->header.uncompressed_page_size = 0;
  } else {
    pages_.push_back(DataPage());
    current_page_ = &pages_[num_data_pages_++];
    DataPageHeader header;
    header.num_values = 0;
    current_page_->header.__set_data_page_header(header);
  }
  current_encoding_ = next_page_encoding_;
  current_page_->finalized = false;
}

template <typename T>
bool ColumnWriter<T>::ProcessValue(void* value) {
  if (current_encoding_ == Encoding::PLAIN_DICTIONARY) {
    int64_t bytes_needed = 0;
    if (num_values_since_dict_size_check_ >=
        DICTIONARY_DATA_PAGE_SIZE_CHECK_PERIOD) {
      num_values_since_dict_size_check_ = 0;
      if (dict_encoder_->EstimatedDataEncodedSize() >= page_size_) return false;
    }
    ++num_values_since_dict_size_check_;
    bytes_needed = dict_encoder_->Put(value);
    if (bytes_needed < 0) {
      next_page_encoding_ = Encoding::PLAIN;
      return false;
    } else {
      parent_->file_size_estimate_ += bytes_needed;
      return true;
    }
  } else if (current_encoding_ == Encoding::PLAIN) {
    if (current_page_->header.uncompressed_page_size +
            column_type_.get_length() >
        page_size_) {
      return false;
    } else {
      uint8_t* dst_ptr =
          values_buffer_ + current_page_->header.uncompressed_page_size;
      column_type_.operate->assignment(value, dst_ptr);
      current_page_->header.uncompressed_page_size += column_type_.get_length();
      return true;
    }
  }
}

template <typename T>
RetCode ColumnWriter<T>::FinalizeCurrentPage() {
  RetCode ret = rSuccess;
  if (current_page_ == nullptr) {
    LOG(ERROR) << "current page is null , page num is  " << num_data_pages_
               << endl;
    ret = rInvalidNullData;
    return ret;
  }
  if (current_page_->finalized == true) return ret;
  if (current_encoding_ == Encoding::PLAIN_DICTIONARY) WriteDictDataPage();

  PageHeader& header = current_page_->header;
  column_encodings_.insert(header.data_page_header.encoding);

  ++data_encoding_stats_[header.data_page_header.encoding];

  uint8_t* uncompressed_data = values_buffer_;
  int64_t max_compressed_size =
      snappy::MaxCompressedLength(header.uncompressed_page_size);
  // data is lager than mem pool block
  current_page_->data = malloc(max_compressed_size);
  if (current_page_->data == nullptr) {
    LOG(ERROR) << "no memory, at finalize current page stage" << endl;
    ret = rMemoryAllocationFailed;
    return ret;
  }
  size_t output_length = 0;
  snappy::RawCompress(reinterpret_cast<const char*>(uncompressed_data),
                      static_cast<size_t>(header.uncompressed_page_size),
                      reinterpret_cast<char*>(current_page_->data),
                      &output_length);
  header.compressed_page_size = output_length;
  uint8_t* header_buffer;
  uint32_t header_len = 0;
  ret = parent_->thrift_serializer_->Serialize(&current_page_->header,
                                               &header_len, &header_buffer);
  if (ret != 0) {
    LOG(ERROR) << "SerializeError, at finalize current page stage" << endl;
    return rSerializeError;
  }
  current_page_->finalized = true;
  total_compressed_byte_size_ += header_len + header.compressed_page_size;
  total_uncompressed_byte_size_ += header_len + header.uncompressed_page_size;
  parent_->file_size_estimate_ += header_len + header.compressed_page_size;
  return ret;
}

template <typename T>
RetCode ColumnWriter<T>::Flush(int64_t* file_pos, int64_t* first_data_page,
                               int64_t* first_dictionary_page) {
  if (current_page_ == nullptr) {
    // This column/file is empty
    *first_data_page = *file_pos;
    *first_dictionary_page = -1;
    return rSuccess;
  }
  RetCode ret = rSuccess;
  RetCode subret = rSuccess;
  ret = FinalizeCurrentPage();
  if (ret != rSuccess) {
    LOG(ERROR) << "col_index_ :" << col_index_
               << "flush error at finalize current page" << endl;
    return ret;
  }
  *first_dictionary_page = -1;
  if (dict_encoder_ != nullptr) {
    *first_dictionary_page = *file_pos;
    // Write dictionary page header
    DictionaryPageHeader dict_header;
    dict_header.num_values = dict_encoder_->num_entries();
    dict_header.encoding = Encoding::PLAIN_DICTIONARY;
    ++dict_encoding_stats_[dict_header.encoding];

    PageHeader header;
    header.type = PageType::DICTIONARY_PAGE;
    header.uncompressed_page_size = dict_encoder_->dict_encoded_size();
    header.__set_dictionary_page_header(dict_header);
    int size =
        header.uncompressed_page_size / TableParquetWriter::MEM_POOL_SIZE + 1;
    uint8_t* dict_buffer = nullptr;
    if (size > 1) {
      dict_buffer = parent_->mem_pool_.ordered_malloc(size);
    } else {
      dict_buffer = parent_->mem_pool_.malloc();
    }
    if (dict_buffer == nullptr) {
      LOG(ERROR) << "no memory, at finalize current page stage" << endl;
      ret = rMemoryAllocationFailed;
      return ret;
    }
    dict_encoder_->WriteDict(dict_buffer);

    int64_t max_compressed_size =
        snappy::MaxCompressedLength(header.uncompressed_page_size);
    int cmp_size =
        header.uncompressed_page_size / TableParquetWriter::MEM_POOL_SIZE + 1;
    uint8_t* compressed_data = nullptr;
    if (cmp_size > 1) {
      compressed_data = parent_->mem_pool_.ordered_malloc(size);
    } else {
      compressed_data = parent_->mem_pool_.malloc();
    }
    uint64_t length = 0;
    snappy::RawCompress(reinterpret_cast<const char*>(dict_buffer),
                        static_cast<size_t>(header.uncompressed_page_size),
                        reinterpret_cast<char*>(compressed_data), &length);
    header.compressed_page_size = length;
    // free tmp dic memory
    if (size > 1) {
      parent_->mem_pool_.ordered_free(dict_buffer, size);
    } else {
      parent_->mem_pool_.free(dict_buffer);
    }

    uint8_t* header_buffer;
    uint32_t header_len;
    parent_->thrift_serializer_->Serialize(&header, &header_len,
                                           &header_buffer);
    parent_->file_handles_parq_->AppendNoCompress(header_buffer, header_len);
    *file_pos += header_len;
    total_compressed_byte_size_ += header_len;
    total_uncompressed_byte_size_ += header_len;

    parent_->file_handles_parq_->AppendNoCompress(compressed_data,
                                                  header.compressed_page_size);
    if (cmp_size > 1) {
      parent_->mem_pool_.ordered_free(compressed_data, size);
    } else {
      parent_->mem_pool_.free(compressed_data);
    }
    *file_pos += header.compressed_page_size;
    total_compressed_byte_size_ += header.compressed_page_size;
    total_uncompressed_byte_size_ += header.uncompressed_page_size;
  }
  *first_data_page = *file_pos;

  for (int i = 0; i < num_data_pages_; ++i) {
    DataPage& page = pages_[i];
    if (page.header.data_page_header.num_values == 0) {
      // Skip empty pages
      continue;
    }
    uint8_t* buffer = nullptr;
    uint32_t len = 0;
    parent_->thrift_serializer_->Serialize(&page.header, &len, &buffer);
    parent_->file_handles_parq_->AppendNoCompress(buffer, len);
    *file_pos += len;

    subret = parent_->file_handles_parq_->AppendNoCompress(
        page.data, page.header.compressed_page_size);
    free(page.data);
    if (subret != rSuccess) {
      ret = subret;
      LOG(ERROR) << "col_index_ :" << col_index_ << "flush error" << endl;
      return ret;
    }

    *file_pos += page.header.compressed_page_size;
  }
  return ret;
}

template <typename T>
void ColumnWriter<T>::WriteDictDataPage() {
  DCHECK(dict_encoder_ != nullptr);
  DCHECK_EQ(current_page_->header.uncompressed_page_size, 0);
  int len = dict_encoder_->WriteData(values_buffer_, values_buffer_len_);
  while (len < 0) {
    values_buffer_len_ *= 2;
    value_buffer_time_ *= 2;
    values_buffer_ = parent_->mem_pool_.ordered_malloc(value_buffer_time_);
    if (values_buffer_ == 0) {
      LOG(ERROR) << "no memory in WriteDictDataPage stage \n";
      assert(false);
    }
    len = dict_encoder_->WriteData(values_buffer_, values_buffer_len_);
  }
  dict_encoder_->ClearIndices();
  current_page_->header.uncompressed_page_size = len;
  current_page_->header.data_page_header.encoding = 2;
}

}  // namespace loader
}  // namespace claims
