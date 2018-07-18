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
#include "./mysql_spr_packet.h"

#include "../../common/Logging.h"
namespace claims {
namespace mysql {
MysqlSprPacket::MysqlSprPacket() :
		status_(0x05), statement_id_(0), column_num_(0), param_num_(0), reserved_(
				0), warning_count_(0) {
}

MysqlSprPacket::~MysqlSprPacket() {
}

int MysqlSprPacket::serialize(char *buffer, int64_t len, int64_t &pos) {

	int ret = C_SUCCESS;
	if (NULL == buffer || len <= 0 || pos < 0) {
		MySqlElog("invalid argument buffer=%p, "
				"len=%ld, pos=%ld", buffer, len, pos);
		ret = C_INVALID_ARGUMENT;
	} else {
		if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int1(buffer, len, status_, pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog("serialize status failed, "
						"buffer=%p, len=%ld, status=%u, pos=%ld, ret=%d",
						buffer, len, status_, pos, ret);
			}
		} else if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int4(buffer, len, statement_id_,
						pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog("serialize warning_count failed, "
						"buffer=%p, len=%ld, statement_id_=%u, pos=%ld, ret=%d",
						buffer, len, statement_id_, pos, ret);
			}
		} else if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int2(buffer, len, column_num_, pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog("serialize marker failed, "
						"buffer=%p, len=%ld, column_num_=%u, pos=%ld, ret=%d",
						buffer, len, column_num_, pos, ret);
			}
		} else if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int2(buffer, len, param_num_, pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog("serialize marker failed, "
						"buffer=%p, len=%ld, param_num_=%u, pos=%ld, ret=%d",
						buffer, len, param_num_, pos, ret);
			}
		} else if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int1(buffer, len, reserved_, pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog(
						"serialize marker failed, buffer=%p, len=%ld, reserved_=%u, pos=%ld, ret=%d",
						buffer, len, reserved_, pos, ret);
			}
		} else if (C_SUCCESS
				!= (ret = CMysqlUtil::store_int2(buffer, len, warning_count_,
						pos))) {
			if (C_SIZE_OVERFLOW == ret) {
				MySqlElog(
						"serialize marker failed, buffer=%p, len=%ld, warning_count_=%u, pos=%ld, ret=%d",
						buffer, len, warning_count_, pos, ret);
			}
		}
	}
	return ret;
}
}  // namespace mysql
}  // mysql

