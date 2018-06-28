#include "mysql_sendsql.h"
#include "../Config.h"
#include "../common/Logging.h"

namespace claims {
namespace mysql {

MysqlConnect::MysqlConnect() {
  ip = Config::httpserver_master_ip;
  stringstream ss;
  ss << Config::mysql_port;
  port = ss.str();
  password = Config::mysql_password;
}

void MysqlConnect::getconnection() {
  try {
    driver = sql::mysql::get_driver_instance();
  } catch (sql::SQLException &e) {
    LOG(ERROR) << "cannot get the instance driver." << endl;
  }
  try {
    conn = driver->connect(ip + ":" + port, "root", password);
  } catch (sql::SQLException &e) {
    LOG(ERROR) << "cannot get connection to claims_mysql." << endl;
  }
}
void MysqlConnect::closeconnection() {
  delete conn;
  conn = NULL;
  driver = NULL;
}
}
}
