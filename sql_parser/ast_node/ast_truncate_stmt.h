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


class AstTruncateTableStmt : public AstNode {
 public:
  AstTruncateTableStmt(AstNodeType ast_node_type, int is_if_exists,
		  string table_name);
  ~AstTruncateTableStmt();
  void Print(int level = 0) const;
  RetCode SemanticAnalisys(SemanticContext* sem_cnxt);


  AstNodeType ast_node_type_;
  string table_name_;
  int is_if_exists_;
};
//}  // namespace sql_parser
//}  // namespace claims

#endif /* SQL_PARSER_AST_NODE_AST_TRUNCATE_STMT_H_ */
