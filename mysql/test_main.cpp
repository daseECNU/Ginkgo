/*
 * TestMain.cpp
 *
 *  Created on: 2014-9-6
 *      Author: imdb
 */
#include <iostream>

#include "mysql_server.h"
using namespace std;
namespace claims {
namespace mysql {
int main32312()
{
	CMysqlServer *server = new CMysqlServer();
	server->Initialize();
	server->Start();
}
}  // namespace mysql
}  // namespace claims
