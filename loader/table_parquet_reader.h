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
 * /Claims/loader/table_parquet_reader.h
 *
 *  Created on: Dec 9, 2017
 *      Author: zzh
 *       Email: 358088534@qq.com
 *
 * Description:
 *
 */

#ifndef LOADER_TABLE_PARQUET_READER_H_
#define LOADER_TABLE_PARQUET_READER_H_
#include <boost/unordered_map.hpp>
#include <boost/pool/pool.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

#include "../common/parquet_types.h"
#include "../Config.h"

#include "../common/error_define.h"
#include "../common/error_no.h"
#include "../common/Logging.h"
#include "../utility/thrift_util.h"
#include "../utility/dict_encoding.h"
#include "../common/ids.h"

using std::string;
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
using parquet::FileMetaData;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using boost::pool;
namespace claims {
namespace loader {
class ParquetColumnReader;
template <typename T>
class ColumnReader;
struct ParqMetaInfo {
  string file_name_;
  vector<uint32_t> meta_length_;
  vector<uint64_t> meta_start_;
  vector<uint64_t> file_length_;
};
struct DataSlice {
  uint8_t* page_data_;
  PageHeader header_;
  int mem_size_;
};
class TableParquetReader {
 public:
  TableParquetReader() {}
  ~TableParquetReader() {}  // data_.clear();
  int LoadFromParq(const ChunkID& chunk_id, void* const& desc,
                   const unsigned& length);
  int readMetaData(string file_name, uint32_t meta_len, uint64_t meta_start);
  int readRowGroup(string file_name, const ParqMetaInfo& Pmi);
  static TableParquetReader* getInstance();

  boost::unordered_map<PartitionID, ParqMetaInfo> meta_info_;
  boost::unordered_map<string, vector<ParquetColumnReader*>> column_readers_;
  static const int MEM_POOL_SIZE = 70000;
  boost::unordered_map<string, pool<>*> pools_;
  boost::unordered_map<string, bool> has_data_;
  /// file name to metadata and read rowGroup id
  boost::unordered_map<string, pair<FileMetaData, int>> metadata_;
  boost::unordered_map<string, int> file_cur_;
  boost::unordered_map<string, int> file_total_;

 private:
  string GetFileName(const ChunkID& chunk_id, int& partkey_index);
  static TableParquetReader* table_parq_reader_;
  void prepareDataForReader(ParquetColumnReader* reader,
                            const ColumnChunk& column_chunk,
                            uint64_t common_offset, string file_name);
  // file name to column_reader
  void loadDataPage(string name, const PageHeader& header, const uint8_t* page,
                    uint8_t*& data, bool is_dict);
  // file name to RowGroupdata
  boost::unordered_map<string, vector<uint8_t>> data_;
};

class ParquetColumnReader {
 public:
  ParquetColumnReader(int col_id, int type, int fixed_len_size)
      : col_id_(col_id),
        type_(type),
        fixed_len_size_(fixed_len_size),
        num_of_page_(0),
        data_(nullptr),
        data_end_(nullptr),
        cur_page_(-1) {}
  ~ParquetColumnReader() {}
  int GetFixLen() { return fixed_len_size_; }
  virtual bool ReadSlot(void* tuple) = 0;
  virtual void ResetDictDecoder(uint8_t* dict_buffer, int dict_len) = 0;
  // protected:
  /// Pointer to start of next value in data page
  uint8_t* data_;
  /// End of the data page.
  const uint8_t* data_end_;
  int fixed_len_size_;
  // used for select chunkid
  int col_id_;
  int type_;
  int num_of_page_;
  int cur_page_;
  parquet::Encoding::type page_encoding_;
  parquet::PageHeader current_page_header_;
  vector<DataSlice> data_slices;
};
template <typename T>
class ColumnReader : public ParquetColumnReader {
 public:
  ColumnReader(int col_id, int type, int fixed_len_size)
      : ParquetColumnReader(col_id, type, fixed_len_size) {}
  ~ColumnReader() {}
  void ResetDictDecoder(uint8_t* dict_buffer, int dict_len) {
    //    cout << "~~~~~~~~Reset!!!~~~~~~~`\n";
    dict_decoder_.Reset(dict_buffer, dict_len, fixed_len_size_);
    free(dict_buffer);
  }
  bool ReadSlot(void* tuple) {
    while (true) {
      if (page_encoding_ == parquet::Encoding::PLAIN_DICTIONARY) {
        //        if (cur_page_ == 0) {
        //          if (col_id_ == 1)
        //            cout << "cur_page  " << cur_page_ << "  num of page  "
        //                 << num_of_page_ << " \n";
        //          DataSlice& data = data_slices[0];
        //          dict_decoder_.SetData(data_,
        //          data.header_.uncompressed_page_size);
        //          cur_page_++;
        //        }
        //        if (UNLIKELY(!dict_decoder_.GetNextValue(tuple))) {
        //          if (cur_page_ < num_of_page_) {
        //            if (col_id_ == 1)
        //              cout << "cur_page  " << cur_page_ << "  num of page"
        //                   << num_of_page_ << " \n";
        //            DataSlice& data = data_slices[cur_page_++];
        //            page_encoding_ = data.header_.data_page_header.encoding;
        //            data_ = data.page_data_;
        //            data_end_ = data_ + data.header_.uncompressed_page_size;
        //            if (page_encoding_ == parquet::Encoding::PLAIN_DICTIONARY)
        //            {
        //              dict_decoder_.SetData(data_,
        //              data.header_.uncompressed_page_size);
        //            } else {
        //              cur_page_--;
        //            }
        //            continue;
        //          }
        //          num_of_page_ = 0;
        //          return false;
        //        } else {
        //          return true;
        //        }
      } else if (page_encoding_ == parquet::Encoding::PLAIN) {
        if ((data_end_ - data_) >= fixed_len_size_) {
          if (type_ != 5) {
            *(T*)tuple = *(T*)data_;
          } else {
            strcpy((char*)tuple, (char*)data_);
          }
          data_ += fixed_len_size_;
          return true;
        } else {
          if (cur_page_ < num_of_page_ - 1) {
            DataSlice& data = data_slices[++cur_page_];
            page_encoding_ = data.header_.data_page_header.encoding;
            data_ = data.page_data_;
            data_end_ = data_ + data.header_.uncompressed_page_size;
            continue;
          }
          num_of_page_ = 0;
          return false;
        }
      }
    }
  }
  DictDecoder<T> dict_decoder_;
};
} /* namespace loader */
} /* namespace claims */
#endif  // LOADER_TABLE_PARQUET_READER_H_
