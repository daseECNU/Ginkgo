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
 * /Claims/scheduler/stage_task.h
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef SCHEDULER_STAGE_TASK_H_
#define SCHEDULER_STAGE_TASK_H_
#include <boost/unordered/unordered_map.hpp>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include "../common/ids.h"
#include "../common/error_define.h"
using std::vector;
using std::cout;
using std::endl;
using claims::common::rSuccess;
namespace claims {
#define kMaxJobIdNum 100
#define kMaxTaskIdNum 100
#define kMaxPartNum 100
namespace physical_operator {
class PhysicalOperatorBase;
}
class StmtExecStatus;

namespace scheduler {
class StageTask {
 public:
  enum StageTaskStatus { kWaiting, kRunning, kDone };
  virtual ~StageTask();
  StageTask(physical_operator::PhysicalOperatorBase* plan,
            vector<NodeID> lower_node_id_list,
            vector<NodeID> upper_node_id_list, u_int64_t exchange_id);
  physical_operator::PhysicalOperatorBase* get_plan_() { return plan_; }
  void PrintPlan();
  RetCode SendAndStartPlan(StmtExecStatus* const stmt_exec_status,
                           const u_int32_t id);
  RetCode IsUpperExchangeRegistered(const vector<NodeID>& upper_node_id_list,
                                    const u_int64_t exchange_id);
  u_int16_t GetPartNum() { return lower_node_id_list_.size(); }

  StageTaskStatus get_stage_status() const { return stage_status_; }

  void set_stage_status(StageTaskStatus stage_status) {
    stage_status_ = stage_status;
  }
  void ComputeNodeTask(boost::unordered_map<int, u_int16_t>& node_task_num);

 private:
  StageTaskStatus stage_status_;
  vector<NodeID> lower_node_id_list_;
  vector<NodeID> upper_node_id_list_;
  u_int64_t exchange_id_ = 0;
  physical_operator::PhysicalOperatorBase* plan_;
};
}  // namespace scheduler
}  // namespace claims

#endif  //  SCHEDULER_STAGE_TASK_H_
