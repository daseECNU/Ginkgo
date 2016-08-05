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
#include<string>
#include "./mysql_field_packet.h"

#include "../../common/Logging.h"
#include "../mysql_util.h"
namespace claims {
namespace mysql {
MysqlFieldPacket::MysqlFieldPacket(){
}
MysqlFieldPacket::MysqlFieldPacket(MySQLField field):field_(field) {
}

MysqlFieldPacket::~MysqlFieldPacket() {
}

int MysqlFieldPacket::serialize(char *buf, int64_t len, int64_t& pos) {
  //std::cout << "serialize a mysql field packet!" << std::endl;
  CMysqlUtil::EMySQLFieldType type = claims::mysql::CMysqlUtil::MYSQL_TYPE_GEOMETRY;  // init with type unsupported
  int ret = C_SUCCESS;
  uint8_t num_decimals = field_.decimals_;
  uint32_t length = field_.length_;
  if (C_SUCCESS
      != (ret = CMysqlUtil::get_mysql_type(type, num_decimals, length))) {
    MySqlLog("get mysql type failed, mysql type is %d", type);
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_str(buf, len, field_.catalog_, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize catalog failed ret is %d", ret);
    }
  } else if (C_SUCCESS != (ret = CMysqlUtil::store_str(buf, len, field_.db_, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize db failed ret is %d", ret);
    }
  }  else if (C_SUCCESS
      != (ret = CMysqlUtil::store_str_v(buf, len, field_.tname_.c_str(),
    		  field_.tname_.length(), pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize tname failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_str_v(buf, len, field_.org_tname_.c_str(),
    		  field_.org_tname_.length(), pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize org_tname failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_str_v(buf, len, field_.column_name_.c_str(),
    		  field_.column_name_.length(), pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize cname failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_str_v(buf, len, field_.org_cname_.c_str(),
    		  field_.org_cname_.length(), pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize org_cname failed ret is %d", ret);
    }
  } else if (C_SUCCESS != (ret = CMysqlUtil::
      store_int1(buf, len, 0x0c, pos))) {  // length of belows
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize 0x0c failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_int2(buf, len, field_.charsetnr_, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize charsetnr failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_int4(buf, len, length, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize length failed ret is %d", ret);
    }
  } else if (C_SUCCESS != (ret = CMysqlUtil::store_int1(buf, len, type, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize type failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_int2(buf, len, field_.flags_, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize flags failed ret is %d", ret);
    }
  } else if (C_SUCCESS
      != (ret = CMysqlUtil::store_int1(buf, len, num_decimals, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize num_decimals failed ret is %d", ret);
    }
  } else if (C_SUCCESS != (ret = CMysqlUtil::store_int2(buf, len, 0x0000, pos))) {
    if (C_SIZE_OVERFLOW == ret) {
      MySqlLog("serialize 0x0000 failed ret is %d", ret);
    }
  }
  return ret;
}
}  // namespace mysql
}  // namespace claims
