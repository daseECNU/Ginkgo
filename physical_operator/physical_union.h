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
 * /CLAIMS/physical_operator/physical_union.h
 *
 *  Created on: May 20, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 *
 */

#ifndef PHYSICAL_OPERATOR_PHYSICAL_UNION_H_
#define PHYSICAL_OPERATOR_PHYSICAL_UNION_H_

#include <vector>
#include <map>
#include <stack>

#include "../common/error_define.h"
#include "../common/expression/expr_node.h"
#include "../common/expression/expr_unary.h"
#include "../physical_operator/physical_operator_base.h"
#include "../common/hashtable.h"
#include "../common/hash.h"
#include "../common/ExpandedThreadTracker.h"
#include "../Debug.h"
#include "../utility/lock.h"
#include "../common/Schema/Schema.h"
#include "../common/Expression/queryfunc.h"
#include "../physical_operator/physical_operator.h"

using claims::common::ExprUnary;
using claims::common::ExprNode;
using claims::common::ExprEvalCnxt;

namespace claims {
namespace physical_operator {
#define NEWCONDI

/**
 * @brief     Aggregation physical operator
 * @details   physical operator about group by and aggregation,
 *  data will be processed as stream within one block each time from its child
 * operator.
 *  several threads will be created dynamically to process data simultaneously.
 */
class PhysicalUnion : public PhysicalOperator {
 protected:
  class UnionContext : public ThreadContext {
   public:
    ~UnionContext();
    BlockStreamBase *block_for_asking_;
    BlockStreamBase::BlockStreamTraverseIterator *block_stream_iterator_;
    DynamicBlockBuffer::Iterator buffer_iterator_;
    BlockStreamBase::BlockStreamTraverseIterator *buffer_stream_iterator_;
  };

 public:
  class State {
    friend class PhysicalUnion;

   public:
    enum Aggregation { kSum, kMin, kMax, kCount, kAvg };
    enum AggNodeType { kHybridAggGlobal, kHybridAggLocal, kNotHybridAgg };
    State(std::vector<Schema *> input, Schema *output,
          std::vector<PhysicalOperatorBase *> children, unsigned block_size);
    State()
        : input_schemas_(0), output_schema_(0), children_(0), block_size_(0){};
    ~State(){};
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
      ar &input_schemas_ &output_schema_ &children_;
    }

   public:
    std::vector<Schema *> input_schemas_;
    Schema *output_schema_;
    std::vector<PhysicalOperatorBase *> children_;
    unsigned block_size_;
  };
  PhysicalUnion(State state);
  PhysicalUnion();
  virtual ~PhysicalUnion();

  bool Open(SegmentExecStatus *const exec_status,
            const PartitionOffset &partition_offset);
  bool Next(SegmentExecStatus *const exec_status, BlockStreamBase *block);
  bool Close(SegmentExecStatus *const exec_status);
  // void Print();
  RetCode GetAllSegments(stack<Segment *> *all_segments);
  ThreadContext *CreateContext();

 public:
  State state_;

 private:
  DynamicBlockBuffer *block_buffer_;
// DynamicBlockBuffer::Iterator buffer_iterator_;

// BasicHashTable *hashtable_;
//  PartitionFunction *hash_;
// hashtable traverse and in the next func
//  Lock hashtable_cur_lock_;
//  unsigned bucket_cur_;
// BasicHashTable::Iterator it_;
// BlockStreamBase *block_for_asking_;
// PerformanceInfo *perf_info_;

// unsigned allocated_tuples_in_hashtable;
#ifdef TIME
  unsigned long long timer;
#endif

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<PhysicalOperator>(*this) & state_;
  }
};

}  // namespace physical_operator
}  // namespace claims

#endif  // PHYSICAL_OPERATOR_PHYSICAL_AGGREGATION_H_
