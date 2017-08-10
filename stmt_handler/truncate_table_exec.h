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
 * /CLAIMS/stmt_handler/truncate_table_exec.h
 *
 *  Created on: Jun 13, 2017
 *      Author: zyhe
 *       Email: hzylab@gmail.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_
#define STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_

#include <string>
#include "../stmt_handler/stmt_exec.h"
#include "../sql_parser/ast_node/ast_truncate_stmt.h"
#include "../stmt_handler/drop_table_exec.h"

namespace claims {
namespace stmt_handler {
/**
 * @brief
 */
class TruncateTableExec : public StmtExec {
 public:
  TruncateTableExec(AstNode* stmt);  // NOLINT
  virtual ~TruncateTableExec();

  RetCode Execute(ExecutedResult* exec_result);

 private:
  /**
   * @brief
   * truncate all projections of the table from the catalog and delete the
   * associated files in the disk or in the hdfs
   * @param table_name
   * @return
   */
  RetCode TruncateTable(const string& table_name);

  /**
   * @brief
   * delete the data information of table in catalog and unbind the
   * projection bound to Slave Node
   * @param table_name
   * @return
   */
  RetCode TruncateTableFromCatalog(const string& table_name);

  RetCode TruncateProjection(const string& table_name, const int& proj_id);

  RetCode TruncateProjectionFromCatalog(const string& table_name,
                                        const int& proj_id);

 private:
  AstTruncateTable* truncate_table_ast_;
};

} /* namespace stmt_handler */
} /* namespace claims */

#endif /* STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_ */
