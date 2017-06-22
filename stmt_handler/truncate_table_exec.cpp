/*
 * truncate_table_exec.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: he
 */

#include <string>
#include <vector>
#include <iostream>
#include <assert.h>  // NOLINT

#include "../catalog/catalog.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/error_define.h"
#include "../Config.h"
#include "../Environment.h"
#include "../loader/data_injector.h"
#include "../loader/table_file_connector.h"
#include "../stmt_handler/truncate_table_exec.h"
using claims::loader::TableFileConnector;
using claims::catalog::Catalog;
using std::vector;

namespace claims {
namespace stmt_handler {

TruncateTableExec::TruncateTableExec(AstNode* stmt) : StmtExec(stmt) {
  assert(stmt_);
  truncate_stmt_ast_ = dynamic_cast<AstTruncateTableStmt*>(stmt_);
}

TruncateTableExec::~TruncateTableExec() {}

RetCode TruncateTableExec::Execute(ExecutedResult* exec_result) {
  RetCode ret = rSuccess;

  SemanticContext sem_cnxt;
  ret = truncate_stmt_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->error_info_ =
        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    exec_result->status_ = false;
    LOG(WARNING) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
	}
	Catalog* local_catalog = Environment::getInstance()->getCatalog();
	string table_name;
	table_name = truncate_stmt_ast_->table_name_;
	if (CheckBaseTbl(table_name)) {  // truncate the base table
//		ret = TruncateTable(table_name + "_DEL");
//		if (ret == rSuccess) {
//			cout << table_name + "_DEL is dropped from this database!" << endl;
//			ret = TruncateTable(table_name);
//			cout << table_name + "is dropped from this database!" << endl;
//		} else {
//			TruncateTable(table_name + "_DEL");
//			TruncateTable(table_name);
//		}
		std::cout<<"the table is exist"<<std::endl;
	} else {
//		ret = DeleteTableFiles(table_name);
//		// todo (miqni 2016.1.28) to delete the del table from memory
//		cout << table_name + "_DeL is dropped from this database!" << endl;
//		std::cout<<"truncate the base table"<<std::endl;
		std::cout<<"the table is not exist"<<std::endl;
	}

//	if (ret == rSuccess) {
//		exec_result->info_ = "drop table successfully!";
//	} else {
//		exec_result->error_info_ = "drop table [" + table_name + "] failed.";
//		exec_result->status_ = false;
//		exec_result->result_ = NULL;
//		return ret;
//	}
//
//	local_catalog->saveCatalog();
//	exec_result->status_ = true;
//	exec_result->result_ = NULL;
//	return ret;
}

bool TruncateTableExec::CheckBaseTbl(const string& table_name) const {
  Catalog* local_catalog = Environment::getInstance()->getCatalog();
  string base_tbl_name = "";
  // if the length of the table name is less than 4, it should be the name of
  // the base table.
  if ("" != table_name && table_name.size() < 4) {
    return true;
  }
  if ("_DEL" == table_name.substr(table_name.size() - 4, 4)) {
    base_tbl_name = table_name.substr(0, table_name.size() - 4);
    if (NULL != local_catalog->getTable(base_tbl_name)) {
      return false;
    } else {
      return true;
    }
  } else {
    if (NULL != local_catalog->getTable(table_name + "_DEL")) {
      return true;
    } else {
      return false;
    }
  }
}

/**
 * truncate the table based on the provided table name,
 * this operator will truncate the table in the catalog as well as the table file
 *on the disk or hdfs
 *
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::TruncateTable(const string& table_name) {

}

/**
 * truncate the table information from the catalog as well as to delete the object
 * of the TableDescriptor of the table_anme
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::TruncateTableFromCatalog(const string& table_name) {

}

/**
 * delete the file associated with the Table table_name only
 * @param table_name
 * @return
 */
RetCode TruncateTableExec::DeleteTableFiles(const string& table_name) {

}
} /* namespace stmt_handler */
} /* namespace claims */

