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
#include <string>
#include "./mysql_handshake_packet.h"

#include "../../common/Logging.h"
using std::string;
namespace claims {
namespace mysql {
MysqlHandshakePacket::MysqlHandshakePacket() {
  const char* str = "5.";
  protocol_version_ = 10;  // Protocol::HandshakeV10
  string server_version(str);
  server_version_ = server_version;
  thread_id_ = 100;  //
  memset(scramble_buff_, 'a', 9);
  server_capabilities_ = 63487;
  server_language_ = 8;  // latin1_swedish_ci
  server_status_ = 0;  // no this value in mysql protocol document
  memset(plugin_, 0, sizeof(plugin_));
  memset(plugin2_, 'b', 12);
  terminated_ = '\0';
}

MysqlHandshakePacket::~MysqlHandshakePacket() {
}

void MysqlHandshakePacket::set_thread_id(uint32_t id) {
  thread_id_ = id;
}

int MysqlHandshakePacket::serialize(char *buffer, int64_t len, int64_t &pos) {
  /*------------------报文体-----------------           字节数      实现方式
   *protocol_version_: 协议版本号                         1       store_int1
   *server_version_: 服务器版本信息                        3
   *thread_id_: 服务器线程号                              4        store_int4
   *scramble_buff_: "ob中将挑战随机数和填充值合并了"         9        memcpy
   *server_capabilities_: 服务器权能标志                   2       store_int2
   *server_language_: 字符编码                           1        store_int1
   *server_status_: 服务器状态                            2       store_int2
   *char plugin_[13]: "ob中服务器权能，挑战长度和填充值的和"  13        memcpy
   *char plugin2_[12]: 第二波挑战随机数，至少12字节         12        memcpy
   *terminated_: 结束                                   1        memset(0)
   *------------------报文头-----------------
   *下面是要放到报文头中
   *(header size)pkt_len: 消息长度				          3        store_int3
   *(header seq)0： 消息序号                              1        store_int1

   [casa@casa ~]$ mysql -h 10.11.1.174 -P2345 --debug-info
   ERROR 2013 (HY000): Lost connection to MySQL server at 'reading authorization packet', system error: 0
   User time 0.00, System time 0.00
   Maximum resident set size 2012, Integral resident set size 0
   Non-physical pagefaults 611, Physical pagefaults 0, Swaps 0
   Blocks in 0 out 0, Messages in 0 out 0, Signals 0
   Voluntary context switches 2, Involuntary context switches 2
   *(header
   */
  /*MySqlLog("start to serialize packet header and packet.");
   int64_t start_pos = pos;
   pos += C_MYSQL_PACKET_HEADER_SIZE;

   CMysqlUtil::store_int1(buffer, len, protocol_version_, pos);
   //	cout<<"-----------------------------------pos: "<<pos<<endl;
   /*服务器版本信息*/
//	cout<<"服务器版本信息长度： "<<server_version_.length()<<endl;
//	memcpy(buffer+pos,server_version_.c_str(),3);pos=pos+3;
//  CMysqlUtil::store_str_vzt(buffer, len, server_version_.c_str(),
//                            server_version_.length(), pos);
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  CMysqlUtil::store_int4(buffer, len, thread_id_, pos);
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  memcpy(buffer + pos, scramble_buff_, 9);
//  pos = pos + 9;
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  CMysqlUtil::store_int2(buffer, len, server_capabilities_, pos);
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  CMysqlUtil::store_int1(buffer, len, server_language_, pos);
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  CMysqlUtil::store_int2(buffer, len, server_status_, pos);
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  memcpy(buffer + pos, plugin_, 13);
//  pos = pos + 13;
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  memcpy(buffer + pos, plugin2_, 12);
//  pos = pos + 12;
////	cout<<"-----------------------------------pos: "<<pos<<endl;
//  memset(buffer + pos, 0, 1);
//  pos = pos + 1;
//  cout << "-----------------------------------pos: " << pos << endl;
//  uint32_t pkt_len = static_cast<uint32_t>(pos - start_pos
//      - C_MYSQL_PACKET_HEADER_SIZE);
//  ;
//  CMysqlUtil::store_int3(buffer, len, pkt_len, start_pos);
//  //	cout<<"-----------------------------------pos: "<<pos<<endl;
//  CMysqlUtil::store_int1(buffer, len, 0, start_pos);
//  //	cout<<"-----------------------------------pos: "<<pos<<endl;
//  return C_SUCCESS;
//  //三个字节的 length=48;
//  //一个字节的 seq=0;
  int ret = C_SUCCESS;
  int64_t start_pos = pos;
  if (NULL == buffer || 0 >= len || pos < 0) {
    MySqlLog("invalid argument buffer=%p, length=%ld, pos=%ld", buffer, len, pos);
    ret = C_INVALID_ARGUMENT;
  } else {
    // skip packet header serialize head at end of this function
    pos += C_MYSQL_PACKET_HEADER_SIZE;

    if (C_SUCCESS
        != (ret = CMysqlUtil::
            store_int1(buffer, len, protocol_version_, pos))) {
      MySqlLog("serialize packet protocol_version failed, buffer=%p, length=%ld,"
          "protocol_version=%d, pos=%ld",
          buffer, len, protocol_version_, pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::store_str_vzt(buffer, len,
                                            server_version_.c_str(),
                                            server_version_.length(), pos))) {
      MySqlLog("serialize packet server_version failed, buffer=%p, length=%ld,"
          "server_version length=%d, pos=%ld",
          buffer, len, server_version_.length(), pos);
    } else if (C_SUCCESS
        != (ret = CMysqlUtil::store_int4(buffer, len, thread_id_, pos))) {
      MySqlLog("serialize packet thread_id failed, buffer=%p, length=%ld,"
          "thread_id=%d, pos=%ld",
          buffer, len, thread_id_, pos);
    }

    // make sure buffer + pos + SCRAMBLE_SIZE < buffer + length
    // serialize SCRAMBLE && filler_
    if (C_SUCCESS == ret) {
      if ((buffer + pos + SCRAMBLE_SIZE < buffer + len)) {
        memcpy(buffer + pos, scramble_buff_, SCRAMBLE_SIZE + 1);
        pos += SCRAMBLE_SIZE + 1;
      } else {
        MySqlLog("not enough buffer to serialize scramble_buff && filler, "
            "buffer=%p, len=%ld,"
            "scramble_buff&&filler length=%d,pos=%ld",
            buffer, len, SCRAMBLE_SIZE + 1, pos);
        ret = C_ERROR;
      }
    }

    if (C_SUCCESS == ret) {
      if (C_SUCCESS
          != (ret = CMysqlUtil::store_int2(buffer, len, server_capabilities_,
                                           pos))) {
        MySqlLog("serialize packet server_capabilities failed, "
            "buffer=%p, length=%ld,"
            "server_capabilities=%d, pos=%ld",
            buffer, len, server_capabilities_, pos);
      } else if (C_SUCCESS
          != (ret = CMysqlUtil::
              store_int1(buffer, len, server_language_, pos))) {
        MySqlLog("serialize packet server_language failed, buffer=%p, length=%ld,"
            "server_language=%d, pos=%ld",
            buffer, len, server_language_, pos);
      } else if (C_SUCCESS
          != (ret = CMysqlUtil::store_int2(buffer, len, server_status_, pos))) {
        MySqlLog("serialize packet server_status failed, buffer=%p, length=%ld,"
            "server_status=%d, pos=%ld",
            buffer, len, server_status_, pos);
      }
    }

    if (C_SUCCESS == ret) {
      if ((buffer + pos + PLUGIN_SIZE < buffer + len)) {
        memcpy(buffer + pos, plugin_, PLUGIN_SIZE);
        pos += PLUGIN_SIZE;
      } else {
        MySqlLog("not enough buffer to serialize plugin, buffer=%p, len=%ld,"
            "scramble_buff length=%d,pos=%ld",
            buffer, len, PLUGIN_SIZE, pos);
        ret = C_ERROR;
      }
    }

    if (C_SUCCESS == ret) {
      if ((buffer + pos + PLUGIN2_SIZE < buffer + len)) {
        memcpy(buffer + pos, plugin2_, PLUGIN2_SIZE);
        pos += PLUGIN2_SIZE;
      } else {
        MySqlLog("not enough buffer to serialize plugin, buffer=%p, len=%ld,"
            "plugin2 length=%d,pos=%ld",
            buffer, len, PLUGIN2_SIZE, pos);
        ret = C_ERROR;
      }
    }

    if (C_SUCCESS == ret) {
      if ((buffer + pos + 1 < buffer + len)) {
        memset(buffer + pos, 0, 1);
        pos += 1;
      } else {
        MySqlLog("not enough buffer to serialize filler2, buffer=%p, len=%ld,"
            "terminated_ length=%c,pos=%ld",
            buffer, len, terminated_, pos);
        ret = C_ERROR;
      }
    }

    uint32_t pkt_len = static_cast<uint32_t>(pos - start_pos
        - C_MYSQL_PACKET_HEADER_SIZE);
    if (C_SUCCESS == ret) {
      if (C_SUCCESS
          != (ret = CMysqlUtil::store_int3(buffer, len, pkt_len, start_pos))) {
        MySqlLog("serialize packet haader size failed, "
            "buffer=%p, length=%ld, value=%d, pos=%ld",
            buffer, len, pkt_len, start_pos);
      } else if (C_SUCCESS
          != (ret = CMysqlUtil::store_int1(buffer, len, 0, start_pos))) {
        MySqlLog("serialize packet haader seq failed, "
            "buffer=%p, length=%ld, value=%d, pos=%ld",
            buffer, len, 1, start_pos);
      }
    }
  }
  return ret;
}
}  // namespace mysql
}  // namespace claims
