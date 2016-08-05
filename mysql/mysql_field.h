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
 * /CLAIMS/mysql/mysql_field.h
 *
 *  Created on: Nov 25, 2015
 *      Author: chenlingyun,yukai
 *		   Email: geekchenlingyun@outlook.com
 * 
 * Description:
 *
 */

#ifndef MYSQL_MYSQL_FIELD_H_
#define MYSQL_MYSQL_FIELD_H_
#include<string>

#include "../common/data_type.h"
namespace claims {
namespace mysql {
class MySQLResultSet;
// pre-declearation
class MySQLField  {
  friend class ObMySQLResultSet;
 public:
  /**
   * 构造函数
   */
  MySQLField();
 private:
 public:
  const char *catalog_; /* Catalog for table */
  const char *db_; /* database name for table*/
  uint32_t length_; /*Width of column (create length) */
  uint16_t flags_; /* Div flags */
  uint8_t decimals_; /* Number of decimals in field */
  uint16_t charsetnr_; /* Character set */
  std::string tname_;
  std::string org_tname_;
  std::string column_name_;
  std::string org_cname_;
  column_type type_;

  // enum enum_field_types type_; /* Type of field. See mysql_com.h for types */
  // void *extension;

};
// end class ObMySQLField

}// namespace mysql
}  // namespace claims

#endif //  MYSQL_MYSQL_FIELD_H_ 
