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
 * /CLAIMS/physical_operator/physical_aggregation.cpp
 *
 *  Created on: Sep 9, 2013
 *      Author: casa cswang
 *       Email: cs_wang@infosys.com
 *
 * Description: Aggregation physical operator, implement interface of Open(),
 *Next(), Close().
 *  multiply threads to process data blocks in one Node by different node type.
 *  this file is about the class BlockStreamAggregationIterator implementation.
 *
 */

#include "../physical_operator/physical_aggregation.h"
#include <glog/logging.h>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <functional>
#include <sstream>

#include "../common/expression/expr_node.h"
#include "../common/expression/expr_column.h"
#include "../common/expression/data_type_oper.h"
#include "../common/expression/expr_unary.h"
#include "../common/memory_handle.h"
#include "../common/Schema/Schema.h"
#include "../Debug.h"
#include "../utility/rdtsc.h"
#include "../Executor/expander_tracker.h"
#include "../utility/lock_guard.h"

using claims::common::DataTypeOper;
using claims::common::DataTypeOperFunc;
using claims::common::ExprEvalCnxt;
using claims::common::ExprNode;
using claims::common::ExprUnary;
using claims::common::OperType;
using claims::utility::LockGuard;
using std::vector;

namespace claims {
namespace physical_operator {

PhysicalAggregation::PhysicalAggregation(State state)
    : PhysicalOperator(4, 3),
      state_(state),
      hashtable_(NULL),
      hash_(NULL),
      bucket_cur_(0),
      set_ptr_size_(0) {
  set_phy_oper_type(kPhysicalAggregation);
  InitExpandedStatus();
  assert(state_.hash_schema_);
}

PhysicalAggregation::PhysicalAggregation()
    : PhysicalOperator(4, 3), hashtable_(NULL), hash_(NULL), bucket_cur_(0),
      set_ptr_size_(0) {
  set_phy_oper_type(kPhysicalAggregation);
  InitExpandedStatus();
}

PhysicalAggregation::~PhysicalAggregation() {
  if (NULL != state_.input_schema_) {
    delete state_.input_schema_;
    state_.input_schema_ = NULL;
  }
  if (NULL != state_.hash_schema_) {
    delete state_.hash_schema_;
    state_.hash_schema_ = NULL;
  }
  if (NULL != state_.output_schema_) {
    delete state_.output_schema_;
    state_.output_schema_ = NULL;
  }
  if (NULL != state_.child_) {
    delete state_.child_;
    state_.child_ = NULL;
  }
  for (int i = 0; i < state_.group_by_attrs_.size(); ++i) {
    if (NULL != state_.group_by_attrs_[i]) {
      delete state_.group_by_attrs_[i];
      state_.group_by_attrs_[i] = NULL;
    }
  }
  state_.group_by_attrs_.clear();
  for (int i = 0; i < state_.aggregation_attrs_.size(); ++i) {
    if (NULL != state_.aggregation_attrs_[i]) {
      delete state_.aggregation_attrs_[i];
      state_.aggregation_attrs_[i] = NULL;
    }
  }
  state_.aggregation_attrs_.clear();
}

PhysicalAggregation::State::State(
    Schema *input, Schema *output, Schema *hash_schema,
    PhysicalOperatorBase *child, unsigned num_of_buckets, unsigned bucket_size,
    unsigned block_size, std::vector<unsigned> avg_index,
    AggNodeType agg_node_type, vector<ExprNode *> group_by_attrs,
    vector<ExprUnary *> aggregation_attrs, int count_column_id)
    : input_schema_(input),
      output_schema_(output),
      hash_schema_(hash_schema),
      child_(child),
      num_of_buckets_(num_of_buckets),
      bucket_size_(bucket_size),
      block_size_(block_size),
      avg_index_(avg_index),
      agg_node_type_(agg_node_type),
      group_by_attrs_(group_by_attrs),
      aggregation_attrs_(aggregation_attrs),
      count_column_id_(count_column_id) {}

/**
 * while one thread starts Open(), the thread will be registered to all
 * barriers
 * to synchronize other threads.
 * Open() aggregate tuples from child's block in private hashtable by several
 * threads.
 * One block of data get from child operator each time, then loop to get every
 * tuple,
 * firstly check it whether in this private hash table.
 * operate the prepared aggregation function to update new tuple into private
 * hash table if the tuple key exists.
 * otherwise, allocate new bucket and assign every value of column in the
 * tuple
 * to the new bucket as the first tuple value in the new bucket.
 * after all block from child be processed. merge private hash table into
 * shared
 * hash table thread by thread synchronized by the hash table lock.
 */
bool PhysicalAggregation::Open(SegmentExecStatus *const exec_status,
                               const PartitionOffset &partition_offset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();
  // copy expression and initialize them
  vector<ExprNode *> group_by_attrs;
  vector<ExprUnary *> agg_attrs;
  ExprNode *group_by_node = NULL;
  ExprUnary *agg_node = NULL;
  int group_by_size = state_.group_by_attrs_.size();
  int aggr_size = state_.aggregation_attrs_.size();
  unsigned tuple_size = state_.hash_schema_->getTupleMaxSize();

  for (int i = 0; i < state_.group_by_attrs_.size(); ++i) {
    group_by_node = state_.group_by_attrs_[i]->ExprCopy();
    group_by_node->InitExprAtPhysicalPlan();
    group_by_attrs.push_back(group_by_node);
  }
  for (int i = 0; i < state_.aggregation_attrs_.size(); ++i) {
    agg_node =
        reinterpret_cast<ExprUnary *>(state_.aggregation_attrs_[i]->ExprCopy());
    agg_node->InitExprAtPhysicalPlan();
    agg_attrs.push_back(agg_node);
  }

  if (TryEntryIntoSerializedSection(0)) {
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_desc, "Aggregation", 0));
  }
  BarrierArrive(0);

  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    UnregisterExpandedThreadToAllBarriers(1);
    return true;
  }
  RETURN_IF_CANCELLED(exec_status);

  state_.child_->Open(exec_status, partition_offset);
  ticks start = curtick();
  // only sum(), avg(),count() need create set.
  // i means the index of distinct aggregation in result tuple,
  // j means the offset in hashtable (common and private).
  if (TryEntryIntoSerializedSection(1)) {
    hash_ = PartitionFunctionFactory::createGeneralModuloFunction(
        state_.num_of_buckets_);
    for (int i = 0, j=0; i < agg_attrs.size(); ++i) {
      if (agg_attrs[i]->is_distinct_ == 1 &&
          (agg_attrs[i]->oper_type_ == OperType::oper_agg_sum
          || agg_attrs[i]->oper_type_ == OperType::oper_agg_count)) {
        column_off_.insert(make_pair(i, j));
        j++;
      }
    }
    // create common hashtable
    if (column_off_.size() > 0) {
      set_ptr_size_ = sizeof(int64_t *)*column_off_.size();
      hashtable_ = new BasicHashTable(state_.num_of_buckets_,
                                      state_.bucket_size_,
                                      tuple_size+set_ptr_size_);
    } else {
      hashtable_ = new BasicHashTable(state_.num_of_buckets_,
                                    state_.bucket_size_, tuple_size);
    }
  }

  start = curtick();
  /* A private hash table is allocated for each thread to buffer the local
   * results. All the private hash table should be merged
   * at the final phase to complete the aggregation. Aggregation using private
   * hash tables is called private aggregation. Although
   * consuming larger memory, private aggregation is more efficient than
   * shared
   * aggregation for scalar aggregation or aggregation
   * with small groups, as private aggregation avoids the contention to the
   * shared hash table.
   */
  BasicHashTable *private_hashtable;
  RETURN_IF_CANCELLED(exec_status);
  if (column_off_.size() == 0) {
    private_hashtable =
        new BasicHashTable(state_.num_of_buckets_, state_.bucket_size_,
                         tuple_size);
  } else {
    private_hashtable =
        new BasicHashTable(state_.num_of_buckets_,
                           state_.bucket_size_+set_ptr_size_,
                           tuple_size+set_ptr_size_);
  }

  start = curtick();
  BarrierArrive(1);
  void *cur = 0;
  unsigned bn;
  bool key_exist;
  void *group_by_expr_result;
  void *tuple_in_hashtable;
  void *key_in_input_tuple;
  void *key_in_hash_table;
  void *value_in_input_tuple;
  void *value_in_hash_table;
  void *new_tuple_in_hash_table;
  // put all group-by key into string and hash it
  ExprEvalCnxt eecnxt;
  eecnxt.schema[0] = state_.input_schema_;

  unsigned allocated_tuples_in_hashtable = 0;
  BasicHashTable::Iterator ht_it = hashtable_->CreateIterator();
  BasicHashTable::Iterator pht_it = private_hashtable->CreateIterator();

  int64_t one = 1;
  BlockStreamBase *block_for_asking =
      BlockStreamBase::createBlock(state_.input_schema_, state_.block_size_);
  BlockStreamBase::BlockStreamTraverseIterator *bsti = NULL;
  block_for_asking->setEmpty();

  start = curtick();
  // traverse every block from child

  RETURN_IF_CANCELLED(exec_status);
  while (state_.child_->Next(exec_status, block_for_asking)) {
    RETURN_IF_CANCELLED(exec_status);
    DELETE_PTR(bsti);
    bsti = block_for_asking->createIterator();
    bsti->reset();
    // traverse every tuple from block
    while (NULL != (cur = bsti->currentTuple())) {
      /* get the corresponding bucket index according to the first column in
       * group-by attributes.
       * Note that bn is always 0 for scalar aggregation.
       */
      bn = 0;
      // execute group by attributes and get partition key
      eecnxt.tuple[0] = cur;
      if (state_.group_by_attrs_.size() > 0) {
        group_by_expr_result = group_by_attrs[0]->ExprEvaluate(eecnxt);
        bn = state_.hash_schema_->getcolumn(0).operate->getPartitionValue(
            group_by_expr_result, state_.num_of_buckets_);
      }
      private_hashtable->placeIterator(pht_it, bn);
      key_exist = false;
      while (NULL != (tuple_in_hashtable = pht_it.readCurrent())) {
        /* set key_exist flag to true such that the the case for scalar
         * aggregation (i.e., aggregation without group-by attributes)
         * could be considered as passed the group by value verification.
         */
        key_exist = true;
        for (int i = 0; i < group_by_attrs.size(); ++i) {
          group_by_expr_result = group_by_attrs[i]->ExprEvaluate(eecnxt);
          key_in_hash_table =
              state_.hash_schema_->getColumnAddess(i, tuple_in_hashtable);
          if (!state_.hash_schema_->getcolumn(i)
                   .operate->equal(group_by_expr_result, key_in_hash_table)) {
            key_exist = false;
            break;
          }
        }
        if (key_exist) {
          // value_in_input_tuple by expression
          // update function
          for (int i = 0; i < agg_attrs.size(); ++i) {
            agg_attrs[i]->ExprEvaluate(
                eecnxt, state_.hash_schema_->getColumnAddess(
                            i + group_by_size, tuple_in_hashtable));
            if (column_off_.find(i) != column_off_.end()) {
              LockGuard<Lock> guard(dist_set_lock_);
              int offset = (column_off_.find(i)->second)*sizeof(int64_t *)
                                                         +tuple_size;
              void* target = state_.hash_schema_
                    ->getColumnAddess(0, tuple_in_hashtable)+offset;
              void* set_ptr = *reinterpret_cast<int64_t *>(target);
              void* value = agg_attrs[i]->arg0_->ExprEvaluate(eecnxt);
              int type = agg_attrs[i]->arg0_->actual_type_;
              InsertSetValue(set_ptr, value, type);
            }
          }
          bsti->increase_cur_();
          break;
        } else {
          pht_it.increase_cur_();
        }
      }
      if (key_exist) {
        continue;
      }
      eecnxt.tuple[0] = cur;
      new_tuple_in_hash_table = private_hashtable->allocate(bn);
      // set group-by's original value by expression
      for (int i = 0; i < group_by_attrs.size(); ++i) {
        key_in_input_tuple = group_by_attrs[i]->ExprEvaluate(eecnxt);
        key_in_hash_table =
            state_.hash_schema_->getColumnAddess(i, new_tuple_in_hash_table);
        state_.hash_schema_->getcolumn(i)
            .operate->assignment(key_in_input_tuple, key_in_hash_table);
      }
      // get value_in_input_tuple from expression
      for (int i = 0; i < agg_attrs.size(); ++i) {
        value_in_input_tuple = agg_attrs[i]->arg0_->ExprEvaluate(eecnxt);
        if (column_off_.find(i) != column_off_.end()) {
            LockGuard<Lock> guard(dist_set_lock_);
            // set is not created yet
            int offset = (column_off_.find(i)->second)*sizeof(int64_t *)
                                                            +tuple_size;
            void* target = state_.hash_schema_
                ->getColumnAddess(0, new_tuple_in_hash_table)+offset;
            int type = agg_attrs[i]->arg0_->actual_type_;
            void* ptr = NULL;
            CreateSetBytype(ptr, type);
            InsertSetValue(ptr, value_in_input_tuple, type);
            *reinterpret_cast<int64_t *>(target) = ptr;
        }
        value_in_hash_table = state_.hash_schema_->getColumnAddess(
            group_by_size + i, new_tuple_in_hash_table);
        state_.hash_schema_->getcolumn(group_by_size + i)
            .operate->assignment(value_in_input_tuple, value_in_hash_table);
      }
      bsti->increase_cur_();
    }
    block_for_asking->setEmpty();
  }

  // merge private_hash_table into hash_table
  for (int i = 0; i < state_.num_of_buckets_; i++) {
    RETURN_IF_CANCELLED(exec_status);

    if (!private_hashtable->placeIterator(pht_it, i)) {
      LOG(INFO) << "placeIterator false";
    }
    // traverse every tuple from block
    while (NULL != (cur = pht_it.readCurrent())) {
      /* get the corresponding bucket index according to the first column in
       * group-by attributes.
       * Note that bn is always 0 for scalar aggregation.
       */
      bn = 0;
      if (group_by_attrs.size() > 0) {
        bn = state_.hash_schema_->getcolumn(0).operate->getPartitionValue(
            state_.hash_schema_->getColumnAddess(0, cur),
            state_.num_of_buckets_);
      }
      // add a lock to guarantee operating the hash_table atomically
      hashtable_->lockBlock(bn);
      hashtable_->placeIterator(ht_it, bn);
      key_exist = false;
      while (NULL != (tuple_in_hashtable = ht_it.readCurrent())) {
        /* set key_exist flag to true such that the the case for scalar
         * aggregation (i.e., aggregation with no group-by attributes)
         * could be considered as passed the group by value verification.
         */
        key_exist = true;
        for (int i = 0; i < group_by_attrs.size(); ++i) {
          key_in_input_tuple = state_.hash_schema_->getColumnAddess(i, cur);
          key_in_hash_table =
              state_.hash_schema_->getColumnAddess(i, tuple_in_hashtable);
          if (!state_.hash_schema_->getcolumn(i)
                   .operate->equal(key_in_input_tuple, key_in_hash_table)) {
            key_exist = false;
            break;
          }
        }
        if (key_exist) {
          // hash table have the key (the value in group-by attribute)
          // global_aggregation update
          for (int i = 0; i < agg_attrs.size(); ++i) {
            agg_attrs[i]->ExprEvaluate(
                state_.hash_schema_->getColumnAddess(i + group_by_size, cur),
                state_.hash_schema_->getColumnAddess(i + group_by_size,
                                                     tuple_in_hashtable));
            if (column_off_.find(i) != column_off_.end()) {
              LockGuard<Lock> guard(dist_set_lock_);
              // traverse all set value in private hashtable
              int offset = (column_off_.find(i)->second)*sizeof(int64_t *)
                                                          +tuple_size;
              void* Dest = state_.hash_schema_
                  ->getColumnAddess(0, tuple_in_hashtable)+offset;
              void* From = state_.hash_schema_
                  ->getColumnAddess(0, cur)+offset;
              // merge private set into global set
              void* fromPtr = *reinterpret_cast<int64_t *>(From);
              void* destPtr = *reinterpret_cast<int64_t *>(Dest);
              int type = agg_attrs[i]->arg0_->actual_type_;
              InsertSetfromSet(destPtr, fromPtr, type);
              delete fromPtr;
              }
          }
          pht_it.increase_cur_();
          hashtable_->unlockBlock(bn);
          break;
        } else {
          ht_it.increase_cur_();
        }
      }
      if (key_exist) {
        continue;
      }
      // if the key doesn't exist, then set the initial value
      new_tuple_in_hash_table = hashtable_->allocate(bn);
      allocated_tuples_in_hashtable++;
      for (int i = 0; i < group_by_attrs.size(); ++i) {
        key_in_input_tuple = state_.hash_schema_->getColumnAddess(i, cur);
        key_in_hash_table =
            state_.hash_schema_->getColumnAddess(i, new_tuple_in_hash_table);
        state_.hash_schema_->getcolumn(i)
            .operate->assignment(key_in_input_tuple, key_in_hash_table);
      }
      for (int i = 0; i < agg_attrs.size(); ++i) {
        value_in_input_tuple =
            state_.hash_schema_->getColumnAddess(i + group_by_size, cur);
        value_in_hash_table = state_.hash_schema_->getColumnAddess(
            i + group_by_size, new_tuple_in_hash_table);
        state_.hash_schema_->getcolumn(i + group_by_size)
            .operate->assignment(value_in_input_tuple, value_in_hash_table);
        // traverse all set value in private hashtable
        if (column_off_.find(i) != column_off_.end()) {
          LockGuard<Lock> guard(dist_set_lock_);
          int offset = (column_off_.find(i)->second)*sizeof(int64_t *)
                                                          +tuple_size;
          void* Dest = state_.hash_schema_
              ->getColumnAddess(0, new_tuple_in_hash_table)+offset;
          void* From = state_.hash_schema_->getColumnAddess(0, cur)+offset;
          void* destPtr = NULL;
          void* fromPtr = *reinterpret_cast<int64_t *>(From);
          int type = agg_attrs[i]->arg0_->actual_type_;
          CreateSetBytype(destPtr, type);
          InsertSetfromSet(destPtr, fromPtr, type);
          *reinterpret_cast<int64_t *>(Dest) = destPtr;
          delete fromPtr;
        }
      }
      hashtable_->unlockBlock(bn);
      pht_it.increase_cur_();
    }
  }

  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    UnregisterExpandedThreadToAllBarriers(2);
    return true;
  }
  RETURN_IF_CANCELLED(exec_status);

  BarrierArrive(2);

  if (TryEntryIntoSerializedSection(2)) {
    it_ = hashtable_->CreateIterator();
    bucket_cur_ = 0;
    hashtable_->placeIterator(it_, bucket_cur_);
    SetReturnStatus(true);
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_src, "Aggregation  ", 0));
    perf_info_ =
        ExpanderTracker::getInstance()->getPerformanceInfo(pthread_self());
    perf_info_->initialize();
    // deal with set value
    if (column_off_.size() >0) {
      void *tuple_in_hashtable;
      while (it_.readCurrent() != 0 ||
          (hashtable_->placeIterator(it_, bucket_cur_)) != false) {
        while (NULL != (tuple_in_hashtable = it_.readCurrent())) {
          for (int i = 0; i < agg_attrs.size(); ++i) {
            if (column_off_.find(i) != column_off_.end()) {
              int offset = (column_off_.find(i)->second)*sizeof(int64_t *)
                                                              +tuple_size;
              void* fromPtr = state_.hash_schema_
                        ->getColumnAddess(0, tuple_in_hashtable)+offset;
              void* destPtr = state_.hash_schema_
                      ->getColumnAddess(group_by_size+i,
                                        tuple_in_hashtable);
              int type = agg_attrs[i]->arg0_->actual_type_;
              int offsets = i + group_by_size;
              ProcessDistinct(fromPtr, destPtr, agg_attrs[i],
                              type, offsets, tuple_in_hashtable);
              }
            }
            it_.increase_cur_();
          }
          bucket_cur_++;
        }
      }
      // reinitialize the iterator
      bucket_cur_ = 0;
      hashtable_->placeIterator(it_, bucket_cur_);
  }

  BarrierArrive(3);


  if (NULL != block_for_asking) {
    delete block_for_asking;
    block_for_asking = NULL;
  }
  if (NULL != private_hashtable) {
    delete private_hashtable;
    private_hashtable = NULL;
  }
  for (auto &i : agg_attrs) DELETE_PTR(i);
  agg_attrs.clear();
  for (auto &i : group_by_attrs) DELETE_PTR(i);
  group_by_attrs.clear();
  LOG(INFO) << "Agg open() finish" << endl;
  return GetReturnStatus();
}

