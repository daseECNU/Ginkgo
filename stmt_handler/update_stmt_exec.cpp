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
 * /CLAIMS/stmt_handler/delete_stmt_exec.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: cswang
 *		   Email: cs_wang@infosys.com
 *
 * Description:
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "../Environment.h"
#include "../stmt_handler/update_stmt_exec.h"

#include "../common/Block/BlockStream.h"
#include "../common/Block/ResultSet.h"
#include "../loader/data_injector.h"
#include "../loader/data_injector_for_parq.h"
#include "../catalog/table.h"
#include "../catalog/projection.h"
#include "../Daemon/Daemon.h"
#include "../sql_parser/ast_node/ast_select_stmt.h"
#include "../stmt_handler/select_exec.h"
#include "../common/error_define.h"
using claims::loader::DataInjector;
using claims::loader::DataInjectorForParq;
using std::endl;
using std::string;
using std::vector;
using std::cout;
using claims::catalog::TableDescriptor;
using claims::common::rSuccess;
using claims::common::rFailure;
using claims::common::rNoProjection;
using claims::common::rCreateProjectionOnDelTableFailed;
namespace claims {
namespace stmt_handler {

UpdateStmtExec::UpdateStmtExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  update_stmt_ast_ = dynamic_cast<AstUpdateStmt*>(stmt_);
}

UpdateStmtExec::~UpdateStmtExec() {}

RetCode UpdateStmtExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;
  string table_base_name =
      dynamic_cast<AstTable*>(update_stmt_ast_->update_table_)->table_name_;

  TableDescriptor* new_table =
      Environment::getInstance()->getCatalog()->getTable(table_base_name);

  SemanticContext sem_cnxt;
  ret = update_stmt_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->SetError("Semantic analysis error.\n" + sem_cnxt.error_msg_);
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  }

  AstTable* update_table =
      dynamic_cast<AstTable*>(update_stmt_ast_->update_table_);
  AstWhereClause* update_where =
      dynamic_cast<AstWhereClause*>(update_stmt_ast_->where_list_);
  AstUpdateSetList* update_set_list =
      dynamic_cast<AstUpdateSetList*>(update_stmt_ast_->update_set_list_);

  AstFromList* from_list = new AstFromList(AST_FROM_LIST, update_table, NULL);

  AstNode* appended_query_sel_stmt;
  ret = GenerateSelectForUpdateStmt(table_base_name, appended_query_sel_stmt);
  if (rSuccess == ret) {
    appended_query_sel_stmt->Print();
    SelectExec* appended_query_exec = new SelectExec(appended_query_sel_stmt);
    ret = appended_query_exec->Execute(exec_result);
    if (ret != rSuccess) {
      WLOG(ret, "failed to find the update tuples from the table ");
      delete appended_query_exec;
      return ret;
    }
    ostringstream ostr;
    ostr << exec_result->result_->getNumberOftuples() << " tuples updated.";

    /* STEP2 ： generate update selected data */
    vector<string> sel_result;
    ret = GenerateUpdateData(table_base_name, update_set_list, exec_result,
                             sel_result);
    delete exec_result->result_;
    exec_result->result_ = NULL;
    delete appended_query_exec;
    if (rSuccess != ret) {
      WLOG(ret, "updating tuples failed ");
      return ret;
    }
    /* STEP3 ： del update data */
    AstDeleteStmt* delete_stmt_ast =
        new AstDeleteStmt(AST_DELETE_STMT, from_list, update_where, 0);
    DeleteStmtExec* deletestmtexec = new DeleteStmtExec(delete_stmt_ast);
    ret = deletestmtexec->Execute(exec_result);
    if (ret != rSuccess) {
      WLOG(ret, "failed to find the update tuples from the table ");
      delete deletestmtexec;
      return ret;
    }
    /* STEP4 ：insert generate update selected data */
    InsertUpdatedDataIntoTable(table_base_name, exec_result, sel_result);
    exec_result->info_ = ostr.str();
    delete exec_result->result_;
    exec_result->result_ = NULL;
    delete deletestmtexec;
    return ret;
  } else if (rCreateProjectionOnDelTableFailed == ret) {
    WLOG(ret,
         "no projections has been created on the del table when delete tuples "
         "from the base table");
    return ret;
  }
  return ret;
}

