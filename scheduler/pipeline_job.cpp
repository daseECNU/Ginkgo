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
#include <vector>
namespace claims {
namespace scheduler {

PipelineJob::PipelineJob() : child_(NULL), job_id_(0) {}

PipelineJob::PipelineJob(vector<StageTask*> stage_tasks,
                         vector<PipelineJob*> parents, uint16_t job_id)
    : stage_tasks_(stage_tasks),
      parents_(parents),
      job_id_(job_id),
      child_(NULL) {}

PipelineJob::~PipelineJob() {
  // TODO Auto-generated destructor stub
}
void PipelineJob::PrintJob() {
  std::cout << "***** job_id= " << job_id_ << "***** has "
            << stage_tasks_.size() << " stage_task begin*****" << std::endl;
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
}
}  // namespace claims
