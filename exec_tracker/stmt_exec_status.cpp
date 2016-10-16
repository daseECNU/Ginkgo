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
 * /Claims/exec_tracker/stmt_exec_status.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "./stmt_exec_status.h"

#include <boost/pool/pool.hpp>
#include <string>
#include <iostream>
#include <utility>

#include "../Environment.h"
#include "../node_manager/base_node.h"
#include "caf/all.hpp"

#include "caf/io/all.hpp"
using boost::chrono::seconds;
using caf::io::remote_actor;
using std::make_pair;
using std::string;
namespace claims {

StmtExecStatus::StmtExecStatus(string sql_stmt)
    : sql_stmt_(sql_stmt),
      query_result_(NULL),
      exec_info_("OK"),
      exec_status_(ExecStatus::kOk),
      segment_id_gen_(1) {}

StmtExecStatus::~StmtExecStatus() {
  // due to the query result should return, so shouldn't be deleted here
  // if (NULL != query_result_) delete query_result_;
  lock_.acquire();
  for (auto it = node_seg_id_to_seges_.begin();
       it != node_seg_id_to_seges_.end(); ++it) {
    delete it->second;
    it->second = NULL;
  }
  node_seg_id_to_seges_.clear();
  for (auto it = stage_id_to_sem_.begin(); it != stage_id_to_sem_.end(); ++it) {
    delete it->second;
  }
  stage_id_to_sem_.clear();
  lock_.release();
}
/// just mark exec_status be kCancelled
RetCode StmtExecStatus::CancelStmtExec(bool locked) {
  if (!locked) {
    lock_.acquire();
  }
  if (ExecStatus::kCancelled == exec_status_) {
    if (!locked) {
      lock_.release();
    }
    return rSuccess;
  }
  exec_status_ = kCancelled;
  LOG(INFO) << query_id_ << " query should be cancelled!";
  if (!locked) {
    lock_.release();
  }
  return rSuccess;
}
// check every segment status
bool StmtExecStatus::CouldBeDeleted(u_int64_t logic_time) {
  // exec_status_ is set kDone or kError when the stmt is over in
  // select_exec.cpp, and then it could be deleted
  lock_.acquire();
  if (!(exec_status_ == kDone || exec_status_ == kError)) {
    lock_.release();
    return false;
  }
  // then check every segment of this stmt, if one is kOk (e.t. not kCancel and
  // kDone), then shouldn't delete this stmt
  for (auto it = node_seg_id_to_seges_.begin();
       it != node_seg_id_to_seges_.end(); ++it) {
    if (it->second->get_exec_status() == SegmentExecStatus::ExecStatus::kOk &&
        !(it->second->HaveErrorCase(logic_time))) {
      lock_.release();
      return false;
    }
  }
  LOG(INFO) << query_id_
            << " query can be deleted and status= " << exec_status_;
  lock_.release();
  return true;
}
bool StmtExecStatus::HaveErrorCase(u_int64_t logic_time) {
  lock_.acquire();
  int error_count = 0;
  int count = 0;
  int max_lost = 0;
  for (auto it = node_seg_id_to_seges_.begin();
       it != node_seg_id_to_seges_.end(); ++it) {
    if (it->second->HaveErrorCase(logic_time)) {
      LOG(INFO) << "change status to kCancelled" << endl;
      it->second->set_exec_status(SegmentExecStatus::ExecStatus::kCancelled);
      error_count++;
    }
    // if segment has done, judging the Max time that is the difference between
    // segment finish time and current time is over 1000. Besides, if the ratio
    // of finished segments >= 50%, so it has to be deleted.
    if (it->second->get_exec_status() == kDone) {
      count++;
      if (max_lost < logic_time - it->second->logic_time_) {
        max_lost = logic_time - it->second->logic_time_;
      }
    }
    if (it->second->get_exec_status() == kOk) {
      if (count * 100 / node_seg_id_to_seges_.size() > 50) {
        if (max_lost > 1000) {
          LOG(ERROR)
              << "This segment in loop, Error.Need to send the sql again."
              << endl;
          lock_.release();
          return true;
        }
      }
    }
  }
  lock_.release();
  if (error_count > 0) {
    return true;
  } else {
    return false;
  }
}
RetCode StmtExecStatus::RegisterToTracker() {
  return Environment::getInstance()->get_stmt_exec_tracker()->RegisterStmtES(
      this);
}

RetCode StmtExecStatus::UnRegisterFromTracker() {
  return Environment::getInstance()->get_stmt_exec_tracker()->UnRegisterStmtES(
      query_id_);
}
void StmtExecStatus::AddSegExecStatus(SegmentExecStatus* seg_exec_status) {
  lock_.acquire();
  node_seg_id_to_seges_.insert(
      make_pair(seg_exec_status->get_node_segment_id(), seg_exec_status));
  lock_.release();
}
// if remote segment status is error, then cancel corresponding statement
// once the statement is cancelled, update the segment's status to be cancelled,
// and returning false for canceling remote segment
bool StmtExecStatus::UpdateSegExecStatus(
    NodeSegmentID node_segment_id, SegmentExecStatus::ExecStatus exec_status,
    string exec_info, u_int64_t logic_time) {
  lock_.acquire();
  if (SegmentExecStatus::ExecStatus::kError == exec_status) {
    CancelStmtExec(true);
  }
  auto it = node_seg_id_to_seges_.find(node_segment_id);
  if (it != node_seg_id_to_seges_.end()) {
    if (ExecStatus::kCancelled == exec_status_ ||
        ExecStatus::kError == exec_status_) {
      it->second->UpdateStatus(SegmentExecStatus::ExecStatus::kCancelled,
                               exec_info, logic_time);
      lock_.release();
      return false;
    } else {
      it->second->UpdateStatus(exec_status, exec_info, logic_time);
      if (SegmentExecStatus::ExecStatus::kDone == exec_status) {
        CheckJobIsDone(node_segment_id.second);
      }
      lock_.release();
      return true;
    }
  } else {
    LOG(ERROR) << "query id = < " << it->first.first << " , "
               << it->first.second
               << " >couldn't be found when updating segment execution status!";
    lock_.release();
    assert(false);
    return false;
  }
}

void StmtExecStatus::AddOneJob(u_int16_t job_id, u_int16_t part_num) {
  u_int16_t stage_id = 0;
  for (int i = 0; i < part_num; ++i) {
    // (job_id,task_id=0,part_num)
    stage_id = job_id * kMaxTaskIdNum * kMaxPartNum + i;
    stage_id_to_sem_.insert(make_pair(stage_id, new semaphore()));
  }
}

bool StmtExecStatus::CheckJobIsDone(u_int64_t node_stage_id) {
#ifdef SYN
  u_int16_t stage_id = node_stage_id / kMaxNodeNum;
  u_int16_t task_id = (stage_id / kMaxPartNum) % kMaxTaskIdNum;
  if (0 == task_id) {  // the top task of this pipeline job
    if (stage_id_to_sem_.end() == stage_id_to_sem_.find(stage_id)) {
      LOG(WARNING) << "%%% (job,task,partition)= " << stage_id
                   << " couldn't found!";
      return false;
    }
    stage_id_to_sem_[stage_id]->post();
    return true;
  }
  return false;
#else
  u_int16_t job_id =
      (node_stage_id / kMaxNodeNum / kMaxPartNum / kMaxTaskIdNum) %
      kMaxJobIdNum;
  u_int16_t task_id =
      (node_stage_id / kMaxNodeNum / kMaxPartNum) % kMaxTaskIdNum;
  if (0 == task_id) {  // the top task of this pipeline job
    map_lock_.acquire();
    auto it = job_id_to_job_.find(job_id);
    if (job_id_to_job_.end() == it) {
      map_lock_.release();
      return false;
    } else {
      bool rs = it->second->CheckTopTaskIsDone((node_stage_id / kMaxNodeNum) %
                                               kMaxPartNum);
      if (rs) {
        job_id_to_job_.erase(it);
      }
      map_lock_.release();
      return rs;
    }
  }
  return false;
#endif
}

void StmtExecStatus::RegisterOneJob(u_int16_t job_id, PipelineJob* const pjob) {
  job_id_to_job_.insert(make_pair(job_id, pjob));
}

void StmtExecStatus::JobWaitingDone(u_int16_t job_id, u_int16_t part_num = 1) {
  u_int16_t stage_id = 0;
  for (int i = 0; i < part_num; ++i) {
    // (job_id,task_id=0,part_num)
    stage_id = job_id * kMaxTaskIdNum * kMaxPartNum + i;
    stage_id_to_sem_[stage_id]->wait();
    LOG(INFO) << "%%% (job,task,partition)= " << stage_id << " waiting Done!";
  }
}

}  // namespace claims