/**
 * In the current implementation, the lock is used based on the entire
 * hash table, which will definitely reduce the degree of parallelism.
 * But it is for now, assuming that the aggregated results are small.
 */
bool PhysicalAggregation::Next(SegmentExecStatus *const exec_status,
                               BlockStreamBase *block) {
  RETURN_IF_CANCELLED(exec_status);
  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    UnregisterExpandedThreadToAllBarriers(3);
    LOG(INFO) << "<<<<<<<<<<<<<<<<<Aggregation next detected call back "
                 "signal!>>>>>>>>>>>>>>>>>" << std::endl;

    return false;
  }
  void *cur_in_ht;
  void *tuple;
  void *key_in_hash_tuple;
  void *key_in_output_tuple;
  hashtable_cur_lock_.acquire();
  while (it_.readCurrent() != 0 ||
         (hashtable_->placeIterator(it_, bucket_cur_)) != false) {
    while (NULL != (cur_in_ht = it_.readCurrent())) {
      if (NULL != (tuple = block->allocateTuple(
                       state_.output_schema_->getTupleMaxSize()))) {
        // copy the whole tuple, and update the corresponding column if there
        // is
        // avg()
        memcpy(tuple, cur_in_ht, state_.output_schema_->getTupleMaxSize());
        // update the sum=sum/count if there is avg()
        if (state_.avg_index_.size() > 0 &&
            (state_.agg_node_type_ == State::kHybridAggGlobal ||
             state_.agg_node_type_ == State::kNotHybridAgg)) {
          int id = 0;
          void *sum_value;
          int64_t count_value =
              *reinterpret_cast<int64_t *>(state_.hash_schema_->getColumnAddess(
                  state_.count_column_id_ + state_.group_by_attrs_.size(),
                  tuple));
          for (int i = 0; i < state_.avg_index_.size(); ++i) {
            id = state_.group_by_attrs_.size() + state_.avg_index_[i];
            sum_value = state_.hash_schema_->getColumnAddess(id, tuple);
            DataTypeOper::avg_divide_[state_.hash_schema_->columns[id].type](
                sum_value, count_value, sum_value);
            }
          }
        it_.increase_cur_();
      } else {
        hashtable_cur_lock_.release();
        perf_info_->processed_one_block();
        return true;
      }
    }
    bucket_cur_++;
  }
  hashtable_cur_lock_.release();
  if (block->Empty()) {
    return false;
  } else {
    perf_info_->processed_one_block();
    return true;
  }
}

