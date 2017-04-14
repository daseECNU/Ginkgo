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
 * /CLAIMS/txn_manager/log_store.hpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */

#ifndef TXN_MANAGER_WA_LOG_STORE_H_
#define TXN_MANAGER_WA_LOG_STORE_H_

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include "../utility/lock.h"
#include "../utility/lock_guard.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../txn_manager/txn.hpp"
#include "../txn_manager/wa_log_impl.h"
#include "../Config.h"
using ginkgo::common::FileHandleImpFactory;
using ginkgo::common::FileHandleImp;
using ginkgo::common::kHdfs;
using ginkgo::common::kDisk;
using ginkgo::utility::LockGuard;
using ginkgo::common::rReachLogTail;
using std::shared_ptr;
using std::dynamic_pointer_cast;
using std::map;
namespace ginkgo {
namespace txn {

class DurableStream {
 public:
  explicit DurableStream(PartitionID part)
      : file_name_(part.getPathAndName() + ".value_log") {}
  explicit DurableStream(const string& name) : file_name_(name) {}
  DurableStream() : file_name_(Config::data_dir + "txnserver.cmd_log") {}
  RetCode Open();
  bool IsOpen() const { return file_handle_ != nullptr; }
  RetCode Close();
  RetCode Append(const char* buf, uint64_t buf_size);
  uint64_t CurrentSize();
  ~DurableStream() { file_handle_->Close(); }
  /**
   * Inner visitor of durable stream
   */
  class Iterator {
   public:
    explicit Iterator(DurableStream* stream, int mode)
        : stream_(stream), mode_(mode) {}
    ~Iterator() { free(cache_); }
    RetCode Open();
    bool isOpen() const { return stream_->IsOpen(); }
    shared_ptr<WALog> NextLog();
    int64_t GetCursor() const { return cursor_; }
    uint64_t GetFileSize() const { return file_size_; }
    void SwitchMode(int mode) { mode_ = mode; }
    static const int ForwardMode = 1;
    static const int ReverseMode = -1;

   private:
    RetCode Seek(uint64_t position);
    RetCode Move(int step);
    RetCode ReadFromFile(char* buffer, uint64_t buffer_size,
                         uint64_t start_pos);
    bool IsCacheHit(uint64_t size) const;
    RetCode ReadFromCache(char* buffer, uint64_t buffer_size);
    char* LookupFromCache(uint64_t buffer_size);
    char NextLogChar();
    string NextLogLine();
    int64_t cursor_;
    uint64_t file_size_;
    DurableStream* stream_;

    // bool use_cache_ = true;
    static const uint64_t CacheSize = 16 * 1024 * 1024;
    char* cache_ = nullptr;
    int64_t cache_pos_;
    bool cache_valid_ = false;

    int mode_ = ForwardMode;

    static map<string, LogType> tokens_;
  };

  shared_ptr<Iterator> GenIterator(int mode) {
    auto iterator = make_shared<Iterator>(this, mode);
    if (iterator->Open() == rSuccess)
      return iterator;
    else
      return nullptr;
  }

 private:
  FileHandleImp* file_handle_ = nullptr;
  string file_name_;

  Lock lock_;

  friend class Iterator;
};

}  // namespace txn
}  // namespace ginkgo

#endif  //  TXN_MANAGER_WA_LOG_STORE_H_
