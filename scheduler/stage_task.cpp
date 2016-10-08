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

#include "../common/ids.h"
#include "../exec_tracker/segment_exec_status.h"
#include "../exec_tracker/stmt_exec_status.h"
#include "../exec_tracker/stmt_exec_tracker.h"
#include "../Environment.h"
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
void StageTask::PrintPlan() {
  cout << "total have " << upper_node_id_list_.size() << " upper_nodes : ";
  for (int i = 0; i < upper_node_id_list_.size(); ++i) {
    cout << upper_node_id_list_[i] << " ";
  }
  cout << endl;
  cout << "total have " << lower_node_id_list_.size() << " lower_nodes : ";
  for (int i = 0; i < lower_node_id_list_.size(); ++i) {
    cout << lower_node_id_list_[i] << " ";
  }
  cout << endl;
  plan_->Print();
}
RetCode StageTask::SendPlan(StmtExecStatus* const stmt_exec_status,
                            const u_int32_t task_id) {
  LOG(INFO) << "begin to send plan of query_id, job_id, task_id "
            << stmt_exec_status->get_query_id() << " , "
            << task_id / kMaxTaskIdNum << " , " << task_id % kMaxTaskIdNum;
  int32_t stage_id = 0;
  RetCode ret = rSuccess;
  if (stmt_exec_status->IsCancelled()) {
    return rFailure;
  }
  // make sure upper exchanges are prepared
  ret = IsUpperExchangeRegistered(upper_node_id_list_, exchange_id_);
  if (rSuccess == ret) {
    for (int part_off = 0; part_off < lower_node_id_list_.size(); ++part_off) {
      if (stmt_exec_status->IsCancelled()) {
        return rFailure;
      }
      // set partition offset for each segment
      // stage_id of every stage =
      // job_id*kMaxTaskIdNum+task_id*kMaxPartNum+part_id
      stage_id = task_id * kMaxPartNum + part_off;

      // new SegmentExecStatus and add it to StmtExecStatus
      SegmentExecStatus* seg_exec_status = new SegmentExecStatus(
          make_pair(stmt_exec_status->get_query_id(),
                    stage_id * kMaxNodeNum + lower_node_id_list_[part_off]));

      stmt_exec_status->AddSegExecStatus(seg_exec_status);
      // send plan
      if (Environment::getInstance()
              ->get_iterator_executor_master()
              ->ExecuteBlockStreamIteratorsOnSite(
                  plan_, lower_node_id_list_[part_off],
                  stmt_exec_status->get_query_id(), stage_id,
                  part_off) == false) {
        LOG(ERROR) << "sending plan of " << stmt_exec_status->get_query_id()
                   << " , " << stage_id << "error!!!";
        return rFailure;
      }

      LOG(INFO) << "sending plan of " << stmt_exec_status->get_query_id()
                << " , " << stage_id << "succeed!!!";
    }
  } else {
    LOG(ERROR) << "asking upper exchange failed!" << endl;
    return rFailure;
  }

  return ret;
}
RetCode StageTask::IsUpperExchangeRegistered(
    const vector<NodeID>& upper_node_id_list, const u_int64_t exchange_id) {
  RetCode ret = rSuccess;
  NodeAddress node_addr;
  int times = 0;
  /// TODO(fzh)should release the strong synchronization
  for (int i = 0; i < upper_node_id_list.size(); ++i) {
    auto target_actor =
        Environment::getInstance()->get_slave_node()->GetNodeActorFromId(
            upper_node_id_list[i]);
    while (Environment::getInstance()
               ->getExchangeTracker()
               ->AskForSocketConnectionInfo(ExchangeID(exchange_id, i),
                                            upper_node_id_list[i], node_addr,
                                            target_actor) != true) {
      LOG(WARNING) << "busy asking socket connection info of node = "
                   << upper_node_id_list[i] << " , total times= " << ++times
                   << endl;
      usleep(200);
    }
  }
  return ret;
}

}  // namespace scheduler
}  // namespace claims
