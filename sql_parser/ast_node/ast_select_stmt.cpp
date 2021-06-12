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
 * /sql_parser/ast_node/ast_select_stmt.cpp
 *  Created on: May 22, 2015 11:32:03 AM
 *  Modified on: Nov 16, 2015
 *      Author: fzh, tonglanxuan
 *       Email: fzhedu@gmail.com
 */

#include "./ast_select_stmt.h"
#include <glog/logging.h>
#include <algorithm>
#include <bitset>
#include <iostream>  // NOLINT
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include "../../common/expression/expr_node.h"
#include "../../common/expression/expr_column.h"
#include "../../common/expression/expr_unary.h"
#include "../../Environment.h"
#include "../../catalog/attribute.h"
#include "../../catalog/table.h"
#include "../../logical_operator/logical_aggregation.h"
#include "../../logical_operator/logical_equal_join.h"
#include "../../logical_operator/logical_cross_join.h"
#include "../../logical_operator/logical_filter.h"
#include "../../logical_operator/logical_limit.h"
#include "../../logical_operator/logical_project.h"
#include "../../logical_operator/logical_scan.h"
#include "../../logical_operator/logical_sort.h"
#include "../../logical_operator/logical_subquery.h"
#include "../../logical_operator/logical_delete_filter.h"
#include "../../logical_operator/logical_outer_join.h"

#include "../ast_node/ast_expr_node.h"
#include "../ast_node/ast_node.h"
#include "../../common/error_define.h"
using namespace ginkgo::common;
using ginkgo::common::ExprColumn;
using ginkgo::common::ExprNodeType;
using ginkgo::common::ExprUnary;
using ginkgo::logical_operator::LogicalCrossJoin;
using ginkgo::logical_operator::LogicalEqualJoin;
using ginkgo::logical_operator::LogicalFilter;
using ginkgo::logical_operator::LogicalProject;
using ginkgo::logical_operator::LogicalScan;
using ginkgo::logical_operator::LogicalSort;
using ginkgo::logical_operator::LogicalLimit;
using ginkgo::logical_operator::LogicalSubquery;
using ginkgo::logical_operator::LogicalDeleteFilter;
using ginkgo::catalog::Attribute;
using std::bitset;
using std::endl;
using std::cout;
using std::setw;
using std::string;
using std::map;
using std::endl;
using std::multimap;
using std::sort;
using std::vector;
// namespace ginkgo {
// namespace sql_parser {
//#define PRINTCONTEXT
AstSelectList::AstSelectList(AstNodeType ast_node_type, bool is_all,
                             AstNode* args, AstNode* next)
    : AstNode(ast_node_type), is_all_(is_all), args_(args), next_(next) {
  // should add selectexpr->astcolumn()
  if (is_all) {
    args_ = new AstColumn(AST_COLUMN_ALL_ALL, "*", "*", "*.*");
  }
}

AstSelectList::~AstSelectList() {
  delete args_;
  delete next_;
}

void AstSelectList::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|select list|" << endl;
  if (args_ != NULL) {
    args_->Print(level + 1);
  } else {
    cout << setw((level + 1) * TAB_SIZE) << " "
         << "|select expr|" << endl;
    cout << setw((level + 1) * TAB_SIZE) << " "
         << "|column| : *(ALL) " << endl;
  }
  if (next_ != NULL) {
    next_->Print(level);
  }
}

RetCode AstSelectList::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (args_ != NULL) {
    args_->SetScanAttrList(sem_cnxt);
  }
  if (next_ != NULL) {
    next_->SetScanAttrList(sem_cnxt);
    return rSuccess;
  }
}

RetCode AstSelectList::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != args_) {
    sem_cnxt->clause_type_ = SemanticContext::kSelectClause;
    sem_cnxt->select_expr_have_agg = false;
    ret = args_->SemanticAnalisys(sem_cnxt);
    sem_cnxt->select_expr_have_agg = false;
    sem_cnxt->clause_type_ = SemanticContext::kNone;
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (is_all_) {
    ret = sem_cnxt->AddSelectAttrs(args_);  // collect select expr node
    return rSuccess;
  }
  if (NULL != next_) {
    ret = next_->SemanticAnalisys(sem_cnxt);
    return ret;
  }
  return rSuccess;
}
void AstSelectList::RecoverExprName(string& name) {
  if (NULL != args_) {
    args_->RecoverExprName(name);
  }
  if (NULL != next_) {
    next_->RecoverExprName(name);
  }
  return;
}
void AstSelectList::ReplaceAggregation(AstNode*& agg_column,
                                       set<AstNode*>& agg_node,
                                       bool is_select) {
  if (NULL != args_) {
    args_->ReplaceAggregation(agg_column, agg_node, is_select);
  }
  if (NULL != next_) {
    next_->ReplaceAggregation(agg_column, agg_node, is_select);
  }
  return;
}
RetCode AstSelectList::GetLogicalPlan(LogicalOperator*& logic_plan) {
  return rSuccess;
}
AstSelectExpr::AstSelectExpr(AstNodeType ast_node_type, std::string expr_alias,
                             AstNode* expr)
    : AstNode(ast_node_type),
      expr_alias_(expr_alias),
      expr_(expr),
      have_agg_func_(false),
      have_alias_(expr_alias != "NULL") {}

AstSelectExpr::~AstSelectExpr() { delete expr_; }




void AstSelectExpr::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|select expr|" << endl;
  if (expr_ != NULL) {
    expr_->Print(level);
  }
  cout << setw(level * TAB_SIZE) << " "
       << "expr alias: " << expr_alias_ << endl;
}

RetCode AstSelectExpr::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (expr_ != NULL) {
     expr_->SetScanAttrList(sem_cnxt);
  }
  return rSuccess;
}

// there is no need to eliminate alias conflict in top select, but in sub query,
// the alias conflict will be checked by Ast.
RetCode AstSelectExpr::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != expr_) {
    ret = expr_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    // transfer the alias to expr, but if this expr has aggregation, it mustn't
    // give the expr_alias_ go expr_str_, because aggregation shouldn't be
    // aliased at this time, but to be aliased after ReplaceAggregation(), at
    // that time, the aggregation has changed to be one column, the
    // select_expr_have_agg = false.
    if (!sem_cnxt->select_expr_have_agg) {
      expr_->expr_str_ = expr_alias_;
    }
    ret = sem_cnxt->AddSelectAttrs(expr_);   // collect select expr attr
    sem_cnxt->select_expr_.push_back(this);  // collect select expr node
    if (rSuccess != ret) {
      return ret;
    }
  }
  return rSuccess;
}
void AstSelectExpr::RecoverExprName(string& name) {
  string expr_name = "";
  if (NULL != expr_) {
    expr_->RecoverExprName(expr_name);
  }
  if (expr_alias_ == "NULL") {
    expr_alias_ = expr_name;
  }
  return;
}
void AstSelectExpr::ReplaceAggregation(AstNode*& agg_column,
                                       set<AstNode*>& agg_node,
                                       bool is_select) {
  if (NULL != expr_) {
    agg_column = NULL;
    int agg_node_num = agg_node.size();
    expr_->ReplaceAggregation(agg_column, agg_node, is_select);
    have_agg_func_ = (agg_node.size() > agg_node_num);
    if (NULL != agg_column) {
      expr_ = agg_column;
    }
    agg_column = NULL;
  }
}

AstFromList::AstFromList(AstNodeType ast_node_type, AstNode* args,
                         AstNode* next)
    : AstNode(ast_node_type), args_(args), next_(next), condition_(NULL) {}

AstFromList::~AstFromList() {
  delete args_;
  delete next_;
}

void AstFromList::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|from list|" << endl;
  ++level;
  cout << setw(level * TAB_SIZE) << " "
       << "|equal join condition: |" << endl;
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->Print(level + 1);
    cout << endl;
  }
  cout << setw(level * TAB_SIZE) << " "
       << "|normal condition: |" << endl;
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->Print(level + 1);
  }
  cout << endl;

  if (args_ != NULL) {
    args_->Print(level + 1);
  }
  if (next_ != NULL) {
    --level;
    next_->Print(level);
  }
}

