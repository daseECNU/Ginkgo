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
 *      Author: chenlingyun,yukai
 *       Email: geekchenlingyun@outlook.com
 *
 * Description:
 *
 */
#include <unistd.h>
#include <bitset>
#include <utility>
#include <queue>
#include <string>
#include "mysql_server.h"

#include <glog/logging.h>
#include <string.h>

#include "packet/mysql_sql_packet.h"
#include "packet/mysql_field_packet.h"
#include "packet/mysql_eof_packet.h"
#include "packet/mysql_row_packet.h"
#include "packet/mysql_resheader_packet.h"
#include "../common/Logging.h"
#include "../Daemon/Daemon.h"
#include "../mysql/mysql_result_set.h"
#include "../httpserver/connection.hpp"
#include "../httpserver/ResultManage.hpp"



namespace claims {
namespace mysql {

CMysqlServer* CMysqlServer::mysql_server_instance = NULL;

CMysqlServer::CMysqlServer() :
		port_(3306), work_threads_count_(4) {
	temp_buffer_ = reinterpret_cast<char*>(malloc(
			MAX_PACKET_SIZE * sizeof(char)));
	memset(temp_buffer_, 0, sizeof(temp_buffer_));
}

CMysqlServer::~CMysqlServer() {
}

int CMysqlServer::Start() {
	LOG(INFO) << "启动cliams mysql server..." << endl;
	int ret = C_SUCCESS;
	int result;

	Initialize();
	pthread_t t_sendhandler;
	const int error1 = pthread_create(&t_sendhandler, NULL, SendHandler, this);
	if (error1 != 0) {
	std::cout << "cannot create receive thread!" << strerror(errno)
			  << std::endl;
	}

//	threadpool_ = new ThreadPool();
//	if (threadpool_->Init(work_threads_count_) == false) {
//		MySqlElog("thread pool init failed.");
//		return C_ERROR;
//	}
	if (ListenPort(port_) == C_ERROR) {
		return C_ERROR;
	}

	if ((epoll_fd_ = epoll_create(kConnectionMaxCount)) == -1) {
		MySqlElog("%s. create epoll failed.", strerror(errno));
		close(listening_fd_);
		return C_ERROR;
	}
	epoll_event event_list[kConnectionMaxCount];

	epoll_event event;
	event.events = EPOLLIN | EPOLLET;
	event.data.fd = listening_fd_;

	if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, listening_fd_, &event)) {
		MySqlElog("%s. register epoll failed. ", strerror(errno));
		close(listening_fd_);
		close(epoll_fd_);
		return C_ERROR;
	}
	while (1) {
		if ((result = epoll_wait(epoll_fd_, event_list, kConnectionMaxCount,
				EPOLLTIMEOUT)) == -1) {
			if (errno != EINTR) {
				MySqlElog("%s. wait epoll failed. ", strerror(errno));
				ret = C_ERROR;
				break;
			}
		} else {
			//cout<<"result is "<<result<<endl;
			//sleep(10);
			for (int i = 0; i < result; ++i) {
				// exit abnormally
				int ready_fd = event_list[i].data.fd;
				if ((event_list[i].events & EPOLLERR)
						|| (event_list[i].events & EPOLLHUP)
						|| !(event_list[i].events & EPOLLIN)) {
					sockaddr_in temp = fd_to_session_.at(ready_fd)->get_addr();

					MySqlElog("%s.%d exit abnormally.\n",
							inet_ntoa(temp.sin_addr), ntohs(temp.sin_port));
					close(ready_fd);
					// unregister this fd
					epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, ready_fd, NULL);
					delete fd_to_session_.at(ready_fd);
					fd_to_session_.erase(ready_fd);
					continue;
				}
//				LOG(INFO) << "listen fd is:"<< listening_fd_ << endl;
				if (ready_fd == listening_fd_) {
					AcceptConnection(listening_fd_, connected_fd_);
					ret = loginer_.login(*(fd_to_session_.at(connected_fd_)));
				} else {
					if (ReceiveData(event_list[i].data.fd) == C_SUCCESS) {
						// TODO(cly)
						MySqlElog("received !\n");
					}
					LOG(INFO)<<"complete the ReceiveData function."<<endl;
				}
			}
		}
	}
	return ret;
}

