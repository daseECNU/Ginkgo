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
 * /CLAIMS/logical_operator/logical_operator.h
 *
 *  Created on: Nov 7, 2013
 *      Author: wangli, fzh
 *       Email: fzhedu@gmail.com
 *
 * Description:
 *
 */
#ifndef LOGICAL_OPERATOR_LOGICAL_OPERATOR_H_
#define LOGICAL_OPERATOR_LOGICAL_OPERATOR_H_
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <atomic>
#include <iosfwd>
#include <set>

#include "../common/ids.h"
#include "../common/Schema/SchemaFix.h"
#include "../logical_operator/plan_context.h"
#include "../logical_operator/Requirement.h"
#include "../physical_operator/physical_operator_base.h"
#include "../utility/lock.h"
#include "../txn_manager/txn.hpp"
static std::atomic_uint MIDINADE_TABLE_ID(1000000);
namespace ginkgo {
namespace logical_operator {
#define kTabSize 4
using ginkgo::physical_operator::PhysicalOperatorBase;
using ginkgo::txn::QueryReq;
using ginkgo::txn::Query;
using ginkgo::txn::GetGlobalPartId;
enum OperatorType {
  kLogicalScan,
  kLogicalFilter,
  kLogicalAggregation,
  kLogicalEqualJoin,
  kLogicalProject,
  kLogicalSort,
  kLogicalQueryPlanRoot,
  kLogicalCrossJoin,
  kLogicalLimit,
  kLogicalSubquery,
  kLogicalDeleteFilter,
  kLogicalOuterJoin
};

typedef PhysicalOperatorBase* PhysicalPlan;
typedef struct PhysicalPlanDescriptor {
  PhysicalPlan plan;
  PlanContext plan_context_;
  unsigned cost;
};
/**
 * LogicalOperator is the base class of all logical operator.
 * GetPlanContext() aims at maintaining the property of the data after
 * completing every operator of plan. the property contains the output
 * attributes, partition key, cardinality and communication cost.
 * GetPhysicalPlan() adds current physical operator into the whole plan, result
 * into a plan tree.
 */
class LogicalOperator {
 public:
  LogicalOperator() {}
  LogicalOperator(OperatorType operator_type) {
    operator_type_ = operator_type;
    lock_ = new Lock();
  }
  virtual ~LogicalOperator() {
    if (NULL != lock_) {
      delete lock_;
      lock_ = NULL;
    }
  }
  /**
   * get the plan context which describes the property of the data after
   * having
   * executed corresponding operator.
   */
  virtual PlanContext GetPlanContext() = 0;

  /**
   * generate the iterator tree based on the computed plan_context. Hence,
   * this function can only be called after the calling of GetPlanContext().
   */
  virtual PhysicalOperatorBase* GetPhysicalPlan(const unsigned&) = 0;

  /**
   * get the optimal Physical plan that meets the requirement.
   * @return true if find physical plan that meets the requirement and store
   * the
   * physical plan and
   * its corresponding information in physical_plan_descriptor.
   */
  virtual bool GetOptimalPhysicalPlan(
      Requirement requirement, PhysicalPlanDescriptor& physical_plan_descriptor,
      const unsigned& block_size = 4096 * 1024){};

  virtual void Print(int level = 0) const = 0;
  virtual void PruneProj(set<string>& above_attrs) {}
  OperatorType get_operator_type() { return operator_type_; }

  /**
   * Get the information(list of partition to scan) for txn creation
   * Set the txn concurrency information to operator
   * @param request
   */
  virtual void GetTxnInfo(QueryReq& request) const {}
  virtual void SetTxnInfo(const Query& query) {}

  LogicalOperator* DecideAndCreateProject(set<string>& attrs,
                                          LogicalOperator* child);

 protected:
  Schema* GetSchema(const std::vector<Attribute>&) const;
  Schema* GetSchema(const std::vector<Attribute>&,
                    const std::vector<Attribute>&) const;
  std::vector<NodeID> GetInvolvedNodeID(const PlanPartitioner&) const;
  std::vector<NodeIP> ConvertNodeIDListToNodeIPList(
      const std::vector<NodeID>&) const;
  PhysicalPlanDescriptor GetBestPhysicalPlanDescriptor(
      const std::vector<PhysicalPlanDescriptor>) const;
  int GetIdInAttributeList(const std::vector<Attribute>& attributes,
                           const Attribute& attribute) const;
  inline void set_operator_type(OperatorType operator_type) {
    operator_type_ = operator_type;
  }
  void GetColumnToId(const std::vector<Attribute>& attributes,
                     map<string, int>& column_to_id);
  Lock* lock_;
  //  static std::atomic_uint MIDINADE_TABLE_ID;

 protected:
  OperatorType operator_type_;
};

}  // namespace logical_operator
}  // namespace ginkgo

#endif  // LOGICAL_OPERATOR_LOGICAL_OPERATOR_H_
