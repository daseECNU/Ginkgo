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
 * /CMySQL/for_copy_right.h
 *
 *  Created on: Oct 10, 2015
 *      Author: ChenLingyun,yukai
 *		   Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#ifndef MYSQL_SERVER_H_
#define MYSQL_SERVER_H_

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <iostream>
#include <map>
#include <queue>
#include "../mysql/mysql_connection.h"
#include "../mysql/mysql_loginer.h"
#include "packet/mysql_command_packet.h"
#include "packet/mysql_eof_packet.h"
#include "packet/mysql_field_packet.h"
#include "packet/mysql_resheader_packet.h"
#include "packet/mysql_spr_packet.h"
#include "packet/mysql_sql_packet.h"
#include "../utility/thread_pool.h"
#include "mysql_result_set.h"
class CMysqlLoginer;
namespace claims {
namespace mysql {

string bytestohexstring(char* bytes,int bytelength);
class CMysqlServer {
private:
	static CMysqlServer* mysql_server_instance;
	CMysqlServer();
	virtual ~CMysqlServer();



public:
	static CMysqlServer* GetInstance();

	int Start();
	int Initialize();
	/*void set_work_threads_count(){
	 if ( < 0){
	 elog();
	 }
	 else{
	 work_threads_count_ = ;
	 }
	 work_threads_count_ = 4;
	 TODO: read value from config
	 }
	 inline void set_connection_max_count(){
	 }*/
	int ListenPort(int port);
	bool AcceptConnection(int fd, int &connected_fd);
	bool ReceiveData(epoll_event event, char *buf);
	bool ReceiveData(int fd);
	int HasFullSession() {
		int ret = C_SUCCESS;
		// TODO(cly)
		return ret;
	}
	void HandlePacket(int fd, MysqlCommandPacket* packet);

private:
	int DoComQuery(int fd, MysqlCommandPacket* packet);

	int DoComQuit(int fd, MysqlCommandPacket* packet);

	int DoComPrepare(int fd, MysqlCommandPacket* packet);

	int DoComExcute(int fd, MysqlCommandPacket* packet);

	int DoComCloseStmt(int fd, MysqlCommandPacket* packet);

	int DoComResetStmt(int fd, MysqlCommandPacket* packet);

	int DoComPing(int fd, MysqlCommandPacket* packet);

	int DoComDeleteSession(int fd, MysqlCommandPacket* packet);

	int DoComUnsupported(int fd, MysqlCommandPacket* packet);

	int SendServerVersion(int fd);

public:
	int PostPacket(int fd, MysqlSQLPacket* packet, uint8_t seq);
	int SendResponse(int fd, MysqlCommandPacket* packet,
			MysqlResultSet &result);
	int SendErrorPacket(int fd, MysqlCommandPacket* packet,
			MysqlResultSet &result);
	int SendOkPacket(int fd,
			const MysqlResultSet& result, uint16_t server_status,MysqlCommandPacket* packet);
	int SendResultSet(int fd, MysqlResultSet &result, uint16_t server_status);
	int ProcessResHeaderPacket(int fd, char* buffer, int64_t& pos,
			MysqlResultSet &result);
	int ProcessFieldPacket(int fd, char* buffer, int64_t& pos,
			MysqlResultSet &result);
	int ProcessEofPacket(int fd, char* buffer, int64_t& pos,
			MysqlResultSet &result);
	int ProcessRowPackets(int fd, char* buffer, int64_t& pos,
			MysqlResultSet &result);
	int ProcessSinglePacket(int fd, char *buffer, int len);

	static void *SendHandler(void * null_);

public:
//	ThreadPool *threadpool_;
	queue<MysqlSQLPacket*> in_queue_;
	queue<MysqlSQLPacket*> out_queue_;
	map<int, CMysqlConnection*> fd_to_session_;
	char *temp_buffer_;  // TODO(cly): should be replaced by memory pool

private:
	int listening_fd_;
	int epoll_fd_;
	int connected_fd_;
	int port_;
	int work_threads_count_;
	const int kConnectionMaxCount = 300;
	CMysqlLoginer loginer_;
	uint8_t number_ = 0;
};


}  // namespace mysql
}  // namespace claims

#endif  // MYSQL_SERVER_H_
