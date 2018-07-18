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
 * /CMySQL/mysql_result_set.h
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */

#ifndef PACKET_MYSQL_COMMAND_PACKET_H_
#define PACKET_MYSQL_COMMAND_PACKET_H_

#include <string.h>
#include <stdint.h>

#include "../mysql_util.h"
#include "../mysql_define.h"
#include "./mysql_packet_header.h"
namespace claims {
namespace mysql {
// sizeof(CMysqlCommandPacket) = 24
// because virtual function hold 8 Bytes, regardless virtual function count
class MysqlCommandPacket {
 public:
  MysqlCommandPacket();
  enum MySQLCommandType {
    MYSQL_LOGIN,
    MYSQL_LOGOUT,
    MYSQL_PREPARE,
    MYSQL_EXECUTE,
    MYSQL_OTHER
  };
  inline void setPacketHeader(uint32_t pkt_length, uint8_t pkt_seq) {
    length_ = pkt_length;
    seq_ = pkt_seq;
  }
  inline MySQLPacketHeader& getPacketHeader() {
    return header_;
  }
  inline void setType(uint8_t type) {
    type_ = type;
  }
  inline uint8_t getType() {
    return type_;
  }
  inline void setReceiveTs(const int64_t &now) {
    receive_ts_ = now;
  }
  inline uint64_t  getReceiveTs() {
    return receive_ts_;
  }
  inline void setSqlCommand(char* sql_command, int length) {
    sql_command_ = sql_command;
    sql_command_length_ = length;
  }
  inline char* getSqlCommand() {
    return sql_command_;
  }
  inline uint32_t getSqlCommandLength() {
    return sql_command_length_;
  }

 private:
    MySQLPacketHeader header_;
    MysqlCommandPacket* next_;
    uint32_t length_;
    uint8_t seq_;
    uint8_t type_;
    uint64_t receive_ts_;
    char *sql_command_;
    uint32_t sql_command_length_;
};
}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_COMMAND_PACKET_H_
