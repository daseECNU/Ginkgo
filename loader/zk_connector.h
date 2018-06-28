/*
 * Copyright [2012-2017] DaSE@ECNU
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
 * /Claims/common/file_handle/HdfsConnector.h
 *
 *  Created on: May 26, 2017
 *      Author: huangchengsheng
 *                 Email: 285649461@qq.com
 *
 * Description:
 *
 */


#ifndef LOADER_ZK_CONNECTOR_H_
#define LOADER_ZK_CONNECTOR_H_

#include "../../Config.h"
#include <glog/logging.h>
#include"zookeeper.h"
#include "../../Config.h"
#include "../../common/rename.h"

using namespace std;
namespace claims{
namespace common{
void zktest_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx);

void zk_wexists_watcher(zhandle_t *zh,int type,int state,const char *path,void *watcherCtx);

class ZkConnector{
public:
        static zhandle_t* Instance(){
                if(NULL == zh_){
                        LOG(INFO) << "create the connection to ZkServer"<<endl;
                        Config::getInstance();
                        watcher_fn test =zktest_watcher_g;
                        host = Config::zookeeper_host_list.data();
                        zh_ = zookeeper_init(host,test, timeout, 0, (void*) "hello zookeeper.", 0);
                        LOG(INFO)<<"host is :"<<host<<endl;
                        sleep(2);
                        if (zoo_state(zh_)!= ZOO_CONNECTED_STATE){
                                LOG(INFO) << "Error when connecting to zookeeper servers..."<<endl;
                                assert(false);
                        }
                        LOG(INFO)<<"connected to Zookeeper "<<endl;

                }
                return zh_;
        }
        NO_COPY_AND_ASSIGN(ZkConnector);
        ~ZkConnector(){
                        zookeeper_close(zh_);
                        zh_ = NULL;
                }


        private :
                static char* host;
                static int timeout;


                ZkConnector(){}
                static zhandle_t* zh_ ;
        };
        }
        }

        #endif

