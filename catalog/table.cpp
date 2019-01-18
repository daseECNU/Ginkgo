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
 * /Claims/catalog/table.cpp
 *
 *  Created on: 2013-9-22
 *      Author: liyongfeng, wangli, yukai
 *       Email: yukai2014@gmail.com
 *
 * Description:
 *
 */
#include "../catalog/table.h"

#include <string>
#include <vector>
#include <map>
#include "../common/file_handle/file_handle_imp_factory.h"
#include "../common/Schema/SchemaFix.h"
#include "../loader/table_file_connector.h"
using claims::common::FilePlatform;
using claims::utility::LockGuard;
using claims::common::rTruncateReset;
using claims::common::rTruncateFileFail;
namespace claims {
namespace catalog {

// only for deserialization
TableDescriptor::TableDescriptor() {}

TableDescriptor::TableDescriptor(const string& name, const TableID table_id)
    : tableName(name), table_id_(table_id), row_number_(0), file_num_(0) {
  write_connector_ = new TableFileConnector(
      Config::local_disk_mode ? FilePlatform::kDisk : FilePlatform::kHdfs, this,
      common::kAppendFile);
}

TableDescriptor::~TableDescriptor() {
  if (!projection_list_.empty()) {
    delete write_connector_;
    for (auto projection : projection_list_) {
      delete projection;
    }
  }
}

void TableDescriptor::addAttribute(Attribute attr) {
  LockGuard<SpineLock> guard(update_lock_);
  attributes.push_back(attr);
}

// make sure the format of attname is column name
bool TableDescriptor::addAttribute(string attname, data_type dt,
                                   unsigned max_length, bool unique,
                                   bool can_be_null) {
  LockGuard<SpineLock> guard(update_lock_);
  attname = tableName + '.' + attname;
  /*check for attribute rename*/

  for (unsigned i = 0; i < attributes.size(); i++) {
    if (attributes[i].attrName == attname) return false;
  }
  Attribute att(table_id_, attributes.size(), attname, dt, max_length, unique,
                can_be_null);
  attributes.push_back(att);
  return true;
}

void TableDescriptor::InitFileConnector() {
  write_connector_ = new TableFileConnector(
      Config::local_disk_mode ? FilePlatform::kDisk : FilePlatform::kHdfs, this,
      common::kAppendFile);
}

void TableDescriptor::InitTableData() {
  row_number_ = 0;
  has_deleted_tuples_ = false;
  if (Config::enable_parquet) {
    file_num_ = 0;
    meta_start_pos_.clear();
    file_len_.clear();
    meta_len_.clear();
  } else {
    if (Config::distributed_load) {
      for (map<int, vector<vector<uint64_t>>>::iterator iter =
               logical_files_length_dist_.begin();
           iter != logical_files_length_dist_.end(); iter++) {
        for (int i = 0; i < iter->second.size(); ++i) {
          for (int j = 0; j < iter->second[i].size(); ++j) {
            iter->second[i][j] = 0;
          }
        }
      }
      for (int i = 0; i < getNumberOfProjection(); i++) {
        for (int j = 0;
             j < projection_list_[i]->getPartitioner()->getNumberOfPartitions();
             ++j) {
          projection_list_[i]->getPartitioner()->initPartitionData(j);
        }
      }
    } else {
      for (int i = 0; i < getNumberOfProjection(); i++) {
        for (int j = 0;
             j < projection_list_[i]->getPartitioner()->getNumberOfPartitions();
             ++j) {
          projection_list_[i]->getPartitioner()->initPartitionData(j);
          logical_files_length_[i][j] = 0;
        }
      }
    }
  }
}

RetCode TableDescriptor::createHashPartitionedProjection(
    const vector<ColumnOffset>& column_list, Attribute partition_attribute,
    unsigned number_of_partitions) {
  //  LockGuard<SpineLock> guard(update_lock_);
  if (!update_lock_.try_lock()) {
    LOG(WARNING) << "failed to lock update_lock, may someone is loading or "
                    "inserting data";
    return common::rResourceIsLocked;
  }
  ProjectionID projection_id(
      table_id_, projection_list_.size() == 0 ? 0 : getMaxProjectionID() + 1);
  //  ProjectionID projection_id(table_id_, projection_list_.size());

  ProjectionDescriptor* projection = new ProjectionDescriptor(projection_id);

  for (unsigned i = 0; i < column_list.size(); i++) {
    projection->addAttribute(attributes[column_list[i]]);
  }

  PartitionFunction* hash_function =
      PartitionFunctionFactory::createGeneralModuloFunction(
          number_of_partitions);
  projection->DefinePartitonier(number_of_partitions, partition_attribute,
                                hash_function);

  projection_list_.push_back(projection);
  //  AddProjectionLocks(number_of_partitions);
  //  UpdateConnectorWithNewProj(number_of_partitions);
  write_connector_->UpdateWithNewProj();
  update_lock_.release();
  return rSuccess;
}

RetCode TableDescriptor::createHashPartitionedProjection(
    const vector<Attribute>& attribute_list, Attribute partition_attr,
    unsigned number_of_partitions) {
  //  LockGuard<SpineLock> guard(update_lock_);
  if (!update_lock_.try_lock()) {
    LOG(WARNING) << "failed to lock update_lock, may someone is loading or "
                    "inserting data";
    return common::rResourceIsLocked;
  }
  //  ProjectionID projection_id(table_id_, projection_list_.size());
  ProjectionID projection_id(
      table_id_, projection_list_.size() == 0 ? 0 : getMaxProjectionID() + 1);

  ProjectionDescriptor* projection = new ProjectionDescriptor(projection_id);

  for (unsigned i = 0; i < attribute_list.size(); i++) {
    projection->addAttribute(attribute_list[i]);
  }

  PartitionFunction* hash_function =
      PartitionFunctionFactory::createGeneralModuloFunction(
          number_of_partitions);
  projection->DefinePartitonier(number_of_partitions, partition_attr,
                                hash_function);

  projection_list_.push_back(projection);
  //  AddProjectionLocks(number_of_partitions);
  write_connector_->UpdateWithNewProj();
  update_lock_.release();
  return rSuccess;
}

// void TableDescriptor::AddProjectionLocks(int number_of_partitions) {
//  vector<Lock> locks;
//  for (int i = 0; i < number_of_partitions; ++i) locks.push_back(Lock());
//  partitions_write_lock_.push_back(locks);
//}

bool TableDescriptor::isExist(const string& name) const {
  for (unsigned i = 0; i < attributes.size(); i++) {
    if (attributes[i].attrName == name) return true;
  }
  return false;
}

ProjectionDescriptor* TableDescriptor::getProjectoin(
    ProjectionOffset pid) const {
  if (pid >= 0) {
    for (auto projection : projection_list_) {
      if (projection->getProjectionID().projection_off == pid) {
        return projection;
      }
    }
  } else {
    LOG(WARNING) << "no projection has been created on this table" << endl;
    return NULL;
  }
  //  if (pid >= 0 && pid < projection_list_.size()) {
  //    return projection_list_.at(pid);
  //  } else {
  //    LOG(WARNING) << "no projection has been created on this table" << endl;
  //    return NULL;
  //  }
}

unsigned TableDescriptor::getNumberOfProjection() const {
  return projection_list_.size();
}
unsigned TableDescriptor::getMaxProjectionID() const {
  return projection_list_.back()->getProjectionID().projection_off;
}
Attribute TableDescriptor::getAttribute(const std::string& name) const {
  // format of name is colname, not tablename.colname
  stringstream ss;
  ss << tableName.c_str() << "." << name.c_str();
  //  cout<<"partition_name :"<<name<<endl; // for test--by yu
  for (unsigned i = 0; i < attributes.size(); i++) {
    //    cout<<attributes[i].attrName<<endl; // for test -- by yu
    //    cout<<"--"<<attributes[i].attrName<<"--"<<ss.str()<<endl;
    if (attributes[i].attrName == ss.str()) {
      return attributes[i];
    }
  }
  printf("The attribute name [%s] does not match any attribute!\n",
         ss.str().c_str());
  assert(false);
  return NULL;
}

Attribute TableDescriptor::getAttribute2(const std::string& name) const {
  // format of name is tablename.colname
  stringstream ss;
  ss << name.c_str();
  for (unsigned i = 0; i < attributes.size(); i++) {
    //    cout<<"--"<<attributes[i].attrName<<endl;
    if (attributes[i].attrName == ss.str()) {
      return attributes[i];
    }
  }
  printf("The attribute name [%s] does not match any attribute!\n",
         ss.str().c_str());
  assert(false);
  return NULL;
}

vector<vector<string>> TableDescriptor::GetAllPartitionsPath() const {
  vector<vector<string>> write_paths;
  for (int i = 0; i < getNumberOfProjection(); i++) {
    vector<string> prj_write_path;
    prj_write_path.clear();
    for (int j = 0;
         j < projection_list_[i]->getPartitioner()->getNumberOfPartitions();
         ++j) {
      prj_write_path.push_back(
          PartitionID(getProjectoin(i)->getProjectionID(), j).getPathAndName());
    }
    write_paths.push_back(prj_write_path);
  }
  LOG(INFO) << " table:" << getTableName() << " has the below partition:";
  for (auto prj : write_paths)
    for (auto part : prj) LOG(INFO) << part;
  return write_paths;
}
Schema* TableDescriptor::getSchema() const {
  const vector<Attribute> attributes = getAttributes();
  std::vector<column_type> columns;
  for (unsigned i = 0; i < attributes.size(); i++) {
    columns.push_back(*(attributes[i].attrType));
  }
  return new SchemaFix(columns);
}
RetCode TableDescriptor::CreateLogicalFilesLength(
    vector<uint64_t> part_files_length) {
  logical_files_length_.push_back(part_files_length);
  return rSuccess;
}
RetCode TableDescriptor::SetLogicalFilesLength(unsigned projection_offset,
                                               unsigned partition_offset,
                                               unsigned file_length) {
  logical_files_length_[projection_offset][partition_offset] = file_length;
  return rSuccess;
}
RetCode TableDescriptor::SetLogicalFilesLengthDist(int node_id,
                                                   unsigned projection_offset,
                                                   unsigned partition_offset,
                                                   unsigned file_length) {
  logical_files_length_dist_[node_id][projection_offset][partition_offset] =
      file_length;
  return rSuccess;
}

RetCode TableDescriptor::TruncateFilesFromTable() {
  RetCode ret = rSuccess;
  if (Config::enable_parquet) {
    map<int, int> part_key_to_num;
    map<int, int> part_to_proj;
    for (int i = 0; i < getNumberOfProjection(); i++) {
      Attribute partition_attribute =
          getProjectoin(i)->getPartitioner()->getPartitionKey();
      int hash_key_index =
          getProjectoin(i)->getAttributeIndex(partition_attribute);
      if (part_key_to_num.find(hash_key_index) == part_key_to_num.end()) {
        part_key_to_num[hash_key_index] =
            getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
        part_to_proj.insert(make_pair(hash_key_index, i));
      } else {
        // two projection has same partition key but diff projection number(not
        // support) like
        unsigned part_num =
            getProjectoin(i)->getPartitioner()->getNumberOfPartitions();
        if (part_key_to_num[hash_key_index] < part_num) {
          part_key_to_num[hash_key_index] = part_num;
          part_to_proj[hash_key_index] = i;
        }
      }
    }
    // for every
    for (auto ptp : part_to_proj) {
      map<int, vector<uint64_t>>& parq_file = file_len_[ptp.first];
      if (parq_file.size() == 0) {
        uint64_t file_length = 0;
        for (unsigned int i = 0; i < getProjectoin(ptp.second)
                                         ->getPartitioner()
                                         ->getNumberOfPartitions();
             i++) {
          ret =
              write_connector_->TruncateFileFromPrtn(ptp.first, i, file_length);
        }
        if (rTruncateFileFail == ret) {
          return ret;
        }
      } else {
        for (auto file : parq_file) {
          uint64_t file_length = 0;
          for (auto length : file.second) {
            file_length += length;
          }
          ret = write_connector_->TruncateFileFromPrtn(ptp.first, file.first,
                                                       file_length);
          if (rTruncateFileFail == ret) {
            return ret;
          }
          if (rTruncateReset == ret) {
            InitTableData();
          }
        }
      }
    }
  } else {
    if (Config::distributed_load) {
      for (map<int, vector<vector<uint64_t>>>::iterator iter =
               logical_files_length_dist_.begin();
           iter != logical_files_length_dist_.end(); iter++) {
        for (int i = 0; i < iter->second.size(); i++) {
          for (int j = 0; j < iter->second[i].size(); ++j) {
            ret = write_connector_->TruncateFileFromPrtnDist(
                i, j, iter->first, iter->second[i][j]);
            if (rTruncateFileFail == ret) {
              return ret;
            } else {
              if (rTruncateReset == ret) {
                InitTableData();
              }
              write_connector_->SaveUpdatedFileLengthToCatalog();
            }
          }
        }
      }

    } else {
      for (int i = 0; i < getNumberOfProjection(); i++) {
        for (int j = 0;
             j < projection_list_[i]->getPartitioner()->getNumberOfPartitions();
             ++j) {
          ret = write_connector_->TruncateFileFromPrtn(
              i, j, logical_files_length_[i][j]);
          if (rTruncateFileFail == ret) {
            return ret;
          } else {
            if (rTruncateReset == ret) {
              InitTableData();
            }
            write_connector_->SaveUpdatedFileLengthToCatalog();
          }
        }
      }
    }
  }
  return ret;
}

} /* namespace catalog */
} /* namespace claims */
