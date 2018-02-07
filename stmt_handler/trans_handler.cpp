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
 * /Ginkgo/stmt_handler/trans_handler.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#include <boost/algorithm/string.hpp>
#include "../stmt_handler/trans_handler.h"
#include "../catalog/catalog.h"
#include "../catalog/table.h"

using claims::stmt_handler::StmtHandler;
using claims::common::rFailure;
using boost::algorithm::trim;

namespace claims {
namespace trans_handler {
TransHandler::TransHandler(string sql_stmt, int socket_fd)
    : sql_stmt_(sql_stmt), socket_fd_(socket_fd), tables_backup_(NULL) {
  stmt_handler_ = new StmtHandler(sql_stmt_);
}
TransHandler::~TransHandler() {
  if (stmt_handler_ != NULL) delete stmt_handler_;
}

RetCode TransHandler::Execute() {
  RetCode ret = rSuccess;
  ExecutedResult result;
  result.fd_ = socket_fd_;
  result.status_ = true;
  bool first_write = true;
  EXEC_AND_RETURN_ERROR(ret, InitTransactionBlock(result),
                        "failed to initTransactionBlock");
  trans_block_status_ = Begin;
  for (int i = 0; i < stmt_to_table_list_.size(); ++i) {
    auto beg = stmt_to_table_list_[i].begin();
    auto end = stmt_to_table_list_[i].end();
    while (beg != end) {
      TableDescriptor* table = Catalog::getInstance()->getTable((*beg).second);
      if (table != NULL) {
        if ((*beg).first == 0) {
          if (table->rLock()) rlock_tables_.push_back((*beg).second);
        } else if ((*beg).first == 1) {
          if (table->wLock()) {
            if (first_write) {
              Snapshot();
              first_write = false;
            }
            wlock_tables_.push_back((*beg).second);
          }
        } else if ((*beg).first == 2) {
          table->wLock();
        }
      }
      ++beg;
    }
    ret = StartTransactionCommand(result);
    UnlockAllReadTables();
    if (rSuccess != ret) {
      trans_block_status_ = Abort;
      break;
    }
  }
  if (trans_block_status_ != Abort) {
    trans_block_status_ = Commit;
  }
  switch (trans_block_status_) {
    case Commit: {
      CommitTransactionBlock();
      UnlockAllWriteTables();
      cout << "Transaction Commit" << endl;
      break;
    }
    case Abort: {
      AbortTransactionBlock();
      UnlockAllWriteTables();
      cout << "Transaction Abort" << endl;

      break;
    }
  }
  return ret;
}
void TransHandler::UnlockAllReadTables() {
  if (rlock_tables_.size() != 0) {
    auto beg = rlock_tables_.begin();
    while (beg != rlock_tables_.end()) {
      Catalog::getInstance()->getTable(*beg)->unwrLock();
      ++beg;
    }
    rlock_tables_.clear();
  }
}
void TransHandler::UnlockAllWriteTables() {
  if (wlock_tables_.size() != 0) {
    auto beg = wlock_tables_.begin();
    while (beg != wlock_tables_.end()) {
      Catalog::getInstance()->getTable(*beg)->unwrLock();
      ++beg;
    }
    wlock_tables_.clear();
  }
}
RetCode TransHandler::InitTransactionBlock(ExecutedResult result) {
  RetCode ret = rSuccess;
  trans_block_status_ = Begin;
  trim(sql_stmt_);
  EXEC_AND_RETURN_ERROR(ret, stmt_handler_->StmtParser(result),
                        "failed to parser");
  EXEC_AND_RETURN_ERROR(
      ret, stmt_handler_->StmtContentAnalysis(result, stmt_to_table_list_),
      "failed to analyze content");
  return ret;
}
RetCode TransHandler::StartTransactionCommand(ExecutedResult result) {
  RetCode ret = rSuccess;
  if (trans_block_status_ == Begin) {
    EXEC_AND_RETURN_ERROR(ret, stmt_handler_->Execute(result),
                          "failed to execute");
  } else {
    LOG(ERROR) << "In StartTransactionCommand, the status of transaction error"
               << endl;
    return rFailure;
  }
  return ret;
}

RetCode TransHandler::AbortTransactionBlock() {
  if (tables_backup_.size() != 0) {
    auto beg = tables_backup_.begin();
    while (beg != tables_backup_.end()) {
      TableDescriptor* table =
          Catalog::getInstance()->getTable((*beg).getTableName());
      table = &(*beg);
      table->TruncateFilesFromTable();
      ++beg;
    }
  }
  return rSuccess;
}

RetCode TransHandler::CommitTransactionBlock() {
  Catalog::getInstance()->saveCatalog();
  return rSuccess;
}

RetCode TransHandler::Snapshot() {
  if (wlock_tables_.size() != 0) {
    auto beg = wlock_tables_.begin();
    while (beg != wlock_tables_.end()) {
      TableDescriptor table = *(Catalog::getInstance()->getTable(*beg));
      tables_backup_.push_back(table);
      ++beg;
    }
  }
  return rSuccess;
}

}  // namespace trans_handler
}  // namespace claims
