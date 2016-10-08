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
 * /Claims/scheduler/pipeline_job.h
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_PIPELINE_JOB_H_
#define SCHEDULER_PIPELINE_JOB_H_
#include "../scheduler/pipeline_job.h"

#include <stdint.h>
#include <set>
#include <utility>
#include <vector>

#include "./stage_task.h"
using std::pair;
using std::set;
using std::vector;

namespace claims {
namespace scheduler {
class PipelineJob {
 public:
  PipelineJob();
  PipelineJob(vector<StageTask*> stage_task, vector<PipelineJob*> parents,
              uint16_t job_id);
  virtual ~PipelineJob();
  void PrintJob();
  PipelineJob* const get_child() const { return child_; }

  void set_child(PipelineJob* const child);

  uint16_t get_job_id() const { return job_id_; }

  void set_job_id(uint16_t job_id) { job_id_ = job_id; }

  const vector<PipelineJob*>& get_parents() const { return parents_; }

  void set_parents(const vector<PipelineJob*>& parents) { parents_ = parents; }

  const vector<StageTask*>& get_stage_tasks() const { return stage_tasks_; }

  void set_stage_tasks(const vector<StageTask*>& stage_tasks) {
    stage_tasks_ = stage_tasks;
  }
  bool operator<(PipelineJob* const a) const { return rank_ > a->rank_; }
  RetCode ComputeJobRank(double upper_rank = 0);
  RetCode GetReadyJobs(set<PipelineJob*>& ready_jobs);
  RetCode ExecuteJob(StmtExecStatus* const stmt_exec_status);
  bool IsReadyJob();
  double get_rank() const { return rank_; }

  void set_rank(double rank) { rank_ = rank; }

  int get_waiting_parents() const { return waiting_parents_; }

  void set_waiting_parents(int waiting_parents) {
    waiting_parents_ = waiting_parents;
  }
  void ReduceWaitingParents() { --waiting_parents_; }

 private:
  vector<StageTask*> stage_tasks_;
  vector<PipelineJob*> parents_;
  PipelineJob* child_;
  uint16_t job_id_;
  int waiting_parents_;
  double rank_;
};
}
}  // namespace claims

#endif  //  SCHEDULER_PIPELINE_JOB_H_
