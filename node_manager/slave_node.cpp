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
 * /Claims/node_manager/slave_node.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */
#include <glog/logging.h>
#include <string>
#include <utility>
#include <iostream>
#include "./slave_node.h"

#include <stdlib.h>
#include <unistd.h>

#include "../common/Message.h"
#include "caf/io/all.hpp"

#include "./base_node.h"
#include "../common/ids.h"
#include "../Environment.h"
#include "../storage/StorageLevel.h"
#include "caf/all.hpp"
#include <map>
#include <unordered_map>
#include "../stmt_handler/load_exec.h"
#include "../common/error_define.h"
#include "../common/Schema/TupleConvertor.h"
#include "../loader/data_injector.h"
using caf::io::remote_actor;
using caf::make_message;
using caf::message;
using std::make_pair;
// using std::unordered_map;
using claims::common::rConRemoteActorError;
using claims::common::rRegisterToMasterTimeOut;
using claims::common::rRegisterToMasterError;
using claims::stmt_handler::LoadExec;
using claims::loader::DataInjector;
namespace claims {
SlaveNode* SlaveNode::instance_ = 0;
class SlaveNodeActor : public event_based_actor {
 public:
  SlaveNodeActor(SlaveNode* slave_node) : slave_node_(slave_node) {}

  behavior make_behavior() override {
    LOG(INFO) << "slave node actor is OK!" << std::endl;
    return {
        [=](ExitAtom) {
          LOG(INFO) << "slave " << slave_node_->get_node_id() << " finish!"
                    << endl;
          quit();
        },
        [=](SendPlanAtom, string str, u_int64_t query_id,
            u_int32_t segment_id) {
          LOG(INFO) << "coor node receive one plan " << query_id << " , "
                    << segment_id << " plan string size= " << str.length();
          PhysicalQueryPlan* new_plan = new PhysicalQueryPlan(
              PhysicalQueryPlan::TextDeserializePlan(str));
          LOG(INFO) << "coor node deserialized plan " << query_id << " , "
                    << segment_id;
          ticks start = curtick();
          Environment::getInstance()
              ->getIteratorExecutorSlave()
              ->createNewThreadAndRun(new_plan);

          string log_message =
              "Slave: received plan segment and create new thread and run it! ";
          LOG(INFO) << log_message << query_id << " , " << segment_id
                    << " , createNewThreadAndRun:" << getMilliSecond(start);
        },
        [=](LoadPlanAtom, string filename, int open_flag, string col_sep,
            string row_sep, uint64_t start, uint64_t end, uint64_t tuple_id,
            int total_nodes, LoadInfo l) {
          std::cout << "start : " << start << " end : " << end << endl;
          vector<column_type> columns;
          vector<vector<column_type> > proj_columns;
          vector<GeneralModuloFunction> part_func_v;
          for (int i = 0; i < l.cols_.size(); ++i) {
            col_type c;
            std::istringstream is(l.cols_[i]);
            boost::archive::binary_iarchive ia(is);
            ia >> c;
            columns.push_back(column_type(c.type_, c.size_, c.nullable_));
          }
          for (int i = 0; i < l.proj_cols_.size(); ++i) {
            vector<column_type> tmp;
            for (int j = 0; j < l.proj_cols_[i].size(); ++j) {
              col_type c;
              std::istringstream is(l.proj_cols_[i][j]);
              boost::archive::binary_iarchive ia(is);
              ia >> c;
              tmp.push_back(column_type(c.type_, c.size_, c.nullable_));
            }
            proj_columns.push_back(tmp);
          }
          for (int i = 0; i < l.part_func_v_.size(); ++i) {
            GeneralModuloFunction f;
            std::istringstream is(l.part_func_v_[i]);
            boost::archive::binary_iarchive ia(is);
            ia >> f;
            part_func_v.push_back(f);
          }
          tuple_id += slave_node_->node_id_ * 10000;
          DataInjector* data_in = new DataInjector(
              col_sep, row_sep, tuple_id, columns, proj_columns, l.write_path_,
              l.part_key_idx_, part_func_v, l.prj_index_vec_, l.tbl_name_);
          vector<string> files;
          vector<uint64_t> starts;
          vector<uint64_t> ends;
          files.push_back(filename);
          starts.push_back(start);
          ends.push_back(end);
          LoadMsg ldmsg;
          ldmsg.node_id_ = slave_node_->node_id_;
          ldmsg.tbl_name_ = l.tbl_name_;
          ldmsg.load_mode_ = open_flag;
          data_in->DistributedLoadMultiThread(files, open_flag, starts, ends,
                                              total_nodes, ldmsg);
          delete data_in;

          caf::scoped_actor self;
          try {
            auto target_actor = SlaveNode::GetInstance()->GetMasterActor();
            self->send(target_actor, LoadPlanAtom::value, ldmsg);
          } catch (caf::bind_failure& e) {
            LOG(ERROR)
                << "master sending load plan binds port error when connecting "
                   "remote actor";
          } catch (caf::network_error& e) {
            LOG(ERROR) << "master sending load plan connect to remote node "
                          "error due to "
                          "network error!";
          }
        },
        [=](AskExchAtom, ExchangeID exch_id) -> message {
          auto addr =
              Environment::getInstance()->getExchangeTracker()->GetExchAddr(
                  exch_id);
          return make_message(OkAtom::value, addr.ip, addr.port);
        },
        [=](BindingAtom, const PartitionID partition_id,
            const unsigned number_of_chunks,
            const StorageLevel desirable_storage_level) -> message {
          LOG(INFO) << "receive binding message!" << endl;
          Environment::getInstance()->get_block_manager()->AddPartition(
              partition_id, number_of_chunks, desirable_storage_level);
          return make_message(OkAtom::value);
        },
        [=](UnBindingAtom, const PartitionID partition_id) -> message {
          LOG(INFO) << "receive unbinding message~!" << endl;
          Environment::getInstance()->get_block_manager()->RemovePartition(
              partition_id);
          return make_message(OkAtom::value);
        },
        [=](BroadcastNodeAtom, const unsigned int& node_id,
            const string& node_ip, const uint16_t& node_port) {
          LOG(INFO) << "receive broadcast message~!" << endl;
          // check if this node is Reregister node
          unsigned int tmp_node_id;
          bool is_reregister = false;
          for (auto it = slave_node_->node_id_to_addr_.begin();
               it != slave_node_->node_id_to_addr_.end(); ++it) {
            if (it->second.first == node_ip) {
              is_reregister = true;
              tmp_node_id = it->first;
            }
          }
          if (is_reregister) {
            slave_node_->node_id_to_addr_.erase(tmp_node_id);
            slave_node_->node_id_to_actor_.erase(tmp_node_id);
            LOG(INFO) << "slave " << slave_node_->get_node_id()
                      << "remove old node :" << tmp_node_id << "info" << endl;
          }
          slave_node_->AddOneNode(node_id, node_ip, node_port);
        },
        [=](ReportSegESAtom, NodeSegmentID node_segment_id, int exec_status,
            string exec_info) -> message {
          bool ret =
              Environment::getInstance()
                  ->get_stmt_exec_tracker()
                  ->UpdateSegExecStatus(
                      node_segment_id,
                      (SegmentExecStatus::ExecStatus)exec_status, exec_info);
          LOG(INFO) << node_segment_id.first << " , " << node_segment_id.second
                    << " after receive: " << exec_status << " , " << exec_info;
          if (false == ret) {
            return make_message(CancelPlanAtom::value);
          }
          return make_message(OkAtom::value);
        },
        [=](HeartBeatAtom) {
          try {
            slave_node_->master_actor_ =
                caf::io::remote_actor(slave_node_->master_addr_.first,
                                      slave_node_->master_addr_.second);
            sync_send(slave_node_->master_actor_, HeartBeatAtom::value,
                      slave_node_->get_node_id(), slave_node_->node_addr_.first,
                      slave_node_->node_addr_.second)
                .then([=](OkAtom) { slave_node_->heartbeat_count_ = 0; },
                      [=](OkAtom, unsigned int node_id, const BaseNode& node) {
                        /*
                         * In this condition, master is down, and restart
                         * quickly.
                         * The slave node is still send heartbeat.
                         * master will give is a new id like reregister.
                         */
                        slave_node_->set_node_id(node_id);
                        Environment::getInstance()->setNodeID(node_id);
                        slave_node_->node_id_to_addr_.clear();
                        slave_node_->node_id_to_actor_.clear();
                        slave_node_->node_id_to_addr_.insert(
                            node.node_id_to_addr_.begin(),
                            node.node_id_to_addr_.end());
                        for (auto it = slave_node_->node_id_to_addr_.begin();
                             it != slave_node_->node_id_to_addr_.end(); ++it) {
                          auto actor =
                              remote_actor(it->second.first, it->second.second);
                          slave_node_->node_id_to_actor_.insert(
                              make_pair(it->first, actor));
                        }
                        LOG(INFO) << "register node succeed in heartbeart "
                                     "stage! insert "
                                  << node.node_id_to_addr_.size() << " nodes";
                        slave_node_->heartbeat_count_ = 0;
                        BlockManager::getInstance()->initialize();
                      });
          } catch (caf::network_error& e) {
            LOG(WARNING) << "node" << slave_node_->get_node_id()
                         << "can't send heartbeart to master" << endl;
          } catch (caf::bind_failure& e) {
            LOG(WARNING) << "node" << slave_node_->get_node_id()
                         << "occur bind failure" << endl;
          }
          slave_node_->heartbeat_count_++;
          if (slave_node_->heartbeat_count_ > kTimeout * 2) {
            // slave lost master.
            LOG(INFO) << "slave" << slave_node_->node_id_
                      << "lost heartbeat from master, start register again"
                      << endl;
            std::cout << "slave" << slave_node_->node_id_
                      << "lost heartbeat from master, start register again"
                      << endl;
            bool is_success = false;
            become(caf::keep_behavior, [=, &is_success](RegisterAtom) {
              auto ret = slave_node_->RegisterToMaster(false);
              if (ret == rSuccess) {
                LOG(INFO) << "reregister successfully , now the node id is "
                          << slave_node_->get_node_id() << endl;
                std::cout << "reregister successfully , now the node id is "
                          << slave_node_->get_node_id() << endl;
                // report storage message to new master
                BlockManager::getInstance()->initialize();
                is_success = true;
                unbecome();
              } else {
                // when slave Register fails,
                caf::scoped_actor self;
                delayed_send(this, std::chrono::seconds(kTimeout),
                             RegisterAtom::value);
                LOG(WARNING)
                    << "register fail, slave will register in 5 seconds"
                    << endl;
                std::cerr << "register fail, slave will register in 5 seconds"
                          << endl;
              }
            });
            if (!is_success) {
              caf::scoped_actor self;
              self->send(this, RegisterAtom::value);
            }
          }
          delayed_send(this, std::chrono::seconds(kTimeout / 5),
                       HeartBeatAtom::value);
        },
        [=](SyncNodeInfo, const BaseNode& node) {
          slave_node_->node_id_to_addr_.clear();
          slave_node_->node_id_to_actor_.clear();
          slave_node_->node_id_to_addr_.insert(node.node_id_to_addr_.begin(),
                                               node.node_id_to_addr_.end());
          for (auto it = slave_node_->node_id_to_addr_.begin();
               it != slave_node_->node_id_to_addr_.end(); ++it) {
            try {
              auto actor = remote_actor(it->second.first, it->second.second);
              slave_node_->node_id_to_actor_.insert(
                  make_pair(it->first, actor));
            } catch (caf::network_error& e) {
              LOG(WARNING) << "cann't connect to node ( " << it->first << " , "
                           << it->second.first << it->second.second
                           << " ) and create remote actor failed!!";
            }
          }
          LOG(INFO) << "node" << slave_node_->get_node_id()
                    << "update nodelist info successfully, now size is"
                    << slave_node_->node_id_to_addr_.size() << endl;
        },
        [=](OkAtom) {},
        caf::others >> [=]() {
                         LOG(WARNING) << "unknown message at slave node!!!"
                                      << endl;
                       }

    };
  }

