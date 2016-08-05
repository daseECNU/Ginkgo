/*
 * mysql_row.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: ccccly
 */

#include<string>
#include "./mysql_row.h"
#include "../../common/data_type.h"
#include "../../common/Logging.h"
#include "mysql_util.h"
namespace claims {
namespace mysql {
MysqlRow::MysqlRow() {
}

MysqlRow::~MysqlRow() {
}


int MysqlRow::serialize(char *buffer, int64_t len, int64_t& pos) {
  int64_t cell_index = 0;
  const column_type *cell;
  uint64_t table_id = 0;
  int64_t pos_bk = pos;
  int ret = C_SUCCESS;
  for (cell_index = 0; cell_index < column_num_; cell_index++) {
	  cell = &schema_->getcolumn(cell_index);
	  cell_str(*cell, buffer, len, pos, cell_index);
  }

  if (C_SUCCESS != ret) {
    pos = pos_bk;
  }
  return ret;
}
uint64_t MysqlRow::get_serialize_size() {
  // @bug
  return 0;
}
int MysqlRow::cell_str(const column_type &obj, char *buf,
                             const int64_t len, int64_t &pos,
                             int64_t cell_index) const {
  int ret = C_SUCCESS;
  if( NULL == obj.type )
	  ret = null_cell_str(obj, buf, len, pos, cell_index);
  else
	  ret = anything_but_null_cell_str(obj, buf, len, pos, cell_index);
  return ret;
}

int MysqlRow::null_cell_str(const column_type &obj, char *buf,
                                  const int64_t len, int64_t &pos,
                                  int64_t cell_index) const {
  int ret = C_SUCCESS;
  if (len - pos <= 0) {
    ret = C_SIZE_OVERFLOW;
  }
  ret = CMysqlUtil::store_null(buf, len, pos);
  return ret;
}

int MysqlRow::anything_but_null_cell_str(const column_type &obj, char *buf,
                                     const int64_t len, int64_t &pos,int64_t cell_index) const {
  int ret = C_SUCCESS;
  uint64_t length = 0;
  /* skip 1 byte to store length */
  string str = obj.operate->toString(schema_->getColumnAddess(cell_index,tuple_));
  length = str.length();
  if((ret = CMysqlUtil::store_length(buf, len, length, pos))==C_SUCCESS) {
	  if(len-pos >=length) {
		  memcpy(buf+pos,str.c_str(),length);
	  }
  }
  pos += length;
  return ret;
}
}  // namespace mysql
}  // namespace claims






