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
 * /CLAIMS/txn_manager/log_store.cpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */
#include <string>
#include <map>
#include "../common/error_define.h"
#include "../txn_manager/wa_log_store.h"
using ginkgo::common::rSuccess;
using ginkgo::common::rFailure;
namespace ginkgo {
namespace txn {
int count = 0;
RetCode DurableStream::Open() {
  LockGuard<Lock> guard(lock_);
  if (!Config::local_disk_mode) {
    file_handle_ =
        FileHandleImpFactory::Instance().CreateFileHandleImp(kHdfs, file_name_);
  } else {
    file_handle_ =
        FileHandleImpFactory::Instance().CreateFileHandleImp(kDisk, file_name_);
  }
  if (file_handle_ != nullptr)
    return rSuccess;
  else
    return rFailure;
}

RetCode DurableStream::Close() {
  LockGuard<Lock> guard(lock_);
  return file_handle_->Close();
}

RetCode DurableStream::Append(const char* buf, uint64_t buf_size) {
  LockGuard<Lock> guard(lock_);
  return file_handle_->Append(buf, buf_size);
}

uint64_t DurableStream::CurrentSize() {
  assert(IsOpen());
  LockGuard<Lock> guard(lock_);
  return file_handle_->GetSize();
}

map<string, LogType> DurableStream::Iterator::tokens_ = {
    {"begin", LogType::kBegin},
    {"write", LogType::kWrite},
    {"commit", LogType::kCommit},
    {"abort", LogType::kAbort},
    {"checkpoint", LogType::kCheckpoint},
    {"value", LogType::kValue},
    {"tail", LogType::kTail}};

RetCode DurableStream::Iterator::Open() {
  // LockGuard<Lock> guard(stream_->lock_);
  assert(stream_->IsOpen());
  file_size_ = stream_->CurrentSize();
  if (mode_ == ForwardMode)
    cursor_ = 0;
  else if (mode_ == ReverseMode)
    cursor_ = file_size_ - 1;
  cache_ = static_cast<char*>(malloc(CacheSize));
  return rSuccess;
}

RetCode DurableStream::Iterator::Seek(uint64_t position) {
  if (position < file_size_)
    cursor_ = position;
  else
    return rFailure;
  return rSuccess;
}

RetCode DurableStream::Iterator::Move(int step) {
  int64_t new_cursor = cursor_ + step;
  if (step > 0 && new_cursor >= file_size_) return rFailure;  // cursor overflow
  if (step < 0 && new_cursor > cursor_) return rFailure;  // cursor underflow
  cursor_ = new_cursor;
  return rSuccess;
}

RetCode DurableStream::Iterator::ReadFromFile(char* buffer,
                                              uint64_t buffer_size,
                                              uint64_t start_pos) {
  // if (cursor_ + buffer_size > file_size_) buffer_size = file_size_ - cursor_;
  if (start_pos + buffer_size > file_size_)
    buffer_size = file_size_ - start_pos;
  return stream_->file_handle_->PRead(buffer, buffer_size, start_pos);
}

bool DurableStream::Iterator::IsCacheHit(uint64_t size) const {
  if (cache_valid_ && cursor_ >= cache_pos_ &&
      (cursor_ + size) <= (cache_pos_ + CacheSize)) {
    // cout << "cache hit" << endl;
    return true;
  } else {
    /*    cout << "<cache miss> cursor," << cursor_ << " ,size:" << size
             << " ,cache range:" << cache_pos_ << "->" << cache_pos_ + CacheSize
             << endl;*/
    // assert(!cache_valid_);
    return false;
  }
}

RetCode DurableStream::Iterator::ReadFromCache(char* buffer,
                                               uint64_t buffer_size) {
  assert(cursor_ >= 0);
  if (buffer_size > CacheSize) assert(false);

  // directly read from RAM cache
  if (IsCacheHit(buffer_size)) {
    /*    count++;
        if (count < 200) {
          cout << "<read from cache> cursor:" << cursor_
               << ",cache_pos:" << cache_pos_ << ",char:" << *buffer << endl;
        }*/
    if (buffer_size == sizeof(char))
      *buffer = *(cache_ + (cursor_ - cache_pos_));
    else
      memcpy(buffer, cache_ + (cursor_ - cache_pos_), buffer_size);
    return rSuccess;
  }
  // cout << "<try to load from file in read @cursor:" << cursor_ << " >" <<
  // endl;
  // fill the cache by loading from file
  int64_t new_cache_pos = 0;
  if (mode_ == ForwardMode) {
    new_cache_pos = cursor_;
    /*    if (count == 0 || count == 1)
          cout << "<new_cache_pos>" << new_cache_pos << "," << cursor_ << endl;
        else
          assert(false);
        count++;*/
  } else if (mode_ == ReverseMode) {
    new_cache_pos = cursor_ - CacheSize + 1;
    if (new_cache_pos < 0) new_cache_pos = 0;
  }
  if (ReadFromFile(cache_, CacheSize, new_cache_pos) == rSuccess) {
    /*    cout << "<read from file in read> cursor:" << cursor_
             << ",cache_pos:" << cache_pos_ << ",new_cache_pos:" <<
       new_cache_pos
             << endl;*/
    cache_valid_ = true;
    cache_pos_ = new_cache_pos;
    return ReadFromCache(buffer, buffer_size);
  } else {
    assert(false);
    return rFailure;
  }
}

char* DurableStream::Iterator::LookupFromCache(uint64_t buffer_size) {
  if (buffer_size > CacheSize) {
    assert(false);
    return rFailure;
  }
  if (IsCacheHit(buffer_size)) {
    return cache_ + (cursor_ - cache_pos_);
  }
  /*cout << "<try to load from file in lookup @cursor:" << cursor_ << " >"
       << endl;*/
  int64_t new_cache_pos = 0;
  if (mode_ == ForwardMode) {
    new_cache_pos = cursor_;
  } else if (mode_ == ReverseMode) {
    new_cache_pos = cursor_ - CacheSize + 1;
    if (new_cache_pos < 0) new_cache_pos = 0;
  }
  if (ReadFromFile(cache_, CacheSize, new_cache_pos) == rSuccess) {
    cache_valid_ = true;
    cache_pos_ = cursor_;
    /*    cout << "<read from file in lookup> cursor:" << cursor_
             << ",cache_pos:" << cache_pos_ << ",new_cache_pos:" <<
       new_cache_pos
             << endl;*/
    return LookupFromCache(buffer_size);
  } else {
    assert(false);
    return nullptr;
  }
}

char DurableStream::Iterator::NextLogChar() {
  assert(cursor_ >= 0);
  char buffer;
  if (ReadFromCache(&buffer, sizeof(char)) == rSuccess) {
    // cout << "move:" << cursor_;
    Move(sizeof(char) * mode_);
    // cout << "->" << cursor_ << endl;
    return buffer;
  }
  assert(false);
  return '\0';
}

string DurableStream::Iterator::NextLogLine() {
  string str = "";
  char c;
  do {
    if ((mode_ == ForwardMode && cursor_ >= file_size_) ||
        (mode_ == ReverseMode && cursor_ < 0))
      return str;
    c = NextLogChar();
    // cout << "get char:" << c << "@" << cursor_ << "=>" << mode_ << endl;
    if (c == '\0') break;
    if (mode_ == ForwardMode) {
      str.insert(str.end(), c);
      if (c == '\n' && str.length() > 1) break;
    } else if (mode_ == ReverseMode) {
      str.insert(str.begin(), c);
      if (c == '<') break;
    }
    // if (c == '\n' && str.length() > 1) break;
    // str.find_first_not_of('\n');
  } while (true);
  // cout << "$$" << cursor_ << "," << mode_ << "$$" << str << "$$$$$$" << endl;
  return str;
}

shared_ptr<WALog> DurableStream::Iterator::NextLog() {
  // cout << "scan log  cursor @" << cursor_ << endl;
  if ((mode_ == ForwardMode && cursor_ >= file_size_) ||
      (mode_ == ReverseMode && cursor_ < 0)) {
    cout << "<finish scan>" << endl;
    return nullptr;
  }
  uint64_t part, pos, offset, body_size, tail_size, shift;
  char* body;
  shared_ptr<ValueLog> value_log;
  shared_ptr<WALog> wa_log;
  string line = NextLogLine();
  auto items = WALog::DecodeLine(line);
  /*  cout << "$$$" << cursor_ << "$$$" << line << "$$$"
         << "$$$" << endl;*/
  if (items.size() == 0) return nullptr;
  for (auto& item : items) {
    // cout << "*" << item << "*" << endl;
  }
  // generate each type log;
  switch (tokens_[items[0]]) {
    // read Command log
    case kBegin:
      return BeginLog::Gen(line);
    case kWrite:
      return WriteLog::Gen(line);
    case kCommit:
      return CommitLog::Gen(line);
    case kAbort:
      return AbortLog::Gen(line);
    case kCheckpoint:
      return CheckpointLog::Gen(line);

    // forward read value log
    case kValue:

      part = stoull(items[1]);
      pos = stoull(items[2]);
      offset = stoull(items[3]);
      body_size = stoull(items[4]);
      body = LookupFromCache(body_size);
      Move(body_size * mode_);
      // skip < tail size >
      NextLogLine();
      if (body == nullptr) {
        assert(false);
        return nullptr;
      }
      value_log = ValueLog::Gen(part, pos, offset);
      value_log->EncodeData(body, body_size);
      return value_log;

    // reverse read value log
    case kTail:
      tail_size = line.length();
      shift = stoull(items[1]);
      Move((shift - 1) * mode_);
      // cout << "1. move to position@" << cursor_ << endl;
      SwitchMode(ForwardMode);
      value_log = dynamic_pointer_cast<ValueLog>(NextLog());
      assert(value_log != nullptr);
      // cout << "find 1 value log@" << cursor_ << endl;
      SwitchMode(ReverseMode);
      Move((value_log->GetBufferSize() + 1) * mode_);
      return value_log;
      // cout << "2. move to position@" << cursor_ << endl;
  }
}

}  // namespace txn
}  // namespace ginkgo
