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
 * /Claims/loader/data_injector_for_parq.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: zzh
 *       Email: 358088534@qq.com
 *
 * Description:
 *
 */
#include "./data_injector_for_parq.h";
#include <glog/logging.h>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <utility>
#include "../catalog/attribute.h"
#include "../catalog/catalog.h"
#include "../catalog/partitioner.h"
#include "../catalog/projection.h"
#include "../catalog/projection_binding.h"
#include "../common/Block/BlockStream.h"
#include "../common/data_type.h"
#include "../common/error_no.h"
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/ids.h"
#include "../common/memory_handle.h"
#include "../common/Schema/Schema.h"
#include "../common/Schema/TupleConvertor.h"
#include "../Config.h"
#include "../Debug.h"
#include "../Environment.h"
#include "../utility/lock.h"
#include "../utility/lock_guard.h"
#include "../utility/thread_pool.h"
#include "../utility/Timer.h"
#include "./table_file_connector.h"
#include "./hdfs_loader.h"
#define hdfsreadlength 64 * 1024 * 1024
using claims::common::Malloc;
using claims::common::FileOpenFlag;
namespace claims {
namespace loader {
uint64_t GetBlockNumber(unsigned tuple_size, int64_t number_of_tuple) {
  int block_fix = BLOCK_SIZE - sizeof(unsigned);
  int div = block_fix / tuple_size;
  if ((number_of_tuple % div) == 0)
    return number_of_tuple / div;
  else
    return (number_of_tuple / div) + 1;
}
DataInjectorForParq::DataInjectorForParq(TableDescriptor* table,
                                         const string col_separator = "|",
                                         const string row_separator = "\n")
    : table_(table),
      col_separator_(col_separator),
      row_separator_(row_separator),
      row_id_in_table_(table_->row_number_),
      connector_(table_->get_connector()),
      hdfsloader_(new HdfsLoader()) {
  table_schema_ = table_->getSchema();
  // initialize different partition key
  for (int i = 0; i < table_->getNumberOfProjection(); i++) {
    Attribute partition_attribute =
        table_->getProjectoin(i)->getPartitioner()->getPartitionKey();
    int hash_key_index =
        table_->getProjectoin(i)->getAttributeIndex(partition_attribute);
    if (part_key_to_num_.find(hash_key_index) == part_key_to_num_.end()) {
      part_key_to_num_[hash_key_index] =
          table_->getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
      part_to_proj_.insert(make_pair(hash_key_index, i));
    } else {
      // two projection has same partition key but diff projection number(not
      // support) like
      unsigned part_num =
          table_->getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
      if (part_key_to_num_[hash_key_index] < part_num) {
        part_key_to_num_[hash_key_index] = part_num;
        part_to_proj_[hash_key_index] = i;
      }
    }
  }
  table_->setPartProjMap(part_to_proj_);
  vector<string> parq_write_path;
  vector<Lock> part_locks;
  for (auto it = part_to_proj_.begin(); it != part_to_proj_.end(); it++) {
    int j = table_->getProjectoin(it->second)
                ->getPartitioner()
                ->getNumberOfPartitions();
    for (int i = 0; i < j; i++) {
      stringstream ss;
      ss << Config::data_dir << 'T' << table_->table_id_ << 'P' << it->first
         << 'N' << i << ".parq";
      string tbl_name = ss.str();
      parq_write_path.push_back(tbl_name);
      part_locks.push_back(Lock());
    }
    write_path_.insert(make_pair(it->first, parq_write_path));
    write_locks_parq_.insert(make_pair(it->first, part_locks));
    parq_write_path.clear();
  }
}

DataInjectorForParq::~DataInjectorForParq() {
  write_path_.clear();
  part_key_to_num_.clear();
  part_to_proj_.clear();
  for (auto wri_iter : writers_) {
    for (auto iter : wri_iter.second) {
      delete iter;
    }
  }
  delete table_schema_;
}

inline RetCode DataInjectorForParq::AddRowIdColumn(string& tuple_string) {
  uint64_t row_id_value = __sync_fetch_and_add(&row_id_in_table_, 1L);
  // make sure tuple string in a uniform format(always has a column
  // separator before row separator) with format of what is get from INSERT
  tuple_string = std::to_string(row_id_value) + col_separator_ + tuple_string +
                 col_separator_;
  return rSuccess;
}
RetCode DataInjectorForParq::SetTableState(FileOpenFlag open_flag,
                                           ExecutedResult* result) {
  int ret = rSuccess;
  if (FileOpenFlag::kCreateFile == open_flag) {
    /*
     * Before overwriting data, it is need to unbind all projection, as well
     * as
     * set row_id 0
     */
    row_id_in_table_ = 0;

    LOG(INFO) << "\n--------------------Load  Begin!------------------------\n";
  } else {
    LOG(INFO) << "\n------------------Append  Begin!-----------------------\n";
  }
  for (int i = 0; i < table_->getNumberOfProjection(); i++) {
    if (table_->getProjectoin(i)->getPartitioner()->allPartitionBound()) {
      bool res =
          Catalog::getInstance()->getBindingModele()->UnbindingEntireProjection(
              table_->getProjectoin(i)->getPartitioner());
      if (res) {
        LOG(INFO) << "unbound entire projection " << i << " in table "
                  << table_->getTableName() << std::endl;
      } else {
        result->SetError("inner error");
        LOG(ERROR) << "failed to unbind entire projection " << i << " in table "
                   << table_->getTableName() << std::endl;
        return rFailure;
      }
    }
  }
  return ret;
}
RetCode DataInjectorForParq::LoadFromFileMultiThread(
    vector<string> input_file_names, FileOpenFlag open_flag,
    ExecutedResult* result) {
  int ret = rSuccess;
  int file_count = 0;
  uint64_t row_id_in_file = 0;
  uint64_t inserted_tuples_in_file = 0;
  uint64_t total_tuple_count = 0;
  string hdfs_name = "HDFS:";
  string tuple_record = "";
  multi_thread_status_ = rSuccess;
  all_tuple_read_ = false;
  result_ = result;
  thread_index_ = 0;
  cout << endl;

  // if load, delete all files
  if (kCreateFile == open_flag) {
    EXEC_AND_LOG(ret, connector_.DeleteAllTableFiles(),
                 "deleted all table files", "failed to delete all table files");
    table_->InitTableData();
  }
  EXEC_AND_RETURN_ERROR(ret, connector_.Open(), " failed to openconnector");
  // prepare load handler, clean memory buffer, check file accessible
  EXEC_AND_RETURN_ERROR(ret, SetTableState(open_flag, result),
                        "failed to set table state");
  // init parquet writers
  for (auto iter : connector_.file_handles_parq_) {
    vector<TableParquetWriter*> temp;
    for (auto it : iter.second) {
      temp.push_back(new TableParquetWriter(table_, it));
    }
    writers_[iter.first] = temp;
    temp.clear();
  }
  // check files
  EXEC_AND_RETURN_ERROR(
      ret, DataInjector::CheckFiles(input_file_names, result, hdfsloader_),
      "some files are unaccessible");

  int thread_count = Config::load_thread_num;
  assert(thread_count >= 1);
  task_lists_ = new std::list<DataInjector::LoadTask>[thread_count];
  task_list_access_lock_ = new SpineLock[thread_count];
  tuple_count_sem_in_lists_ = new semaphore[thread_count];
  for (int i = 0; i < thread_count; ++i) {
    Environment::getInstance()->getThreadPool()->AddTask(HandleTuple, this);
  }

  // start to read every raw data file
  GETCURRENTTIME(start_read_time);
  for (auto file_name : input_file_names) {
    if (file_name.find(hdfs_name) == 0) {
      file_name = file_name.substr(hdfs_name.length());
      LOG(INFO) << "Now handle hdfs_file :" << file_name << endl;
      void* buffer;
      buffer = Malloc(hdfsreadlength + 1);
      int pos = 0;
      int read_num = 0;
      const int length = hdfsreadlength;
      ret = hdfsloader_->OpenHdfsFile(file_name);
      if (ret != rSuccess) {
        cout << "open file error" << endl;
      }
      while (DataInjector::GetTupleTerminatedByFromHdfs(
                 buffer, hdfsloader_, file_name, tuple_record, row_separator_,
                 pos, read_num, length) ||
             tuple_record != "") {
        if (tuple_record == "\r")
          tuple_record = "";  // eliminate the effect of '\r'
        // just to tell everyone "i am alive!!!"
        if (0 == row_id_in_file % 50000) DataInjector::AnnounceIAmLoading();
        ++row_id_in_file;

        int list_index = row_id_in_file % thread_count;
        {  // push into one thread local tuple pool
          LockGuard<SpineLock> guard(
              task_list_access_lock_[list_index]);  /// lock/sem
          task_lists_[list_index].push_back(std::move(
              DataInjector::LoadTask(tuple_record, file_name, row_id_in_file)));
        }

        tuple_count_sem_in_lists_[list_index].post();
      }
      free(buffer);
      buffer = NULL;
      hdfsloader_->CloseHdfsFile();
    } else {
      ifstream input_file(file_name.c_str());
      LOG(INFO) << "Now handle file :" << file_name << endl;
      // read every tuple
      while (DataInjector::GetTupleTerminatedBy(input_file, tuple_record,
                                                row_separator_) ||
             tuple_record != "") {
        if (tuple_record == "\r")
          tuple_record = "";  // eliminate the effect of '\r'
        if (0 == row_id_in_file % 50000) DataInjector::AnnounceIAmLoading();
        ++row_id_in_file;
        int list_index = row_id_in_file % thread_count;
        {  // push into one thread local tuple pool
          LockGuard<SpineLock> guard(
              task_list_access_lock_[list_index]);  /// lock/sem
          task_lists_[list_index].push_back(std::move(
              DataInjector::LoadTask(tuple_record, file_name, row_id_in_file)));
        }

        tuple_count_sem_in_lists_[list_index].post();
      }
      input_file.close();
      ++file_count;
    }
  }
  __sync_add_and_fetch(&all_tuple_read_, 1);
  LOG(INFO) << "used "
            << GetElapsedTimeInUs(start_read_time) / 1000000.0  // 5 sec
            << " time to read all " << file_count
            << " file and insert them into pool " << endl;
  for (int i = 0; i < thread_count; ++i)
    LOG(INFO) << "after reading all tuple, tuple count sem value of thread "
              << i << " is :" << tuple_count_sem_in_lists_[i].get_value();
  // waiting for all threads finishing task
  for (int i = 0; i < thread_count; ++i) finished_thread_sem_.wait();
  LOG(INFO) << " all threads finished its job " << endl;
  if (rSuccess != (ret = multi_thread_status_)) {
    ELOG(multi_thread_status_, "failed to load using multi-thread ");
    return ret;
  }
  // <partition_key_index, <partition_num, meta_length_vector>>
  map<int, map<int, vector<uint32_t>>>& meta_offset = table_->getMetalength();
  map<int, map<int, vector<uint64_t>>>& meta_start_pos =
      table_->getMetaStartPos();
  map<int, map<int, vector<uint64_t>>>& file_length = table_->getFilelength();
  // finalize and write footer
  for (auto iter : writers_) {
    for (int i = 0; i < iter.second.size(); i++) {
      // finalize and update
      iter.second[i]->Finalize();
      meta_offset[iter.first][i].push_back(iter.second[i]->GetmetaPos());
      meta_start_pos[iter.first][i].push_back(
          iter.second[i]->GetMetaStartPos());
      file_length[iter.first][i].push_back(iter.second[i]->GetFileLength());
    }
  }

  EXEC_AND_LOG(ret, connector_.Close(), "closed connector.",
               "Failed to close connector. ret:" << ret);
  // update block number

  for (int i = 0; i < thread_count; ++i) task_lists_[i].clear();
  DELETE_ARRAY(task_lists_);
  DELETE_ARRAY(task_list_access_lock_);
  DELETE_ARRAY(tuple_count_sem_in_lists_);
  EXEC_AND_ONLY_LOG_ERROR(ret, UpdateCatalog(open_flag),
                          "failed to update catalog information. ret:" << ret);
  LOG(INFO) << "\n-----------------------"
            << (kCreateFile == open_flag ? "Load" : "Append")
            << " End!-----------------------\n";
  return ret;
}

/*
 * multi-thread version of InsertFromString
 */
RetCode DataInjectorForParq::InsertFromStringMultithread(
    const vector<string>& tuples, ExecutedResult* result) {
  int ret = rSuccess;
  uint64_t row_id_in_file = 0;
  uint64_t inserted_tuples_in_file = 0;
  uint64_t total_tuple_count = 0;
  multi_thread_status_ = rSuccess;
  all_tuple_read_ = false;
  result_ = result;
  thread_index_ = 0;
  cout << endl;

  EXEC_AND_RETURN_ERROR(ret, connector_.Open(), " failed to openconnector");
  // prepare load handler, clean memory buffer, check file accessible
  EXEC_AND_RETURN_ERROR(ret, SetTableState(kAppendFile, result),
                        "failed to set table state");
  // init parquet writers
  for (auto iter : connector_.file_handles_parq_) {
    vector<TableParquetWriter*> temp;
    for (auto it : iter.second) {
      temp.push_back(new TableParquetWriter(table_, it));
    }
    writers_[iter.first] = temp;
    temp.clear();
  }
  int thread_count = Config::load_thread_num;
  assert(thread_count >= 1);
  task_lists_ = new std::list<DataInjector::LoadTask>[thread_count];
  task_list_access_lock_ = new SpineLock[thread_count];
  tuple_count_sem_in_lists_ = new semaphore[thread_count];
  for (int i = 0; i < thread_count; ++i) {
    Environment::getInstance()->getThreadPool()->AddTask(HandleTuple, this);
  }
  GETCURRENTTIME(start_read_time);
  for (auto& c : tuples) {
    string::size_type cur = 0;
    int prev_cur = 0;
    while (string::npos != (cur = c.find('\n', prev_cur))) {
      string tuple_record = c.substr(prev_cur, cur - prev_cur - 1);
      prev_cur = cur + 1;
      ++row_id_in_file;
      int list_index = row_id_in_file % thread_count;
      {  // push into one thread local tuple pool
        LockGuard<SpineLock> guard(
            task_list_access_lock_[list_index]);  /// lock/sem
        task_lists_[list_index].push_back(std::move(
            DataInjector::LoadTask(tuple_record, "", row_id_in_file)));
      }
      tuple_count_sem_in_lists_[list_index].post();
    }
  }

  __sync_add_and_fetch(&all_tuple_read_, 1);
  LOG(INFO) << "used "
            << GetElapsedTimeInUs(start_read_time) / 1000000.0  // 5 sec
            << " time to read all tuple and insert them into pool " << endl;
  for (int i = 0; i < thread_count; ++i)
    LOG(INFO) << "after reading all tuple, tuple count sem value of thread "
              << i << " is :" << tuple_count_sem_in_lists_[i].get_value();
  // waiting for all threads finishing task
  for (int i = 0; i < thread_count; ++i) finished_thread_sem_.wait();
  LOG(INFO) << " all threads finished its job " << endl;
  if (rSuccess != (ret = multi_thread_status_)) {
    ELOG(multi_thread_status_, "failed to load using multi-thread ");
    return ret;
  }
  // <partition_key_index, <partition_num, meta_length_vector>>
  map<int, map<int, vector<uint32_t>>>& meta_offset = table_->getMetalength();
  map<int, map<int, vector<uint64_t>>>& meta_start_pos =
      table_->getMetaStartPos();
  map<int, map<int, vector<uint64_t>>>& file_length = table_->getFilelength();
  // finalize and write footer
  for (auto iter : writers_) {
    for (int i = 0; i < iter.second.size(); i++) {
      // finalize and update
      iter.second[i]->Finalize();
      meta_offset[iter.first][i].push_back(iter.second[i]->GetmetaPos());
      meta_start_pos[iter.first][i].push_back(
          iter.second[i]->GetMetaStartPos());
      file_length[iter.first][i].push_back(iter.second[i]->GetFileLength());
    }
  }

  EXEC_AND_LOG(ret, connector_.Close(), "closed connector.",
               "Failed to close connector. ret:" << ret);
  // update block number

  for (int i = 0; i < thread_count; ++i) task_lists_[i].clear();
  DELETE_ARRAY(task_lists_);
  DELETE_ARRAY(task_list_access_lock_);
  DELETE_ARRAY(tuple_count_sem_in_lists_);
  EXEC_AND_ONLY_LOG_ERROR(ret, UpdateCatalog(kAppendFile),
                          "failed to update catalog information. ret:" << ret);
  LOG(INFO) << "\n-----------------------"
            << "Insert "
            << " End!-----------------------\n";
  return ret;
}
static void* DataInjectorForParq::HandleTuple(void* ptr) {
  DataInjectorForParq* injector = static_cast<DataInjectorForParq*>(ptr);
  string tuple_to_handle = "";
  string file_name = "";
  uint64_t row_id_in_file = 0;
  DataInjector::LoadTask task;
  RetCode ret = rSuccess;
  int self_thread_index = __sync_fetch_and_add(&injector->thread_index_, 1);
  LOG(INFO) << "my thread_index is " << self_thread_index << endl;
  LOG(INFO)
      << "before handling tuple, thread " << self_thread_index
      << " tuple count sem value is :"
      << injector->tuple_count_sem_in_lists_[self_thread_index].get_value()
      << endl;
  /*
   * store the validity of every column data,
   * the extra 2 validity[(-1, rTooManyColumn), (-1, rTooFewColumn)]
   * is used for too many columns and too few columns
   */
  vector<Validity> columns_validities;
  void* tuple_buffer = Malloc(injector->table_schema_->getTupleMaxSize());
  if (NULL == tuple_buffer) {
    ret = rNoMemory;
    injector->multi_thread_status_ = ret;
    injector->finished_thread_sem_.post();
    return NULL;
  }

  map<int, vector<BlockStreamBase*>> part_buffer;
  injector->PrepareLocalPartBuffer(part_buffer);

  while (true) {
    if (injector->multi_thread_status_ != rSuccess) break;
    if (injector->all_tuple_read_ == 1) {
      if (!injector->tuple_count_sem_in_lists_[self_thread_index]
               .try_wait()) {  ///// lock/sem
        LOG(INFO) << "all tuple in pool is handled \n";
        EXEC_AND_LOG(ret, injector->FlushNotFullBlock(part_buffer),
                     "flush all last block that are not full",
                     "failed to flush all last block.");
        if (ret != rSuccess)  // it is not need to use lock
          injector->multi_thread_status_ = ret;
        DELETE_PTR(tuple_buffer);
        injector->DestroyLocalPartBuffer(part_buffer);
        injector->finished_thread_sem_.post();
        return NULL;  // success. all tuple is handled
      }
      // get tuple from list without lock, as
      // producer thread is over, there are only consumer threads
      task = std::move(injector->task_lists_[self_thread_index].front());
      injector->task_lists_[self_thread_index].pop_front();
    } else {
      // waiting for new tuple read from file
      if (!injector
               ->tuple_count_sem_in_lists_[self_thread_index]  ///// lock/sem
               .try_wait()) {                                  ///// lock/sem
        continue;
      }
      // get tuple from pool with lock
      LockGuard<SpineLock> guard(
          injector->task_list_access_lock_[self_thread_index]);  ///// lock/sem
      task = std::move(
          injector->task_lists_[self_thread_index].front());  ///// lock/sem
      injector->task_lists_[self_thread_index].pop_front();   ///// lock/sem
    }
    tuple_to_handle = task.tuple_;
    file_name = task.file_name_;
    row_id_in_file = task.row_id_in_file_;

    if (0 == row_id_in_file % 50000) DataInjector::AnnounceIAmLoading();

    EXEC_AND_ONLY_LOG_ERROR(ret, injector->AddRowIdColumn(tuple_to_handle),
                            "failed to add row_id column for tuple.");
    if (ret != rSuccess) {  // it is not need to use lock
      injector->multi_thread_status_ = ret;
      break;
    }

    // check
    columns_validities.clear();
    memset(tuple_buffer, 0, injector->table_schema_->getTupleMaxSize());
    if (rSuccess != (ret = injector->CheckAndToValue(
                         tuple_to_handle, tuple_buffer, RawDataSource::kFile,
                         columns_validities))) {
      LOG(INFO) << "Data is in file name: " << file_name
                << "  Line: " << row_id_in_file;
      injector->multi_thread_status_ = ret;
      break;
    }
    // only handle data warnings, because of no data error
    if (!injector->result_->HasEnoughWarning()) {
      for (auto it : columns_validities) {
        string validity_info = DataInjector::GenerateDataValidityInfo(
            it, injector->table_, row_id_in_file, file_name);
        injector->result_->AtomicAppendWarning(validity_info);  /////  lock/sem
      }
    }
    if (rSuccess !=
        (ret = injector->InsertSingleTuple(tuple_buffer, part_buffer))) {
      LOG(ERROR) << "failed to insert tuple in " << file_name << " at line "
                 << row_id_in_file << ".";
    }
    if (ret != rSuccess) {
      injector->multi_thread_status_ = ret;
      break;
    }
  }
  DELETE_PTR(tuple_buffer);
  injector->DestroyLocalPartBuffer(part_buffer);
  injector->finished_thread_sem_.post();
}
inline RetCode DataInjectorForParq::CheckAndToValue(
    string tuple_string, void* tuple_buffer, RawDataSource raw_data_source,
    vector<Validity>& columns_validities) {
  return table_schema_->CheckAndToValue(tuple_string, tuple_buffer,
                                        col_separator_, raw_data_source,
                                        columns_validities);
}
RetCode DataInjectorForParq::PrepareLocalPartBuffer(
    map<int, vector<BlockStreamBase*>>& part_buffer) {
  for (auto it : write_path_) {
    for (int i = 0; i < it.second.size(); i++) {
      part_buffer[it.first].push_back(
          BlockStreamBase::createBlock(table_->getSchema(),
                                       BLOCK_SIZE - sizeof(unsigned)));
    }
  }
}

RetCode DataInjectorForParq::DestroyLocalPartBuffer(
    map<int, vector<BlockStreamBase*>>& part_buffer) {
  for (auto it : part_buffer) {
    for (auto iter : it.second) {
      delete iter;
    }
    it.second.clear();
  }
  part_buffer.clear();
}

RetCode DataInjectorForParq::InsertTupleIntoParquet(
    int partkey_index, void* tuple_buffer,
    map<int, vector<BlockStreamBase*>>& part_buffer) {
  int ret = rSuccess;
  // get tuple partition number
  unsigned tuple_size = table_schema_->getTupleMaxSize();
  void* partition_key_addr =
      table_schema_->getColumnAddess(partkey_index, tuple_buffer);
  int partNum =
      table_schema_->getcolumn(partkey_index).operate->getPartitionValue(
          partition_key_addr, part_key_to_num_[partkey_index]);
  void* block_tuple_addr =
      part_buffer[partkey_index][partNum]->allocateTuple(tuple_size);
  if (block_tuple_addr == NULL) {
    LockGuard<Lock> guard(write_locks_parq_[partkey_index][partNum]);
    writers_[partkey_index][partNum]->AppendRows(
        part_buffer[partkey_index][partNum]);
    part_buffer[partkey_index][partNum]->setEmpty();
    block_tuple_addr =
        part_buffer[partkey_index][partNum]->allocateTuple(tuple_size);
  }
  int copy_size = table_schema_->copyTuple(tuple_buffer, block_tuple_addr);
  if (copy_size != tuple_size) {
    LOG(ERROR) << "copy " << copy_size << " length memory not equals "
               << tuple_size << std::endl;
  }
  return ret;
}

RetCode DataInjectorForParq::InsertSingleTuple(
    void* tuple_buffer, map<int, vector<BlockStreamBase*>>& part_buffer) {
  int ret = rSuccess;
  map<int, vector<BlockStreamBase*>>::iterator it = part_buffer.begin();
  while (it != part_buffer.end()) {
    ret = InsertTupleIntoParquet(it->first, tuple_buffer, part_buffer);
    it++;
  }
  return ret;
}
RetCode DataInjectorForParq::FlushNotFullBlock(
    map<int, vector<BlockStreamBase*>>& part_buffer) {
  int ret = rSuccess;
  for (auto it : part_buffer) {
    for (int i = 0; i < it.second.size(); i++) {
      if (!it.second[i]->Empty()) {
        LockGuard<Lock> guard(write_locks_parq_[it.first][i]);
        writers_[it.first][i]->AppendRows(part_buffer[it.first][i]);
      }
    }
  }
  return ret;
}
RetCode DataInjectorForParq::UpdateCatalog(FileOpenFlag open_flag) {
  int ret = rSuccess;
  for (int i = 0; i < table_->getNumberOfProjection(); i++) {
    for (
        int j = 0;
        j < table_->getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
        j++) {
      int hash_key_index = table_->getProjectoin(i)->getAttributeIndex(
          table_->getProjectoin(i)->getPartitioner()->getPartitionKey());
      int64_t number_of_tuple = writers_[hash_key_index][j]->GetRowCount();
      Schema* schema = table_->getProjectoin(i)->getSchema();
      unsigned tuple_size = schema->getTupleMaxSize();
      uint64_t number_of_blocks = GetBlockNumber(tuple_size, number_of_tuple);
      if (kCreateFile == open_flag) {
        table_->getProjectoin(i)
            ->getPartitioner()
            ->RegisterPartitionWithNumberOfBlocks(j, number_of_blocks);
      }
      if (kAppendFile == open_flag) {
        table_->getProjectoin(i)
            ->getPartitioner()
            ->RegisterPartitionWithNumberOfBlocksPar(j, number_of_blocks);
      }
      delete schema;
    }
  }
  table_->file_num_++;
  //  cout << table_->tableName << "file num is  " << table_->file_num_ << endl;
  return ret;
}

} /* namespace loader */
} /* namespace claims */
