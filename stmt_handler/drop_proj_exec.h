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
 * /CLAIMS/stmt_handler/drop_proj_exec.h
 *
 *  Created on: Aug 6, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_DROP_PROJ_EXEC_H_
#define STMT_HANDLER_DROP_PROJ_EXEC_H_

#include <string>
#include "../stmt_handler/stmt_exec.h"
#include "../sql_parser/ast_node/ast_drop_stmt.h"
#include "../stmt_handler/drop_table_exec.h"

namespace claims {
namespace stmt_handler {

class DropProjExec : public StmtExec {
 public:
  DropProjExec(AstNode* stmt);  // NOLINT
  virtual ~DropProjExec();
  friend class TruncateTableExec;

  RetCode Execute(ExecutedResult* exec_result);

 private:
  /* Drop all projections of a table */
  RetCode DropAllProj(const string& table_name);

  /* Drop all projections of a table from Catalog */
  RetCode DropAllProjFromCatalog(const string& table_name);

  /* Drop one projection of table */
  RetCode DropOneProj(const string& table_name, const int& projection_id);

  /* Drop one projections of table from Catalog */
  RetCode DropOneProjFromCatalog(const string& table_name,
                                 const int& projection_id);

  /* This function only frees one projection of the table */
  bool FreeProjectionFromMemory(const string& table_name, const int& proj_id);

  RetCode GetWriteAndReadTables(
      vector<vector<pair<int, string>>>& stmt_to_table_list);

 private:
  AstDropProjection* drop_proj_ast_;
};

} /* namespace stmt_handler */
} /* namespace claims */

#endif /* STMT_HANDLER_DROP_PROJ_EXEC_H_ */
