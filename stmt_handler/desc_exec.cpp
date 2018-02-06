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
 * /CLAIMS/stmt_handler/desc_stmt_exec.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: yuyang
 *		   Email: youngfish93@hotmail.com
 *
 *  Modified on: Aug 4, 2017
 *       Author: zyhe
 *	  	 Email: hzylab@gmail.com
 * Description:
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include "../stmt_handler/desc_exec.h"
#include "../catalog/catalog.h"
#include "../Environment.h"
#include "../catalog/stat/Analyzer.h"
#include "../catalog/projection_binding.h"
using std::endl;
using std::string;
using std::vector;
using claims::catalog::Catalog;

namespace claims {
namespace stmt_handler {

DescExec::DescExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  desc_stmt_ast_ = dynamic_cast<AstDescStmt*>(stmt_);
}

DescExec::~DescExec() {}

RetCode DescExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;
  ostringstream ostr;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table = local_catalog->getTable(desc_stmt_ast_->table_name_);
  for (int i = 0; i < table->getAttributes().size(); i++) {
    desc_stmt_ast_->column_name_.push_back(table->getAttributes()[i].attrName);
    // extra and is_key not used now.
    desc_stmt_ast_->extra_.push_back("");
    desc_stmt_ast_->is_key_.push_back("");
    desc_stmt_ast_->size_.push_back(
        table->getAttributes()[i].attrType->get_length());
    if (table->getAttributes()[i].attrType->nullable) {
      desc_stmt_ast_->nullable_.push_back("YES");
    } else {
      desc_stmt_ast_->nullable_.push_back("NO");
    }
    switch (table->getAttributes()[i].attrType->type) {
      case t_smallInt:
        desc_stmt_ast_->type_.push_back("small int");
        desc_stmt_ast_->default_value_.push_back("0");
        break;
      case t_int:
        desc_stmt_ast_->type_.push_back("int");
        desc_stmt_ast_->default_value_.push_back("0");
        break;
      case t_u_long:
        desc_stmt_ast_->type_.push_back("unsigned long");
        desc_stmt_ast_->default_value_.push_back("0");
        break;
      case t_float:
        desc_stmt_ast_->type_.push_back("float");
        desc_stmt_ast_->default_value_.push_back("0.0");
        break;
      case t_double:
        desc_stmt_ast_->type_.push_back("double");
        desc_stmt_ast_->default_value_.push_back("0.0");
        break;
      case t_string:
        desc_stmt_ast_->type_.push_back("string");
        desc_stmt_ast_->default_value_.push_back("NULL");
        break;
      case t_date:
        desc_stmt_ast_->type_.push_back("date");
        desc_stmt_ast_->default_value_.push_back("1400-01-01");
        break;
      case t_time:
        desc_stmt_ast_->type_.push_back("time");
        desc_stmt_ast_->default_value_.push_back("00:00:00.000000");
        break;
      case t_datetime:
        desc_stmt_ast_->type_.push_back("date and time");
        desc_stmt_ast_->default_value_.push_back("1400-01-01 00:00:00.000000");
        break;
      case t_decimal:
        desc_stmt_ast_->type_.push_back("decimal");
        desc_stmt_ast_->default_value_.push_back("0.0");
        break;
      case t_boolean:
        desc_stmt_ast_->type_.push_back("boolean");
        desc_stmt_ast_->default_value_.push_back("false");
        break;
      case t_u_smallInt:
        desc_stmt_ast_->type_.push_back("unsigned small int");
        desc_stmt_ast_->default_value_.push_back("0.0");
        break;
      case t_date_day:
        desc_stmt_ast_->type_.push_back("date day");
        desc_stmt_ast_->default_value_.push_back("");
        break;
      case t_date_week:
        desc_stmt_ast_->type_.push_back("date week");
        desc_stmt_ast_->default_value_.push_back("");
        break;
      case t_date_month:
        desc_stmt_ast_->type_.push_back("date month");
        desc_stmt_ast_->default_value_.push_back("");
        break;
      case t_date_year:
        desc_stmt_ast_->type_.push_back("date year");
        desc_stmt_ast_->default_value_.push_back("");
        break;
      case t_date_quarter:
        desc_stmt_ast_->type_.push_back("date quarter");
        desc_stmt_ast_->default_value_.push_back("");
        break;
      default:
        desc_stmt_ast_->type_.push_back("unknown");
        desc_stmt_ast_->default_value_.push_back("");
        break;
    }
  }

  // get projection information                --added by zyhe
  vector<ProjectionDescriptor*>* projection_list = table->GetProjectionList();
  for (auto projection : *projection_list) {
    Partitioner* partitioner = projection->getPartitioner();
    desc_stmt_ast_->projection_id_.push_back(
        partitioner->getProejctionID().projection_off);
    string proj_col_name = "";
    for (auto i : projection->getColumnList()) {
      proj_col_name +=
          table->getAttributes()[i.column_id_.column_off].attrName + " ";
    }
    desc_stmt_ast_->projection_col_.push_back(proj_col_name);
    desc_stmt_ast_->partition_num_.push_back(
        partitioner->getNumberOfPartitions());
    desc_stmt_ast_->partition_keys_.push_back(
        partitioner->getPartitionKey().attrName);
    if (partitioner->isEmpty()) {
      desc_stmt_ast_->is_null_.push_back("FALSE");
    } else {
      desc_stmt_ast_->is_null_.push_back("TRUE");
    }
  }