  SlaveNode* slave_node_;
};

SlaveNode* SlaveNode::GetInstance() {
  if (NULL == instance_) {
    instance_ = new SlaveNode();
  }
  return instance_;
}
RetCode SlaveNode::AddOneNode(const unsigned int& node_id,
                              const string& node_ip,
                              const uint16_t& node_port) {
  lock_.acquire();
  RetCode ret = rSuccess;
  node_id_to_addr_.insert(make_pair(node_id, make_pair(node_ip, node_port)));
  try {
    auto actor = remote_actor(node_ip, node_port);
    node_id_to_actor_.insert(make_pair(node_id, actor));
  } catch (caf::network_error& e) {
    LOG(WARNING) << "cann't connect to node ( " << node_ip << " , " << node_port
                 << " ) and create remote actor failed!!";
    ret = rConRemoteActorError;
  }
  LOG(INFO) << "slave : get broadested node( " << node_id << " < " << node_ip
            << " " << node_port << " > )" << std::endl;
  lock_.release();
  return rSuccess;
}
SlaveNode::SlaveNode() : BaseNode() {
  instance_ = this;
  CreateActor();
}
SlaveNode::SlaveNode(string node_ip, uint16_t node_port)
    : BaseNode(node_ip, node_port) {
  instance_ = this;
  CreateActor();
}
SlaveNode::~SlaveNode() { instance_ = NULL; }
void SlaveNode::CreateActor() {
  auto slave_actor = caf::spawn<SlaveNodeActor>(this);
  bool is_done = false;

  for (int try_time = 0; try_time < 20 && !is_done; ++try_time) {
    try {
      master_actor_ =
          caf::io::remote_actor(master_addr_.first, master_addr_.second);
      is_done = true;
    } catch (caf::network_error& e) {
      cout << "slave node connect remote_actor error due to network "
              "error! will try " << 19 - try_time << " times" << endl;
    }
    sleep(1);
  }
  if (!is_done) {
    cout << "Node(" << get_node_ip() << " , " << get_node_port()
         << ") register to master(" << master_addr_.first << " , "
         << master_addr_.second
         << ") failed after have tried 20 times! please check ip and "
            "port, then try again!!!" << endl;
    LOG(ERROR) << "Node(" << get_node_ip() << " , " << get_node_port()
               << ") register to master(" << master_addr_.first << " , "
               << master_addr_.second
               << ") failed after have tried 20 times! please check ip and "
                  "port, then try again!!!" << endl;
    exit(0);
  } else {
    LOG(INFO) << "the node connect to master succeed!!!";
    cout << "the node connect to master succeed!!!" << endl;
  }
  try {
    caf::io::publish(slave_actor, get_node_port(), nullptr, 1);
    LOG(INFO) << "slave node publish port " << get_node_port()
              << " successfully!";
  } catch (caf::bind_failure& e) {
    LOG(ERROR) << "slave node binds port error when publishing";
  } catch (caf::network_error& e) {
    LOG(ERROR) << "slave node publish error due to network error!";
  }
}

RetCode SlaveNode::RegisterToMaster(bool isFirstRegister) {
  RetCode ret = rSuccess;
  caf::scoped_actor self;
  LOG(INFO) << "slave just RegisterToMaster!!" << endl;
  try {
    master_actor_ =
        caf::io::remote_actor(master_addr_.first, master_addr_.second);
    self->sync_send(master_actor_, RegisterAtom::value, get_node_ip(),
                    get_node_port())
        .await([=](OkAtom, const unsigned int& id, const BaseNode& node) {
                 set_node_id(id);
                 Environment::getInstance()->setNodeID(id);
                 heartbeat_count_ = 0;
                 node_id_to_addr_.clear();
                 node_id_to_actor_.clear();
                 node_id_to_addr_.insert(node.node_id_to_addr_.begin(),
                                         node.node_id_to_addr_.end());
                 for (auto it = node_id_to_addr_.begin();
                      it != node_id_to_addr_.end(); ++it) {
                   auto actor =
                       remote_actor(it->second.first, it->second.second);
                   node_id_to_actor_.insert(make_pair(it->first, actor));
                 }
                 LOG(INFO) << "register node succeed! insert "
                           << node.node_id_to_addr_.size() << " nodes";
                 if (isFirstRegister) {
                   caf::scoped_actor self1;
                   auto slave_self =
                       caf::io::remote_actor(get_node_ip(), get_node_port());
                   self1->send(slave_self, HeartBeatAtom::value);
                 }
               },
               [&](const caf::sync_exited_msg& msg) {
                 LOG(WARNING) << "register link fail";
               },
               caf::after(std::chrono::seconds(kTimeout)) >>
                   [&]() {
                     ret = rRegisterToMasterTimeOut;
                     LOG(WARNING) << "slave register timeout!";
                   });
  } catch (caf::network_error& e) {
    ret = rRegisterToMasterError;
    LOG(WARNING) << "cann't connect to " << master_addr_.first << " , "
                 << master_addr_.second << " in register";
  }
  return ret;
}
} /* namespace claims */