RetCode AstFromList::SetScanAttrList(SemanticContext* sem_cnxt) {
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  if (args_ != NULL) {
    args_->SetScanAttrList(sem_cnxt);
  }
  if (next_ != NULL) {
    next_->SetScanAttrList(sem_cnxt);
  }
  return rSuccess;
}
RetCode AstFromList::SemanticAnalisys(SemanticContext* sem_cnxt) {
  sem_cnxt->clause_type_ = SemanticContext::kFromClause;
  RetCode ret = rSuccess;
  if (NULL != args_) {
    ret = args_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != next_) {
    ret = next_->SemanticAnalisys(sem_cnxt);
    return ret;
  }
  sem_cnxt->clause_type_ = SemanticContext::kNone;
  return rSuccess;
}

RetCode AstFromList::PushDownCondition(PushDownConditionContext& pdccnxt) {
  PushDownConditionContext cur_pdccnxt;
  cur_pdccnxt.sub_expr_info_ = pdccnxt.sub_expr_info_;

  if (NULL != args_) {
    cur_pdccnxt.from_tables_.clear();
    args_->PushDownCondition(cur_pdccnxt);
    pdccnxt.from_tables_.insert(cur_pdccnxt.from_tables_.begin(),
                                cur_pdccnxt.from_tables_.end());
  }
  if (NULL != next_) {
    cur_pdccnxt.from_tables_.clear();
    next_->PushDownCondition(cur_pdccnxt);
    pdccnxt.from_tables_.insert(cur_pdccnxt.from_tables_.begin(),
                                cur_pdccnxt.from_tables_.end());
  }
  pdccnxt.SetCondition(equal_join_condition_, normal_condition_);
  return rSuccess;
}
RetCode AstFromList::GetLogicalPlan(LogicalOperator*& logic_plan) {
  LogicalOperator* args_lplan = NULL;
  LogicalOperator* next_lplan = NULL;
  RetCode ret = rSuccess;
  if (NULL != args_) {
    args_->GetLogicalPlan(args_lplan);
  }
  if (NULL != next_) {
    next_->GetLogicalPlan(next_lplan);
  }
  if (NULL != next_lplan) {
    if (!equal_join_condition_.empty()) {
      vector<LogicalEqualJoin::JoinPair> join_pair;
      join_pair.clear();
      // "args_lplan" and "next_lplan" order in GetEqualJoinPair' should be
      // same as "arg_lplan" and "next_lplan" in "new LogicalJoin"
      ret = GetEqualJoinPair(join_pair, args_lplan, next_lplan,
                             equal_join_condition_);
      if (rSuccess != ret) {
        return ret;
      }
      vector<ExprNode*> condition;
      condition.clear();
      ret = GetJoinCondition(condition, equal_join_condition_, next_lplan,
                             args_lplan);
      if (rSuccess != ret) {
        return ret;
      }
      ret = GetJoinCondition(condition, normal_condition_, next_lplan,
                             args_lplan);
      if (rSuccess != ret) {
        return ret;
      }
      // judge from join_type "left" "right"
      string join_type = "";
      // this->args_ can be AST_TABLE, but treat as join.
      if (AST_JOIN == (static_cast<AstJoin*>(this->args_))->ast_node_type_) {
        join_type = (static_cast<AstJoin*>(this->args_))->join_type_;
      }
      if (-1 != join_type.find("left")) {
        int join = 0;
        logic_plan = new LogicalOuterJoin(join_pair, args_lplan, next_lplan, 0,
                                          condition);
      } else if (-1 != join_type.find("right")) {
        logic_plan = new LogicalOuterJoin(join_pair, args_lplan, next_lplan, 1,
                                          condition);
      } else if (-1 != join_type.find("full")) {
        logic_plan = new LogicalOuterJoin(join_pair, args_lplan, next_lplan, 2,
                                          condition);
      } else {
        logic_plan =
            new LogicalEqualJoin(join_pair, args_lplan, next_lplan, condition);
      }
    } else {
      vector<ExprNode*> condition;
      condition.clear();
      ret = GetJoinCondition(condition, normal_condition_, next_lplan,
                             args_lplan);
      if (rSuccess != ret) {
        return ret;
      }
      logic_plan = new LogicalCrossJoin(next_lplan, args_lplan, condition);
    }
  } else {
    logic_plan = args_lplan;
  }
  return rSuccess;
}

AstTable::AstTable(AstNodeType ast_node_type, string db_name, string table_name,
                   string table_alias)
    : AstNode(ast_node_type),
      db_name_(db_name),
      table_name_(table_name),
      table_alias_(table_alias),
      table_id_(0) {}

AstTable::~AstTable() {}

void AstTable::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|table| " << endl;
  ++level;
  cout << setw(level * TAB_SIZE) << " "
       << "|equal join condition: |" << endl;
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->Print(level + 1);
    cout << endl;
  }
  cout << setw(level * TAB_SIZE) << " "
       << "|normal condition: |" << endl;
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->Print(level + 1);
  }
  cout << endl;
  level++;
  cout << setw(level * TAB_SIZE) << " "
       << "db_name: " << db_name_ << endl;
  cout << setw(level * TAB_SIZE) << " "
       << "table_name: " << table_name_ << endl;
  cout << setw(level * TAB_SIZE) << " "
       << "table_alias: " << table_alias_ << endl;
}

RetCode AstTable::SetScanAttrList(SemanticContext* sem_cnxt) {
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  // if sql is not  select *
  if (sem_cnxt->is_all != true) {
    is_all_ = false;
    if (sem_cnxt->table_to_column.find(table_name_) !=
        sem_cnxt->table_to_column.end()) {
        columns_ = sem_cnxt->table_to_column[table_name_];
        return rSuccess;
    } else {
      return rTableNotExisted;
    }
  } else {
    is_all_ = true;
  }
}
RetCode AstTable::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  TableDescriptor* tbl =
      Environment::getInstance()->getCatalog()->getTable(table_name_);
  if (NULL == tbl) {
    LOG(ERROR) << "table: " << table_name_ << " dosen't exist!" << endl;
    sem_cnxt->error_msg_ =
        "table: '\e[1m" + table_name_ + "\e[0m' dosen't exist ";
    return rTableNotExisted;
  }
  if (table_alias_ == "NULL") {
    table_alias_ = table_name_;
  }
  sem_cnxt->AddTable(table_alias_);

  std::vector<Attribute> attrs = tbl->getAttributes();
  // NOTE: PART.row_id should row_id
  for (auto it = attrs.begin(); it != attrs.end(); ++it) {
    sem_cnxt->AddTableColumn(table_alias_,
                             it->attrName.substr((it->attrName).find('.') + 1));
  }
  LOG(INFO) << table_name_ << " , " << table_alias_ << " semantic successfully"
            << endl;
  return rSuccess;
}
RetCode AstTable::PushDownCondition(PushDownConditionContext& pdccnxt) {
  pdccnxt.from_tables_.insert(table_alias_);
  pdccnxt.SetCondition(equal_join_condition_, normal_condition_);
  return rSuccess;
}
// TODO(FZH) diver table_name_ to LogicalScan
RetCode AstTable::GetLogicalPlan(LogicalOperator*& logic_plan) {
  RetCode ret = rSuccess;

  //
  // TODO(xiaozhou): judge del is null or not
  if (Environment::getInstance()
          ->getCatalog()
          ->getTable(table_name_)
          ->HasDeletedTuples()) {
    LogicalOperator* base_table = new LogicalScan(table_alias_, columns_, table_name_, is_all_);

    Attribute filter_base =
        base_table->GetPlanContext().plan_partitioner_.get_partition_key();
    LogicalOperator* del_table =
        new LogicalScan(table_alias_ + "_DEL", columns_, table_name_ , is_all_);
    Attribute filter_del =
        del_table->GetPlanContext().plan_partitioner_.get_partition_key();

    assert(filter_base.attrName != "NULL");
    assert(filter_del.attrName != "NULL");
    vector<LogicalDeleteFilter::FilterPair> filter_pair;
    filter_pair.push_back(
        LogicalDeleteFilter::FilterPair(filter_del, filter_base));
    logic_plan = new LogicalDeleteFilter(filter_pair, del_table, base_table);

  } else {
    logic_plan = new LogicalScan(table_alias_, columns_, table_name_, is_all_);
  }
  if (equal_join_condition_.size() > 0) {
    LOG(ERROR) << "equal join condition shouldn't occur in a single table!"
               << endl;
    assert(false);
    return rEqualJoinCondiInATable;
  }
  if (normal_condition_.size() > 0) {
    vector<ExprNode*> condition;
    ExprNode* qnode = NULL;
    for (auto it = normal_condition_.begin(); it != normal_condition_.end();
         ++it) {
      ret = (*it)->GetLogicalPlan(qnode, logic_plan, NULL);
      if (rSuccess != ret) {
        LOG(ERROR) << "get normal condition upon a table, due to [err: " << ret
                   << " ] !" << endl;
        return ret;
      }
      assert(NULL != qnode);
      condition.push_back(qnode);
    }

    logic_plan = new LogicalFilter(logic_plan, condition);
  }
  return rSuccess;
}
AstSubquery::AstSubquery(AstNodeType ast_node_type, std::string subquery_alias,
                         AstNode* subquery)
    : AstNode(ast_node_type),
      subquery_alias_(subquery_alias),
      subquery_(subquery) {}