bool PhysicalAggregation::Close(SegmentExecStatus *const exec_status) {
  InitExpandedStatus();
  if (NULL != hashtable_) {
    delete hashtable_;
    hashtable_ = NULL;
  }
  state_.child_->Close(exec_status);
  return true;
}
void PhysicalAggregation::Print() {
  cout << "Aggregation:  " << state_.num_of_buckets_ << " buckets in hash table"
       << std::endl;
  cout << "group by attributes:" << endl;
  for (int i = 0; i < state_.group_by_attrs_.size(); ++i) {
    cout << "    " << state_.group_by_attrs_[i]->alias_ << endl;
  }
  cout << "aggregation attributes:" << endl;
  for (int i = 0; i < state_.aggregation_attrs_.size(); ++i) {
    cout << "    " << state_.aggregation_attrs_[i]->alias_ << endl;
  }
  cout << "---------------" << std::endl;
  state_.child_->Print();
}
RetCode PhysicalAggregation::GetAllSegments(stack<Segment *> *all_segments) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_) {
    return state_.child_->GetAllSegments(all_segments);
  }
  return ret;
}
struct HashFunc_Date{
  std::size_t operator() (const date &d) const {
  return boost::hash_value(d.julian_day());
  }
};

struct HashFunc_TimeDura{
  std::size_t operator() (const time_duration &td) const {
    return boost::hash_value(td.total_nanoseconds());
  }
};