// RetCode SlaveNode::reRegisterToMaster() {
//  RetCode ret = rSuccess;
//  caf::scoped_actor self;
//  LOG(INFO)<<"slave reRegisterToMaster!!"<<endl;
//  try {
//    master_actor_=
//    caf::io::remote_actor(master_addr_.first,master_addr_.second);
//    self->sync_send(master_actor_, RegisterAtom::value, get_node_ip(),
//                    get_node_port())
//        .await([=](OkAtom, const unsigned int& id, const BaseNode& node) {
//                 set_node_id(id);
//                 Environment::getInstance()->setNodeID(id);
//                 heartbeat_count_ = 0;
//                 node_id_to_addr_.clear();
//                 node_id_to_actor_.clear();
//                 node_id_to_addr_.insert(node.node_id_to_addr_.begin(),
//                                         node.node_id_to_addr_.end());
//                 for (auto it = node_id_to_addr_.begin();
//                      it != node_id_to_addr_.end(); ++it) {
//                   auto actor =
//                       remote_actor(it->second.first, it->second.second);
//                   node_id_to_actor_.insert(make_pair(it->first, actor));
//                 }
//                 LOG(INFO) << "register node succeed! insert "
//                           << node.node_id_to_addr_.size() << " nodes";
//               },
//               [&](const caf::sync_exited_msg& msg) {
//                 LOG(WARNING) << "register link fail";
//               },
//               caf::after(std::chrono::seconds(kTimeout)) >>
//                   [&]() {
//                     ret = rRegisterToMasterTimeOut;
//                     LOG(WARNING) << "slave register timeout!";
//                   });
//  } catch (caf::network_error& e) {
//    ret = rRegisterToMasterError;
//    LOG(WARNING) << "cann't connect to " << master_addr_.first << " , "
//                 << master_addr_.second << " in register";
//  }
//  return ret;
//}
