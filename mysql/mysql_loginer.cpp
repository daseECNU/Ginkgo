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

#include <unistd.h>
#include <bitset>
#include <string>
#include "../mysql/mysql_server.h"
#include "./mysql_loginer.h"

#include "../common/Logging.h"
namespace claims {
namespace mysql {
CMysqlLoginer::CMysqlLoginer() {
  buffer_ = reinterpret_cast<char*>(malloc(MAX_PACKET_SIZE * sizeof(char)));
  memset(buffer_, 0, MAX_PACKET_SIZE * sizeof(char));
}

CMysqlLoginer::~CMysqlLoginer() {
  free(buffer_);
  buffer_ = NULL;
}

int CMysqlLoginer::login(const CMysqlConnection& session) {
  MySqlLog("start to shake hand");
  int ret = C_SUCCESS;
  ret = shake_hand(session);
  if (ret != C_SUCCESS) {
    MySqlElog("send shake hand packet failed.");
  } else {
    MySqlLog("send shake hand packet successfully");
  }

  ret = receive_authority(session);
  if (ret != C_SUCCESS) {
    MySqlElog("receive authority packet failed.");
  } else {
    MySqlLog("receive authority packet successfully");
  }

  ret = send_authority_res(session);
  if (ret != C_SUCCESS) {
    MySqlElog("send authority result failed.");
  } else {
    MySqlLog("send authority result packet successfully");
  }
  return ret;
}

int CMysqlLoginer::shake_hand(const CMysqlConnection& session) {
  MySqlLog("in shake_hand function------");
  int ret;
  MysqlHandshakePacket shakehand_packet;
  shakehand_packet.set_thread_id(pthread_self());

  int64_t len = MAX_PACKET_SIZE;
  int64_t pos = 0;
  memset(buffer_, 0, MAX_PACKET_SIZE * sizeof(char));
  char *buffer = get_buffer();
  ret = shakehand_packet.serialize(buffer, len, pos);
  if (ret != C_SUCCESS) {
    MySqlElog(
        "shake hand packet serialize fails. "
        "buffer_ is %p, len is %d, pos is %d",
        buffer, len, pos);
    return ret;
  }
  ret = write_data(session.get_fd(), buffer, pos);
  if (ret == C_ERROR) {
    MySqlElog("write shake hand data to client fails. "
         "fd is %d, buffer is %p, len is %ld, errno is %d",
         session.get_fd(), buffer, len, ret);
  } else {
    MySqlLog("send shake hand packet to fd %d with ip is %s", session.get_fd(),
        inet_ntoa(session.get_addr().sin_addr));
  }

  return ret;
}

int CMysqlLoginer::receive_authority(const CMysqlConnection& session) {
  MySqlLog("in receive_authority function------");
  int ret = C_SUCCESS;
  int read_size = C_MYSQL_PACKET_HEADER_SIZE;
  // memset(buffer_, 0, MAX_PACKET_SIZE * sizeof(char));

  char *buffer = get_buffer();
  ret = read_data(session.get_fd(), buffer, read_size);
  if (ret != C_SUCCESS) {
    MySqlElog("read authority header data from client fails.");
  } else {
    uint32_t messege_body_length = 0;
    CMysqlUtil::get_uint3(buffer, messege_body_length);
    buffer -= 3;
    MySqlLog("real size of authorition packet is %ld", messege_body_length);
    MySqlLog("start to read authority data from %s:%d.",
        inet_ntoa(session.get_addr().sin_addr),
        ntohs(session.get_addr().sin_port));

    ret = read_data(session.get_fd(), buffer + read_size, messege_body_length);
    if (ret != C_SUCCESS) {
      MySqlElog("read authority data from client fails.");
    }
    cout << "received authority data: "<<bytestohexstring(buffer,50)<<endl;
//    {
//      cout << "received authority data: ";
//      for (int i = 0; i < 40; ++i) {
//        bitset<8> a(static_cast<int>(buffer[i]));
//        cout << a << "-";
//      }
//      cout << endl;
//    }

    /*
     * 解析登录认证报文，客户端至服务器
     * ===================报文头===========		Byte
     * 消息长度		3
     * 序号			1
     * ===================报文体===========		Byte
     * capability_flags: 客户端权能标志         4
     * max_packet_size: 最大消息长度            	4
     * character_set: 字符编码					1
     *  填充值（略过）                           		23
     * user_name_: 用户名
     * auth_response_: 挑战认证数据
     * db_name_: 数据库名称（可选）	useless for CLAIMS
     *
     * */

    uint8_t auth_len = 0;
    uint64_t user_name_len = 0;
    uint64_t db_len = 0;
    char *pos = get_buffer();
    pos += C_MYSQL_PACKET_HEADER_SIZE;
    CMysqlUtil::get_uint4(pos, login_info_.capability_.cap_flags);
    CMysqlUtil::get_uint4(pos, login_info_.max_message_length_);
    CMysqlUtil::get_uint1(pos, login_info_.character_set_);
    pos += 23;
    user_name_len = strlen(pos);
    login_info_.user_name_ = string(pos, user_name_len);
    pos += user_name_len + 1;  // null
    CMysqlUtil::get_uint1(pos, auth_len);
    login_info_.auth_ = string(pos, auth_len);
    pos += auth_len;
    db_len = strlen(pos);
    login_info_.db_ = string(pos, db_len);
    pos += db_len;

    MySqlLog("read authority data successfully");
    MySqlLog("login info: max message len is %ld, "
        "character set is %d, user name is %s, "
        "auth is %s, db name is %s",
        login_info_.max_message_length_, login_info_.character_set_,
        login_info_.user_name_.c_str(), login_info_.auth_.c_str(),
        login_info_.db_.c_str());
  }

  return ret;
}

int CMysqlLoginer::send_authority_res(const CMysqlConnection& session) {
  MySqlLog("in send_authority_res function------");
  int ret = C_SUCCESS;
  MysqlOKPacket ok_packet;
  MysqlErrorPacket error_packet;
  MysqlSQLPacket *packet = NULL;
  char *buffer = get_buffer();
  memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
  if (CMysqlServer::GetInstance()->HasFullSession() != C_SUCCESS) {
    ret = C_ERR_FULL_SESSION;
    MySqlElog("session is full. sorry to refuse.");
    error_packet.set_errcode(ret);
    error_packet.set_message("too many sessions");
    packet = &error_packet;
  } else if ((ret = check_authority()) != C_SUCCESS) {
    MySqlElog("sorry, check fails");
    string message;
    switch (ret) {
      case C_ERR_USER_EMPTY: {
        message.assign("username is empty");
      }
        break;
      case C_ERR_USER_NOT_EXIST: {
        message.assign("username not exists");
      }
        break;
      case C_ERR_WRONG_PASSWORD: {
        message.assign("wrong password");
      }
        break;
      default: {
      }
    }
    error_packet.set_errcode(ret);
    error_packet.set_message(message);

    packet = &error_packet;
  } else {
    packet = &ok_packet;
  }

  // encode packet and write
  int64_t pos = 0;  // record the real size of packet
  int64_t len = MAX_PACKET_SIZE;
  cout<<"mysql_loginer.cpp:228 buffer is :"<<*buffer<<endl;
  ret = packet->encode(buffer, len, pos);
  if (ret != C_SUCCESS) {
    MySqlElog("when send authority result, encode packet fails");
  } else {
    buffer = get_buffer();
    cout << "send authority data: "<<bytestohexstring(buffer,50)<<endl;
//    {
//      cout << "send authority data: ";
//      for (int i = 0; i < 40; ++i) {
//        bitset<8> a(static_cast<int>(buffer[i]));
//        cout << a << "-";
//      }
//      cout << endl;
//    }
    ret = write_data(session.get_fd(), buffer, pos);
    if (ret == C_ERROR) {
      MySqlElog("write check authority result to client fails. "
           "fd is %d, buffer is %p, len is %ld, errno is %d",
           session.get_fd(), buffer, len, ret);
    } else {
      MySqlLog("send check authority result to %d:%s successfully", session.get_fd(),
          inet_ntoa(session.get_addr().sin_addr));
    }
  }

  return ret;
}

int CMysqlLoginer::check_authority() {
  int ret = C_SUCCESS;
  MySqlLog("username is %s", login_info_.user_name_.c_str());
  MySqlLog("authority is %s", login_info_.auth_.c_str());
  return ret;
}

int CMysqlLoginer::write_data(int fd, char *buffer, int len) {
  int ret = C_SUCCESS;
  if (len <= 0 || fd < 0 || buffer == NULL) {
    MySqlElog("invalid argument fd=%d, buffer=%p, length=%d", fd, buffer, len);
    ret = C_ERROR;
  } else {
    int count;
    // make sure write all data
    while (len > 0 && (count = write(fd, buffer, len)) != 0) {
      if (count == -1) {
        if (errno == EINTR) {  // if call is interrupted by signal
          continue;
        }
        MySqlElog("%s. write buffer fails, fd is %d, buffer is %p, len is %d.", fd,
             buffer, len);
        ret = C_ERROR;
        break;
      } else {
        buffer += count;
        len -= count;
      }
    }
  }
  return ret;
}

int CMysqlLoginer::read_data(int fd, char *buffer, int len) {
  int ret = C_SUCCESS;
  if (fd < 0 || buffer == NULL || len <= 0) {
    ret = C_ERROR;
    MySqlElog("invalid argument fd=%d, buffer=%p, length=%d", fd, buffer, len);
  } else {
    int count;
    while (len > 0 && (count = read(fd, buffer, len)) != 0) {
      if (count == -1) {
        if (errno == EINTR || errno == EAGAIN) {
          continue;
        }
        ret = C_ERROR;
        MySqlElog("%s. read data failed. fd is %d, buffer is %p, len is %d.", fd,
             buffer, len);
        break;
      } else {
        len -= count;
        buffer += count;
      }
    }
  }
  return ret;
}
}  // namespace mysql
}  // namespace claims
