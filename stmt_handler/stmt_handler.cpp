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
 * /CLAIMS/stmt_handler/stmt_handler.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include <glog/logging.h>
#include <iostream>
#include <string>
#include "../stmt_handler/stmt_handler.h"
#include "../common/memory_handle.h"
#include <boost/algorithm/string.hpp>
#include "../stmt_handler/create_projection_exec.h"
#include "../stmt_handler/desc_exec.h"
#include "../stmt_handler/drop_table_exec.h"
#include "../stmt_handler/select_exec.h"
#include "../stmt_handler/truncate_table_exec.h"
#include "../stmt_handler/drop_proj_exec.h"
#include "../stmt_handler/show_exec.h"
#include "../stmt_handler/export_exec.h"
#include "../utility/Timer.h"
#include "../common/error_define.h"

using boost::algorithm::to_lower;
using boost::algorithm::trim;
using claims::common::rUnknowStmtType;
using claims::common::rSQLParserErr;
namespace claims {
namespace stmt_handler {

StmtHandler::StmtHandler(string sql_stmt)
    : sql_stmt_(sql_stmt), stmt_exec_(NULL), sql_parser_(NULL) {}
StmtHandler::StmtHandler(string sql_stmt, ExecutedResult* exec_result)
    : sql_stmt_(sql_stmt), stmt_exec_(NULL), sql_parser_(NULL) {}
StmtHandler::~StmtHandler() {
  if (NULL != stmt_exec_) {
    delete stmt_exec_;
    stmt_exec_ = NULL;
  }
  if (NULL != sql_parser_) {
    delete sql_parser_;
    sql_parser_ = NULL;
  }
}

RetCode StmtHandler::GenerateStmtExec(AstNode* stmt_ast) {
  switch (stmt_ast->ast_node_type_) {
    case AST_SELECT_STMT: {
      stmt_exec_ = new SelectExec(stmt_ast, sql_stmt_);
      break;
    }
    case AST_INSERT_STMT: {
      stmt_exec_ = new InsertExec(stmt_ast);
      break;
    }
    case AST_LOAD_TABLE: {
      stmt_exec_ = new LoadExec(stmt_ast);
      break;
    }
    case AST_SHOW_STMT: {
      stmt_exec_ = new ShowExec(stmt_ast);
      break;
    }
    case AST_DESC_STMT: {
      stmt_exec_ = new DescExec(stmt_ast);
      break;
    }
    case AST_CREATE_TABLE_LIST:
    case AST_CREATE_TABLE_LIST_SEL:
    case AST_CREATE_TABLE_SEL: {
      stmt_exec_ = new CreateTableExec(stmt_ast);
      break;
    }
    case AST_CREATE_PROJECTION:
    case AST_CREATE_PROJECTION_NUM: {
      stmt_exec_ = new CreateProjectionExec(stmt_ast);
      break;
    }
    case AST_DROP_TABLE: {
      stmt_exec_ = new DropTableExec(stmt_ast);
      break;
    }
    case AST_DROP_PROJECTION: {
      stmt_exec_ = new DropProjExec(stmt_ast);
      break;
    }
    case AST_DELETE_STMT: {
      stmt_exec_ = new DeleteStmtExec(stmt_ast);
      break;
    }
    case AST_UPDATE_STMT: {
      stmt_exec_ = new UpdateStmtExec(stmt_ast);
      break;
    }
    case AST_TRUNCATE_TABLE: {
      stmt_exec_ = new TruncateTableExec(stmt_ast);
      break;
    }
    case AST_EXPORT_TABLE: {
      stmt_exec_ = new ExportExec(stmt_ast);
      break;
    }
    default: {
      LOG(ERROR) << "unknow statement type!" << std::endl;
      return rUnknowStmtType;
    }
  }
  return rSuccess;
}

RetCode StmtHandler::Execute(ExecutedResult& result) {
  RetCode ret = rSuccess;
  ExecutedResult* exec_result = &result;
  if (stmt_list_->stmt_ != NULL) {
    ret = GenerateStmtExec(stmt_list_->stmt_);
    if (rSuccess != ret) {
      Daemon::getInstance()->addExecutedResult(result);
      return ret;
    }
    ret = stmt_exec_->Execute(exec_result);
    if (rSuccess != ret) {
      Daemon::getInstance()->addExecutedResult(result);
      return ret;
    }
    Daemon::getInstance()->addExecutedResult(result);
  }
  if (stmt_list_->next_ != NULL) {
    stmt_list_ = reinterpret_cast<AstStmtList*>(stmt_list_->next_);
  }
  return ret;
}

RetCode StmtHandler::StmtParser(ExecutedResult& result) {
  RetCode ret = rSuccess;
  sql_parser_ = new Parser(sql_stmt_, result.info_);
  AstNode* raw_ast = sql_parser_->GetRawAST();
  if (NULL == raw_ast) {
    result.error_info_ = "Parser Error\n" + result.info_;
    result.status_ = false;
    result.result_ = NULL;
    Daemon::getInstance()->addExecutedResult(result);
    return rSQLParserErr;
  }
  // print the raw ast if it's necessary.
  raw_ast->Print();
  return ret;
}

RetCode StmtHandler::StmtContentAnalysis(
    ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  stmt_list_ = reinterpret_cast<AstStmtList*>(sql_parser_->GetRawAST());
  if (stmt_list_->stmt_ != NULL) {
    ret = GetTablesInfomation(stmt_list_->stmt_, result, stmt_to_table_list);
    if (rSuccess != ret) {
      cout << "GetTablesInfomation Wrong" << endl;
      Daemon::getInstance()->addExecutedResult(result);
      return ret;
    }
  }
  while (stmt_list_->next_ != NULL) {
    stmt_list_ = reinterpret_cast<AstStmtList*>(stmt_list_->next_);
    ret = GetTablesInfomation(stmt_list_->stmt_, result, stmt_to_table_list);
    if (rSuccess != ret) {
      cout << "GetTablesInformation Wrong" << endl;
      Daemon::getInstance()->addExecutedResult(result);
      return ret;
    }
  }
  stmt_list_ = reinterpret_cast<AstStmtList*>(sql_parser_->GetRawAST());
  return ret;
}

RetCode StmtHandler::GetTablesInfomation(
    AstNode* stmt_ast, ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  pair<int, string> table_status;
  vector<pair<int, string>> table_list;
  switch (stmt_ast->ast_node_type_) {
    case AST_SELECT_STMT: {
      stmt_exec_ = new SelectExec(stmt_ast, sql_stmt_);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_INSERT_STMT: {
      stmt_exec_ = new InsertExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_LOAD_TABLE: {
      stmt_exec_ = new LoadExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_SHOW_STMT: {
      stmt_exec_ = new ShowExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_DESC_STMT: {
      stmt_exec_ = new DescExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_CREATE_TABLE_LIST:
    case AST_CREATE_TABLE_LIST_SEL:
    case AST_CREATE_TABLE_SEL: {
      stmt_exec_ = new CreateTableExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_CREATE_PROJECTION:
    case AST_CREATE_PROJECTION_NUM: {
      stmt_exec_ = new CreateProjectionExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_DROP_TABLE: {
      stmt_exec_ = new DropTableExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_DROP_PROJECTION: {
      stmt_exec_ = new DropProjExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_DELETE_STMT: {
      stmt_exec_ = new DeleteStmtExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_UPDATE_STMT: {
      stmt_exec_ = new UpdateStmtExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_TRUNCATE_TABLE: {
      stmt_exec_ = new TruncateTableExec(stmt_ast);
      ret = stmt_exec_->GetWriteAndReadTables(result, stmt_to_table_list);
      break;
    }
    case AST_EXPORT_TABLE: {
      stmt_exec_ = new ExportExec(stmt_ast);
      stmt_exec_->GetWriteAndReadTables(result,stmt_to_table_list);
      break;
    }
    default: {
      LOG(ERROR) << "unknow statement type!" << std::endl;
      return rUnknowStmtType;
    }
  }
  return ret;
}
}  // namespace stmt_handler
}  // namespace claims
