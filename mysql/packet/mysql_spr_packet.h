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
#ifndef PACKET_MYSQL_SPR_PACKET_H_
#define PACKET_MYSQL_SPR_PACKET_H_
#include <string.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include "../mysql_define.h"e
#include "../mysql_util.h"
using std::string;
namespace claims {
namespace mysql {
class MysqlSprPacket {
public:
	MysqlSprPacket();
	virtual ~MysqlSprPacket();

public:
	int serialize(char *buffer, int64_t length, int64_t &pos);

	inline void set_statement_id(uint32_t id) {
		statement_id_ = id;
	}

	inline void set_column_num(uint16_t num) {
		column_num_ = num;
	}

	inline void set_param_num(uint16_t num) {
		param_num_ = num;
	}

	inline void set_warning_count(uint16_t count) {
		warning_count_ = count;
	}

	uint64_t get_serialize_size() {
		uint64_t len = 0;
		len += 1;                 // status
		len += 4;                 // statement id
		len += 2;                 // column num
		len += 2;                 // param num
		len += 1;                 // reserved
		len += 2;                 // warning count
		return len;
	}

private:
	uint8_t status_;
	uint32_t statement_id_;
	uint16_t column_num_;
	uint16_t param_num_;
	uint8_t reserved_;
	uint16_t warning_count_;
};
}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_SPR_PACKET_H_
