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
 * /Claims/physical_operator/physical_projection_scan.cpp
 *
 *  Created on: Nov.14, 2013
 *      Author: wangli, Hanzhang
 *		   Email: wangli1426@gmail.com
 *
 * Description: Implementation of Scan operator in physical layer.
 *
 */

#include "../physical_operator/physical_projection_scan.h"

#include <memory.h>
#include <malloc.h>
#include <glog/logging.h>
#include <sys/mman.h>
#include <errno.h>
#include <limits.h>
#include <stack>

#include "../common/rename.h"
#include "../storage/BlockManager.h"
#include "../Config.h"
#include "../utility/warmup.h"
#include "../storage/ChunkStorage.h"
#include "../Executor/expander_tracker.h"
#include "../storage/PartitionStorage.h"
using ginkgo::common::rNoPartitionIdScan;
using ginkgo::common::rSuccess;
using ginkgo::common::rCodegenFailed;
using ginkgo::txn::GetGlobalPartId;
namespace ginkgo {
namespace physical_operator {
PhysicalProjectionScan::PhysicalProjectionScan(State state)
    : state_(state), partition_reader_iterator_(NULL), perf_info_(NULL) {
  set_phy_oper_type(kPhysicalScan);
  InitExpandedStatus();
}

PhysicalProjectionScan::PhysicalProjectionScan()
    : partition_reader_iterator_(NULL), perf_info_(NULL) {
  set_phy_oper_type(kPhysicalScan);
  InitExpandedStatus();
}

PhysicalProjectionScan::~PhysicalProjectionScan() {
  if (NULL != state_.schema_) {
    delete state_.schema_;
    state_.schema_ = NULL;
  }
  //  if (NULL != perf_info_) {
  //    delete perf_info_;
  //    perf_info_ = NULL;
  //  }
}

PhysicalProjectionScan::State::State(ProjectionID projection_id, Schema* schema,
                                     unsigned block_size, float sample_rate)
    : schema_(schema),
      projection_id_(projection_id),
      block_size_(block_size),
      sample_rate_(sample_rate) {}

/**
 * Initialize the operator to get the initial position. Scan is the start point
 * of stage, get instance of ExpanderTracker to add this point. Different policy
 * decide if it generates a buffer.
 */

bool PhysicalProjectionScan::Open(SegmentExecStatus* const exec_status,
                                  const PartitionOffset& kPartitionOffset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();

  if (TryEntryIntoSerializedSection()) {
    /* this is the first expanded thread*/
    PartitionStorage* partition_handle_ = NULL;
    if (NULL ==
        (partition_handle_ = BlockManager::getInstance()->GetPartitionHandle(
             PartitionID(state_.projection_id_, kPartitionOffset)))) {
      LOG(ERROR) << PartitionID(state_.projection_id_, kPartitionOffset)
                        .getName()
                        .c_str() << CStrError(rNoPartitionIdScan) << std::endl;
      SetReturnStatus(false);
    } else {
      auto table_id = state_.projection_id_.table_id;
      auto proj_id = state_.projection_id_.projection_off;
      auto part_id = kPartitionOffset;
      auto global_part_id = GetGlobalPartId(table_id, proj_id, part_id);
      auto cp = state_.query_.scan_cp_list_[global_part_id];
      //      cout << "table:" << table_id << ",proj:" << proj_id
      //           << ",part_id:" << part_id << ",cp:" << cp << endl;
      partition_reader_iterator_ = partition_handle_->CreateTxnReaderIterator(
          cp, state_.query_.scan_snapshot_[global_part_id]);
      cout << "version:" << state_.query_.ts_ << ",part:" << global_part_id
           << ",checkpoint :"
           << "block:" << cp / BLOCK_SIZE << "," << cp % BLOCK_SIZE << endl;
      for (auto& part : state_.query_.scan_snapshot_[global_part_id])
        cout << "[<" << part.first / BLOCK_SIZE << ","
             << part.first % BLOCK_SIZE << ">," << part.second << "]";
      cout << endl;
      //  partition_reader_iterator_ =
      //     partition_handle_->CreateAtomicReaderIterator();
      SetReturnStatus(true);
    }

#ifdef AVOID_CONTENTION_IN_SCAN
    unsigned long long start = curtick();

    ChunkReaderIterator* chunk_reader_it;
    ChunkReaderIterator::block_accessor* ba;
    while (chunk_reader_it = partition_reader_iterator_->NextChunk()) {
      while (chunk_reader_it->GetNextBlockAccessor(ba)) {
        ba->GetBlockSize();
        input_dataset_.input_data_blocks_.push_back(ba);
      }
    }
#endif
    ExpanderTracker::getInstance()->addNewStageEndpoint(
        pthread_self(), LocalStageEndPoint(stage_src, "Scan", 0));
    perf_info_ =
        ExpanderTracker::getInstance()->getPerformanceInfo(pthread_self());
    perf_info_->initialize();
  }
  BarrierArrive();
  return GetReturnStatus();
}

/**
 * There are two method of strategy to scan data.
 * 1) make a buffer(input_data). wait for quantitative block and return it.
 * because destorySelfContext() is not work, we don't use this method(code has
 * commented).
 * 2) get a block and return it immediately.
 */

// TODO(Hanzhang): According to AVOID_CONTENTION_IN_SCAN, we choose the
// strategy. We need finish case(1).
bool PhysicalProjectionScan::Next(SegmentExecStatus* const exec_status,
                                  BlockStreamBase* block) {
  RETURN_IF_CANCELLED(exec_status);

  unsigned long long total_start = curtick();
  if (!block->isIsReference()) {
    block->setIsReference(false);
  }
#ifdef AVOID_CONTENTION_IN_SCAN
  ScanThreadContext* stc = reinterpret_cast<ScanThreadContext*>(GetContext());
  if (NULL == stc) {
    stc = new ScanThreadContext();
    InitContext(stc);
  }
  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    input_dataset_.AtomicPut(stc->assigned_data_);
    delete stc;
    destorySelfContext();
    //    kPerfInfo->report_instance_performance_in_millibytes();
    return false;
  }

