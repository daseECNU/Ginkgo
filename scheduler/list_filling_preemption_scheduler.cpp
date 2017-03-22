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
#include "list_filling_preemption_scheduler.h"
#include "scheduler_base.h"
namespace claims {
namespace scheduler {

ListFillingPreemptionScheduler::ListFillingPreemptionScheduler(
    PipelineJob* const dag_root, StmtExecStatus* stmt_exec_status)
    : BackfillScheduler(dag_root, stmt_exec_status) {}

ListFillingPreemptionScheduler::~ListFillingPreemptionScheduler() {
  // TODO Auto-generated destructor stub
}
// modified from FineGrainBackfillScheduler, just remove scheduling extra jobs
void ListFillingPreemptionScheduler::ScheduleJob(
    caf::event_based_actor* self, ListFillingPreemptionScheduler* scheduler) {
  LOG(INFO) << "ListFillingPreemption starts up now!";
  scheduler->ComputeTaskNum();
  scheduler->InitThread();
  int delt_cost = 100;
  self->become(
      [=](SchPJobAtom) {

        multiset<PipelineJob*, PipelineJob::PipelineJobGT> ready_extra_job;
        ready_extra_job.insert(scheduler->ready_jobs_.begin(),
                               scheduler->ready_jobs_.end());
        ready_extra_job.insert(scheduler->extra_jobs_.begin(),
                               scheduler->extra_jobs_.end());
        for (auto it = ready_extra_job.begin(); it != ready_extra_job.end();
             ++it) {
          bool confilict = false;
          for (auto pit = scheduler->pivot_jobs_.begin();
               pit != scheduler->pivot_jobs_.end();) {
#ifndef REAL-PREEMPTION
            if ((*pit)->get_rank() >= (*it)->get_rank() - delt_cost) {
#else
            if ((*pit)->get_rank() < 0) {
#endif
              // if resources conflict, break
              if (scheduler->IsConflict((*it)->node_task_num_,
                                        (*pit)->node_task_num_)) {
                confilict = true;
                LOG(INFO) << "query ,job id, status = "
                          << scheduler->stmt_exec_status_->get_query_id()
                          << " , " << (*it)->get_job_id() << " , "
                          << (*it)->get_job_status()
                          << " will not be executed due to conflict with "
                          << (*pit)->get_job_id();
                break;
              }
              ++pit;
              continue;
            } else {
              // if resources conflict, set pivot to extra and set it to pivot
              if (scheduler->IsConflict((*it)->node_task_num_,
                                        (*pit)->node_task_num_)) {
                // return the resources of pivot job
                for (auto rit = (*pit)->node_task_num_.begin();
                     rit != (*pit)->node_task_num_.end(); ++rit) {
                  scheduler->thread_rest_[rit->first] =
                      (*pit)->node_allocated_thread_[rit->first];
                  (*pit)->node_allocated_thread_[rit->first] = 0;
                }
                // change status from pivot to extra
                LOG(INFO) << "query ,job id, status = "
                          << scheduler->stmt_exec_status_->get_query_id()
                          << " , " << (*pit)->get_job_id() << " , "
                          << (*pit)->get_job_status()
                          << " will be changed to extra due to conflict with "
                             "job id = " << (*it)->get_job_id();
                self->send((*pit)->get_job_actor(), SkJobAtom::value);
                (*pit)->set_job_status(PipelineJob::kExtra);
                scheduler->extra_jobs_.insert(*pit);
                // erase this pivot job
                pit = scheduler->pivot_jobs_.erase(pit);
              } else {
                ++pit;
              }
            }
          }
          if (!confilict) {
            LOG(INFO) << "query ,job id, status = "
                      << scheduler->stmt_exec_status_->get_query_id() << " , "
                      << (*it)->get_job_id() << " , " << (*it)->get_job_status()
                      << " will be changed to pivot";
            scheduler->pivot_jobs_.insert((*it));
            // set resources for this it job
            for (auto rit = (*it)->node_task_num_.begin();
                 rit != (*it)->node_task_num_.end(); ++rit) {
              (*it)->node_allocated_thread_[rit->first] +=
                  scheduler->thread_rest_[rit->first];
              scheduler->thread_rest_[rit->first] = 0;
            }
            // run the underlying job
            if (PipelineJob::kReady == (*it)->get_job_status()) {
              (*it)->set_job_status(PipelineJob::kPivot);
              scheduler->EraseJobFromMultiset(scheduler->ready_jobs_,
                                              (*it)->get_job_id());
              // execute the underlying job
              (*it)->CreatJobActor(scheduler);
              self->send((*it)->get_job_actor(), ExceJobAtom::value);

            } else if (PipelineJob::kExtra == (*it)->get_job_status()) {
              scheduler->EraseJobFromMultiset(scheduler->extra_jobs_,
                                              (*it)->get_job_id());
              (*it)->set_job_status(PipelineJob::kPivot);
              // expand the underlying job
              self->send((*it)->get_job_actor(), EpdJobAtom::value);
            } else {
              assert(false && "doesn't know the status of the pivot job");
            }
          }
        }

        // schedule one extra job
        self->send(self, SchEJobAtom::value);
      },

      [=](SchEJobAtom) {
        // according to the free resource decide to execute one new job or
        // expand an extra job
        // naive method : schedule job among extra and ready jobs that's could
        // use the most free resource
        PipelineJob* ejob = NULL;
        /*
        int tmp_score = 0;
        int max_score = 0;
        float max_rank = 0;

        for (auto it = scheduler->ready_jobs_.begin();
             it != scheduler->ready_jobs_.end(); ++it) {
          tmp_score = 0;
          for (auto nit = (*it)->node_task_num_.begin();
               nit != (*it)->node_task_num_.end(); ++nit) {
            if (scheduler->thread_rest_[nit->first] > 0) {
              tmp_score += scheduler->thread_rest_[nit->first];
            } else {
              // tmp_score -= 100;
            }
          }
          if (tmp_score >= max_score && (*it)->get_rank() > max_rank)
          {
            max_score = tmp_score;
            ejob = *it;
            max_rank = (*it)->get_rank();
          }
        }
*/
        for (auto it = scheduler->ready_jobs_.begin();
             it != scheduler->ready_jobs_.end(); ++it) {
          ejob = *it;
          if (NULL != ejob) {
            LOG(INFO) << "query ,job id, status = "
                      << scheduler->stmt_exec_status_->get_query_id() << " , "
                      << ejob->get_job_id() << " , " << ejob->get_job_status()
                      << " will be extra executed!";
            //            scheduler->ready_jobs_.erase(ejob);
            ejob->set_job_status(PipelineJob::kExtra);
            scheduler->extra_jobs_.insert(ejob);
            // execute the underlying job
            /*
                      for (auto it = ejob->node_task_num_.begin();
                           it != ejob->node_task_num_.end(); ++it) {
                        ejob->node_allocated_thread_[it->first] +=
                            scheduler->thread_rest_[it->first];
                        scheduler->thread_rest_[it->first] = 0;
                      }
            */
            ejob->CreatJobActor(scheduler);
            self->send(ejob->get_job_actor(), ExceJobAtom::value);

          } else {
            LOG(INFO) << "query id= "
                      << scheduler->stmt_exec_status_->get_query_id()
                      << " couldn't found right job to expand or execute ";
          }
        }
        scheduler->ready_jobs_.clear();
      },

      [=](DoneJobAtom, PipelineJob* pjob) {
        // if DoneJob is pivot, then trigger SchPJobAtom, else is extra, then
        // trigger SchEJobAtom
        // once complete a job, reduce the underling waiting parents and check
        // whether it's ready
        LOG(INFO) << "query, job id, status = "
                  << scheduler->stmt_exec_status_->get_query_id() << " , "
                  << pjob->get_job_id() << " , " << pjob->get_job_status()
                  << " has been Done";
        if (NULL != pjob->get_child()) {
          pjob->get_child()->ReduceWaitingParents();
          if (pjob->get_child()->IsReadyJob()) {
            LOG(INFO) << "job id = " << pjob->get_child()->get_job_id()
                      << " will be ready";
            scheduler->ready_jobs_.insert(pjob->get_child());
          }
        }

        for (auto it = pjob->node_task_num_.begin();
             it != pjob->node_task_num_.end(); ++it) {
          scheduler->thread_rest_[it->first] +=
              pjob->node_allocated_thread_[it->first];
          pjob->node_allocated_thread_[it->first] = 0;
        }

        if (PipelineJob::kPivot == pjob->get_job_status()) {
          scheduler->EraseJobFromMultiset(scheduler->pivot_jobs_,
                                          pjob->get_job_id());
          self->send(self, SchPJobAtom::value);
        } else if (PipelineJob::kExtra == pjob->get_job_status()) {
          scheduler->EraseJobFromMultiset(scheduler->extra_jobs_,
                                          pjob->get_job_id());
          self->send(self, SchEJobAtom::value);
        }
        pjob->set_job_status(PipelineJob::kDone);
        self->send(pjob->get_job_actor(), ExitAtom::value);

      },
      [=](UpdateRPAtom) {
        bool flag = false;
        multiset<PipelineJob*, PipelineJob::PipelineJobGT> jobs;
        for (auto it = scheduler->extra_jobs_.begin();
             it != scheduler->extra_jobs_.end(); ++it) {
          (*it)->RecomputeRank(jobs);
          flag = true;
        }
        // if there are extra jobs, then recompute rank for extra and pivot jobs
        if (flag) {
          scheduler->extra_jobs_.clear();
          scheduler->extra_jobs_.insert(jobs.begin(), jobs.end());
          jobs.clear();
          for (auto it = scheduler->extra_jobs_.begin();
               it != scheduler->extra_jobs_.end(); ++it) {
            LOG(INFO) << "extra job: id, status " << (*it)->get_job_id()
                      << " , " << (*it)->get_job_status() << " , "
                      << (*it)->get_rank();
          }

          for (auto it = scheduler->pivot_jobs_.begin();
               it != scheduler->pivot_jobs_.end(); ++it) {
            (*it)->RecomputeRank(jobs);
          }
          scheduler->pivot_jobs_.clear();
          scheduler->pivot_jobs_.insert(jobs.begin(), jobs.end());
          jobs.clear();
          for (auto it = scheduler->pivot_jobs_.begin();
               it != scheduler->pivot_jobs_.end(); ++it) {
            LOG(INFO) << "pivot job: id, status " << (*it)->get_job_id()
                      << " , " << (*it)->get_job_status() << " , "
                      << (*it)->get_rank();
          }
          self->send(self, SchPJobAtom::value);
          self->delayed_send(self, std::chrono::milliseconds(500),
                             UpdateRPAtom::value);
        }

      },
      [=](ExitAtom) { self->quit(); },

      caf::others >>

          [=]() {
            LOG(WARNING) << "ListFillingPreemption receives unkown message";
          });
  self->send(self, SchPJobAtom::value);
  self->delayed_send(self, std::chrono::milliseconds(500), UpdateRPAtom::value);
}

PipelineJob* ListFillingPreemptionScheduler::GetPivotJob() { return NULL; }

bool ListFillingPreemptionScheduler::IsConflict(
    const boost::unordered_map<int, u_int16_t>& nodes1,
    const boost::unordered_map<int, u_int16_t>& nodes2) {
  bool is_conflict = false;
  for (auto it = nodes1.begin(); it != nodes1.end() && !is_conflict; ++it) {
    is_conflict = (nodes2.find(it->first) != nodes2.end());
  }
  return is_conflict;
}

void ListFillingPreemptionScheduler::CreateActor() {
  scheduler_actor_ = caf::spawn(ScheduleJob, this);
}
}
}  // namespace claims
