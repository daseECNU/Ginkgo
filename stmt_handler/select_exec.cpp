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
 * /CLAIMS/stmt_handler/select_exec.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "../stmt_handler/select_exec.h"
#include "../sql_parser/ast_node/ast_create_stmt.h"
#include "../stmt_handler/create_projection_exec.h"
#include "../loader/data_injector.h"
#include <glog/logging.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <unordered_map>

#include "../common/error_define.h"
#include "../common/ids.h"
#include "../exec_tracker/stmt_exec_tracker.h"
#include "../Environment.h"
#include "../logical_operator/logical_query_plan_root.h"
#include "../physical_operator/exchange_sender.h"
#include "../physical_operator/exchange_sender_pipeline.h"
#include "../physical_operator/physical_aggregation.h"
#include "../physical_operator/physical_nest_loop_join.h"
#include "../physical_operator/physical_operator_base.h"
#include "caf/io/all.hpp"
using caf::io::remote_actor;
using claims::logical_operator::LogicalQueryPlanRoot;
using claims::physical_operator::ExchangeSender;
using claims::physical_operator::ExchangeSenderPipeline;
using claims::physical_operator::PhysicalAggregation;
using claims::physical_operator::PhysicalNestLoopJoin;
using claims::physical_operator::PhysicalOperatorBase;
using claims::physical_operator::PhysicalOperatorType;
using std::endl;
using std::vector;
using std::string;
using std::cout;
using std::make_pair;
using claims::common::rStmtCancelled;
using claims::loader::DataInjector;
namespace claims {
namespace stmt_handler {
AstDataType* GenerateDataType(Schema* schema, int i);
AstColumnAtts* GenerateColumnAtts(Schema* schema, int i);
int GenerateDatatypeBytype(int a);
RetCode execSelectInto(StmtExecStatus* exec_status,
                       AstSelectIntoClause* select_into,
                       ExecutedResult* exec_result);
//#define PRINTCONTEXT
SelectExec::SelectExec(AstNode* stmt, string raw_sql)
    : StmtExec(stmt), raw_sql_(raw_sql) {
  select_ast_ = reinterpret_cast<AstSelectStmt*>(stmt_);
}
SelectExec::SelectExec(AstNode* stmt) : StmtExec(stmt), raw_sql_("") {
  select_ast_ = reinterpret_cast<AstSelectStmt*>(stmt_);
}
SelectExec::~SelectExec() {
  //  if (NULL != select_ast_) {
  //    delete select_ast_;
  //    select_ast_ = NULL;
  //  }
  while (!all_segments_.empty()) {
    delete all_segments_.top();
    all_segments_.pop();
  }
}

RetCode SelectExec::Execute(ExecutedResult* exec_result) {
  GETCURRENTTIME(start_time);
  // exec_status is deleted by tracker
  StmtExecStatus* exec_status = new StmtExecStatus(raw_sql_);
  exec_status->RegisterToTracker();
  set_stmt_exec_status(exec_status);
  RetCode ret = Execute();
  if (rSuccess != ret) {
    exec_result->result_ = NULL;
    exec_result->status_ = false;
    exec_result->error_info_ = raw_sql_ + string(" execution error!");
    exec_status->set_exec_status(StmtExecStatus::ExecStatus::kError);
    cout << "rSuccess != ret" << endl;
    return ret;
  } else {
    if (StmtExecStatus::ExecStatus::kCancelled ==
        exec_status->get_exec_status()) {
      exec_result->result_ = NULL;
      exec_result->status_ = false;
      exec_result->error_info_ = raw_sql_ + string(" have been cancelled!");
      exec_status->set_exec_status(StmtExecStatus::ExecStatus::kError);
    } else if (StmtExecStatus::ExecStatus::kOk ==
               exec_status->get_exec_status()) {
      if (select_ast_->select_into_clause_ != NULL) {
        AstSelectIntoClause* select_into =
            reinterpret_cast<AstSelectIntoClause*>(
                select_ast_->select_into_clause_);
        execSelectInto(exec_status, select_into, exec_result);
        exec_status->get_query_result()->destory();
        delete exec_status->get_query_result();
        exec_result->status_ = true;
        exec_status->set_exec_status(StmtExecStatus::ExecStatus::kDone);
      } else {
        exec_result->result_ = exec_status->get_query_result();
        exec_result->status_ = true;
        exec_result->info_ = exec_status->get_exec_info();
        exec_status->set_exec_status(StmtExecStatus::ExecStatus::kDone);
      }

    } else {
      assert(false);
      exec_status->set_exec_status(StmtExecStatus::ExecStatus::kError);
    }
  }

  double exec_time_ms = GetElapsedTime(start_time);
  if (NULL != exec_result->result_) {
    exec_result->result_->query_time_ = exec_time_ms / 1000.0;
  }
  LOG(INFO) << raw_sql_ << " execution time: " << exec_time_ms / 1000.0
            << " sec" << endl;

  return rSuccess;
}

RetCode SelectExec::Execute() {
#ifdef PRINTCONTEXT
  select_ast_->Print();
  cout << "--------------begin semantic analysis---------------" << endl;
#endif
  SemanticContext sem_cnxt;
  RetCode ret = rSuccess;
  ret = select_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    stmt_exec_status_->set_exec_info("semantic analysis error \n" +
                                     sem_cnxt.error_msg_);
    stmt_exec_status_->set_exec_status(StmtExecStatus::ExecStatus::kError);
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    return ret;
  }

#ifdef PRINTCONTEXT
  select_ast_->Print();
  cout << "--------------begin push down condition ------------" << endl;
#endif
  PushDownConditionContext pdccnxt;
  ret = select_ast_->PushDownCondition(pdccnxt);
  if (rSuccess != ret) {
    stmt_exec_status_->set_exec_info("push down condition error");
    stmt_exec_status_->set_exec_status(StmtExecStatus::ExecStatus::kError);
    stmt_exec_status_->set_query_result(NULL);
    ELOG(ret, stmt_exec_status_->get_exec_info());
    cout << stmt_exec_status_->get_exec_info();
    return ret;
  }
  //#ifndef PRINTCONTEXT
  ret = select_ast_->SetScanAttrList(&sem_cnxt);
  if (rSuccess != ret) {
    stmt_exec_status_->set_exec_info("semantic analysis error \n" +
                                     sem_cnxt.error_msg_);
    stmt_exec_status_->set_exec_status(StmtExecStatus::ExecStatus::kError);
    LOG(ERROR) << " Set Scan Attribute list error result= : " << ret;
    return ret;
  }
  //  select_ast_->Print();
  cout << "--------------begin logical plan -------------------" << endl;
  //#endif

