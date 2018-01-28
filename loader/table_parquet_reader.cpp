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
 * /Claims/loader/table_parquet_reader.cpp
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
#include <algorithm>
#include "./table_parquet_reader.h"
#include "../common/error_no.h"
#include "../common/error_define.h"
#include "../utility/thrift_util.h"
#include "../common/file_handle/hdfs_connector.h"
#include "snappy.h"
using claims::common::rSuccess;

namespace claims {
namespace loader {

TableParquetReader* TableParquetReader::table_parq_reader_ = NULL;
int TableParquetReader::LoadFromParq(const ChunkID& chunk_id, void* const& desc,
                                     const unsigned& length) {
  RetCode ret = rSuccess;
  uint64_t totoal_read = 0, block_read = 0;
  int partkey = 0;
  ParqMetaInfo meta_info;
  // read metadata
  if (meta_info_.find(chunk_id.partition_id) == meta_info_.end()) {
    cout << " can't find metadata !!\n";
    assert(false);
  } else {
    meta_info = meta_info_[chunk_id.partition_id];
    if (metadata_.find(meta_info.file_name_) == metadata_.end()) {
      int cur = file_cur_[meta_info.file_name_];
      if ((ret = readMetaData(meta_info.file_name_, meta_info.meta_length_[cur],
                              meta_info.meta_start_[cur])) != rSuccess) {
        return totoal_read;
      }
      // inital mem_pool when read Metadata
      if (pools_.find(meta_info.file_name_) == pools_.end()) {
        pools_[meta_info.file_name_] = new pool<>(MEM_POOL_SIZE);
      }
    }
  }
  // read rowgroup data, if necessary
  string filename = meta_info.file_name_;
  if (has_data_.find(filename) == has_data_.end()) {
    has_data_[filename] = false;
    metadata_[filename].second = 0;
    if ((ret = readRowGroup(filename, meta_info)) != rSuccess) {
      return totoal_read;
    }
  } else if (has_data_[filename] == false) {
    if ((ret = readRowGroup(filename, meta_info)) != rSuccess) {
      return totoal_read;
    }
  }
  vector<ParquetColumnReader*>& readers = column_readers_[meta_info.file_name_];
  int tuplesize = 0;
  for (auto it : readers) {
    tuplesize += it->GetFixLen();
  }
  stringstream* sstr = new stringstream();
  size_t reader_size = readers.size();
  char* block_ptr = nullptr;
  unsigned tuple_count;
  string blockdata;
  while (totoal_read < length) {
    blockdata.clear();
    blockdata.resize(BLOCK_SIZE);
    block_ptr = const_cast<char*>(blockdata.c_str());
    while ((block_read + tuplesize) < (BLOCK_SIZE - sizeof(unsigned))) {
      for (int i = 0; i < reader_size; i++) {
        if (readers[i]->ReadSlot(block_ptr)) {
          block_ptr += readers[i]->GetFixLen();
          block_read += readers[i]->GetFixLen();
        } else {
          has_data_[filename] = false;
          if ((ret = readRowGroup(filename, meta_info)) == rSuccess) {
            i--;
            continue;
          } else {
            totoal_read += BLOCK_SIZE;
            tuple_count = block_read / tuplesize;
            block_ptr = const_cast<char*>(blockdata.c_str()) +
                        (BLOCK_SIZE - sizeof(unsigned));
            *(unsigned*)block_ptr = tuple_count;
            *sstr << blockdata;
            string final = sstr->str();
            final.copy((char*)desc, totoal_read, 0);
            delete sstr;
            return totoal_read;
          }
        }
      }
    }
    tuple_count = block_read / tuplesize;
    block_ptr =
        const_cast<char*>(blockdata.c_str()) + (BLOCK_SIZE - sizeof(unsigned));
    *(unsigned*)block_ptr = tuple_count;
    *sstr << blockdata;
    totoal_read += BLOCK_SIZE;
    block_read = 0;
  }
  string final = sstr->str();
  delete sstr;
  final.copy((char*)desc, totoal_read, 0);
  return totoal_read;
}
void TableParquetReader::loadDataPage(string name, const PageHeader& header,
                                      const uint8_t* page, uint8_t*& data,
                                      bool is_dict) {
  if (is_dict) {
    data = malloc(header.compressed_page_size);
    cout << "malloc data " << header.compressed_page_size << endl;
  } else {
    data = pools_[name]->malloc();
  }
  if (data == nullptr) {
    cerr << " memory pool malloc fail";
    assert(false);
  }
  size_t compressed_page_size = header.compressed_page_size;
  if (!snappy::RawUncompress(reinterpret_cast<const char*>(page),
                             compressed_page_size,
                             reinterpret_cast<char*>(data))) {
    cout << "Uncompress fail, compressed page size is " << compressed_page_size
         << endl;
  }
}

TableParquetReader* TableParquetReader::getInstance() {
  if (table_parq_reader_ == NULL) {
    table_parq_reader_ = new TableParquetReader();
  }
  return table_parq_reader_;
}
int TableParquetReader::readRowGroup(string file_name,
                                     const ParqMetaInfo& Pmi) {
  RetCode ret = rSuccess;
  int idx = metadata_[file_name].second;
  if (idx == metadata_[file_name].first.row_groups.size()) {
    // read next file
    if (file_cur_[file_name] < file_total_[file_name] - 1) {
      file_cur_[file_name]++;
      int cur = file_cur_[file_name];
      uint64_t meta_start = Pmi.meta_start_[cur];
      for (int i = 0; i < cur; i++) {
        meta_start += Pmi.file_length_[i];
      }
      readMetaData(file_name, Pmi.meta_length_[cur], meta_start);
      return readRowGroup(file_name, Pmi);
    } else {
      return -1;
    }
  }
  uint64_t common_offset = 0;
  for (int i = 0; i < file_cur_[file_name]; i++) {
    common_offset += Pmi.file_length_[i];
  }
  pools_[file_name]->release_memory();

  RowGroup& rg = metadata_[file_name].first.row_groups[idx];
  vector<ParquetColumnReader*>& readers = column_readers_[file_name];
  for (auto it : readers) {
    it->num_of_page_ = 0;
    prepareDataForReader(it, rg.columns[it->col_id_], common_offset, file_name);
  }
  metadata_[file_name].second++;
  has_data_[file_name] = true;
  return rSuccess;
}
int TableParquetReader::readMetaData(string file_name, uint32_t meta_len,
                                     uint64_t meta_start) {
  if (Config::local_disk_mode) {
    // disk mode
    int fd = FileOpen(file_name.c_str(), O_RDONLY);
    if (fd == -1) {
      LOG(ERROR) << "rLoadFromDiskOpenFailed ----" << file_name;
      return 1;
    } else {
      LOG(INFO) << "open success -----" << file_name << "----- from  Disk.";
      lseek(fd, meta_start, SEEK_SET);
      vector<uint8_t> buffer_vector(meta_len);
      uint8_t* buffer = buffer_vector.data();
      size_t bytes_read = read(fd, buffer, meta_len);
      DeserializeThriftMsg(buffer, &meta_len, true,
                           &metadata_[file_name].first);
      metadata_[file_name].second = 0;
      return rSuccess;
    }
  } else {
    hdfsFS fs = HdfsConnector::Instance();
    hdfsFile readFile = hdfsOpenFile(fs, file_name.c_str(), O_RDONLY, 0, 0, 0);
    if (!readFile) {
      LOG(ERROR) << "rLoadFromHdfsOpenFailed ----" << file_name;
      hdfsDisconnect(fs);
      return 1;
    } else {
      vector<uint8_t> buffer_vector(meta_len);
      uint8_t* buffer = buffer_vector.data();
      LOG(INFO) << "open success -----" << file_name << "----- from  Hdfs.";
      hdfsPread(fs, readFile, meta_start, static_cast<void*>(buffer), meta_len);
      DeserializeThriftMsg(buffer, &meta_len, true,
                           &metadata_[file_name].first);
      metadata_[file_name].second = 0;
      return rSuccess;
    }
  }
}
void TableParquetReader::prepareDataForReader(ParquetColumnReader* reader,
                                              const ColumnChunk& column_chunk,
                                              uint64_t common_offset,
                                              string file_name) {
  vector<uint8_t> chunk_data;
  chunk_data.resize(column_chunk.meta_data.total_compressed_size);
  uint8_t* data_ptr = chunk_data.data();
  int first_page_offset = column_chunk.meta_data.data_page_offset;
  if (column_chunk.meta_data.__isset.dictionary_page_offset) {
    first_page_offset = std::min(
        first_page_offset,
        static_cast<int>(column_chunk.meta_data.dictionary_page_offset));
  }
  uint64_t start = common_offset + first_page_offset;
  if (Config::local_disk_mode) {
    int fd = FileOpen(file_name.c_str(), O_RDONLY);
    if (fd == -1) {
      LOG(ERROR) << "rLoadFromDiskOpenFailed ----" << file_name
                 << "in readRowGroup.";
      return -1;
    } else {
      LOG(INFO) << "open success -----" << file_name
                << "----- from  Disk. in in readRowGroup.";
    }
    // seek to row group
    lseek(fd, start, SEEK_SET);
    read(fd, data_ptr, column_chunk.meta_data.total_compressed_size);
  } else {
    hdfsFS fs = HdfsConnector::Instance();
    hdfsFile readFile = hdfsOpenFile(fs, file_name.c_str(), O_RDONLY, 0, 0, 0);
    if (!readFile) {
      LOG(ERROR) << "rLoadFromHdfsOpenFailed ----" << file_name;
      hdfsDisconnect(fs);
      return -1;
    } else {
      hdfsPread(fs, readFile, start, static_cast<void*>(data_ptr),
                column_chunk.meta_data.total_compressed_size);
    }
  }
  uint8_t* data_start = chunk_data.data();
  uint8_t* data_end = data_start + column_chunk.meta_data.total_compressed_size;
  uint8_t* page_data = nullptr;
  while (data_start < data_end) {
    uint32_t header_size = 1024;
    PageHeader header;
    int ret = DeserializeThriftMsg(data_start, &header_size, true, &header);
    if (ret == -1) {
      cout << "paser error\n";
    }
    data_start += header_size;
    if (header.__isset.dictionary_page_header) {
      loadDataPage(file_name, header, data_start, page_data, true);
      reader->ResetDictDecoder(page_data, header.uncompressed_page_size);
    } else if (header.__isset.data_page_header) {
      loadDataPage(file_name, header, data_start, page_data, false);
      if (reader->num_of_page_ < reader->data_slices.size()) {
        DataSlice& cur = reader->data_slices[reader->num_of_page_++];
        cur.header_ = header;
        cur.page_data_ = page_data;
      } else {
        reader->data_slices.push_back(DataSlice());
        DataSlice& cur = reader->data_slices[reader->num_of_page_++];
        cur.header_ = header;
        cur.page_data_ = page_data;
      }
    }
    data_start += header.compressed_page_size;
  }
  reader->cur_page_ = 0;
  reader->data_ = reader->data_slices[0].page_data_;
  reader->data_end_ =
      reader->data_ + reader->data_slices[0].header_.uncompressed_page_size;
  reader->page_encoding_ =
      reader->data_slices[0].header_.data_page_header.encoding;
}
} /* namespace loader */
} /* namespace claims */
