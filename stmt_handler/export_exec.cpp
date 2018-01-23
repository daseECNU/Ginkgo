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

#include <assert.h>
#include <vector>
#include <string>
#include "../stmt_handler/export_exec.h"
#include "../Environment.h"
#include "../loader/data_injector.h"
#include <string>
#include "../loader/file_connector.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/file_handle/file_handle_imp.h"
#include "../common/memory_handle.h"
#include "../common/rename.h"
#include "../storage/BlockManager.h"
#include "../common/file_handle/hdfs_connector.h"
using std::vector;
using claims::loader::DataInjector;
using claims::common::HdfsConnector;
namespace claims {
namespace stmt_handler {
#define NEWRESULT
#define NEW_LOADER
ExportExec::ExportExec(AstNode *stmt) : StmtExec(stmt) {
  // TODO Auto-generated constructor stub

  assert(stmt_);
  export_ast_ = dynamic_cast<AstExportTable *>(stmt_);
  tablename_ = export_ast_->table_name_;
  table_desc_ = Environment::getInstance()->getCatalog()->getTable(tablename_);
}

ExportExec::~ExportExec() {
  // TODO Auto-generated destructor stub
}
/**
 * @brief export data into file system.
 * @details check whether the table we have created or not. forbid to export data
 * from an nonexistent table.
 *  then add path names from path node to a vector path_names,
 *  create new HdfsLoader, load data.
 */
RetCode ExportExec::Execute(ExecutedResult *exec_result) {
  RetCode ret = rSuccess;

  SemanticContext sem_cnxt;
  ret = export_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    exec_result->SetError("Semantic analysis error.\n" + sem_cnxt.error_msg_);
    //    exec_result->error_info_ =
    //        "Semantic analysis error.\n" + sem_cnxt.error_msg_;
    //    exec_result->status_ = false;
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  }

  TableDescriptor *table = Environment::getInstance()->getCatalog()->getTable(
		  export_ast_->table_name_);
  int attr_size=table->getNumberOfAttribute();
  string column_separator=export_ast_->column_separator_;
  string tuple_separator=export_ast_->tuple_separator_;
  AstExprList *path_node = dynamic_cast<AstExprList *>(export_ast_->path_);
  AstExprConst *data = dynamic_cast<AstExprConst *>(path_node->expr_);
  string path =data->data_;
  /*
  vector<vector<string>> write_paths;
  write_paths=table->GetAllPartitionsPath();
  cout<<"GetAllPartitionsPath"<<endl;
  for (auto prj : write_paths){
	 cout<<"path  prj:"<<&prj<<endl;
    for (auto part : prj) cout<<"part:"<<&part<<endl;}
 // ProjectionID pj = table
*/
  vector<ProjectionDescriptor*>* a1=table->GetProjectionList();
  vector<ProjectionDescriptor*> aa =*a1;
  std::vector<ChunkStorage*> chunk_list_;

  ProjectionDescriptor* pj=table->getProjectoin(0);
  vector<PartitionInfo *> pt_list=pj->getPartitioner()->getPartitionList();
  vector<PartitionID> ptid_list=pj->getPartitioner()->getPartitionIDList();

  // create chunk_list
  EXEC_AND_LOG(ret, CreateChunklist(pt_list,chunk_list_,ptid_list),
                 "CreateChunklist",
                 "failed to CreateChunklist");
  /*
  int pt_num=0;
 	 for (auto ww : pt_list){
 		 int number_of_blocks=ww->get_number_of_blocks() ;
 		 unsigned number_of_chunks = ceil((number_of_blocks) / (float)1024);
 		 for (unsigned i = 0; i < number_of_chunks; i++) {
 		     chunk_list_.push_back(new ChunkStorage(
 		         ChunkID(ptid_list[pt_num], i), BLOCK_SIZE, DISK));
 		   }
 		pt_num++;
 	 }
*/
  void *buffer= malloc(64*1024*1024);
  int write_buffer_size=0;
  string block_record;
  string tuple_record;
  common::FilePlatform platform_;
  platform_=0;
  imp_ = common::FileHandleImpFactory::Instance().CreateFileHandleImp(platform_, path);
  GETCURRENTTIME(start_time);
  for(auto chunklist : chunk_list_){
	  memset((void*)buffer, '\0', 64 * 1024*1024);
	  int chunk_size = Config::local_disk_mode ? BlockManager::getInstance()->LoadFromDisk(chunklist->GetChunkID(),buffer,64*1024*1024)
			                                     : BlockManager::getInstance()->LoadFromHdfs(chunklist->GetChunkID(),buffer,64*1024*1024);
	  int block_num=chunk_size/BLOCK_SIZE;
	  int block_=0;

	  while(block_ < block_num){
		  int tuple_num=*(int *)(BLOCK_SIZE*block_+buffer+65532);
		  int tuple_=0;

		  while(tuple_ < tuple_num){
			  int tup_size=table->getSchema()->getTupleMaxSize();
			  for(int i=1 ; i< attr_size ; i++){
				  string colval= table->getSchema()->getColumnValue(BLOCK_SIZE*block_+tuple_*tup_size+buffer,i);
				  tuple_record+=colval;
				  tuple_record+=column_separator;
			  }
			  tuple_record+=tuple_separator;
//			  cout<<tuple_record<<endl;
			  write_buffer_size+=tup_size;
			  tuple_++;
		  }
		  block_++;
		  if(write_buffer_size >= 64*1024){
			  char *tmp=tuple_record.c_str();
			  imp_->AppendNoCompress(tmp,strlen(tmp));
			  tuple_record="";
			  write_buffer_size=0;
		  }
	  }

  }
  if(write_buffer_size != 0){
	  char *tmp1=tuple_record.c_str();
	  imp_->AppendNoCompress(tmp1,strlen(tmp1));
	  tuple_record="";
	  write_buffer_size=0;
   }

  free(buffer);
  imp_->Close();

  LOG(INFO) << "complete export table."<<std::endl;
  double export_time_ms = GetElapsedTime(start_time);
  LOG(INFO) << " export time: " << export_time_ms / 1000.0 << " sec" << endl;
  ostringstream oss;
  oss << "export table successfully (" << export_time_ms / 1000.0 << " sec) ";
  exec_result->SetResult(oss.str(), NULL);
  return ret;
}

RetCode ExportExec::CreateChunklist(
		 vector<PartitionInfo *> pt_list,std::vector<ChunkStorage*>& chunk_list_,
		vector<PartitionID> ptid_list){
	int ret=rSuccess;
	int pt_num=0;
	 	for (auto ww : pt_list){
	 		int number_of_blocks=ww->get_number_of_blocks() ;
	 		unsigned number_of_chunks = ceil((number_of_blocks) / (float)1024);
	 		for (unsigned i = 0; i < number_of_chunks; i++) {
	 		   chunk_list_.push_back(new ChunkStorage(
	 		       ChunkID(ptid_list[pt_num], i), BLOCK_SIZE, DISK));
	 		 }
	 		pt_num++;
	     }
	 	 return ret;

}
void ExportExec::AnnounceIAmLoading() {
  static char* load_output_info[7] = {
      "Loading         \r", "Loading.\r",     "Loading..\r",    "Loading...\r",
      "Loading....\r",      "Loading.....\r", "Loading......\r"};
  static int count = 0;
  cout << load_output_info[count = (++count % 7)] << std::flush;
}

}  // namespace stmt_handler
}  // namespace claims