int CMysqlServer::Initialize() {
	LOG(INFO) << "Initialize the JDBC server！" <<endl;
	//cout<<"初始化服务器！"<<endl;
	/*
	 set_work_threads_count();
	 set_port();
	 set_connection_max_count();
	 */
	return 0;
}

int CMysqlServer::ListenPort(int port) {
	if ((listening_fd_ = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		MySqlElog("%s. can't create socket.", strerror(errno));
		return C_ERROR;
	}
	// enable address reuse
	int temp_val = 1;
	setsockopt(listening_fd_, SOL_SOCKET, SO_REUSEADDR, &temp_val,
			sizeof(temp_val));
	sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	if (bind(listening_fd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr))
			== -1) {
		MySqlElog("%s. can't bind socket.", strerror(errno));
		close(listening_fd_);
		return C_ERROR;
	}

	if (listen(listening_fd_, kConnectionMaxCount) == -1) {
		MySqlElog("%s. can't listen socket.", strerror(errno));
		close(listening_fd_);
		return C_ERROR;
	}
	return C_SUCCESS;
}

bool CMysqlServer::AcceptConnection(int fd, int &connected_fd) {
	int ret = C_SUCCESS;

	LOG(INFO) << "in AcceptConnection function" << endl;
	sockaddr_in connected_socket_addr;
	bzero(&connected_socket_addr, sizeof(connected_socket_addr));

	socklen_t length = sizeof(connected_socket_addr);
	connected_fd = accept(fd,
			reinterpret_cast<sockaddr*>(&connected_socket_addr), &length);
	if (connected_fd < 0) {
		MySqlElog("%s. accept socket failed.", strerror(errno));
		return false;
	} else {
		LOG(INFO) << "connected fd is %d"<< connected_fd<<endl;
		LOG(INFO) << "accept socket connection from %s:%d"<<
				inet_ntoa(connected_socket_addr.sin_addr)<<
				ntohs(connected_socket_addr.sin_port)<<endl;
		// fd_to_adddr.insert(pair<int, sockaddr_in>(connected_fd,
		// connected_socket));
		fd_to_session_.insert(
				pair<int, CMysqlConnection*>(connected_fd,
						new CMysqlConnection(connected_fd,
								connected_socket_addr)));
	}

	// register new socket to epoll
	epoll_event event;
	event.events = EPOLLIN | EPOLLET;
	// make sure this fd equal with connected
	// socket fd returned from accept()
	event.data.fd = connected_fd;
	epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, connected_fd, &event);
	LOG(INFO) << ("still in AcceptConnection");
	// ReceiveData(connected_fd);
	return ret;
}

