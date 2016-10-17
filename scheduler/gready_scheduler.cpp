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
 * /Claims/scheduler/gready_scheduler.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "gready_scheduler.h"

#include <glog/logging.h>

#include "../node_manager/base_node.h"
#include "../scheduler/pipeline_job.h"
#include "caf/all.hpp"
#include "scheduler_base.h"
namespace claims {
namespace scheduler {

GreadyScheduler::GreadyScheduler(PipelineJob* const dag_root,
                                 StmtExecStatus* stmt_exec_status)
    : SchedulerBase(dag_root, stmt_exec_status) {}

GreadyScheduler::~GreadyScheduler() {
  // TODO Auto-generated destructor stub
}

void GreadyScheduler::ScheduleJob(caf::event_based_actor* self,
                                  GreadyScheduler* scheduler) {
  LOG(INFO) << "GreadyScheduler starts up now!";
  self->become(

      [=](SchPJobAtom) {
        while (!scheduler->ready_jobs_.empty()) {
          scheduler->PrintReadyJobs();
          // fetch the first high rank job
          PipelineJob* pjob = *scheduler->ready_jobs_.begin();
          scheduler->ready_jobs_.erase(scheduler->ready_jobs_.begin());
          pjob->set_job_status(PipelineJob::kPivot);
          pjob->set_scheduler(scheduler);
          LOG(INFO) << "query, job id = "
                    << scheduler->stmt_exec_status_->get_query_id() << " , "
                    << pjob->get_job_id() << " will execute!";
          // execute the job
          pjob->DirectExecuteJob(scheduler->stmt_exec_status_);
        }
      },
      [=](DoneJobAtom, PipelineJob* pjob) {
        // once complete a job, reduce the underling waiting parents and check
        // whether it's ready
        LOG(INFO) << "query, job id = "
                  << scheduler->stmt_exec_status_->get_query_id() << " , "
                  << pjob->get_job_id() << " have been Done!";
        if (NULL != pjob->get_child()) {
          pjob->get_child()->ReduceWaitingParents();
          if (pjob->get_child()->IsReadyJob()) {
            scheduler->ready_jobs_.insert(pjob->get_child());
          }
        }
        self->send(self, SchPJobAtom::value);

      },
      [=](ExitAtom) { self->quit(); },
      caf::others >> [=]() {
                       LOG(WARNING)
                           << "SerializedScheduler receives unkown message";
                     }

      );
  self->send(self, SchPJobAtom::value);
}

void GreadyScheduler::CreateActor() {
  scheduler_actor_ = caf::spawn(ScheduleJob, this);
}
}
}  // namespace claims
