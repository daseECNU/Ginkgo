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
 * /CLAIMS/stmt_handler/create_exec.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: cswang
 *	 Email: cs_wang@infosys.com
 *
 * Description:
 *
 *
 */

#include <assert.h>
#include <string>
#include "../Environment.h"
#include "../stmt_handler/create_table_exec.h"
#include "../common/error_define.h"
#include "../catalog/catalog.h"

using ginkgo::common::rStmtHandlerCreateTableExisted;
using ginkgo::common::rStmtHandlerCreateTableFailed;
using ginkgo::common::rSuccess;
namespace ginkgo {
namespace stmt_handler {
/**
 * @brief Constructor
 * @detail convert the base class member stmt_ to createtable_ast_ and get the
 * table name,
 *  firstly get the descriptor from catalog by table name.
 */
#define NEWRESULT
#define CREATE_DEL_TABLE
CreateTableExec::CreateTableExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  result_flag_ = true;
  createtable_ast_ = dynamic_cast<AstCreateTable*>(stmt_);
  if (!createtable_ast_->additional_name_.empty()) {
    tablename_ = createtable_ast_->additional_name_;
  } else {
    tablename_ = createtable_ast_->table_name_;
  }
  if (!tablename_.empty()) {
    table_desc_ =
        Environment::getInstance()->getCatalog()->getTable(tablename_);
  }
}

CreateTableExec::~CreateTableExec() {}
/**
 * @brief create a table by the AST.
 * @detail check whether the table we have created or not.
 *  Create the new table and give it a default attribute "row_id",
 *  then add all attributes like the information about
 *  column's value type, can be null or not from AST to the new table's
 * descriptor,
 *  save it to catalog by the end.
 * @return a result code cooperate with the client.
 */
RetCode CreateTableExec::Execute(ExecutedResult* exec_result) {
  SemanticContext sem_cnxt;
  RetCode ret = createtable_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->error_info_ =
        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    exec_result->status_ = false;
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  }

