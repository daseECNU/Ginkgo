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
 * /CLAIMS/stmt_handler/stmt_handler.h
 *
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_STMT_HANDLER_H_
#define STMT_HANDLER_STMT_HANDLER_H_

#include <string>
#include "../stmt_handler/stmt_exec.h"
#include "../stmt_handler/select_exec.h"
#include "../stmt_handler/load_exec.h"
#include "../stmt_handler/insert_exec.h"
#include "../stmt_handler/update_stmt_exec.h"
#include "./create_table_exec.h"
#include "../Daemon/Daemon.h"
#include "../sql_parser/parser/parser.h"
namespace ginkgo {
namespace stmt_handler {

class StmtHandler {
 public:
  explicit StmtHandler(string sql_stmt);
  StmtHandler(string sql_stmt, ExecutedResult* exec_result);
  virtual ~StmtHandler();
  RetCode Execute(ExecutedResult* exec_result);

 private:
  RetCode GenerateStmtExec(AstNode* stmt_ast);

 private:
  Parser* sql_parser_;
  string sql_stmt_;
  StmtExec* stmt_exec_;
};

}  // namespace stmt_handler
}  // namespace ginkgo
#endif  //  STMT_HANDLER_STMT_HANDLER_H_