AstSubquery::~AstSubquery() { delete subquery_; }

void AstSubquery::Print(int level) const {
  cout << setw(level++ * TAB_SIZE) << " "
       << "|subquery| "
       << " subquery_alias: " << subquery_alias_ << endl;
  ++level;
  cout << setw(level * TAB_SIZE) << " "
       << "|equal join condition: |" << endl;
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->Print(level + 1);
    cout << endl;
  }
  cout << setw(level * TAB_SIZE) << " "
       << "|normal condition: |" << endl;
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->Print(level + 1);
  }
  cout << endl;
  if (subquery_ != NULL) {
    subquery_->Print(level);
  }
}

RetCode AstSubquery::SetScanAttrList(SemanticContext* sem_cnxt) {
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
      ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  if (subquery_ != NULL) {
    subquery_->SetScanAttrList(sem_cnxt);
  }
  return rSuccess;
}

RetCode AstSubquery::SemanticAnalisys(SemanticContext* sem_cnxt) {
  SemanticContext sub_sem_cnxt;
  //  // subquery_alias_ == existed_table?
  //  if (NULL !=
  //      Environment::getInstance()->getCatalog()->getTable(subquery_alias_))
  //      {
  //    LOG(ERROR) << "subquery's alias couldn't equal to table that's exist
  //    in
  //    DB"
  //               << endl;
  //    return eTableAliasEqualExistedTable;
  //  }

  // subquery_ is OK?
  RetCode ret = subquery_->SemanticAnalisys(&sub_sem_cnxt);
  if (rSuccess != ret) {
    return ret;
  }
  //  // subquery_alias in tables that occur in subquery?
  //  ret = sub_sem_cnxt.IsTableExist(subquery_alias_);
  //  if (rSuccess == ret) {
  //    return eTableAliasEqualLowerAlias;
  //  }

  // add this sub query alias into upper query's table list
  ret = sem_cnxt->AddTable(subquery_alias_);
  if (rSuccess != ret) {
    return ret;
  }
  // reconstruct the output attribute in subquery
  multimap<string, string> column_to_table;
  ret = sub_sem_cnxt.GetAliasColumn(subquery_alias_, column_to_table);
  if (rSuccess != ret) {
    return ret;
  }

  return sem_cnxt->AddTableColumn(column_to_table);
}

RetCode AstSubquery::PushDownCondition(PushDownConditionContext& pdccnxt) {
  RetCode ret = rSuccess;
  PushDownConditionContext child_pdccnxt;
  ret = subquery_->PushDownCondition(child_pdccnxt);
  if (rSuccess != ret) {
    return ret;
  }
  pdccnxt.from_tables_.insert(subquery_alias_);
  pdccnxt.SetCondition(equal_join_condition_, normal_condition_);
  return rSuccess;
}
// may be deliver subquery output schema
RetCode AstSubquery::GetLogicalPlan(LogicalOperator*& logic_plan) {
  RetCode ret = rSuccess;
  ret = subquery_->GetLogicalPlan(logic_plan);
  if (rSuccess != ret) {
    return ret;
  }
  logic_plan = new LogicalSubquery(logic_plan, subquery_alias_);

  LOG(WARNING) << "there shouldn't be equal join condition here.";
  assert(equal_join_condition_.size() == 0);

  if (normal_condition_.size() > 0) {
    vector<ExprNode*> condition;
    condition.clear();
    ret = GetFilterCondition(condition, normal_condition_, logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
    logic_plan = new LogicalFilter(logic_plan, condition);
  }
  return rSuccess;
}

AstJoinCondition::AstJoinCondition(AstNodeType ast_node_type,
                                   string join_condition_type,
                                   AstNode* condition)
    : AstNode(ast_node_type),
      join_condition_type_(join_condition_type),
      condition_(condition) {}

AstJoinCondition::~AstJoinCondition() { delete condition_; }

RetCode AstJoinCondition::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (condition_ != NULL) {
     condition_->SetScanAttrList(sem_cnxt);
  }
  return rSuccess;
}

void AstJoinCondition::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|join condition| " << join_condition_type_ << endl;
  if (condition_ != NULL) {
    condition_->Print(level + 1);
  } else {
    cout << setw(level * TAB_SIZE) << " "
         << "null" << endl;
  }
}

RetCode AstJoinCondition::SemanticAnalisys(SemanticContext* sem_cnxt) {
  if (NULL != condition_) {
    return condition_->SemanticAnalisys(sem_cnxt);
  }
  return rSuccess;
}

AstJoin::AstJoin(AstNodeType ast_node_type, int join_type, AstNode* left_table,
                 AstNode* right_table, AstNode* join_condition)
    : AstNode(ast_node_type),
      left_table_(left_table),
      right_table_(right_table),
      join_condition_(reinterpret_cast<AstJoinCondition*>(join_condition)) {
  bitset<10> bit_num;
  bit_num = join_type;
  join_type_ = "";
  if (bit_num[9] == 1) {
    join_type_ = "straight ";
  } else {
    if (bit_num[0] == 1) {
      join_type_ = join_type_ + "inner ";
    }
    if (bit_num[1] == 1) {
      join_type_ = join_type_ + "cross ";
    }
    if (bit_num[2] == 1) {
      join_type_ = join_type_ + "outer ";
    }
    if (bit_num[3] == 1) {
      join_type_ = join_type_ + "left ";
      left_table_ = right_table;
      right_table_ = left_table;
    }
    if (bit_num[4] == 1) {
      join_type_ = join_type_ + "right ";
    }
    if (bit_num[5] == 1) {
      join_type_ = join_type_ + "natural ";
    }
    if (bit_num[6] == 1) {
      join_type_ = join_type_ + "full ";
    }
  }
  join_type_ = join_type_ + "join";
}

AstJoin::~AstJoin() {
  delete left_table_;
  delete right_table_;
  delete join_condition_;
}
RetCode AstJoin::SetScanAttrList(SemanticContext* sem_cnxt) {
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->SetScanAttrList(sem_cnxt);
  }
  if (left_table_ != NULL) left_table_->SetScanAttrList(sem_cnxt);
  if (right_table_ != NULL) right_table_->SetScanAttrList(sem_cnxt);
  if (join_condition_ != NULL) join_condition_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}

