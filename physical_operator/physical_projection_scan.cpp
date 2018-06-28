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
#include <vector>
#include <sstream>
#include <string>
#include "../common/rename.h"
#include "../storage/BlockManager.h"
#include "../Config.h"
#include "../utility/warmup.h"
#include "../storage/ChunkStorage.h"
#include "../Executor/expander_tracker.h"
#include "../storage/PartitionStorage.h"
#include "../loader/table_parquet_reader.h"
#include "../Environment.h"
#include "../catalog/catalog.h"

using claims::common::rNoPartitionIdScan;
using claims::common::rSuccess;
using claims::common::rCodegenFailed;
using claims::catalog::TableDescriptor;
using claims::loader::TableParquetReader;
using claims::loader::ParqMetaInfo;
using claims::catalog::Catalog;
using claims::catalog::TableDescriptor;
using claims::loader::ParquetColumnReader;
using claims::loader::ColumnReader;
namespace claims {
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
void PhysicalProjectionScan::initParqReader(unsigned kPartitionOffset) {
  TableDescriptor* table =
      Catalog::getInstance()->getTable(state_.projection_id_.table_id);
  int proj_offset = state_.projection_id_.projection_off;
  unsigned part_key_off = state_.part_key_off_;
  stringstream ss;
  ParqMetaInfo meta_info;
  ss << Config::data_dir << 'T' << state_.projection_id_.table_id << 'P'
     << part_key_off << 'N' << kPartitionOffset << ".parq";
  meta_info.meta_start_ = state_.meta_start_[kPartitionOffset];
  meta_info.meta_length_ = state_.meta_len_[kPartitionOffset];
  meta_info.file_length_ = state_.file_len_[kPartitionOffset];
  meta_info.file_name_ = ss.str();
  file_name_ = meta_info.file_name_;
  TableParquetReader* tbl_parq_reader = TableParquetReader::getInstance();
  tbl_parq_reader
      ->meta_info_[PartitionID(state_.projection_id_, kPartitionOffset)] =
      meta_info;

  vector<int> order = state_.scan_order_;
  // create column reader
  std::vector<column_type>& columns = state_.schema_->columns;
  readers_.resize(columns.size());
  for (int i = 0; i < columns.size(); ++i) {
    ParquetColumnReader* parq_reader = nullptr;
    int col_id = order[i];
    data_type type = columns[i].type;
    unsigned fix_length = columns[i].get_length();
    switch (columns[i].type) {
      case t_int:
      case t_boolean:
        parq_reader = new ColumnReader<int>(col_id, type, fix_length);
        break;
      case t_float:
        parq_reader = new ColumnReader<float>(col_id, type, fix_length);
        break;
      case t_double:
        parq_reader = new ColumnReader<double>(col_id, type, fix_length);
        break;
      case t_string:
        parq_reader = new ColumnReader<char*>(col_id, type, fix_length);
        break;
      case t_u_long:
        parq_reader = new ColumnReader<unsigned long>(col_id, type, fix_length);
        break;
      case t_date:
        parq_reader = new ColumnReader<date>(col_id, type, fix_length);
        break;
      case t_time:
        parq_reader = new ColumnReader<time_duration>(col_id, type, fix_length);
        break;
      case t_datetime:
        parq_reader = new ColumnReader<ptime>(col_id, type, fix_length);
        break;
      case t_decimal:
        parq_reader = new ColumnReader<Decimal>(col_id, type, fix_length);
        break;
      case t_smallInt:
        parq_reader = new ColumnReader<short>(col_id, type, fix_length);
        break;
      case t_u_smallInt:
        parq_reader =
            new ColumnReader<unsigned short>(col_id, type, fix_length);
        break;
    }
    readers_[i] = parq_reader;
  }
  tbl_parq_reader->column_readers_[meta_info.file_name_] = readers_;
  tbl_parq_reader->file_cur_[meta_info.file_name_] = 0;
  tbl_parq_reader->file_total_[meta_info.file_name_] = state_.file_num_;
}
bool PhysicalProjectionScan::Open(SegmentExecStatus* const exec_status,
                                  const PartitionOffset& kPartitionOffset) {
  RETURN_IF_CANCELLED(exec_status);

  RegisterExpandedThreadToAllBarriers();

  if (TryEntryIntoSerializedSection()) {
    /* this is the first expanded thread*/
    if (Config::enable_parquet == 1) {
      initParqReader(kPartitionOffset);
    }
    PartitionStorage* partition_handle_ = NULL;
    if (NULL ==
        (partition_handle_ = BlockManager::getInstance()->GetPartitionHandle(
             PartitionID(state_.projection_id_, kPartitionOffset)))) {
      LOG(ERROR) << PartitionID(state_.projection_id_, kPartitionOffset)
                        .getName()
                        .c_str() << CStrError(rNoPartitionIdScan) << std::endl;
      SetReturnStatus(false);
    } else {
      partition_reader_iterator_ =
          partition_handle_->CreateAtomicReaderIterator();
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
  if (partition_reader_iterator_ == NULL)
	  return NULL;
  return partition_reader_iterator_->NextBlock(block);

#endif
}

bool PhysicalProjectionScan::Close(SegmentExecStatus* const exec_status) {
  if (NULL != partition_reader_iterator_) {
    delete partition_reader_iterator_;
    partition_reader_iterator_ = NULL;
  }
  if (Config::enable_parquet == 1) {
    for (auto it : readers_) delete it;
    TableParquetReader::getInstance()->column_readers_[file_name_].clear();
    TableParquetReader::getInstance()->has_data_[file_name_] = false;
    TableParquetReader::getInstance()->metadata_.erase(file_name_);
    if (TableParquetReader::getInstance()->pools_[file_name_] != NULL)
    	TableParquetReader::getInstance()->pools_[file_name_]->purge_memory();
  }
  DestoryAllContext();

  /* reset the expanded status in that open and next will be re-invoked.*/
  InitExpandedStatus();
  return true;
}

void PhysicalProjectionScan::Print() {
  printf("Scan (Proj id=%d)(ID=%d)\n", state_.projection_id_.projection_off,
         state_.projection_id_.table_id);
}

bool PhysicalProjectionScan::PassSample() const {
  if ((rand() / (float)RAND_MAX) < state_.sample_rate_) return true;
  return false;
}
RetCode PhysicalProjectionScan::GetAllSegments(stack<Segment*>* all_segments) {
  return rSuccess;
}
}  // namespace physical_operator
}  // namespace claims
