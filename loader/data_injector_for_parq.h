#ifndef LOADER_DATA_INJECTOR_FOR_PARQ_H_
#define LOADER_DATA_INJECTOR_FOR_PARQ_H_
#include "./table_parquet_writer.h"
#include "../common/file_handle/file_handle_imp.h"
#include "./hdfs_loader.h"
#include "../catalog/table.h"
#include "./data_injector.h"
#include "../common/error_define.h"
using claims::common::FileOpenFlag;
using claims::catalog::TableDescriptor;
using std::vector;
using std::string;

class Block;
class BlockStreamBase;
class Schema;
class PartitionFunction;
namespace claims {
namespace loader {

class DataInjectorForParq {
  friend class TableParquetWriter;

 public:
  DataInjectorForParq(TableDescriptor* table, const string col_separator = "|",
                      const string row_separator = "\n");
  ~DataInjectorForParq();
  // get string,insert to all partition multi-thread
  //  RetCode InsertFromStringMultithread(const vector<string>& tuples,
  //                                      ExecutedResult* result);
  // update number of block
  RetCode UpdateCatalog(FileOpenFlag open_flag);
  static void* HandleTuple(void* ptr);
  RetCode SetTableState(FileOpenFlag open_flag, ExecutedResult* result);
  RetCode PrepareLocalPartBuffer(
      map<int, vector<BlockStreamBase*>>& part_buffer);
  RetCode DestroyLocalPartBuffer(
      map<int, vector<BlockStreamBase*>>& part_buffer);
  // use DataInjector:: GetTupleTerminatedBy()  GetTupleTerminatedByFromHdfs()
  RetCode LoadFromFileMultiThread(vector<string> input_file_names,
                                  FileOpenFlag open_flag,
                                  ExecutedResult* result);
  RetCode InsertFromStringMultithread(const vector<string>& tuples,
                                      ExecutedResult* result);
  inline RetCode AddRowIdColumn(string& tuple_string);
  inline RetCode CheckAndToValue(string tuple_string, void* tuple_buffer,
                                 RawDataSource raw_data_source,
                                 vector<Validity>& columns_validities);
  RetCode FlushNotFullBlock(map<int, vector<BlockStreamBase*>>& part_buffer);
  RetCode InsertSingleTuple(void* tuple_buffer,
                            map<int, vector<BlockStreamBase*>>& part_buffer);
  RetCode InsertTupleIntoParquet(
      int partkey_index, void* tuple_buffer,
      map<int, vector<BlockStreamBase*>>& part_buffer);

 private:
  TableDescriptor* table_;
  TableFileConnector& connector_;
  HdfsLoader* hdfsloader_;
  Schema* table_schema_;

  // partition key index to write_path
  map<int, vector<string>> write_path_;
  // <partition_key_index,partition number>
  map<int, int> part_key_to_num_;
  // <partition_key_index, projection_id>
  map<int, int> part_to_proj_;
  // partkey to partition
  //  map<int, vector<size_t>> blocks_per_partition_;
  string col_separator_;
  string row_separator_;
  uint64_t& row_id_in_table_;

  // multi-thread
  std::list<DataInjector::LoadTask>* task_lists_ = NULL;
  SpineLock* task_list_access_lock_ = NULL;
  semaphore* tuple_count_sem_in_lists_;
  int thread_index_ = 0;
  map<int, vector<TableParquetWriter*>> writers_;
  map<int, vector<Lock>> write_locks_parq_;
  //  SpineLock row_id_lock_;
  semaphore finished_thread_sem_;
  // should be bool type,
  int all_tuple_read_ = 0;
  RetCode multi_thread_status_ = rSuccess;
  ExecutedResult* result_;
};
} /* namespace loader */
} /* namespace claims */
#endif  // LOADER_DATA_INJECTOR_FOR_PARQ_H_
