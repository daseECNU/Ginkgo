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
 * /CLAIMS/mysql/mysql_result_set.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: chenlingyun,yukai
 *		   Email: geekchenlingyun@outlook.com
 * 
 * Description:
 *
 */

#ifndef MYSQL_MYSQL_RESULT_SET_CPP_
#define MYSQL_MYSQL_RESULT_SET_CPP_
#include "mysql_result_set.h"

#include "./mysql_row.h"
#include "mysql_field.h"
#include "./mysql_define.h"
namespace claims {
namespace mysql {
MysqlResultSet::MysqlResultSet(ResultSet &res){
	this->schema_ = res.schema_->duplicateSchema();
	this->query_time_ = res.query_time_;
	this->column_header_list_ = res.column_header_list_;
}
int MysqlResultSet::next_field(MySQLField& field) {
	int ret = C_SUCCESS;
	if(field_index_ >= this->column_header_list_.size()) return C_ERROR;
	field.column_name_ = this->column_header_list_[field_index_];

	std::cout<<schema_->getncolumns()<<endl;
	field.type_ = this->schema_->getcolumn(field_index_);
	field.length_ = this->column_header_list_[field_index_].size();
	field_index_++;
	LOG(INFO)<<"field.column_name_ is "<<field.column_name_<<endl;
	//LOG(INFO)<<"field.type_ is "<<field.type_<<endl;
	LOG(INFO)<<"field.length_ is "<<field.length_<<endl;
	LOG(INFO)<<"field_index_ is "<<field_index_<<endl;
	return ret;
}
int MysqlResultSet::next_row(MysqlRow& row) {
	int ret = C_SUCCESS;
	row.column_num_=column_header_list_.size();
	row.schema_ = schema_->duplicateSchema();
	Iterator it = this->createIterator();
	BlockStreamBase* block;
	BlockStreamBase::BlockStreamTraverseIterator* tuple_it;
	unsigned sample_times = 0;
	while (block = it.nextBlock()) {
		bool finish = false;
		tuple_it = block->createIterator();
		void * tuple;
		row.tuple_=tuple_it->nextTuple();
	}
	return ret;
}
int MysqlResultSet::getFieldCount() const{
	int64_t cnt = 0;
	uint64_t ret = 0;
	cnt = column_header_list_.size();
	if(cnt>0){
		ret = static_cast<uint64_t>(cnt);
	}
	return ret;

}
}  // namespace mysql
}  // namespace claims
#endif //  MYSQL_MYSQL_RESULT_SET_CPP_ 
