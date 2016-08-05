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
#ifndef PACKET_MYSQL_ERROR_PACKET_H_
#define PACKET_MYSQL_ERROR_PACKET_H_
#include <string>
#include <iostream>
using std::string;
#include "./mysql_packet_header.h"
#include "./mysql_sql_packet.h"
#include "../mysql_state.h"
#include "../mysql_define.h"
#include "../mysql_util.h"
namespace claims {
namespace mysql {
class MysqlErrorPacket : public MysqlSQLPacket {
 public:
  static const uint64_t SQLSTATE_SIZE = 5;
  static const uint8_t MARKER = '#';

 public:
  MysqlErrorPacket();
  virtual ~MysqlErrorPacket();
  int serialize(char* buffer, int64_t len, int64_t& pos);
  uint64_t get_serialize_size();
  virtual int encode(char *buffer, int64_t length, int64_t & pos);
  int set_message(const string& message);

  /**
   * set error code and sql state string.
   *
   * @note OB_ERROR shouldn't passing to this function for
   * hostorical reason.
   *
   * @note It will make a negation and truncate it from 4 bytes
   * (int) to 2 bytes (uint16_t) for fitting msyql protocol.
   *
   * @param errcode oceanbase error code
   */
  int set_errcode(int errcode) {
    errcode_ = static_cast<uint16_t>(-errcode);
    return set_sqlstate(CMysqlState::get_instance().get_jdbc_state(errcode));
  }

  MySQLPacketHeader getHeader() const {
    return header_;
  }

  void setHeader(MySQLPacketHeader header) {
    header_ = header;
  }

 private:
  inline void set_errcode(int16_t code) {
    errcode_ = code;
  }

  int set_sqlstate(const char *sqlstate) {
    int ret = C_SUCCESS;
    if (SQLSTATE_SIZE == strlen(sqlstate)) {
      sqlstate_ = sqlstate;
    } else {
      ret = C_INVALID_ARGUMENT;
    }
    return ret;
  }
  inline uint8_t get_field_count() const {
    return field_count_;
  }

  inline int16_t get_err_code() const {
    return errcode_;
  }

  inline const char* get_sql_state() {
    return sqlstate_;
  }

  inline string& get_message() {
    return message_;
  }

 private:
  MySQLPacketHeader header_;
  uint8_t field_count_; /* Always 0xff */
  int16_t errcode_;
  const char *sqlstate_;
  string message_;
};
#endif  // PACKET_MYSQL_ERROR_PACKET_H_
}  // namespace mysql
}  // namespace claims