  LogicalOperator* logic_plan = NULL;
  ret = select_ast_->GetLogicalPlan(logic_plan);
  if (rSuccess != ret) {
    stmt_exec_status_->set_exec_info("get logical plan error");
    stmt_exec_status_->set_exec_status(StmtExecStatus::ExecStatus::kError);
    stmt_exec_status_->set_query_result(NULL);
    ELOG(ret, stmt_exec_status_->get_exec_info());
    cout << stmt_exec_status_->get_exec_info();
    delete logic_plan;
    return ret;
  }
  logic_plan = new LogicalQueryPlanRoot(0, logic_plan, raw_sql_,
                                        LogicalQueryPlanRoot::kResultCollector);
  logic_plan->GetPlanContext();
  // if there is select * or select A.* , do not use prune_column
  bool prune_column_flag = true;
  if (((AstSelectList*)(select_ast_->select_list_))->is_all_ == 1)
    prune_column_flag = false;
  if (sem_cnxt.is_all) prune_column_flag = false;
  for (auto it = sem_cnxt.table_to_column.begin();
       it != sem_cnxt.table_to_column.end(); it++) {
    if (it->second.size() == 1 && it->second.find("*") != it->second.end()) {
      prune_column_flag = false;
    }
  }
  if (Config::enable_prune_column & prune_column_flag) {
    set<string> attrs;
    logic_plan->PruneProj(attrs);
  }
  logic_plan->GetPlanContext();
#ifndef PRINTCONTEXT
  logic_plan->Print();
  cout << "--------------begin physical plan -------------------" << endl;
#endif

  PhysicalOperatorBase* physical_plan = logic_plan->GetPhysicalPlan(64 * 1024);
#ifndef PRINTCONTEXT
  physical_plan->Print();
  cout << "--------------begin output result -------------------" << endl;
#endif
  // collect all plan segments
  physical_plan->GetAllSegments(&all_segments_);
  // create thread to send all segments
  pthread_t tid = 0;
  // add segment_exec_status to stmt_exec_status_
  SegmentExecStatus* seg_exec_status_1 = new SegmentExecStatus(
      make_pair(stmt_exec_status_->get_query_id(),
                Environment::getInstance()->get_slave_node()->get_node_id()));

