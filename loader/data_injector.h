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
 * /Claims/loader/data_injector.h
 *
 *  Created on: Oct 22, 2015
 *      Author: yukai
 *       Email: yukai2014@gmail.com
 *
 * Description: class for injecting data from files or string
 *
 */

#ifndef LOADER_DATA_INJECTOR_H_
#define LOADER_DATA_INJECTOR_H_
#include <list>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../common/error_define.h"
#include "../common/hash.h"
#include "../catalog/table.h"
#include "./validity.h"
#include "../common/file_handle/file_handle_imp.h"
#include "hdfs_loader.h"
#include "../common/data_type.h"

using claims::common::FileOpenFlag;
using claims::catalog::TableDescriptor;
using std::vector;
using std::string;
class SubTuple;
class Block;
class BlockStreamBase;
class Schema;
class PartitionFunction;
class ExecutedResult;

namespace claims {
namespace loader {
class TableFileConnector;
class DataInjector {
 public:
  struct LoadTask {
    std::string tuple_;
    std::string file_name_;
    uint64_t row_id_in_file_ = 0;
    LoadTask(std::string tuple, std::string file_name, uint64_t row_id)
        : tuple_(tuple), file_name_(file_name), row_id_in_file_(row_id) {}
    LoadTask() = default;
  };

 public:
  //  DataInjector() {}
  /**
   * @brief Method description: get necessary info from table and init
   * connector_
   * @param table: table to load
   * @param col_separator: column separator
   * @param row_separator: row separator
   */
  DataInjector(TableDescriptor* table, const string col_separator = "|",
               const string row_separator = "\n");
  /**
     * @brief Method description: get necessary info from table and init
     * connector_
     * @param col_separator: column separator
     * @param row_separator: row separator
     * @param tuple_start: row id start number
     * @param columns : column type info construct schema info
     * @param proj_columns:  proj_columns construct schema info
     * @param write_path : inital table connector
     * @param part_key_idx : partition column index
     * @param part_func_v : partition function vector
     * @param prj_index_vec : construct SubTuple class
     * @param tbl_name : table name
     */
  DataInjector(const string col_separator, const string row_separator,
               uint64_t tuple_start, vector<column_type> columns,
               vector<vector<column_type>> proj_columns,
               vector<vector<string>> write_path, vector<int> part_key_idx,
               vector<GeneralModuloFunction> part_func_v,
               vector<vector<unsigned>> prj_index_vec, string tbl_name);
  virtual ~DataInjector();

  /**
   * @brief Method description: load/append data from multiple files into table
   * @param file_names: the names of files to be read
   * @param open_flag: specify the way to write to data file:
   *        kCreateFile(meaning create or overwrite i.e., implies O_TRUNC) /
   *        kAppendFile(implies O_APPEND) /
   *        kReadFile( implies O_RDONLY)
   * @param sample_rate: the sample rate about write data into table
   * @return rSuccess if success or other on error
   */
  RetCode LoadFromFile(vector<string> input_file_names, FileOpenFlag open_flag,
                       ExecutedResult* result, double sample_rate = 1.0);

  /**
   * @brief Method description: insert tuples into table
   * @param tuples: the data to insert into tables, which may be a line or
   * multiple lines
   * @return rSuccess if success or other on error
   */
  RetCode InsertFromString(const string tuples, ExecutedResult* result);
  /**
   * @brief Method description: insert tuples into table by multithread
   * @param tuples: the the vectordata to insert into tables, which may be a
   * line or
   * multiple lines
   * @return rSuccess if success or other on error
   */
  RetCode InsertFromStringMultithread(const vector<string>& tuples,
                                      ExecutedResult* result);
  /**
   * @brief Method description: load/append data from multiple files into table
   * @param input_file_names: the names of files to be read
   * @param open_flag: specify the way to write to data file:
   *        kCreateFile(meaning create or overwrite i.e., implies O_TRUNC) /
   *        kAppendFile(implies O_APPEND)
   * @param start: start offset of every file
   * @param end: end offset of every file
   * @param total_nodes: for decide row_id
   * @param ldmsg: load finish info, include block_num of partition, logical
   * length
   * @return rSuccess if success or other on error
   */
  RetCode DistributedLoadMultiThread(vector<string> input_file_names,
                                     int open_flag, vector<uint64_t> start,
                                     vector<uint64_t> end, int total_nodes,
                                     LoadMsg& ldmsg);

 private:
  RetCode LoadFromFileSingleThread(vector<string> input_file_names,
                                   FileOpenFlag open_flag,
                                   ExecutedResult* result, double sample_rate);

  RetCode LoadFromFileMultiThread(vector<string> input_file_names,
                                  FileOpenFlag open_flag,
                                  ExecutedResult* result, double sample_rate);

  /**
   * @brief Method description: handle memory which store single line
   * @param tuple_buffer: single tuple memory
   * @return  rSuccess if succeed
   */
  RetCode InsertSingleTuple(void* tuple_buffer, Block* block_to_write,
                            vector<vector<BlockStreamBase*>>& local_pj_buffer);

