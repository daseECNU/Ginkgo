/*
 * Schema.cpp
 *
 *  Created on: Jun 7, 2013
 *      Author: wangli
 */
#include "./Schema.h"
#include <glog/logging.h>
#include <string>
#include <iostream>
#include <vector>

#include "../../common/memory_handle.h"
Schema::Schema(const std::vector<column_type>& columns) : columns(columns) {}
Schema::Schema(const Schema& r) { this->columns = r.columns; }
Schema::~Schema() {
//  for (auto& i : columns) DELETE_PTR(i.operate);
//  columns.clear();
}

unsigned Schema::getncolumns() const { return columns.size(); }

void Schema::displayTuple(const void* tuple_start_address,
                          const char* spliter) const {
  for (unsigned i = 0; i < columns.size(); i++) {
    DLOG(INFO) << columns[i].operate->toString(
                      getColumnAddess(i, tuple_start_address)) << spliter;
  }
  DLOG(INFO) << endl;
}

std::string Schema::getColumnValue(const void* tuple_start_address, int i) {
  return columns[i].operate->toString(getColumnAddess(i, tuple_start_address));
}

std::vector<col_type> Schema::getColumnVec() {
  vector<col_type> res;
  for (int i = 0; i < columns.size(); ++i) {
    col_type c_type;
    c_type.nullable_ = columns[i].nullable;
    c_type.size_ = columns[i].size;
    c_type.type_ = columns[i].type;
    res.push_back(c_type);
  }
  return res;
}
bool Schema::hasSameSchema(Schema* schema) {
  if (this->getSchemaType() != schema->getSchemaType()) return false;
  if (this->getncolumns() != schema->getncolumns()) return false;
  for (unsigned i = 0; i < columns.size(); i++) {
    if (!(columns[i] == schema->getcolumn(i))) return false;
  }
  return true;
}
