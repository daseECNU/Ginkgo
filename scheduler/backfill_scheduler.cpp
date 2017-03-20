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

#include "../Config.h"
#include "../exec_tracker/stmt_exec_tracker.h"
#include "../Environment.h"
#include "../scheduler/pipeline_job.h"
#include "scheduler_base.h"
namespace claims {
namespace scheduler {

BackfillScheduler::BackfillScheduler(PipelineJob* const dag_root,
                                     StmtExecStatus* const stmt_exec_status)
    : SchedulerBase(dag_root, stmt_exec_status) {}

BackfillScheduler::~BackfillScheduler() {}
// for scheduling well, so guarantee the thread info is updated in time
void BackfillScheduler::ScheduleJob(caf::event_based_actor* self,
                                    BackfillScheduler* scheduler) {
  LOG(INFO) << "BackfillScheduler starts up now!";
  scheduler->ComputeTaskNum();
  scheduler->InitThread();
  self->become(
      [=](SchPJobAtom) {
        scheduler->lock_.acquire();
        PipelineJob* pjob = scheduler->GetPivotJob();
        if (NULL != pjob) {
          // decide to shrink which jobs to release resource
          // naive method : shrink every extra jobs that is conflict with pjob

          for (auto it = scheduler->extra_jobs_.begin();
               it != scheduler->extra_jobs_.end(); ++it) {
            for (auto mit = pjob->node_task_num_.begin();
                 mit != pjob->node_task_num_.end(); ++mit) {
              if (0 != (*it)->node_allocated_thread_[mit->first]) {
                LOG(INFO) << "query, job id, node = "
                          << scheduler->stmt_exec_status_->get_query_id()
                          << " , " << (*it)->get_job_id() << " , " << mit->first
                          << " will be shrunk when active pivot job";
                scheduler->thread_rest_[mit->first] +=
                    (*it)->node_allocated_thread_[mit->first];
                (*it)->node_allocated_thread_[mit->first] = 0;
                self->send((*it)->get_job_actor(), SkJobAtom::value);
              }
            }
          }

          LOG(INFO) << "query ,job id, status = "
                    << scheduler->stmt_exec_status_->get_query_id() << " , "
                    << pjob->get_job_id() << " , " << pjob->get_job_status()
                    << " will be pivot";
          if (PipelineJob::kReady == pjob->get_job_status()) {
            pjob->set_job_status(PipelineJob::kPivot);
            // execute the underlying job
            for (auto it = pjob->node_task_num_.begin();
                 it != pjob->node_task_num_.end(); ++it) {
              pjob->node_allocated_thread_[it->first] +=
                  scheduler->thread_rest_[it->first];
              scheduler->thread_rest_[it->first] = 0;
            }
            pjob->CreatJobActor(scheduler);
            self->send(pjob->get_job_actor(), ExceJobAtom::value);

          } else if (PipelineJob::kExtra == pjob->get_job_status()) {
            pjob->set_job_status(PipelineJob::kPivot);
            // expand the underlying job
            self->send(pjob->get_job_actor(), EpdJobAtom::value);
          } else {
            assert(false && "doesn't know the status of the pivot job");
          }
          // schedule one extra job
          self->send(self, SchEJobAtom::value);
        }
        scheduler->lock_.release();

      },

      [=](SchEJobAtom) {
        // according to the free resource decide to execute one new job or
        // expand an extra job
        // naive method : schedule job among extra and ready jobs that's could
        // use the most free resource
        scheduler->lock_.acquire();

        int tmp_score = 0;
        int max_score = 0;
        PipelineJob* ejob = NULL;

        for (auto it = scheduler->ready_jobs_.begin();
             it != scheduler->ready_jobs_.end(); ++it) {
          tmp_score = 0;
          for (auto nit = (*it)->node_task_num_.begin();
               nit != (*it)->node_task_num_.end(); ++nit) {
            if (scheduler->thread_rest_[nit->first] > 0) {
              tmp_score += scheduler->thread_rest_[nit->first];
            } else {
              tmp_score -= 100;
            }
          }
          if (tmp_score > max_score) {
            max_score = tmp_score;
            ejob = *it;
          }
        }

        if (max_score > 0) {
          LOG(INFO) << "query ,job id, status = "
                    << scheduler->stmt_exec_status_->get_query_id() << " , "
                    << ejob->get_job_id() << " , " << ejob->get_job_status()
                    << " will be extra executed!";
          scheduler->EraseJobFromMultiset(scheduler->ready_jobs_,
                                          ejob->get_job_id());
          ejob->set_job_status(PipelineJob::kExtra);
          scheduler->extra_jobs_.insert(ejob);
          // execute the underlying job

          for (auto it = ejob->node_task_num_.begin();
               it != ejob->node_task_num_.end(); ++it) {
            ejob->node_allocated_thread_[it->first] +=
                scheduler->thread_rest_[it->first];
            scheduler->thread_rest_[it->first] = 0;
          }

          ejob->CreatJobActor(scheduler);
          self->send(ejob->get_job_actor(), ExceJobAtom::value);

        } else {
          LOG(INFO) << "query id= "
                    << scheduler->stmt_exec_status_->get_query_id()
                    << " couldn't found right job to expand or execute";
        }
        scheduler->lock_.release();
      },

      [=](DoneJobAtom, PipelineJob* pjob) {
        // if DoneJob is pivot, then trigger SchPJobAtom, else is extra, then
        // trigger SchEJobAtom
        // once complete a job, reduce the underling waiting parents and check
        // whether it's ready
        scheduler->lock_.acquire();

        if (NULL != pjob->get_child()) {
          pjob->get_child()->ReduceWaitingParents();
          if (pjob->get_child()->IsReadyJob()) {
            scheduler->ready_jobs_.insert(pjob->get_child());
          }
        }

        for (auto it = pjob->node_task_num_.begin();
             it != pjob->node_task_num_.end(); ++it) {
          scheduler->thread_rest_[it->first] +=
              pjob->node_allocated_thread_[it->first];
          pjob->node_allocated_thread_[it->first] = 0;
        }

        LOG(INFO) << "query, job id, status = "
                  << scheduler->stmt_exec_status_->get_query_id() << " , "
                  << pjob->get_job_id() << " , " << pjob->get_job_status()
                  << " has been Done";
        if (PipelineJob::kPivot == pjob->get_job_status()) {
          self->send(self, SchPJobAtom::value);
        } else if (PipelineJob::kExtra == pjob->get_job_status()) {
          scheduler->EraseJobFromMultiset(scheduler->extra_jobs_,
                                          pjob->get_job_id());
          self->send(self, SchEJobAtom::value);
        }
        pjob->set_job_status(PipelineJob::kDone);
        self->send(pjob->get_job_actor(), ExitAtom::value);

        scheduler->lock_.release();
      },

      [=](ExitAtom) { self->quit(); },
      caf::others >>
          [=]() { LOG(WARNING) << "ScheduleBase receives unkown message"; }

      );
  self->send(self, SchPJobAtom::value);
}

PipelineJob* BackfillScheduler::GetPivotJob() {
  PipelineJob* ret = NULL;
  if (extra_jobs_.empty()) {
    if (!ready_jobs_.empty()) {
      ret = *ready_jobs_.begin();
      ready_jobs_.erase(ready_jobs_.begin());
    }
  } else {
    if (ready_jobs_.empty()) {
      ret = *extra_jobs_.begin();
      extra_jobs_.erase(extra_jobs_.begin());
    } else {
      if ((*extra_jobs_.begin())->get_rank() >=
          (*ready_jobs_.begin())->get_rank()) {
        ret = *extra_jobs_.begin();
        extra_jobs_.erase(extra_jobs_.begin());
      } else {
        ret = *ready_jobs_.begin();
        ready_jobs_.erase(ready_jobs_.begin());
      }
    }
  }
  return ret;
}

void BackfillScheduler::InitThread() {
  for (int i = 0; i < kMaxNodeNum; ++i) {
    thread_num_.push_back(Config::total_thread_num);
    thread_rest_.push_back(Config::total_thread_num);
  }
}

RetCode BackfillScheduler::ComputeJobRank() {
  RetCode ret = rSuccess;
  dag_root_->ComputeJobRank(0);
  return ret;
}

void BackfillScheduler::CreateActor() {
  scheduler_actor_ = caf::spawn(ScheduleJob, this);
}

void BackfillScheduler::ComputeTaskNum() { dag_root_->ComputeNodeTask(); }

}  // namespace scheduler
}  // namespace claims
