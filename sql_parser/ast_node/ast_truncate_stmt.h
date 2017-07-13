/*
 * ast_truncate_stmt.h
 *
 *  Created on: Jun 13, 2017
 *      Author: he
 */

#ifndef SQL_PARSER_AST_NODE_AST_TRUNCATE_STMT_H_
#define SQL_PARSER_AST_NODE_AST_TRUNCATE_STMT_H_

#include "../ast_node/ast_node.h"

using std::string;

// namespace claims {
// namespace sql_parser {

class AstTruncateTable : public AstNode {
 public:
  AstTruncateTable(AstNodeType ast_node_type, AstNode* table_list_);
  ~AstTruncateTable();
  void Print(int level = 0) const;
  AstNodeType ast_node_type_;
  AstNode* table_list_;
  RetCode SemanticAnalisys(SemanticContext* sem_cnxt);
};
//}  // namespace sql_parser
//}  // namespace claims

#endif /* SQL_PARSER_AST_NODE_AST_TRUNCATE_STMT_H_ */
