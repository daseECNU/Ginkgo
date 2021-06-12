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
 * /CLAIMS/stmt_handler/delete_stmt_exec.h
 *
 *  Created on: Aug 18, 2016
 *      Author: cswnag
 *		   Email: cs_wang@infosys.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_UPDATE_STMT_EXEC_H_
#define STMT_HANDLER_UPDATE_STMT_EXEC_H_

#include <string>

#include "../common/Block/ResultSet.h"
#include "../stmt_handler/stmt_exec.h"
#include "../sql_parser/ast_node/ast_update_stmt.h"
using std::string;

namespace ginkgo {
namespace stmt_handler {

class UpdateStmtExec : public StmtExec {
 public:
  /**
   * @brief Method description: The executor about update statement.
   * @param AstNode* stmt   point to AST
   */
  UpdateStmtExec(AstNode *stmt);  // NOLINT
  virtual ~UpdateStmtExec();

  /**
   * @brief the concrete operation of update statement.
   */
  RetCode Execute(ExecutedResult *exec_result);

 private:
  RetCode GenerateSelectForUpdateStmt(const string table_name,
                                      AstNode *&appended_query_sel_stmt);
  RetCode GenerateUpdateData(string table_base_name, AstNode *update_set_list,
                             ExecutedResult *exec_result, ostringstream &ostr);
  void InsertUpdatedDataIntoTable(string table_name,
                                  ExecutedResult *exec_result,
                                  ostringstream &ostr);

 private:
  AstUpdateStmt *update_stmt_ast_;
};

} /* namespace stmt_handler */
} /* namespace ginkgo */

#endif  //  STMT_HANDLER_UPDATE_STMT_EXEC_H_
