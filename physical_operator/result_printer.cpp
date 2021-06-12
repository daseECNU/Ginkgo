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
 * /CLAIMS/physical_operator/result_printer.cpp
 *  Created on: Nov 19, 2013
 *      Author: wangli
 */

#include "../common/error_define.h"
#include "../physical_operator/result_printer.h"
#include <stack>
using ginkgo::common::rSuccess;
namespace ginkgo {
namespace physical_operator {
ResultPrinter::ResultPrinter() : block_buffer_(0) {
  set_phy_oper_type(kPhysicalResult);
}
ResultPrinter::ResultPrinter(State state) : state_(state), block_buffer_(0) {
  set_phy_oper_type(kPhysicalResult);
}

ResultPrinter::~ResultPrinter() {}
bool ResultPrinter::Open(SegmentExecStatus* const exec_status,
                         const PartitionOffset& offset) {
  RETURN_IF_CANCELLED(exec_status);

  block_buffer_ =
      BlockStreamBase::createBlock(state_.schema_, state_.block_size_);
  tuple_count_ = 0;
  return state_.child_->Open(exec_status, offset);
}
bool ResultPrinter::Next(SegmentExecStatus* const exec_status,
                         BlockStreamBase*) {
  RETURN_IF_CANCELLED(exec_status);

  printf("Query result:\n");
  printf(
      "========================================================================"
      "================\n");
  for (unsigned i = 0; i < state_.attribute_name_list_.size(); i++) {
    std::string format = "%s" + state_.spliter_;
    printf(format.c_str(), state_.attribute_name_list_[i].c_str());
  }
  printf("\n");

  //	getchar();
  //	getchar();

  unsigned block_count(0);
  while (state_.child_->Next(exec_status, block_buffer_)) {
    RETURN_IF_CANCELLED(exec_status);

    unsigned tuple_in_block(0);
    BlockStreamBase::BlockStreamTraverseIterator* it =
        block_buffer_->createIterator();
    void* tuple;
    while ((tuple = it->nextTuple()) != 0) {
      state_.schema_->displayTuple(tuple, state_.spliter_.c_str());
      tuple_in_block++;
      tuple_count_++;
    }
    //		printf("Tuples in
    // Block[%d]=%d\n",block_count++,block_buffer_->getTuplesInBlock());
    block_buffer_->setEmpty();
    //		sleep(1);
  }
  return false;
}
bool ResultPrinter::Close(SegmentExecStatus* const exec_status) {
  printf("tuple count:%d\n", tuple_count_);
  block_buffer_->~BlockStreamBase();
  cout << "----------total tuples: " << tuple_count_ << "----------\n";
  return state_.child_->Close(exec_status);
}
void ResultPrinter::Print() {
  printf("Print:\n");
  state_.child_->Print();
}

ResultPrinter::State::~State() {
  delete schema_;
  if (child_ > 0) delete child_;
}

RetCode ResultPrinter::GetAllSegments(stack<Segment*>* all_segments) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_) {
    ret = state_.child_->GetAllSegments(all_segments);
  }
  return ret;
}
}  // namespace physical_operator
}  // namespace ginkgo
