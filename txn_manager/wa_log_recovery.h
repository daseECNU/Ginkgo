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
 * /CLAIMS/txn_manager/recovery.hpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */

#ifndef TXN_MANAGER_WA_LOG_RECOVERY_H_
#define TXN_MANAGER_WA_LOG_RECOVERY_H_

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <memory>
#include <iostream>
#include "../txn_manager/txn.hpp"
using std::shared_ptr;
using std::make_shared;
using std::unordered_set;
namespace ginkgo {
namespace txn {

class LogRecovery {
 public:
  static shared_ptr<TxnState> GetTxnState(
      const unordered_set<UInt64> &part_list);
  // static RedoBeginLog
};
}
}

#endif  //  TXN_MANAGER_WA_LOG_RECOVERY_H_
