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
 *  /Ginkgo/sql_parser/ast_node/ast_union_stmt.cpp
 *  Created on: May 31, 2018 10:19:13 PM
 *  Modified on: May 31, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 */

#include "ast_union_stmt.h"

#include "./ast_select_stmt.h"
using namespace claims::common;

AstUnionStmt::AstUnionStmt(AstNodeType ast_node_type, AstNode* lselect_stmt,
                           AstNode* rselect_stmt)
    : AstNode(ast_node_type),
      lselect_stmt_(lselect_stmt),
      rselect_stmt_(rselect_stmt) {}

AstUnionStmt::~AstUnionStmt() {}
RetCode AstUnionStmt::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (lselect_stmt_ != NULL) {
    if (lselect_stmt_->ast_node_type_ == AST_UNION_STMT) {
      AstUnionStmt* ls_stmt_ = reinterpret_cast<AstUnionStmt*>(lselect_stmt_);
      ret = ls_stmt_->SemanticAnalisys(sem_cnxt);
    } else if (lselect_stmt_->ast_node_type_ == AST_SELECT_STMT) {
      SemanticContext sem;
      sem_cnxt = &sem;
      AstSelectStmt* ls_stmt_ = reinterpret_cast<AstSelectStmt*>(lselect_stmt_);
      ret = ls_stmt_->SemanticAnalisys(sem_cnxt);
      if (ret != rSuccess) return ret;
    } else {
      ret = rGetUnionChild;
      return ret;
    }
  }
  if (rselect_stmt_ != NULL) {
    if (rselect_stmt_->ast_node_type_ == AST_UNION_STMT) {
      AstUnionStmt* rs_stmt_ = reinterpret_cast<AstUnionStmt*>(rselect_stmt_);
      ret = rs_stmt_->SemanticAnalisys(sem_cnxt);
    } else if (rselect_stmt_->ast_node_type_ == AST_SELECT_STMT) {
      SemanticContext sem2;

      sem_cnxt = &sem2;
      AstSelectStmt* rs_stmt_ = reinterpret_cast<AstSelectStmt*>(rselect_stmt_);
      ret = rs_stmt_->SemanticAnalisys(sem_cnxt);
    } else {
      ret = rGetUnionChild;
      return ret;
    }
  }
  //  sem_cnxt->RebuildTableColumn();
  return ret;
}
void AstUnionStmt::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Union Stmt|" << endl;
  level++;
  if (lselect_stmt_ != NULL) {
    if (lselect_stmt_->ast_node_type_ == AST_UNION_STMT) {
      AstUnionStmt* ls_stmt_ = reinterpret_cast<AstUnionStmt*>(lselect_stmt_);
      ls_stmt_->Print(level);
    } else if (lselect_stmt_->ast_node_type_ == AST_SELECT_STMT) {
      AstSelectStmt* ls_stmt_ = reinterpret_cast<AstSelectStmt*>(lselect_stmt_);
      ls_stmt_->Print(level);
    }
  }
  if (rselect_stmt_ != NULL) {
    if (rselect_stmt_->ast_node_type_ == AST_UNION_STMT) {
      AstUnionStmt* rs_stmt_ = reinterpret_cast<AstUnionStmt*>(rselect_stmt_);
      rs_stmt_->Print(level);
    } else if (rselect_stmt_->ast_node_type_ == AST_SELECT_STMT) {
      AstSelectStmt* rs_stmt_ = reinterpret_cast<AstSelectStmt*>(rselect_stmt_);
      rs_stmt_->Print(level);
    }
  }
}
