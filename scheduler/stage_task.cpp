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
 * /Claims/scheduler/stage_task.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "stage_task.h"

#include <sys/types.h>
#include <vector>

#include "../physical_operator/physical_operator_base.h"

using claims::physical_operator::PhysicalOperatorBase;
namespace claims {
namespace scheduler {

StageTask::StageTask() {
  // TODO Auto-generated constructor stub
}

StageTask::~StageTask() {
  // TODO Auto-generated destructor stub
}

StageTask::StageTask(PhysicalOperatorBase* plan,
                     vector<NodeID> lower_node_id_list,
                     vector<NodeID> upper_node_id_list, u_int64_t exchange_id)
    : plan_(plan),
      lower_node_id_list_(lower_node_id_list),
      upper_node_id_list_(upper_node_id_list),
      exchange_id_(exchange_id) {}
void StageTask::PrintPlan() { plan_->Print(); }
}
}  // namespace claims
