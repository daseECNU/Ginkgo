
AM_CPPFLAGS= -fPIC -fpermissive \
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/serialization \
-I${THERON_HOME}/Include 


AM_LDFLAGS=-lc -lm -lrt -lboost_serialization -lxs

if OPT_TCMALLOC
AM_CPPFLAGS+=-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
AM_LDFLAGS+=-ltcmalloc 
endif

LDADD = 	../catalog/libcatalog.a \
		../Daemon/libdaemon.a \
		../common/Block/libblock.a \
		../common/Schema/libschema.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.so 

noinst_LIBRARIES=libclient.a
libclient_a_SOURCES = \
	ClaimsServer.cpp			ClaimsServer.h \
	Client.cpp 				Client.h \
	ClientResponse.cpp 		ClientResponse.h \
	jsoncpp.cpp

#SUBDIRS = json Test
#DIST_SUBDIRS = json Test
