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
 * /CLAIMS/txn_manager/logging.cpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */
#include <string>
#include <vector>

#include "../txn_manager/wa_log_server.h"

namespace ginkgo {
namespace txn {
LogServer LogServer::proxy_;

RetCode LogStream::Append(const char* buffer, uint64_t buffer_size) {
  return du_stream_->Append(buffer, buffer_size);
}

RetCode CmdLogStream::Append(const vector<shared_ptr<CommandLog>>& logs) {
  vector<string> cmds;
  for (auto& log : logs) cmds.push_back(log->ToString());
  uint64_t total_size = 0;
  for (auto& cmd : cmds) total_size += cmd.length();
  char* buffer = static_cast<char*>(malloc(total_size));
  if (buffer == nullptr) return rFailure;
  uint64_t cursor = 0;
  for (auto& cmd : cmds) {
    memcpy(buffer + cursor, cmd.c_str(), cmd.length());
    cursor += cmd.length();
  }
  return LogStream::Append(buffer, total_size);
}

RetCode ValueLogStream::Append(const vector<shared_ptr<ValueLog>>& logs) {
  for (auto& log : logs) {
    auto ret = LogStream::Append(log->GetBuffer(), log->GetBufferSize());
    assert(ret == rSuccess);
    if (ret == rFailure) return rFailure;
  }
  return rSuccess;
}

ValueLogStream* LogServer::GetValueLogStream(PartitionID part) {
  LockGuard<Lock> guard(proxy_.lock_);
  if (proxy_.value_stream_list_.find(part) != proxy_.value_stream_list_.end())
    return proxy_.value_stream_list_[part];
  proxy_.value_stream_list_[part] = new ValueLogStream(part);
  return proxy_.value_stream_list_[part];
}

CmdLogStream* LogServer::GetCmdLogStream() {
  LockGuard<Lock> guard(proxy_.lock_);
  if (proxy_.cmd_stream_ != nullptr) return proxy_.cmd_stream_;
  proxy_.cmd_stream_ = new CmdLogStream();
  return proxy_.cmd_stream_;
}

RetCode LogServer::CloseCmdLogStream() {
  LockGuard<Lock> gurad(proxy_.lock_);
  if (proxy_.cmd_stream_ == nullptr) return rFailure;
  delete proxy_.cmd_stream_;
  proxy_.cmd_stream_ = nullptr;
  return rSuccess;
}

RetCode LogServer::CloseValueLogStream(PartitionID part) {
  LockGuard<Lock> gurad(proxy_.lock_);
  auto stream = proxy_.value_stream_list_.find(part);
  if (stream == proxy_.value_stream_list_.end()) return rFailure;
  delete stream->second;
  proxy_.value_stream_list_.erase(stream);
  return rSuccess;
}

}  // namespace txn
}  // namespace ginkgo
