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
 * /CLAIMS/stmt_handler/drop_proj_exec.cpp
 *
 *  Created on: Aug 6, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
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
#include "../stmt_handler/drop_proj_exec.h"

using claims::common::rFailure;
using claims::common::FilePlatform;
using claims::loader::TableFileConnector;
using claims::catalog::Catalog;
using std::vector;

namespace claims {
namespace stmt_handler {
DropProjExec::DropProjExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  drop_proj_ast_ = dynamic_cast<AstDropProjection*>(stmt_);
}

DropProjExec::~DropProjExec() {}

RetCode DropProjExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;

  SemanticContext sem_cnxt;
  ret = drop_proj_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->error_info_ =
        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    exec_result->status_ = false;
    LOG(WARNING) << "semantic analysis error result= : " << ret;
    return ret;
  }

  string table_name = drop_proj_ast_->table_name_;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);

  // Drop all projections
  if (drop_proj_ast_->is_all_ == true) {
    if (DropTableExec::CheckBaseTbl(table_name)) {
      // Drop all projections of the del table first, and then the base table
      ret = DropAllProj(table_name + "_DEL");
      if (ret == rSuccess) {
        LOG(INFO) << "all projections of " + table_name +
                         "_DEL is dropped from this database!" << endl;
        ret = DropAllProj(table_name);
        LOG(INFO) << "all projections of " + table_name +
                         " is dropped from this database!" << endl;
      } else {
        LOG(ERROR) << "execution failed for dropping all projections of " +
                          table_name << endl;
      }
    } else {
      LOG(ERROR)
          << table_name +
                 " is DEL table! This operation is only aimed at base table!"
          << endl;
      ret = rFailure;
    }
    if (ret == rSuccess) {
      exec_result->info_ = "drop all projections successfully!";
    } else {
      exec_result->error_info_ =
          "drop all projections of  [" + table_name + "] failed.";
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      return ret;
    }
  }
  // Only drop one projection of a table.
  else {
    string proj_id = std::to_string(drop_proj_ast_->projection_id_);
    int projection_id = drop_proj_ast_->projection_id_;
    if (DropTableExec::CheckBaseTbl(table_name)) {  // drop the base table
      ret = DropOneProj(table_name + "_DEL", projection_id);
      if (ret == rSuccess) {
        LOG(INFO) << "the projection [" + proj_id + "] of " + table_name +
                         "_DEL is dropped from this database!" << endl;
        ret = DropOneProj(table_name, projection_id);
        LOG(INFO) << "the projection [" + proj_id + "] of " + table_name +
                         " is dropped from this database!" << endl;
      } else {
        LOG(ERROR) << "execution failed for dropping projection [" + proj_id +
                          "] of table [" + table_name + "]" << endl;
      }
    } else {
      LOG(ERROR)
          << table_name +
                 " is DEL table! This operator is only aimed at base table!"
          << endl;
      ret = rFailure;
    }
    if (ret == rSuccess) {
      exec_result->info_ = "drop projection [" + proj_id + "] of table [" +
                           table_name + "] successfully!";
    } else {
      exec_result->error_info_ =
          "drop projection [" + proj_id + "] of [" + table_name + "] failed.";
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      return ret;
    }
  }
  exec_result->status_ = true;
  exec_result->result_ = NULL;
  return ret;
}

/* drop all projections of table */
RetCode DropProjExec::DropAllProj(const string& table_name) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  // Start to drop all projections.
  // You need to delete all the files of projections first, and then free the
  // memories which are used by projections. In the end, drop information in
  // the catalog.
  ret = DropTableExec::DeleteTableFiles(table_name);
  if (ret == rSuccess) {
    // Unbind all projections with slave nodes
    if (DropTableExec::FreeTableFromMemory(table_name)) {
      ret = DropAllProjFromCatalog(table_name);
      if (ret != rSuccess) {
        ELOG(ret, "failed to drop all projections of " + table_name +
                      " from the catalog");
        return ret;
      }
    } else {
      ELOG(ret,
           "failed to unbind projections from memory when "
           "dropping all projections of the table " +
               table_name);
      return rFailure;
    }
  } else {
    return ret;
  }
}

/* Drop all projections of table from Catalog */
RetCode DropProjExec::DropAllProjFromCatalog(const string& table_name) {
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  if (local_catalog->dropAllProjection(table_name)) {
    LOG(INFO) << "drop all projections "
              << "of [" + table_name + "] from catalog success! " << endl;
    return rSuccess;
  } else {
    return rFailure;
  }
}

/* Drop one projection of table */
RetCode DropProjExec::DropOneProj(const string& table_name,
                                  const int& projection_id) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  // Start to drop one projection:
  // You need to delete files of the projection first, and then free the
  // memory which are used by projection. In the end, drop information in
  // the catalog.
  string proj_id = std::to_string(projection_id);
  ret = DropTableExec::DeleteProjectionFiles(table_name, proj_id);
  if (ret == rSuccess) {
    // unbind the projection with slave node;
    if (FreeProjectionFromMemory(table_name, projection_id)) {
      ret = DropOneProjFromCatalog(table_name, projection_id);
      if (ret != rSuccess) {
        ELOG(ret, "failed to drop projection [" + proj_id + "] of [" +
                      table_name + "] from the catalog");
        return ret;
      }
    } else {
      ELOG(
          ret,
          "failed to unbind projection from memory when dropping projection [" +
              proj_id + "] of the table [" + table_name + "]");
      return rFailure;
    }
    return ret;
  } else {
    return ret;
  }
}

/* Drop one projections of table from Catalog */
RetCode DropProjExec::DropOneProjFromCatalog(const string& table_name,
                                             const int& projection_id) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  if (local_catalog->dropOneProjection(table_name, projection_id)) {
    LOG(INFO) << "drop projection[" << projection_id
              << "] of [" + table_name + "] from catalog success! " << endl;
    return rSuccess;
  } else {
    return rFailure;
  }
}

/* This function only frees one projection of the table */
bool DropProjExec::FreeProjectionFromMemory(const string& table_name,
                                            const int& proj_id) {
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name);
  if (table_desc != NULL) {
    vector<ProjectionDescriptor*>* projection_list =
        table_desc->GetProjectionList();
    if (projection_list != NULL) {
      for (auto projection : *projection_list) {
        Partitioner* partitioner = projection->getPartitioner();
        if (proj_id == partitioner->getProejctionID().projection_off) {
          bool res = Catalog::getInstance()
                         ->getBindingModele()
                         ->UnbindingEntireProjection(partitioner);
          if (res) {
            LOG(INFO) << "unbind entire projection [" << proj_id
                      << "] in table [" << table_desc->getTableName() << "]"
                      << std::endl;
          } else {
            LOG(ERROR) << "failed to unbind entire projection [" << proj_id
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

RetCode DropProjExec::GetWriteAndReadTables(
    vector<vector<pair<int, string>>>& stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  table_status.first = 1;
  table_status.second = drop_proj_ast_->table_name_;
  table_list.push_back(table_status);
  stmt_to_table_list.push_back(table_list);
  return ret;
}
} /* namespace stmt_handler */
} /* namespace claims */
