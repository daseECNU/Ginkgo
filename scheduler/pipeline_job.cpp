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
 * /Claims/scheduler/pipeline_job.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "pipeline_job.h"

#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "../exec_tracker/stmt_exec_tracker.h"
#include "caf/all.hpp"

#include "../Environment.h"
#include "scheduler_base.h"
using caf::scoped_actor;
using caf::typed_event_based_actor;
using std::reverse;
namespace claims {
namespace scheduler {

PipelineJob::PipelineJob(vector<StageTask*> stage_tasks,
                         vector<PipelineJob*> parents, uint16_t job_id)
    : stage_tasks_(stage_tasks),
      parents_(parents),
      job_id_(job_id),
      child_(NULL),
      rank_(-1),
      job_status_(kQueued),
      scheduler_(NULL) {
  // reorder the stage_task of one pipeline from top to down
  reverse(stage_tasks_.begin(), stage_tasks_.end());
  for (int i = 0; i < kMaxNodeNum; ++i) {
    //    node_task_num_[i] = 0;
    node_allocated_thread_[i] = 0;
  }
}

PipelineJob::~PipelineJob() {
  // TODO Auto-generated destructor stub
}
void PipelineJob::PrintJob() {
  std::cout << "***** job_id= " << job_id_ << " rank = " << rank_
            << "***** has " << stage_tasks_.size() << " stage_task begin*****"
            << std::endl;
  int i = 0;
  for (auto it = stage_tasks_.begin(); it != stage_tasks_.end(); ++it, ++i) {
    std::cout << "+++++ job_id= " << job_id_ << "+++++ task_id= " << i
              << " +++++" << std::endl;
    (*it)->PrintPlan();
  }
  std::cout << "***** job_id= " << job_id_ << "***** has "
            << stage_tasks_.size() << " stage_task end  *****" << std::endl;
  for (auto it = parents_.begin(); it != parents_.end(); ++it) {
    std::cout << "===== " << job_id_ << " child <===== parent "
              << (*it)->job_id_ << " =====" << std::endl;
    (*it)->PrintJob();
  }
}

void PipelineJob::set_child(PipelineJob* const child) {
  child_ = child;
  for (auto it = parents_.begin(); it != parents_.end(); ++it) {
    (*it)->set_child(this);
  }
}
RetCode PipelineJob::ComputeJobRank(float upper_rank) {
  RetCode ret = rSuccess;
  set_waiting_parents(parents_.size());
  set_rank(upper_rank + 1);
  for (auto it = parents_.begin(); it != parents_.end(); ++it) {
    (*it)->ComputeJobRank(get_rank());
  }
  return ret;
}

RetCode PipelineJob::GetReadyJobs(set<PipelineJob*>& ready_jobs) {
  RetCode ret = rSuccess;
  if (parents_.empty()) {  // leaf job
    set_job_status(kReady);
    ready_jobs.insert(this);
  } else {
    for (auto it = parents_.begin(); it != parents_.end(); ++it) {
      (*it)->GetReadyJobs(ready_jobs);
    }
  }
  return ret;
}

RetCode PipelineJob::DirectExecuteJob(StmtExecStatus* const stmt_exec_status) {
  RetCode ret = rSuccess;
#ifdef SYN
  stmt_exec_status->AddOneJob(job_id_, stage_tasks_[0]->GetPartNum());
#else
  InitTopTaskStatus();
  stmt_exec_status->RegisterOneJob(job_id_, this);
#endif
  // the id of stage_task corresponding to the order to stage_task_ vector
  // note the top task id =0
  // as some scheduler don't set job status, so if it's set kExtra, so not
  // kPivot
  bool is_pivot = (kExtra == job_status_ ? false : true);
  for (u_int16_t id = 0; id < stage_tasks_.size(); ++id) {
    stage_tasks_[id]->SendAndStartPlan(stmt_exec_status,
                                       job_id_ * kMaxTaskIdNum + id, is_pivot);
  }
#ifdef SYN
  // just check the top task(id=0) is Done?
  stmt_exec_status->JobWaitingDone(job_id_, stage_tasks_[0]->GetPartNum());
  LOG(INFO) << "$$$ query_id, job_id = " << stmt_exec_status->get_query_id()
            << " , " << job_id_ << " is Done!";
#endif
  return ret;
}
bool PipelineJob::IsReadyJob() { return get_waiting_parents() < 1; }

void PipelineJob::ExecuteNewJob(caf::event_based_actor* self,
                                SchedulerBase* const scheduler) {
  set_scheduler(scheduler);

  //  DirectExecuteJob(scheduler->get_stmt_exec_status());

  for (auto it = node_task_num_.begin(); it != node_task_num_.end(); ++it) {
    node_allocated_thread_[it->first] += scheduler->thread_rest_[it->first];
    scheduler->thread_rest_[it->first] = 0;
  }
  CreatJobActor(scheduler);
  self->send(get_job_actor(), ExceJobAtom::value);
  LOG(INFO) << "query, job id= "
            << scheduler->get_stmt_exec_status()->get_query_id() << " , "
            << job_id_ << " will be executed! has been sent";
}

void PipelineJob::ExecuteJob(caf::event_based_actor* self, PipelineJob* job,
                             SchedulerBase* const scheduler) {
  job->set_scheduler(scheduler);
  self->become(

      [=](ExceJobAtom) {
        LOG(INFO) << "query, job id= "
                  << scheduler->get_stmt_exec_status()->get_query_id() << " , "
                  << job->job_id_ << " will be executed!";
        job->DirectExecuteJob(scheduler->get_stmt_exec_status());

        for (auto it = job->node_task_num_.begin();
             it != job->node_task_num_.end(); ++it) {
          job->node_allocated_thread_[it->first] +=
              scheduler->thread_rest_[it->first];
          scheduler->thread_rest_[it->first] = 0;
        }
      },
      [=](EpdJobAtom) {
        LOG(INFO) << "query, job id= "
                  << scheduler->get_stmt_exec_status()->get_query_id() << " , "
                  << job->job_id_ << " will be expaned!";
        for (auto it = job->node_task_num_.begin();
             it != job->node_task_num_.end(); ++it) {
          self->sync_send(Environment::getInstance()
                              ->get_slave_node()
                              ->GetNodeActorFromId(it->first),
                          EpdJobAtom::value,
                          scheduler->get_stmt_exec_status()->get_query_id(),
                          job->get_job_id())
              .then(

                  [=](OkAtom) {
                    job->node_allocated_thread_[it->first] +=
                        scheduler->thread_rest_[it->first];
                    scheduler->thread_rest_[it->first] = 0;
                  },
                  caf::others >>
                      [=]() {
                        LOG(WARNING)
                            << "pipeline expand job receives unknown message";
                      },
                  caf::after(std::chrono::seconds(kTimeout)) >>
                      [&]() {
                        LOG(WARNING) << "expand job " << job->get_job_id()
                                     << " timeout!";
                      }

                  );
        }

      },
      [=](SkJobAtom) {
        LOG(INFO) << "query, job id= "
                  << scheduler->get_stmt_exec_status()->get_query_id() << " , "
                  << job->job_id_ << " will be shrunk!";
        for (auto it = job->node_task_num_.begin();
             it != job->node_task_num_.end(); ++it) {
          self->sync_send(Environment::getInstance()
                              ->get_slave_node()
                              ->GetNodeActorFromId(it->first),
                          SkJobAtom::value,
                          scheduler->get_stmt_exec_status()->get_query_id(),
                          job->get_job_id(),
                          -job->node_allocated_thread_[it->first])
              .then(

                  [=](OkAtom) {
                    scheduler->thread_rest_[it->first] +=
                        job->node_allocated_thread_[it->first];
                    job->node_allocated_thread_[it->first] = 0;
                  },
                  caf::others >>
                      [=]() {
                        LOG(WARNING)
                            << "pipeline shrink job receives unknown message";
                      },
                  caf::after(std::chrono::seconds(kTimeout)) >>
                      [&]() {
                        LOG(WARNING) << "shrink job " << job->get_job_id()
                                     << " timeout!";
                      }

                  );
        }
      },

      [=](ExitAtom) { self->quit(); },
      caf::others >>
          [=]() { LOG(WARNING) << "ScheduleBase receives unkown message"; }

      );
}

void PipelineJob::InitTopTaskStatus() {
  u_int64_t part_num = stage_tasks_[0]->GetPartNum();
  for (auto i = 0; i < part_num; ++i) {
    top_task_is_done_[i] = false;
  }
}

bool PipelineJob::CheckTopTaskIsDone(u_int64_t part_id) {
  u_int64_t part_num = stage_tasks_[0]->GetPartNum();
  assert(part_id < part_num);
  top_task_is_done_[part_id] = true;
  for (auto i = 0; i < part_num; ++i) {
    if (top_task_is_done_[i] == false) {
      return false;
    }
  }

  scoped_actor self;
  self->send(get_scheduler()->get_scheduler_actor(), DoneJobAtom::value, this);
  LOG(INFO) << "query,job_id = "
            << scheduler_->get_stmt_exec_status()->get_query_id() << " , "
            << job_id_ << " is Done";
  return true;
}
void PipelineJob::ReduceWaitingParents() {
  --waiting_parents_;
  if (1 > waiting_parents_) {
    set_job_status(kReady);
  }
}
void PipelineJob::CreatJobActor(SchedulerBase* const scheduler) {
  job_actor_ = caf::spawn(ExecuteJob, this, scheduler);
}
void PipelineJob::ComputeNodeTask() {
  for (int i = 0; i < stage_tasks_.size(); ++i) {
    stage_tasks_[i]->ComputeNodeTask(node_task_num_);
  }
  if (!parents_.empty()) {
    for (auto it = parents_.begin(); it != parents_.end(); ++it) {
      (*it)->ComputeNodeTask();
    }
  }
}

}  // namespace scheduler
}  // namespace claims
