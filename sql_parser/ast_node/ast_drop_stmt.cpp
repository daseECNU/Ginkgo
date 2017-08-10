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
 *  /sql_parser/astnode/ast_drop_stmt.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: yuyang
 *       Email: youngfish93@hotmail.com
 */

#include "../ast_node/ast_drop_stmt.h"

#include <glog/logging.h>
#include <iostream>  //  NOLINT
#include <iomanip>
#include <string>
#include <bitset>

#include "../../catalog/catalog.h"
#include "../../catalog/table.h"
#include "../../Environment.h"
#include "../../common/error_define.h"
using namespace claims::common;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::bitset;

// namespace claims {
// namespace sql_parser {

AstDropIndex::AstDropIndex(AstNodeType ast_node_type, string index_name,
                           string table_name)
    : AstNode(ast_node_type),
      index_name_(index_name),
      table_name_(table_name) {}

AstDropIndex::~AstDropIndex() {}

void AstDropIndex::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Drop Index|" << endl;
}

AstDropDatabase::AstDropDatabase(AstNodeType ast_node_type, int drop_type,
                                 int check, string db_name)
    : AstNode(ast_node_type),
      db_name_(db_name),
      drop_type_(drop_type),
      check_(check) {}

AstDropDatabase::~AstDropDatabase() {}

void AstDropDatabase::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Drop Database|" << endl;
}

AstDropTable::AstDropTable(AstNodeType ast_node_type, int is_temp, int is_check,
                           int opt_rc, AstNode* table_list)
    : AstNode(ast_node_type),
      is_temporary_(is_temp),
      is_if_exists_(is_check),
      option_rc_(opt_rc),
      table_list_(table_list) {}

AstDropTable::~AstDropTable() { delete table_list_; }
RetCode AstDropTable::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;

  if (NULL != table_list_) {
    ret = table_list_->SemanticAnalisys(sem_cnxt);
  } else {
    LOG(ERROR) << "No table found or invalid table name.";
    sem_cnxt->error_msg_ = "No table found or invalid table name.";
    ret = rNoTalbeFound;
  }
  return ret;
}

void AstDropTable::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Drop Table|" << endl;
  if (table_list_ != NULL) {
    cout << setw(++level * TAB_SIZE) << " "
         << "|Table List|" << endl;
    table_list_->Print(level);
  }
}

AstDropTableList::AstDropTableList(AstNodeType ast_node_type, string db_name,
                                   string table_name, AstNode* next)
    : AstNode(ast_node_type),
      db_name_(db_name),
      table_name_(table_name),
      next_(next) {}

AstDropTableList::~AstDropTableList() { delete next_; }

void AstDropTableList::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " " << table_name_ << endl;
  if (next_ != NULL) {
    next_->Print(level);
  }
}
RetCode AstDropTableList::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name_);
  if ("" == table_name_) {
    LOG(ERROR) << "No table name or invalid name during dropping table!";
    sem_cnxt->error_msg_ =
        "No table name or invalid name during dropping table!";
    ret = rTableillegal;
    return ret;
  }
  if (NULL == table_desc) {
    LOG(ERROR) << "Table [" + table_name_ + "] is not exist!";
    sem_cnxt->error_msg_ = "Table [" + table_name_ + "] is not exist!";
    ret = rTableNotExisted;
    return ret;
  }
  if (NULL != next_) {
    ret = next_->SemanticAnalisys(sem_cnxt);
  }
  return ret;
}

AstDropProjection::AstDropProjection(AstNodeType ast_node_type,
                                     string table_name, bool is_all,
                                     int projection_id)
    : AstNode(ast_node_type),
      table_name_(table_name),
      is_all_(is_all),
      projection_id_(projection_id) {}

AstDropProjection::~AstDropProjection() {}

RetCode AstDropProjection::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;
  bool proj_match = false;
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  TableDescriptor* table_desc = local_catalog->getTable(table_name_);
  if ("" == table_name_) {
    LOG(ERROR) << "No table name or invalid name during dropping projection!";
    sem_cnxt->error_msg_ =
        "No table name or invalid name during dropping projection!";
    ret = rTableillegal;
    return ret;
  }
  if (NULL == table_desc) {
    LOG(ERROR) << "Table [" + table_name_ + "] is not exist!";
    sem_cnxt->error_msg_ = "Table [" + table_name_ + "] is not exist!";
    ret = rTableNotExisted;
    return ret;
  }
  vector<ProjectionDescriptor*>* projection_list =
      table_desc->GetProjectionList();
  if (is_all_ == true) {
    if (projection_list->empty()) {
      LOG(ERROR) << "There is no projection in table [" + table_name_ + "]!";
      sem_cnxt->error_msg_ =
          "There is no projection in table [" + table_name_ + "]!";
      ret = rNoProjection;
      return ret;
    }
  } else {
    string proj_id = std::to_string(projection_id_);
    for (auto projection : *projection_list) {
      if (projection_id_ == projection->getProjectionID().projection_off) {
        proj_match = true;
      }
    }
    if (proj_match == false) {
      LOG(ERROR) << "Projection [" + proj_id + "] is not exist!";
      sem_cnxt->error_msg_ = "Projection [" + proj_id + "] is not exist!";
      ret = rNoProjection;
      return ret;
    }
  }
  return ret;
}

void AstDropProjection::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Table Name| : " << table_name_ << endl;
  if (is_all_ == true) {
    cout << setw(++level * TAB_SIZE) << " "
         << "|Drop All Projection|" << endl;
  } else {
    cout << setw(++level * TAB_SIZE) << " "
         << "|Drop Projection| : " << projection_id_ << endl;
  }
}

//}  // namespace sql_parser
//}  // namespace claims