  string tablename_del;
  tablename_del = tablename_ + "_DEL";
#ifdef sem_cnxt
  if (isTableExist()) {
    exec_result->status_ = false;
    result_flag_ = false;
    exec_result->error_info =
        "The table " + tablename_ + " has existed during creating table!";
    LOG(ERROR) << "The table " + tablename_ +
                      " has existed during creating table!" << std::endl;
    ret = ginkgo::common::kStmtHandlerTableExistDuringCreate;
  } else {
#endif
    table_desc_ = new TableDescriptor(
        tablename_,
        Environment::getInstance()->getCatalog()->allocate_unique_table_id());
    table_desc_->addAttribute("row_id", data_type(t_u_long), 0, true);

    AstCreateColList* list =
        dynamic_cast<AstCreateColList*>(createtable_ast_->col_list_);
    string primaryname = "";
    int colNum = 0;

    while (list) {
      AstCreateDef* data = dynamic_cast<AstCreateDef*>(list->data_);
      if (data->def_type_ == 1) {
        ++colNum;
        string colname = data->col_name_;
        primaryname = colname;
        AstColumnAtts* column_atts =
            dynamic_cast<AstColumnAtts*>(data->col_atts_);

        /* TODO: Whether column is unique or has default value is not
         * finished,
         *  because there are no supports
         */
        AstDataType* datatype = dynamic_cast<AstDataType*>(data->data_type_);
        switch (datatype->data_type_) {
          case 1: {
            if (column_atts && (column_atts->datatype_ & 01)) {  // not null
              table_desc_->addAttribute(colname, data_type(t_boolean), 0, true,
                                        false);
            } else if (column_atts &&
                       (column_atts->datatype_ & 02)) {  // can be null
              table_desc_->addAttribute(colname, data_type(t_boolean), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_boolean), 0, true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 3: {
            if (datatype->opt_uz_ & 01 != 0) {
              if (column_atts && (column_atts->datatype_ & 01)) {
                table_desc_->addAttribute(colname, data_type(t_u_smallInt), 0,
                                          true, false);
              } else if (column_atts && (column_atts->datatype_ & 02)) {
                table_desc_->addAttribute(colname, data_type(t_u_smallInt), 0,
                                          true, true);
              } else {
                table_desc_->addAttribute(colname, data_type(t_u_smallInt), 0,
                                          true);
              }
            } else {
              if (column_atts && (column_atts->datatype_ & 01)) {
                table_desc_->addAttribute(colname, data_type(t_smallInt), 0,
                                          true, false);
              } else if (column_atts && (column_atts->datatype_ & 02)) {
                table_desc_->addAttribute(colname, data_type(t_smallInt), 0,
                                          true, true);
              } else {
                table_desc_->addAttribute(colname, data_type(t_smallInt), 0,
                                          true);
              }
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 5:
          case 6: {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_int), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_int), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_int), 0, true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 7: {
            if (datatype->opt_uz_ & 01 != 0) {
              if (column_atts && (column_atts->datatype_ & 01)) {
                table_desc_->addAttribute(colname, data_type(t_u_long), 0, true,
                                          false);
              } else if (column_atts && (column_atts->datatype_ & 02)) {
                table_desc_->addAttribute(colname, data_type(t_u_long), 0, true,
                                          true);
              } else {
                table_desc_->addAttribute(colname, data_type(t_u_long), 0,
                                          true);
              }
              LOG(INFO) << colname + " is created" << std::endl;
            } else {
              // TODO(fzh): not supports
              exec_result->error_info_ =
                  "This type is not supported during creating table!";
              exec_result->status_ = false;
              // error_msg_ = "This type is not supported during creating
              // table!";
              LOG(ERROR) << "This type is not supported during creating table!"
                         << std::endl;
              result_flag_ = false;
              // result_set_ = NULL;
              ret = common::rStmtHandlerTypeNotSupport;
            }
            break;
          }
          case 9: {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_double), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_double), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_double), 0, true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 10: {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_float), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_float), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_float), 0, true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 11: {
            int precision = 10;
            int scale = 0;
            if (datatype->length_) {
              AstOptLength* l = dynamic_cast<AstOptLength*>(datatype->length_);
              if((l->data1_>0))
              {
                precision = l->data1_;
                scale = l->data2_;
              }
            }
            /* here 1000 used for separating precision and scale, 
                 you will always see multiply or divide 1000 during process decimal type  */
            //TODO: define an marco value of 1000 in global file.
            int max_length = precision*1000+scale;
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_decimal), max_length,
                                        true, false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_decimal), max_length,
                                        true, true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_decimal), max_length,
                                        true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 12:  // DATE
          {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_date), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_date), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_date), 0, true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 13:  // TIME
          {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_time), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_time), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_time), 0, true);
            }
            LOG(INFO) << colname << " is created" << std::endl;
            break;
          }
          case 15:  // DATETIME
          {
            if (column_atts && (column_atts->datatype_ & 01)) {
              table_desc_->addAttribute(colname, data_type(t_datetime), 0, true,
                                        false);
            } else if (column_atts && (column_atts->datatype_ & 02)) {
              table_desc_->addAttribute(colname, data_type(t_datetime), 0, true,
                                        true);
            } else {
              table_desc_->addAttribute(colname, data_type(t_datetime), 0,
                                        true);
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          case 17:
          case 18: {
            if (datatype->length_) {
              AstOptLength* l = dynamic_cast<AstOptLength*>(datatype->length_);

              if (column_atts && (column_atts->datatype_ & 01)) {
                table_desc_->addAttribute(colname, data_type(t_string),
                                          l->data1_ + 1, true, false);
              } else if (column_atts && (column_atts->datatype_ & 02)) {
                table_desc_->addAttribute(colname, data_type(t_string),
                                          l->data1_ + 1, true, true);
              } else {
                table_desc_->addAttribute(colname, data_type(t_string),
                                          l->data1_ + 1, true);
              }
            } else {
              if (column_atts && (column_atts->datatype_ & 01)) {
                table_desc_->addAttribute(colname, data_type(t_string), 2, true,
                                          false);
              } else if (column_atts && (column_atts->datatype_ & 02)) {
                table_desc_->addAttribute(colname, data_type(t_string), 2, true,
                                          true);
              } else {
                table_desc_->addAttribute(colname, data_type(t_string), 2,
                                          true);
              }
            }
            LOG(INFO) << colname + " is created" << std::endl;
            break;
          }
          default: {
#ifdef NEWRESULT
            exec_result->error_info_ =
                "This type is not supported now during creating table!";
            LOG(ERROR)
                << "This type is not supported now during creating table!"
                << std::endl;
            exec_result->status_ = false;
            exec_result->result_ = NULL;
            ret = common::rStmtHandlerTypeNotSupport;
#else
            error_msg_ =
                "This type is not supported now during creating table!";
            LOG(ERROR)
                << "This type is not supported now during creating table!"
                << std::endl;
            result_flag_ = false;
            result_set_ = NULL;
            ret = common::rStmtHandlerTypeNotSupport;
#endif
          }
        }
      }

      list = dynamic_cast<AstCreateColList*>(list->next_);
    }

