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
#ifndef PACKET_MYSQL_OK_PACKET_H_
#define PACKET_MYSQL_OK_PACKET_H_

#include <stdint.h>
#include<string>
#include "../mysql_util.h"
#include "./mysql_sql_packet.h"
namespace claims {
namespace mysql {
class MysqlOKPacket : public MysqlSQLPacket {
 public:
  MysqlOKPacket();
  virtual ~MysqlOKPacket();

 public:
  int serialize(char* buffer, int64_t length, int64_t& pos);

  uint64_t get_serialize_size();

  /**
   * This function used to serialize OK packet
   * to thread buffer include packet header
   * called when send login_ok packet
   */
  virtual int encode(char* buffer, int64_t length, int64_t& pos);
  int set_message(string message);

  inline void set_affected_rows(uint64_t row) {
    affected_rows_ = row;
  }

  inline void set_insert_id(uint64_t id) {
    insert_id_ = id;
  }

  inline void set_server_status(uint16_t status) {
    server_status_ = status;
  }

  inline void set_warning_count(uint16_t warning_count) {
    warning_count_ = warning_count;
  }
  inline uint8_t get_field_count() const {
    return field_count_;
  }

  inline uint64_t get_affected_rows() const {
    return affected_rows_;
  }

  inline uint64_t get_insert_id() const {
    return insert_id_;
  }

  inline uint16_t get_server_status() const {
    return server_status_;
  }

  inline uint16_t get_warning_count() const {
    return warning_count_;
  }

  inline string& get_message() {
    return message_;
  }

 private:
  uint8_t field_count_; /* always 0x00 */
  uint64_t affected_rows_;
  uint64_t insert_id_;
  uint16_t server_status_;
  uint16_t warning_count_;
  string message_;
};
}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_OK_PACKET_H_
