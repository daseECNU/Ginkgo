#include "mysql_sendsql.h"
#include "../Config.h"
#include "../common/Logging.h"

namespace claims{namespace mysql{


MysqlConnect::MysqlConnect(){
	ip = Config::httpserver_master_ip;
	stringstream ss;
	ss<<Config::mysql_port;
	port = ss.str();
	password = Config::mysql_password;
}

void MysqlConnect::getconnection(){
	try{
		driver = sql::mysql::get_driver_instance();
	}catch(sql::SQLException &e){
		LOG(ERROR) <<"cannot get the instance driver."<<endl;
	}
	try{
		conn = driver->connect(ip+":"+port,"root",password);
	}catch(sql::SQLException &e){
		LOG(ERROR) <<"cannot get connection to claims_mysql."<<endl;
	}
}
void MysqlConnect::closeconnection(){
	delete conn;
	conn = NULL;
	driver = NULL;
}

//void MysqlConnect::getResultSet(string &sql, sql::ResultSet *rs){
//	sql::Statement *state;
//	state = conn->createStatement();
//	cout<<sql<<endl;
//	rs = state->executeQuery(sql);
//
//	delete state;
//	state = NULL;
//}
//void MysqlSendsql(string sql, sql::ResultSet *rs){
//	string ip = Config::httpserver_master_ip;
//	string port = Config::mysql_port;
//	string password = Config::mysql_password;
//	try{
//		driver = sql::mysql::get_driver_instance();
//	}
//	catch(sql::SQLException &e){
//		LOG(ERROR) <<"cannot get the instance driver."<<endl;
//	}
//	try{
//		conn = driver->connect(ip+":"+port,"root",password);
//	}
//	catch(sql::SQLException &e){
//		LOG(ERROR) <<"cannot get connection to claims_mysql."<<endl;
//	}
//	rs = state->executeQuery(sql);
//}

}}
