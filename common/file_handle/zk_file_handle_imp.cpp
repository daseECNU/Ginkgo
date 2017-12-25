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

#include "./zk_file_handle_imp.h"
#include <glog/logging.h>
#include "../memory_handle.h"
#include <string>

namespace claims {
namespace common {

//
RetCode ZkFileHandleImp::SwitchStatus(FileStatus status_to_be) {
  int old_file_status = file_status_;
  int flag;
  if (kInReading == status_to_be && kInReading != file_status_) {
    // Close();
    // file_ = hdfsOpenFile(fs_, file_name_.c_str(), O_RDONLY, 0, 0, 0);
    flag = zoo_wexists(zh_, zk_znode_name_, zk_wexists_watcher, (void*)"test",
                       NULL);
  } else if (kInOverWriting == status_to_be) {
    // Close();
    // file_ = hdfsOpenFile(fs_, file_name_.c_str(), O_WRONLY, 0, 0, 0);
    flag = zoo_wexists(zh_, zk_znode_name_, zk_wexists_watcher, (void*)"test",
                       NULL);
  } else if (kInAppending == status_to_be && kInAppending != file_status_) {
    // Close();

    flag = zoo_wexists(zh_, zk_znode_name_, zk_wexists_watcher, (void*)"test",
                       NULL);
    // file_ = hdfsOpenFile(fs_, file_name_.c_str(), O_WRONLY | O_APPEND, 0, 0,
    // 0);
  } else {
    return rSuccess;
  }

  if (flag != ZOK) {
    //    PLOG(INFO) << "failed to reopen ZNode:" << file_name_ << "("
    //                << file_status_info[old_file_status] << ")  in mode "
    //                << file_status_info[status_to_be] << " .";
    //    return rOpenHdfsFileFail;
    PLOG(INFO) << "The ZNode : " << zk_znode_name_ << "is not exists...";
    PLOG(INFO) << "creating ZNode ....";

    char path_buffer[64];
    int bufferlen = sizeof(path_buffer);
    int flag = zoo_create(zh_, zk_znode_name_, "0", 1, &ZOO_OPEN_ACL_UNSAFE, 0,
                          path_buffer, bufferlen);
    if (flag != ZOK) {
      LOG(INFO) << "Error when create Znode..." << endl;
    }
  } else {
    //    can_close_.set_value(1);
    file_status_ = status_to_be;
    LOG(INFO) << "Znode : " << zk_znode_name_ << "is exists";
    //              << file_status_info[old_file_status] << ") is reopened for "
    //              << file_status_info[file_status_] << endl;
    return rSuccess;
  }
}

RetCode ZkFileHandleImp::OverWriteNoCompress(const void* buffer,
                                             const size_t length) {
  assert(NULL != zh_ && "failed to connect Zookeeper");
  int ret = rSuccess;
  EXEC_AND_RETURN_ERROR(ret, SwitchStatus(kInOverWriting),
                        "failed to switch status");
  return WriteNoCompress(buffer, length);
}
RetCode ZkFileHandleImp::WriteNoCompress(const void* buffer,
                                         const size_t length) {
  assert(NULL != zh_ && "failed to connect Zookeeper");
  char* chr = buffer;
  zoo_set(zh_, zk_znode_name_, chr, length, -1);

  return rSuccess;
}

RetCode ZkFileHandleImp::ReadTotalFile(void*& buffer, size_t* length) {
  //
  assert(NULL != zh_ && "failed to connect Zookeeper");
  int ret = rSuccess;
  //
  EXEC_AND_RETURN_ERROR(ret, SwitchStatus(kInReading),
                        "failed to switch status");
  char buffer_[1000 * 1000 - 1];
  int bufferlen = sizeof(buffer_);
  int flag = zoo_get(zh_, zk_znode_name_, 0, buffer_, &bufferlen, NULL);
  buffer = Malloc(bufferlen);
  flag = zoo_get(zh_, zk_znode_name_, 0, static_cast<char*>(buffer), &bufferlen,
                 NULL);

  // for(int i=0;i<bufferlen;i)(char*)buffer[i]=buffer_[i];
  //*buffer = *buffer_;
  *length = bufferlen;
  if (flag == ZOK)
    return rSuccess;
  else
    return rFailure;
}

RetCode ZkFileHandleImp::Close() { return rSuccess; }
RetCode ZkFileHandleImp::Append(const void* buffer, const size_t length) {}

RetCode ZkFileHandleImp::AppendNoCompress(const void* buffer,
                                          const size_t length) {}

RetCode ZkFileHandleImp::AtomicAppend(const void* buffer, const size_t length,
                                      function<void()> lock_func,
                                      function<void()> unlock_func) {}
RetCode ZkFileHandleImp::OverWrite(const void* buffer, const size_t length) {}

RetCode ZkFileHandleImp::AtomicOverWrite(const void* buffer,
                                         const size_t length,
                                         function<void()> lock_func,
                                         function<void()> unlock_func) {}

RetCode ZkFileHandleImp::Read(void* buffer, size_t length) {}

RetCode ZkFileHandleImp::DeleteFile() {}

RetCode ZkFileHandleImp::SetPosition(size_t pos) {}

RetCode ZkFileHandleImp::Truncate(const size_t newlength) { return rSuccess; }
}  // claims&common
}
