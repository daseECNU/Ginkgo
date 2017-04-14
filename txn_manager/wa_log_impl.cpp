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
 * /CLAIMS/txn_manager/log_server.cpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */

#ifndef TXN_MANAGER_LOG_SERVER_CPP_
#define TXN_MANAGER_LOG_SERVER_CPP_

#include "../txn_manager/wa_log_impl.h"
#include <string>
#include <sstream>
#include <vector>
namespace ginkgo {
namespace txn {
using std::istringstream;
string WALog::EncodeLine(const string& type, const vector<uint64_t>& items) {
  // < type items[0] items[1] ... items[n] >\n
  string str = "< " + type;
  for (auto& item : items) str += " " + to_string(item);
  return str + " >\n";
}

vector<string> WALog::DecodeLine(const string& line) {
  // {type, para_1, para_2,...,para_n} => vector
  vector<string> result;
  // istringstream strim(line.substr(2, line.size() - 2 - 3));
  istringstream strim(line);
  string tmp;
  while (strim >> tmp)
    if (tmp != "<" && tmp != ">") result.push_back(tmp);
  return result;
}

void ValueLog::EncodeData(const char* body, unsigned body_size) {
  body_size_ = body_size;
  string head = EncodeLine("value", {part_, pos_, offset_, body_size_});
  string tail = "\n< tail " + to_string(head.length() + body_size) + " >\n";
  buffer_size_ = head.length() + body_size_ + tail.length();
  buffer_ = static_cast<char*>(malloc(buffer_size_));
  memcpy(buffer_, head.c_str(), head.length());
  memcpy(buffer_ + head.length(), body, body_size);
  memcpy(buffer_ + head.length() + body_size_, tail.c_str(), tail.length());
  body_ = buffer_ + head.length();
}

void ValueLog::DecodeData(const char* buffer, unsigned buffer_size,
                          bool copy_mode) {
  string header = "";
  unsigned index = 0;
  while (true) {
    // cout << "append:" << buffer[index] << endl;
    header.insert(header.end(), buffer[index]);
    if (buffer[index] == '\n') break;
    ++index;
  }
  // cout << "header:" << header << endl;
  istringstream strim(header);
  string tmp, part, pos, offset, body_size;
  strim >> tmp >> tmp >> part >> pos >> offset >> body_size;
  /*   cout << "str paras:" << part << "," << pos << "," << offset << ","
        << body_size << endl;*/
  part_ = stoull(part);
  pos_ = stoull(pos);
  offset_ = stoull(offset);
  body_size_ = stoull(body_size);
  buffer_size_ = buffer_size;
  /*  cout << "paras:" << part_ << "," << pos_ << "," << offset << "," <<
     body_size_
         << endl;*/
  if (copy_mode) {
    buffer_ = static_cast<char*>(malloc(buffer_size_));
    memcpy(buffer_, buffer, buffer_size);
    is_buffer_copy_ = true;
  } else {
    buffer_ = buffer;
  }
  body_ = buffer_ + header.length();
}

}  // namespace txn
}  // namespace ginkgo

#endif  //  TXN_MANAGER_LOG_SERVER_CPP_
