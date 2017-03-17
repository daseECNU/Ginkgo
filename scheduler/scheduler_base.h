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
 * /Claims/scheduler/scheduler_base.h
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_SCHEDULER_BASE_H_
#define SCHEDULER_SCHEDULER_BASE_H_
#include <set>

#include "../common/error_define.h"
#include "../scheduler/pipeline_job.h"
#include "caf/all.hpp"
using std::set;
namespace claims {
using EpdJobAtom = caf::atom_constant<caf::atom("ExpandJob")>;
namespace scheduler {
using SchEJobAtom = caf::atom_constant<caf::atom("SchEJob")>;
using SchPJobAtom = caf::atom_constant<caf::atom("SchPJob")>;
using SkJobAtom = caf::atom_constant<caf::atom("ShrinkJob")>;
using ExceJobAtom = caf::atom_constant<caf::atom("ExecuteJob")>;
using DoneJobAtom = caf::atom_constant<caf::atom("DoneJob")>;

class SchedulerBase {
 public:
  SchedulerBase(PipelineJob* const dag_root, StmtExecStatus* exec_status);

  virtual ~SchedulerBase();
  virtual RetCode Schedule();
  static void ScheduleJob(caf::event_based_actor* self,
                          SchedulerBase* scheduler);

  actor& get_scheduler_actor() { return scheduler_actor_; }
  StmtExecStatus*& get_stmt_exec_status() { return stmt_exec_status_; }
  virtual void CreateActor();

 public:
  StmtExecStatus* stmt_exec_status_;
  multiset<PipelineJob*, PipelineJob::PipelineJobGT> ready_jobs_;
  vector<int> thread_num_, thread_rest_;

  virtual RetCode ComputeJobRank();
  virtual RetCode GetReadyJobs(multiset<PipelineJob*, PipelineJob::PipelineJobGT>& ready_jobs);
  virtual void PrintReadyJobs();

 protected:
  boost::unordered_map<u_int16_t, PipelineJob*> job_id_to_job_;
  PipelineJob* dag_root_;
  actor scheduler_actor_;
};
}
}  // namespace claims

#endif  //  SCHEDULER_SCHEDULER_BASE_H_
