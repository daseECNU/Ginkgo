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
 * /CLAIMS/logical_operator/logical_left_join.h
 *
 *  Created on: Mar 16, 2016
 *      Author: yuyang
 *		   Email: youngfish93@hotmail.com
 *
 * Description:
 *
 */

#ifndef LOGICAL_OPERATOR_LOGICAL_OUTER_JOIN_H_
#define LOGICAL_OPERATOR_LOGICAL_OUTER_JOIN_H_
#include <vector>
#include "../common/expression/expr_node.h"
#include "../catalog/attribute.h"
#include "../catalog/partitioner.h"
#include "../logical_operator/logical_operator.h"
#include "../physical_operator/physical_sort.h"
#include "../logical_operator/logical_equal_join.h"

namespace ginkgo {
namespace logical_operator {

/**
 * @brief Generate equal join logical plan.
 * @details EqualJoin operator achieves the join statement tables.It requires
 * equivalent conditions.As for implementation, one is to
 * send all data to a same machine.But the generated table will be too big to
 * store and it is inefficient.So we partition the data to several machines.Each
 * of them does some join and return.
 */
class LogicalOuterJoin : public LogicalOperator {
 public:
  /**
   * @brief The JoinPair contains two attributes to be joined.
   */
  //  struct JoinPair {
  //    JoinPair(const Attribute& left_join_attr, const Attribute&
  //    right_join_attr)
  //        : left_join_attr_(left_join_attr), right_join_attr_(right_join_attr)
  //        {}
  //    Attribute left_join_attr_;
  //    Attribute right_join_attr_;
  //  };
  enum JoinPolicy {
    kNull,
    kNoRepartition,
    kLeftRepartition,
    kRightRepartition,
    kCompleteRepartition
  };

 public:
  /**
   * @brief  Method description:Create a OuterJoin implement.
   * @param  std::vector<JoinPair>
   * @param  LogicalOperator* left_input
   * @param  LogicalOperator* right_input
   */
  LogicalOuterJoin(std::vector<LogicalEqualJoin::JoinPair>,
                   LogicalOperator* left_input, LogicalOperator* right_input,
                   int join_type);
  LogicalOuterJoin(std::vector<LogicalEqualJoin::JoinPair>,
                   LogicalOperator* left_input, LogicalOperator* right_input,
                   int join_type, vector<ExprNode*> join_condi);
  virtual ~LogicalOuterJoin();
  /**
   * @brief Method description: Get the child information.
   * @details The mostly important member is "property" and "attributes
   * list". When getting data from child, we make some choices according to
   * JoinPolice. JoinPolice is generated from
   * canLeverageHashPartition(), isEqualCondition(), hasSamePartition().
   * If all of them is true, it means partition_key in the join_list and two
   * partition_keys in the same join_pair.Besides, it they have partitioned to
   * the same machine.So we don't need repartition, and JoinPolice =
   * kNodeRepartition.
   * If both canLeverageHashPartition()s are true, but isEqualCondition() or
   * hasSamePartition() is false, the machine which has smaller data will send
   * its data to another according to decideLeftOrRightRepartition().
   * If canLeverageHashPartition(left) is true but canLeverageHashPartition
   * (right) is false, right nodes will be repartitioned.
   * join_police_ = kRightRepartition
   * If canLeverageHashPartition(left) is false but canLeverageHashPartition
   * (right) is true, left nodes will be repartitioned.
   * oin_police_ = kLeftRepartition
   * If both canLeverageHashPartition()s are false, left and right nodes will be
   * repartitioned.
   * join_police_ = kCompleteRepartition
   */
  PlanContext GetPlanContext();
  PhysicalOperatorBase* GetPhysicalPlan(const unsigned& blocksize);
  bool GetOptimalPhysicalPlan(Requirement requirement,
                              PhysicalPlanDescriptor& physical_plan_descriptor,
                              const unsigned& block_size = 4096 * 1024);

