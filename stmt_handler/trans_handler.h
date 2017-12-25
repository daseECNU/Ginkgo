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
 * /Claims/transam/transaction.h
 *
 *  Created on: Nov 18, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#ifndef TRANS_HANDLER_TRANS_HANDLER_H_
#define TRANS_HANDLER_TRANS_HANDLER_H_

#include <string>
#include <vector>
#include "../stmt_handler/stmt_handler.h"
#include "../common/error_define.h"
#include "../common/data_type.h"
#include "../catalog/catalog.h"

using claims::stmt_handler::StmtHandler;
namespace claims {
namespace trans_handler {
class TransHandler {
  enum TransBlockStatu { Default, Begin, Abort, Commit };

 public:
  TransHandler(string sql_stmt, int socket_fd);
  virtual ~TransHandler();

  RetCode Execute();

  RetCode InitTransactionBlock(ExecutedResult result);

  RetCode StartTransactionCommand(ExecutedResult result);
  RetCode CommitTransactionBlock();
  RetCode AbortTransactionBlock();
  RetCode Snapshot();

  void UnlockAllWriteTables();

  void UnlockAllReadTables();

 private:
  StmtHandler* stmt_handler_;
  TransBlockStatu trans_block_status_ = Default;
  int socket_fd_;
  string sql_stmt_;

  /* @param stmt_to_table_list_ Collect the information about the list of tables
   to be executed. Pair<int, string> is used to collect the information about
   the list of tables of one statement. The first param of pair is operation
   status(0 is read, 1 is write,2 is drop,3 is null). The second param record
   the table name;
   */
  vector<vector<pair<int, string>>> stmt_to_table_list_;
  vector<string> wlock_tables_;
  vector<string> rlock_tables_;
  vector<TableDescriptor> tables_backup_;
};
}  // namespace trans_handler
}  // namespace claims
#endif  //  TRANS_HANDLER_TRANS_HANDLER_H_