void AstJoin::Print(int level) const {
  cout << setw(level++ * TAB_SIZE) << " "
       << "|join|" << endl;
  cout << setw(level * TAB_SIZE) << " "
       << "|equal join condition: |" << endl;
  for (auto it = equal_join_condition_.begin();
       it != equal_join_condition_.end(); ++it) {
    (*it)->Print(level + 1);
    cout << endl;
  }
  cout << setw(level * TAB_SIZE) << " "
       << "|normal condition: |" << endl;
  for (auto it = normal_condition_.begin(); it != normal_condition_.end();
       ++it) {
    (*it)->Print(level + 1);
  }
  cout << endl;

  cout << setw(level * TAB_SIZE) << " "
       << "|join type|: " << join_type_ << endl;
  cout << setw(level * TAB_SIZE) << " "
       << "|join left table| " << endl;
  if (left_table_ != NULL) left_table_->Print(level + 1);
  cout << setw(level * TAB_SIZE) << " "
       << "|join right table| " << endl;
  if (right_table_ != NULL) right_table_->Print(level + 1);
  //    cout << setw(level * TAB_SIZE) << " " << "|join condition| " << endl;
  if (join_condition_ != NULL) join_condition_->Print(level + 1);
}
RetCode AstJoin::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  SemanticContext join_sem_cnxt;
  if (NULL == left_table_) {
    LOG(ERROR) << "left table is null in join!" << endl;
    assert(false);
    return rLeftTableIsNULLInJoin;
  }
  if (NULL == right_table_) {
    LOG(ERROR) << "right table is null in join!" << endl;
    assert(false);
    return rRightTableIsNULLInJoin;
  }
  ret = left_table_->SemanticAnalisys(&join_sem_cnxt);
  if (rSuccess != ret) {
    return ret;
  }

  ret = right_table_->SemanticAnalisys(&join_sem_cnxt);
  if (rSuccess != ret) {
    return ret;
  }

  if (NULL != join_condition_) {
    ret = join_condition_->SemanticAnalisys(&join_sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  ret = sem_cnxt->AddTable(join_sem_cnxt.get_tables());
  ret = sem_cnxt->AddTableColumn(join_sem_cnxt.get_column_to_table());
  //  join_sem_cnxt.~SemanticContext();
  return ret;
}
RetCode AstJoin::PushDownCondition(PushDownConditionContext& pdccnxt) {
  PushDownConditionContext cur_pdccnxt;
  // cout << "join type = " << join_type_ << endl;
  // pdccnxt.sub_expr_info -- conditions from where clause
  if (-1 == join_type_.find("outer")) {
    cur_pdccnxt.sub_expr_info_ = pdccnxt.sub_expr_info_;
  }

  // join_condition_->condition -- conditions from on clause
  if (NULL != join_condition_) {
    cur_pdccnxt.GetSubExprInfo(
        reinterpret_cast<AstJoinCondition*>(join_condition_)->condition_);
  }

  cur_pdccnxt.from_tables_.clear();
  PushDownConditionContext child_pdccnxt;
  child_pdccnxt.sub_expr_info_ = cur_pdccnxt.sub_expr_info_;
  child_pdccnxt.from_tables_.clear();

  left_table_->PushDownCondition(child_pdccnxt);
  cur_pdccnxt.from_tables_.insert(child_pdccnxt.from_tables_.begin(),
                                  child_pdccnxt.from_tables_.end());

  child_pdccnxt.from_tables_.clear();
  if (-1 == join_type_.find("outer")) {
    right_table_->PushDownCondition(child_pdccnxt);
    cur_pdccnxt.from_tables_.insert(child_pdccnxt.from_tables_.begin(),
                                    child_pdccnxt.from_tables_.end());
  } else {
    if (right_table_->ast_node_type_ == AST_TABLE) {
      cur_pdccnxt.from_tables_.insert(
          reinterpret_cast<AstTable*>(right_table_)->table_alias_);
    }
  }

  // cout << "!!!" << cur_pdccnxt.sub_expr_info_.size() << endl;
  cur_pdccnxt.SetCondition(equal_join_condition_, normal_condition_);
  // cout << "equal :" << equal_join_condition_.size() << endl;
  // cout << "normal :" << normal_condition_.size() << endl;

  pdccnxt.from_tables_.insert(cur_pdccnxt.from_tables_.begin(),
                              cur_pdccnxt.from_tables_.end());
  if (-1 != join_type_.find("outer")) {
    //    cout << "When pushdown, normal condi num is: "
    //         << pdccnxt.sub_expr_info_.size() << endl;

    for (int i = 0; i < pdccnxt.sub_expr_info_.size(); i++) {
      normal_condition_.push_back(pdccnxt.sub_expr_info_[i]->sub_expr_);
    }
  }

  return rSuccess;
}
RetCode AstJoin::GetLogicalPlan(LogicalOperator*& logic_plan) {
  LogicalOperator* left_plan = NULL;
  LogicalOperator* right_plan = NULL;
  RetCode ret = rSuccess;
  ret = left_table_->GetLogicalPlan(left_plan);
  if (rSuccess != ret) {
    return ret;
  }
  ret = right_table_->GetLogicalPlan(right_plan);
  if (rSuccess != ret) {
    return ret;
  }

  // cout << "equal join condition num = " << equal_join_condition_.size() <<
  // endl;
  // cout << "normal condition num = " << normal_condition_.size() << endl;
  if (!equal_join_condition_.empty()) {
    vector<ExprNode*> condition;
    condition.clear();
    ret = GetJoinCondition(condition, equal_join_condition_, left_plan,
                           right_plan);
    if (rSuccess != ret) {
      return ret;
    }
    // As for outer join, normal condition can not be processed in hash join
    if (-1 == join_type_.find("outer")) {
      ret =
          GetJoinCondition(condition, normal_condition_, left_plan, right_plan);
      if (rSuccess != ret) {
        return ret;
      }
    }
    vector<LogicalEqualJoin::JoinPair> join_pair;
    join_pair.clear();
    ret = GetEqualJoinPair(join_pair, left_plan, right_plan,
                           equal_join_condition_);
    if (rSuccess != ret) {
      return ret;
    }

    // Outer join should generate a filter to deal with normal conditon.
    if (-1 != join_type_.find("left")) {
      logic_plan =
          new LogicalOuterJoin(join_pair, left_plan, right_plan, 0, condition);
      ret = GetFilterLogicalPlan(logic_plan);
    } else if (-1 != join_type_.find("right")) {
      logic_plan =
          new LogicalOuterJoin(join_pair, left_plan, right_plan, 1, condition);
      ret = GetFilterLogicalPlan(logic_plan);
    } else if (-1 != join_type_.find("full")) {
      logic_plan =
          new LogicalOuterJoin(join_pair, left_plan, right_plan, 2, condition);
      ret = GetFilterLogicalPlan(logic_plan);
    } else {
      logic_plan =
          new LogicalEqualJoin(join_pair, left_plan, right_plan, condition);
    }
  } else {
    if (!normal_condition_.empty()) {
      vector<ExprNode*> condition;
      condition.clear();
      ret =
          GetJoinCondition(condition, normal_condition_, left_plan, right_plan);
      if (rSuccess != ret) {
        return ret;
      }
      logic_plan = new LogicalCrossJoin(left_plan, right_plan, condition);
    } else {
      logic_plan = new LogicalCrossJoin(left_plan, right_plan);
    }
  }

  return rSuccess;
}
RetCode AstJoin::GetFilterLogicalPlan(LogicalOperator*& logic_plan) {
  RetCode ret = rSuccess;
  if (!normal_condition_.empty()) {
    vector<ExprNode*> condition;
    condition.clear();
    ret = GetFilterCondition(condition, normal_condition_, logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
    logic_plan = new LogicalFilter(logic_plan, condition);
  }
  return ret;
}
AstWhereClause::AstWhereClause(AstNodeType ast_node_type, AstNode* expr)
    : AstNode(ast_node_type), expr_(expr) {}

AstWhereClause::~AstWhereClause() { delete expr_; }


RetCode AstWhereClause::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (expr_ != NULL) expr_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}

void AstWhereClause::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|where clause| " << endl;
  if (expr_ != NULL) expr_->Print(level + 1);
}
RetCode AstWhereClause::SemanticAnalisys(SemanticContext* sem_cnxt) {
  if (NULL != expr_) {
    sem_cnxt->clause_type_ = SemanticContext::kWhereClause;
    RetCode ret = rSuccess;
    ret = expr_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) return ret;
    sem_cnxt->clause_type_ = SemanticContext::kNone;
  }
  return rSuccess;
}
void AstWhereClause::RecoverExprName(string& name) {
  if (NULL != expr_) {
    expr_->RecoverExprName(name);
  }
}

