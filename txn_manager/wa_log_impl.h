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
 * /CLAIMS/txn_manager/log_server.hpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */

#ifndef TXN_MANAGER_WA_LOG_IMPL_H_
#define TXN_MANAGER_WA_LOG_IMPL_H_

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include "../txn_manager/txn.hpp"
#include "../common/error_define.h"

namespace ginkgo {
namespace txn {
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::string;
using ginkgo::common::rSuccess;
using ginkgo::common::rFailure;
enum LogType { kBegin, kWrite, kCommit, kAbort, kCheckpoint, kValue, kTail };
class WALog {
 public:
  static string EncodeLine(const string& type, const vector<uint64_t>& items);
  static vector<string> DecodeLine(const string& line);
  virtual LogType GetType() const = 0;
  virtual string ToString() const = 0;
};

class CommandLog : public WALog {
 public:
  explicit CommandLog(uint64_t ts) : ts_(ts) {}
  CommandLog() {}
  uint64_t GetTs() const { return ts_; }
  virtual LogType GetType() const = 0;
  virtual string ToString() const = 0;

 protected:
  uint64_t ts_;
};

class BeginLog : public CommandLog {
 public:
  explicit BeginLog(uint64_t ts) : CommandLog(ts) {}
  explicit BeginLog(const string& line) { ts_ = stoull(DecodeLine(line)[1]); }
  string ToString() const { return EncodeLine("begin", {ts_}); }
  LogType GetType() const { return LogType::kBegin; }
  static shared_ptr<CommandLog> Gen(uint64_t ts) {
    return make_shared<BeginLog>(ts);
  }
  static shared_ptr<CommandLog> Gen(const string& line) {
    return make_shared<BeginLog>(line);
  }
};

class WriteLog : public CommandLog {
 public:
  explicit WriteLog(uint64_t ts, uint64_t part, uint64_t pos, uint64_t offset)
      : CommandLog(ts), part_(part), pos_(pos), offset_(offset) {}
  explicit WriteLog(const string& line) {
    auto items = DecodeLine(line);
    ts_ = stoull(items[1]);
    part_ = stoull(items[2]);
    pos_ = stoull(items[3]);
    offset_ = stoull(items[4]);
  }
  string ToString() const {
    return EncodeLine("write", {ts_, part_, pos_, offset_});
  }
  uint64_t GetPart() const { return part_; }
  uint64_t GetPos() const { return pos_; }
  uint64_t GetOffset() const { return offset_; }
  LogType GetType() const { return kWrite; }
  static shared_ptr<CommandLog> Gen(uint64_t ts, uint64_t part, uint64_t pos,
                                    uint64_t offset) {
    return make_shared<WriteLog>(ts, part, pos, offset);
  }
  static shared_ptr<CommandLog> Gen(const string& line) {
    return make_shared<WriteLog>(line);
  }

 private:
  uint64_t part_;
  uint64_t pos_;
  uint64_t offset_;
};

class CommitLog : public CommandLog {
 public:
  explicit CommitLog(uint64_t ts) : CommandLog(ts) {}
  explicit CommitLog(const string& line) { ts_ = stoull(DecodeLine(line)[1]); }
  string ToString() const { return EncodeLine("commit", {ts_}); }
  LogType GetType() const { return kCommit; }
  static shared_ptr<CommandLog> Gen(uint64_t ts) {
    return make_shared<CommitLog>(ts);
  }
  static shared_ptr<CommandLog> Gen(const string& line) {
    return make_shared<CommitLog>(line);
  }
};

class AbortLog : public CommandLog {
 public:
  explicit AbortLog(uint64_t ts) : CommandLog(ts) {}
  explicit AbortLog(const string& line) { ts_ = stoull(DecodeLine(line)[1]); }
  string ToString() const { return EncodeLine("abort", {ts_}); }
  LogType GetType() const { return kAbort; }
  static shared_ptr<CommandLog> Gen(uint64_t ts) {
    return make_shared<AbortLog>(ts);
  }
  static shared_ptr<CommandLog> Gen(const string& line) {
    return make_shared<AbortLog>(line);
  }
};

class CheckpointLog : public CommandLog {
 public:
  explicit CheckpointLog(uint64_t ts, uint64_t part, uint64_t his_cp,
                         uint64_t rt_cp)
      : CommandLog(ts), part_(part), his_cp_(his_cp), rt_cp_(rt_cp) {}
  explicit CheckpointLog(const string& line) {
    auto items = DecodeLine(line);
    ts_ = stoull(items[1]);
    part_ = stoull(items[2]);
    his_cp_ = stoull(items[3]);
    rt_cp_ = stoull(items[4]);
  }
  string ToString() const {
    return EncodeLine("checkpoint", {ts_, part_, his_cp_, rt_cp_});
  }
  uint64_t GetPart() const { return part_; }
  uint64_t GetHisCP() const { return his_cp_; }
  uint64_t GetRtCP() const { return rt_cp_; }
  LogType GetType() const { return kCheckpoint; }
  static shared_ptr<CommandLog> Gen(uint64_t ts, uint64_t part, uint64_t his_cp,
                                    uint64_t rt_cp) {
    return make_shared<CheckpointLog>(ts, part, his_cp, rt_cp);
  }

  static shared_ptr<CommandLog> Gen(const string& line) {
    return make_shared<CheckpointLog>(line);
  }

 private:
  uint64_t part_;
  uint64_t his_cp_;
  uint64_t rt_cp_;
};

class ValueLog : public WALog {
 public:
  ValueLog(uint64_t part, uint64_t pos, uint64_t offset)
      : part_(part), pos_(pos), offset_(offset) {}
  ValueLog() {}
  ~ValueLog() {
    if (is_buffer_copy_) free(buffer_);
  }
  uint64_t GetPart() const { return part_; }
  uint64_t GetPos() const { return pos_; }
  uint64_t GetOffset() const { return offset_; }
  char* GetBody() const { return body_; }
  uint64_t GetBodySize() const { return body_size_; }
  char* GetBuffer() const { return buffer_; }
  uint64_t GetBufferSize() const { return buffer_size_; }
  LogType GetType() const { return kValue; }
  void EncodeData(const char* body, unsigned body_size);
  void DecodeData(const char* buffer, unsigned buffer_size, bool copy_mode);
  string ToString() const {
    return EncodeLine("value", {part_, pos_, offset_, body_size_});
  }
  static shared_ptr<ValueLog> Gen(uint64_t part, uint64_t pos,
                                  uint64_t offset) {
    return make_shared<ValueLog>(part, pos, offset);
  }
  static shared_ptr<ValueLog> Gen(uint64_t part, uint64_t pos, uint64_t offset,
                                  const char* body, uint64_t body_size) {
    auto log = make_shared<ValueLog>(part, pos, offset);
    log->EncodeData(body, body_size);
    return log;
  }
  static shared_ptr<ValueLog> Gen(const char* buffer, uint64_t buffer_size,
                                  bool copy_mode) {
    auto log = make_shared<ValueLog>();
    log->DecodeData(buffer, buffer_size, copy_mode);
  }

 private:
  uint64_t part_;
  uint64_t pos_;
  uint64_t offset_;

  char* body_ = nullptr;
  uint64_t body_size_;

  char* buffer_ = nullptr;
  uint64_t buffer_size_ = 0;

  bool is_buffer_copy_ = false;
};
}  // namespace txn
}  // namespace ginkgo

#endif  //  TXN_MANAGER_WA_LOG_IMPL_H_
