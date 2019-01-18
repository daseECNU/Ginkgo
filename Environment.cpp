/*
 * Environment.cpp
 *
 *  Created on: Aug 10, 2013
 *      Author: wangli
 */

#include "Environment.h"
#include "caf/all.hpp"
#include <map>
#include <vector>
#include <utility>
#include <net_write.c>
#include <boost/thread/thread.hpp>
#include <glog/logging.h>
#include <libconfig.h++>
#include <iostream>
#include <sstream>
#include <string>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include "k5-int.h"
#include "krb5.h"
#include "./Debug.h"
#include "./Config.h"
#include "common/Message.h"
#include "exec_tracker/stmt_exec_tracker.h"
#include "exec_tracker/segment_exec_tracker.h"
#include "node_manager/base_node.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "common/Logging.h"
#include "common/TypePromotionMap.h"
#include "common/TypeCast.h"
#include "common/error_define.h"
#include "codegen/CodeGenerator.h"
#include "common/expression/data_type_oper.h"
#include "common/expression/expr_type_cast.h"
#include "common/expression/type_conversion_matrix.h"
#include "mysql/mysql_server.h"
#include "httpserver/claimshttpserver.hpp"
#include "./stmt_handler/trans_handler.h"
using caf::announce;
using claims::BaseNode;
using claims::catalog::Catalog;
using claims::common::InitAggAvgDivide;
using claims::common::InitOperatorFunc;
using claims::common::InitpartitionValue;
using claims::common::InitTypeCastFunc;
using claims::common::InitTypeConversionMatrix;
using claims::common::rSuccess;
using claims::NodeAddr;
using claims::NodeSegmentID;
using claims::StmtExecTracker;
using claims::trans_handler::TransHandler;

Environment* Environment::_instance = 0;

void* sendauthinfo(void* args) {
  int SERVERPORT = Config::kerberos_notify_port;
  const int BACKLOG = 10;  //
  const int MAXSIZE = 1024;
  int sock, client_fd;
  sockaddr_in myAddr;
  sockaddr_in remoteAddr;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  int n = 0;
  // create socket
  if (sock == -1) {
    cout << "socket create fail!" << endl;
    exit(1);
  }
  // bind
  myAddr.sin_family = AF_INET;
  myAddr.sin_port = htons(SERVERPORT);
  myAddr.sin_addr.s_addr = INADDR_ANY;
  bzero(&(myAddr.sin_zero), 8);
  if (bind(sock, (sockaddr*)(&myAddr), sizeof(sockaddr)) == -1) {
    cout << "bind " << SERVERPORT << " error!" << endl;
    exit(1);
  }
  // listen
  if (listen(sock, 99) == -1) {
    cout << "listen" << SERVERPORT << "  error" << endl;
    exit(1);
  }
  while (true) {
    unsigned int sin_size = sizeof(sockaddr_in);
    if ((client_fd = accept(sock, (sockaddr*)(&remoteAddr), &sin_size)) == -1) {
      cout << "accept " << SERVERPORT << " error!" << endl;
      continue;
    }

    if (!fork()) {
      int rval;
      char buf[MAXSIZE];
      stringstream ss;
      if (Config::enable_kerberos)
        ss << "yes";
      else
        ss << "no";
      string s1 = ss.str();
      const char* msg = (char*)s1.c_str();
      if (send(client_fd, const_cast<char*>(msg), strlen(msg), 0) == -1)
        cout << "send " << SERVERPORT << " error!" << endl;
      close(client_fd);
      exit(0);
    }
  }
}

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
    if (rSuccess != catalog_->truncateDirtyData()) {
      LOG(ERROR) << "failed to truncate dirty data" << std::endl;
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
  }

  if (ismaster) {
    int kerberos_notify_port = Config::kerberos_notify_port;
    pthread_t test1;
    pthread_create(&test1, NULL, sendauthinfo, (void*)kerberos_notify_port);
    if (Config::enable_kerberos) initializeKerberosListener();
    initializeClientListener();
    /*create jdbc three system tables
     * variables, session, COLLATIONS
     *
     * JDBC system table confilict with distributed loading ,because system use
     *insert
     * */
    if (catalog_->getTable("variables") == NULL) {
      string query1 =
          "create table if not exists variables(Variable_name "
          "varchar(64),Valve "
          "varchar(1024));";
      TransHandler* trans_handler = new TransHandler(query1, -1);
      trans_handler->Execute();
      delete trans_handler;

      string query2 =
          "create projection on variables(Variable_name,Valve) number =1"
          "partitioned on row_id;";
      TransHandler* trans_handler1 = new TransHandler(query2, -1);
      trans_handler1->Execute();
      delete trans_handler1;
      // distribute load conflict with insert
      if (Config::distributed_load == false) {
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
        TransHandler* trans_handler2 = new TransHandler(query3, -1);
        trans_handler2->Execute();
        delete trans_handler2;
      }
    }
    if (catalog_->getTable("session") == NULL) {
      string query1 = "create table if not exists session(increment int);";
      TransHandler* trans_handler = new TransHandler(query1, -1);
      trans_handler->Execute();
      delete trans_handler;

      string query2 =
          "create projection on session(increment) number = 1 partitioned on"
          " row_id;";
      TransHandler* trans_handler1 = new TransHandler(query2, -1);
      trans_handler1->Execute();
      delete trans_handler1;
      if (Config::distributed_load == false) {
        string query3 = "insert into session values(1);";
        TransHandler* trans_handler2 = new TransHandler(query3, -1);
        trans_handler2->Execute();
        delete trans_handler2;
      }
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
      TransHandler* trans_handler = new TransHandler(query1, -1);
      trans_handler->Execute();
      delete trans_handler;

      string query2 =
          "create projection on "
          "COLLATIONS(COLLATION_NAME,CHARACTER_SET_NAME,I_d,D_EFAULT, "
          "COMPILED,"
          "SORTLEN) number = 1 partitioned on row_id;";
      TransHandler* trans_handler1 = new TransHandler(query2, -1);
      trans_handler1->Execute();
      delete trans_handler1;
      if (Config::distributed_load == false) {
        string query3 =
            "insert into COLLATIONS "
            "values(\"big5_chinese_ci\",\"big5\",1,\"Yes\",\"Yes\",1);";
        TransHandler* trans_handler2 = new TransHandler(query3, -1);
        trans_handler2->Execute();
        delete trans_handler2;
      }
    }
  }
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
                        &PartitionID::partition_off, &PartitionID::node_id);
  announce<ExchangeID>("ExchangeID", &ExchangeID::exchange_id,
                       &ExchangeID::partition_offset);
  announce<LoadInfo>("LoadInfo", &LoadInfo::cols_, &LoadInfo::proj_cols_,
                     &LoadInfo::write_path_, &LoadInfo::part_key_idx_,
                     &LoadInfo::prj_index_vec_, &LoadInfo::part_func_v_,
                     &LoadInfo::tbl_name_);
  announce<LoadMsg>("LoadMsg", &LoadMsg::blks_per_partition_,
                    &LoadMsg::logical_lengths_, &LoadMsg::write_path_name_,
                    &LoadMsg::node_id_, &LoadMsg::load_mode_,
                    &LoadMsg::tbl_name_);
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
  slave_node_->RegisterToMaster(true);
  node_id_ = slave_node_->get_node_id();
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
NodeID Environment::getNodeID() const { return node_id_; }
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
  InitpartitionValue();
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

