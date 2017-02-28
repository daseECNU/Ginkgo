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
 * /CMySQL/for_copyright.h
 *
 *  Created on: Oct 13, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */

#ifndef MYSQL_UTIL_H_
#define MYSQL_UTIL_H_

#include <sys/time.h>
#include <time.h>

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "mysql_define.h"
#include "../common/data_type.h"
using std::string;

namespace claims {
namespace mysql {
class CMysqlUtil {
 public:
	enum MYSQL_PROTOCOL_TYPE {
		TEXT = 1,
		BINARY,
	};
  enum EMySQLFieldType{
    MYSQL_TYPE_DECIMAL,
    MYSQL_TYPE_TINY,
    MYSQL_TYPE_SHORT,
    MYSQL_TYPE_LONG,
    MYSQL_TYPE_FLOAT,
    MYSQL_TYPE_DOUBLE,
    MYSQL_TYPE_NULL,
    MYSQL_TYPE_TIMESTAMP,
    MYSQL_TYPE_LONGLONG,
    MYSQL_TYPE_INT24,
    MYSQL_TYPE_DATE,
    MYSQL_TYPE_TIME,
    MYSQL_TYPE_DATETIME,
    MYSQL_TYPE_YEAR,
    MYSQL_TYPE_NEWDATE,
    MYSQL_TYPE_VARCHAR,
    MYSQL_TYPE_BIT,
    MYSQL_TYPE_NEWDECIMAL = 246,
    MYSQL_TYPE_ENUM = 247,
    MYSQL_TYPE_SET = 248,
    MYSQL_TYPE_TINY_BLOB = 249,
    MYSQL_TYPE_MEDIUM_BLOB = 250,
    MYSQL_TYPE_LONG_BLOB = 251,
    MYSQL_TYPE_BLOB = 252,
    MYSQL_TYPE_VAR_STRING = 253,
    MYSQL_TYPE_STRING = 254,
    MYSQL_TYPE_GEOMETRY = 255,
    MYSQL_TYPE_NOT_DEFINED = 65535
  };

	static inline EMySQLFieldType get_MysqlType(column_type ttype) {
	    switch (ttype.type) {
	      case t_int:
	        return MYSQL_TYPE_INT24;
	      case t_float:
	        return MYSQL_TYPE_FLOAT;
	      case t_double:
	        return MYSQL_TYPE_DOUBLE;
	      case t_u_long:
	        return MYSQL_TYPE_LONGLONG;
	      case t_string:
	        return MYSQL_TYPE_VAR_STRING;
	      case t_date:
	        return MYSQL_TYPE_DATE;
	      case t_time:
	        return MYSQL_TYPE_TIME;
	      case t_datetime:
	        return MYSQL_TYPE_DATETIME;
	      case t_decimal:
	        /* here the 1000 is the same as the  */
	        return MYSQL_TYPE_DECIMAL;
	      case t_smallInt:
	        return MYSQL_TYPE_SHORT;
	      case t_u_smallInt:
	        return MYSQL_TYPE_TINY;
	      case t_boolean:
	        return MYSQL_TYPE_BIT;
	      default:
	    	  return MYSQL_TYPE_VARCHAR;
	    }
	}
  CMysqlUtil();
  virtual ~CMysqlUtil();

 public:
  static int store_null(char *buf, int64_t len, int64_t  &pos);
  static int store_int1(char *buf, int64_t len, int8_t v, int64_t &pos);
  static int store_int2(char *buf, int64_t len, int16_t v, int64_t &pos);
  static int store_int3(char *buf, int64_t len, int32_t v, int64_t &pos);
  static int store_int4(char *buf, int64_t len, int32_t v, int64_t &pos);
  static int store_int8(char *buf, int64_t len, int64_t v, int64_t &pos);
  static int store_str(char *buf, int64_t len, const char *str, int64_t &pos);
  static int store_length(char *buf, int64_t len,
                          uint64_t length, int64_t &pos);
  static int store_str_v(char *buf, int64_t len, const char *str,
                         const uint64_t length, int64_t &pos);
  static int store_str_vzt(char *buf, int64_t len, const char *str,
                           const uint64_t length, int64_t &pos);
  static int store_obstr_nzt(char *buf, int64_t len, string str, int64_t &pos);
  static void get_uint3(char *&pos, uint32_t &v);
  static void get_uint4(char *&pos, uint32_t &v);
  static void get_uint1(char *&pos, uint8_t &v);
  static int get_mysql_type(EMySQLFieldType &, uint8_t &, uint32_t &, column_type &);
  static int get_statement(char *buffer, char *statement);
  static int store_obstr(char *buf, int64_t len, string str, int64_t &pos) {
    return store_str_v(buf, len, str.c_str(), str.length(), pos);
  }
  static int64_t get_current_time() {
    timeval time;
    gettimeofday(&time, NULL);
    return ((int64_t)time.tv_sec)*1000000 + time.tv_usec;
  }
  static void print_current_time() {
  timeval tv;
  tm t;
  gettimeofday(&tv, NULL);
  localtime_r(&(tv.tv_sec), &t);
  printf("[%d-%d-%d %d:%d:%d.%6.6d] ",
        t.tm_year+1900, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min,
        t.tm_sec, static_cast<int>(tv.tv_usec));
  }
};
}  // namespace mysql
}  // namespace claims
#endif  // MYSQL_UTIL_H_