  /**
   * @brief Method description: check the validity of the tuple string, and
   *        store it in tuple_buffer
   * @param tuple_string: raw tuple data to be insert
   * @param tuple_buffer: the address of memory where tuple data is stored
   * @param warning_indexs: store the index of columns which have warning
   * @return true if tuple is not valid even though there are some warnings
   */
  inline RetCode CheckAndToValue(string tuple_string, void* tuple_buffer,
                                 RawDataSource raw_data_source,
                                 vector<Validity>& columns_validities);

  /**
   * @brief Method description: add row_id column value
   */
  inline RetCode AddRowIdColumn(string& tuple_string);

  /**
   * @brief Method description: insert single tuple insert the proj_index
   * projection
   * @param proj_index: the id of projection
   * @param tuple_buffer: the memory of tuple to be write
   */
  RetCode InsertTupleIntoProjection(
      int proj_index, void* tuple_buffer, Block* block_to_write,
      vector<vector<BlockStreamBase*>>& local_pj_buffer);

  RetCode UpdateCatalog(FileOpenFlag open_flag);

  /**
   * @brief Method description: after handle all tuple, flush all block that are
   *        not full into file
   */
  RetCode FlushNotFullBlock(Block* block_to_write,
                            vector<vector<BlockStreamBase*>>& pj_buffer);

  RetCode PrepareInitInfo(FileOpenFlag open_flag);

  RetCode HandleSingleLine(string tuple_record, void* tuple_buffer,
                           string data_source, uint64_t row_id_in_raw_data,
                           ExecutedResult* result);

  static void* HandleTuple(void* ptr);

  RetCode SetTableState(FileOpenFlag open_flag, ExecutedResult* result);

  RetCode PrepareEverythingForLoading(vector<string> input_file_names,
                                      FileOpenFlag open_flag,
                                      ExecutedResult* result,
                                      HdfsLoader* hdfsloader_);
  RetCode PrepareEverythingForDistributed(vector<string> input_file_names,
                                          FileOpenFlag open_flag);

  RetCode FinishJobAfterLoading(FileOpenFlag open_flag);
  RetCode PrepareLocalPJBuffer(vector<vector<BlockStreamBase*>>& pj_buffer);

  RetCode DestroyLocalPJBuffer(vector<vector<BlockStreamBase*>>& pj_buffer);

 public:
  static RetCode CheckFiles(vector<string> input_file_names,
                            ExecutedResult* result, HdfsLoader* hdfsloader_);
  static string GenerateDataValidityInfo(const Validity& vali,
                                         TableDescriptor* table, int line,
                                         const string& file);
  static void AnnounceIAmLoading();
  static istream& GetTupleTerminatedBy(ifstream& ifs, string& res,
                                       const string& terminator);
  static bool GetTupleTerminatedByFromHdfs(void*& buffer,
                                           HdfsLoader* hdfsloader_,
                                           string& file_name, string& res,
                                           const string& terminator, int& pos,
                                           int& read_num, const int& length);
  static bool GetTupleFromHdfs(void*& buffer, HdfsLoader* hdfsloader_,
                               string& res, const string& terminator, int& pos,
                               int& read_num, uint64_t& total_read_num,
                               const int& length);
  static vector<size_t> getPart(char* fileName, int part);
  static size_t getOffset(FILE* fd, size_t start, size_t end);

 private:
  TableDescriptor* table_;
  string tbl_name_;
  TableFileConnector& connector_;
  TableFileConnector* connector_pointer_;
  Schema* table_schema_;
  vector<Schema*> projections_schema_;
  std::vector<std::string> file_list_;
  vector<vector<string>> write_path_;

  vector<PartitionFunction*> partition_functin_list_;
  vector<GeneralModuloFunction> part_func_list_;
  vector<int> partition_key_index_;
  vector<SubTuple*> sub_tuple_generator_;
  Block* sblock_;

  vector<vector<size_t>> blocks_per_partition_;
  vector<vector<size_t>> tuples_per_partition_;
  vector<vector<BlockStreamBase*>> pj_buffer_;

  string col_separator_;
  string row_separator_;
  uint64_t row_id_in_table_;

  // support multi-thread
  std::list<LoadTask>* task_lists_ = NULL;
  SpineLock* task_list_access_lock_ = NULL;
  semaphore* tuple_count_sem_in_lists_;
  int thread_index_ = 0;

  //  SpineLock row_id_lock_;
  semaphore finished_thread_sem_;

  // should be bool type,
  // but in order to use __sync_..... function it changed to be int type
  int all_tuple_read_ = 0;
  RetCode multi_thread_status_ = rSuccess;
  ExecutedResult* result_;
  HdfsLoader* hdfsloader_;

  /******************debug********************/
 public:
  static uint64_t total_get_substr_time_;
  static uint64_t total_check_string_time_;
  static uint64_t total_to_value_time_;
  static uint64_t total_check_and_to_value_func_time_;
  static uint64_t total_check_and_to_value_time_;
  static uint64_t total_insert_time_;
  static uint64_t total_add_time_;

  static uint64_t total_lock_tuple_buffer_time_;
  static uint64_t total_lock_pj_buffer_time_;
  static uint64_t total_get_task_time_;

  static uint64_t total_read_sem_time_;
  static uint64_t total_unread_sem_time_;
  static uint64_t total_read_sem_fail_count_;
  static uint64_t total_unread_sem_fail_count_;

  static uint64_t total_append_warning_time_;
};

} /* namespace loader */
} /* namespace claims */

#endif  // LOADER_DATA_INJECTOR_H_
