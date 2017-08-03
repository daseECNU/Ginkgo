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
 * /CLAIMS/sql_parser/ast_node/ast_truncate_stmt.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: zy.he
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#include "../ast_node/ast_truncate_stmt.h"

#include <glog/logging.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>

#include "./ast_truncate_stmt.h"
#include "../../common/error_define.h"
#include "../../catalog/table.h"
#include "../../Environment.h"
using namespace claims::common;  // NOLINT
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::bitset;

// namespace claims {
// namespace sql_parser {
AstTruncateTable::AstTruncateTable(AstNodeType ast_node_type,
                                   AstNode* table_list)
    : AstNode(ast_node_type), table_list_(table_list) {
  //  cout << "Generate AstTruncateTableStmt" << endl;
}

AstTruncateTable::~AstTruncateTable() {
  if (NULL != table_list_) {
    delete table_list_;
    table_list_ = NULL;
  }
}

void AstTruncateTable::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Truncate Stmt|" << endl;
  if (table_list_ != NULL) {
    cout << setw(++level * TAB_SIZE) << " "
         << "|Table List|" << endl;
    table_list_->Print(level);
  }
}

RetCode AstTruncateTable::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;

  if (NULL != table_list_) {
    ret = table_list_->SemanticAnalisys(sem_cnxt);
  } else {
    LOG(ERROR) << "No table found or invalid table name.";
    sem_cnxt->error_msg_ = "No table found or invalid table name.";
    ret = rNoTalbeFound;
  }
  return ret;
}
//}  // namespace sql_parser
//}  // namespace claims