RetCode UpdateStmtExec::GenerateSelectForUpdateStmt(
    const string table_name, AstNode*& appended_query_sel_stmt) {
  RetCode ret = rSuccess;
  if (rCreateProjectionOnDelTableFailed == ret) {
    WLOG(ret,
         "create projection on del table failed, since no projection has been "
         "created on the base table");
    return ret;
  }
  /* SELECT * FROM TABLLE */
  AstFromList* from_list =
      new AstFromList(AST_FROM_LIST, update_stmt_ast_->update_table_, NULL);
  AstNode* appended_query_sel_list =
      new AstSelectList(AST_SELECT_LIST, true, NULL, NULL);
  appended_query_sel_stmt = new AstSelectStmt(
      AST_SELECT_STMT, 0, appended_query_sel_list, from_list,
      update_stmt_ast_->where_list_, NULL, NULL, NULL, NULL, NULL);

  return ret;
}

RetCode UpdateStmtExec::GenerateUpdateData(string table_base_name,
                                           AstNode* update_set_list,
                                           ExecutedResult* exec_result,
                                           vector<string>& sel_result) {
  RetCode ret = rSuccess;
  DynamicBlockBuffer::Iterator it = exec_result->result_->createIterator();
  BlockStreamBase* block = NULL;
  BlockStreamBase::BlockStreamTraverseIterator* tuple_it = NULL;

  std::unordered_map<int, AstNode*> update_attr_list;

  AstUpdateSetList* update_set_list_temp = update_set_list;
  while (NULL != update_set_list_temp) {
    AstColumn* update_column =
        dynamic_cast<AstColumn*>(update_set_list_temp->args0_);
    AstExprConst* expr_const =
        dynamic_cast<AstExprConst*>(update_set_list_temp->args1_);

    int update_column_index = -1;
    for (unsigned i = 0; i < exec_result->result_->column_header_list_.size();
         i++) {
      if (exec_result->result_->column_header_list_[i] ==
          (table_base_name + "." + update_column->column_name_)) {
        update_column_index = i;
        break;
      }
    }
    if (update_column_index == -1) {
      ret = rFailure;
      string err_msg = "The column [" + table_base_name + "." +
                       update_column->column_name_ +
                       "] is not existed during update data.";
      LOG(ERROR) << err_msg << std::endl;
      exec_result->SetError(err_msg);
      return ret;
    }
    update_attr_list.insert({update_column_index, expr_const});
    update_set_list_temp = update_set_list_temp->next_;
  }
  unsigned int row_count = 0;
  ostringstream ostr;
  while (block = it.nextBlock()) {
    tuple_it = block->createIterator();
    void* tuple;
    while (tuple = tuple_it->nextTuple()) {
      for (unsigned i = 1; i < exec_result->result_->column_header_list_.size();
           i++) {
        if (update_attr_list.find(i) != update_attr_list.end()) {
          ostr << dynamic_cast<AstExprConst*>(update_attr_list[i])->data_;
        } else {
          ostr << exec_result->result_->schema_->getcolumn(i)
                      .operate->toString(exec_result->result_->schema_
                                             ->getColumnAddess(i, tuple))
                      .c_str();
        }
        ostr << "|";
      }
      ostr << "\n";
      ++row_count;
      if (row_count == 1000000) {
        sel_result.push_back(ostr.str());
        row_count = 0;
        ostr.str("");
      }
    }
    delete tuple_it;
  }
  if (row_count > 0) sel_result.push_back(ostr.str());
  return ret;
}

void UpdateStmtExec::InsertUpdatedDataIntoTable(string table_name,
                                                ExecutedResult* exec_result,
                                                vector<string>& sel_result) {
  TableDescriptor* table =
      Environment::getInstance()->getCatalog()->getTable(table_name);
  if (NULL == table) {
    LOG(ERROR) << "The table " + table_name +
                      " is not existed during update data." << std::endl;
    return;
  }
  if (Config::enable_parquet) {
    DataInjectorForParq* injector = new DataInjectorForParq(table);
    injector->InsertFromStringMultithread(sel_result, exec_result);
    DELETE_PTR(injector);
  } else {
    DataInjector* injector = new DataInjector(table);
    injector->InsertFromStringMultithread(sel_result, exec_result);
    DELETE_PTR(injector);
  }
}

RetCode UpdateStmtExec::GetWriteAndReadTables(
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  string name =
      dynamic_cast<AstTable*>(update_stmt_ast_->update_table_)->table_name_;
  table_status.first = 1;
  table_status.second = name;
  table_list.push_back(table_status);
  stmt_to_table_list.push_back(table_list);
  return ret;
}
} /* namespace stmt_handler */
} /* namespace claims */
