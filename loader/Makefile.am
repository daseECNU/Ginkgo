
AM_CPPFLAGS= -fPIC -fpermissive \
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/serialization \
-I${HADOOP_HOME}/include\
-I${JAVA_HOME}/include\
-I${JAVA_HOME}/include/linux \
-I${ZOOKEEPER_HOME}/src/c/include\
-I${ZOOKEEPER_HOME}/src/c/generated


AM_LDFLAGS=-lc -lm -lrt  -lxs -lboost_serialization -lboost_system  -lthrift -DTHREAD -lzookeeper_mt -lhdfs


if OPT_TCMALLOC
AM_CPPFLAGS+=-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
AM_LDFLAGS+=-ltcmalloc 
endif

LDADD = 	../catalog/libcatalog.a \
		../common/libcommon.a \
		../common/Block/libblock.a \
		../common/file_handle/libfilehandle.a \
		../common/Schema/libschema.a \
		../utility/libutility.a \
		${HADOOP_HOME}/lib/native/libhdfs.a\
		${JAVA_HOME}/jre/lib/amd64/server/libjvm.so\
		${BOOST_HOME}/stage/lib/libboost_serialization.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.so 

noinst_LIBRARIES=libloader.a
libloader_a_SOURCES = \
	data_injector.cpp 				data_injector.h \
	data_injector_for_parq.cpp 		data_injector_for_parq.h \
	single_file_connector.h 		single_file_connector.cpp \
	single_thread_single_file_connector.h single_thread_single_file_connector.cpp \
	table_file_connector.cpp 		table_file_connector.h  \
	validity.h 						validity.cpp	\
	hdfs_loader.cpp					hdfs_loader.h \
	table_parquet_writer.cpp		table_parquet_writer.h \
	table_parquet_reader.cpp		table_parquet_reader.h \
	zk_connector.cpp		zk_connector.h


SUBDIRS = test
DIST_SUBDIRS = test
