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
#include "./zk_connector.h"
#include "../Config.h"
namespace claims{
namespace common{
void zktest_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
        {
                LOG(INFO)<<"Something happened."<<endl;
                LOG(INFO)<<"type: "<<type<<endl;
                LOG(INFO)<<"state: "<< state<<endl;
                LOG(INFO)<<"path: "<< path<<endl;
                LOG(INFO)<<"watcherCtx: " << (char *)watcherCtx<<endl;
        }
void zk_wexists_watcher(zhandle_t *zh,int type,int state,const char *path,void *watcherCtx)
        {
                LOG(INFO)<<"just for testing zk_connector.h:63"<<endl;
        }

zhandle_t* ZkConnector::zh_ = NULL;
char* ZkConnector::host = "";
int ZkConnector::timeout = 30000;
}
}
