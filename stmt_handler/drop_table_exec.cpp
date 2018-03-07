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
 * /CLAIMS/stmt_handler/drop_table_exec.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: yuyang
 *		   Email: youngfish93@hotmail.com
 *
 * 	Modified on : Aug 8, 2017
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
#include "../stmt_handler/drop_table_exec.h"
using claims::common::rFailure;
using claims::common::FilePlatform;
using claims::loader::TableFileConnector;
using claims::catalog::Catalog;
using std::vector;
using claims::common::rNULLDropTableName;
namespace claims {
namespace stmt_handler {

DropTableExec::DropTableExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  drop_table_ast_ = dynamic_cast<AstDropTable*>(stmt_);
}

DropTableExec::~DropTableExec() {}

RetCode DropTableExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;

  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  AstDropTableList* table_list =
      dynamic_cast<AstDropTableList*>(drop_table_ast_->table_list_);
  while (NULL != table_list) {
    string table_name;
    if ("" != table_list->table_name_) {  // if the table_name is null, then
                                          // go to the next element of the
                                          // table_list_
      // to make consistency, drop the del table first, and then the base table
      table_name = table_list->table_name_;
      if (CheckBaseTbl(table_name)) {  // drop the base table
        ret = DropTable(table_name);
        if (ret == rSuccess) {
          LOG(INFO) << table_name + " is dropped from this database!" << endl;
          ret = DropTable(table_name + "_DEL");
          LOG(INFO) << table_name + "_DEL is dropped from this database!"
                    << endl;
        } else {
          LOG(ERROR) << "drop " << table_name + " failure!" << endl;
          return ret;
        }
      } else {  // drop the del table only, but the information in the catalog
                // does not need to be removed
        ret = DeleteTableFiles(table_name);
        // todo (miqni 2016.1.28) to delete the del table from memory
        // free table from memory(_pool)
        FreeTableFromMemory(table_name);
        LOG(INFO) << table_name + " is dropped from this database!" << endl;
      }

      if (ret == rSuccess) {
        exec_result->info_ = "drop table successfully!";
      } else {
        exec_result->error_info_ = "drop table [" + table_name + "] failed.";
        exec_result->status_ = false;
        exec_result->result_ = NULL;
        return ret;
      }
    }
    table_list = dynamic_cast<AstDropTableList*>(table_list->next_);
  }
  exec_result->status_ = true;
  exec_result->result_ = NULL;
  return ret;
}

static bool DropTableExec::CheckBaseTbl(const string& table_name) {
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  string base_tbl_name = "";
  // if the length of the table name is less than 4, it should be the name of
  // the base table.
  if ("" != table_name && table_name.size() < 4) {
    return true;
  }
  if ("_DEL" == table_name.substr(table_name.size() - 4, 4)) {
    base_tbl_name = table_name.substr(0, table_name.size() - 4);
    if (NULL != local_catalog->getTable(base_tbl_name)) {
      return false;
    } else {
      return true;
    }
  } else {
    if (NULL != local_catalog->getTable(table_name + "_DEL")) {
      return true;
    } else {
      return false;
    }
  }
}

/**
 * @brief drop the table based on the provided table name, this operator will
 * delete the table in the catalog as well as the table file on the disk or
 * hdfs.
 * @param table_name
 * @return
 */
RetCode DropTableExec::DropTable(const string& table_name) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  if ("" == table_name) {
    ret = rNULLDropTableName;
    WLOG(ret, "the name of the table to be dropped is NULL");
    return ret;
  }
  // start to drop table
  // you need to delete the file first. and then unbind the partition in slave
  // node. in the end, drop the information in the catalog
  ret = DeleteTableFiles(table_name);
  if (ret == rSuccess) {
    if (FreeTableFromMemory(table_name)) {
      ret = DropTableFromCatalog(table_name);
      if (ret != rSuccess) {
        ELOG(ret,
             "failed to drop the table from the catalog, while its files have "
             "been deleted, when dropping table " +
                 table_name);
        return ret;
      }
      return ret;
    } else {
      ELOG(ret, "failed to delete the table from memory when dropping table " +
                    table_name);
      return rFailure;
    }
  } else {
    ELOG(ret, "failed to delete the file when dropping table " + table_name);
    return rFailure;
  }
}

/**
 * @brief drop the table information from the catalog as well as to delete the
 * object of the TableDescroptor of the table_anme
 * @param table_name
 * @return
 */
