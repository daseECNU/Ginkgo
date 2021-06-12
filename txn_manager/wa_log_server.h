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
 * /CLAIMS/txn_manager/logging.hpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */

#ifndef TXN_MANAGER_WA_LOG_SERVER_H_
#define TXN_MANAGER_WA_LOG_SERVER_H_
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include "../common/error_define.h"
#include "../common/ids.h"
#include "../utility/lock.h"
#include "../utility/lock_guard.h"
#include "../txn_manager/wa_log_impl.h"
#include "../txn_manager/wa_log_store.h"
using std::map;
// using std::unordered_map;
using std::shared_ptr;
using std::make_shared;
using ginkgo::utility::LockGuard;
using ginkgo::common::rSuccess;
using ginkgo::common::rFailure;
namespace ginkgo {
namespace txn {

class LogStream {
 public:
  explicit LogStream(PartitionID part) {
    du_stream_ = make_shared<DurableStream>(part);
    du_stream_->Open();
  }
  LogStream() {
    du_stream_ = make_shared<DurableStream>();
    du_stream_->Open();
  }

  virtual RetCode Append(const char *buffer, uint64_t buffer_size);
  virtual ~LogStream() {}
  virtual RetCode Close() { du_stream_->Close(); }
  shared_ptr<DurableStream> GetDurableStream() { return du_stream_; }

 protected:
  shared_ptr<DurableStream> du_stream_;
};

class CmdLogStream : public LogStream {
 public:
  CmdLogStream() : LogStream() {}
  RetCode Append(const vector<shared_ptr<CommandLog>> &logs);
};

class ValueLogStream : public LogStream {
 public:
  explicit ValueLogStream(PartitionID part) : LogStream(part) {}
  RetCode Append(const vector<shared_ptr<ValueLog>> &logs);
};

class LogServer {
 public:
  static CmdLogStream *GetCmdLogStream();
  static ValueLogStream *GetValueLogStream(PartitionID part);

 private:
  static RetCode CloseCmdLogStream();
  static RetCode CloseValueLogStream(PartitionID part);
  static LogServer proxy_;
  map<PartitionID, ValueLogStream *> value_stream_list_;
  CmdLogStream *cmd_stream_;
  Lock lock_;
};

}  // namespace txn
}  // namespace ginkgo

#endif  //  TXN_MANAGER_WA_LOG_SERVER_H_
