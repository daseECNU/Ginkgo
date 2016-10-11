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
 * /Claims/Executor/job_expander_tracker.cpp
 *
 *  Created on: Oct 10, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "./job_expander_tracker.h"
#include <glog/logging.h>
#include "../node_manager/base_node.h"
#include "expander_tracker.h"
#include "map"

#include "../common/memory_handle.h"
#include "../Config.h"
namespace claims {
#define DECISION_SHRINK 0
#define DECISION_EXPAND 1
#define DECISION_KEEP 2

#define THRESHOLD 0.1
#define THRESHOLD_EMPTY (THRESHOLD)
#define THRESHOLD_FULL (1 - THRESHOLD)
#define Refine 0.05
ExpanderStatus::~ExpanderStatus() {}

void ExpanderStatus::AddEndpoint(LocalStageEndPoint new_end_point) {
  lock.acquire();
  if (new_end_point.type == stage_desc) {
    pending_endpoints.push(new_end_point);
  } else {
    LocalStageEndPoint top = pending_endpoints.top();
    pending_endpoints.pop();
    current_stage = LocalStage(new_end_point, top);
  }
  lock.release();
}
JobExpanderTracker::JobExpanderTracker()
    : thread_num_threshold_(Config::total_thread_num), cur_thread_num_(0) {
  job_expander_actor_ = caf::spawn(ScheduleResource, this);
}

JobExpanderTracker::~JobExpanderTracker() {
  caf::scoped_actor self;
  self->send(job_expander_actor_, ExitAtom::value);
}

void JobExpanderTracker::ScheduleResource(caf::event_based_actor* self,
                                          JobExpanderTracker* job_epd_tracker) {
  self->become(

      [=](SchRAtom, int cur) {
        if (cur >= job_epd_tracker->expander_id_to_status_.size()) {
          cur = 0;
        }
        job_epd_tracker->get_sch_lock().acquire();
        job_epd_tracker->PeriodSchedule(cur);
        job_epd_tracker->get_sch_lock().release();

        self->delayed_send(self,
                           std::chrono::milliseconds(
                               Config::expander_adaptivity_check_frequency),
                           SchRAtom::value, ++cur);
      },
      [=](ForceSchR, int thread_num) {
        job_epd_tracker->get_sch_lock().acquire();
        if (thread_num > 0) {
          job_epd_tracker->ForceExpand(thread_num);
        } else if (thread_num < 0) {
          job_epd_tracker->ForceShrink(-thread_num);
        }
        job_epd_tracker->get_sch_lock().release();
      },
      [=](ExitAtom) { self->quit(); },
      caf::others >> [=]() {
                       LOG(WARNING)
                           << "ScheduleResource receives unkown message";
                     });
  if (Config::enable_expander_adaptivity) {
    self->send(self, SchRAtom::value, 0);
  }
}

RetCode JobExpanderTracker::PeriodSchedule(int cur) {
  RetCode ret = rSuccess;
  map_lock_.acquire();
  if (expander_id_to_expander_.empty()) {
    map_lock_.release();
    return ret;
  }
  auto it = expander_id_to_status_.begin();
  for (int tmp = 0; tmp < cur; tmp++) {
    it++;
  }
  ExpanderID id = it->first;
  assert(!expander_id_to_expander_.empty());
  LOG(INFO) << "Instance throughput: "
            << it->second->perf_info.report_instance_performance_in_millibytes()
            << " Mbytes";
  const unsigned int current_degree_of_parallelism =
      expander_id_to_expander_[it->first]->GetDegreeOfParallelism();
  int decision =
      DecideSchedule(it->second->current_stage, current_degree_of_parallelism);
  LOG(INFO) << "^^^ stage  "
            << it->second->current_stage.dataflow_src_.end_point_name_.c_str()
            << " ---->   "
            << it->second->current_stage.dataflow_desc_.end_point_name_.c_str()
            << "  parallelism= " << current_degree_of_parallelism;
  map_lock_.release();
  lock_adapt_.acquire();
  if (expander_id_to_expander_.find(it->first) ==
      expander_id_to_expander_.end()) {
    LOG(WARNING) << "expander_id= " << it->first.first << " , "
                 << it->first.second
                 << " has been erased from expander_id_to_expander_, so "
                    "coundn't expand or shrink it!";
    lock_adapt_.release();
    return rFailure;
  }
  switch (decision) {
    case DECISION_EXPAND: {
      if (true == expander_id_to_expander_[it->first]->Expand()) {
        ++cur_thread_num_;
        LOG(INFO) << "=========Expanding======== "
                  << current_degree_of_parallelism << " --> "
                  << current_degree_of_parallelism + 1;
      } else {
        LOG(WARNING) << "=========Expanding======== Failed to expand!";
      }
      break;
    }
    case DECISION_SHRINK: {
      if (true == expander_id_to_expander_[it->first]->Shrink()) {
        --cur_thread_num_;
        LOG(INFO) << "=========Shrinking======== "
                  << current_degree_of_parallelism << " --> "
                  << current_degree_of_parallelism - 1;
      } else {
        LOG(WARNING) << "=========Shrinking======== Failed to shrink!";
      }
      break;
    }
    default: {
      LOG(INFO) << "=========KEEP========";
      break;
    }
  }
  lock_adapt_.release();
  return ret;
}

RetCode JobExpanderTracker::ForceExpand(int thread_num) {
  RetCode ret = rSuccess;
  for (int i = 0; i < thread_num;) {
    for (auto it = expander_id_to_expander_.begin();
         it != expander_id_to_expander_.end() && i < thread_num; ++it, ++i) {
      int tmp = 0;
      while (true) {
        tmp = it->second->Expand();
        if (false == tmp) {
          LOG(WARNING) << "job expander id= " << it->first.first << " , "
                       << it->first.second
                       << " Force expand thread failed, try again";
        } else if (-1 == tmp) {
          LOG(WARNING) << "job expander id= " << it->first.first << " , "
                       << it->first.second
                       << " Force expand thread failed, but isn't necessary";
          i = thread_num;
          break;
        } else {
          LOG(INFO) << "job expander id= " << it->first.first << " , "
                    << it->first.second << " Force Add one thread successfully";
          --cur_thread_num_;
          break;
        }
      }
      if (cur_thread_num_ >= thread_num_threshold_ || cur_thread_num_ < 1) {
        LOG(ERROR) << "job expander id= " << it->first.first << " , "
                   << it->first.second
                   << " the thread-num isn't consistent to remote info !!";
      }
    }
  }
  return ret;
}
// reverse iterate the expander_id_to_expander_ to reduce one thread for every
// expander
RetCode JobExpanderTracker::ForceShrink(int thread_num) {
  RetCode ret = rSuccess;
  for (int i = 0; i < thread_num;) {
    for (auto it = expander_id_to_expander_.rbegin();
         it != expander_id_to_expander_.rend() && i < thread_num; ++it) {
      int tmp = 0;
      while (true) {
        tmp = it->second->Shrink();
        if (true == tmp) {
          ++i;
          LOG(INFO) << "job expander id= " << it->first.first << " , "
                    << it->first.second
                    << " Force Shrink one thread successfully";
          ++cur_thread_num_;
          break;
        } else if (2 == tmp) {
          LOG(INFO) << "job expander id= " << it->first.first << " , "
                    << it->first.second
                    << " Force Shrink one thread failed, but ignore it";
          break;
        } else {
          LOG(WARNING) << "job expander id= " << it->first.first << " , "
                       << it->first.second
                       << " Force Shrink one thread failed, try again";
        }
        if (cur_thread_num_ >= thread_num_threshold_ || cur_thread_num_ < 1) {
          LOG(ERROR) << "job expander id= " << it->first.first << " , "
                     << it->first.second
                     << " the thread-num isn't consistent to remote info !!";
        }
      }
    }
  }
  return ret;
}
int JobExpanderTracker::DecideSchedule(LocalStage& current_stage,
                                       u_int16_t cur_thread_num) {
  /**
   * In the initial implementation, if all expanded threads are shrunk and the
   * condition for expanding will never be triggered due to the exhaust of input
   * data-flow, then the remaining work will never be done.
   *
   *  To avoid this problem, we should first check whether the dataflow is
   * exhausted. If so, we should guarantee that there is at least one expanded
   * threads to process the remaining data in buffer.
   */

  int ret;
  switch (current_stage.type_) {
    case LocalStage::incomplete: {
      ret = DECISION_KEEP;
      break;
    }
    case LocalStage::no_buffer: {
      ret = DECISION_KEEP;
      /**
       * Currently, for the stage without synchronization
       * all_merged_data_buffer_, the workload is not known and hence
       * maximum degree of parallelism is used.
       */
      if (cur_thread_num == Config::max_degree_of_parallelism) {
        ret = DECISION_KEEP;
      } else if (cur_thread_num < Config::max_degree_of_parallelism) {
        ret = DECISION_EXPAND;
      } else {
        ret = DECISION_SHRINK;
      }
      break;
    }
    case LocalStage::from_buffer: {
      ret = DECISION_KEEP;
      LOG(INFO)
          << "Buffer usage: "
          << current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage()
          << " =====>N/A ";
      const double current_usage =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      if (current_stage.dataflow_src_.monitorable_buffer_->inputComplete()) {
        if (cur_thread_num == 0) {
          ret = DECISION_EXPAND;
          break;
        } else {
          ret = DECISION_KEEP;
          break;
        }
      }
      if (current_usage > THRESHOLD_FULL || cur_thread_num == 0) {
        ret = DECISION_EXPAND;
        break;
      } else if (current_usage < THRESHOLD_EMPTY) {
        ret = DECISION_SHRINK;
        break;
      } else {
        ret = DECISION_KEEP;
        break;
      }
    }
    case LocalStage::to_buffer: {
      LOG(INFO)
          << "Buffer usage:  N/A=====> "
          << current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      const double current_usage =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      if (current_usage > THRESHOLD_FULL) {
        ret = DECISION_SHRINK;
      } else if (current_usage < THRESHOLD_EMPTY) {
        ret = DECISION_EXPAND;
      } else {
        ret = DECISION_KEEP;
      }
      break;
    }
    case LocalStage::buffer_to_buffer: {
      LOG(INFO)
          << "Buffer usage: "
          << current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage()
          << " =====> "
          << current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      const double bottom_usage =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      const double top_usage =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      /* guarantee that there is at least one expanded thread when the input is
       * complete so that the stage can be finished soon.*/
      if (current_stage.dataflow_src_.monitorable_buffer_->inputComplete()) {
        if (cur_thread_num == 0) {
          ret = DECISION_EXPAND;
          break;
        } else {
          ret = DECISION_KEEP;
          break;
        }
      }

      if (bottom_usage > THRESHOLD_FULL && top_usage < THRESHOLD_EMPTY) {
        ret = DECISION_EXPAND;
        break;
      }
      if (top_usage > THRESHOLD_FULL || bottom_usage < THRESHOLD_EMPTY) {
        ret = DECISION_SHRINK;
        break;
      }
      ret = DECISION_KEEP;
    }
  }

  if (ret == DECISION_EXPAND) {
    if (cur_thread_num >= Config::max_degree_of_parallelism ||
        cur_thread_num >= thread_num_threshold_) {
      ret = DECISION_KEEP;
    }
  } else if (ret == DECISION_SHRINK) {
    if (cur_thread_num < 1) {
      ret = DECISION_KEEP;
    }
  }
  return ret;
}

bool JobExpanderTracker::AddStageEndpoint(ExpanderID epd_id,
                                          LocalStageEndPoint endpoint) {
  map_lock_.acquire();
  if (expander_id_to_status_.find(epd_id) == expander_id_to_status_.end()) {
    LOG(ERROR) << "the status of expander= " << epd_id.first << " , "
               << epd_id.second << " doesn't exist";
    map_lock_.release();
    assert(false);
    return false;
  }
  expander_id_to_status_[epd_id]->AddEndpoint(endpoint);
  map_lock_.release();
  return true;
}
PerformanceInfo* const JobExpanderTracker::GetPerformance(ExpanderID epd_id) {
  map_lock_.acquire();
  if (expander_id_to_status_.find(epd_id) == expander_id_to_status_.end()) {
    LOG(ERROR) << "the perf of expander= " << epd_id.first << " , "
               << epd_id.second << " doesn't exist";
    map_lock_.release();
    assert(false);
    return false;
  }
  auto ret = &expander_id_to_status_[epd_id]->perf_info;
  map_lock_.release();
  return ret;
}
RetCode JobExpanderTracker::RegisterExpander(
    MonitorableBuffer* buffer, ExpandabilityShrinkability* expand_shrink,
    ExpanderID expander_id) {
  RetCode ret = rSuccess;
  map_lock_.acquire();
  expander_id_to_status_[expander_id] = new ExpanderStatus(expand_shrink);
  expander_id_to_status_[expander_id]->AddEndpoint(
      LocalStageEndPoint(stage_desc, "Expander", buffer));
  expander_id_to_expander_[expander_id] = expand_shrink;
  ++cur_thread_num_;
  map_lock_.release();
  return ret;
}
RetCode JobExpanderTracker::UnRegisterExpander(ExpanderID expander_id) {
  map_lock_.acquire();
  if (expander_id_to_expander_.find(expander_id) ==
      expander_id_to_expander_.end()) {
    LOG(ERROR) << "Unregister expander_id = " << expander_id.first << " , "
               << expander_id.second
               << " doesn't exist in expander_id_to_expander_";
    map_lock_.release();
    return rFailure;
  }
  if (expander_id_to_status_.find(expander_id) ==
      expander_id_to_status_.end()) {
    LOG(ERROR) << "Unregister expander_id = " << expander_id.first << " , "
               << expander_id.second
               << " doesn't exist in expander_id_to_status_ ";
    map_lock_.release();
    return rFailure;
  }
  auto es = expander_id_to_status_.find(expander_id)->second;
  expander_id_to_status_.erase(expander_id);
  DELETE_PTR(es);
  LOG(INFO) << "erased expander id:" << expander_id.first << " , "
            << expander_id.second << " from expander_id_to_status_"
            << std::endl;
  expander_id_to_expander_.erase(expander_id);
  --cur_thread_num_;
  map_lock_.release();
  return rSuccess;
}

}  // namespace claims