AstGroupByList::AstGroupByList(AstNodeType ast_node_type, AstNode* expr,
                               AstNode* next)
    : AstNode(ast_node_type), expr_(expr), next_(next) {}

AstGroupByList::~AstGroupByList() {
  delete expr_;
  delete next_;
}

RetCode AstGroupByList::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (expr_ != NULL) {
    expr_->SetScanAttrList(sem_cnxt);
  }
  if (next_ != NULL) {
    next_->SetScanAttrList(sem_cnxt);
  }
  return rSuccess;
}

void AstGroupByList::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|groupby list| " << expr_str_ << endl;
  if (expr_ != NULL) {
    expr_->Print(level + 1);
  }
  if (next_ != NULL) {
    next_->Print(level);
  }
}
RetCode AstGroupByList::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != expr_) {
    // to limit that don't support expression in group by
    //    // don't support expression in group by list
    //    if (AST_COLUMN != expr_->ast_node_type()) {
    //      LOG(ERROR) << "group by list should be single column!" << endl;
    //      return eGroupByNotSupportColumn;
    //    }
    ret = expr_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    sem_cnxt->AddGroupByAttrs(expr_);  // collect group by expr node
  }
  if (NULL != next_) {
    ret = next_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  return rSuccess;
}
void AstGroupByList::RecoverExprName(string& name) {
  if (NULL != expr_) {
    expr_->RecoverExprName(name);
  }
  if (NULL != next_) {
    next_->RecoverExprName(name);
  }
}
// for select a+b as A, count(*) from TB group by A, should to be "select A,
// count(*) from TB group by a+b as A".
RetCode AstGroupByList::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  RetCode ret = rSuccess;
  if (NULL != expr_) {
    AstSelectExpr* select_expr_i = NULL;
    if (AST_COLUMN == expr_->ast_node_type()) {
      AstColumn* column = reinterpret_cast<AstColumn*>(expr_);
      for (int i = 0; i < select_alias_solver->select_expr_.size(); ++i) {
        select_expr_i = reinterpret_cast<AstSelectExpr*>(
            select_alias_solver->select_expr_[i]);
        if (select_expr_i->have_alias_ && !select_expr_i->have_agg_func_ &&
            select_expr_i->expr_alias_ == column->column_name_) {
          // even through is false, but for avoiding ignore solve it again
          select_expr_i->have_agg_func_ = true;
          // should give alias to expr_str_
          //          select_expr_i->expr_->expr_str_ =
          //          select_expr_i->expr_alias_;
          swap(select_expr_i->expr_, expr_);
          break;
        }
      }
    }
  }
  if (NULL != next_) {
    ret = next_->SolveSelectAlias(select_alias_solver);
  }
  return ret;
}
AstGroupByClause::AstGroupByClause(AstNodeType ast_node_type,
                                   AstNode* groupby_list, bool with_roolup)
    : AstNode(ast_node_type),
      groupby_list_(reinterpret_cast<AstGroupByList*>(groupby_list)),
      with_roolup_(with_roolup) {}

AstGroupByClause::~AstGroupByClause() { delete groupby_list_; }

RetCode AstGroupByClause::SetScanAttrList(SemanticContext* sem_cnxt) {
  groupby_list_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstGroupByClause::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|groupby clause| "
       << "with rool_up: " << with_roolup_ << endl;
  groupby_list_->Print(level + 1);
}
RetCode AstGroupByClause::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != groupby_list_) {
    sem_cnxt->clause_type_ = SemanticContext::kGroupByClause;
    ret = groupby_list_->SemanticAnalisys(sem_cnxt);
    sem_cnxt->clause_type_ = SemanticContext::kNone;
    if (rSuccess != ret) {
      return ret;
    }
    return rSuccess;
  }
  ELOG(rGroupbyListIsNULL, "");
  return rGroupbyListIsNULL;
}
void AstGroupByClause::RecoverExprName(string& name) {
  if (NULL != groupby_list_) {
    groupby_list_->RecoverExprName(name);
  }
}
RetCode AstGroupByClause::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  if (NULL != groupby_list_) {
    RetCode ret = groupby_list_->SolveSelectAlias(select_alias_solver);
    if (rSuccess != ret) {
      return ret;
    }
  }
  return rSuccess;
}

AstOrderByList::AstOrderByList(AstNodeType ast_node_type, AstNode* expr,
                               int orderby_type, AstNode* next)
    : AstNode(ast_node_type),
      expr_(expr),
      orderby_direction_(orderby_type == 0 ? "ASC" : "DESC"),
      next_(next) {}

AstOrderByList::~AstOrderByList() {
  delete expr_;
  delete next_;
}

RetCode AstOrderByList::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (expr_ != NULL) expr_->SetScanAttrList(sem_cnxt);
  if (next_ != NULL) next_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstOrderByList::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|orderby list| " << endl;
  if (expr_ != NULL) expr_->Print(level + 1);
  cout << setw((level + 1) * TAB_SIZE) << " "
       << "orderby direction: " << orderby_direction_ << endl;
  if (next_ != NULL) {
    next_->Print(level);
  }
}
RetCode AstOrderByList::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != expr_) {
    ret = expr_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != next_) {
    ret = next_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  return rSuccess;
}
void AstOrderByList::RecoverExprName(string& name) {
  if (NULL != expr_) {
    expr_->RecoverExprName(name);
  }
  if (NULL != next_) {
    next_->RecoverExprName(name);
  }
}
void AstOrderByList::ReplaceAggregation(AstNode*& agg_column,
                                        set<AstNode*>& agg_node,
                                        bool is_select) {
  if (NULL != expr_) {
    agg_column = NULL;
    expr_->ReplaceAggregation(agg_column, agg_node, is_select);
    if (NULL != agg_column) {
      delete expr_;
      expr_ = agg_column;
    }
    agg_column = NULL;
  }
  if (NULL != next_) {
    next_->ReplaceAggregation(agg_column, agg_node, is_select);
  }
}
RetCode AstOrderByList::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  if (NULL != expr_) {
    expr_->SolveSelectAlias(select_alias_solver);
    select_alias_solver->SetNewNode(expr_);
    select_alias_solver->DeleteOldNode();
  }
  if (NULL != next_) {
    next_->SolveSelectAlias(select_alias_solver);
    select_alias_solver->SetNewNode(next_);
    select_alias_solver->DeleteOldNode();
  }
  return rSuccess;
}
AstOrderByClause::AstOrderByClause(AstNodeType ast_node_type,
                                   AstNode* orderby_list)
    : AstNode(ast_node_type),
      orderby_list_(reinterpret_cast<AstOrderByList*>(orderby_list)) {}

AstOrderByClause::~AstOrderByClause() { delete orderby_list_; }

RetCode AstOrderByClause::SetScanAttrList(SemanticContext *sem_cnxt) {
  if (orderby_list_ != NULL) orderby_list_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}

