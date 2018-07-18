/*
 * Copyright [2012-2017] DaSE@ECNU
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
 * /CLAIMS/stmt_handler/union_stmt.cpp
 *
 *  Created on: May 20, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 *
 * Description:
 *
 */
#include "../stmt_handler/union_stmt.h"

#include <iostream>
#include <string>

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
#include "../stmt_handler/select_exec.h"
#include "../sql_parser/ast_node/ast_create_stmt.h"
#include "../stmt_handler/create_projection_exec.h"
#include "../loader/data_injector.h"
#include "../loader/data_injector_for_parq.h"
#include "../common/error_define.h"
#include "../common/ids.h"
#include "../exec_tracker/stmt_exec_tracker.h"
#include "../Environment.h"
#include "../logical_operator/logical_union.h"
#include "../logical_operator/logical_query_plan_root.h"
#include "../logical_operator/logical_aggregation.h"
#include "../physical_operator/exchange_sender.h"
#include "../physical_operator/exchange_sender_pipeline.h"
#include "../physical_operator/physical_nest_loop_join.h"
#include "../physical_operator/physical_operator_base.h"
#include "caf/io/all.hpp"
using caf::io::remote_actor;
using claims::logical_operator::LogicalUnion;
using claims::logical_operator::LogicalQueryPlanRoot;
using claims::logical_operator::LogicalAggregation;
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
using claims::loader::DataInjectorForParq;

