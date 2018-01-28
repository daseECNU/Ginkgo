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
 * /Claims/loader/table_file_connector.h
 *
 *  Created on: Oct 21, 2015
 *      Author: yukai
 *		   Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef LOADER_TABLE_FILE_CONNECTOR_H_
#define LOADER_TABLE_FILE_CONNECTOR_H_

#include <atomic>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "../common/error_define.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "./file_connector.h"
#include "../common/rename.h"

using std::vector;
using std::string;
using std::atomic;
using std::map;
using std::set;
namespace claims {
namespace catalog {
class TableDescriptor;
}
using claims::catalog::TableDescriptor;

namespace loader {
class TableFileConnector {
  NO_COPY_AND_ASSIGN(TableFileConnector);

 public:
  TableFileConnector(common::FilePlatform platform, TableDescriptor* table,
                     common::FileOpenFlag open_flag);
  //  TableFileConnector(common::FilePlatform platform,
  //                     std::vector<std::vector<std::string>> writepath);
  ~TableFileConnector();
  RetCode Open();
  RetCode Close();

  /**
   * @brief Method description: flush length bytes data from source into file
   *        whose projection id is projection_offset and partition id is
   *        partition_offset
   */
  /*
    RetCode Flush(unsigned projection_offset, unsigned partition_offset,
                  const void* source, unsigned length, bool overwrite = false);

    RetCode AtomicFlush(unsigned projection_offset, unsigned partition_offset,
                        const void* source, unsigned length,
                        function<void()> lock_func, function<void()>
    unlock_func,
                        bool overwrite = false);
   */
  RetCode AtomicFlush(unsigned projection_offset, unsigned partition_offset,
                      const void* source, unsigned length);

  RetCode AtomicFlushNoCompress(unsigned partition_key_index,
                                unsigned partition_offset, const void* source,
                                unsigned length);
  RetCode DeleteAllTableFiles();

  RetCode DeleteOneProjectionFiles(string proj_id);

  RetCode UpdateWithNewProj();

  RetCode TruncateFileFromPrtn(unsigned projection_offset,
                               unsigned partition_offset, uint64_t& length);

  // added by zyhe
  void SaveUpdatedFileLengthToCatalog();

  void InitMemFileLength(unsigned projection_offset, unsigned partition_offset);

 private:
  common::FilePlatform platform_;
  /// for common file
  vector<vector<common::FileHandleImp*>> file_handles_;
  vector<vector<string>> write_path_name_;
  vector<vector<Lock>> write_locks_;
  TableDescriptor* table_;

  /// for parquet
  // <partition_key_index, projection_id>
  map<int, int> part_to_proj_;
  map<int, vector<string>> write_path_parq_;
  map<int, vector<Lock>> write_locks_parq_;
  // <partition_key_index,partition number>
  map<int, int> part_key_to_num_;

  common::FileOpenFlag open_flag_ = static_cast<common::FileOpenFlag>(-1);

  atomic<int> ref_;
  bool is_closed = true;
  Lock open_close_lock_;

 public:
  map<int, vector<common::FileHandleImp*>> file_handles_parq_;
};

} /* namespace loader */
} /* namespace claims */

#endif  // LOADER_TABLE_FILE_CONNECTOR_H_
