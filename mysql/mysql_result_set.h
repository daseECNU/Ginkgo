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
 * /CLAIMS/mysql/mysql_result_set.h
 *
 *  Created on: Nov 18, 2015
 *      Author: chenlingyun,yukai
 *		   Email: geekchenlingyun@outlook.com
 * 
 * Description:
 *
 */

#ifndef MYSQL_MYSQL_RESULT_SET_H_
#define MYSQL_MYSQL_RESULT_SET_H_
#include<string>

#include "./mysql_row.h"
#include "../common/Block/ResultSet.h"
#include "../common/Schema/Schema.h"
#include "mysql_field.h"

namespace claims {
namespace mysql {
class MysqlResultSet: public ResultSet {
public:

public:
	MysqlResultSet(ResultSet &res);
	int getFieldCount() const;

	int64_t getAffectedRows() const {
		return affected_rows_;
	}

	void setAffectedRows(int64_t affectedRows) {
		affected_rows_ = affectedRows;
	}

	int64_t getFieldIndex() const {
		return field_index_;
	}

	void setFieldIndex(int64_t fieldIndex) {
		field_index_ = fieldIndex;
	}

	std::string getMessage() const {
		return message_;
	}

	void setMessage(const string& message) {
		message_ = message;
	}

	const std::string& getStatementName() const {
		return statement_name_;
	}

	void setStatementName(const string& statementName) {
		statement_name_ = statementName;
	}

	int64_t getWarningCount() const {
		return warning_count_;
	}

	void setWarningCount(int64_t warningCount) {
		warning_count_ = warningCount;
	}

public:
	int next_field(MySQLField& field);
	int next_row(MysqlRow& row);
private:

	int64_t field_index_ = 0; /**< 下一个需要读取的字段的序号 */
	int64_t affected_rows_ = 0;
	int64_t warning_count_ = 0;
	std::string statement_name_;
	std::string message_ = "message";
//  std::vector<std::string> column_header_list_;
//  double query_time_;
//  Schema* schema_;
};
}  // namespace mysql
}  // namespace claims

#endif  //  MYSQL_MYSQL_RESULT_SET_H_