bool CMysqlServer::ReceiveData(int fd) {
	int ret = C_SUCCESS;
	LOG(INFO) << "in ReceiveData function" <<endl;
	CMysqlConnection *s;
	if (fd_to_session_.find(fd) == fd_to_session_.end()) {
		MySqlElog("fd %d is not in map", fd);

	} else {
		s = fd_to_session_.find(fd)->second;
	}

	const int kMessageLength = 10000;
	uint8_t cmd_type = 0;
	char statement[kMessageLength];
	char buf[kMessageLength];
	memset(buf, 0, sizeof(buf));
	int recv_count = recv(fd, buf, kMessageLength, 0);
	if (recv_count < 0) {
		MySqlElog(" read data failed.");
		return false;
	} else if (recv_count == 0) {
		MySqlElog("client close normally\n");
		epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, NULL);
		return false;
	}
	char* buf_ = buf;
	buf_ += C_MYSQL_PACKET_HEADER_SIZE;
	CMysqlUtil::get_uint1(buf_, cmd_type);
	CMysqlUtil::get_statement(buf_, statement);
	LOG(INFO) << statement <<endl;
	MysqlCommandPacket command_packet;
	command_packet.setType(cmd_type);
	command_packet.setSqlCommand(statement, strlen(statement));
	HandlePacket(fd, &command_packet);
	return true;
}
void CMysqlServer::HandlePacket(int fd, MysqlCommandPacket* packet) {
	int ret = C_SUCCESS;
	LOG(INFO)<<"enter the HandlePackeet function"<<endl;
	if (NULL == packet) {
		LOG(ERROR)<< "invalide argument packet is " << packet << endl;
		ret = C_INVALID_ARGUMENT;
	} else {
		uint8_t type = packet->getType();
		switch (type) {
			case COM_QUIT:
			ret = DoComQuit(fd, packet);//have completed it;
			break;
			case COM_QUERY:
			ret = DoComQuery(fd, packet);
			break;
//			case COM_STMT_PREPARE://Claims don't support it.
//			ret = DoComPrepare(fd, packet);
//			break;
//			case COM_STMT_EXECUTE://Claims don't support it.
//			ret = DoComExcute(fd, packet);
//			break;
//			case COM_STMT_CLOSE://Claims don't support it.
//			ret = DoComCloseStmt(fd, packet);
//			break;
			case COM_PING:
			ret = DoComPing(fd, packet);
			break;
//			case COM_DELETE_SESSION://claims don't have it;
//			ret = DoComDeleteSession(fd, packet);
//			break;
			default:
			LOG(WARNING) << "unsupport command " << type << endl;
			ret = DoComUnsupported(fd, packet);
			break;
		}
	}
}
int CMysqlServer::DoComUnsupported(int fd, MysqlCommandPacket* packet) {
	int ret = C_SUCCESS;
	string message = "command not yet supported";
	MysqlErrorPacket* error_packet;
	error_packet->set_message(message);
	number_ = packet->getPacketHeader().seq_;
	++number_;
	//ret = post_packet(error_packet, number);
	if (C_SUCCESS != ret) {
		LOG(ERROR)<< "failed to send error packet to mysql client, "
		"ret is " << ret << endl;
	} else {
		sockaddr_in temp = fd_to_session_.at(fd)->get_addr();
		LOG(ERROR) << "send error packet to mysql client "
		<< inet_ntoa(temp.sin_addr) << "client port:"
		<< ntohs(temp.sin_port) << endl;
	}
}
int CMysqlServer::DoComQuit(int fd, MysqlCommandPacket* packet) {
	int ret = C_SUCCESS;
	sockaddr_in temp = fd_to_session_.at(fd)->get_addr();
	LOG(INFO)<< "client quit, client address: " << inet_ntoa(temp.sin_addr)
	<< "client port:" << ntohs(temp.sin_port) << endl;
	close(connected_fd_);
}

