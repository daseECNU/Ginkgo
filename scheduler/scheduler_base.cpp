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
 * /Claims/scheduler/scheduler_base.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "scheduler_base.h"

#include <glog/logging.h>
#include "../common/memory_handle.h"
#include "../node_manager/base_node.h"
namespace claims {
namespace scheduler {

SchedulerBase::~SchedulerBase() {
  DELETE_PTR(dag_root_);
  caf::scoped_actor self;
  self->send(scheduler_actor_, ExitAtom::value);
}

SchedulerBase::SchedulerBase(PipelineJob* const dag_root,
                             StmtExecStatus* stmt_exec_status)
    : dag_root_(dag_root), stmt_exec_status_(stmt_exec_status) {}

RetCode SchedulerBase::GetReadyJobs(set<PipelineJob*>& ready_jobs) {
  RetCode ret = rSuccess;
  dag_root_->GetReadyJobs(ready_jobs);
  return ret;
}

void SchedulerBase::PrintReadyJobs() {
  cout << "Total " << ready_jobs_.size() << " ready jobs: " << endl;
  for (auto it = ready_jobs_.begin(); it != ready_jobs_.end(); ++it) {
    cout << "( job_id= " << (*it)->get_job_id()
         << " , rank= " << (*it)->get_rank() << " ) " << endl;
  }
  cout << endl;
}
RetCode SchedulerBase::Schedule() {
  RetCode ret = rSuccess;
  ret = ComputeJobRank();
  dag_root_->PrintJob();
  ret = GetReadyJobs(ready_jobs_);
  dag_root_->set_child(NULL);
  CreateActor();
  return ret;
}
void SchedulerBase::ScheduleJob(caf::event_based_actor* self,
                                SchedulerBase* scheduler) {
  LOG(INFO) << "ScheduleBase starts up now!";
  self->become(

      [=](ExitAtom) { self->quit(); },
      caf::others >> [=]() {
                       LOG(WARNING) << "ScheduleBase receives unkown message";

                     });
}

RetCode SchedulerBase::ComputeJobRank() {
  RetCode ret = rSuccess;
  dag_root_->ComputeJobRank(0);
  return ret;
}
void SchedulerBase::CreateActor() {
  scheduler_actor_ = caf::spawn(ScheduleJob, this);
}

}  // namespace scheduler
}  // namespace claims