  void GetTxnInfo(QueryReq& request) const override {
    left_child_->GetTxnInfo(request);
    right_child_->GetTxnInfo(request);
  }
  void SetTxnInfo(const Query& query) override {
    left_child_->SetTxnInfo(query);
    right_child_->SetTxnInfo(query);
  }

  void PruneProj(set<string>& above_attrs);

 private:
  std::vector<unsigned> GetLeftJoinKeyIds() const;
  std::vector<unsigned> GetRightJoinKeyIds() const;
  std::vector<unsigned> GetLeftPayloadIds() const;
  std::vector<unsigned> GetRightPayloadIds() const;
  int GetIdInLeftJoinKeys(const Attribute&) const;
  int GetIdInLeftJoinKeys(
      const Attribute&,
      const std::vector<Attribute> shadow_attribute_list) const;
  int GetIdInRightJoinKeys(const Attribute&) const;
  int GetIdInRightJoinKeys(
      const Attribute&,
      const std::vector<Attribute> shadow_attribute_list) const;
  int GetIdInAttributeList(const std::vector<Attribute>& attributes,
                           const Attribute&) const;
  bool IsHashOnLeftKey(const Partitioner& part, const Attribute& key) const;
  void DecideJoinPolicy(const PlanContext& left_context,
                        const PlanContext& right_context);
  /**
   * @brief Method description:Check whether the partitioning is based on hash
   * and the hash key is a subset of the join keys such that hash join is
   * enabled.
   * @param const std::vector<Attribute>& partition_key_list
   * @param const DataflowPartitioningDescriptor& partitoiner
   * @return bool
   */
  bool CanOmitHashRepartition(const std::vector<Attribute>& join_key_list,
                              const PlanPartitioner& partitoiner) const;
  /**
   * @brief Method description:Check whether two partition_keys in the same
   * join_pair.
   * @param const Attribute& left
   * @param const Attribute& right
   * @return  bool
   */
  bool IsInOneJoinPair(const Attribute& left_partition_key,
                       const Attribute& right_partition_key) const;

  /**
   * @brief Method description:Check which has the smaller data.
   * @details Current version only consider the data size for simplicity.
   * @param const Dataflow& left_dataflow
   * @param const Dataflow& right_dataflow
   * @return JoinPolice
   * TODO(admin): Consider not only data size but also other factors, such as
   * parallelism, resource, etc.
   */
  JoinPolicy DecideLeftOrRightRepartition(
      const PlanContext& left_dataflow,
      const PlanContext& right_dataflow) const;

  PlanPartitioner DecideOutputDataflowProperty(
      const PlanContext& left_dataflow, const PlanContext& right_dataflow,
      int join_type) const;
  void Print(int level = 0) const;

  /**
   * Assuming that R and S are the two join table, the selectivity is
   * the number of tuples generated by the join operator to the number of
   * |R|*|S|.
   */
  double PredictEqualJoinSelectivity(const PlanContext& left_dataflow,
                                     const PlanContext& right_dataflow) const;

  /**
   * assuming that R ane S are the two join table, and the join condition is
   * R.x=S.x.
   * return |O|, where |O|=|R.x=x1|*|S.x=x1|+|R.x=x2|*|S.x=x2|+......
   */
  double PredictEqualJoinSelectivityOnSingleJoinAttributePair(
      const Attribute& attr_left, const Attribute& attr_right) const;

 private:
  std::vector<ExprNode*> join_condi_;
  std::vector<LogicalEqualJoin::JoinPair> joinkey_pair_list_;
  std::vector<Attribute> left_join_key_list_;
  std::vector<Attribute> right_join_key_list_;
  LogicalOperator* left_child_;
  LogicalOperator* right_child_;
  JoinPolicy join_policy_;
  PlanContext* plan_context_;
  // join_type_ = 0 means left join while join_type = 1 means right join
  // join_type_ = 2 means full join
  int join_type_;
};
}  // namespace logical_operator
}  // namespace ginkgo

#endif  //  LOGICAL_OPERATOR_LOGICAL_OUTER_JOIN_H_