int CMysqlServer::DoComPing(int fd, MysqlCommandPacket* packet) {
	int ret = C_SUCCESS;
	sockaddr_in temp = fd_to_session_.at(fd)->get_addr();
	number_ = packet->getPacketHeader().seq_;
	//there are mistakes;
	MysqlResultSet result(*(Daemon::getInstance()->getExecutedResult().result_));
	result.setMessage("server is ok");
	LOG(INFO)<< "start to ping " << inet_ntoa(temp.sin_addr) << endl;
	//ret = send_ok_packet();
}
int CMysqlServer::DoComQuery(int fd, MysqlCommandPacket* packet) {
	int ret = C_SUCCESS;
	int err = C_SUCCESS;
	LOG(INFO)<<"enter the DoComQuery"<<endl;
	char* q = packet->getSqlCommand();
	char* version_query = "select @@version_comment limit 1;";
	if (strcmp(q, version_query) == 0) {
		SendServerVersion(fd);
		cout<<"version sent successfully"<<endl;
	} else {
		remote_command command;
		command.socket_fd = fd;
		command.cmd = q;
		httpserver::ResultString& rs = httpserver::GetResultString();
		httpserver::mutex_.lock();
		int i;
		for (i = 2; i < rs.connection_max_number_; i++) {
			if (rs.connection_lock_[i] == false) {
				rs.connection_lock_[i] = true;
				rs.sock_fd_[i] = command.socket_fd;
				//rcmd.socket_fd = -rs.fd_[i];
				rs.command_packet_[i] = *packet;
				break;
			}
		}
		httpserver::mutex_.unlock();

		Daemon::getInstance()->addRemoteCommand(command);

		//number_ = packet->getPacketHeader().seq_;
		//number_++;
		//cout<<"after getPacketHeader, the number_ is: "<<(int)number_<<endl;
		/*
		while(true){
			usleep(100);
			if(rs.result_got_[i] == true){

				httpserver::mutex_.lock();
				string buff_to_send;
				httpserver::result_manage(buff_to_send,rs.result_[i]);
				//cout<<"mysql_server.cpp:379 now result is :"<<buff_to_send<<endl;
				ExecutedResult result_ = rs.result_[i];
				ResultSet* result_set = result_.result_;





				if(result_set != NULL){
					MysqlResultSet result (*result_set);
					//cout<<"after define the result_set."<<endl;
					httpserver::result_manage(buff_to_send,result_);
					//cout<<"mysql_server.cpp:381 now result is :"<<buff_to_send<<endl;
					//cout<<"fd is:"<<i<<"command.socket_fd is:"<<command.socket_fd<<endl;

					ret = SendResponse(fd, packet, result);
					ExecutedResult resulttemp;
					rs.result_[i] = resulttemp;
					rs.result_got_[i] = false;
					rs.connection_lock_[i] = false;
					rs.sock_fd_[i] = -1;
					httpserver::mutex_.unlock();
					break;
				}
				ExecutedResult resulttemp;
				rs.result_[i] = resulttemp;
				rs.result_got_[i] = false;
				rs.connection_lock_[i] = false;
				rs.sock_fd_[i] = -1;
				httpserver::mutex_.unlock();


//				else{
//					LOG(WARNING)<< "direct_execute failed, ret is " << ret << endl;
//				}

			}

		}*/
		return ret;


	}
}
string bytestohexstring(char* bytes,int bytelength)
{
  string str("");
  string str2("0123456789abcdef");
   for (int i=0;i<bytelength;i++) {
     int b;
     b = 0x0f&(bytes[i]>>4);
     char s1 = str2.at(b);
     str.append(1,str2.at(b));
     b = 0x0f & bytes[i];
     str.append(1,str2.at(b));
     str.append(" ");
     char s2 = str2.at(b);
   }
   return str;
}
int CMysqlServer::SendServerVersion(int fd) {
	int ret = C_SUCCESS;
	MysqlResHeaderPacket res_header_packet;
	res_header_packet.set_field_count(0x01);
	res_header_packet.set_seq(1);
	char* buffer = new char[MAX_PACKET_SIZE];
	int64_t pos = 0;
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	int64_t len = MAX_PACKET_SIZE;
	MysqlSQLPacket *packet = NULL;
	packet = &res_header_packet;
	ret = packet->encode(buffer, len, pos);
	//cout << "header buffer: "<<bytestohexstring(buffer,50)<<endl;
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process response header packet failed,ret is " << ret
		<< endl;
	}
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	MysqlFieldPacket field_packet;
	MySQLField field;
	field_packet.field_ = field;
	field_packet.set_seq(2);
	packet = &field_packet;
	ret = packet->encode(buffer, len, pos);
	//cout << "field buffer: "<<bytestohexstring(buffer,50)<<endl;

	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process field packet failed,ret is " << ret
		<< endl;
	}

	MysqlEOFPacket eof_packet;
	eof_packet.set_seq(03);
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	packet = &eof_packet;
	ret = packet->encode(buffer, len, pos);
	//cout << "eof buffer: "<<bytestohexstring(buffer,50)<<endl;
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process eof packet failed,ret is " << ret
		<< endl;
	}

	MysqlRowPacket row_packet;
	row_packet.set_seq(04);
	pos = 0;
	int64_t start_pos = pos;
	pos += C_MYSQL_PACKET_HEADER_SIZE;
	string str = "Claims server 0.1";
	int64_t length = str.length();
	if ((ret = CMysqlUtil::store_length(buffer, len, length, pos))
			== C_SUCCESS) {
		if (len - pos >= length) {
			memcpy(buffer + pos, str.c_str(), length);
			pos += length;
		}
	}
	uint32_t pkt_len = 0x000012;
	CMysqlUtil::store_int3(buffer, length, pkt_len, start_pos);
	CMysqlUtil::store_int1(buffer, length, 4, start_pos);
	//cout << "row buffer: "<<bytestohexstring(buffer,50)<<endl;
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process row packet failed,ret is " << ret
		<< endl;
	}

	eof_packet.set_seq(05);
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	packet = &eof_packet;
	ret = packet->encode(buffer, len, pos);
	//cout << "eof buffer: "<<bytestohexstring(buffer,50)<<endl;
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process eof packet failed,ret is " << ret
		<< endl;
	}

}
int CMysqlServer::DoComPrepare(int fd, MysqlCommandPacket* packet) {
	// TODO(cly)
	return C_SUCCESS;
}
int CMysqlServer::DoComExcute(int fd, MysqlCommandPacket* packet) {
	// TODO(cly)
	return C_SUCCESS;
}
int CMysqlServer::DoComCloseStmt(int fd, MysqlCommandPacket* packet) {
	// TODO(cly)
	return C_SUCCESS;
}
int CMysqlServer::DoComResetStmt(int fd, MysqlCommandPacket* packet) {
	// TODO(cly)
	return C_SUCCESS;
}
int CMysqlServer::DoComDeleteSession(int fd, MysqlCommandPacket* packet) {
	// TODO(cly)
	return C_SUCCESS;
}
int CMysqlServer::SendResponse(int fd, MysqlCommandPacket* packet,
		MysqlResultSet &result) {
	LOG(INFO)<<"enter SendResponse"<<endl;
	int ret = C_SUCCESS;
	number_ = packet->getPacketHeader().seq_;
	number_++;
	uint16_t server_status = 0;
	ret = SendResultSet(fd, result, server_status);
//	ret = SendOkPacket(fd, result, server_status);
	return ret;

}
int CMysqlServer::SendErrorPacket(int fd, MysqlCommandPacket* packet,
		MysqlResultSet &result) {
	int ret = C_SUCCESS;
	MysqlErrorPacket* error_packet;
	error_packet->set_message(result.getMessage());
	++number_;
	ret = PostPacket(fd, error_packet, number_);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "failed to send error packet to mysql client, "
		"ret is " << ret << endl;
	} else {
		LOG(INFO) << "success to send error packet to mysql client" << endl;
	}
	return ret;
}
int CMysqlServer::SendOkPacket(int fd,
		const MysqlResultSet& result, uint16_t server_status, MysqlCommandPacket *packet) {
	LOG(INFO)<< "enter SendOkPacket" << endl;
	int ret = C_SUCCESS;
	sockaddr_in temp = fd_to_session_.at(fd)->get_addr();
	MysqlOKPacket ok;
	ok.set_affected_rows(result.getAffectedRows());
	ok.set_warning_count(static_cast<uint16_t>(result.getWarningCount()));
	ok.set_server_status(server_status);
	ok.set_message(result.getMessage());
	number_ = packet->getPacketHeader().seq_;
	number_++;
	ret = PostPacket(fd, &ok, number_);
	cout<<"send ok_packet to fd:"<<fd<<endl;
	return ret;
}
int CMysqlServer::ProcessResHeaderPacket(int fd, char* buffer, int64_t& pos,
		MysqlResultSet &result) {
	//LOG(INFO)<<"enter ResHeaderPacket"<<endl;
	int ret = C_SUCCESS;
	MysqlResHeaderPacket res_header_packet;

	res_header_packet.set_field_count(result.getFieldCount());
	res_header_packet.set_seq(number_++);
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	int64_t len = MAX_PACKET_SIZE;
	//MysqlSQLPacket *packet = NULL;
	//packet = &res_header_packet;
	ret = res_header_packet.encode(buffer, len, pos);

	//LOG(INFO)<<"before SinglePacket"<<endl;
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "process response header packet failed,ret is " << ret
		<< endl;
	}
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	//LOG(INFO)<<"exit ResHeaderPacket"<<endl;
	return ret;
}
int CMysqlServer::ProcessFieldPacket(int fd, char* buffer, int64_t& pos,
		MysqlResultSet &result) {
	int ret = C_SUCCESS;

	MySQLField field;
	//LOG(INFO)<<"enter ProcessFieldPacket"<<endl;
	while (C_SUCCESS == result.next_field(field)) {
		MysqlFieldPacket field_packet(field);
		field_packet.set_seq(number_++);
		//cout<<"number field is "<<(int)number_<<endl;
		int64_t len = MAX_PACKET_SIZE;
		//MysqlSQLPacket *packet = NULL;
		//packet = &field_packet;
		//cout << "number of packet is "<<(int)packet
		ret = field_packet.encode(buffer, len, pos);
		ret = ProcessSinglePacket(fd, buffer, pos);
		if (ret != C_SUCCESS) {
			LOG(ERROR)<< "when send field packet, encode packet fails, "
			"ret is " << ret << endl;
		}

		memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
		pos = 0;
	}
	LOG(INFO)<<"exit ProcessFieldPacket"<<endl;
	return ret;
}
int CMysqlServer::ProcessEofPacket(int fd, char* buffer, int64_t& pos,
		MysqlResultSet &result) {
	int ret = C_SUCCESS;

	LOG(INFO)<<"enter ProcessEofPacket"<<endl;
	MysqlEOFPacket eof_packet;
	eof_packet.set_seq(number_++);
	eof_packet.set_warning_count(result.getWarningCount());
	eof_packet.setServerStatus(0x0200);
	int64_t len = MAX_PACKET_SIZE;
	//MysqlSQLPacket *packet = NULL;
	//packet = &eof_packet;
	ret = eof_packet.encode(buffer, len, pos);
	ret = ProcessSinglePacket(fd, buffer, pos);
	if (ret != C_SUCCESS) {
		LOG(ERROR)<< "when send end of file packet, encode packet fails, "
		"ret is " << ret << endl;
	}
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	LOG(INFO)<<"exit ProcessEofPacket"<<endl;
	return ret;
}
int CMysqlServer::ProcessRowPackets(int fd, char* buffer, int64_t& pos,
		MysqlResultSet &result) {
	int ret = C_SUCCESS;

	LOG(INFO)<<"enter ProcessRowPacket"<<endl;
	/*
	 * get the resutl from resultstring global.
	 */
	//cout<<"enter ProcessRowPacket"<<endl;

	httpserver::ResultString& rs = httpserver::GetResultString();
	int temp;
	for(temp = 2;temp <rs.connection_max_number_; temp++){
		//cout<<"temp is: "<<temp<<".and rs.fd_[temp] is: "<<rs.fd_[temp]<<endl;
		if(rs.sock_fd_[temp] == fd)
			break;
	}
	//cout<<"yes1,and temp is:"<<temp<<endl;
	string buff_to_send;
	httpserver::result_manage(buff_to_send,rs.result_[temp]);
						//cout<<"mysql_server.cpp:706 now result is :"<<buff_to_send<<endl;
	ResultSet* result_set = rs.result_[temp].result_;
	//cout<<"yes2"<<endl;
	MysqlRow mysql_row;
	int64_t len = MAX_PACKET_SIZE;
	//MysqlSQLPacket *packet = NULL;
	int row_number = 0;
	//cout<<"yes3"<<endl;

	DynamicBlockBuffer::Iterator it = result_set->createIterator();
	//cout<<"yes4"<<endl;
	//cout<<result_set->schema_->getncolumns()<<endl;
	mysql_row.column_num_ = (int64_t)result_set->schema_->getncolumns();
	//cout<<"yes5"<<endl;
	mysql_row.schema_ = result_set->schema_->duplicateSchema();
	BlockStreamBase * block;
	//cout<<"before block"<<endl;
	while (block = it.nextBlock()){
		/*
		 *
		 * test log
		 *
		 */
		//cout<<"enter the nextblock"<<endl;
		BlockStreamBase::BlockStreamTraverseIterator *block_it = block->createIterator();
		while(mysql_row.tuple_ = block_it->nextTuple()){
			/*
			 *
			 * test log;
			 *
			 */
			//cout<<"enter the nexttuple"<<endl;
			MysqlRowPacket row_packet(&mysql_row);
			row_packet.set_seq(number_++);
			pos = 0;
			memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
			ret = row_packet.encode(buffer, len, pos);
			ret = ProcessSinglePacket(fd, buffer, pos);
			/*
			 * Now just send the first row_packet for test;
			 */
			//break;
			if (ret != C_SUCCESS){
				LOG(ERROR)<< "when send row data packet, encode packet fails"
							<< endl;
			}

		}
	}


//	while (C_SUCCESS == result.next_row(mysql_row)) {
//		row_number++;
//		cout<<row_number<<endl;
//		MysqlRowPacket row_packet(&mysql_row);
//		row_packet.set_seq(number_++);
//		//packet = &row_packet;
//		pos = 0;
//		ret = row_packet.encode(buffer, len, pos);
//		ret = ProcessSinglePacket(fd, buffer, pos);
//		if (ret != C_SUCCESS) {
//			LOG(ERROR)<< "when send row data packet, encode packet fails"
//			<< endl;
//		}
//
//		memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
//		pos = 0;
//	}

	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos = 0;
	LOG(INFO)<<"exit ProcessRowPacket"<<endl;
	return ret;

}
int CMysqlServer::SendResultSet(int fd, MysqlResultSet &result,
		uint16_t server_status) {
	int ret = C_SUCCESS;
	//int64_t buffer_length = 0;
	int64_t buffer_pos = 0;
	LOG(INFO)<<"enter SendResultSet"<<endl;
	if (NULL == &result) {
		LOG(ERROR)<< "invalid argument result is " << &result << endl;
	} else {
		sockaddr_in temp = fd_to_session_.at(fd)->get_addr();
		char *buffer = new char[MAX_PACKET_SIZE];
		memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
		if (C_SUCCESS
				!= (ret = ProcessResHeaderPacket(fd, buffer, buffer_pos, result))) {
			LOG(WARNING) << "process resheasder packet failed dest is "
			<< inet_ntoa(temp.sin_addr) << "ret is " << ret << endl;
		} else if (C_SUCCESS
				!= (ret = ProcessFieldPacket(fd, buffer, buffer_pos, result))) {
			LOG(WARNING) << "process field packet failed dest is "
			<< inet_ntoa(temp.sin_addr) << "ret is " << ret << endl;
		} else if (C_SUCCESS
				!= (ret = ProcessEofPacket(fd, buffer, buffer_pos, result))) {
			LOG(WARNING) << "process field eof packet failed dest is "
			<< inet_ntoa(temp.sin_addr) << "ret is " << ret << endl;
		} else if (C_SUCCESS
				!= (ret = ProcessRowPackets(fd, buffer, buffer_pos, result))) {
			LOG(WARNING) << "process row packet failed dest is "
			<< inet_ntoa(temp.sin_addr) << "ret is " << ret << endl;
		} else if (C_SUCCESS
				!= (ret = ProcessEofPacket(fd, buffer, buffer_pos, result))) {
			LOG(WARNING) << "process row eof packet failed dest is "
			<< inet_ntoa(temp.sin_addr) << "ret is " << ret << endl;
		}
		LOG(INFO)<<"complete packets of result"<<endl;
		if (C_SUCCESS == ret) {
			LOG(INFO) << "send result set to client "
			<< inet_ntoa(temp.sin_addr) << endl;
			number_ = 0;
		}
	}
	return ret;
}
int CMysqlServer::PostPacket(int fd, MysqlSQLPacket* packet, uint8_t seq) {
	int ret = C_SUCCESS;
	int32_t pkt_len = 0;
	int64_t len_pos = 0;
	int64_t pos = 0;
	uint64_t size = packet->get_serialize_size() + C_MYSQL_PACKET_HEADER_SIZE;
	char *buffer = new char[MAX_PACKET_SIZE];
	memset(buffer, 0, sizeof(char) * MAX_PACKET_SIZE);
	pos += 3;
	CMysqlUtil::store_int1(buffer, size, seq, pos);
	ret = packet->serialize(buffer, size, pos);
	len_pos = 0;
	// 写入包的长度
	pkt_len = static_cast<int32_t>(pos - C_MYSQL_PACKET_HEADER_SIZE);
	CMysqlUtil::store_int3(buffer, size, pkt_len, len_pos);
	cout<<"mysql_server.cpp:812: buffer is:"<<bytestohexstring(buffer,50)<<"and the pkt_len is:"<<pkt_len<<endl;

	ret = ProcessSinglePacket(fd, buffer, pos);

	return ret;
}
int CMysqlServer::ProcessSinglePacket(int fd, char *buffer, int len) {
	int ret = C_SUCCESS;
	//cout<<"buffer is :"<<bytestohexstring(buffer,50)<<"len is :"<<endl;
	//LOG(INFO)<<"enter ProcessSinglePacket"<<endl;
	if (len <= 0 || fd < 0 || buffer == NULL) {
		MySqlElog("invalid argument fd=%d, buffer=%p, length=%d", fd, buffer,
				len);
		ret = C_ERROR;
	} else {
		int count;
		// make sure write all data

//		LOG(INFO)<<"before write"<<endl;
		while (len > 0 && (count = write(fd, buffer, len)) != 0) {
//			LOG(INFO)<<"this time send "<<count<<" size"<<endl;
			if (count == -1) {
				if (errno == EINTR) {  // if call is interrupted by signal
					continue;
				}
				MySqlElog(
						"%s. write buffer fails, fd is %d, buffer is %p, len is %d.",
						fd, buffer, len);
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
CMysqlServer* CMysqlServer::GetInstance() {
	if (NULL == mysql_server_instance) {
		mysql_server_instance = new CMysqlServer();
	}
	return mysql_server_instance;
}

void *CMysqlServer::SendHandler(void * para){
	//todu（此函数未做ret信号处理）
	int fd = 0;
	sleep(2);
	CMysqlServer *server = (CMysqlServer*) para;
	while(true){
		usleep(100);
		httpserver::ResultString& rs = httpserver::GetResultString();
		int i;
		for( i = 2; i < rs.connection_max_number_; i++){
			if(rs.result_got_[i] == true && rs.sock_fd_[i] > 0){

				httpserver::mutex_.lock();
				string buff_to_send;
				httpserver::result_manage(buff_to_send,rs.result_[i]);
//				cout<<"mysql_server.cpp:865 now result is :"<<buff_to_send<<endl;
				ExecutedResult result_ = rs.result_[i];
				ResultSet* result_set = result_.result_;

				httpserver::result_manage(buff_to_send,result_);

				cout<<"mysql_server.cpp:871 now result is :"<<buff_to_send<<endl;


				if(rs.result_[i].status_ != NULL){
					if(result_set != NULL){
						MysqlResultSet result (*result_set);
						//cout<<"after define the result_set."<<endl;
						//cout<<"fd is:"<<i<<"command.socket_fd is:"<<command.socket_fd<<endl;

						server->SendResponse(rs.sock_fd_[i], &rs.command_packet_[i], result);
					}
					else{
						if("" == rs.result_[i].warning_){
							MysqlResultSet result (rs.result_[i]);
							string info = rs.result_[i].info_ + "\n\nWARNINGS:\n" + rs.result_[i].warning_ + "\n";
							result.setMessage(info);
							uint16_t server_status = 0;
							server->SendOkPacket(rs.sock_fd_[i],result,server_status, &rs.command_packet_[i]);

						}
						else{

							MysqlResultSet result (rs.result_[i]);
							result.setMessage(rs.result_[i].info_);
							uint16_t server_status = 0;
							server->SendOkPacket(rs.sock_fd_[i],result,server_status, &rs.command_packet_[i]);
						}
					}
				}
				else{
					MysqlResultSet result (rs.result_[i]);
					result.setMessage(rs.result_[i].error_info_);
					uint16_t server_status = 0;
					server->SendOkPacket(rs.sock_fd_[i],result,server_status, &rs.command_packet_[i]);
				}
				ExecutedResult resulttemp;
				delete rs.result_[i].result_;
				rs.result_[i].result_ = NULL;
				rs.result_[i] = resulttemp;
				rs.result_got_[i] = false;
				rs.connection_lock_[i] = false;
				rs.sock_fd_[i] = -1;
				httpserver::mutex_.unlock();
				break;
		//				else{
		//					LOG(WARNING)<< "direct_execute failed, ret is " << ret << endl;
		//				}

			}


		}
	}
	//server->SendResponse(fd, &command_packet, result);
}
}  // namespace mysql
}  // namespace claims
