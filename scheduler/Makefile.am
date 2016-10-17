AM_CPPFLAGS= -fPIC -fpermissive \
-I${HADOOP_HOME}/include\
-I${JAVA_HOME}/include\
-I${JAVA_HOME}/include/linux\
-I${BOOST_HOME} \
-I${BOOST_HOME}/boost/serialization

AM_LDFLAGS=-lc -lm -lrt -lboost_serialization -lxs

if OPT_TCMALLOC
AM_CPPFLAGS+=-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
AM_LDFLAGS+=-ltcmalloc 
endif

LDADD = ../logical_operator/libscheduler.a \
		../catalog/libcatalog.a \
		../catalog/stat/libstat.a \
		../Resource/libresource.a \
		../common/libcommon.a \
		../common/Schema/libschema.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.a \
		${BOOST_HOME}/stage/lib/libboost_serialization.so \
		${BOOST_HOME}/stage/lib/libboost_system.a \
		${BOOST_HOME}/stage/lib/libboost_system.so

noinst_LIBRARIES=libscheduler.a
libscheduler_a_SOURCES = \
	fine_grain_backfill_scheduler.cpp	fine_grain_backfill_scheduler.h	\
	gready_scheduler.cpp		gready_scheduler.h		\
	serialized_scheduler.cpp	serialized_scheduler.h	\
	backfill_scheduler.cpp		backfill_scheduler.h	\
	job_context.cpp				job_context.h			\
	pipeline_job.cpp			pipeline_job.h			\
	scheduler_base.cpp			scheduler_base.h		\
	stage_task.cpp				stage_task.h
	
SUBDIRS = 
DIST_SUBDIRS = 
					