  vector<int> max_column_size;
  max_column_size.push_back(5);  // Field
  max_column_size.push_back(4);  // Type
  max_column_size.push_back(4);  // Null
  max_column_size.push_back(3);  // Key
  max_column_size.push_back(7);  // Default
  max_column_size.push_back(5);  // Size
  max_column_size.push_back(5);  // Extra

  vector<string> col_header;
  col_header.push_back("Field");
  col_header.push_back("Type");
  col_header.push_back("Null");
  col_header.push_back("Key");
  col_header.push_back("Default");
  col_header.push_back("Size");
  col_header.push_back("Extra");

  for (int i = 0; i < table->getAttributes().size(); i++) {
    if (desc_stmt_ast_->column_name_[i].size() > max_column_size[0]) {
      max_column_size[0] = desc_stmt_ast_->column_name_[i].size();
    }
    if (desc_stmt_ast_->type_[i].size() > max_column_size[1]) {
      max_column_size[1] = desc_stmt_ast_->type_[i].size();
    }
    if (desc_stmt_ast_->nullable_[i].size() > max_column_size[2]) {
      max_column_size[2] = desc_stmt_ast_->nullable_[i].size();
    }
    if (desc_stmt_ast_->is_key_[i].size() > max_column_size[5]) {
      max_column_size[3] = desc_stmt_ast_->is_key_[i].size();
    }
    if (desc_stmt_ast_->default_value_[i].size() > max_column_size[4]) {
      max_column_size[4] = desc_stmt_ast_->default_value_[i].size();
    }
  }
  // print header
  for (int i = 0; i < 7; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  for (int i = 0; i < 7; i++) {
    ostr << "|";
    ostr << " " << std::left << std::setw(max_column_size[i]) << col_header[i];
    ostr << " ";
  }
  ostr << "|" << endl;
  for (int i = 0; i < 7; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  // print the description table
  for (int i = 0; i < desc_stmt_ast_->column_name_.size(); i++) {
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[0])
         << desc_stmt_ast_->column_name_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[1])
         << desc_stmt_ast_->type_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[2])
         << desc_stmt_ast_->nullable_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[3])
         << desc_stmt_ast_->is_key_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[4])
         << desc_stmt_ast_->default_value_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[5])
         << desc_stmt_ast_->size_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[6])
         << desc_stmt_ast_->extra_[i] << " ";
    ostr << "|" << endl;
  }

  // print last line
  for (int i = 0; i < 7; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  // print the information about projections of the table  --added by zyhe
  ostr << " " << endl;
  ostr << "the projections information:" << endl;

  max_column_size.clear();
  max_column_size.push_back(12);  // ProjectionID
  max_column_size.push_back(17);  // Projection_Fields
  max_column_size.push_back(17);  // Partition_key
  max_column_size.push_back(12);  // Partition_num
  max_column_size.push_back(8);   // Has_Data

  col_header.clear();
  col_header.push_back("ProjectionID");
  col_header.push_back("Projection_Fields");
  col_header.push_back("Partition_key");
  col_header.push_back("PartitionNum");
  col_header.push_back("Has_Data");

  for (int i = 0; i < table->GetProjectionList()->size(); i++) {
    if (desc_stmt_ast_->projection_col_[i].size() > max_column_size[1]) {
      max_column_size[1] = desc_stmt_ast_->projection_col_[i].size();
    }
  }

  // print header
  for (int i = 0; i < 5; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  for (int i = 0; i < 5; i++) {
    ostr << "|";
    ostr << " " << std::left << std::setw(max_column_size[i]) << col_header[i];
    ostr << " ";
  }
  ostr << "|" << endl;
  for (int i = 0; i < 5; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  // print the description table
  for (int i = 0; i < desc_stmt_ast_->projection_id_.size(); i++) {
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[0])
         << desc_stmt_ast_->projection_id_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[1])
         << desc_stmt_ast_->projection_col_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[2])
         << desc_stmt_ast_->partition_keys_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[3])
         << desc_stmt_ast_->partition_num_[i] << " ";
    ostr << "|"
         << " " << std::left << std::setw(max_column_size[4])
         << desc_stmt_ast_->is_null_[i] << " ";
    ostr << "|" << endl;
  }

  // print last line
  for (int i = 0; i < 5; i++) {
    ostr << "+";
    for (int j = 0; j < (max_column_size[i] + 2); j++) {
      ostr << "-";
    }
  }
  ostr << "+" << endl;

  exec_result->info_ = ostr.str();
  exec_result->status_ = true;
  exec_result->result_ = NULL;

  return ret;
}
RetCode DescExec::GetWriteAndReadTables(
    ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  SemanticContext sem_cnxt;
  ret = desc_stmt_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    result.error_info_ = "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    result.status_ = false;
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  } else {
    table_status.first = 0;
    table_status.second = desc_stmt_ast_->table_name_;
    table_list.push_back(table_status);
    stmt_to_table_list.push_back(table_list);
    return ret;
  }
}
} /* namespace stmt_handler */
} /* namespace claims */
