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

#include "./mysql_ok_packet.h"

#include <bitset>
#include <string>

#include "../../common/Logging.h"
namespace claims {
namespace mysql {
MysqlOKPacket::MysqlOKPacket()

    : field_count_(0x00),
      affected_rows_(0),
      insert_id_(0),
      server_status_(0x22),
      warning_count_(0) {
}

MysqlOKPacket::~MysqlOKPacket() {
//  str_buf_.clear();
}

int MysqlOKPacket::set_message(string message) {
  int ret = C_SUCCESS;
  if (message.empty() || 0 > message.length()) {
    MySqlElog("invalid argument message.ptr=%p, message.length=%d", &message,
         message.length());
    ret = C_ERROR;
  } else {
    message_.assign(message);
    if (C_SUCCESS != ret) {
      MySqlElog("write string to messaget failed");
    }
  }
  return ret;
}

int MysqlOKPacket::encode(char* buffer, int64_t length, int64_t& pos) {
  MySqlLog("in MysqlOKPacket::encode Function");
  int ret = C_SUCCESS;
  int64_t start_pos = pos;
  if (NULL == buffer || 0 >= length || pos < 0) {
    MySqlElog("invalid argument "
        "buffer=%p, length=%ld, pos=%ld", buffer, length, pos);
    ret = C_INVALID_ARGUMENT;
  } else {
    pos += C_MYSQL_PACKET_HEADER_SIZE;
    ret = serialize(buffer, length, pos);
    if (C_SUCCESS == ret) {
      uint32_t pkt_len = static_cast<uint32_t>(pos - start_pos
          - C_MYSQL_PACKET_HEADER_SIZE);
      if (C_SUCCESS
          != (ret = CMysqlUtil::
              store_int3(buffer, length, pkt_len, start_pos))) {
        MySqlElog(
            "serialize packet header size failed, "
            "buffer=%p, buffer length=%ld, packet length=%d, pos=%ld",
            buffer, length, pkt_len, start_pos);
      } else if (C_SUCCESS
          != (ret = CMysqlUtil::store_int1(buffer, length, 2, start_pos))) {
        MySqlElog(
            "serialize packet haader seq failed, "
            "buffer=%p, buffer length=%ld, seq number=%d, pos=%ld",
            buffer, length, 2, start_pos);
      }
    } else {
      MySqlElog("encode ok packet data failed");
    }
  }
  return ret;
}

uint64_t MysqlOKPacket::get_serialize_size() {
  uint64_t len = 0;
  /*1byte field_count + 2bytes server_status +
   * 2bytes warning_count see MySQL protocol*/
  len += 5;
  len += 9; /*max length for unit64_t*/
  len += 9; /*max length for store_length*/
  len += 9 + message_.length();
  return len;
}

int MysqlOKPacket::serialize(char* buffer, int64_t length, int64_t& pos) {
  int ret = C_SUCCESS;

  if (NULL == buffer || 0 >= length || pos < 0) {
    MySqlElog("invalid argument "
        "buffer=%p, length=%ld, pos=%ld", buffer, length, pos);
    ret = C_INVALID_ARGUMENT;
  } else {
    if (C_SUCCESS
        != (ret = CMysqlUtil::store_int1(buffer, length, field_count_, pos))) {
      MySqlElog(
          "serialize field_count failed, buffer=%p, length=%ld, field_count=%u,"
          "pos=%ld",
          buffer, length, field_count_, pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::
            store_length(buffer, length, affected_rows_, pos))) {
      MySqlElog(
          "serialize affected_row failed, "
          "buffer=%p, length=%ld, affected_rows=%lu,"
          "pos=%ld",
          buffer, length, affected_rows_, pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::store_length(buffer, length, insert_id_, pos))) {
      MySqlElog("serialize insert_id failed, buffer=%p, length=%ld, insert_id=%lu,"
           "pos=%ld",
           buffer, length, insert_id_, pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::
            store_int2(buffer, length, server_status_, pos))) {
      MySqlElog(
          "serialize server_status failed, "
          "buffer=%p, length=%ld, server_status=%u,"
          "pos=%ld",
          buffer, length, server_status_, pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::
            store_int2(buffer, length, warning_count_, pos))) {
      MySqlElog(
          "serialize warning_count failed, "
          "buffer=%p, length=%ld, warning_count=%u,"
          "pos=%ld",
          buffer, length, warning_count_, pos);
    } else if (0 != message_.length()) {
      if (C_SUCCESS
          != (ret = CMysqlUtil::store_obstr(buffer, length, message_, pos))) {
        MySqlElog("serialize message failed, buffer=%p, length=%ld, insert_id=%lu,"
             "pos=%ld",
             buffer, length, insert_id_, pos);
      }
    }
  }
  return ret;
}
}  // namespace mysql
}  // namespace claims
