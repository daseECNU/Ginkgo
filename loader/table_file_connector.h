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

#include "../common/error_define.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "./file_connector.h"
#include "../common/rename.h"

using std::vector;
using std::string;
using std::atomic;

namespace ginkgo {
namespace catalog {
class TableDescriptor;
}
using ginkgo::catalog::TableDescriptor;

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
  RetCode DeleteAllTableFiles();

  RetCode UpdateWithNewProj();

 private:
  common::FilePlatform platform_;
  vector<vector<common::FileHandleImp*>> file_handles_;
  vector<vector<string>> write_path_name_;
  TableDescriptor* table_;

  common::FileOpenFlag open_flag_ = static_cast<common::FileOpenFlag>(-1);

  vector<vector<Lock>> write_locks_;

  atomic<int> ref_;
  bool is_closed = true;
  Lock open_close_lock_;
};

} /* namespace loader */
} /* namespace ginkgo */

#endif  // LOADER_TABLE_FILE_CONNECTOR_H_