RetCode DropTableExec::DropTableFromCatalog(const string& table_name) {
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  local_catalog->dropTable(table_name, table_desc->get_table_id());
  delete table_desc;
  return rSuccess;
}

/**
 * @brief delete the file associated with the Table table_name only
 * @param table_name
 * @return
 */
static RetCode DropTableExec::DeleteTableFiles(const string& table_name) {
  RetCode ret = rSuccess;
  // start to delete the files
  TableDescriptor* table =
      Environment::getInstance()->getCatalog()->getTable(table_name);
  if (table != NULL) {
    if (!table->GetProjectionList()->empty()) {
      TableFileConnector* connector = new TableFileConnector(
          Config::local_disk_mode ? FilePlatform::kDisk : FilePlatform::kHdfs,
          table, common::kReadFile);
      EXEC_AND_RETURN_ERROR(ret, connector->DeleteAllTableFiles(),
                            "failed to delete all the projections, when delete "
                            "the file on table " +
                                table_name);
      delete connector;
      return ret;
    } else {
      ELOG(rFailure, "failed to drop table '" + table_name +
                         "' files, cause its projections is null");
      return rFailure;
    }
  } else {
    ELOG(rFailure, "failed to drop table '" + table_name +
                       "' files, cannot find the table in catalog");
    return rFailure;
  }
}

/**
 * @brief delete one projection of the table files from the stroage
 * @param table_name, projection_id
 * @author zyhe
 * @return
 */
static RetCode DropTableExec::DeleteProjectionFiles(const string& table_name,
                                                    const string& proj_id) {
  RetCode ret = rSuccess;
  TableDescriptor* table =
      Environment::getInstance()->getCatalog()->getTable(table_name);
  if (!table->GetProjectionList()->empty()) {
    TableFileConnector* connector = new TableFileConnector(
        Config::local_disk_mode ? FilePlatform::kDisk : FilePlatform::kHdfs,
        table, common::kReadFile);
    EXEC_AND_RETURN_ERROR(ret, connector->DeleteOneProjectionFiles(proj_id),
                          "failed to delete the projection [" + proj_id +
                              "] when delete the file on table [" + table_name +
                              "]");
    delete connector;
  }
  return ret;
}

/**
 * @brief call the UnbindingEntireProjection() function to free the memory in
 * the memory pool. The memory return to the memory pool rather than return to
 * the operating system directly. It causes when you apply the memory next
 * time thread will use the memory pool first.
 * @param table_name
 * @author zyhe
 * @return
 */
static bool DropTableExec::FreeTableFromMemory(const string& table_name) {
  if (table_name != "") {
    Catalog* local_catalog = Environment::getInstance()->getCatalog();
    TableDescriptor* table_desc = local_catalog->getTable(table_name);
    if (table_desc != NULL) {
      vector<ProjectionDescriptor*>* projection_list =
          table_desc->GetProjectionList();
      if (!projection_list->empty()) {
        for (auto projection : *projection_list) {
          Partitioner* partitioner = projection->getPartitioner();
          bool res = Catalog::getInstance()
                         ->getBindingModele()
                         ->UnbindingEntireProjection(partitioner);
          if (res) {
            LOG(INFO) << "unbind entire projection ["
                      << partitioner->getProejctionID().projection_off
                      << "] in table [" << table_desc->getTableName() << "]"
                      << std::endl;
          } else {
            LOG(ERROR) << "failed to unbind entire projection ["
                       << partitioner->getProejctionID().projection_off
                       << "] in table [" << table_desc->getTableName() << "]"
                       << std::endl;
            return false;
          }
        }
      }
    }
  }
  return true;
}
RetCode DropTableExec::GetWriteAndReadTables(
    ExecutedResult& result,
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  SemanticContext sem_cnxt;
  ret = drop_table_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    result.error_info_ = "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    result.status_ = false;
    LOG(WARNING) << "semantic analysis error result= : " << ret;
    return ret;
  } else {
    AstDropTableList* drop_list =
        reinterpret_cast<AstDropTableList*>(drop_table_ast_->table_list_);
    table_status.first = 2;
    table_status.second = drop_list->table_name_;
    table_list.push_back(table_status);
    while (drop_list->next_ != NULL) {
      drop_list = reinterpret_cast<AstDropTableList*>(drop_list->next_);
      table_status.first = 2;
      table_status.second = drop_list->table_name_;
      table_list.push_back(table_status);
    }
    stmt_to_table_list.push_back(table_list);
    return ret;
  }
}
} /* namespace stmt_handler */
} /* namespace claims */
