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
 * /CLAIMS/logical_operator/logical_scan.h
 *
 *  Created on: Nov 7, 2013
 *      Author: wangli, HanZhang
 *       Email:wangli1426@gmail.com
 *
 * Description: Implementation of Scan operator in logical layer
 *
 */

#ifndef LOGICAL_OPERATOR_LOGICAL_SCAN_H_
#define LOGICAL_OPERATOR_LOGICAL_SCAN_H_

#include <iosfwd>
#include <vector>
#include <set>

#include "../common/ids.h"
#include "../catalog/attribute.h"
#include "../catalog/table.h"
#include "../logical_operator/logical_operator.h"
#include "../logical_operator/plan_context.h"
#include "../physical_operator/physical_operator_base.h"

namespace ginkgo {
namespace logical_operator {

/**
 * @brief Method description:This is the implementation of Scan operator in
 * logical layer. Currently, we only choose the third of constructor functions.
 * Through the method of LogicalScan, we can get data context and a physical
 * operator.
 */

class LogicalScan : public LogicalOperator {
 public:
  LogicalScan(std::vector<Attribute> attribute_list);
  LogicalScan(const TableID&);
  LogicalScan(ProjectionDescriptor* projection, const float sample_rate_ = 1);
  LogicalScan(string table_alias, set<string> columns, string table_name,
              bool is_all, const float sample_rate_ = 1);

  LogicalScan(const TableID&,
              const std::vector<unsigned>& selected_attribute_index_list);
  virtual ~LogicalScan();
  PlanContext GetPlanContext();
  PhysicalOperatorBase* GetPhysicalPlan(const unsigned&);
  bool GetOptimalPhysicalPlan(Requirement requirement,
                              PhysicalPlanDescriptor& physical_plan_descriptor,
                              const unsigned& kBlock_size = 4096 * 1024);
  void ChangeAliasAttr();

  void GetTxnInfo(QueryReq& request) const override {
    auto table_id = target_projection_->getProjectionID().table_id;
    auto proj_id = target_projection_->getProjectionID().projection_off;
    auto part_count =
        target_projection_->getPartitioner()->getNumberOfPartitions();
    for (auto part_id = 0; part_id < part_count; part_id++) {
      request.part_list_.push_back(GetGlobalPartId(table_id, proj_id, part_id));
    }
  }
  void SetTxnInfo(const Query& query) override {
    query_ = query;
    query_.GenTxnInfo();
  }

 private:
  /**check whether all the involved attributes are in the same projection.*/
  bool IsInASingleProjection() const;
  void Print(int level = 0) const;

 private:
  std::vector<Attribute> scan_attribute_list_;
  ProjectionDescriptor* target_projection_;
  PlanContext* plan_context_;
  string table_alias_;
  string table_name_;
  float sample_rate_;

  Query query_;

  set<string> columns_;
  bool is_all_;
};

}  // namespace logical_operator
}  // namespace ginkgo

#endif  //  LOGICAL_OPERATOR_LOGICAL_SCAN_H_
