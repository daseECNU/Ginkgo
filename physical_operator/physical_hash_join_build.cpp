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
 * /Claims/physical_operator/physical_hash_join_build.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "./physical_hash_join_build.h"

#include <stack>
#include <vector>

#include "../common/expression/data_type_oper.h"
#include "../Environment.h"
#include "../Executor/expander_tracker.h"
#include "../physical_operator/physical_hash_join.h"
#include "../physical_operator/segment.h"

using claims::common::DataTypeOper;
namespace claims {
namespace physical_operator {
PhysicalHashJoinBuild::PhysicalHashJoinBuild(State state)
    : state_(state),
      hashtable_(NULL),
      PhysicalOperator(barrier_number(2), serialized_section_number(1)),
      gpv_left_(NULL) {
  set_phy_oper_type(kPhysicalHashJoinBuild);
  InitExpandedStatus();
}
PhysicalHashJoinBuild::PhysicalHashJoinBuild()
    : hashtable_(NULL),
      PhysicalOperator(barrier_number(2), serialized_section_number(1)),
      gpv_left_(NULL) {
  set_phy_oper_type(kPhysicalHashJoinBuild);
  InitExpandedStatus();
}

PhysicalHashJoinBuild::~PhysicalHashJoinBuild() {
  if (NULL != state_.child_left_) {
    delete state_.child_left_;
    state_.child_left_ = NULL;
  }
}

PhysicalHashJoinBuild::State::State(PhysicalOperatorBase* child_left,
                                    Schema* input_schema_left,
                                    Schema* ht_schema,
                                    std::vector<unsigned> joinIndex_left,
                                    unsigned ht_nbuckets,
                                    unsigned ht_bucketsize, unsigned block_size,
                                    int64_t join_id)
    : child_left_(child_left),
      input_schema_left_(input_schema_left),
      hashtable_schema_(ht_schema),
      join_index_left_(joinIndex_left),
      hashtable_bucket_num_(ht_nbuckets),
      hashtable_bucket_size_(ht_bucketsize),
      block_size_(block_size),
      join_id_(join_id) {}

bool PhysicalHashJoinBuild::Open(SegmentExecStatus* const exec_status,
                                 const PartitionOffset& partition_offset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();

  if (TryEntryIntoSerializedSection(0)) {
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_desc, "Hash join build", 0));

    // optimal bucket size could contain 2 tuples
    hashtable_ = new BasicHashTable(
        state_.hashtable_bucket_num_, state_.hashtable_bucket_size_,
        state_.input_schema_left_->getTupleMaxSize());
    // register hashtable to SegmentExecTracker
    Environment::getInstance()->get_segment_exec_tracker()->RegisterHashTable(
        state_.join_id_ * 100 + partition_offset, hashtable_);

    gpv_left_ = DataTypeOper::partition_value_
        [state_.input_schema_left_->getcolumn(state_.join_index_left_[0])
             .type][((state_.hashtable_bucket_num_ &
                      (state_.hashtable_bucket_num_ - 1)) == 0)];

    bucket_num_mod_ = state_.hashtable_bucket_num_;
    if (((state_.hashtable_bucket_num_ & (state_.hashtable_bucket_num_ - 1)) ==
         0)) {
      --bucket_num_mod_;
    }
  }

  /**
   * For performance concern, the following line should place just after
   *"RegisterNewThreadToAllBarriers();"
   * in order to accelerate the open response time.
   *
   * I suppose not moving it before TryEntryIntoSerializedSection(0), in that
   * case, all the other threads must wait until the main thread finished
   * serialization, then continue processing. Tong
   */
  LOG(INFO) << "join build begin to open left child" << endl;
  state_.child_left_->Open(exec_status, partition_offset);
  LOG(INFO) << "join build finished opening left child" << endl;
  BarrierArrive(0);

  void* cur;
  void* tuple_in_hashtable;
  unsigned bn;

  BlockStreamBase* l_block_for_asking_ = BlockStreamBase::createBlock(
      state_.input_schema_left_, state_.block_size_);

  BlockStreamBase::BlockStreamTraverseIterator* l_block_stream_iterator_ =
      l_block_for_asking_->createIterator();

  const Schema* input_schema = state_.input_schema_left_->duplicateSchema();

  RETURN_IF_CANCELLED(exec_status);

  LOG(INFO) << "join build begin to call left child's next()" << endl;
  while (state_.child_left_->Next(exec_status, l_block_for_asking_)) {
    RETURN_IF_CANCELLED(exec_status);
    // TODO(fzh) should reuse the block_iterator, instead of doing create/delete
    delete l_block_stream_iterator_;
    l_block_stream_iterator_ = l_block_for_asking_->createIterator();
    while (NULL != (cur = l_block_stream_iterator_->nextTuple())) {
      const void* key_addr =
          input_schema->getColumnAddess(state_.join_index_left_[0], cur);
      bn = gpv_left_(key_addr, bucket_num_mod_);
      tuple_in_hashtable = hashtable_->atomicAllocate(bn);
      /* copy join index columns*/
      input_schema->copyTuple(cur, tuple_in_hashtable);
    }
    l_block_for_asking_->setEmpty();
  }

  DELETE_PTR(input_schema);
  DELETE_PTR(l_block_for_asking_);
  DELETE_PTR(l_block_stream_iterator_);
  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    UnregisterExpandedThreadToAllBarriers(1);
    return true;
  }

  BarrierArrive(1);
  LOG(INFO) << "join build finished" << endl;

  return true;
}

bool PhysicalHashJoinBuild::Next(SegmentExecStatus* const exec_status,
                                 BlockStreamBase* block) {
  return false;  // should be false, otherwise while() of upper operator will be
                 // in dead loop
}

bool PhysicalHashJoinBuild::Close(SegmentExecStatus* const exec_status) {
  state_.child_left_->Close(exec_status);
  return true;
}

void PhysicalHashJoinBuild::Print() {
  LOG(INFO) << "Join: buckets: (num= " << state_.hashtable_bucket_num_
            << " , size= "
            << get_aligned_space(state_.input_schema_left_->getTupleMaxSize())
            << ")" << endl;
  cout << "Join: buckets: (num= " << state_.hashtable_bucket_num_ << " , size= "
       << get_aligned_space(state_.input_schema_left_->getTupleMaxSize()) << ")"
       << endl;
  LOG(INFO) << "------Join Build-------" << endl;
  cout << "------Join Build-------" << endl;
  state_.child_left_->Print();
}

RetCode PhysicalHashJoinBuild::GetAllSegments(stack<Segment*>* all_segments) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_left_) {
    ret = state_.child_left_->GetAllSegments(all_segments);
  }
  return ret;
}
}
}  // namespace claims
