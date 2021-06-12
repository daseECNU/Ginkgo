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
 * /Claims/Executor/query_exec_tracker.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#include "../exec_tracker/stmt_exec_tracker.h"

#include <string>
#include <iostream>
#include <utility>
#include "../common/error_define.h"
#include "../Environment.h"
#include "../node_manager/base_node.h"
#include "caf/all.hpp"
#include "caf/local_actor.hpp"
using std::make_pair;
using std::string;
using ginkgo::common::rCouldnotFindCancelQueryId;
namespace ginkgo {

StmtExecTracker::StmtExecTracker() : query_id_gen_(0), logic_time_(0) {
  stmt_exec_tracker_actor_ = caf::spawn(CheckStmtExecStatus, this);
}

StmtExecTracker::~StmtExecTracker() {
  caf::scoped_actor self;
  self->send(stmt_exec_tracker_actor_, ExitAtom::value);
  assert(query_id_to_stmtes_.size() == 0);
}

RetCode StmtExecTracker::RegisterStmtES(StmtExecStatus* stmtes) {
  lock_.acquire();
  stmtes->set_query_id(GenQueryId());
  query_id_to_stmtes_.insert(make_pair(stmtes->get_query_id(), stmtes));
  lock_.release();
  return rSuccess;
}

RetCode StmtExecTracker::UnRegisterStmtES(u_int64_t query_id) {
  lock_.acquire();
  auto it = query_id_to_stmtes_.find(query_id);
  if (it == query_id_to_stmtes_.end()) {
    LOG(WARNING) << "invalide query id = " << it->first
                 << " at UnRegisterStmtES" << endl;
  }
  query_id_to_stmtes_.erase(it);

  LOG(INFO) << "query id= " << query_id
            << " has erased from StmtEs! then left stmt = "
            << query_id_to_stmtes_.size() << endl;
  lock_.release();
  return rSuccess;
}
// for invoking from outside, so should add lock
RetCode StmtExecTracker::CancelStmtExec(u_int64_t query_id) {
  lock_.acquire();
  auto it = query_id_to_stmtes_.find(query_id);
  if (it == query_id_to_stmtes_.end()) {
    LOG(WARNING) << "inval query id at cancel query of stmt exec tracker"
                 << endl;
    lock_.release();
    assert(false);
    return rCouldnotFindCancelQueryId;
  }
  it->second->CancelStmtExec();
  lock_.release();
  return rSuccess;
}

void StmtExecTracker::CheckStmtExecStatus(caf::event_based_actor* self,
                                          StmtExecTracker* stmtes) {
  self->become(

      [=](CheckStmtESAtom) {
        stmtes->lock_.acquire();
        for (auto it = stmtes->query_id_to_stmtes_.begin();
             it != stmtes->query_id_to_stmtes_.end();) {
          if (it->second->CouldBeDeleted((u_int64_t)stmtes->logic_time_)) {
            LOG(INFO) << "query id = " << it->first << " will be deleted!";
            delete it->second;
            it->second = NULL;
            // pay attention to erase()
            it = stmtes->query_id_to_stmtes_.erase(it);
          } else {
            if (it->second->HaveErrorCase(stmtes->logic_time_)) {
              LOG(ERROR) << "query id = " << it->first
                         << " occur error and will be cancelled!";
              //  assert(false);
              it->second->CancelStmtExec();
            }
            ++it;
          }
        }
        stmtes->lock_.release();
        stmtes->logic_time_++;
        self->delayed_send(self, std::chrono::milliseconds(kCheckIntervalTime),
                           CheckStmtESAtom::value);
      },
      [=](ExitAtom) { self->quit(); },
      caf::others >> [=]() {
                       LOG(WARNING) << "stmt checking receives unkown message"
                                    << endl;
                     });
  self->send(self, CheckStmtESAtom::value);
}

// first find stmt_exec_status, then update status
bool StmtExecTracker::UpdateSegExecStatus(
    NodeSegmentID node_segment_id, SegmentExecStatus::ExecStatus exec_status,
    string exec_info) {
  lock_.acquire();
  auto it = query_id_to_stmtes_.find(node_segment_id.first);
  if (it != query_id_to_stmtes_.end()) {
    StmtExecStatus::ExecStatus stmt_exec_status = it->second->get_exec_status();
    bool ret = it->second->UpdateSegExecStatus(node_segment_id, exec_status,
                                               exec_info, logic_time_);
    LOG(INFO) << node_segment_id.first << " , " << node_segment_id.second
              << " receive : " << exec_status << " , " << exec_info
              << " stmt status before: " << stmt_exec_status
              << " ,after: " << it->second->get_exec_status();
    lock_.release();
    return ret;
  } else {  // maybe receive delayed message
    LOG(WARNING) << "query id = " << node_segment_id.first
                 << " couldn't be found in tracker!";
    lock_.release();
  }
  return false;
}

}  // namespace ginkgo