void AstOrderByClause::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|orderby clause| " << endl;
  if (orderby_list_ != NULL) {
    orderby_list_->Print(level + 1);
  }
}
RetCode AstOrderByClause::SemanticAnalisys(SemanticContext* sem_cnxt) {
  if (NULL != orderby_list_) {
    sem_cnxt->clause_type_ = SemanticContext::kOrderByClause;
    RetCode ret = rSuccess;
    ret = orderby_list_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    sem_cnxt->clause_type_ = SemanticContext::kNone;
    return rSuccess;
  }
  return rSuccess;
}
void AstOrderByClause::RecoverExprName(string& name) {
  if (NULL != orderby_list_) {
    orderby_list_->RecoverExprName(name);
  }
}
void AstOrderByClause::ReplaceAggregation(AstNode*& agg_column,
                                          set<AstNode*>& agg_node,
                                          bool is_select) {
  if (NULL != orderby_list_) {
    orderby_list_->ReplaceAggregation(agg_column, agg_node, is_select);
  }
}
RetCode AstOrderByClause::GetLogicalPlan(LogicalOperator*& logic_plan) {
  vector<pair<ExprNode*, int>> orderby_expr;
  ExprNode* tmp_expr = NULL;
  int direction = 0;
  AstOrderByList* orderby = orderby_list_;
  while (NULL != orderby) {
    orderby->expr_->GetLogicalPlan(tmp_expr, logic_plan, NULL);
    direction = orderby->orderby_direction_ == "ASC" ? 0 : 1;
    orderby_expr.push_back(make_pair(tmp_expr, direction));
    orderby = orderby->next_;
  }
  logic_plan = new LogicalSort(logic_plan, orderby_expr);
  return rSuccess;
}
RetCode AstOrderByClause::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  if (NULL != orderby_list_) {
    orderby_list_->SolveSelectAlias(select_alias_solver);
  }
  return rSuccess;
}
AstHavingClause::AstHavingClause(AstNodeType ast_node_type, AstNode* expr)
    : AstNode(ast_node_type), expr_(expr) {}

AstHavingClause::~AstHavingClause() { delete expr_; }

RetCode AstHavingClause::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (expr_ != NULL) expr_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstHavingClause::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|having clause| " << endl;
  if (expr_ != NULL) expr_->Print(level + 1);
}
RetCode AstHavingClause::SemanticAnalisys(SemanticContext* sem_cnxt) {
  if (NULL != expr_) {
    sem_cnxt->clause_type_ = SemanticContext::kHavingClause;
    RetCode ret = rSuccess;
    ret = expr_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    sem_cnxt->clause_type_ = SemanticContext::kNone;
  }
  return rSuccess;
}
void AstHavingClause::RecoverExprName(string& name) {
  if (NULL != expr_) {
    expr_->RecoverExprName(name);
  }
}
void AstHavingClause::ReplaceAggregation(AstNode*& agg_column,
                                         set<AstNode*>& agg_node,
                                         bool is_select) {
  if (NULL != expr_) {
    expr_->ReplaceAggregation(agg_column, agg_node, is_select);
  }
}
RetCode AstHavingClause::GetLogicalPlan(LogicalOperator*& logic_plan) {
  if (NULL != expr_) {
    vector<ExprNode*> having_expr;
    ExprNode* expr = NULL;
    expr_->GetLogicalPlan(expr, logic_plan, NULL);
    having_expr.push_back(expr);
    logic_plan = new LogicalFilter(logic_plan, having_expr);
  }
  return rSuccess;
}
RetCode AstHavingClause::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  if (NULL != expr_) {
    expr_->SolveSelectAlias(select_alias_solver);
    select_alias_solver->SetNewNode(expr_);
    select_alias_solver->DeleteOldNode();
  }
  return rSuccess;
}
AstLimitClause::AstLimitClause(AstNodeType ast_node_type, AstNode* offset,
                               AstNode* row_count)
    : AstNode(ast_node_type), offset_(offset), row_count_(row_count) {}

AstLimitClause::~AstLimitClause() {
  delete offset_;
  delete row_count_;
}

RetCode AstLimitClause::SetScanAttrList(SemanticContext* sem_cnxt) {
  if (offset_ != NULL) offset_->SetScanAttrList(sem_cnxt);
  if (row_count_ != NULL) row_count_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstLimitClause::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|limit clause| " << endl;
  level++;
  cout << setw(level * TAB_SIZE) << " "
       << " offset: " << endl;
  if (offset_ != NULL) offset_->Print(level + 1);
  cout << setw(level * TAB_SIZE) << " "
       << " row_count " << endl;
  if (row_count_ != NULL) row_count_->Print(level + 1);
}
RetCode AstLimitClause::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != offset_) {
    ret = offset_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != row_count_) {
    return row_count_->SemanticAnalisys(sem_cnxt);
  }
  return rSuccess;
}
RetCode AstLimitClause::GetLogicalPlan(LogicalOperator*& logical_plan) {
  if (NULL == row_count_) {
    if (NULL == offset_) {
      return rSuccess;
    }
    return rLimitNotStandardized;
  }
  if (row_count_->ast_node_type() != AST_EXPR_CONST ||
      (NULL != offset_ && offset_->ast_node_type() != AST_EXPR_CONST)) {
    return rLimitParaShouldNaturalNumber;
  }
  int64_t row_count =
      atol((dynamic_cast<AstExprConst*>(row_count_))->data_.c_str());
  if (0 == row_count) {
    return rLimitZero;
  }
  int64_t offset =
      (NULL != offset_)
          ? atol((dynamic_cast<AstExprConst*>(offset_))->data_.c_str())
          : 0;
  if (row_count < 0 || offset < 0) {
    return rLimitParaCouldnotLessZero;
  }
  logical_plan = new LogicalLimit(logical_plan, row_count, offset);
  return rSuccess;
}
AstColumn::AstColumn(AstNodeType ast_node_type, std::string relation_name,
                     std::string column_name)
    : AstNode(ast_node_type),
      relation_name_(relation_name),
      column_name_(column_name),
      next_(NULL) {}
AstColumn::AstColumn(AstNodeType ast_node_type, std::string relation_name,
                     std::string column_name, string expr_str)
    : AstNode(ast_node_type),
      relation_name_(relation_name),
      column_name_(column_name),
      next_(NULL) {
  expr_str_ = expr_str;
}

AstColumn::AstColumn(AstNodeType ast_node_type, std::string relation_name,
                     std::string column_name, AstNode* next)
    : AstNode(AST_COLUMN),
      relation_name_(relation_name),
      column_name_(column_name) {
  if (NULL != next) {
    next_ = next->AstNodeCopy();
  } else {
    next_ = NULL;
  }
}
AstColumn::AstColumn(AstColumn* node)
    : AstNode(node),
      relation_name_(node->relation_name_),
      column_name_(node->column_name_) {
  if (NULL != node->next_) {
    next_ = node->next_->AstNodeCopy();
  } else {
    next_ = NULL;
  }
}
AstColumn::~AstColumn() { delete next_; }

RetCode AstColumn::SetScanAttrList(SemanticContext* sem_cnxt) {
//  next_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstColumn::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|column| " << expr_str_ << endl;
  cout << setw((level + 1) * TAB_SIZE) << " "
       << "relation name: " << relation_name_ << endl;
  cout << setw((level + 1) * TAB_SIZE) << " "
       << "column name: " << column_name_ << endl;

  if (next_ != NULL) {
    next_->Print(level);
  }
  level++;
}
RetCode AstColumn::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  if (AST_COLUMN_ALL_ALL == ast_node_type_) {
    if (SemanticContext::kSelectClause == sem_cnxt->clause_type_) {
      sem_cnxt->is_all = true;
      return rSuccess;
    } else {
      return rColumnAllShouldNotInOtherClause;
    }
  }
  if (AST_COLUMN_ALL == ast_node_type_) {
    if (SemanticContext::kSelectClause == sem_cnxt->clause_type_) {
      ret = sem_cnxt->IsTableExist(relation_name_);
      if (rSuccess != ret) {
        return rTableNotExistInTableColumnALL;
      }
    } else {
      return rColumnAllShouldNotInOtherClause;
    }
    // insert * means all column in relation
    sem_cnxt->is_all = false;
    sem_cnxt->table_to_column[relation_name_].insert("*");
    return rSuccess;
  }
  ret = sem_cnxt->IsColumnExist(relation_name_, column_name_);
  if (rSuccess != ret) {
    LOG(ERROR) << "There are errors in ( " << relation_name_ << " , "
               << column_name_ << " )" << endl;
    sem_cnxt->error_msg_ =
        "column: '\e[1m" + column_name_ + "\e[0m' is invalid";
    return ret;
  }
  sem_cnxt->is_all = false;
  sem_cnxt->table_to_column[relation_name_].insert(column_name_);
  if (NULL != next_) {
    return next_->SemanticAnalisys(sem_cnxt);
  }
  return rSuccess;
}
void AstColumn::RecoverExprName(string& name) {
  string next_name = "";
  if (NULL != next_) {
    next_->RecoverExprName(next_name);
  }
  if (relation_name_ != "NULL") {
    expr_str_ = relation_name_ + "." + column_name_;
  } else {
    expr_str_ = column_name_;
  }
  if (NULL != next_) {
    name = expr_str_ + " , " + next_name;
  } else {
    name = expr_str_;
  }
  return;
}

