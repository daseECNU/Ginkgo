/*
 * truncate_table_exec.h
 *
 *  Created on: Jun 13, 2017
 *      Author: he
 */

#ifndef STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_
#define STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_

#include <string>
#include "../stmt_handler/stmt_exec.h"
#include "../sql_parser/ast_node/ast_truncate_stmt.h"

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
   * to check the table with given name, whether it is a base table or a del
   * table. If the return value is true, then the table is the base table, if
   * not, the table is the del table.
   * @param table_name the name of the given table
   */
  bool CheckBaseTbl(const string& table_name) const;
  /**
   * truncate the table from the catalog and delete the associated files in
   * the disk or in the hdfs
   * @param table_name
   * @return
   */
  RetCode TruncateTable(const string& table_name);

  /**
   * truncate the table information from the catalog
   * @param table_name
   * @return
   */
  RetCode TruncateTableFromCatalog(const string& table_name);

  /**
   * truncate the table files from the stroage
   * @param table_name
   * @return
   */
  RetCode DeleteTableFiles(const string& table_name);

 private:
  AstTruncateTableStmt *truncate_stmt_ast_;
};

} /* namespace stmt_handler */
} /* namespace claims */

#endif /* STMT_HANDLER_TRUNCATE_TABLE_EXEC_H_ */
