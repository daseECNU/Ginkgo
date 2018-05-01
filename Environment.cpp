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
#include <netinet/in.h>
#include <unistd.h>      //for fork and read
#include <sys/types.h>   //for socket
#include <sys/socket.h>  //for socket
#include <arpa/inet.h>
#include <cstdlib>
#include "k5-int.h"
#include "krb5.h"
#include <net_write.c>

using caf::announce;
using claims::BaseNode;
using claims::catalog::Catalog;
using claims::common::InitAggAvgDivide;
using claims::common::InitOperatorFunc;
using claims::common::InitpartitionValue;
using claims::common::InitTypeCastFunc;
using claims::common::InitTypeConversionMatrix;
//#define DEBUG_MODE
#include "catalog/catalog.h"
using claims::common::rSuccess;
using claims::NodeAddr;
using claims::NodeSegmentID;
using claims::StmtExecTracker;

Environment *Environment::_instance = 0;

void *sendauthinfo(void *args) {
  int SERVERPORT = Config::kerberos_notify_port;
  cout << SERVERPORT << endl;
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
  if (bind(sock, (sockaddr *)(&myAddr), sizeof(sockaddr)) == -1) {
    cout << "bind error!" << endl;
    exit(1);
  }
  // listen
  if (listen(sock, 99) == -1) {
    cout << "listen error" << endl;
    exit(1);
  }
  while (true) {
    unsigned int sin_size = sizeof(sockaddr_in);
    if ((client_fd = accept(sock, (sockaddr *)(&remoteAddr), &sin_size)) ==
        -1) {
      cout << "accept error!" << endl;
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
      const char *msg = (char *)s1.c_str();
      if (send(client_fd, const_cast<char *>(msg), strlen(msg), 0) == -1)
        cout << "send error!" << endl;
      close(client_fd);
      exit(0);
    }
  }
}

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
      cerr << "ERROR: truncate dirty data failed" << endl;
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
#ifndef DEBUG_MODE
  if (ismaster) {
    int kerberos_notify_port = Config::kerberos_notify_port;
    pthread_t test1;
    pthread_create(&test1, NULL, sendauthinfo, (void *)kerberos_notify_port);
    if (Config::enable_kerberos) initializeKerberosListener();
    initializeClientListener();
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
Environment *Environment::getInstance(bool ismaster) {
  if (_instance == 0) {
    new Environment(ismaster);
  }
  return _instance;
}
std::string Environment::getIp() { return ip; }
unsigned Environment::getPort() { return port; }

ThreadPool *Environment::getThreadPool() const { return thread_pool_; }

void Environment::readConfigFile() {
  libconfig::Config cfg;
  cfg.readFile(Config::config_file.c_str());
  ip = (const char *)cfg.lookup("ip");
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
  /*both master and slave node run the BlockManager.*/
  //		BlockManagerId *bmid=new BlockManagerId();
  //		string
  // actorname="blockManagerWorkerActor_"+bmid->blockManagerId;
  //		cout<<actorname.c_str()<<endl;
  //		BlockManager::BlockManagerWorkerActor
  //*blockManagerWorkerActor=new
  // BlockManager::BlockManagerWorkerActor(endpoint,framework_storage,actorname.c_str());

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

ExchangeTracker *Environment::getExchangeTracker() { return exchangeTracker; }
ResourceManagerMaster *Environment::getResourceManagerMaster() {
  return resourceManagerMaster_;
}
InstanceResourceManager *Environment::getResourceManagerSlave() {
  return resourceManagerSlave_;
}
NodeID Environment::getNodeID() const { return node_id_; }
claims::catalog::Catalog *Environment::getCatalog() const { return catalog_; }

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

IteratorExecutorSlave *Environment::getIteratorExecutorSlave() const {
  return iteratorExecutorSlave;
}

void *krbserver(void *args) {
  krb5_context context;
  struct sockaddr_in peername;
  GETPEERNAME_ARG3_TYPE namelen = sizeof(peername);
  int sock = -1; /* incoming connection fd */
  krb5_data recv_data;
  short xmitlen;
  krb5_error_code retval;
  krb5_principal server;
  char repbuf[BUFSIZ];
  char *cname;
  const char *service;
  short port = 0; /* If user specifies port */
  const char *keytab_path;
  extern int opterr, optind;
  extern char *optarg;
  int ch;
  krb5_keytab keytab = NULL; /* Allow specification on command line */
  char *progname;
  int on = 1;

  port = atoi(Config::krb_listen_address.c_str());
  keytab_path = Config::krb_server_keyfile.c_str();
  service = Config::krb_srvname.c_str();

  retval = krb5_init_context(&context);
  if (retval) {
    exit(1);
  }

  if ((retval = krb5_kt_resolve(context, keytab_path, &keytab))) {
    cout << "error while resolving keytab file" << endl;
    exit(2);
  }

  retval =
      krb5_sname_to_principal(context, NULL, service, KRB5_NT_SRV_HST, &server);
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
    //        (void) setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&on,
    //                          sizeof(on));
    sockin.sin_family = AF_INET;
    sockin.sin_addr.s_addr = 0;
    sockin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *)&sockin, sizeof(sockin))) {
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

    if ((client_fd = accept(sock, (struct sockaddr *)&peername, &namelen)) ==
        -1) {
      cout << "accept error!" << endl;
      exit(3);
    }

    if (!fork()) {
      krb5_ticket *ticket;
      krb5_auth_context auth_context = NULL;
      retval =
          krb5_recvauth(context, &auth_context, (krb5_pointer)&client_fd,
                        "KRB5_sample_protocol_v1.0", server, 0, /* no flags */
                        keytab, /* default keytab is NULL */
                        &ticket);

      if (retval) {
        //        cout << "recvauth failed--%s" << error_message(retval)
        //             << endl;  // prints !!!Hello World!!!

        // syslog(LOG_ERR, "recvauth failed--%s", error_message(retval));
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
      if ((retval = krb5_net_write(context, client_fd, (char *)&xmitlen,
                                   sizeof(xmitlen))) < 0) {
        cout << "krb5_net_write len  error" << endl;
        exit(1);
      }
      if ((retval = krb5_net_write(context, client_fd, (char *)recv_data.data,
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
