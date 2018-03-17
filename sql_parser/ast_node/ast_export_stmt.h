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
 *  /Ginkgo/sql_parser/ast_node/ast_export_stmt.h
 *  Created on: Dec 31, 2017 1:23:13 PM
 *  Modified on: Dec 31, 2017
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 */

#ifndef SQL_PARSER_AST_NODE_AST_EXPORT_STMT_H_
#define SQL_PARSER_AST_NODE_AST_EXPORT_STMT_H_

#include <string>
#include <iostream>  //NOLINT

#include "../ast_node/ast_node.h"

using std::string;
// namespace claims {
// namespace sql_parser {
/***
 * @brief The AST of export table statement.
 * @details AstExportTable mainly includes table names, file path, column
 * separator, tuple separator, samples and modes.
 */
class AstExportTable : public AstNode {
 public:
  AstExportTable(AstNodeType ast_node_type, string table_name, AstNode* path,
                 string column_separator, string tuple_separator,
                 AstNode* select_stmt);
  ~AstExportTable();
  void Print(int level = 0) const;
  RetCode SemanticAnalisys(SemanticContext* sem_cnxt);
  AstNodeType ast_node_type_;
  string table_name_;
  AstNode* path_;
  string column_separator_;
  string tuple_separator_;
  AstNode* select_stmt_;

 private:
};

//}  // namespace sql_parser
//}  // namespace claims
#endif /* SQL_PARSER_AST_NODE_AST_EXPORT_STMT_H_ */
