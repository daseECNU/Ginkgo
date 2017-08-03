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

  SemanticContext sem_cnxt;
  ret = truncate_table_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->error_info_ =
        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    exec_result->status_ = false;
    LOG(WARNING) << "semantic analysis error result= : " << ret;
    return ret;
  }
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  AstDropTableList* table_list =
      dynamic_cast<AstDropTableList*>(truncate_table_ast_->table_list_);
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
      exec_result->info_ = "truncated table successfully!";
    } else {
      exec_result->error_info_ = "truncated table [" + table_name + "] failed.";
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      return ret;
    }
    table_list = dynamic_cast<AstDropTableList*>(table_list->next_);
  }
  local_catalog->saveCatalog();
  exec_result->status_ = true;
  exec_result->result_ = NULL;
  return ret;
}

/**
 * @brief
 * truncate the table based on the provided table name,
 * this operator will truncate the table in the catalog as well as the table
 * file on the disk or hdfs
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
 * delete the data information of table in catalog and unbind the projection
 * bound to Slave Node
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::TruncateTableFromCatalog(const string& table_name) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  ret = local_catalog->TruncateTable(table_name);
  return ret;
}

} /* namespace stmt_handler */
} /* namespace claims */
