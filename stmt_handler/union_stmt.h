/*
 * Copyright [2012-2017] DaSE@ECNU
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
 * /CLAIMS/stmt_handler/union_stmt.h
 *
 *  Created on: May 20, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 *
 * Description:
 *
 */

#ifndef STMT_HANDLER_SET_OP_EXEC_H
#define STMT_HANDLER_SET_OP_EXEC_H

#include "../stmt_handler/stmt_exec.h"
#include "../physical_operator/segment.h"
#include "../sql_parser/ast_node/ast_union_stmt.h"
using claims::physical_operator::Segment;
namespace claims {
namespace stmt_handler {
class UnionExec : public StmtExec {
 public:
  UnionExec(AstNode* stmt, string raw_sql);
  UnionExec(AstNode* stmt);
  virtual ~UnionExec();
  RetCode Execute(ExecutedResult* exec_result);
  RetCode Execute();
  //  ExecutedResult executed_result_;
  ResultSet* result_;
  vector<AstNode*> groupby_attrs_;
  vector<AstNode*> distinct_attrs_;
  set<AstNode*> agg_attrs_;

 private:
  //	RetCode GetSelectAstList();
  //	RetCode AddSelectAstList(AstSetOpStmt* setop_ast);
  RetCode GetChildStmt(AstNode* ast_node);
  //	RetCode GetAllChildStmt();
  RetCode GetResultList();
  RetCode GetChildRawSql(string raw_sql);
  RetCode Checkcolumn();
  RetCode RemoveDuplicate();
  void pushcolumn(AstFromList* ast_from_list_);
  RetCode checkcolumn(AstFromList* ast_from_list_,
                      vector<data_type>::iterator& pos);
  RetCode pushcolumn_all(AstFromList* ast_from_list_,
                         AstSelectExpr* select_expr);
  RetCode checkcolumn_all(AstFromList* ast_from_list_,
                          AstSelectExpr* select_expr,
                          vector<data_type>::iterator& pos);
  RetCode CreateHashTable(unsigned length);
  RetCode DeleteHashTable(unsigned length);
  RetCode CopySchema();
  RetCode GetWriteAndReadTables(
      ExecutedResult& result,
      vector<vector<pair<int, string>>>& stmt_to_table_list);
  //  RetCode Print();
  static void* SendAllSegments(void* arg);
  RetCode IsUpperExchangeRegistered(vector<NodeID>& upper_node_id_list,
                                    const u_int64_t exchange_id);

 private:
  vector<AstSelectStmt*> select_ast_list_;
  string raw_sql_;
  AstUnionStmt* setop_ast_;
  vector<ExecutedResult> exec_result_list_;
  vector<string> raw_sql_list_;
  vector<data_type> column_type_list_;
  bool checktype(data_type type, vector<data_type>::iterator& pos);
  RetCode putresultset();
  stack<Segment*> all_segments_;

  //  auto pos;
  //  BasicHashTable* hash_table_;
  struct HashTableU {
    ResultSet* resultset_;
    bool exist_;
    void* tuple_;
    struct HashTableU* next_;
  };
  struct HashTableU* hashtable_u_;
};
}  // namespace stmt_handler
}  // namespace claims
#endif  //  STMT_HANDLER_SET_OP_EXEC_H
