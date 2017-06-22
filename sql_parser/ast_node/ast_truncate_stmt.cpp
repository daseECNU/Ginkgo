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
AstTruncateTableStmt::AstTruncateTableStmt(AstNodeType ast_node_type, int is_if_exists,
		  string table_name)
:AstNode(ast_node_type),is_if_exists_(is_if_exists), table_name_(table_name) {
//	cout << "Generate AstTruncateTableStmt" << endl;
}


AstTruncateTableStmt::~AstTruncateTableStmt(){
//	if (NULL != table_name_) {
//	    delete table_name_;
//	    table_name_ = NULL;
//	  }
}


void AstTruncateTableStmt::Print(int level) const {
  cout << setw(level * TAB_SIZE) << " "
       << "|Truncate Stmt|" << endl;
}

RetCode AstTruncateTableStmt::SemanticAnalisys(SemanticContext* sem_cnxt) {

	RetCode ret = rSuccess;
  string tablename =table_name_;
  TableDescriptor* new_table =
      Environment::getInstance()->getCatalog()->getTable(tablename);
  if (NULL == new_table) {
    LOG(ERROR) << "The table " + tablename + " is not existed.";
    sem_cnxt->error_msg_ = "The table " + tablename + " is not existed.";
    ret = rTableNotExisted;
    return ret;
  }
  string tabledel = tablename + "_DEL";
  new_table = Environment::getInstance()->getCatalog()->getTable(tabledel);
  if (NULL == new_table) {
    LOG(ERROR) << "The table DEL " + tabledel +
                      " is not existed during delete data." << std::endl;
    sem_cnxt->error_msg_ =
        "The table DEL " + tabledel + " is not existed during delete data.";
    ret = rTableNotExisted;
    return ret;
  }
  return ret;
}
//} /* namespace truncate_table_exec */
