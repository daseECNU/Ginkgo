/*
 * Logging.h
 *
 *  Created on: Aug 11, 2013
 *      Author: wangli
 */

#ifndef LOGGING_H_
#define LOGGING_H_
#include <string>
#include <stdarg.h>
#include <stdio.h>
#ifdef DMALLOC
#include "dmalloc.h"
#endif
#include "../Debug.h"
//#define SQL_Parser
//#define SQL_Parser This macro is moved to Logging.cpp.

class Logging {
 public:
  /*
   * print the status information to the standard output.
   */
  virtual void log(const char* format, ...) = 0;
  /**
   * print the error information to stderr.
   */
  virtual void elog(const char* format, ...) = 0;
  virtual ~Logging(){};
};

class IteratorExecutorMasterLogging : public Logging {
 public:
  void log(const char* format, ...);
  void elog(const char* format, ...);
};

class IteratorExecutorSlaveLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class EnvironmentLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class AdaptiveEndPointLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class CoordinatorLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class ExchangeTrackerLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class ExpanderTrackerLogging : public Logging {
 public:
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class ExchangeIteratorEagerLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class ExchangeIteratorEagerLowerLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class ExchangeIteratorSenderMaterialized : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class CatalogLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class ResourceManagerMasterLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class ResourceManagerSlaveLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class StorageManagerLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class StorageManagerMasterLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class BufferManagerLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class BlockStreamExpanderLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};
class PerformanceTopLogging : public Logging {
  void log(const char* format, ...) __attribute__((format(printf, 2, 3)));
  void elog(const char* format, ...) __attribute__((format(printf, 2, 3)));
};

class QueryOptimizationLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

class BlockStreamJoinLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

class ASTParserLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

class ClientListenerLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

class ClientLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

class ThreadPoolLogging {
 public:
  static void log(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
  static void elog(const char* format, ...)
      __attribute__((format(printf, 1, 2)));
};

static void Logging_ExchangeIteratorLowerWithWideDependency(const char* format,
                                                            ...) {
#ifdef DEBUG_ExchangeIteratorWithWideDependency
  printf("[EILWWD]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
  printf("\n");
#endif
}

static void Logging_ExchangeIteratorWithWideDependency(const char* format,
                                                       ...) {
#ifdef DEBUG_ExchangeIteratorWithWideDependency
  printf("[EIWWD]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

// static void Logging_Environment(const char* format,...){
//#ifdef DEBUG_Environment
//	printf("[Environment]: ");
//	va_list arg;
//	va_start (arg, format);
//	vprintf (format, arg);
//	printf("\n");
//	va_end (arg);
//#endif
//}

static void Logging_PortManager(const char* format, ...) {
#ifdef DEBUG_PortManager
  printf("[PortManager]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

static void Logging_IteratorExecutorSlave(const char* format, ...) {
#ifdef DEBUG_IteratorExecutorSlave
  printf("[IteratorExecutorSlave]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

static void Logging_ExchangeIteratorEager(const char* format, ...) {
  //#ifdef DEBUG_ExchangeIteratorEager
  printf("[ExchangeIteratorEager]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
  //#endif
}

static void Logging_BlockStreamExchangeBase(const char* format, ...) {
#ifdef BlockStreamExchangeBase
  printf("[BlockStreamExchangeBase]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

static void Logging_ExchangeIteratorEagerLower(const char* format, ...) {
#ifdef DEBUG_ExchangeIteratorEagerLower
  printf("[ExchangeIteratorEagerLower]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}
//
// static void Logging_AdaptiveEndPoint(const char* format,...){
//#ifdef DEBUG_AdaptiveEndPoint
//	printf("[AdaptiveEndPoint]: ");
//	va_list arg;
//	va_start (arg, format);
//	vprintf (format, arg);
//	printf("\n");
//	va_end (arg);
//#endif
//}
static void Logging_ExpandableBlockStreamExchangeMaterialized(
    const char* format, ...) {
#ifdef DEBUG_ExpandableBlockStreamExchangeMaterialized
  printf("[ExpandableBlockStreamExchangeMaterialized]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

static void Logging_ExpandableBlockStreamExchangeLM(const char* format, ...) {
#ifdef DEBUG_ExpandableBlockStreamExchangeLM
  printf("[ExpandableBlockStreamExchangeLM]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
#endif
}

static void Logging_BlockStreamExchangeLowerBase(const char* format, ...) {
  //#ifdef DEBUG_BlockStreamExchangeLowerBase
  printf("[BlockStreamExchangeLowerBase]: ");
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  printf("\n");
  va_end(arg);
  //#endif
}

void SQLParse_log(const char* format, ...);
void SQLParse_elog(const char* format, ...);

#endif /* LOGGING_H_ */
