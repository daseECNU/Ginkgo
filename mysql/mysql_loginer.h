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
 * /CMySQL/packet/mysql_eof_packet.h
 *
 *  Created on: Oct 14, 2015
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#ifndef MYSQL_LOGINER_H_
#define MYSQL_LOGINER_H_

#include<string>
#include "./mysql_connection.h"
#include "./mysql_define.h"
//#include "../mysql/mysql_server.h"
#include "packet/mysql_error_packet.h"
#include "packet/mysql_handshake_packet.h"
#include "packet/mysql_ok_packet.h"
using std::string;
namespace claims {
namespace mysql {
union CMysqlClientCapability {
  // CMysqlClientCapability();
  uint32_t cap_flags;
  // ref:http://dev.mysql.com/doc/internals/en/connection-phase.html#packet-Protocol::CapabilityFlags
  struct CapabilityFlags {
    uint32_t CLIENT_LONG_PASSWORD :1;
    uint32_t CLIENT_FOUND_ROWS :1;
    uint32_t CLIENT_LONG_FLAG :1;
    uint32_t CLIENT_CONNECT_WITH_DB :1;
    uint32_t CLIENT_NO_SCHEMA :1;
    uint32_t CLIENT_COMPRESS :1;
    uint32_t CLIENT_ODBC :1;
    uint32_t CLIENT_LOCAL_FILES :1;
    uint32_t CLIENT_IGNORE_SPACE :1;
    uint32_t CLIENT_PROTOCOL_41 :1;
    uint32_t CLIENT_INTERACTIVE :1;
    uint32_t CLIENT_SSL :1;
    uint32_t CLIENT_IGNORE_SIGPIPE :1;
    uint32_t CLIENT_TRANSACTIONS :1;
    uint32_t CLIENT_RESERVED :1;
    uint32_t CLIENT_SECURE_CONNECTION :1;
    uint32_t CLIENT_MULTI_STATEMENTS :1;
    uint32_t CLIENT_MULTI_RESULTS :1;
    uint32_t CLIENT_PS_MULTI_RESULTS :1;
    uint32_t CLIENT_PLUGIN_AUTH :1;
    uint32_t CLIENT_CONNECT_ATTRS :1;
    uint32_t CLIENT_PLUGIN_AUTH_LENENC_CLIENT_DATA :1;
    uint32_t CLIENT_RESERVED_NOT_USE :10;
  } CapabilityFlags;
};

class CMysqlLoginer {
 public:
  struct LoginInfo {
    union CMysqlClientCapability capability_;
    uint32_t max_message_length_;
    uint8_t character_set_;
    string user_name_;
    string auth_;
    string db_;
  };

 public:
  CMysqlLoginer();
  ~CMysqlLoginer();

  int shake_hand(const CMysqlConnection& session);
  int login(const CMysqlConnection& session);
  int check_authority(const CMysqlConnection& session);
  int receive_authority(const CMysqlConnection& session);
  int send_authority_res(const CMysqlConnection& session);
  int check_authority();

  int write_data(int fd, char *buffer, int len);
  int read_data(int fd, char *buffer, int len);

  char *get_buffer() {  // TODO(cly): use memory pool
    return buffer_;
  }

 private:
  char *buffer_;
  LoginInfo login_info_;
};
}  // namespace mysql
}  // namespace claims
#endif  // MYSQL_LOGINER_H_
