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
 * /CLAIMS/mysql/mysql_field.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: chenlingyun,yukai
 *		   Email: geekchenlingyun@outlook.com
 * 
 * Description:
 *
 */
#include "mysql_field.h"

//#include "mysql_util.h"
namespace claims {
namespace mysql {
MySQLField::MySQLField()
    : catalog_("def"),
      db_("claims"),
      length_(28),
      flags_(0),
      decimals_(0x1f),
      charsetnr_(0x0008),
	  tname_(""),
	  org_tname_(""),
	  org_cname_(""),
	  type_(data_type::t_string),
	  column_name_("@@version_comment"){
}
}  // end of namespace mysql
}  // end of namespace claims

