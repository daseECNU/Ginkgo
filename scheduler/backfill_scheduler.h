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
 * /Claims/scheduler/backfill_scheduler.h
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_BACKFILL_SCHEDULER_H_
#define SCHEDULER_BACKFILL_SCHEDULER_H_

#include <set>
#include "../common/error_define.h"
#include "../scheduler/pipeline_job.h"
#include "../utility/lock.h"
#include "scheduler_base.h"

using std::set;

namespace claims {
namespace scheduler {

class BackfillScheduler : public SchedulerBase {
 public:
  BackfillScheduler(PipelineJob* const dag_root, StmtExecStatus* exec_status);
  virtual ~BackfillScheduler();
  static void ScheduleJob(caf::event_based_actor* self,
                          BackfillScheduler* scheduler);
  PipelineJob* GetPivotJob();
  void InitThread();
  void CreateActor();

  Lock lock_;

 private:
  PipelineJob* pivot_jobs_;
  set<PipelineJob*> extra_jobs_;
  RetCode ComputeJobRank();
  void ComputeTaskNum();
};
}
}  // namespace claims

#endif  //  SCHEDULER_BACKFILL_SCHEDULER_H_
