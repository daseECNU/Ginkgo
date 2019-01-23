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
 * /CLAIMS/stmt_handler/load_exec.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: cswang
 *       Email: cs_wang@infosys.com
 *
 * Description:
 *    this file is the function body of class LoadExec.
 */

#include <assert.h>
#include <vector>
#include <string>
#include "../stmt_handler/load_exec.h"
#include "../Environment.h"
#include "../loader/data_injector.h"
#include "../loader/data_injector_for_parq.h"
#include "../common/file_handle/hdfs_connector.h"
#include "../node_manager/base_node.h"
#include "../common/Schema/TupleConvertor.h"
using std::vector;
using claims::loader::DataInjector;
using claims::loader::DataInjectorForParq;
using claims::LoadPlanAtom;
using namespace claims::common;
namespace claims {
namespace stmt_handler {
#define NEWRESULT
#define NEW_LOADER
const int step = 500;  // for distributed loading
LoadExec::LoadExec(AstNode *stmt) : StmtExec(stmt) {
  // TODO Auto-generated constructor stub
  assert(stmt_);
  load_ast_ = dynamic_cast<AstLoadTable *>(stmt_);
  tablename_ = load_ast_->table_name_;
  table_desc_ = Environment::getInstance()->getCatalog()->getTable(tablename_);
}

LoadExec::~LoadExec() {
  // TODO Auto-generated destructor stub
}
/**
 * @brief load data from file system.
 * @details check whether the table we have created or not. forbid to load data
 * into an nonexistent table.
 *  then add path names from path node to a vector path_names,
 *  create new HdfsLoader, load data.
 */
RetCode LoadExec::Execute(ExecutedResult *exec_result) {
  RetCode ret = rSuccess;

  TableDescriptor *table = Environment::getInstance()->getCatalog()->getTable(
      load_ast_->table_name_);

  string column_separator = load_ast_->column_separator_;
  string tuple_separator = load_ast_->tuple_separator_;
  AstExprList *path_node = dynamic_cast<AstExprList *>(load_ast_->path_);

  LOG(INFO) << "load file's name:" << std::endl;
  std::vector<string>
      path_names;  // save the name of files which should be loaded
  // for test: the path name is:   /home/imdb/data/tpc-h/part.tbl
  while (path_node) {
    AstExprConst *data = dynamic_cast<AstExprConst *>(path_node->expr_);
    LOG(INFO) << data->data_ << std::endl;
    path_names.push_back(data->data_);
    path_node = dynamic_cast<AstExprList *>(path_node->next_);
  }

  // split sign should be considered carefully, in case of it may be "||" or
  // "###"

  LOG(INFO) << "The separator are :" + column_separator + "," +
                   tuple_separator + ", The sample is " << load_ast_->sample_
            << ", mode is " << load_ast_->mode_ << std::endl;
  if (Config::distributed_load) {
    GETCURRENTTIME(start_time);
    DistributeLoad(path_names, Config::load_node_num, column_separator,
                   tuple_separator, table, load_ast_->mode_);
    double load_time_ms = GetElapsedTime(start_time);
    ostringstream oss;
    oss << "distributed load data successfully (" << load_time_ms / 1000.0
        << " sec) ";
    exec_result->SetResult(oss.str(), NULL);
  } else {
    GETCURRENTTIME(start_time);
    if (Config::enable_parquet == 1) {
      DataInjectorForParq *injector =
          new DataInjectorForParq(table, column_separator, tuple_separator);
      ret = injector->LoadFromFileMultiThread(
          path_names, static_cast<FileOpenFlag>(load_ast_->mode_), exec_result);
      double load_time_ms = GetElapsedTime(start_time);
      if (ret != rSuccess) {
        LOG(ERROR) << "failed to load files: ";
        for (auto it : path_names) {
          LOG(ERROR) << it << " ";
        }
        LOG(ERROR) << " into table " << table->getTableName() << endl;

        if (exec_result->error_info_ == "")
          exec_result->SetError("failed to load data");
      } else {
        ostringstream oss;
        oss << "load data successfully (" << load_time_ms / 1000.0 << " sec) ";
        exec_result->SetResult(oss.str(), NULL);
      }
      DELETE_PTR(injector);
    } else {
      DataInjector *injector =
          new DataInjector(table, column_separator, tuple_separator);
      LOG(INFO) << "complete create new DataInjector for test." << std::endl;
      ret = injector->LoadFromFile(path_names,
                                   static_cast<FileOpenFlag>(load_ast_->mode_),
                                   exec_result, load_ast_->sample_);
      double load_time_ms = GetElapsedTime(start_time);
      LOG(INFO) << " load time: " << load_time_ms / 1000.0 << " sec" << endl;
      if (ret != rSuccess) {
        LOG(ERROR) << "failed to load files: ";
        for (auto it : path_names) {
          LOG(ERROR) << it << " ";
        }
        LOG(ERROR) << " into table " << table->getTableName() << endl;

        if (exec_result->error_info_ == "")
          exec_result->SetError("failed to load data");
      } else {
        ostringstream oss;
        oss << "load data successfully (" << load_time_ms / 1000.0 << " sec) ";
        exec_result->SetResult(oss.str(), NULL);
      }
      DELETE_PTR(injector);
    }
  }
  return ret;
}

RetCode LoadExec::DistributeLoad(std::vector<string> path_names, int parallel,
                                 string col_sep, string row_sep,
                                 TableDescriptor *table, int open_flag) {
  vector<int64_t> lengths;
  vector<NodeID> live_list = MasterNode::GetInstance()->GetAllNodeID();
  vector<col_type> columns = table->getSchema()->getColumnVec();
  vector<string> cols;
  string tbl_name = table->getTableName();
  for (int i = 0; i < columns.size(); ++i) {
    std::ostringstream os;
    boost::archive::binary_oarchive oa(os);
    oa << columns[i];
    string content = os.str();
    cols.push_back(content);
  }
  vector<vector<string>> proj_columns;
  for (int i = 0; i < table->getNumberOfProjection(); ++i) {
    vector<string> col_types;
    vector<Column> pro_cols = table->getProjectoin(i)->getColumnList();
    for (int j = 0; j < pro_cols.size(); ++j) {
      std::ostringstream os;
      boost::archive::binary_oarchive oa(os);
      col_type c((*pro_cols[j].attrType).type, (*pro_cols[j].attrType).nullable,
                 (*pro_cols[j].attrType).size);
      oa << c;
      col_types.push_back(os.str());
    }
    proj_columns.push_back(col_types);
  }

  vector<vector<string>> write_path;
  vector<int> part_key_idx;
  vector<string> part_func_v;
  vector<vector<unsigned>> prj_index_vec;

  for (int i = 0; i < table->getNumberOfProjection(); i++) {
    vector<string> wp;
    for (int j = 0;
         j < table->getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
         ++j) {
      string path = PartitionID(table->getProjectoin(i)->getProjectionID(), j)
                        .getPathAndName();
      wp.push_back(path);
    }
    write_path.push_back(wp);
    Attribute partition_attribute =
        table->getProjectoin(i)->getPartitioner()->getPartitionKey();
    int hash_key_index =
        table->getProjectoin(i)->getAttributeIndex(partition_attribute);
    part_key_idx.push_back(hash_key_index);
    GeneralModuloFunction pf =
        *(GeneralModuloFunction *)(table->getProjectoin(i)
                                       ->getPartitioner()
                                       ->getPartitionFunction());
    std::ostringstream os_func;
    boost::archive::binary_oarchive oa_func(os_func);
    oa_func << pf;
    part_func_v.push_back(os_func.str());
    vector<unsigned> prj_index;
    vector<Attribute> prj_attrs = table->getProjectoin(i)->getAttributeList();
    prj_index.clear();
    for (int j = 0; j < prj_attrs.size(); j++) {
      prj_index.push_back(prj_attrs[j].index);
    }
    prj_index_vec.push_back(prj_index);
  }
  for (auto file : path_names) {
    if (getPart(file, parallel, row_sep[0], lengths) == rFailure) {
      return rFailure;
    }
    // tuple number means already load tuple numbers
    uint64_t start = 0, end = 0, tup_num = 0;
    int total_nodes = live_list.size();
    for (int i = 0, j = 0; i < lengths.size() - 1;
         ++i, j = (j + 1) % total_nodes) {
      start = lengths[i];
      end = lengths[i + 1];
      try {
        caf::scoped_actor self;
        auto target_actor = MasterNode::GetInstance()->GetNodeActorFromId(j);
        LoadInfo l(cols, proj_columns, write_path, part_key_idx, prj_index_vec,
                   part_func_v, tbl_name);
        self->send(target_actor, LoadPlanAtom::value, file, open_flag, col_sep,
                   row_sep, start, end, tup_num, total_nodes, l);
        MasterNode::GetInstance()->AddLoadJob();
      } catch (caf::bind_failure &e) {
        LOG(ERROR)
            << "master sending load plan binds port error when connecting "
               "remote actor";
      } catch (caf::network_error &e) {
        LOG(ERROR)
            << "master sending load plan connect to remote node error due to "
               "network error!";
      }
    }
    lengths.clear();
    while (int last_job = MasterNode::GetInstance()->GetLoadJob()) {
      sleep(1);
    }
  }
  return rSuccess;
}

RetCode LoadExec::getOffset(int64_t start, int64_t end, int64_t &result,
                            char sep) {
  if (start + step >= end) {
    return -1;
  }
  int ret = hdfsSeek(fs_, file_, start);
  if (ret != 0) {
    std::cout << "hdfsSeek fail\n";
    return -1;
  }
  vector<char> dataSeg;
  dataSeg.resize(step);
  size_t readByte = hdfsRead(fs_, file_, &dataSeg[0], step);
  if (readByte == -1) {
    return -1;
  }
  for (int i = 0; i < readByte; i++) {
    if (dataSeg[i] == sep) {
      result = i + start;
      return 0;
    }
  }
  return getOffset(start + step, end, result, sep);
}

RetCode LoadExec::getPart(string path, int part, char sep,
                          vector<int64_t> &offset) {
  fs_ = claims::common::HdfsConnector::Instance();
  hdfsFileInfo *info = hdfsGetPathInfo(fs_, path.c_str());
  if (info == NULL) {
    return rFailure;
  }
  int64_t totalLength = info->mSize;
  offset.push_back(0);
  if (part == 1) {
    offset.push_back(totalLength);
    return rSuccess;
  }
  file_ = hdfsOpenFile(fs_, path.c_str(), O_RDONLY, 0, 0, 0);
  if (file_ == NULL) {
    std::cout << " file open failure !\n";
    return rFailure;
  }
  int64_t avg = totalLength / part;
  int64_t start = avg, end = avg * 2;

  for (int i = 0; i < part - 1; ++i) {
    int64_t retValue = 0;
    int res = getOffset(start, end, retValue, sep);
    start += avg;
    end += avg;
    if (res == 0) {
      // if success
      offset.push_back(retValue);
    }
  }
  offset.push_back(totalLength);
  return rSuccess;
}
RetCode LoadExec::GetWriteAndReadTables(
    ExecutedResult &result,
    vector<vector<pair<int, string>>> &stmt_to_table_list) {
  RetCode ret = rSuccess;
  vector<pair<int, string>> table_list;
  pair<int, string> table_status;
  SemanticContext sem_cnxt;
  ret = load_ast_->SemanticAnalisys(&sem_cnxt);
  if (rSuccess != ret) {
    result.SetError("Semantic analysis error.\n" + sem_cnxt.error_msg_);
    LOG(ERROR) << "semantic analysis error result= : " << ret;
    cout << "semantic analysis error result= : " << ret << endl;
    return ret;
  } else {
    table_status.first = 1;
    table_status.second = load_ast_->table_name_;
    table_list.push_back(table_status);
    stmt_to_table_list.push_back(table_list);
    return ret;
  }
}
}  // namespace stmt_handler
}  // namespace claims
