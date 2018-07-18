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
 * physical_operator/physical_union.cpp
 *
 *  Created on: May 20, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 *
 * Description:
 */

#include "../physical_operator/physical_union.h"
#include "../common/Block/BlockStream.h"
#include "../Executor/expander_tracker.h"
#include "../physical_operator/physical_nest_loop_join.h"

namespace claims {
namespace physical_operator {

PhysicalUnion::PhysicalUnion(State state)
    : PhysicalOperator(2, 2), block_buffer_(NULL), state_(state) {
  InitExpandedStatus();
}

PhysicalUnion::State::State(std::vector<Schema *> input_schemas,
                            Schema *output_schema,
                            std::vector<PhysicalOperatorBase *> children,
                            unsigned block_size)
    : input_schemas_(input_schemas),
      output_schema_(output_schema),
      children_(children),
      block_size_(block_size) {}

PhysicalUnion::~PhysicalUnion() {}

bool PhysicalUnion::Open(SegmentExecStatus *const exec_status,
                         const PartitionOffset &partition_offset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();
  if (TryEntryIntoSerializedSection(0)) {  // the first thread of all need to do
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_desc, "Union", 0));
    LOG(INFO) << "[Union]: [the first thread opens the Union "
                 "physical operator]" << std::endl;
  }
  int child_size = state_.children_.size();
  for (auto i = 0; i < child_size - 1; i++) {
    state_.children_[i]->Open(exec_status, partition_offset);
    BarrierArrive(0);
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_desc, "union", 0));
    LOG(INFO) << "[Union]: [the first thread opens the Union "
                 "physical operator]" << endl;
  }

  state_.children_[child_size - 1]->Open(exec_status, partition_offset);
  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    UnregisterExpandedThreadToAllBarriers(1);
    LOG(INFO) << "[union]: [the" << pthread_self()
              << "the union thread is called to exit]" << std::endl;
    return true;  // the
  }
  BarrierArrive(1);
  return true;
}

bool PhysicalUnion::Next(SegmentExecStatus *const exec_status,
                         BlockStreamBase *block) {
  //  unsigned total_length_ = 0;
  //  for (unsigned i = 0; i < state_.input_schemas_.size(); i++) {
  //    total_length_ += state_.input_schemas_[i]->getTupleMaxSize();
  //  }
  static int num;
  BlockStreamBase *block_for_asking;
  block_for_asking = BlockStreamBase::createBlock(state_.input_schemas_[0],
                                                  state_.block_size_);

  BlockStreamBase::BlockStreamTraverseIterator *block_it;
  void *tuple_ptr = NULL;
  vector<void *> thread_tuple;
  thread_tuple.clear();
  BlockStreamBase::BlockStreamTraverseIterator *tuple_it;

  for (auto i = 0; i < state_.children_.size(); i++) {
    while (state_.children_[i]->Next(exec_status, block)) {
      num++;
      RETURN_IF_CANCELLED(exec_status);
      return true;
    }
  }
  return false;
}

bool PhysicalUnion::Close(SegmentExecStatus *const exec_status) {
  for (unsigned i = 0; i < state_.children_.size(); i++) {
    state_.children_[i]->Close(exec_status);
  }
  return true;
}

RetCode PhysicalUnion::GetAllSegments(stack<Segment *> *all_segments) {
  RetCode ret = rSuccess;
  for (auto i = 0; i < state_.children_.size(); i++) {
    ret = state_.children_[i]->GetAllSegments(all_segments);
  }
  return ret;
}

PhysicalUnion::UnionContext::~UnionContext() {
  DELETE_PTR(block_for_asking_);
  DELETE_PTR(block_stream_iterator_);
  DELETE_PTR(buffer_stream_iterator_);
}

ThreadContext *PhysicalUnion::CreateContext() {
  UnionContext *jtc = new UnionContext();
  return jtc;
}

}  // namespace physical_operator
}  // namespace claims
