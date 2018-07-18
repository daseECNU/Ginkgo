AM_CPPFLAGS= -fPIC -fpermissive \
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/asio \
-I${BOOST_HOME}/boost/serialization \
-I${THERON_HOME}/Include 

AM_LDFLAGS = -pthread -g -lboost_serialization


noinst_LIBRARIES=libpacket.a

libpacket_a_SOURCES = \
	mysql_command_packet.cpp 	mysql_command_packet.h \
	mysql_eof_packet.cpp 		mysql_eof_packet.h \
	mysql_error_packet.cpp 		mysql_error_packet.h \
	mysql_field_packet.cpp 		mysql_field_packet.h \
	mysql_handshake_packet.cpp 	mysql_handshake_packet.h \
	mysql_ok_packet.cpp 		mysql_ok_packet.h \
	mysql_packet_header.h 		mysql_resheader_packet.cpp \
	mysql_resheader_packet.h 	mysql_row_packet.cpp \
	mysql_row_packet.h 		mysql_sql_packet.cpp \
	mysql_sql_packet.h 		mysql_spr_packet.cpp \
	mysql_spr_packet.h
