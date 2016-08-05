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

#ifndef PACKET_MYSQL_EOF_PACKET_H_
#define PACKET_MYSQL_EOF_PACKET_H_

#include <stdint.h>
#include "./mysql_sql_packet.h"
#include "../mysql_util.h"
#include "../mysql_define.h"
namespace claims {
namespace mysql {
class MysqlEOFPacket: public MysqlSQLPacket {
 public:
  MysqlEOFPacket();
  virtual ~MysqlEOFPacket();
  int serialize(char *buffer, int64_t len, int64_t &pos);
  inline void set_warning_count(uint16_t count) {
    warning_count_ = count;
  }
  inline void set_server_status(uint16_t status) {
      server_status_ = status;
  }
  virtual uint64_t get_serialize_size() {
    uint64_t len = 0;
    len += 1;                 // field_count_
    len += 2;                 // warning_count_
    len += 2;                 // server_status_
    return len;
  }
  inline uint8_t get_field_count() const {
    return field_count_;
  }
  inline uint16_t get_warning_count() const {
    return warning_count_;
  }
  inline uint16_t get_server_status() const {
    return server_status_;
  }

  uint8_t getFieldCount() const {
    return field_count_;
  }

  void setFieldCount(uint8_t fieldCount) {
    field_count_ = fieldCount;
  }

  uint16_t getServerStatus() const {
    return server_status_;
  }

  void setServerStatus(uint16_t serverStatus) {
    server_status_ = serverStatus;
  }

  uint16_t getWarningCount() const {
    return warning_count_;
  }

  void setWarningCount(uint16_t warningCount) {
    warning_count_ = warningCount;
  }

 private:
    uint8_t field_count_;
    uint16_t warning_count_;
    uint16_t server_status_;
    DISALLOW_COPY_AND_ASSIGN(MysqlEOFPacket);
};

}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_EOF_PACKET_H_