void* krbserver(void* args) {
  krb5_context context;
  struct sockaddr_in peername;
  GETPEERNAME_ARG3_TYPE namelen = sizeof(peername);
  int sock = -1; /* incoming connection fd */
  krb5_data recv_data;
  short xmitlen;
  krb5_error_code retval;
  krb5_principal server;
  char repbuf[BUFSIZ];
  char* cname;
  const char* service;
  short port = 0; /* If user specifies port */
  const char* keytab_path;
  extern int opterr, optind;
  extern char* optarg;
  int ch;
  krb5_keytab keytab = NULL; /* Allow specification on command line */
  char* progname;
  int on = 1;
  const char* krb_srvinstance;

  port = atoi(Config::krb_listen_address.c_str());
  keytab_path = Config::krb_server_keyfile.c_str();
  service = Config::krb_srvname.c_str();
  krb_srvinstance = Config::krb_srvinstance.c_str();

  retval = krb5_init_context(&context);
  if (retval) {
    exit(1);
  }

  if ((retval = krb5_kt_resolve(context, keytab_path, &keytab))) {
    cout << "error while resolving keytab file" << endl;
    exit(2);
  }

  retval = krb5_sname_to_principal(context, krb_srvinstance, service,
                                   KRB5_NT_SRV_HST, &server);
  if (retval) {
    cout << "while generating service name" << endl;

    exit(1);
  }

  if (port) {
    struct sockaddr_in sockin;

    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
      // syslog(LOG_ERR, "socket: %m");
      exit(3);
    }

    /* Let the socket be reused right away */
    (void)setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(on));
    sockin.sin_family = AF_INET;
    sockin.sin_addr.s_addr = 0;
    sockin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr*)&sockin, sizeof(sockin))) {
      cout << "bind error!" << endl;
      exit(3);
    }
    if (listen(sock, 99) == -1) {
      cout << "listen error!" << endl;
      exit(3);
    }
  }

  while (true) {
    int client_fd;

    if ((client_fd = accept(sock, (struct sockaddr*)&peername, &namelen)) ==
        -1) {
      cout << "accept error!" << endl;
      exit(3);
    }

    if (!fork()) {
      krb5_ticket* ticket;
      krb5_auth_context auth_context = NULL;
      retval =
          krb5_recvauth(context, &auth_context, (krb5_pointer)&client_fd,
                        "KRB5_sample_protocol_v1.0", server, 0, /* no flags */
                        keytab, /* default keytab is NULL */
                        &ticket);

      if (retval) {
        exit(1);
      }
      retval = krb5_unparse_name(context, ticket->enc_part2->client, &cname);
      if (retval) {
        cout << "krb5_unparse_name error" << endl;
        strncpy(repbuf, "You are <unparse error>\n", sizeof(repbuf) - 1);
      } else {
        strncpy(repbuf, "You are ", sizeof(repbuf) - 1);
        strncat(repbuf, cname, sizeof(repbuf) - 1 - strlen(repbuf));
        strncat(repbuf, "\n", sizeof(repbuf) - 1 - strlen(repbuf));
        free(cname);
      }
      xmitlen = htons(strlen(repbuf));
      recv_data.length = strlen(repbuf);
      recv_data.data = repbuf;
      if ((retval = krb5_net_write(context, client_fd, (char*)&xmitlen,
                                   sizeof(xmitlen))) < 0) {
        cout << "krb5_net_write len  error" << endl;
        exit(1);
      }
      if ((retval = krb5_net_write(context, client_fd, (char*)recv_data.data,
                                   recv_data.length)) < 0) {
        cout << "krb5_net_write data error" << endl;
        exit(1);
      }

      krb5_free_ticket(context, ticket);
      if (keytab) krb5_kt_close(context, keytab);
      krb5_free_principal(context, server);
      krb5_auth_con_free(context, auth_context);
      krb5_free_context(context);
      close(client_fd);
      exit(0);
    }
  }
}

void Environment::initializeKerberosListener() {
  int a;
  pthread_t test;
  pthread_create(&test, NULL, krbserver, NULL);
}
