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
 * /CMySQL/packet/mysql_eof_packet.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#include "./mysql_eof_packet.h"

#include "../../common/Logging.h"
namespace claims {
namespace mysql {
MysqlEOFPacket::MysqlEOFPacket()
    : field_count_(0xfe),
      warning_count_(0),
      server_status_(2) {
}

MysqlEOFPacket::~MysqlEOFPacket() {
}

int MysqlEOFPacket::serialize(char *buffer, int64_t len, int64_t& pos) {
  int ret = C_SUCCESS;
  if (NULL == buffer || len <= 0 || pos < 0) {
    MySqlLog("invalid argument buffer=%p, len=%ld, pos=%ld", buffer, len, pos);
    ret = C_INVALID_ARGUMENT;
  } else {
    if (C_SUCCESS
        != (ret = CMysqlUtil::store_int1(buffer, len, field_count_, pos))) {
      if (C_SIZE_OVERFLOW == ret) {
        MySqlLog("serialize field_count failed, "
            "buffer=%p, len=%ld, field_count=%u, pos=%ld, ret=%d",
            buffer, len, field_count_, pos, ret);
      }
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::store_int2(buffer, len, warning_count_, pos))) {
      if (C_SIZE_OVERFLOW == ret) {
        MySqlLog("serialize warning_count failed, "
            "buffer=%p, len=%ld, warning_count=%u, pos=%ld, ret=%d",
            buffer, len, warning_count_, pos, ret);
      }
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::store_int2(buffer, len, server_status_, pos))) {
      if (C_SIZE_OVERFLOW == ret) {
        MySqlLog("serialize marker failed, "
            "buffer=%p, len=%ld, marker=%c, pos=%ld, ret=%d",
            buffer, len, server_status_, pos, ret);
      }
    }
  }
  return ret;
}
}  // namespace mysql
}  // namespace claims
