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
 * /Claims/scheduler/backfill_scheduler.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "backfill_scheduler.h"

#include <stdlib.h>
namespace claims {
namespace scheduler {

BackfillScheduler::BackfillScheduler() : dag_root_(NULL) {}
BackfillScheduler::BackfillScheduler(PipelineJob* const dag_root,
                                     StmtExecStatus* const stmt_exec_status)
    : dag_root_(dag_root), stmt_exec_status_(stmt_exec_status) {}

BackfillScheduler::~BackfillScheduler() {}

RetCode BackfillScheduler::ScheduleJob() {
  RetCode ret = rSuccess;
  ret = ComputeJobRank();
  dag_root_->PrintJob();
  ret = GetReadyJobs(ready_jobs_);
  dag_root_->set_child(NULL);
  PipelineJob* pjob = NULL;
  while (!ready_jobs_.empty()) {
    PrintReadyJobs();
    // fetch the first high rank job
    pjob = *ready_jobs_.begin();
    ready_jobs_.erase(ready_jobs_.begin());
    // execute the job
    pjob->ExecuteJob(stmt_exec_status_);
    // once complete a job, reduce the underling waiting parents and check
    // whether it's ready
    if (NULL != pjob->get_child()) {
      pjob->get_child()->ReduceWaitingParents();
      if (pjob->get_child()->IsReadyJob()) {
        ready_jobs_.insert(pjob->get_child());
      }
    }
  }

  return ret;
}

RetCode BackfillScheduler::ComputeJobRank() {
  RetCode ret = rSuccess;
  dag_root_->ComputeJobRank(0);
  return ret;
}

RetCode BackfillScheduler::GetReadyJobs(set<PipelineJob*>& ready_jobs) {
  RetCode ret = rSuccess;
  dag_root_->GetReadyJobs(ready_jobs);
  return ret;
}

void BackfillScheduler::PrintReadyJobs() {
  cout << "Total " << ready_jobs_.size() << " ready jobs: " << endl;
  for (auto it = ready_jobs_.begin(); it != ready_jobs_.end(); ++it) {
    cout << "( job_id= " << (*it)->get_job_id()
         << " , rank= " << (*it)->get_rank() << " ) " << endl;
  }
  cout << endl;
}
}
}  // namespace claims