struct HashFunc_Ptime{
  std::size_t operator() (const ptime &p) const {
    return boost::hash_value(to_simple_string(p));
  }
};
struct HashFunc_Deci{
  std::size_t operator() (const Decimal &d) const {
    OperateDecimal opd;
    return opd.getPartitionValue(&d);
  }
};
void PhysicalAggregation::CreateSetBytype(void* &target,
                                          int const &data_type) {
  switch (data_type) {
    case t_int:
    case t_boolean:
      target = new boost::unordered_set<int>();
      break;
    case t_float:
      target = new boost::unordered_set<float>();
      break;
    case t_double:
      target = new boost::unordered_set<double>();
      break;
    case t_string:
      target = new boost::unordered_set<char*>();
      break;
    case t_u_long:
      target = new boost::unordered_set<unsigned long>();
      break;
    case t_date:
      target = new boost::unordered_set<date, HashFunc_Date>();
      break;
    case t_time:
      target = new boost::unordered_set<time_duration, HashFunc_TimeDura>();
      break;
    case t_datetime:
      target = new boost::unordered_set<ptime, HashFunc_Ptime>();
      break;
//    case t_decimal:
//      target = new boost::unordered_set<Decimal, HashFunc_Deci>();
//      break;
    case t_smallInt:
      target = new boost::unordered_set<short>();
      break;
    case t_u_smallInt:
      target = new boost::unordered_set<unsigned short>();
      break;
    default:
      break;
  }
}
void PhysicalAggregation::InsertSetValue(void* const &target,
                                         void* const &value,
                                         int const &data_type) {
  switch (data_type) {
    case t_int:
    case t_boolean:
      ((boost::unordered_set<int>*)(target))
        ->insert(*reinterpret_cast<int*>(value));
      break;
    case t_float:
      ((boost::unordered_set<float>*)(target))
        ->insert(*reinterpret_cast<float*>(value));
      break;
    case t_double:
      ((boost::unordered_set<double>*)(target))
        ->insert(*reinterpret_cast<double*>(value));
      break;
    case t_string:
      ((boost::unordered_set<char*>*)(target))
              ->insert(*reinterpret_cast<char*>(value));
      break;
    case t_u_long:
      ((boost::unordered_set<unsigned long>*)(target))
        ->insert(*reinterpret_cast<unsigned long*>(value));
      break;
    case t_date:
      ((boost::unordered_set<date, HashFunc_Date>*)(target))
              ->insert(*reinterpret_cast<date*>(value));
      break;
    case t_time:
      ((boost::unordered_set<time_duration, HashFunc_TimeDura>*)(target))
              ->insert(*reinterpret_cast<time_duration*>(value));
      break;
    case t_datetime:
      ((boost::unordered_set<ptime, HashFunc_Ptime>*)(target))
              ->insert(*reinterpret_cast<ptime*>(value));
      break;
    case t_smallInt:
      ((boost::unordered_set<short>*)(target))
              ->insert(*reinterpret_cast<short*>(value));
      break;
    case t_u_smallInt:
      ((boost::unordered_set<unsigned short>*)(target))
              ->insert(*reinterpret_cast<unsigned short*>(value));
      break;
//    case t_decimal:
//      ((boost::unordered_set<Decimal, HashFunc_Deci>*)(target))
//              ->insert(*reinterpret_cast<Decimal*>(value));
//      break;
    default:
      break;
  }
}
void PhysicalAggregation::InsertSetfromSet(void* const &target,
                                         void* const &from,
                                         int const &data_type) {
  switch (data_type) {
    case t_int:
    case t_boolean:
      ((boost::unordered_set<int>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<int>*>(from)->begin(),
                 reinterpret_cast<boost::unordered_set<int>*>(from)->end());
      break;
    case t_float:
      ((boost::unordered_set<float>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<float>*>(from)->begin(),
                 reinterpret_cast<boost::unordered_set<float>*>(from)->end());
      break;
    case t_double:
      ((boost::unordered_set<double>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<double>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<double>*>
                (from)->end());
      break;
    case t_string:
      ((boost::unordered_set<char*>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<char*>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<char*>*>
                (from)->end());
      break;
    case t_u_long:
      ((boost::unordered_set<unsigned long>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<unsigned long>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<unsigned long>*>
                (from)->end());
      break;
    case t_date:
      ((boost::unordered_set<date, HashFunc_Date>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<date, HashFunc_Date>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<date, HashFunc_Date>*>
                (from)->end());
      break;
    case t_time:
      ((boost::unordered_set<time_duration, HashFunc_TimeDura>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<time_duration,
                 HashFunc_TimeDura>*>(from)->begin(),
                 reinterpret_cast<boost::unordered_set<time_duration,
                 HashFunc_TimeDura>*>(from)->end());
      break;
    case t_datetime:
      ((boost::unordered_set<ptime, HashFunc_Ptime>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<ptime>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<ptime>*>
                (from)->end());
      break;
    case t_smallInt:
      ((boost::unordered_set<short>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<short>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<short>*>
                (from)->end());
      break;
    case t_u_smallInt:
      ((boost::unordered_set<unsigned short>*)(target))
        ->insert(reinterpret_cast<boost::unordered_set<unsigned short>*>
                (from)->begin(),
                 reinterpret_cast<boost::unordered_set<unsigned short>*>
                (from)->end());
      break;
//    case t_decimal:
//      ((boost::unordered_set<Decimal, HashFunc_Deci>*)(target))
//        ->insert(reinterpret_cast<boost::unordered_set<Decimal>*>
//                (from)->begin(),
//                 reinterpret_cast<boost::unordered_set<Decimal>*>
//                (from)->end());
//      break;
    default:
      break;
  }
}

void PhysicalAggregation::ProcessDistinct(void*& from,
                                          void*& destPtr,
                                          ExprUnary *& agg_attrs,
                                          int &data_type,
                                          int &offset,
                                          void*& tuple_in_hashtable) {
  int set_size = 0;
  cout <<"!!!!!!!!!!!!! " <<data_type <<endl;
  switch (data_type) {
      case t_int:
      case t_boolean:
      {
        boost::unordered_set<int>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
           int *sum = new int();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             int * a = new int(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_float:
      {
        boost::unordered_set<float>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
           float *sum = new float();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             float * a = new float(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_double:
      {
        boost::unordered_set<double>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
          double *sum = new double();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             double * a = new double(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_string:
      {
        boost::unordered_set<char*>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        }
        break;
      }
      case t_u_long:
      {
        boost::unordered_set<unsigned long>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
          unsigned long *sum = new unsigned long();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             unsigned long * a = new unsigned long(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_smallInt:
      {
        boost::unordered_set<short>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
          short *sum = new short();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             short * a = new short(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_u_smallInt:
      {
        boost::unordered_set<unsigned short>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        } else if (agg_attrs->oper_type_ == OperType::oper_agg_sum) {
          unsigned short *sum = new unsigned short();
           for (auto it = fromPtr->begin();
               it != fromPtr->end(); it++) {
             unsigned short * a = new unsigned short(*it);
             agg_attrs->ExprEvaluate(a, sum);
             delete a;
           }
           state_.hash_schema_->getcolumn(offset)
                       .operate->assignment(sum, destPtr);
           delete sum;
        }
        break;
      }
      case t_date:
      {
        boost::unordered_set<date, HashFunc_Date>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        }
        break;
      }
      case t_time:
      {
        boost::unordered_set<time_duration, HashFunc_TimeDura>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        }
        break;
      }
      case t_datetime:
      {
        boost::unordered_set<ptime, HashFunc_Ptime>* fromPtr
              = *reinterpret_cast<int64_t *>(from);
        set_size = fromPtr->size();
        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
          void* value = new int(set_size);
          state_.hash_schema_->getcolumn(offset)
                      .operate->assignment(value, destPtr);
          delete value;
        }
        break;
      }
//      case t_decimal:
//      {
//        boost::unordered_set<Decimal, HashFunc_Deci>* fromPtr
//              = *reinterpret_cast<int64_t *>(from);
//        set_size = fromPtr->size();
//        if (agg_attrs->oper_type_ == OperType::oper_agg_count) {
//          void* value = new int(set_size);
//          state_.hash_schema_->getcolumn(offset)
//                      .operate->assignment(value, destPtr);
//          delete value;
//        }
//        break;
//      }
      default:
        break;
    }
    if (state_.avg_index_.size() > 0) {
    // set avg count number equal set size.
    *reinterpret_cast<int64_t *>(state_.hash_schema_->getColumnAddess(
        state_.count_column_id_+ state_.group_by_attrs_.size(),
          tuple_in_hashtable)) = set_size;
  }
}

}  // namespace physical_operator
}  // namespace claims


