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
 * /CMySQL/mysql_result_set.h
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#ifndef PACKET_MYSQL_PACKET_HEADER_H_
#define PACKET_MYSQL_PACKET_HEADER_H_

#include <stdint.h>
namespace claims {
namespace mysql {
class MySQLPacketHeader {
 public:
  MySQLPacketHeader(): length_(0), seq_(0) { }
 public:
  uint32_t length_;         /* MySQL packet length not include packet header */
  uint8_t  seq_;            /* MySQL packet sequence */
};
}  // namespace mysql
}  // namespace claims
#endif  // PACKET_MYSQL_PACKET_HEADER_H_
