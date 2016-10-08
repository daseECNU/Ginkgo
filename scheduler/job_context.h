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
 * /Claims/scheduler/job_context.h
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_JOB_CONTEXT_H_
#define SCHEDULER_JOB_CONTEXT_H_
#include <stdint.h>
#include <atomic>
#include <vector>

#include "../scheduler/pipeline_job.h"
#include "../scheduler/stage_task.h"
using std::atomic;
using std::vector;

namespace claims {
namespace scheduler {
// cache temporary variables for creating DAG
class JobContext {
 public:
  JobContext();
  virtual ~JobContext();

  PipelineJob* const get_dag_root() const { return dag_root_; }
  void set_dag_root(PipelineJob* const dag_root) { dag_root_ = dag_root; }
  void PushNodeId(uint16_t node_id) { node_id_.push_back(node_id); }
  uint16_t GenJobId() { return ++job_id_; }

  const vector<int>& get_node_id() const { return node_id_; }
  void ClearStageTasks() { stage_tasks_.clear(); }
  void ClearParents() { parents_.clear(); }

  void set_node_id(const vector<int>& node_id) { node_id_ = node_id; }
  void set_node_id(int node_id) { node_id_.push_back(node_id); }

  const vector<PipelineJob*>& get_parents() const { return parents_; }

  void set_parents(const vector<PipelineJob*>& parents) { parents_ = parents; }
  void set_parents(PipelineJob* const parents) { parents_.push_back(parents); }

  const vector<StageTask*>& get_stage_tasks() const { return stage_tasks_; }

  void set_stage_tasks(const vector<StageTask*>& stage_tasks) {
    stage_tasks_ = stage_tasks;
  }
  void set_stage_tasks(StageTask* const stage_task) {
    stage_tasks_.push_back(stage_task);
  }

 private:
  vector<StageTask*> stage_tasks_;
  vector<PipelineJob*> parents_;
  vector<int> node_id_;
  atomic<uint16_t> job_id_;
  PipelineJob* dag_root_;
};
}
}  // namespace claims

#endif  //  SCHEDULER_JOB_CONTEXT_H_
