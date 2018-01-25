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
#include "../common/memory_handle.h"

using std::vector;
using claims::loader::DataInjector;
using claims::common::HdfsConnector;
using claims::common::Malloc;
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

   table = Environment::getInstance()->getCatalog()->getTable(
	export_ast_->table_name_);
   int attr_size=table->getNumberOfAttribute();
   column_separator=export_ast_->column_separator_;
   tuple_separator=export_ast_->tuple_separator_;
   AstExprList *path_node = dynamic_cast<AstExprList *>(export_ast_->path_);
   AstExprConst *data = dynamic_cast<AstExprConst *>(path_node->expr_);
   string path =data->data_;

   std::vector<ChunkID*> chunk_id;

   ProjectionDescriptor* pj=table->getProjectoin(0);
   vector<PartitionInfo *> pt_list=pj->getPartitioner()->getPartitionList();
   vector<PartitionID> ptid_list=pj->getPartitioner()->getPartitionIDList();

  // create chunk_list
   EXEC_AND_LOG(ret, CreateChunklist(pt_list,ptid_list,chunk_id),
                 "CreateChunklist",
                 "failed to CreateChunklist");

   platform_=0;
   imp_ = common::FileHandleImpFactory::Instance().CreateFileHandleImp(platform_, path);
   GETCURRENTTIME(start_time);

   int file_num_ = ExportIntoFile(attr_size,chunk_id,path);

   for (unsigned i = 0; i < chunk_id.size(); i++) {
     delete chunk_id[i];
     chunk_id[i]=NULL;
   }
   chunk_id.clear();

   LOG(INFO) << "complete export table."<<std::endl;
   double export_time_ms = GetElapsedTime(start_time);
   LOG(INFO) << " export time: " << export_time_ms / 1000.0 << " sec" << endl;
   if (ret != rSuccess) {
     LOG(ERROR) << "failed to export table: "<<table->getTableName()<<" ";

     LOG(ERROR) << " into file " << path << endl;

     if (exec_result->error_info_ == "")
       exec_result->SetError("failed to export table");
   } else {
	   ostringstream oss;
	   oss << "export table successfully (" << export_time_ms / 1000.0 << " sec) \n";
	   if(file_num_ >1){
		   ostringstream os;
		   os<<file_num_;
		   oss << "the table is divided into "+ os.str() +" parts for the table is  too large.\n";
	   }
	   exec_result->SetResult(oss.str(), NULL);
	   oss.clear();
   }

   return ret;
}
RetCode ExportExec::ExportIntoFile(int attr_size , std::vector<ChunkID*> chunk_id , string path){
	RetCode ret = rSuccess;
	void *buffer= malloc(64*1024*1024);
	string *result=new string;
	Schema* schema =  table->getSchema();
	int row_id_in_file=0;
	int write_buffer_size=0;
	int file_num=1;
	unsigned int file_size=1;

	for(auto chunklist : chunk_id){
		memset((void*)buffer, '\0', 64 * 1024 *1024 );
		BlockManager *BManager=  BlockManager::getInstance();
		//read a chunk of data into buffer
		int chunk_size = Config::local_disk_mode ? BManager->LoadFromDisk(*chunklist,buffer,64*1024*1024)
		   			                             : BManager->LoadFromHdfs(*chunklist,buffer,64*1024*1024);
		int block_num=chunk_size/BLOCK_SIZE;
		int block_=0;

	   while(block_ < block_num){
		   int tuple_num=*(int *)(BLOCK_SIZE*block_+buffer+65532);
		   int tuple_=0;
		   //add a tuple of data into result
		   while(tuple_ < tuple_num){
			   int tup_size=schema->getTupleMaxSize();
			   for(int i=1 ; i< attr_size ; i++){
				   string colval= schema->getColumnValue(BLOCK_SIZE*block_+tuple_*tup_size+buffer,i);
				   (*result).append(colval);
				   (*result).append(column_separator);
			    }
			   (*result).append(tuple_separator);
			   write_buffer_size+=tup_size;
			   file_size+=tup_size;
			   tuple_++;

			   if (0 == row_id_in_file % 40000)
				   AnnounceIAmExporting();
			   ++row_id_in_file;
		   }
		   block_++;
		   if(write_buffer_size >= 64 * 1024){
			   flush(result , &file_size ,&file_num,	&write_buffer_size, path);
		    }
	   }
	}
	if(write_buffer_size != 0){
		flush(result ,& file_size ,&file_num, &write_buffer_size, path);
	}
	delete result;
	result=NULL;
	free(buffer);
	buffer=NULL;
	delete schema;
	imp_->Close();
	return file_num;
}

void ExportExec::flush(string *result ,unsigned int *file_size ,int *file_num,int *write_buffer_size, string path ){
	   imp_->AppendNoCompress((*result).c_str(),strlen((*result).c_str()));
	   (*result).clear();
	   string().swap(*result);
	   *write_buffer_size=0;
	   if(*file_size > (4*1024*1024*1024-10) ){
		   unsigned pos = path.rfind("/");
		   string path_former = path.substr(0,pos+1);
		   string file_name = path.substr(pos + 1, path.length());
		   unsigned pos1 = file_name.rfind(".");
		   string file_name_former = file_name.substr(0,pos1);
		   string file_name_latter = file_name.substr(pos1, file_name.length());
		   ostringstream os;
		   os<<*file_num;
		   if(*file_num==1){
			   string new_name=path_former+file_name_former + "_1" +file_name_latter;
			   int rename_result= rename( path.c_str() , new_name.c_str() );
		   }else{
				string new_path=path_former+file_name_former + "_"+os.str() +file_name_latter;
			   imp_ = common::FileHandleImpFactory::Instance().CreateFileHandleImp(platform_, new_path);
			   (*file_size)=0;
		   }
		   os.clear();
		   (*file_num)++;

	   }

}

RetCode ExportExec::CreateChunklist(vector<PartitionInfo *> pt_list,vector<PartitionID> ptid_list,
		 std::vector<ChunkID*>& chunk_id){
	int ret=rSuccess;
	int pt_num=0;
	for (auto ww : pt_list){
	 	int number_of_blocks=ww->get_number_of_blocks() ;
	 	unsigned number_of_chunks = ceil((number_of_blocks) / (float)1024);
	 	for (unsigned i = 0; i < number_of_chunks; i++) {
	 		chunk_id.push_back(new ChunkID(ptid_list[pt_num], i));
	 	}
	 	pt_num++;
	 }
	 return ret;
}
void ExportExec::AnnounceIAmExporting() {
  static char* load_output_info[7] = {
      "Exporting         \r", "Exporting.\r",     "Exporting..\r",    "Exporting...\r",
      "Exporting....\r",      "Exporting.....\r", "Exporting......\r"};
  static int count = 0;
  cout << load_output_info[count = (++count % 7)] << std::flush;
}

}  // namespace stmt_handler
}  // namespace claims
