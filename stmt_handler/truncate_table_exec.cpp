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
 * /CLAIMS/stmt_handler/ast_truncate_stmt.h
 *
 *  Created on: Jun 13, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <assert.h>  // NOLINT

#include "../catalog/catalog.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/error_define.h"
#include "../Config.h"
#include "../Environment.h"
#include "../loader/data_injector.h"
#include "../loader/table_file_connector.h"
#include "../stmt_handler/truncate_table_exec.h"
using claims::common::FilePlatform;
using claims::common::rFailure;
using claims::loader::TableFileConnector;
using claims::catalog::Catalog;
using std::vector;

namespace claims {
namespace stmt_handler {

TruncateTableExec::TruncateTableExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  truncate_table_ast_ = dynamic_cast<AstTruncateTable*>(stmt_);
}

TruncateTableExec::~TruncateTableExec() {}

RetCode TruncateTableExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;

  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  AstDropTableList* table_list =
      dynamic_cast<AstDropTableList*>(truncate_table_ast_->table_list_);

  // truncate all projections of the table;
  while (NULL != table_list) {
    string table_name = table_list->table_name_;
    if (table_name != "") {  // if the table_name is null, then
                             // go to the next element of the
                             // table_list_
      // to make consistency, truncate the table_del first, and then the table
      if (DropTableExec::CheckBaseTbl(table_name)) {
        if (TruncateTable(table_name + "_DEL") == rSuccess) {
          LOG(INFO) << table_name + "_DEL is truncated from this database!"
                    << endl;
        } else {
          LOG(ERROR) << "execution failed for truncating " + table_name +
                            "_DEL !" << endl;
        }
        if (TruncateTable(table_name) == rSuccess) {
          LOG(INFO) << table_name + " is truncated from this database!" << endl;
        } else {
          LOG(ERROR) << "execution failed for truncating " + table_name +
                            "_DEL !" << endl;
        }
      } else {  // truncate the table_del only
        ret = TruncateTable(table_name);
        LOG(INFO) << table_name + " is truncated from this database!" << endl;
      }
    }
    if (ret == rSuccess) {
      exec_result->info_ = "truncated all projections of the table [" +
                           table_name + "] successfully!";
    } else {
      exec_result->error_info_ =
          "truncated all projections of the table [" + table_name + "] failed.";
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      return ret;
    }
    table_list = dynamic_cast<AstDropTableList*>(table_list->next_);
  }

  // truncate particular projection of the table;
  string table_name = truncate_table_ast_->table_name_;
  int projection_id = truncate_table_ast_->projection_id_;
  if (table_name != "" && projection_id != "") {
    string proj_id = std::to_string(projection_id);
    if (DropTableExec::CheckBaseTbl(table_name)) {
      ret = TruncateProjection(table_name + "_DEL", projection_id);
      if (ret == rSuccess) {
        LOG(INFO) << "the projection [" + proj_id + "] of [" + table_name +
                         "_DEL] is truncated from this database!" << endl;
      } else {
        LOG(ERROR) << "execution failed for truncating the [projection " +
                          proj_id + "] of [" + table_name + "_DEL] !" << endl;
      }
      ret = TruncateProjection(table_name, projection_id);
      if (ret == rSuccess) {
        LOG(INFO) << "the projection [" + proj_id + "] of [" + table_name +
                         "] is truncated from this database!" << endl;
      } else {
        LOG(ERROR) << "execution failed for truncating the projection [" +
                          proj_id + "] of [" + table_name + "]!" << endl;
      }
    } else {
      LOG(ERROR)
          << table_name +
                 " is DEL table! This operator is only aimed at base table!"
          << endl;
      ret = rFailure;
    }
    if (ret == rSuccess) {
      exec_result->info_ = "truncated the projection [" + proj_id +
                           "] of the table [" + table_name + "] successfully!";
    } else {
      exec_result->error_info_ = "truncated the projection [" + proj_id +
                                 "] of the table[" + table_name + "] failed.";
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      return ret;
    }
  }
  exec_result->status_ = true;
  exec_result->result_ = NULL;
  return ret;
}

/**
 * @brief
 * truncate all projections of the table from the catalog and delete the
 * associated files in the disk or in the hdfs
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::TruncateTable(const string& table_name) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  // start to truncate table
  // delete the file first, and then truncate the information in the catalog
  ret = DropTableExec::DeleteTableFiles(table_name);
  if (rSuccess != ret) {
    ELOG(ret, "failed to delete the files when truncating table " + table_name);
    return ret;
  } else {
    ret = TruncateTableFromCatalog(table_name);
    if (ret != rSuccess) {
      ELOG(ret,
           "failed to truncate the table from the catalog, while its files "
           "have been deleted, when truncating table" +
               table_name);
      return ret;
    }
  }
  return ret;
}

/**
 * @brief
 * delete the data information of table in catalog and unbind the
 * projection bound to Slave Node
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::TruncateTableFromCatalog(const string& table_name) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  ret = local_catalog->truncateTable(table_name);
  return ret;
}

RetCode TruncateTableExec::GetWriteAndReadTables(
    ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  SemanticContext sem_cnxt;
  ret = truncate_table_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    result.error_info_ = "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    result.status_ = false;
    LOG(WARNING) << "semantic analysis error result= : " << ret;
    return ret;
  } else {
    vector<string> ori_tables = sem_cnxt.GetOriTables();
    for (auto str : ori_tables) {
      table_status.first = 2;
      table_status.second = str;
    }
    table_list.push_back(table_status);
    stmt_to_table_list.push_back(table_list);
    return ret;
  }
}

RetCode TruncateTableExec::TruncateProjection(const string& table_name,
                                              const int& projection_id) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  // start to truncate projection
  // delete the files first, and then truncate the relative information in the
  // catalog
  string proj_id = std::to_string(projection_id);
  ret = DropTableExec::DeleteProjectionFiles(table_name, proj_id);
  if (rSuccess != ret) {
    ELOG(ret, "failed to delete the files when truncating table " + table_name);
    return ret;
  } else {
    ret = TruncateProjectionFromCatalog(table_name, projection_id);
    if (ret != rSuccess) {
      ELOG(ret,
           "failed to truncate the table from the catalog, while its files "
           "have been deleted, when truncating table" +
               table_name);
      return ret;
    }
  }
  return ret;
}

RetCode TruncateTableExec::TruncateProjectionFromCatalog(
    const string& table_name, const int& proj_id) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  ret = local_catalog->truncateProjection(table_name, proj_id);
  return ret;
}

} /* namespace stmt_handler */
} /* namespace claims */
