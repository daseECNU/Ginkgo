#include <iostream>
#include <string>
using namespace std;
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <glog/logging.h>

namespace claims {
namespace mysql {

class MysqlConnect {
 public:
  MysqlConnect();
  void getconnection();
  void closeconnection();
  sql::Driver *driver;
  sql::Connection *conn;
  sql::Statement *state;

 private:
  string ip;        // = "127.0.0.1";//Config::httpserver_master_ip;
  string port;      // = "3306";//Config::mysql_port;
  string password;  // = "imdb";//Config::mysql_password;
};
}
}
