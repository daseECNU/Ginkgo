/*
 * Message.cpp
 *
 *  Created on: May 12, 2013
 *      Author: wangli
 */

#include "Message.h"

#include "../exec_tracker/segment_exec_status.h"
using claims::SegmentExecStatus;
// the top node of every stage-plan is ExchangeSender or Expander or
// ResultCollector
void PhysicalQueryPlan::RunStagePlan() {
  SegmentExecStatus* segment_exec_status = new SegmentExecStatus(
      make_pair(query_id_, segment_id_ * kMaxNodeNum + target_node_id_),
      coor_node_id_, is_pivot_);
  segment_exec_status->RegisterToTracker();
  segment_exec_status->UpdateStatus(
      SegmentExecStatus::ExecStatus::kOk,
      "physical plan reveived succeed and begin to open()", 0, true);
  bool ret = stage_plan_->Open(segment_exec_status, partition_offset_);
  if (ret) {
    segment_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kOk,
                                      "physical plan open() succeed", 0, true);
    while (stage_plan_->Next(segment_exec_status, 0)) {
    }

    segment_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kOk,
                                      "physical plan next() succeed", 0, true);
  } else {
    LOG(WARNING) << segment_exec_status->node_segment_id_.first << " , "
                 << segment_exec_status->node_segment_id_.second
                 << " open failed ";

    segment_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kError,
                                      "physical plan open() failed", 0, true);
  }

  ret = stage_plan_->Close(segment_exec_status);
  segment_exec_status->UpdateStatus(SegmentExecStatus::ExecStatus::kDone,
                                    "physical plan close() succeed", 0, true);
}
