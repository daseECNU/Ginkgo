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
 *  /Ginkgo/stmt_handler/export_exec.cpp
 *  Created on: Jan 3, 2018
 *      Author: hqli
 *       Email: huang_qiuli@outlook.com
 */

#ifndef STMT_HANDLER_EXPORT_EXEC_H_
#define STMT_HANDLER_EXPORT_EXEC_H_

#include "../stmt_handler/stmt_exec.h"
#include "../loader/file_connector.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../common/memory_handle.h"
#include "../common/rename.h"
#include "../storage/ChunkStorage.h"

namespace claims {
namespace stmt_handler {
/**
 * @brief
 * @details
 */
class ExportExec : public StmtExec {
 public:
  ExportExec(AstNode* stmt);
  virtual ~ExportExec();
  /**
   * @brief the concrete operation of export data.
   */
  RetCode Execute(ExecutedResult* exec_result);
  void ExportExec::AnnounceIAmExporting();
  RetCode ExportExec::CreateChunklist(vector<PartitionInfo *> pt_list,
		  vector<PartitionID> ptid_list,   std::vector<ChunkID*> &chunk_id) ;
  RetCode ExportExec::ExportIntoFile(int attr_size , std::vector<ChunkID*> chunk_id,
		  string path);
  void ExportExec::flush(string *result ,unsigned int *file_size ,int*file_num,int * write_buffer_size, string path);
 private:
  /**
   * this pointer describes the abstract syntax tree about export data from
   * tables.
   * It is converted from the member stmt_ of base class when we construct a new
   * object.
   */

  //int file_size;
  //int file_num;
  TableDescriptor *table;
  AstExportTable* export_ast_;
  common::FileHandleImp* imp_;
  common::FilePlatform platform_;
  string file_name_;
  string column_separator;
  string tuple_separator;
  int  fd_;
};

}  // namespace stmt_handler
}  // namespace claims

#endif /* STMT_HANDLER_EXPORT_EXEC_H_ */
