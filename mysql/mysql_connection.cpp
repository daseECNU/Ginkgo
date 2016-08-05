/*
 * CMysqlConnection.cpp
 *
 *  Created on: 2014-9-4
 *      Author: imdb
 */
#include "mysql_connection.h"
namespace claims {
namespace mysql {
CMysqlConnection::CMysqlConnection(){

}

CMysqlConnection::CMysqlConnection(int fd):fd_(fd), stat_(to_check){

}

CMysqlConnection::~CMysqlConnection(){

}


CMysqlConnection::CMysqlConnection(int fd, sockaddr_in addr):fd_(fd), addr_(addr) {

}

bool CMysqlConnection::check_timeout(){
	return (CMysqlUtil::get_current_time()-get_last_time()) > TIMEOUT;
}

int64_t CMysqlConnection::get_last_time(){
	return int64_t(last_used_time_.tv_sec * 1000000 + last_used_time_.tv_usec);
}
}  // namespace mysql
}  // namespace claims
