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
#include "./mysql_resheader_packet.h"

#include "../../common/Logging.h"
namespace claims {
namespace mysql {
MysqlResHeaderPacket::MysqlResHeaderPacket()
    : field_count_(0) {
}

MysqlResHeaderPacket::~MysqlResHeaderPacket() {
}

int MysqlResHeaderPacket::serialize(char* buffer, int64_t len, int64_t& pos) {
  int ret = C_SUCCESS;
  if (NULL == buffer || len <= 0 || pos < 0) {
    MySqlLog("invalid argument buffer=%p, len=%ld, pos=%ld", buffer, len, pos);
    ret = C_INVALID_ARGUMENT;
  } else {
    if (C_SUCCESS
        != (ret = CMysqlUtil::store_length(buffer, len, field_count_, pos))) {
      if (C_SIZE_OVERFLOW == ret) {
        MySqlLog("serialize field_count failed, "
            "buffer=%p, len=%ld, field_count=%lu, pos=%ld, ret=%d",
            buffer, len, field_count_, pos, ret);
      }
    }
  }
  return ret;
}
uint64_t MysqlResHeaderPacket::get_serialize_size() {
  uint64_t len = 0;
  len += MAX_STORE_LENGTH;  // field_count_
  return len;
}
}  // namespace mysql
}  // namespace claims
