
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
 * ./LogicalPlan/logical_union.cpp
 *
 *  Created on: May 20, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 *
 */
#define GLOG_NO_ABBREVIATED_SEVERITIES  // avoid macro conflict
#include <glog/logging.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "../common/expression/expr_node.h"
#include "../common/expression/expr_column.h"
#include "../common/expression/expr_const.h"
#include "../common/expression/expr_unary.h"
#include "../logical_operator/logical_union.h"
#include "../logical_operator/plan_context.h"
#include "../IDsGenerator.h"
#include "../Config.h"
#include "../catalog/stat/StatManager.h"
#include "../physical_operator/exchange_merger.h"
#include "../physical_operator/expander.h"
#include "../physical_operator/physical_union.h"

using claims::physical_operator::ExchangeMerger;
using claims::physical_operator::Expander;
using std::vector;
using claims::common::ExprNode;
using claims::common::ExprNodeType;
using claims::common::ExprUnary;
using claims::common::OperType;
using claims::common::ExprConst;
using claims::common::ExprColumn;
using claims::common::LogicInitCnxt;

using claims::physical_operator::PhysicalUnion;
namespace claims {
namespace logical_operator {
LogicalUnion::LogicalUnion(vector<LogicalOperator*> children)
    : LogicalOperator(kLogicalUnion),
      plan_context_(NULL),
      children_(children) {}

LogicalUnion::~LogicalUnion() {
  if (NULL != plan_context_) {
    delete plan_context_;
    plan_context_ = NULL;
  }
  for (auto i = 0; i < children_.size(); i++) {
    if (NULL != children_[i]) {
      delete children_[i];
      children_[i] = NULL;
    }
  }
}
// due to avg() column may be aliased, so judge the agg type by oper_type_

PlanContext LogicalUnion::GetPlanContext() {
  lock_->acquire();
  if (NULL != plan_context_) {
    delete plan_context_;
    plan_context_ = NULL;
  }
  vector<PlanContext> child_context;
  PlanContext ret;
  PlanContext ret1;
  // for (auto i = 0; i < children_.size(); i++) {
  child_context.push_back(children_[0]->GetPlanContext());
  child_context.push_back(children_[1]->GetPlanContext());

  ret.attribute_list_ = child_context[0].attribute_list_;

  //  ret.plan_partitioner_ = child_context[0].plan_partitioner_;
  //  cout << child_context[0].plan_partitioner_.GetNumberOfPartitions();
  //

  ret.plan_partitioner_.set_partition_func(
      child_context[0].plan_partitioner_.get_partition_func());
  ret.plan_partitioner_.set_partition_key(
      children_[0]->GetPlanContext().plan_partitioner_.get_partition_key());

  NodeID location = 0;
  int64_t data_cardinality;
  for (unsigned i = 0; i < children_.size(); i++) {
    for (unsigned j = 0; j < children_[i]
                                 ->GetPlanContext()
                                 .plan_partitioner_.GetNumberOfPartitions();
         j++) {
      data_cardinality += children_[i]
                              ->GetPlanContext()
                              .plan_partitioner_.GetPartition(j)
                              ->get_cardinality();
    }
  }
  // cout << "data_cardinality" << data_cardinality << endl;

  PartitionOffset offset = 0;
  PlanPartitionInfo par(offset, data_cardinality, location);
  std::vector<PlanPartitionInfo> partition_list;
  partition_list.push_back(par);
  ret.plan_partitioner_.set_partition_list(partition_list);
  //  ret.plan_partitioner_.set_partition_list(
  //      child_context[0].plan_partitioner_.get_partition_list());

  plan_context_ = new PlanContext();
  *plan_context_ = ret;
  lock_->release();
  return ret;
}

PhysicalOperatorBase* LogicalUnion::GetPhysicalPlan(
    const unsigned& block_size) {
  if (NULL == plan_context_) {
    GetPlanContext();
  }
  PhysicalOperatorBase* ret;
  vector<PhysicalOperatorBase*> children_phyplan;
  vector<PlanContext> child_plan_context;

  Expander::State expander_state;
  PhysicalOperatorBase* expander;
  ExchangeMerger::State exchange_state;
  std::vector<NodeID> upper_id_list;
  std::vector<NodeID> lower_id_list;
  PhysicalOperatorBase* exchange;

  for (auto i = 0; i < children_.size(); i++) {
    expander_state.block_count_in_buffer_ = EXPANDER_BUFFER_SIZE;
    expander_state.block_size_ = block_size;
    expander_state.init_thread_count_ = Config::initial_degree_of_parallelism;
    expander_state.child_ = children_[i]->GetPhysicalPlan(block_size);
    expander_state.schema_ = children_[i]->GetPlanContext().GetSchema();
    expander = new Expander(expander_state);
    exchange_state.block_size_ = block_size;
    exchange_state.child_ = expander;
    exchange_state.exchange_id_ =
        IDsGenerator::getInstance()->generateUniqueExchangeID();
    upper_id_list = GetInvolvedNodeID(plan_context_->plan_partitioner_);
    exchange_state.upper_id_list_ = upper_id_list;
    lower_id_list =
        GetInvolvedNodeID(children_[i]->GetPlanContext().plan_partitioner_);
    exchange_state.lower_id_list_ = lower_id_list;
    exchange_state.partition_schema_ =
        partition_schema::set_broadcast_partition();
    exchange_state.schema_ = children_[i]->GetPlanContext().GetSchema();
    exchange = new ExchangeMerger(exchange_state);

    Expander::State expander_state;
    expander_state.block_count_in_buffer_ = 10;
    expander_state.block_size_ = block_size;
    expander_state.init_thread_count_ = Config::initial_degree_of_parallelism;
    expander_state.child_ = exchange;
    expander_state.schema_ = children_[i]->GetPlanContext().GetSchema();
    PhysicalOperatorBase* expander = new Expander(expander_state);

    children_phyplan.push_back(exchange);

    child_plan_context.push_back(children_[i]->GetPlanContext());
  }

  PhysicalUnion::State local_state;
  vector<Schema*> input_schema;
  for (auto i = 0; i < children_.size(); i++) {
    input_schema.push_back(GetSchema(child_plan_context[1].attribute_list_));
  }
  local_state.block_size_ = block_size;
  local_state.input_schemas_ = input_schema;
  local_state.output_schema_ = GetSchema(child_plan_context[1].attribute_list_);
  local_state.children_ = children_phyplan;
  ret = new PhysicalUnion(local_state);
  return ret;
}

void LogicalUnion::Print(int level) const {
  cout << setw(level * kTabSize) << " "
       << "Union: ";
  ++level;
  GetPlanContext();
  cout << setw(level * kTabSize) << " "
       << "[Partition info: "
       << plan_context_->plan_partitioner_.get_partition_key().attrName
       << " table_id= "
       << plan_context_->plan_partitioner_.get_partition_key().table_id_
       << " column_id= "
       << plan_context_->plan_partitioner_.get_partition_key().index << " ]"
       << endl;
  for (auto i = 0; i < children_.size(); i++) {
    children_[i]->Print(level);
  }
}

}  // namespace logical_operator
}  // namespace claims
