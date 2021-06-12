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
 * /CLAIMS/txn_manager/wa_log_test.cpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <sys/time.h>
#include "../txn_manager/wa_log_impl.h"
#include "../txn_manager/wa_log_store.h"
#include "../txn_manager/wa_log_server.h"
#include "../Config.h"

// #define TEST_LOG
// #define TEST_LOG_STREAM
// #define SHARED_PTR_INHERIT
// #define TEST_TYPE
// #define TEST_CMDLOG
// #define TEST_VALUELOG
// #define BENCH_CMDLOG
// #define BENCH_VALUELOG
//#define TEST_SHARED_PTR
#define TEST_SCAN_CMDLOG
#define TEST_SCAN_VALUE
using namespace std;
using namespace ginkgo::txn;

template <typename T>
shared_ptr<T> make_shared_array(unsigned size) {
  return make_shared<T>(new T[size], std::default_delete<T[]>());
}
class A {
 public:
  A() {}
  ~A() { cout << "A free" << endl; }
  virtual string ToString() { return "[A]"; }
};

class AA : public A {
 public:
  AA() {}
  ~AA() { cout << "AA free" << endl; }
  virtual string ToString() { return "[AA]"; }
};

int main() {
#ifdef TEST_LOG
  BeginLog begin(1);
  cout << begin.ToString() << BeginLog(begin.ToString()).ToString() << endl;
  WriteLog write(1, 2, 10, 10);
  cout << write.ToString() << WriteLog(write.ToString()).ToString() << endl;
  CommitLog commit(2);
  cout << commit.ToString() << CommitLog(commit.ToString()).ToString() << endl;
  AbortLog abort(3);
  cout << abort.ToString() << AbortLog(abort.ToString()).ToString() << endl;
  CheckpointLog cp(10, 2, 20, 30);
  cout << cp.ToString() << CheckpointLog(cp.ToString()).ToString() << endl;

  char buf[10] = "abcabcabc";
  buf[9] = 'x';

  ValueLog data1(1, 10, 15);
  data1.EncodeData(buf, sizeof(buf));
  cout << "**********" << endl;
  for (auto i = 0; i < data1.GetBufferSize(); i++)
    printf("%c", *(data1.GetBuffer() + i));

  cout << "************" << endl;
  ValueLog data2;
  data2.DecodeData(data1.GetBuffer(), data1.GetBufferSize(), false);
  for (auto i = 0; i < data2.GetBufferSize(); i++)
    printf("%c", *(data2.GetBuffer() + i));
#endif

#ifdef SHARED_PTR_INHERIT
  auto aa_ptr = make_shared<AA>();
  cout << aa_ptr->ToString() << endl;
#endif

#ifdef TEST_TYPE
  auto log1 = new BeginLog(1);
  cout << log1->ToString() << log1->GetType() << endl;
  auto log2 = new CommitLog(1);
  cout << log2->ToString() << log2->GetType() << endl;

#endif

#ifdef TEST_CMDLOG
  Config::config_file = "../conf/config";
  Config::getInstance()->print_configure();
  auto stream = LogServer::OpenCmdLogStream();
  vector<shared_ptr<CommandLog>> logs;
  logs.push_back(BeginLog::Gen(1));
  logs.push_back(WriteLog::Gen(1, 1, 10, 5));
  logs.push_back(WriteLog::Gen(1, 2, 10, 5));
  logs.push_back(WriteLog::Gen(1, 2, 10, 5));
  logs.push_back(CommitLog::Gen(1));
  logs.push_back(AbortLog::Gen(1));
  logs.push_back(CheckpointLog::Gen(1, 1, 20, 25));
  stream->Append(logs);
  cout << "stream:" << stream << endl;
#endif

#ifdef TEST_SCAN_CMDLOG
  auto count = 0;
  Config::config_file = "../conf/config";
  Config::getInstance();
  // auto stream = DurableStream(PartitionID(ProjectionID(TableID(1), 0), 0));
  auto stream = DurableStream();
  cout << "open durable stream " << stream.Open() << endl;
  shared_ptr<WALog> log;
  auto iterator = stream.GenIterator(DurableStream::Iterator::ReverseMode);
  struct timeval start, end;

  gettimeofday(&start, nullptr);
  while ((log = iterator->NextLog()) != nullptr) {
    if (count < 10) {
      // cout << "@@@@@@@@@@@@@@@@@" << endl;
      cout << log->ToString();
      /*      auto value_log = dynamic_pointer_cast<ValueLog>(log);
            cout << value_log->ToString();
            for (auto i = 0; i < value_log->GetBodySize(); i++)
              cout << *(value_log->GetBody() + i);
            cout << endl;*/
    }

    // cout << log->ToString();
    /*    switch (log->GetType()) {
          case LogType::kBegin:
            cout << log->ToString() << endl;
            break;
        }*/
    count++;
    // cout << "count:" << count << endl;
  }
  cout << "<last cursor>" << iterator->GetCursor() << endl;
  cout << "<file size>" << iterator->GetFileSize() << endl;
  gettimeofday(&end, nullptr);

  double start_msec = start.tv_sec * 1000 + start.tv_usec / 1000;
  double end_msec = end.tv_sec * 1000 + end.tv_usec / 1000;
  cout << "scan: " << count << " items" << endl;
  cout << "total time: " << (end_msec - start_msec) / 1000.0 << endl;
  cout << "latency:" << (end_msec - start_msec) / (count) << " msec" << endl;
  cout << "throughput:" << (1000 * count) / (end_msec - start_msec)
       << " per second" << endl;
#endif

#ifdef TEST_VALUELOG
  Config::config_file = "../conf/config";
  Config::getInstance();
  auto stream = LogServer::OpenValueLogStream(
      PartitionID(ProjectionID(TableID(0), 0), 0));
  char buffer[20] = {"abcdefgh"};
  vector<shared_ptr<ValueLog>> logs;
  auto log1 = ValueLog::Gen(0, 10, 5, buffer, sizeof(buffer));
  auto log2 = ValueLog::Gen(0, 19, 9, buffer, sizeof(buffer));
  stream->Append({log1, log2});
// stream->Append(logs);
#endif

#ifdef BENCH_CMDLOG
  Config::config_file = "../conf/config";
  Config::getInstance();  //->print_configure();
  auto stream = LogServer::OpenCmdLogStream();
  vector<shared_ptr<CommandLog>> logs1, logs2;
  logs1.push_back(BeginLog::Gen(1));
  logs1.push_back(WriteLog::Gen(1, 1, 10, 5));
  logs1.push_back(WriteLog::Gen(1, 2, 10, 5));
  logs1.push_back(WriteLog::Gen(1, 2, 10, 5));
  logs1.push_back(WriteLog::Gen(1, 2, 10, 5));
  logs1.push_back(CommitLog::Gen(1));
  // logs.push_back(AbortLog::Gen(1));
  const int times = 1000000;
  struct timeval start;
  gettimeofday(&start, nullptr);

  for (auto i = 0; i < times; i++) {
    stream->Append(logs1);
    // stream->Append(logs2);
  }
  struct timeval end;
  gettimeofday(&end, nullptr);

  double start_msec = start.tv_sec * 1000 + start.tv_usec / 1000;
  double end_msec = end.tv_sec * 1000 + end.tv_usec / 1000;
  cout << "total time:" << end_msec - start_msec << " msec" << endl;
  cout << "avg time:" << (end_msec - start_msec) / times << " msec" << endl;
  cout << "througput:" << 1000 / ((end_msec - start_msec) / times) << endl;
#endif

#ifdef BENCH_VALUELOG
  const int buffer_size = 1024 * 10;
  Config::config_file = "../conf/config";
  Config::local_disk_mode = true;
  Config::getInstance()->print_configure();
  auto stream = LogServer::OpenValueLogStream(
      PartitionID(ProjectionID(TableID(1), 0), 0));
  vector<shared_ptr<ValueLog>> logs1;
  char* buffer = static_cast<char*>(malloc(buffer_size));
  logs1.push_back(ValueLog::Gen(0, 10, 5, buffer, buffer_size));
  logs1.push_back(ValueLog::Gen(1, 10, 5, buffer, buffer_size));

  const int times = 10000;
  struct timeval start;
  gettimeofday(&start, nullptr);

  for (auto i = 0; i < times; i++) {
    stream->Append(logs1);
  }
  struct timeval end;
  gettimeofday(&end, nullptr);

  double start_msec = start.tv_sec * 1000 + start.tv_usec / 1000;
  double end_msec = end.tv_sec * 1000 + end.tv_usec / 1000;
  cout << "total time:" << end_msec - start_msec << " msec" << endl;
  cout << "avg time:" << (end_msec - start_msec) / times << " msec" << endl;
  cout << "throughput:"
       << ((times / 1024.0) * (buffer_size / 1024.0)) /
              ((end_msec - start_msec) / 1000.0) << " MB" << endl;
  cout << "throughput:" << (times / (end_msec - start_msec)) * 1000.0 << " n"
       << endl;
#endif

#ifdef TEST_SHARED_PTR
  auto a_ptr = make_shared<A>();
  shared_ptr<A> b_ptr;
  cout << (a_ptr == nullptr) << endl;
  cout << (b_ptr == nullptr) << endl;
#endif
}
