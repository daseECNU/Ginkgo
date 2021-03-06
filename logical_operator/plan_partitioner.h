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
 * ./LogicalPlan/plan_partitioner.h
 *
 *  Created on: Nov 10, 2013
 *      Author: wangli, fangzhuhe
 *       Email: fzhedu@gmail.com
 *
 * Description:
 */

#ifndef LOGICAL_OPERATOR_PLAN_PARTITIONER_H_
#define LOGICAL_OPERATOR_PLAN_PARTITIONER_H_
#include <vector>
#include "../catalog/partitioner.h"
#include "../logical_operator/plan_partition_info.h"

using namespace ginkgo::catalog;

namespace ginkgo {
namespace logical_operator {
/**
 * describe how the PlanContext are partitioned and the partition property
 * between them. I think that, in the current design, the PlanContext
 * descriptor fails to contain the information describing how the data
 * is processed since it is release from the source, i.e., Scan operator.
 * the information of every partition is described by the PlanPartitionInfo.
 * all this information originates from the partition information of the raw
 * dataset.
 */
class PlanPartitioner {
 public:
  PlanPartitioner() : partition_func_(0) {}
  explicit PlanPartitioner(const Partitioner& partitoiner);
  PlanPartitioner(const PlanPartitioner&);
  virtual ~PlanPartitioner();
  bool HasSamePartitionLocation(const PlanPartitioner& target) const;
  unsigned GetAggregatedDataSize() const;
  unsigned long GetAggregatedDataCardinality() const;
  PartitionFunction::PartitionStyle GetPartitionStyle() const;
  unsigned GetNumberOfPartitions() const;
  PlanPartitionInfo* GetPartition(unsigned id) const;

  std::vector<PlanPartitionInfo> get_partition_list() const;
  void set_partition_list(const std::vector<PlanPartitionInfo>&);

  void set_partition_func(PartitionFunction* partition_function);
  PartitionFunction* get_partition_func() const;
  Attribute get_partition_key() const;
  void set_partition_key(const Attribute& partitionkey);
  void AddShadowPartitionKey(const Attribute& partitionkey);
  bool HasShadowPartitionKey() const;
  std::vector<Attribute> get_shadow_partition_keys() const;
  RetCode UpdateTableNameOfPartitionKey(const string& table_alias);

 private:
  std::vector<PlanPartitionInfo> partition_list_;
  PartitionFunction* partition_func_;
  Attribute partition_key_;

  /**
   * After the no-partitioning EqualHashJoin where the left join input is
   * partitioned on A1 and the right join input is partitioned on A2, we can say
   * that the generated PlanContext is either partitioned on A1 or partitioned
   * on A2. In such cases, each attribute is a SHADOW PARTITION KEY to the
   * other.
   */
  std::vector<Attribute> shadow_partition_keys_;

  /**
   * History: a data structure is needed here to represent how the data flow is
   * derived, converted, and transformed, such that the estimate module could
   * leverage this information to make better prediction to the data flow
   * properties, e.g., data volume, distribution, etc.
   * In the current implementation, each operator just know the partition
   * style of the input data flow and the data volume generated by its child
   * operator rather than a global view of the data flow conversion history.
   */
};

}  // namespace logical_operator
}  // namespace ginkgo
#endif  // LOGICAL_OPERATOR_PLAN_PARTITIONER_H_
