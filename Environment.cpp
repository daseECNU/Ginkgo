/*
 * Environment.cpp
 *
 *  Created on: Aug 10, 2013
 *      Author: wangli
 */

#include "Environment.h"
#include "caf/all.hpp"
#include <map>
#include <utility>
#include "common/Message.h"
#include "exec_tracker/stmt_exec_tracker.h"
#include "exec_tracker/segment_exec_tracker.h"
#include "node_manager/base_node.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <libconfig.h++>
#include <iostream>
#include <sstream>
#include <string>
#include "./Debug.h"
#include "./Config.h"
#include "common/Logging.h"
#include "common/TypePromotionMap.h"
#include "common/TypeCast.h"
#include "common/error_define.h"
#include "codegen/CodeGenerator.h"
#include "common/expression/data_type_oper.h"
#include "common/expression/expr_type_cast.h"
#include "common/expression/type_conversion_matrix.h"
#include "mysql/mysql_server.h"
#include <boost/thread/thread.hpp>
#include "httpserver/claimshttpserver.hpp"
#include "./stmt_handler/stmt_handler.h"

using caf::announce;
using claims::BaseNode;
using claims::catalog::Catalog;
using claims::common::InitAggAvgDivide;
using claims::common::InitOperatorFunc;
using claims::common::InitTypeCastFunc;
using claims::common::InitTypeConversionMatrix;
//#define DEBUG_MODE
#include "catalog/catalog.h"
using claims::common::rSuccess;
using claims::NodeAddr;
using claims::NodeSegmentID;
using claims::StmtExecTracker;
using claims::stmt_handler::StmtHandler;
Environment* Environment::_instance = 0;

