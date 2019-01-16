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
 * /CLAIMS/stmt_handler/load_exec.h
 *
 *  Created on: Sep 23, 2015
 *      Author: cswang
 *	     Email: cs_wang@infosys.com
 *
 * Description:
 *      this file contains one class about load data.
 *
 */

#ifndef STMT_HANDLER_LOAD_EXEC_H_
#define STMT_HANDLER_LOAD_EXEC_H_
#include <hdfs.h>
#include "../stmt_handler/stmt_exec.h"
using namespace claims::common;
namespace claims {
namespace stmt_handler {
/**
 * @brief
 * @details
 */
class LoadExec : public StmtExec {
 public:
  LoadExec(AstNode* stmt);
  virtual ~LoadExec();
  /**
   * @brief the concrete operation of load data.
   */
  RetCode Execute(ExecutedResult* exec_result);

  RetCode DistributeLoad(std::vector<string> path_names, int num,
                         string col_sep, string row_sep, TableDescriptor* table,
                         int open_flag);
  RetCode getOffset(int64_t start, int64_t end, int64_t& result, char sep);
  RetCode getPart(string path, int part, char sep, vector<int64_t>& offset);
  RetCode GetWriteAndReadTables(
      ExecutedResult& result,
      vector<vector<pair<int, string>>>& stmt_to_table_list);

 private:
  /**
   * this pointer describes the abstract syntax tree about load data into
   * tables.
   * It is converted from the member stmt_ of base class when we construct a new
   * object.
   */
  AstLoadTable* load_ast_;

  hdfsFS fs_;
  hdfsFile file_;
};

}  // namespace stmt_handler
}  // namespace claims

#endif  // STMT_HANDLER_LOAD_EXEC_H_