/**
 * because GetRefTable from where clause, so there couldn't be AST_COLUMN_ALL
 * or
 * AST_COLUMN_ALL_ALL
 * relation_name_=="NULL" is illegal, but "NULL_MID" means for aggregation, so
 * it's legal
 */
void AstColumn::GetRefTable(set<string>& ref_table) {
  assert(AST_COLUMN_ALL != ast_node_type_ &&
         AST_COLUMN_ALL_ALL != ast_node_type_);
  assert(relation_name_ != "NULL");
  ref_table.insert(relation_name_);
}

RetCode AstColumn::GetLogicalPlan(ExprNode*& logic_expr,
                                  LogicalOperator* const left_lplan,
                                  LogicalOperator* const right_lplan) {
  Attribute ret_lattr = left_lplan->GetPlanContext().GetAttribute(
      string(relation_name_ + "." + column_name_));

  if (NULL != right_lplan) {
    Attribute ret_rattr = right_lplan->GetPlanContext().GetAttribute(
        string(relation_name_ + "." + column_name_));
    if ((ret_lattr.attrName != "NULL") && (ret_rattr.attrName != "NULL")) {
      assert(false);
      return rFailure;
    } else if (ret_lattr.attrName != "NULL") {
      logic_expr =
          new ExprColumn(ExprNodeType::t_qcolcumns, ret_lattr.attrType->type,
                         expr_str_, relation_name_, column_name_);
      return rSuccess;
    } else if (ret_rattr.attrName != "NULL") {
      logic_expr =
          new ExprColumn(ExprNodeType::t_qcolcumns, ret_rattr.attrType->type,
                         expr_str_, relation_name_, column_name_);
      return rSuccess;
    } else {
      assert(false);
      return rFailure;
    }
  } else {
    if (ret_lattr.attrName != "NULL") {
      logic_expr =
          new ExprColumn(ExprNodeType::t_qcolcumns, ret_lattr.attrType->type,
                         expr_str_, relation_name_, column_name_);
      return rSuccess;
    } else {
      logic_expr = NULL;
      assert(false);
      return rFailure;
    }
  }
}
RetCode AstColumn::SolveSelectAlias(
    SelectAliasSolver* const select_alias_solver) {
  RetCode ret = rSuccess;
  AstSelectExpr* select_expr_i = NULL;
  for (int i = 0; i < select_alias_solver->select_expr_.size(); ++i) {
    select_expr_i =
        reinterpret_cast<AstSelectExpr*>(select_alias_solver->select_expr_[i]);
    if (select_expr_i->have_alias_ &&
        select_expr_i->expr_alias_ == column_name_) {
      select_alias_solver->new_node_ = (select_expr_i->expr_)->AstNodeCopy();
      assert(select_alias_solver->new_node_ != NULL);
      select_alias_solver->old_node_ = this;
      break;
    }
  }
  return rSuccess;
}
AstNode* AstColumn::AstNodeCopy() { return new AstColumn(this); }

AstSelectStmt::AstSelectStmt(AstNodeType ast_node_type, int select_opts,
                             AstNode* select_list, AstNode* from_list,
                             AstNode* where_clause, AstNode* groupby_clause,
                             AstNode* having_clause, AstNode* orderby_clause,
                             AstNode* limit_clause, AstNode* select_into_clause)
    : AstNode(ast_node_type),
      select_opts_((SelectOpts)select_opts),
      select_list_(select_list),
      from_list_(from_list),
      where_clause_(where_clause),
      groupby_clause_(groupby_clause),
      having_clause_(having_clause),
      orderby_clause_(orderby_clause),
      limit_clause_(limit_clause),
      select_into_clause_(select_into_clause),
      have_aggeragion_(false) {
  groupby_attrs_.clear();
  agg_attrs_.clear();
}

AstSelectStmt::~AstSelectStmt() {
  delete select_list_;
  delete from_list_;
  delete where_clause_;
  delete groupby_clause_;
  delete having_clause_;
  delete orderby_clause_;
  delete limit_clause_;
  delete select_into_clause_;
}

RetCode AstSelectStmt::SetScanAttrList(SemanticContext* sem_cnxt) {
  select_list_->SetScanAttrList(sem_cnxt);
  if (from_list_ != NULL) from_list_->SetScanAttrList(sem_cnxt);
  if (where_clause_ != NULL) where_clause_->SetScanAttrList(sem_cnxt);
  if (groupby_clause_ != NULL) groupby_clause_->SetScanAttrList(sem_cnxt);
  if (having_clause_ != NULL) having_clause_->SetScanAttrList(sem_cnxt);
  if (orderby_clause_ != NULL) orderby_clause_->SetScanAttrList(sem_cnxt);
  if (limit_clause_ != NULL) limit_clause_->SetScanAttrList(sem_cnxt);
  if (select_into_clause_ != NULL)
    select_into_clause_->SetScanAttrList(sem_cnxt);
  return rSuccess;
}
void AstSelectStmt::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|select statement| " << endl;
  level++;
  select_list_->Print(level);
  if (from_list_ != NULL) from_list_->Print(level);
  if (where_clause_ != NULL) where_clause_->Print(level);
  if (groupby_clause_ != NULL) groupby_clause_->Print(level);
  if (having_clause_ != NULL) having_clause_->Print(level);
  if (orderby_clause_ != NULL) orderby_clause_->Print(level);
  if (limit_clause_ != NULL) limit_clause_->Print(level);
  if (select_into_clause_ != NULL) select_into_clause_->Print(level);
  //  cout << "------------select ast print over!------------------" << endl;
}
/**
 *  NOTE: the physical execution may be divide into 2 step_
 *  from-> where-> groupby-> select_aggregation->select_expression->
 *  having->orderby-> limit
 */

RetCode AstSelectStmt::SemanticAnalisys(SemanticContext* sem_cnxt) {
  if (NULL == sem_cnxt) {
    SemanticContext sem;
    sem_cnxt = &sem;
  }
  RetCode ret = rSuccess;
  // check whether table exist or table alias conflict
  if (NULL != from_list_) {
    ret = from_list_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "from clause has error" << endl;
      return ret;
    }
  } else {
    LOG(WARNING) << "from clause is NULL" << endl;
  }
  // check whether column exist
  // TODO(FZH) check every functions
  if (NULL != where_clause_) {
    string name = "";
    where_clause_->RecoverExprName(name);
    ret = where_clause_->SemanticAnalisys(sem_cnxt);

    if (rSuccess != ret) {
      LOG(ERROR) << "where clause has error" << endl;
      return ret;
    }
  }
#ifdef PRINTCONTEXT
  sem_cnxt->PrintContext("after scan");