struct HttpserverInfo {
  int hargc;
  std::string hargv[5];
};
Environment::Environment(bool ismaster) : ismaster_(ismaster) {
  _instance = this;
  Config::getInstance();
  CodeGenerator::getInstance();
  logging_ = new EnvironmentLogging();
  readConfigFile();
  initializeExpressionSystem();
  portManager = PortManager::getInstance();

  if (ismaster) {
    catalog_ = claims::catalog::Catalog::getInstance();
    logging_->log("restore the catalog ...");
    if (rSuccess != catalog_->restoreCatalog()) {
      LOG(ERROR) << "failed to restore catalog" << std::endl;
      cerr << "ERROR: restore catalog failed" << endl;
    }
  }
  stmt_exec_tracker_ = new StmtExecTracker();
  seg_exec_tracker_ = new SegmentExecTracker();

  if (true == g_thread_pool_used) {
    logging_->log("Initializing the ThreadPool...");
    if (false == initializeThreadPool()) {
      logging_->elog("initialize ThreadPool failed");
    }
  }
  /**
   * TODO:
   * DO something in AdaptiveEndPoint such that the construction function does
          not return until the connection is completed. If so, the following
   sleep()
          dose not needed.

          This is done in Aug.18 by Li :)
   */

  /*Before initializing Resource Manager, the instance ip and port should be
   * decided.*/
  AnnounceCafMessage();
  initializeResourceManager();
  // should after above
  InitMembership();

  initializeStorage();

  initializeBufferManager();

  logging_->log("Initializing the ExecutorMaster...");
  iteratorExecutorMaster = new IteratorExecutorMaster();

  logging_->log("Initializing the ExecutorSlave...");
  iteratorExecutorSlave = new IteratorExecutorSlave();

  exchangeTracker = new ExchangeTracker();
  expander_tracker_ = ExpanderTracker::getInstance();
  if (ismaster) {
    pthread_t t_cmysql, t_httpserver;
    // initializeClientListener();
    const int error1 = pthread_create(&t_cmysql, NULL, InitMysqlListener, NULL);
    if (error1 != 0) {
      LOG(ERROR) << "cannot create t_cmysql thread!" << strerror(errno)
                 << std::endl;
    }
    struct HttpserverInfo HttpserverInof_;
    const int error2 = pthread_create(&t_httpserver, NULL, HttpserverRun, NULL);
    if (error2 != 0) {
      LOG(ERROR) << "cannot create t_httpserver thread!" << strerror(errno)
                 << std::endl;
    }

    //    delete stmt_handler, stmt_handler1, stmt_handler2;
  }

#ifndef DEBUG_MODE
  if (ismaster) {
    initializeClientListener();
    /*create jdbc three system tables
     * variables, session, COLLATIONS
     * */
    if (catalog_->getTable("variables") == NULL) {
      string query1 =
          "create table if not exists variables(Variable_name "
          "varchar(64),Valve "
          "varchar(1024));";
      StmtHandler* stmt_handler = new StmtHandler(query1);
      ExecutedResult exec_r;
      exec_r.status_ = true;
      stmt_handler->Execute(&exec_r);
      if (exec_r.status_ == true) {
        ExecutedResult exec_r1, exec_r2;
        exec_r1.status_ = true;
        exec_r2.status_ = true;
        string query2 =
            "create projection on variables(Variable_name,Valve) number =1"
            "partitioned on row_id;";
        StmtHandler* stmt_handler1 = new StmtHandler(query2);
        stmt_handler1->Execute(&exec_r1);
        string query3 =
            "insert into variables "
            "values(\"character_set_client\",\"utf8\"),(\"character_set_"
            "connection\",\"utf8\"),(\"character_set_results\",\"utf8\"),("
            "\"character_set_server\",\"latin1\"),(\"init_connect\",\" "
            "\"),(\"interactive_timeout\",\"28800\"),(\"lower_case_table_"
            "names\","
            "\"2\"),(\"max_allowed_packet\",\"4194304\"),(\"net_buffer_"
            "length\","
            "\"16384\"),(\"net_write_timeout\",\"60\"),(\"query_cache_size\","
            "\"1048576\"),(\"query_cache_type\",\"OFF\"),(\"sql_mode\",\"NO_"
            "ENGINE_"
            "SUBSTITUTION\"),(\"system_time_zone\",\"CST\"),(\"time_zone\","
            "\"SYSTEM\"),(\"tx_isolation\",\"REPEATABLE-READ\"),(\"wait_"
            "timeout\","
            "\"28800\");";
        StmtHandler* stmt_handler2 = new StmtHandler(query3);
        stmt_handler2->Execute(&exec_r2);
        delete stmt_handler1, stmt_handler2;
      }
      delete stmt_handler;
    }
    if (catalog_->getTable("session") == NULL) {
      string query1 = "create table if not exists session(increment int);";
      StmtHandler* stmt_handler = new StmtHandler(query1);
      ExecutedResult exec_r;
      exec_r.status_ = true;
      stmt_handler->Execute(&exec_r);
      if (exec_r.status_ == true) {
        ExecutedResult exec_r1, exec_r2;
        exec_r1.status_ = true;
        exec_r2.status_ = true;
        string query2 =
            "create projection on session(increment) number = 1 partitioned on "
            "row_id;";
        StmtHandler* stmt_handler1 = new StmtHandler(query2);
        stmt_handler1->Execute(&exec_r1);
        string query3 = "insert into session values(1);";
        StmtHandler* stmt_handler2 = new StmtHandler(query3);
        stmt_handler2->Execute(&exec_r2);
        delete stmt_handler1, stmt_handler2;
      }
      delete stmt_handler;
    }
    if (catalog_->getTable("COLLATIONS") == NULL) {
      string query1 =
          "CREATE TABLE COLLATIONS ("
          "COLLATION_NAME varchar(32),"
          "CHARACTER_SET_NAME varchar(32),"
          "I_d int,"
          "D_EFAULT varchar(3),"
          "COMPILED varchar(3),"
          "SORTLEN int);";
      StmtHandler* stmt_handler = new StmtHandler(query1);
      ExecutedResult exec_r;
      exec_r.status_ = true;
      stmt_handler->Execute(&exec_r);
      if (exec_r.status_ == true) {
        ExecutedResult exec_r1, exec_r2;
        exec_r1.status_ = true;
        exec_r2.status_ = true;
        string query2 =
            "create projection on "
            "COLLATIONS(COLLATION_NAME,CHARACTER_SET_NAME,I_d,D_EFAULT, "
            "COMPILED,"
            "SORTLEN) number = 1 partitioned on row_id;";
        StmtHandler* stmt_handler1 = new StmtHandler(query2);
        stmt_handler1->Execute(&exec_r1);
        string query3 =
            "insert into COLLATIONS "
            "values(\"big5_chinese_ci\",\"big5\",1,\"Yes\",\"Yes\",1);";
        StmtHandler* stmt_handler2 = new StmtHandler(query3);
        stmt_handler2->Execute(&exec_r2);
        delete stmt_handler1, stmt_handler2;
      }
      delete stmt_handler;
    }
  }
#endif
}