#ifdef CREATE_DEL_TABLE
    /**
     * At the same time,create a new table named "table_DEL" to store deleted
     * data.
     */
    TableDescriptor* table_del = NULL;
    ret = CreateDelTable(tablename_del, table_del);

    if (rSuccess == ret) {
    } else if (rStmtHandlerCreateTableExisted == ret) {
    } else {
      exec_result->status_ = false;
      exec_result->result_ = NULL;
      ret = common::rStmtHandlerTypeNotSupport;
    }
#endif

    if (exec_result->status_) {
      Environment::getInstance()->getCatalog()->add_table(table_desc_);
      Environment::getInstance()->getCatalog()->add_table(table_del);
      Environment::getInstance()->getCatalog()->saveCatalog();
#ifdef NEWRESULT
      exec_result->info_ = "create table successfully";
      LOG(INFO) << "create table successfully" << std::endl;
      exec_result->result_ = NULL;
      result_flag_ = true;
      ret = common::rStmtHandlerCreateTableSuccess;
#else
      info_ = "create table successfully";
      LOG(INFO) << "create table successfully" << std::endl;
      result_set_ = NULL;
      ret = common::rStmtHandlerCreateTableSuccess;
#endif
    }
#ifdef sem_cnxt
  }
#endif
  return ret;
}

/**
 * create the corresponding del table for the base table
 * with the schema as follows:
 * #################################################
 * ##row_id (t_u_long)  |row_id_DEL  (t_u_long)| ###
 * #################################################
 */
RetCode CreateTableExec::CreateDelTable(const string& table_name,
                                        TableDescriptor*& table_del) {
  RetCode ret = rSuccess;
  // TableDescriptor* table_del =
  //   Environment::getInstance()->getCatalog()->getTable(table_name);
  if (table_del == NULL) {
    table_del = new TableDescriptor(
        table_name,
        Environment::getInstance()->getCatalog()->allocate_unique_table_id());
    table_del->addAttribute("row_id", data_type(t_u_long), 0, true);
    table_del->addAttribute("row_id_DEL", data_type(t_u_long), 0, true);
    // new_table->createHashPartitionedProjectionOnAllAttribute(
    //    new_table->getAttribute(0).getName(), 4);
    return ret;
  } else {
    ret = rStmtHandlerCreateTableExisted;
    LOG(ERROR) << ret
               << "The table " + table_name +
                      " has existed during creating table_DEL!" << std::endl;
    return ret;
  }
  ret = rStmtHandlerCreateTableFailed;
  LOG(ERROR) << ret << "Create table" + table_name + " failed!" << std::endl;
  return ret;
}

}  // namespace stmt_handler
}  // namespace ginkgo
