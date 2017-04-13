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
 * /Claims/scheduler/fine_grain_backfill_scheduler.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include <glog/logging.h>

#include "caf/all.hpp"

#include "../node_manager/base_node.h"
#include "../scheduler/pipeline_job.h"
#include "list_static_scheduler.h"

#include <algorithm>
#include "../Config.h"
#include "scheduler_base.h"
namespace claims {
namespace scheduler {

ListStaticScheduler::ListStaticScheduler(PipelineJob* const dag_root,
                                         StmtExecStatus* stmt_exec_status)
    : BackfillScheduler(dag_root, stmt_exec_status) {}

ListStaticScheduler::~ListStaticScheduler() {
  // TODO Auto-generated destructor stub
}
// modified from FineGrainBackfillScheduler, just remove scheduling extra jobs
void ListStaticScheduler::ScheduleJob(caf::event_based_actor* self,
                                      ListStaticScheduler* scheduler) {
  LOG(INFO) << "ListStaticScheduler starts up now!";
  scheduler->ComputeTaskNum();
  scheduler->InitThread();
  self->become(
      [=](SchPJobAtom) {
        scheduler->lock_.acquire();
        PipelineJob* pjob = NULL;
        while ((pjob = scheduler->GetPivotJob()) != NULL) {
          LOG(INFO) << "query ,job id, status = "
                    << scheduler->stmt_exec_status_->get_query_id() << " , "
                    << pjob->get_job_id() << " , " << pjob->get_job_status()
                    << " will be pivot";
          // for pivot job to record the resource that is used
          for (auto it = pjob->node_task_num_.begin();
               it != pjob->node_task_num_.end(); ++it) {
            pjob->node_allocated_thread_[it->first] +=
                std::min(scheduler->thread_rest_[it->first],
                         Config::max_degree_of_parallelism);
            scheduler->thread_rest_[it->first] -=
                Config::max_degree_of_parallelism;
            if (scheduler->thread_rest_[it->first] < 0) {
              scheduler->thread_rest_[it->first] = 0;
            }
          }
          if (PipelineJob::kReady == pjob->get_job_status()) {
            pjob->set_job_status(PipelineJob::kPivot);
            // execute the underlying job
            pjob->CreatJobActor(scheduler);
            self->send(pjob->get_job_actor(), ExceJobAtom::value);

          } else if (PipelineJob::kExtra == pjob->get_job_status()) {
            pjob->set_job_status(PipelineJob::kPivot);
            // expand the underlying job
            self->send(pjob->get_job_actor(), EpdJobAtom::value);
          } else {
            assert(false && "doesn't know the status of the pivot job");
          }
        }
        // needn't schedule one extra job
        // self->send(self, SchEJobAtom::value);
        scheduler->lock_.release();

      },

      [=](SchEJobAtom) {
        //        // according to the free resource decide to execute one new
        //        job or
        //        // expand an extra job
        //        // naive method : schedule job among extra and ready jobs
        //        that's could
        //        // use the most free resource
        //        scheduler->lock_.acquire();
        //        PipelineJob* ejob = NULL;
        //        /*
        //        int tmp_score = 0;
        //        int max_score = 0;
        //        float max_rank = 0;
        //
        //        for (auto it = scheduler->ready_jobs_.begin();
        //             it != scheduler->ready_jobs_.end(); ++it) {
        //          tmp_score = 0;
        //          for (auto nit = (*it)->node_task_num_.begin();
        //               nit != (*it)->node_task_num_.end(); ++nit) {
        //            if (scheduler->thread_rest_[nit->first] > 0) {
        //              tmp_score += scheduler->thread_rest_[nit->first];
        //            } else {
        //              // tmp_score -= 100;
        //            }
        //          }
        //          if (tmp_score >= max_score && (*it)->get_rank() > max_rank)
        //          {
        //            max_score = tmp_score;
        //            ejob = *it;
        //            max_rank = (*it)->get_rank();
        //          }
        //        }
        //*/
        //        for (auto it = scheduler->ready_jobs_.begin();
        //             it != scheduler->ready_jobs_.end(); ++it) {
        //          ejob = *it;
        //          if (NULL != ejob) {
        //            LOG(INFO) << "query ,job id, status = "
        //                      << scheduler->stmt_exec_status_->get_query_id()
        //                      << " , "
        //                      << ejob->get_job_id() << " , " <<
        //                      ejob->get_job_status()
        //                      << " will be extra executed!";
        //            //            scheduler->ready_jobs_.erase(ejob);
        //            ejob->set_job_status(PipelineJob::kExtra);
        //            scheduler->extra_jobs_.insert(ejob);
        //            // execute the underlying job
        //            /*
        //                      for (auto it = ejob->node_task_num_.begin();
        //                           it != ejob->node_task_num_.end(); ++it) {
        //                        ejob->node_allocated_thread_[it->first] +=
        //                            scheduler->thread_rest_[it->first];
        //                        scheduler->thread_rest_[it->first] = 0;
        //                      }
        //            */
        //            ejob->CreatJobActor(scheduler);
        //            self->send(ejob->get_job_actor(), ExceJobAtom::value);
        //
        //          } else {
        //            LOG(INFO) << "query id= "
        //                      << scheduler->stmt_exec_status_->get_query_id()
        //                      << " couldn't found right job to expand or
        //                      execute";
        //          }
        //        }
        //        scheduler->ready_jobs_.clear();
        //        scheduler->lock_.release();
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
          // scheduler->extra_jobs_.erase(pjob);
          // self->send(self, SchEJobAtom::value);
        }
        pjob->set_job_status(PipelineJob::kDone);
        self->send(pjob->get_job_actor(), ExitAtom::value);

        scheduler->lock_.release();
      },

      [=](ExitAtom) { self->quit(); },

      caf::others >>

          [=]() {
            LOG(WARNING) << "ListStaticScheduler receives unkown message";
          });
  self->send(self, SchPJobAtom::value);
}

PipelineJob* ListStaticScheduler::GetPivotJob() {
  auto rit = ready_jobs_.begin();
  auto eit = extra_jobs_.begin();
  PipelineJob* tmp_job = NULL;
  for (; rit != ready_jobs_.end() && eit != extra_jobs_.end();) {
    if ((*rit)->get_rank() > (*eit)->get_rank()) {
      if (CouldSchedule(*rit)) {
        tmp_job = *rit;
        ready_jobs_.erase(rit);
        return tmp_job;
      } else {
        ++rit;
      }
    } else {
      if (CouldSchedule(*eit)) {
        tmp_job = *eit;
        extra_jobs_.erase(eit);
        return tmp_job;
      } else {
        ++eit;
      }
    }
  }
  for (; rit != ready_jobs_.end(); ++rit) {
    if (CouldSchedule(*rit)) {
      tmp_job = *rit;
      ready_jobs_.erase(rit);
      return tmp_job;
    }
  }
  for (; eit != extra_jobs_.end(); ++eit) {
    if (CouldSchedule(*eit)) {
      tmp_job = *eit;
      extra_jobs_.erase(eit);
      return tmp_job;
    }
  }
  return NULL;
}

bool ListStaticScheduler::CouldSchedule(PipelineJob* pjob) {
  bool could_sch = true;
  int max_degree = Config::max_degree_of_parallelism;
  int total_degree = Config::total_thread_num;

  for (auto it = pjob->node_task_num_.begin(); it != pjob->node_task_num_.end();
       ++it) {
    if (max_degree * it->second > total_degree) {
      max_degree = total_degree / it->second;
    }
    if (thread_rest_[it->first] < max_degree * it->second) {
      could_sch = false;
    }
  }
  return could_sch;
}

void ListStaticScheduler::CreateActor() {
  scheduler_actor_ = caf::spawn(ScheduleJob, this);
}
}
}  // namespace claims
