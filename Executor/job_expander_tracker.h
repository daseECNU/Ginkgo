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
 * /Claims/Executor/job_expander_tracker.h
 *
 *  Created on: Oct 10, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef EXECUTOR_JOB_EXPANDER_TRACKER_H_
#define EXECUTOR_JOB_EXPANDER_TRACKER_H_
#include <map>
#include <utility>
#include <atomic>
#include <string>
#include "caf/all.hpp"
#include <stack>

#include "../common/Block/MonitorableBuffer.h"
#include "../common/error_define.h"
#include "../common/ExpandedThreadTracker.h"
#include "../common/ids.h"
#include "../utility/ExpandabilityShrinkability.h"
#include "../utility/lock.h"

using caf::actor;
using std::make_pair;
using std::map;
using claims::common::rSuccess;
using claims::common::rFailure;
using std::atomic_bool;
using std::atomic_short;
using std::atomic_ushort;
namespace claims {
// maintain the expander belonging to the same JobExpanderTracker, and schedule
// resource for every job
using SchRAtom = caf::atom_constant<caf::atom("scheduleR")>;
using ForceSchR = caf::atom_constant<caf::atom("forceschR")>;

enum EndpoinType { stage_src, stage_desc };
/**
 * Local local_stage endpoint refers to the start or the end of a stage within a
 * segment.
 * It could be either exchange, state, or expander.
 */
struct LocalStageEndPoint {
  LocalStageEndPoint(EndpoinType tp, std::string name = "Not Given",
                     MonitorableBuffer* buffer_handle = 0)
      : type(tp), monitorable_buffer_(buffer_handle), end_point_name_(name) {}
  LocalStageEndPoint()
      : monitorable_buffer_(0), end_point_name_("Initial"), type(stage_src) {}
  LocalStageEndPoint(const LocalStageEndPoint& r) {
    this->type = r.type;
    this->monitorable_buffer_ = r.monitorable_buffer_;
    this->end_point_name_ = r.end_point_name_;
  }
  EndpoinType type;
  MonitorableBuffer* monitorable_buffer_;
  std::string end_point_name_;
};

// typedef std::pair<LocalStageEndPoint,LocalStageEndPoint> local_stage;

struct LocalStage {
  enum LocalStageType {
    from_buffer,
    buffer_to_buffer,
    to_buffer,
    no_buffer,
    incomplete
  };
  LocalStage() : type_(incomplete) {}
  LocalStage(const LocalStage& r) {
    this->type_ = r.type_;
    this->dataflow_src_ = r.dataflow_src_;
    this->dataflow_desc_ = r.dataflow_desc_;
  }
  //  operator=(const local_stage &r){
  //
  //  }
  LocalStage(LocalStageEndPoint start, LocalStageEndPoint end)
      : dataflow_src_(start), dataflow_desc_(end) {
    bool start_buffer = dataflow_src_.monitorable_buffer_ != 0;
    bool end_buffer = dataflow_desc_.monitorable_buffer_ != 0;
    if (start_buffer) {
      if (end_buffer) {
        type_ = buffer_to_buffer;
      } else {
        type_ = from_buffer;
      }
    } else {
      if (end_buffer) {
        type_ = to_buffer;
      } else {
        type_ = no_buffer;
      }
    }
  }
  LocalStageEndPoint dataflow_src_;
  LocalStageEndPoint dataflow_desc_;
  LocalStageType type_;
  std::string get_type_name(LocalStageType tp) const {
    switch (tp) {
      case from_buffer: {
        return std::string("from_buffer");
      }
      case buffer_to_buffer: {
        return std::string("buffer_to_buffer");
      }
      case to_buffer: {
        return std::string("to_buffer");
      }
      case no_buffer: {
        return std::string("no_buffer");
      }
      default: { return std::string("invalid type!"); }
    }
    //    return std::string();
  }
  void print() {
    if (type_ == incomplete) {
      printf("Incomplete!\n");
      return;
    }
    printf("%s----->%s, type: %s\n", dataflow_src_.end_point_name_.c_str(),
           dataflow_desc_.end_point_name_.c_str(),
           get_type_name(type_).c_str());
  }
};
struct ExpanderStatus {
  ExpanderStatus(ExpandabilityShrinkability* expand_shrink)
      : perf_info(expand_shrink) {}
  //    ExpanderStatus(){};
  ~ExpanderStatus();
  PerformanceInfo perf_info;
  LocalStage current_stage;
  std::stack<LocalStageEndPoint> pending_endpoints;
  void AddEndpoint(LocalStageEndPoint);
  Lock lock;
};
class JobExpanderTracker {
 public:
  JobExpanderTracker(bool is_pivot);
  virtual ~JobExpanderTracker();
  static void ScheduleResource(caf::event_based_actor* self,
                               JobExpanderTracker* job_epd_tracker);
  RetCode PeriodSchedule();
  RetCode ForceExpand(int thread_num);
  RetCode ForceShrink();

  void add_expander_id_to_expander(ExpanderID expander_id,
                                   ExpandabilityShrinkability* const expander) {
    expander_id_to_expander_.insert(make_pair(expander_id, expander));
  }
  actor& get_job_expander_actor() { return job_expander_actor_; }

  Lock& get_sch_lock() { return sch_lock_; }

  int DecideSchedule(LocalStage& current_stage,
                     u_int16_t current_degree_of_parallelism);
  bool AddStageEndpoint(ExpanderID epd_id, LocalStageEndPoint endpoint);
  PerformanceInfo* const GetPerformance(ExpanderID epd_id);

  RetCode RegisterExpander(MonitorableBuffer* buffer,
                           ExpandabilityShrinkability* expand_shrink,
                           ExpanderID expander_id);
  RetCode UnRegisterExpander(ExpanderID expander_id);
  bool IsEmpty() {
    bool ret = false;
    map_lock_.acquire();
    ret = expander_id_to_expander_.empty();
    map_lock_.release();
    return ret;
  }
  void set_is_pivot(const bool is_pivot);
  void AddOneCurThread();
  void DeleteOneCurThread();
  static atomic_ushort extra_cur_thread_num_, pivot_cur_thread_num_;

 private:
  atomic_bool is_pivot_;
  atomic_ushort thread_num_threshold_, cur_thread_num_;
  Lock sch_lock_, lock_adapt_, map_lock_, thread_num_lock_;
  u_int64_t job_id_;
  actor job_expander_actor_;
  // have order to schedule resource for different priority
  map<ExpanderID, ExpandabilityShrinkability*> expander_id_to_expander_;
  map<ExpanderID, ExpanderStatus*> expander_id_to_status_;
};

}  // namespace claims

#endif  //  EXECUTOR_JOB_EXPANDER_TRACKER_H_
