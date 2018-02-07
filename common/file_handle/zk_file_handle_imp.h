/*
 * Copyright [2012-2017] DaSE@ECNU
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
 * /Claims/common/file_handle/zk_file_handle_imp.h
 *
 *  Created on: May 25, 2017
 *      Author: huangchengsheng
 *                 Email: 285649461@qq.com
 *
 * Description:
 *
 */

#ifndef COMMON_FILE_HANDLE_ZK_FILE_HANDLE_IMP_H_
#define COMMON_FILE_HANDLE_ZK_FILE_HANDLE_IMP_H_

#include "./file_handle_imp.h"
#include "../../loader/zk_connector.h"
#include "../../Config.h"

namespace claims {
namespace common {
class FileHandleImpFactory;
class ZkFileHandleImp : public FileHandleImp {
  friend FileHandleImpFactory;

 private:
  explicit ZkFileHandleImp(std::string file_name)
      : FileHandleImp(file_name),
        zh_(ZkConnector::Instance()),
        zk_znode_name_(Config::zk_znode_name.data()) {}
  NO_COPY_AND_ASSIGN(ZkFileHandleImp);

 public:
  virtual ~ZkFileHandleImp() {}
  virtual RetCode Append(const void* buffer, const size_t length);
  virtual RetCode AppendNoCompress(const void* buffer, const size_t length);

  virtual RetCode AtomicAppend(const void* buffer, const size_t length,
                               function<void()> lock_func,
                               function<void()> unlock_func);

  virtual RetCode OverWrite(const void* buffer, const size_t length);
  virtual RetCode OverWriteNoCompress(const void* buffer, const size_t length);

  virtual RetCode AtomicOverWrite(const void* buffer, const size_t length,
                                  function<void()> lock_func,
                                  function<void()> unlock_func);

  virtual RetCode Close();
  virtual RetCode ReadTotalFile(void*& buffer, size_t* length);  // NOLINT

  /**
                       * @brief Method description: read length bytes from file
   * into memory, usually
                       *        called after SetPosition()
                       * @param buffer: hold the data read from file
                       * @param length: the no. of bytes to read
                       * @return rSuccess if succeed
                       */
  virtual RetCode Read(void* buffer, size_t length);
  RetCode PRead(void* buffer, size_t length, size_t start_pos);
  virtual bool CanAccess(std::string file_name) {
    assert(zh_ != NULL && "failed to connect Zkserver");
    return ZOK == zoo_wexists(zh_, zk_znode_name_, zk_wexists_watcher,
                              (void*)"test", NULL);
    ;
  }

  virtual RetCode DeleteFile();

  const string& get_file_name() { return file_name_; }
  virtual RetCode SwitchStatus(FileStatus status_to_be);

  RetCode Truncate(const size_t newlength);

 protected:
  virtual RetCode SetPosition(size_t pos);

 private:
  RetCode WriteNoCompress(const void* buffer, const size_t length);

 private:
  zhandle_t* zh_;
  char* zk_znode_name_;
  string tmp_;
};
}
}

#endif