  stmt_exec_status_->AddSegExecStatus(seg_exec_status_1);

  if (all_segments_.size() > 0) {
    int ret = pthread_create(&tid, NULL, SendAllSegments, this);
  }
  // this segment_exec_status for reporting status
  SegmentExecStatus* seg_exec_status = new SegmentExecStatus(
      make_pair(stmt_exec_status_->get_query_id(),
                Environment::getInstance()->get_slave_node()->get_node_id()),
      Environment::getInstance()->get_slave_node()->get_node_id());
  seg_exec_status->RegisterToTracker();

  bool pret = physical_plan->Open(seg_exec_status);
  if (pret) {
    seg_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kOk,
                                  "physical plan Open() succeed at collector",
                                  0, true);
    while (physical_plan->Next(seg_exec_status, NULL)) {
    }
    seg_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kOk,
                                  "physical plan next() succeed", 0, true);
    // the difference from the execution of normal segment due to getting result
    stmt_exec_status_->set_query_result(physical_plan->GetResultSet());
    stmt_exec_status_->set_exec_info(string("execute a query successfully"));
  } else {
    seg_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kError,
                                  "physical plan open() failed at collector", 0,
                                  true);
    stmt_exec_status_->set_query_result(NULL);
    stmt_exec_status_->set_exec_info(string("execute a query failed"));
  }
  physical_plan->Close(seg_exec_status);
  seg_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kDone,
                                "physical plan close() succeed", 0, true);

  if (tid != 0) {
    //    if (StmtExecStatus::kCancelled ==
    //    stmt_exec_status_->get_exec_status()) {
    //      pthread_cancel(tid);
    //    }
    pthread_join(tid, NULL);
  }

  ret = rSuccess;
  delete logic_plan;
  delete physical_plan;
  return ret;
}
//!!!return ret by global variant
void* SelectExec::SendAllSegments(void* arg) {
  RetCode ret = 0;
  SelectExec* select_exec = reinterpret_cast<SelectExec*>(arg);
  short segment_id = 0;
  while (!select_exec->all_segments_.empty()) {
    pthread_testcancel();
    if (select_exec->stmt_exec_status_->IsCancelled()) {
      return NULL;
    }
    auto a_plan_segment = select_exec->all_segments_.top();
    // make sure upper exchanges are prepared
    ret = select_exec->IsUpperExchangeRegistered(
        a_plan_segment->upper_node_id_list_, a_plan_segment->exchange_id_);
    if (rSuccess == ret) {
      auto physical_sender_oper = a_plan_segment->get_plan_segment();
      for (int i = 0; i < a_plan_segment->lower_node_id_list_.size(); ++i) {
        pthread_testcancel();
        if (select_exec->stmt_exec_status_->IsCancelled()) {
          return NULL;
        }
        // set partition offset for each segment
        reinterpret_cast<ExchangeSender*>(physical_sender_oper)
            ->SetPartitionOffset(i);
        segment_id = select_exec->get_stmt_exec_status()->GenSegmentId();

        // new SegmentExecStatus and add it to StmtExecStatus
        SegmentExecStatus* seg_exec_status = new SegmentExecStatus(make_pair(
            select_exec->get_stmt_exec_status()->get_query_id(),
            segment_id * kMaxNodeNum + a_plan_segment->lower_node_id_list_[i]));

        select_exec->get_stmt_exec_status()->AddSegExecStatus(seg_exec_status);
        // send plan
        if (Environment::getInstance()
                ->get_iterator_executor_master()
                ->ExecuteBlockStreamIteratorsOnSite(
                    physical_sender_oper,
                    a_plan_segment->lower_node_id_list_[i],
                    select_exec->get_stmt_exec_status()->get_query_id(),
                    segment_id) == false) {
          LOG(ERROR) << "sending plan of "
                     << select_exec->get_stmt_exec_status()->get_query_id()
                     << " , " << segment_id << "error!!!" << endl;
          ret = -1;
          return &ret;
        }

        LOG(INFO) << "sending plan of "
                  << select_exec->get_stmt_exec_status()->get_query_id()
                  << " , " << segment_id << "succeed!!!" << endl;
      }
    } else {
      LOG(ERROR) << "asking upper exchange failed!" << endl;
      return &ret;
    }
    select_exec->all_segments_.pop();
    DELETE_PTR(a_plan_segment);
  }
  return &ret;
}
RetCode SelectExec::IsUpperExchangeRegistered(
    vector<NodeID>& upper_node_id_list, const u_int64_t exchange_id) {
  RetCode ret = rSuccess;
  NodeAddress node_addr;
  int times = 0;
  /// TODO(fzh)should release the strong synchronization
  for (int i = 0; i < upper_node_id_list.size(); ++i) {
    auto target_actor =
        Environment::getInstance()->get_slave_node()->GetNodeActorFromId(
            upper_node_id_list[i]);
    while (Environment::getInstance()
               ->getExchangeTracker()
               ->AskForSocketConnectionInfo(ExchangeID(exchange_id, i),
                                            upper_node_id_list[i], node_addr,
                                            target_actor) != true) {
      if (stmt_exec_status_->IsCancelled()) {
        return -1;
      }

      LOG(WARNING) << "busy asking socket connection info of node = "
                   << upper_node_id_list[i] << " , total times= " << ++times
                   << endl;
      usleep(200);
    }
  }
  return ret;
}
RetCode SelectExec::GetWriteAndReadTables(
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  AstFromList* from_list =
      reinterpret_cast<AstFromList*>(select_ast_->from_list_);
  AstTable* table = reinterpret_cast<AstTable*>(from_list->args_);
  table_status.first = 0;
  cout << "table->table_name_:" << table->table_name_ << endl;
  table_status.second = table->table_name_;
  cout << "table_status.second:" << table_status.second << endl;
  table_list.push_back(table_status);
  while (from_list->next_ != NULL) {
    from_list = reinterpret_cast<AstFromList*>(from_list->next_);
    AstTable* table = reinterpret_cast<AstTable*>(from_list->args_);
    table_status.first = 0;
    cout << "table->table_name_:" << table->table_name_ << endl;
    table_status.second = table->table_name_;
    cout << "table_status.second:" << table_status.second << endl;
    table_list.push_back(table_status);
  }
  if (select_ast_->select_into_clause_ != NULL) {
    AstSelectIntoClause* select_into_clause =
        reinterpret_cast<AstSelectIntoClause*>(
            select_ast_->select_into_clause_);
    AstTable* table = reinterpret_cast<AstTable*>(select_into_clause->table_);
    table_status.first = 1;
    table_status.second = table->table_name_;
    table_list.push_back(table_status);
  }
  stmt_to_table_list.push_back(table_list);
  return ret;
}

