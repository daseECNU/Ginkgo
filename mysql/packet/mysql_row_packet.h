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
#ifndef PACKET_MYSQL_ROW_PACKET_H_
#define PACKET_MYSQL_ROW_PACKET_H_

#include <stdint.h>
#include <string>

#include "./mysql_sql_packet.h"
#include "../mysql/mysql_row.h"

namespace claims {
namespace mysql {
class MysqlRowPacket:public MysqlSQLPacket {
public:
	MysqlRowPacket();
	MysqlRowPacket(MysqlRow* row);
	int serialize(char* buffer, int64_t length, int64_t& pos);
	virtual uint64_t get_serialize_size();
	int setRow(const char* content);

private:
	MysqlRow* row_;
};
}
}

#endif  // PACKET_MYSQL_ROW_PACKET_H_