  if (!stc->assigned_data_.empty()) {
    ChunkReaderIterator::block_accessor* ba = stc->assigned_data_.front();
    stc->assigned_data_.pop_front();

    ba->GetBlock(block);

    // whether delete InMemeryBlockAccessor::target_block_start_address
    // is depend on whether use copy in ba->getBlock(block);
    delete ba;
    kPerfInfo->processed_one_block();
    return true;
  } else {
    if (input_dataset_.AtomicGet(stc->assigned_data_, Config::scan_batch)) {
      // case(1)
      return Next(block);
    } else {
      delete stc;
      destorySelfContext();
      return false;
    }
  }

#else

  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
          pthread_self())) {
    return false;
  }
  //  perf_info_->processed_one_block();
  // case(2)
  RETURN_IF_CANCELLED(exec_status);
  return partition_reader_iterator_->NextBlock(block);

#endif
}

bool PhysicalProjectionScan::Close(SegmentExecStatus* const exec_status) {
  if (NULL != partition_reader_iterator_) {
    delete partition_reader_iterator_;
    partition_reader_iterator_ = NULL;
  }
  DestoryAllContext();

  /* reset the expanded status in that open and next will be re-invoked.*/
  InitExpandedStatus();
  return true;
}

void PhysicalProjectionScan::Print() {
  printf("Scan (ID=%d)\n", state_.projection_id_.table_id);
}

bool PhysicalProjectionScan::PassSample() const {
  if ((rand() / (float)RAND_MAX) < state_.sample_rate_) return true;
  return false;
}
RetCode PhysicalProjectionScan::GetAllSegments(stack<Segment*>* all_segments) {
  return rSuccess;
}
}  // namespace physical_operator
}  // namespace ginkgo