int isUnsigned(data_type type) {
  switch (type) {
    case t_u_long:
    case t_u_smallInt:
      return 1;
    default:
      return 0;
  }
}

AstDataType* GenerateDataType(Schema* schema, int i) {
  data_type type = schema->getcolumn(i).type;
  AstOptLength* opt_length = NULL;
  if (type == data_type::t_decimal) {
    OperateDecimal* oper = schema->getcolumn(i).operate;
    int precision = oper->getPrecision();
    int scale = oper->getScale();
    opt_length = new AstOptLength(AST_OPT_LENGTH, precision, scale);
  } else if (type == data_type::t_string) {
    OperateString* oper = schema->getcolumn(i).operate;
    unsigned size = oper->getSize();
    opt_length = new AstOptLength(AST_OPT_LENGTH, size, 0);
  }
  return new AstDataType(AST_DATA_TYPE, GenerateDatatypeBytype(type),
                         opt_length, isUnsigned(type), NULL, 0, NULL);
}

AstColumnAtts* GenerateColumnAtts(Schema* schema, int i) {
  if (schema->getcolumn(i).operate->nullable) {
    // can be null
    return new AstColumnAtts(AST_COLUMN_ATTS, 2, 0, 0, "", NULL);
  } else {
    return new AstColumnAtts(AST_COLUMN_ATTS, 1, 0, 0, "", NULL);
  }
}
int GenerateDatatypeBytype(int a) {
  switch (a) {
    case t_smallInt:
      return 3;
    case t_int:
      return 5;
    case t_u_long:
      return 7;
    case t_float:
      return 10;
    case t_double:
      return 9;
    case t_string:
      return 18;
    case t_date:
      return 12;
    case t_time:
      return 13;
    case t_datetime:
      return 15;
    case t_decimal:
      return 11;
    case t_boolean:
      return 1;
    case t_u_smallInt:
      return 3;
  }
}
RetCode createTableAndProj(StmtExecStatus* exec_status,
                           AstSelectIntoClause* select_into,
                           ExecutedResult* exec_result) {
  RetCode ret = rSuccess;
  ExecutedResult tmp_exec_result;
  std::ostringstream ostr;
  tmp_exec_result.result_ = exec_status->get_query_result();
  tmp_exec_result.status_ = true;
  string table_name =
      reinterpret_cast<AstTable*>(select_into->table_)->table_name_;
  // initialize create info
  AstCreateDef* data;
  AstCreateColList* create_col_ptr, *create_col_head;
  AstColumn* col_ptr, *col_head;
  int size = tmp_exec_result.result_->column_header_list_.size();
  bool ishead = true;
  for (int i = 0; i < size; i++) {
    string column_name = tmp_exec_result.result_->column_header_list_[i];
    // if select * we need remove table name and row_id
    if (column_name.find("row_id") == string::npos) {
      if (i == size - 1) {
        column_name = column_name.substr(0, column_name.find(" "));
      }
      if (column_name.find(".") != string::npos) {
        column_name = column_name.substr(column_name.find(".") + 1,
                                         column_name.length() - 1);
      }
      AstDataType* data_type =
          GenerateDataType(tmp_exec_result.result_->schema_, i);
      AstColumnAtts* column_attr =
          GenerateColumnAtts(tmp_exec_result.result_->schema_, i);
      data = new AstCreateDef(AST_CREATE_DEF_NAME, 1, column_name, data_type,
                              column_attr, NULL);
      if (ishead) {
        create_col_ptr = new AstCreateColList(AST_CREATE_COL_LIST, data, NULL);
        create_col_head = create_col_ptr;
        col_ptr = new AstColumn(AST_COLUMN, table_name, column_name, NULL);
        col_head = col_ptr;
        ishead = false;
      } else {
        create_col_ptr->next_ =
            new AstCreateColList(AST_CREATE_COL_LIST, data, NULL);
        create_col_ptr = create_col_ptr->next_;
        col_ptr->next_ =
            new AstColumn(AST_COLUMN, table_name, column_name, NULL);
        col_ptr = col_ptr->next_;
      }
    }
  }

  AstCreateTable* createtable_ast = new AstCreateTable(
      AST_CREATE_TABLE_LIST, 0, 0, table_name, "", create_col_head, NULL);
  CreateTableExec createtable(createtable_ast);
  ret = createtable.Execute(&tmp_exec_result);
  if (ret != common::rStmtHandlerCreateTableSuccess) {
    ostr.clear();
    LOG(ERROR) << "create table or create projection failure on  " << table_name
               << endl;
    ostr << "create table or create projection failure on  " << table_name
         << endl;
    exec_result->SetError(ostr.str());
  }
  // create projection
  AstCreateProjection* ast_proj;
  if (select_into->partition_number_ == 1) {
    ast_proj = new AstCreateProjection(AST_CREATE_PROJECTION, table_name,
                                       col_head, select_into->partition_number_,
                                       select_into->partition_key_);
  } else {
    ast_proj = new AstCreateProjection(AST_CREATE_PROJECTION_NUM, table_name,
                                       col_head, select_into->partition_number_,
                                       select_into->partition_key_);
  }
  CreateProjectionExec* createpro = new CreateProjectionExec(ast_proj);
  ret = createpro->Execute(&tmp_exec_result);
  // clear all memory
  delete createtable_ast;
  delete createpro;
  delete ast_proj;
  return ret;
}
RetCode execSelectInto(StmtExecStatus* exec_status,
                       AstSelectIntoClause* select_into,
                       ExecutedResult* exec_result) {
  // initialize a result for execute
  RetCode ret = rSuccess;
  string table_name =
      reinterpret_cast<AstTable*>(select_into->table_)->table_name_;
  std::ostringstream ostr;
  ret = createTableAndProj(exec_status, select_into, exec_result);
  if (ret != rSuccess) {
    return ret;
  }
  // insert into table
  unsigned int row_change = 0;
  TableDescriptor* insert_table =
      Environment::getInstance()->getCatalog()->getTable(table_name);
  DataInjector* injector = new DataInjector(insert_table);
  vector<string> sel_result;
  exec_status->get_query_result()->getResult(row_change, sel_result);
  ret = injector->InsertFromStringMultithread(sel_result, exec_result);
  if (rSuccess == ret) {
    ostr.clear();
    ostr << "insert data successfully. " << row_change << " rows changed.";
    exec_result->SetResult(ostr.str(), NULL);
  } else {
    LOG(ERROR) << "failed to insert tuples into table:"
               << insert_table->getTableName() << endl;
    exec_result->SetError("failed to insert tuples into table ");
  }
  DELETE_PTR(injector);
  return ret;
}
}  // namespace stmt_handler
}  // namespace claims
