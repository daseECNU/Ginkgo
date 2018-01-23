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
 *  /Ginkgo/sql_parser/ast_node/ast_export_stmt.cpp
 *  Created on: Dec 31, 2017 2:29:15 PM
 *  Modified on: Dec 31, 2017
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 */

#include "../ast_node/ast_export_stmt.h"
#include <iostream>  //  NOLINT
#include <iomanip>
#include <string>
#include <bitset>

#include "../../catalog/table.h"
#include "../../common/error_define.h"
#include "../../Environment.h"
#include "../ast_node/ast_expr_node.h"

using namespace claims::common;  // NOLINT
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::bitset;
// namespace claims {
// namespace sql_parser {
AstExportTable::AstExportTable(AstNodeType ast_node_type, string table_name,
                           AstNode* path, string column_separator,
                           string tuple_separator)
    : AstNode(ast_node_type),
      table_name_(table_name),
      path_(path),
      column_separator_(column_separator),
      tuple_separator_(tuple_separator){}

AstExportTable::~AstExportTable() { delete path_; }

void AstExportTable::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Export Table|"
       << "    ";
  cout << " Table name: " << table_name_ << endl;
  cout << setw(level * TAB_SIZE) << " "
       << " Path: " << endl;
  if (path_ != NULL) {
    path_->Print(++level);
  }
}

RetCode AstExportTable::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  TableDescriptor* table =
      Environment::getInstance()->getCatalog()->getTable(table_name_);
  AstExprList *path_node = dynamic_cast<AstExprList *>(path_);
  AstExprConst *data = dynamic_cast<AstExprConst *>(path_node->expr_);
  string path =data->data_;
  unsigned pos = path.rfind("/");
  string path_name_former = path.substr(0, pos);
  if (NULL == table) {
    sem_cnxt->error_msg_ =
        "the table " + table_name_ + " does not exist !";
    ret = rTableNotExisted;
    return ret;
  }
  if (0 == table->getNumberOfProjection()) {
    sem_cnxt->error_msg_ = "the table has not been created a projection!";
    ret = rNoProjection;
    return ret;
  }
  if ( -1 ==access(path_name_former.c_str(), 0)){
	  sem_cnxt->error_msg_ = "the path "+ path_name_former + " does not exsit!" ;

	  ret = rDataPathError;
  }else if(-1 ==access(path_name_former.c_str(), 2)){
	  sem_cnxt->error_msg_ = "the path "+ path_name_former + " has not write permission!";
	  ret = rNoPermission;
  }
  return ret;
}

//}  // namespace sql_parser
//}  // namespace claims