using claims::common::rGetUnionChild;
using claims::common::rUnionnomatch;
using claims::common::Malloc;
namespace claims {
namespace stmt_handler {
UnionExec::UnionExec(AstNode* stmt, string raw_sql)
    : StmtExec(stmt), raw_sql_(raw_sql) {
  setop_ast_ = reinterpret_cast<AstUnionStmt*>(stmt_);
  groupby_attrs_.clear();
  distinct_attrs_.clear();
  agg_attrs_.clear();
}
UnionExec::UnionExec(AstNode* stmt) : StmtExec(stmt), raw_sql_("") {
  setop_ast_ = reinterpret_cast<AstUnionStmt*>(stmt_);
}
UnionExec::~UnionExec() {}
RetCode UnionExec::Execute(ExecutedResult* exec_result) {
  GETCURRENTTIME(start_time);
  StmtExecStatus* exec_status = new StmtExecStatus(raw_sql_);
  exec_status->RegisterToTracker();
  set_stmt_exec_status(exec_status);
  result_ = new ResultSet();  // have no delete.
  RetCode ret = Execute();
  if (rSuccess != ret) {
    exec_result->result_ = NULL;
    exec_result->status_ = false;
    exec_result->error_info_ = raw_sql_ + string(" execution error!");
    exec_status->set_exec_status(StmtExecStatus::ExecStatus::kError);
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
      exec_result->result_ = exec_status->get_query_result();
      exec_result->status_ = true;
      exec_result->info_ = exec_status->get_exec_info();
      exec_status->set_exec_status(StmtExecStatus::ExecStatus::kDone);

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
RetCode UnionExec::Execute() {
  int ret = rSuccess;
  SemanticContext sem_cnxt_;
  LogicalOperator* llogic_plan = NULL;
  LogicalOperator* rlogic_plan = NULL;
  LogicalOperator* logic_plan = NULL;

  StmtExec* select_exec_;  // = select_ast_list_[0];

  ret = UnionExec::GetChildStmt(setop_ast_);
  if (ret != rSuccess) {
    LOG(ERROR) << "Get childstmt failed in setop_exec" << endl;
    return ret;
  }

  ret = UnionExec::Checkcolumn();
  if (ret != rSuccess) {
    LOG(ERROR) << "the columns are inequality." << endl;
    return ret;
  }
  vector<LogicalOperator*> children;
  children.clear();
  for (auto i = 0; i < select_ast_list_.size(); i++) {
    ret = select_ast_list_[i]->GetLogicalPlan(llogic_plan);
    children.push_back(llogic_plan);
  }

  logic_plan = new LogicalUnion(children);

  AstSelectList* select_list =
      reinterpret_cast<AstSelectList*>(select_ast_list_[0]->select_list_);
  vector<ExprNode*> distinct_attrs;
  // aggregation_attrs do not have anything
  vector<ExprUnary*> aggregation_attrs;
  distinct_attrs.clear();
  while (NULL != select_list) {
    if (select_list->is_all_) {  // select * from tb;
      // put every column in tables
      AstFromList* from_list =
          reinterpret_cast<AstFromList*>(select_ast_list_[0]->from_list_);
      while (NULL != from_list) {
        AstTable* table = reinterpret_cast<AstTable*>(from_list->args_);
        vector<Attribute> attrs = Environment::getInstance()
                                      ->getCatalog()
                                      ->getTable(table->table_name_)
                                      ->getAttributes();

        for (auto it = attrs.begin(); it != attrs.end(); it++) {
          if (it->attrName.substr(it->attrName.find('.') + 1) != "row_id") {
            auto column = new AstColumn(
                AST_COLUMN, table->table_name_,
                it->attrName.substr(it->attrName.find('.') + 1), it->attrName);
            ExprNode* column_expr = NULL;
            column->GetLogicalPlan(column_expr, logic_plan, NULL);
            distinct_attrs.push_back(column_expr);
          }
        }
        if (NULL != from_list->next_) {
          from_list = reinterpret_cast<AstFromList*>(from_list->next_);
        } else {
          from_list = NULL;
        }
      }
    }
    // select A.* from tb;
    AstSelectExpr* select_expr =
        reinterpret_cast<AstSelectExpr*>(select_list->args_);
    if (select_expr->expr_->ast_node_type() == AST_COLUMN_ALL) {
      AstColumn* column = reinterpret_cast<AstColumn*>(select_expr->expr_);
      vector<Attribute> attrs = Environment::getInstance()
                                    ->getCatalog()
                                    ->getTable(column->relation_name_)
                                    ->getAttributes();
      auto relation_name = column->relation_name_;
      for (auto it = attrs.begin(); it != attrs.end(); ++it) {
        if (it->attrName.substr(it->attrName.find('.') + 1) != "row_id") {
          auto column = new AstColumn(
              AST_COLUMN, relation_name,
              it->attrName.substr(it->attrName.find('.') + 1), it->attrName);
          ExprNode* column_expr = NULL;
          column->GetLogicalPlan(column_expr, logic_plan, NULL);
          distinct_attrs.push_back(column_expr);
        }
      }
    } else if (select_expr->expr_->ast_node_type() == AST_COLUMN) {
      ExprNode* column_expr = NULL;
      select_expr->expr_->GetLogicalPlan(column_expr, logic_plan, NULL);
      distinct_attrs.push_back(column_expr);
      // distinct a, b from tb;
    } else if (select_expr->expr_->ast_node_type() == AST_EXPR_UNARY) {
      ExprNode* column_expr = NULL;
      reinterpret_cast<AstExprUnary*>(select_expr->expr_)
          ->arg0_->GetLogicalPlan(column_expr, logic_plan, NULL);
      distinct_attrs.push_back(column_expr);
    }
    if (NULL != select_list->next_) {
      select_list = reinterpret_cast<AstSelectList*>(select_list->next_);
    } else {
      select_list = NULL;
    }
  }
  if (groupby_attrs_.size() == 0 && agg_attrs_.size() > 0) {
  } else {
    logic_plan =
        new LogicalAggregation(distinct_attrs, aggregation_attrs, logic_plan);
  }

  logic_plan = new LogicalQueryPlanRoot(0, logic_plan, raw_sql_,
                                        LogicalQueryPlanRoot::kResultCollector);

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
    // the difference from the execution of normal segment due to getting
    // result
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

  return ret;
}

RetCode UnionExec::Checkcolumn() {
#ifdef PRINTCONTEXT
  setop_ast_->Print();
  cout << "--------------begin semantic analysis---------------" << endl;
#endif

  SemanticContext sem_cnxt;
  RetCode ret = rSuccess;
  //  ret = setop_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    stmt_exec_status_->set_exec_info("semantic analysis error \n" +
                                     sem_cnxt.error_msg_);
    stmt_exec_status_->set_exec_status(StmtExecStatus::ExecStatus::kError);
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    return ret;
  }
  //  int n = select_ast_list_.size();
  // vector<column_type> column_type_list_;
  // TableDescriptor* tbl;
  // tbl =
  // Environment::getInstance()->getCatalog()->getTable(raw_sql_list_[0]);
  AstSelectStmt* select_ast_;  // = select_ast_list_[0];
  // AstSelectList* ast_select_list_;
  for (int i = 0; i < select_ast_list_.size(); i++) {
    //	  AstSelectStmt* selectstmt = select_ast_list_[i];
    //	  selectstmt->select_list_;
    // ast_select_list_ = select_ast_->select_list_;
    select_ast_ = select_ast_list_[i];
    agg_attrs_ = select_ast_->agg_attrs_;

    AstSelectList* select_list =
        reinterpret_cast<AstSelectList*>(select_ast_list_[i]->select_list_);
    if (i == 0) {
      column_type_list_.clear();
      while (NULL != select_list) {
        if (select_list->is_all_) {
          //遍历from_list,获取全部table将所有table的column放入结构体or对比结构体。
          AstFromList* ast_from_list_ = select_ast_->from_list_;
          pushcolumn(ast_from_list_);
          select_list = NULL;
          break;
        }

        AstSelectExpr* select_expr =
            reinterpret_cast<AstSelectExpr*>(select_list->args_);

        for (auto i : agg_attrs_) {
          string expr_type = i->expr_str_.substr(0, i->expr_str_.find('('));
          cout << "^^^^^^^" << expr_type << endl;
          //          cout << "rrr"
          //               <<
          //               reinterpret_cast<AstExprUnary*>(select_expr->expr_)
          //                      ->arg0_->expr_str_ << endl;

          if (expr_type == "AVG") {
            cout << "jj" << expr_type << endl;
            //  break;

            column_type_list_.push_back(t_double);
          } else if (expr_type == "SUM") {
            cout << "jj" << expr_type << endl;
            column_type_list_.push_back(t_double);

            //    break;
          } else if (expr_type == "MAX") {
            cout << "jj" << expr_type << endl;
            column_type_list_.push_back(t_double);

            //   break;

          } else if (expr_type == "MIN") {
            cout << "jj" << expr_type << endl;
            column_type_list_.push_back(t_double);

            //  break;

          } else if (expr_type == "TO_CHAR") {
            cout << "jj" << expr_type << endl;
            column_type_list_.push_back(t_string);

            //  break;

          } else if (expr_type == "COUNT") {
            cout << "jj" << expr_type << endl;
            column_type_list_.push_back(t_double);

            // break;
          }
          //          switch (expr_type) {
          //            case "AVG":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //            case "COUNT":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //            case "SUM":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //            case "MAX":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //            case "MIN":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //            case "TO_CHAR":
          //              cout << "jj" << expr_type << endl;
          //              break;
          //          }
        }
        if (agg_attrs_.size() > 0) break;

        switch (select_expr->expr_->ast_node_type()) {
          case AST_COLUMN_ALL_ALL: {
            //*
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            pushcolumn(ast_from_list_);

          } break;
          case AST_COLUMN_ALL: {
            // tb.*
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            // select_expr->expr_str_;
            ret = pushcolumn_all(ast_from_list_, select_expr);
            if (rSuccess != ret) {
              LOG(ERROR) << "pushcloumn_all error result= : " << ret;
              return ret;
            }
          } break;

          default: {
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            AstColumn* column_ =
                reinterpret_cast<AstColumn*>(select_expr->expr_);

            AstTable* tbl;
            while (true) {
              tbl = ast_from_list_->args_;
              if (((tbl->table_alias_.compare("NULL") != 0) &&
                   (tbl->table_alias_ == column_->relation_name_)) ||
                  ((tbl->table_alias_.compare("NULL") == 0) &&
                   (tbl->table_name_ == column_->relation_name_))) {
                break;
              } else if (ast_from_list_->next_ != NULL) {
                ast_from_list_ = ast_from_list_->next_;
              } else {
                return rUnionnomatch;
              }
            }
            Attribute attr = Environment::getInstance()
                                 ->getCatalog()
                                 ->getTable(tbl->table_name_)
                                 ->getAttribute(string(column_->column_name_));

            switch (attr.attrType->type) {
              case t_smallInt:
              case t_int:
              case t_u_long:
              case t_float:
              case t_double:
              case t_decimal:
                column_type_list_.push_back(t_double);
                break;
              default:
                column_type_list_.emplace_back(attr.attrType->type);
            }
          }
        }
        if (NULL != select_list->next_) {
          select_list = reinterpret_cast<AstSelectList*>(select_list->next_);
        } else {
          select_list = NULL;
        }
      }
    } else {
      cout << "i>0" << endl;
      vector<data_type>::iterator pos = column_type_list_.begin();
      int column_num = 1;
      while (NULL != select_list) {
        column_num++;
        if (select_list->is_all_) {
          //遍历from_list,获取全部table将所有table的column放入结构体or对比结构体。

          AstFromList* ast_from_list_ = select_ast_->from_list_;
          ret = checkcolumn(ast_from_list_, pos);
          if (ret != rSuccess) {
            LOG(ERROR) << "checkcolumn error result= : " << ret;
            return ret;
          }
          select_list = NULL;

          break;
        }

        for (auto i : agg_attrs_) {
          if (agg_attrs_.size() != column_type_list_.size())
            return rUnionnomatch;
          string expr_type = i->expr_str_.substr(0, i->expr_str_.find('('));
          cout << "^^^^^^^" << expr_type << endl;
          //          cout << "rrr"
          //               <<
          //               reinterpret_cast<AstExprUnary*>(select_expr->expr_)
          //                      ->arg0_->expr_str_ << endl;

          if (expr_type == "AVG") {
            cout << "jj" << expr_type << endl;
            //  break;

            // column_type_list_.push_back(t_u_long);
            if (!checktype(t_double, pos)) return rUnionnomatch;
          } else if (expr_type == "SUM") {
            cout << "jj" << expr_type << endl;
            // column_type_list_.push_back(t_double);
            if (!checktype(t_double, pos)) return rUnionnomatch;
            //    break;
          } else if (expr_type == "MAX") {
            cout << "jj" << expr_type << endl;
            // column_type_list_.push_back(t_double);
            if (!checktype(t_double, pos)) return rUnionnomatch;
            //   break;

          } else if (expr_type == "MIN") {
            cout << "jj" << expr_type << endl;
            // column_type_list_.push_back(t_double);
            if (!checktype(t_double, pos)) return rUnionnomatch;
            //  break;

          } else if (expr_type == "TO_CHAR") {
            cout << "jj" << expr_type << endl;
            // column_type_list_.push_back(t_string);
            if (!checktype(t_string, pos)) return rUnionnomatch;
            //  break;

          } else if (expr_type == "COUNT") {
            cout << "jj" << expr_type << endl;
            //   column_type_list_.push_back(t_u_long);
            if (!checktype(t_double, pos)) return rUnionnomatch;
            // break;
          }
        }
        if (agg_attrs_.size() > 0) break;

        AstSelectExpr* select_expr =
            reinterpret_cast<AstSelectExpr*>(select_list->args_);

        switch (select_expr->expr_->ast_node_type()) {
          case AST_COLUMN_ALL_ALL: {
            //*
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            ret = checkcolumn(ast_from_list_, pos);
            if (ret != rSuccess) {
              LOG(ERROR) << "checkcolumn error result= : " << ret;
              return ret;
            }
          } break;
          case AST_COLUMN_ALL: {
            // tb.*
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            // select_expr->expr_str_;
            ret = checkcolumn_all(ast_from_list_, select_expr, pos);
            if (ret != rSuccess) {
              LOG(ERROR) << "checkcolumn_all error result= : " << ret;
              return ret;
            }
          } break;

          default: {
            AstFromList* ast_from_list_ = select_ast_->from_list_;
            AstColumn* column_ =
                reinterpret_cast<AstColumn*>(select_expr->expr_);

            AstTable* tbl;
            while (true) {
              tbl = ast_from_list_->args_;
              if (((tbl->table_alias_.compare("NULL") != 0) &&
                   (tbl->table_alias_ == column_->relation_name_)) ||
                  ((tbl->table_alias_.compare("NULL") == 0) &&
                   (tbl->table_name_ == column_->relation_name_))) {
                break;
              } else if (ast_from_list_->next_ != NULL) {
                ast_from_list_ = ast_from_list_->next_;
              } else {
                return rUnionnomatch;
              }
            }
            Attribute attr = Environment::getInstance()
                                 ->getCatalog()
                                 ->getTable(tbl->table_name_)
                                 ->getAttribute(string(column_->column_name_));

            switch (attr.attrType->type) {
              case t_smallInt:
              case t_int:
              case t_u_long:
              case t_float:
              case t_double:
              case t_decimal:
                if (!checktype(t_double, pos)) return rUnionnomatch;
                break;
              default:
                if (!checktype(attr.attrType->type, pos)) return rUnionnomatch;
            }
          }
        }

        if (NULL != select_list->next_) {
          select_list = reinterpret_cast<AstSelectList*>(select_list->next_);
        } else {
          select_list = NULL;
        }
        //        pos++;
      }
      if (column_num != column_type_list_.size()) return rUnionnomatch;
    }
  }
  column_type_list_.clear();
  return ret;
}

bool UnionExec::checktype(data_type type, vector<data_type>::iterator& pos) {
  if (pos == column_type_list_.end()) return false;
  if (*pos++ == type)
    return true;
  else
    return false;
}

RetCode UnionExec::checkcolumn_all(AstFromList* ast_from_list_,
                                   AstSelectExpr* select_expr,
                                   vector<data_type>::iterator& pos) {
  RetCode ret = rSuccess;
  if (NULL != ast_from_list_->args_) {
    AstTable* tbl = ast_from_list_->args_;  //= ast_from_list_->args_;
    AstColumn* column_ = reinterpret_cast<AstColumn*>(select_expr->expr_);

    if (((tbl->table_alias_.compare("NULL") != 0) &&
         (tbl->table_alias_ == column_->relation_name_)) ||
        ((tbl->table_alias_.compare("NULL") == 0) &&
         (tbl->table_name_ == column_->relation_name_))) {
      vector<Attribute> attrs = Environment::getInstance()
                                    ->getCatalog()
                                    ->getTable(tbl->table_name_)
                                    ->getAttributes();
      for (auto it = attrs.begin(); it != attrs.end(); it++) {
        switch ((*it).attrType->type) {
          case t_smallInt:
          case t_int:
          case t_u_long:
          case t_float:
          case t_double:
          case t_decimal:
            if (!checktype(t_double, pos)) {
              return rUnionnomatch;
            }
            break;
          default:
            if (!checktype((*it).attrType->type, pos)) return rUnionnomatch;
        }
      }
      return ret;
    }
  }
  if (NULL != ast_from_list_->next_) {
    ret = checkcolumn_all(reinterpret_cast<AstFromList*>(ast_from_list_->next_),
                          select_expr, pos);
  } else
    return rUnionnomatch;
}
RetCode UnionExec::pushcolumn_all(AstFromList* ast_from_list_,
                                  AstSelectExpr* select_expr) {
  RetCode ret = rSuccess;
  if (NULL != ast_from_list_->args_) {
    AstTable* tbl = ast_from_list_->args_;
    AstColumn* column_ = reinterpret_cast<AstColumn*>(select_expr->expr_);

    if (((tbl->table_alias_.compare("NULL") != 0) &&
         (tbl->table_alias_ == column_->relation_name_)) ||
        ((tbl->table_alias_.compare("NULL") == 0) &&
         (tbl->table_name_ == column_->relation_name_))) {
      vector<Attribute> attrs = Environment::getInstance()
                                    ->getCatalog()
                                    ->getTable(tbl->table_name_)
                                    ->getAttributes();
      for (auto it = attrs.begin(); it != attrs.end(); it++) {
        switch ((*it).attrType->type) {
          case t_smallInt:
          case t_int:
          case t_u_long:
          case t_float:
          case t_double:
          case t_decimal:
            column_type_list_.push_back(t_double);
            break;
          default:
            column_type_list_.emplace_back((*it).attrType->type);
        }
      }
      return ret;
    }
  }
  if (NULL != ast_from_list_->next_) {
    pushcolumn_all(reinterpret_cast<AstFromList*>(ast_from_list_->next_),
                   select_expr);
  } else
    return rUnionnomatch;
}

RetCode UnionExec::checkcolumn(AstFromList* ast_from_list_,
                               vector<data_type>::iterator& pos) {
  RetCode ret = rSuccess;
  if (NULL != ast_from_list_->args_) {
    AstTable* tbl = ast_from_list_->args_;
    vector<Attribute> attrs = Environment::getInstance()
                                  ->getCatalog()
                                  ->getTable(tbl->table_name_)
                                  ->getAttributes();

    for (auto it = attrs.begin(); it != attrs.end(); it++) {
      switch ((*it).attrType->type) {
        case t_smallInt:
        case t_int:
        case t_u_long:
        case t_float:
        case t_double:
        case t_decimal:
          if (!checktype(t_double, pos)) return rUnionnomatch;
          break;
        default:
          if (!checktype((*it).attrType->type, pos)) return rUnionnomatch;
      }
    }
  }
  if (NULL != ast_from_list_->next_) {
    ret =
        checkcolumn(reinterpret_cast<AstFromList*>(ast_from_list_->next_), pos);
  }
  return ret;
}
void UnionExec::pushcolumn(AstFromList* ast_from_list_) {
  if (NULL != ast_from_list_->args_) {
    AstTable* tbl = ast_from_list_->args_;
    vector<Attribute> attrs = Environment::getInstance()
                                  ->getCatalog()
                                  ->getTable(tbl->table_name_)
                                  ->getAttributes();
    for (auto it = attrs.begin(); it != attrs.end(); it++) {
      switch ((*it).attrType->type) {
        case t_smallInt:
        case t_int:
        case t_u_long:
        case t_float:
        case t_double:
        case t_decimal:
          column_type_list_.push_back(t_double);
          break;
        default:
          column_type_list_.emplace_back((*it).attrType->type);
      }
    }
  }
  if (NULL != ast_from_list_->next_) {
    ast_from_list_ = ast_from_list_->next_;
    pushcolumn(ast_from_list_);
  }
}

RetCode UnionExec::GetChildStmt(AstNode* ast_node) {
  int ret = rSuccess;
  if (ast_node->ast_node_type_ == AST_UNION_STMT) {
    AstUnionStmt* ast_setop_stmt_ = reinterpret_cast<AstUnionStmt*>(ast_node);
    ret = GetChildStmt(ast_setop_stmt_->lselect_stmt_);
    if (ret != rSuccess) {
      return ret;
    }
    ret = GetChildStmt(ast_setop_stmt_->rselect_stmt_);
    if (ret != rSuccess) {
      return ret;
    }
  } else if (ast_node->ast_node_type_ == AST_SELECT_STMT) {
    select_ast_list_.push_back(reinterpret_cast<AstSelectStmt*>(ast_node));
  } else {
    ret = rGetUnionChild;
    return ret;
  }

  return ret;
}
RetCode UnionExec::GetWriteAndReadTables(
    ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  SemanticContext sem_cnxt;
  ret = setop_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    result.SetError("Semantic analysis error.\n" + sem_cnxt.error_msg_);
    //    exec_result->error_info_ =
    //        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    //    exec_result->status_ = false;
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  } else {
    ret = UnionExec::GetChildStmt(setop_ast_);
    for (auto i = 0; i < select_ast_list_.size(); i++) {
      AstFromList* from_list =
          reinterpret_cast<AstFromList*>(select_ast_list_[i]->from_list_);
      if (AST_JOIN == from_list->args_->ast_node_type_) {
        AstJoin* ast_join = reinterpret_cast<AstJoin*>(from_list->args_);
        AstTable* table = reinterpret_cast<AstTable*>(ast_join->left_table_);
        table_status.first = 0;
        table_status.second = table->table_name_;
        table_list.push_back(table_status);
        table = reinterpret_cast<AstTable*>(ast_join->right_table_);
        table_status.first = 0;
        table_status.second = table->table_name_;
        table_list.push_back(table_status);
      } else {
        AstTable* table = reinterpret_cast<AstTable*>(from_list->args_);
        table_status.first = 0;
        table_status.second = table->table_name_;
        table_list.push_back(table_status);
        while (from_list->next_ != NULL) {
          from_list = reinterpret_cast<AstFromList*>(from_list->next_);
          AstTable* table = reinterpret_cast<AstTable*>(from_list->args_);
          table_status.first = 0;
          table_status.second = table->table_name_;
          table_list.push_back(table_status);
        }
      }
    }
  }
  stmt_to_table_list.push_back(table_list);
  return ret;
}
void* UnionExec::SendAllSegments(void* arg) {
  RetCode ret = 0;
  UnionExec* select_exec = reinterpret_cast<UnionExec*>(arg);
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

RetCode UnionExec::IsUpperExchangeRegistered(vector<NodeID>& upper_node_id_list,
                                             const u_int64_t exchange_id) {
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
}
}