Environment::~Environment() {
  _instance = 0;
  delete expander_tracker_;
  delete logging_;
  delete portManager;
  delete catalog_;
  if (ismaster_) {
    delete iteratorExecutorMaster;
    delete resourceManagerMaster_;
    delete blockManagerMaster_;
#ifndef DEBUG_MODE
    destoryClientListener();
#endif
  }
  delete iteratorExecutorSlave;
  delete exchangeTracker;
  delete resourceManagerSlave_;
  delete blockManager_;
  delete bufferManager_;
}
Environment* Environment::getInstance(bool ismaster) {
  if (_instance == 0) {
    new Environment(ismaster);
  }
  return _instance;
}
std::string Environment::getIp() { return ip; }
unsigned Environment::getPort() { return port; }

ThreadPool* Environment::getThreadPool() const { return thread_pool_; }

void Environment::readConfigFile() {
  libconfig::Config cfg;
  cfg.readFile(Config::config_file.c_str());
  ip = (const char*)cfg.lookup("ip");
}

void Environment::AnnounceCafMessage() {
  announce<StorageBudgetMessage>(
      "StorageBudgetMessage", &StorageBudgetMessage::nodeid,
      &StorageBudgetMessage::memory_budget, &StorageBudgetMessage::disk_budget);
  announce<ProjectionID>("ProjectionID", &ProjectionID::table_id,
                         &ProjectionID::projection_off);
  announce<PartitionID>("PartitionID", &PartitionID::projection_id,
                        &PartitionID::partition_off);
  announce<ExchangeID>("ExchangeID", &ExchangeID::exchange_id,
                       &ExchangeID::partition_offset);
  announce<BaseNode>("BaseNode", &BaseNode::node_id_to_addr_);
  announce<NodeSegmentID>("NodeSegmentID", &NodeSegmentID::first,
                          &NodeSegmentID::second);
}
void Environment::initializeStorage() {
  if (ismaster_) {
    blockManagerMaster_ = BlockManagerMaster::getInstance();
    blockManagerMaster_->initialize();
  }

  blockManager_ = BlockManager::getInstance();
  blockManager_->initialize();
}

void Environment::initializeResourceManager() {
  if (ismaster_) {
    resourceManagerMaster_ = new ResourceManagerMaster();
  }
  resourceManagerSlave_ = new InstanceResourceManager();
  //  nodeid = resourceManagerSlave_->Register();
}
void Environment::InitMembership() {
  if (ismaster_) {
    master_node_ = MasterNode::GetInstance();
  }
  slave_node_ = SlaveNode::GetInstance();
  slave_node_->RegisterToMaster();
  nodeid = slave_node_->get_node_id();
}
void Environment::initializeBufferManager() {
  bufferManager_ = BufferManager::getInstance();
}

void Environment::initializeIndexManager() {
  indexManager_ = IndexManager::getInstance();
}

ExchangeTracker* Environment::getExchangeTracker() { return exchangeTracker; }
ResourceManagerMaster* Environment::getResourceManagerMaster() {
  return resourceManagerMaster_;
}
InstanceResourceManager* Environment::getResourceManagerSlave() {
  return resourceManagerSlave_;
}
NodeID Environment::getNodeID() const { return nodeid; }
claims::catalog::Catalog* Environment::getCatalog() const { return catalog_; }

void Environment::initializeClientListener() {
  listener_ = new ClientListener(Config::client_listener_port);
  listener_->configure();
}

void Environment::initializeExpressionSystem() {
  InitTypeConversionMatrix();
  InitOperatorFunc();
  InitAggAvgDivide();
  InitTypeCastFunc();
}

void Environment::destoryClientListener() {
  listener_->shutdown();
  delete listener_;
}

bool Environment::initializeThreadPool() {
  thread_pool_ = new ThreadPool();
  return thread_pool_->Init(Config::thread_pool_init_thread_num);
}

IteratorExecutorSlave* Environment::getIteratorExecutorSlave() const {
  return iteratorExecutorSlave;
}

void* Environment::InitMysqlListener(void* null_) {
  // claims::mysql::CMysqlServer::GetInstance()->Initialize();
  claims::mysql::CMysqlServer::GetInstance()->Start();
}

void* Environment::HttpserverRun(void* null) {
  struct HttpserverInfo parg;
  parg.hargc = 5;
  parg.hargv[0] = "";
  sleep(1);
  parg.hargv[1] = Config::httpserver_master_ip;
  parg.hargv[2] = Config::httpserver_master_port;
  parg.hargv[3] = Config::httpserver_thread_num;
  parg.hargv[4] = Config::httpserver_doc_root;
  httpserver::init(parg.hargc, parg.hargv);
}