#endif
  // first recover select attr name
  // collect all aggregation functions
  agg_attrs_.clear();
  if (NULL != select_list_) {
    string name = "";
    select_list_->RecoverExprName(name);

    ret = select_list_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "select list has error" << endl;
      return ret;
    }
    // collecting aggregation and replace a aggregation expression to one
    // column
    AstNode* agg_column = NULL;
    select_list_->ReplaceAggregation(agg_column, agg_attrs_, true);

    if (agg_attrs_.size() > 0) {
      sem_cnxt->GetUniqueAggAttr(agg_attrs_);
    }

  } else {
    ELOG(rSelectClauseIsNULL, "");
    return rSelectClauseIsNULL;
  }
  // aggregation couldn't in group by clause
  // collect all group by attributes to rebuild schema
  if (NULL != groupby_clause_) {
    string name = "";
    groupby_clause_->RecoverExprName(name);
    // mustn't change the order of upper clause and below
    SelectAliasSolver* select_alias_solver =
        new SelectAliasSolver(sem_cnxt->select_expr_);
    groupby_clause_->SolveSelectAlias(select_alias_solver);
    ret = groupby_clause_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "groupby clause has error" << endl;
      return ret;
    }
    groupby_attrs_ = sem_cnxt->get_groupby_attrs();
  }

  have_aggeragion_ = (NULL != groupby_clause_ || agg_attrs_.size() > 0);

  if (have_aggeragion_) {
    // rebuild schema result from aggregation
    RetCode ret = sem_cnxt->RebuildTableColumn(agg_attrs_);
    if (rSuccess != ret) {
      LOG(ERROR) << "there are confiction in new schema after agg!" << endl;
      return ret;
    }
#ifdef PRINTCONTEXT
    sem_cnxt->PrintContext("after aggregation");
#endif
  }
  // first replace alias to original expression
  // having clause exist only if have aggregation
  if (NULL != having_clause_) {
    if (!have_aggeragion_) {
      return rHavingNotAgg;
    }
    SelectAliasSolver* select_alias_solver =
        new SelectAliasSolver(sem_cnxt->select_expr_);
    having_clause_->SolveSelectAlias(select_alias_solver);

    string name = "";
    having_clause_->RecoverExprName(name);

    AstNode* agg_column = NULL;
    set<AstNode*> agg_node_having;
    having_clause_->ReplaceAggregation(agg_column, agg_node_having, false);

    ret = having_clause_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "having clause has error" << endl;
      return ret;
    }
  }
  if (NULL != orderby_clause_) {
    RetCode ret = rSuccess;
    SelectAliasSolver* select_alias_solver =
        new SelectAliasSolver(sem_cnxt->select_expr_);
    orderby_clause_->SolveSelectAlias(select_alias_solver);

    string name = "";
    orderby_clause_->RecoverExprName(name);

    AstNode* agg_column = NULL;
    set<AstNode*> agg_node_orderby;
    orderby_clause_->ReplaceAggregation(agg_column, agg_node_orderby, false);

    ret = orderby_clause_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "orderby clause has error" << endl;
      return ret;
    }
  }
  if (NULL != limit_clause_) {
    ret = limit_clause_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      LOG(ERROR) << "limit clause has error" << endl;
      return ret;
    }
  }
  if (have_aggeragion_) {
    AstNode* agg_column = NULL;
    select_list_->ReplaceAggregation(agg_column, agg_attrs_, false);
    // check whether other column except from aggregation funcs and groupby
    // expressions in select expressions
    sem_cnxt->ClearSelectAttrs();
    ret = select_list_->SemanticAnalisys(sem_cnxt);
    if (rSuccess != ret) {
      ELOG(rAggSelectExprHaveOtherColumn, "");
      return rAggSelectExprHaveOtherColumn;
    }
  }
  // for select clause rebuild table column
  sem_cnxt->RebuildTableColumn();
#ifdef PRINTCONTEXT
  sem_cnxt->PrintContext("after select");
#endif

  return ret;
}

RetCode AstSelectStmt::PushDownCondition(PushDownConditionContext& pdccnxt) {
  if (NULL != where_clause_) {
    AstWhereClause* where_clause =
        reinterpret_cast<AstWhereClause*>(where_clause_);
    pdccnxt.GetSubExprInfo(where_clause->expr_);
  }
  from_list_->PushDownCondition(pdccnxt);

  //  from_list_->Print();
  return rSuccess;
}
// should support expression in aggregation
RetCode AstSelectStmt::GetLogicalPlanOfAggeration(
    LogicalOperator*& logic_plan) {
  vector<ExprNode*> group_by_attrs;
  vector<ExprUnary*> aggregation_attrs;
  ExprNode* tmp_expr = NULL;
  RetCode ret = rSuccess;
  for (auto it = groupby_attrs_.begin(); it != groupby_attrs_.end(); ++it) {
    ret = (*it)->GetLogicalPlan(tmp_expr, logic_plan, NULL);
    if (rSuccess != ret) {
      return ret;
    }
    group_by_attrs.push_back(tmp_expr);
  }
  for (auto it = agg_attrs_.begin(); it != agg_attrs_.end(); ++it) {
    ret = (*it)->GetLogicalPlan(tmp_expr, logic_plan, NULL);
    if (rSuccess != ret) {
      return ret;
    }
    aggregation_attrs.push_back(reinterpret_cast<ExprUnary*>(tmp_expr));
  }
  logic_plan =
      new LogicalAggregation(group_by_attrs, aggregation_attrs, logic_plan);
  return rSuccess;
}

RetCode AstSelectStmt::GetLogicalPlanOfProject(LogicalOperator*& logic_plan) {
  AstSelectList* select_list = reinterpret_cast<AstSelectList*>(select_list_);
  vector<ExprNode*> expr_list;
  vector<AstNode*> ast_expr;
  ExprNode* tmp_expr = NULL;
  RetCode ret = rSuccess;
  ast_expr.clear();
  expr_list.clear();
  while (NULL != select_list) {
    if (select_list->is_all_) {  // select * from tb;
      return rSuccess;
    }
    AstSelectExpr* select_expr =
        reinterpret_cast<AstSelectExpr*>(select_list->args_);
    switch (select_expr->expr_->ast_node_type()) {
      case AST_COLUMN_ALL_ALL: {
        return rSuccess;
      } break;
      case AST_COLUMN_ALL: {
        AstColumn* column = reinterpret_cast<AstColumn*>(select_expr->expr_);
        vector<Attribute> attrs = Environment::getInstance()
                                      ->getCatalog()
                                      ->getTable(column->relation_name_)
                                      ->getAttributes();
        for (auto it = attrs.begin(); it != attrs.end(); ++it) {
          ast_expr.push_back(new AstColumn(
              AST_COLUMN, column->relation_name_,
              it->attrName.substr(it->attrName.find('.') + 1), it->attrName));
        }
      } break;
      default: { ast_expr.push_back(select_expr->expr_); }
    }

    if (NULL != select_list->next_) {
      select_list = reinterpret_cast<AstSelectList*>(select_list->next_);
    } else {
      select_list = NULL;
    }
  }
  for (int i = 0; i < ast_expr.size(); ++i) {
    ret = ast_expr[i]->GetLogicalPlan(tmp_expr, logic_plan, NULL);
    if (rSuccess != ret) {
      return rSuccess;
    }
    expr_list.push_back(tmp_expr);
  }
  logic_plan = new LogicalProject(logic_plan, expr_list);
  return rSuccess;
}

// #define SUPPORT
RetCode AstSelectStmt::GetLogicalPlan(LogicalOperator*& logic_plan) {
  RetCode ret = rSuccess;
  if (NULL != from_list_) {
    ret = from_list_->GetLogicalPlan(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (have_aggeragion_) {
    ret = GetLogicalPlanOfAggeration(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != having_clause_) {
    ret = having_clause_->GetLogicalPlan(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != orderby_clause_) {
    ret = orderby_clause_->GetLogicalPlan(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  if (NULL != select_list_) {
    ret = GetLogicalPlanOfProject(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  // it's optimal to add limit operator before select operator, but because it's
  // necessary add limit physical operator below LogicalQueryPlanRoot, so
  // underlying limit should at the top of plan
  if (NULL != limit_clause_) {
    ret = limit_clause_->GetLogicalPlan(logic_plan);
    if (rSuccess != ret) {
      return ret;
    }
  }
  return rSuccess;
}

//}  // namespace sql_parser
//}  // namespace ginkgo
