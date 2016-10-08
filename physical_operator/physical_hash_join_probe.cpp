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
 * /Claims/physical_operator/physical_hash_join_probe.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "./physical_hash_join_probe.h"

#include <stack>
#include <vector>

#include "../common/expression/data_type_oper.h"
#include "../common/expression/expr_node.h"
#include "../Environment.h"
#include "../scheduler/pipeline_job.h"
#include "../scheduler/stage_task.h"

using claims::common::DataTypeOper;
using claims::scheduler::PipelineJob;
using claims::scheduler::StageTask;
namespace claims {
namespace physical_operator {

PhysicalHashJoinProbe::PhysicalHashJoinProbe()
    : hash_func_(NULL),
      PhysicalOperator(barrier_number(2), serialized_section_number(1)),
      hashtable_(NULL),
      eftt_(NULL),
      memcpy_(NULL),
      memcat_(NULL),
      gpv_left_(NULL),
      gpv_right_(NULL) {
  set_phy_oper_type(kPhysicalHashJoinProbe);
  InitExpandedStatus();
}

PhysicalHashJoinProbe::PhysicalHashJoinProbe(State state)
    : state_(state),
      PhysicalOperator(barrier_number(2), serialized_section_number(1)),
      hash_func_(NULL),
      hashtable_(NULL),
      eftt_(NULL),
      memcpy_(NULL),
      memcat_(NULL),
      gpv_left_(NULL),
      gpv_right_(NULL) {
  set_phy_oper_type(kPhysicalHashJoinProbe);
  InitExpandedStatus();
}

PhysicalHashJoinProbe::~PhysicalHashJoinProbe() {
  if (NULL != state_.child_right_) {
    delete state_.child_right_;
    state_.child_right_ = NULL;
  }
  if (NULL != state_.child_left_) {
    delete state_.child_left_;
    state_.child_left_ = NULL;
  }
  for (int i = 0; i < state_.join_condi_.size(); ++i) {
    DELETE_PTR(state_.join_condi_[i]);
  }
  state_.join_condi_.clear();
}

PhysicalHashJoinProbe::State::State(
    PhysicalOperatorBase* child_left, PhysicalOperatorBase* child_right,
    Schema* input_schema_left, Schema* input_schema_right,
    Schema* output_schema, Schema* ht_schema,
    std::vector<unsigned> joinIndex_left, std::vector<unsigned> joinIndex_right,
    unsigned ht_nbuckets, unsigned ht_bucketsize, unsigned block_size,
    vector<ExprNode*> join_condi, int64_t join_id)
    : child_left_(child_left),
      child_right_(child_right),
      input_schema_left_(input_schema_left),
      input_schema_right_(input_schema_right),
      output_schema_(output_schema),
      hashtable_schema_(ht_schema),
      join_index_left_(joinIndex_left),
      join_index_right_(joinIndex_right),
      hashtable_bucket_num_(ht_nbuckets),
      hashtable_bucket_size_(ht_bucketsize),
      block_size_(block_size),
      join_condi_(join_condi),
      join_id_(join_id) {}

bool PhysicalHashJoinProbe::Open(SegmentExecStatus* const exec_status,
                                 const PartitionOffset& partition_offset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();
  //  if the underlying codes are put into the serializedsection, then the
  //  active may be shrunk, resulting into error
  if (NULL != state_.child_left_) {
    state_.child_left_->Open(exec_status, partition_offset);
    BlockStreamBase* l_block_for_asking_ = BlockStreamBase::createBlock(
        state_.input_schema_left_, state_.block_size_);
    state_.child_left_->Next(exec_status, l_block_for_asking_);
    DELETE_PTR(l_block_for_asking_);
  }
  if (TryEntryIntoSerializedSection(0)) {
    gpv_right_ = DataTypeOper::partition_value_
        [state_.input_schema_right_->getcolumn(state_.join_index_right_[0])
             .type][((state_.hashtable_bucket_num_ &
                      (state_.hashtable_bucket_num_ - 1)) == 0)];
    join_id_par_off_ = state_.join_id_ * 100 + partition_offset;
    hashtable_ =
        Environment::getInstance()->get_segment_exec_tracker()->GetHashTable(
            join_id_par_off_);
    assert(NULL != hashtable_);
    bucket_num_mod_ = state_.hashtable_bucket_num_;
    if (((state_.hashtable_bucket_num_ & (state_.hashtable_bucket_num_ - 1)) ==
         0)) {
      --bucket_num_mod_;
    }
  }
  JoinThreadContext* jtc = CreateOrReuseContext(crm_numa_sensitive);

  BarrierArrive(0);

  state_.child_right_->Open(exec_status, partition_offset);
  BarrierArrive(1);
  return true;
}

bool PhysicalHashJoinProbe::Next(SegmentExecStatus* const exec_status,
                                 BlockStreamBase* block) {
  RETURN_IF_CANCELLED(exec_status);

  void* result_tuple = NULL;
  void* tuple_from_right_child;
  void* tuple_in_hashtable;
  void* key_in_input;
  void* key_in_hashtable;
  void* column_in_joined_tuple;
  bool key_exit;
  int hash_tuple_size = state_.hashtable_schema_->getTupleMaxSize();

  JoinThreadContext* jtc = (JoinThreadContext*)GetContext();

  /**
   * A specific method suitable for physical_join.
   * In this case, it preserves the r_block_stream_iterator_ and
   * hashtable_iterator_ status for physical_join's father to call Next() from
   * the previous call.
   * e.g.: Let's suppose that when physical_join's father first called Next(),
   * it returned true when the block for sending was full whereas half of the
   * tuples of a block from its right child was read. The next time
   * physical_join's father calls Next(), it should go on operates on that
   * right child block, so we need r_block_stream_iterator_ preserved, moreover
   * it should go on operates on last matched tuple not sent due to block for
   * send was full, so we need hashtable_iterator_ preserved.
   */
  while (true) {
    RETURN_IF_CANCELLED(exec_status);

    while (NULL != (tuple_from_right_child =
                        jtc->r_block_stream_iterator_->currentTuple())) {
      while (NULL !=
             (tuple_in_hashtable = jtc->hashtable_iterator_.readCurrent())) {
#ifdef CodeGen
        cff_(tuple_in_hashtable, tuple_from_right_child, &key_exit,
             state_.join_index_left_, state_.join_index_right_,
             state_.hashtable_schema_, state_.input_schema_right_, eftt_);
#else
        key_exit =
            JoinCondiProcess(tuple_in_hashtable, tuple_from_right_child, jtc);
#endif
        if (key_exit) {
          if (NULL != (result_tuple = block->allocateTuple(
                           state_.output_schema_->getTupleMaxSize()))) {
            produced_tuples++;
            if (memcat_) {
              memcat_(result_tuple, tuple_in_hashtable, tuple_from_right_child);
            } else {
              const unsigned copyed_bytes =
                  state_.input_schema_left_->copyTuple(tuple_in_hashtable,
                                                       result_tuple);
              state_.input_schema_right_->copyTuple(
                  tuple_from_right_child, (char*)result_tuple + copyed_bytes);
            }
          } else {
            return true;
          }
        }

        jtc->hashtable_iterator_.increase_cur_();
      }
      jtc->r_block_stream_iterator_->increase_cur_();
#ifdef _DEBUG_
      consumed_tuples_from_right++;
#endif
      if (NULL != (tuple_from_right_child =
                       jtc->r_block_stream_iterator_->currentTuple())) {
        unsigned bn =
            gpv_right_(state_.input_schema_right_->getColumnAddess(
                           state_.join_index_right_[0], tuple_from_right_child),
                       bucket_num_mod_);
        hashtable_->placeIterator(jtc->hashtable_iterator_, bn);
      }
    }
    jtc->r_block_for_asking_->setEmpty();
    jtc->hashtable_iterator_ = hashtable_->CreateIterator();
    if (state_.child_right_->Next(exec_status, jtc->r_block_for_asking_) ==
        false) {
      if (block->Empty() == true) {
        return false;
      } else {
        return true;
      }
    }
    delete jtc->r_block_stream_iterator_;
    jtc->r_block_stream_iterator_ = jtc->r_block_for_asking_->createIterator();
    if ((tuple_from_right_child =
             jtc->r_block_stream_iterator_->currentTuple())) {
      unsigned bn =
          gpv_right_(state_.input_schema_right_->getColumnAddess(
                         state_.join_index_right_[0], tuple_from_right_child),
                     bucket_num_mod_);
      hashtable_->placeIterator(jtc->hashtable_iterator_, bn);
    }
  }
}

bool PhysicalHashJoinProbe::Close(SegmentExecStatus* const exec_status) {
  DestoryAllContext();
  InitExpandedStatus();

  Environment::getInstance()->get_segment_exec_tracker()->UnRegisterHashTable(
      join_id_par_off_);
  if (NULL != hashtable_) {
    delete hashtable_;
    hashtable_ = NULL;
  }
  if (NULL != state_.child_left_) {
    state_.child_left_->Close(exec_status);
  }
  state_.child_right_->Close(exec_status);
  return true;
}

void PhysicalHashJoinProbe::Print() {
  std::cout << "-----------------HashJoinProbe------------------" << std::endl;
  std::cout << "hash join id= " << state_.join_id_ << endl;
  if (NULL != state_.child_left_) {
    LOG(INFO) << "------Join probe Left-------" << endl;
    cout << "------Join probe Left-------" << endl;
    state_.child_left_->Print();
  }
  LOG(INFO) << "------Join probe Right-------" << endl;
  cout << "------Join probe Right-------" << endl;
  state_.child_right_->Print();
}

RetCode PhysicalHashJoinProbe::GetAllSegments(stack<Segment*>* all_segments) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_right_) {
    ret = state_.child_right_->GetAllSegments(all_segments);
  }
  if (NULL != state_.child_left_) {
    ret = state_.child_left_->GetAllSegments(all_segments);
  }
  return ret;
}
RetCode PhysicalHashJoinProbe::GetJobDAG(JobContext* const job_cnxt) {
  RetCode ret = rSuccess;
  PipelineJob* pjob = NULL;
  if (NULL != state_.child_left_) {
    ret = state_.child_left_->GetJobDAG(job_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    // create stage-task
    vector<NodeID> empty_node;  // the upper node of this stage-task is empty
    job_cnxt->set_stage_tasks((new StageTask(
        state_.child_left_, job_cnxt->get_node_id(), empty_node, 0)));
    state_.child_left_ = NULL;
    // create pipeline-job
    pjob = new PipelineJob(job_cnxt->get_stage_tasks(), job_cnxt->get_parents(),
                           job_cnxt->GenJobId());
    job_cnxt->ClearParents();
    job_cnxt->ClearStageTasks();
  } else {
    LOG(ERROR) << "the left child of join probe is NULL";
    return rFailure;
  }
  if (NULL != state_.child_right_) {
    ret = state_.child_right_->GetJobDAG(job_cnxt);
    if (rSuccess != ret) {
      return ret;
    }
    job_cnxt->set_parents(pjob);  // add left sub-tree
  } else {
    LOG(ERROR) << "the right child of join probe is NULL";
    return rFailure;
  }
  return ret;
}
inline ThreadContext* PhysicalHashJoinProbe::CreateContext() {
  JoinThreadContext* jtc = new JoinThreadContext();
  jtc->l_block_for_asking_ = BlockStreamBase::createBlock(
      state_.input_schema_left_, state_.block_size_);
  jtc->l_block_stream_iterator_ = jtc->l_block_for_asking_->createIterator();
  jtc->r_block_for_asking_ = BlockStreamBase::createBlock(
      state_.input_schema_right_, state_.block_size_);
  jtc->r_block_stream_iterator_ = jtc->r_block_for_asking_->createIterator();
  ExprNode* new_node = NULL;
  for (int i = 0; i < state_.join_condi_.size(); ++i) {
    new_node = state_.join_condi_[i]->ExprCopy();
    new_node->InitExprAtPhysicalPlan();
    jtc->join_condi_.push_back(new_node);
  }
  jtc->expr_eval_cnxt_.schema[0] = state_.input_schema_left_;
  jtc->expr_eval_cnxt_.schema[1] = state_.input_schema_right_;
  return jtc;
}

inline void PhysicalHashJoinProbe::IsMatch(
    void* l_tuple_addr, void* r_tuple_addr, void* return_addr,
    vector<unsigned>& l_join_index, vector<unsigned>& r_join_index,
    Schema* l_schema, Schema* r_schema, ExprFuncTwoTuples func) {
  bool key_exit = true;
  for (unsigned i = 0; i < r_join_index.size(); ++i) {
    void* key_in_input =
        r_schema->getColumnAddess(r_join_index[i], r_tuple_addr);
    void* key_in_hashtable =
        l_schema->getColumnAddess(l_join_index[i], l_tuple_addr);
    if (!r_schema->getcolumn(r_join_index[i])
             .operate->equal(key_in_input, key_in_hashtable)) {
      key_exit = false;
      break;
    }
  }
  *(bool*)return_addr = key_exit;
}

inline void PhysicalHashJoinProbe::IsMatchCodegen(
    void* l_tuple_addr, void* r_tuple_addr, void* return_addr,
    vector<unsigned>& l_join_index, vector<unsigned>& r_join_index,
    Schema* l_schema, Schema* r_schema, ExprFuncTwoTuples func) {
  func(l_tuple_addr, r_tuple_addr, return_addr);
}

inline bool PhysicalHashJoinProbe::JoinCondiProcess(
    void* tuple_left, void* tuple_right, JoinThreadContext* const hjtc) {
  hjtc->expr_eval_cnxt_.tuple[0] = tuple_left;
  hjtc->expr_eval_cnxt_.tuple[1] = tuple_right;
  bool pass = false;
  for (int i = 0; i < hjtc->join_condi_.size(); ++i) {
    pass = *(bool*)(hjtc->join_condi_[i]->ExprEvaluate(hjtc->expr_eval_cnxt_));
    if (pass == false) {
      return false;
    }
  }
  return true;
}

PhysicalHashJoinProbe::JoinThreadContext::~JoinThreadContext() {
  DELETE_PTR(l_block_for_asking_);
  DELETE_PTR(l_block_stream_iterator_);
  DELETE_PTR(r_block_for_asking_);
  DELETE_PTR(r_block_stream_iterator_);
  for (int i = 0; i < join_condi_.size(); ++i) {
    DELETE_PTR(join_condi_[i]);
  }
  join_condi_.clear();
}
}
}  // namespace claims
