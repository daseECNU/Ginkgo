/*
 * ast_truncate_stmt.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: he
 */

#include "../ast_node/ast_truncate_stmt.h"

#include <glog/logging.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>

#include "./ast_truncate_stmt.h"
#include "../../common/error_define.h"
#include "../../catalog/table.h"
#include "../../Environment.h"
using namespace claims::common;  // NOLINT
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::bitset;

// namespace claims {
// namespace ast_node {
AstTruncateTable::AstTruncateTable(AstNodeType ast_node_type,
                                   AstNode* table_list)
    : AstNode(ast_node_type), table_list_(table_list) {
  //  cout << "Generate AstTruncateTableStmt" << endl;
}

AstTruncateTable::~AstTruncateTable() {
  if (NULL != table_list_) {
    delete table_list_;
    table_list_ = NULL;
  }
}

void AstTruncateTable::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Truncate Stmt|" << endl;
}

RetCode AstTruncateTable::SemanticAnalisys(SemanticContext* sem_cnxt) {
  RetCode ret = rSuccess;

  if (NULL != table_list_) {
    ret = table_list_->SemanticAnalisys(sem_cnxt);
  } else {
    LOG(ERROR) << "No table found or invalid table name.";
    sem_cnxt->error_msg_ = "No table found or invalid table name.";
    ret = rNoTalbeFound;
  }
  return ret;
}
//} /* namespace truncate_table_exec */
