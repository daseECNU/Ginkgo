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
 * /Claims/physical_operator/physical_hash_join_build.h
 *
 *  Created on: Oct 4, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef PHYSICAL_OPERATOR_PHYSICAL_HASH_JOIN_BUILD_H_
#define PHYSICAL_OPERATOR_PHYSICAL_HASH_JOIN_BUILD_H_

#include "./physical_hash_join_build.h"
#include <stack>
#include <vector>

#include "./physical_operator.h"
#include "../common/error_define.h"
#include "../common/expression/expr_node.h"
#include "../common/ids.h"
#include "../common/Schema/Schema.h"
#include "../exec_tracker/segment_exec_status.h"
#include "../physical_operator/physical_operator_base.h"
#include "../physical_operator/segment.h"

using claims::common::ExprNode;
using claims::common::GetPartitionValue;

namespace claims {
namespace physical_operator {

class PhysicalHashJoinBuild : public PhysicalOperator {
 public:
  class State {
    friend class PhysicalHashJoinBuild;

   public:
    /**
     * @brief Method description: Construct the State with paras, not used in
     *                            the current version.
     */
    State(PhysicalOperatorBase* child_left, Schema* input_schema_left,
          Schema* ht_schema, std::vector<unsigned> joinIndex_left,
          unsigned ht_nbuckets, unsigned ht_bucketsize, unsigned block_size,
          int64_t join_id);
    State() {}
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
      ar& child_left_& input_schema_left_& hashtable_schema_& join_index_left_&
          hashtable_bucket_num_& hashtable_bucket_size_& block_size_& join_id_;
    }

   public:
    // input and output
    PhysicalOperatorBase* child_left_;
    Schema* input_schema_left_;
    Schema* hashtable_schema_;
    // how to join
    std::vector<unsigned> join_index_left_;
    // hashtable
    unsigned hashtable_bucket_num_;
    unsigned hashtable_bucket_size_;
    unsigned block_size_;
    int64_t join_id_;
  };

 public:
  PhysicalHashJoinBuild();
  PhysicalHashJoinBuild(State state);

  virtual ~PhysicalHashJoinBuild();
  bool Open(SegmentExecStatus* const exec_status,
            const PartitionOffset& partition_offset = 0);
  bool Next(SegmentExecStatus* const exec_status, BlockStreamBase* block);
  bool Close(SegmentExecStatus* const exec_status);
  void Print();
  RetCode GetAllSegments(stack<Segment*>* all_segments);

 public:
  State state_;
  BasicHashTable* hashtable_;
  Schema* hashtable_schema_;
  GetPartitionValue gpv_left_;
  unsigned bucket_num_mod_;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& boost::serialization::base_object<PhysicalOperator>(*this) & state_;
  }
};
}  // namespace physical_operator
}  // namespace claims

#endif  //  PHYSICAL_OPERATOR_PHYSICAL_HASH_JOIN_BUILD_H_
