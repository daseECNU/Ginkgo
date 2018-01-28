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
#ifndef LOADER_TABLE_PARQUET_WRITER_H_
#define LOADER_TABLE_PARQUET_WRITER_H_

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/pool/pool.hpp>

#include <string>
#include <vector>
#include "../common/data_type.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../utility/dict_encoding.h"
#include "../common/Block/BlockStream.h"
#include "../common/parquet_types.h"
#include "../catalog/table.h"
#include "../common/error_define.h"
#include "../common/error_no.h"
#include "../utility/thrift_util.h"
#include "snappy.h"

using namespace claims::common;

using std::string;
using claims::catalog::TableDescriptor;
using parquet::PageHeader;
using parquet::DataPageHeader;
using parquet::Encoding;
using parquet::FieldRepetitionType;
using parquet::RowGroup;
using parquet::ColumnMetaData;
using parquet::ColumnChunk;
using parquet::DictionaryPageHeader;
using parquet::PageType;
using parquet::PageEncodingStats;
using boost::pool;
enum PARQUET_CODEC { NONE, SNAPPY, GZIP, LZO };
namespace claims {
namespace loader {
using claims::catalog::TableDescriptor;
template <typename T>
class ColumnWriter;
class BaseColumnWriter;
const uint8_t PARQUET_VERSION_NUMBER[4] = {'P', 'A', 'R', '1'};
const uint32_t PARQUET_CURRENT_VERSION = 1;
class TableParquetWriter {
  template <typename T>
  friend class ColumnWriter;
  friend class BaseColumnWriter;

 public:
  TableParquetWriter(const TableDescriptor* table,
                     common::FileHandleImp* file_handles_parq);
  ~TableParquetWriter();
  RetCode Init();
  RetCode Finalize();
  RetCode AppendRows(BlockStreamBase* blk);
  int64_t GetRowCount() { return row_count_; }
  // file position means metadata start postition
  int64_t GetMetaStartPos() { return meta_start_; }
  int64_t GetmetaPos() { return meta_length_; }
  int64_t GetFileLength() { return total_file_length_; }

 private:
  /// Default data page size. In bytes.
  static const int DEFAULT_DATA_PAGE_SIZE = 64 * 1024;
  /// Default hdfs block size. In bytes.
  //  static const int HDFS_BLOCK_SIZE = 256 * 1024 * 1024;
  static const int HDFS_BLOCK_SIZE = 64 * 1024 * 1024;
  /// Default row group size.  In bytes.
  static const int ROW_GROUP_SIZE = HDFS_BLOCK_SIZE;

  /// Minimum file size.  If the configured size is less, fail.
  static const int HDFS_MIN_FILE_SIZE = 8 * 1024 * 1024;
  static const int MAX_COLUMN_STATS_SIZE = 4 * 1024;
  static const int MEM_POOL_SIZE = 100000;
  RetCode WriteFileHeader();
  RetCode WriteFileFooter();
  RetCode FlushCurrentRowGroup();
  // Adds a row group to the metadata and updates current_row_group_ to the
  // new row group.  current_row_group_ will be flushed.
  RetCode AddRowGroup();

  /// The current row group being written to.
  parquet::RowGroup* current_row_group_;
  vector<BaseColumnWriter*> columns_;
  parquet::FileMetaData file_metadata_;
  TableDescriptor* table_;
  common::FileHandleImp* file_handles_parq_;
  ThriftSerializer* thrift_serializer_;
  int64_t file_size_estimate_;
  int64_t row_count_;
  int64_t file_pos_;
  int64_t meta_length_;
  int64_t meta_start_;
  int64_t total_file_length_;
  pool<> mem_pool_;
  Schema* schema_;
};
class BaseColumnWriter {
 public:
  BaseColumnWriter()
      : values_buffer_len_(TableParquetWriter::DEFAULT_DATA_PAGE_SIZE) {}
  virtual RetCode AppendRow(void* value) = 0;
  virtual RetCode Flush(int64_t* file_pos, int64_t* first_data_page,
                        int64_t* first_dictionary_page) = 0;
  virtual ~BaseColumnWriter() {}
  virtual RetCode FinalizeCurrentPage() = 0;
  virtual void NewPage() = 0;
  virtual void Reset() = 0;
  virtual bool ProcessValue(void* value) = 0;
  int64_t num_values_;
  int64_t total_compressed_byte_size_;
  int64_t total_uncompressed_byte_size_;

  int values_buffer_len_;
  boost::unordered_set<Encoding::type> column_encodings_;
  boost::unordered_map<Encoding::type, int> dict_encoding_stats_;
  boost::unordered_map<Encoding::type, int> data_encoding_stats_;
};
template <typename T>
class ColumnWriter : public BaseColumnWriter {
 public:
  ColumnWriter(TableParquetWriter* parent, int col_index, column_type coltype)
      : BaseColumnWriter(),
        parent_(parent),
        page_size_(TableParquetWriter::DEFAULT_DATA_PAGE_SIZE),
        col_index_(col_index),
        dict_encoder_(nullptr),
        num_data_pages_(0),
        value_buffer_time_(1),
        column_type_(coltype),
        mem_pool_for_char_(column_type_.get_length()),
        num_values_since_dict_size_check_(0) {
    values_buffer_ = parent_->mem_pool_.malloc();
    //    if (col_index_ != 0 & column_type_.type != 5) {
    //      dict_encoder_ =
    //          new DictEncoder<T>(&mem_pool_for_char_,
    //          column_type_.get_length());
    //    }
    Reset();
  }
  ~ColumnWriter() {
    pages_.clear();
    dict_encoding_stats_.clear();
    data_encoding_stats_.clear();
    mem_pool_for_char_.purge_memory();
    if (dict_encoder_ != nullptr) dict_encoder_->ClearIndices();
  }
  RetCode AppendRow(void* value);
  RetCode Flush(int64_t* file_pos, int64_t* first_data_page,
                int64_t* first_dictionary_page);
  RetCode FinalizeCurrentPage();
  void NewPage();
  void Reset();
  bool ProcessValue(void* value);
  void WriteDictDataPage();

 private:
  struct DataPage {
    PageHeader header;
    int num_def_bytes;
    uint8_t* data;
    bool finalized;
  };
  static const int DICTIONARY_DATA_PAGE_SIZE_CHECK_PERIOD = 100;
  vector<DataPage> pages_;
  int num_data_pages_;
  int64_t page_size_;
  DataPage* current_page_;
  uint8_t* values_buffer_;
  DictEncoder<T>* dict_encoder_;

  Encoding::type current_encoding_;
  Encoding::type next_page_encoding_;

  column_type column_type_;
  int col_index_;
  int value_buffer_time_;
  TableParquetWriter* parent_;
  int num_values_since_dict_size_check_;
  pool<> mem_pool_for_char_;
};
} /* namespace loader */
} /* namespace claims */
#endif  // LOADER_TABLE_PARQUET_WRITER_H_
