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
 * /CMySQL/packet/mysql_eof_packet.h
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#ifndef PACKET_MYSQL_HANDSHAKE_PACKET_H_
#define PACKET_MYSQL_HANDSHAKE_PACKET_H_

#include <string.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include "../mysql_define.h"
#include "../mysql_util.h"
namespace claims {
namespace mysql {
class MysqlHandshakePacket {
 public:
  MysqlHandshakePacket();
  virtual ~MysqlHandshakePacket();

 public:
  static const int32_t SCRAMBLE_SIZE = 8;
  static const int32_t PLUGIN_SIZE = 13;
  static const int32_t PLUGIN2_SIZE = 12;

 public:
  void set_thread_id(uint32_t id);
  int serialize(char *buffer, int64_t len, int64_t &pos);

 private:
  uint8_t protocol_version_;
  string server_version_;
  uint32_t thread_id_;  // connection id
  char scramble_buff_[8];
  uint16_t server_capabilities_; /* set value to use 4.1protocol */
  uint8_t server_language_;
  uint16_t server_status_;
  char plugin_[13]; /* always 0x00 */
  char plugin2_[12];
  char terminated_;
  string str_buf_;   // store ObString content
  char *buffer_;
};
}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_HANDSHAKE_PACKET_H_
