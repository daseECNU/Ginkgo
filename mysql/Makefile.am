AM_CPPFLAGS= -fPIC -g3 -fpermissive \
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/asio \
-I${BOOST_HOME}/boost/serialization\
-I${CONNECT_HOME}/include/jdbc 

AM_LDFLAGS = -pthread  -lmysqlcppconn -lboost_serialization -lboost_system  


noinst_LIBRARIES=libmysql.a

libmysql_a_SOURCES  =  \
	mysql_define.h	mysql_loginer.cpp \
	mysql_server.cpp mysql_connection.cpp \
	mysql_state.cpp	mysql_util.cpp \
	mysql_server.h 		mysql_connection.h \
	mysql_state.h 		mysql_util.h \
	mysql_field.h       mysql_field.cpp\
	mysql_result_set.h  mysql_result_set.cpp\
	mysql_row.h         mysql_row.cpp\
	mysql_sendsql.h		mysql_sendsql.cpp

LDADD = ./packet/libpacket.a

SUBDIRS = packet
DIST_SUBDIRS = packet


