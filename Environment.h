/*
 * Environment.h
 *
 *  Created on: Aug 10, 2013
 *      Author: wangli
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_
#include "Executor/IteratorExecutorMaster.h"
#include "Executor/IteratorExecutorSlave.h"
#include "storage/BlockManager.h"
#include "storage/BlockManagerMaster.h"
#include "Resource/ResourceManagerMaster.h"
#include "Resource/ResourceManagerSlave.h"
#include "IndexManager/IndexManager.h"
#include "Executor/PortManager.h"
#include "common/Logging.h"
#include "utility/thread_pool.h"
#include "Client/ClaimsServer.h"
#include "exec_tracker/stmt_exec_tracker.h"
#include "exec_tracker/segment_exec_tracker.h"
#include "Executor/exchange_tracker.h"
#include "Executor/expander_tracker.h"
#include "node_manager/master_node.h"
#include "node_manager/slave_node.h"
#include "Resource/BufferManager.h"

namespace ginkgo {
namespace loader {
class SlaveLoader;
class MasterLoader;
}
}
using ginkgo::catalog::Catalog;
using ginkgo::loader::SlaveLoader;
using ginkgo::loader::MasterLoader;
using ginkgo::MasterNode;
using ginkgo::SegmentExecTracker;
using ginkgo::SlaveNode;
using ginkgo::StmtExecTracker;
class Catalog;
class IteratorExecutorSlave;
class BlockManager;
class ResourceManagerMaster;
class InstanceResourceManager;
class BlockManagerMaster;

class Environment {
 public:
  virtual ~Environment();
  static Environment* getInstance(bool ismaster = 0);
  std::string getIp();
  unsigned getPort();
  ExchangeTracker* getExchangeTracker();
  ResourceManagerMaster* getResourceManagerMaster();
  InstanceResourceManager* getResourceManagerSlave();
  NodeID getNodeID() const;
  void setNodeID(NodeID node_id){ node_id_ = node_id ;}
  ginkgo::catalog::Catalog* getCatalog() const;
  ThreadPool* getThreadPool() const;
  IteratorExecutorSlave* getIteratorExecutorSlave() const;
  Environment(bool ismaster = false);
  MasterNode* get_master_node() { return master_node_; }
  SlaveNode* get_slave_node() { return slave_node_; }
  BlockManager* get_block_manager() { return blockManager_; }
  IteratorExecutorMaster* get_iterator_executor_master() {
    return iteratorExecutorMaster;
  }
  BlockManagerMaster* get_block_manager_master() { return blockManagerMaster_; }

  StmtExecTracker* get_stmt_exec_tracker() { return stmt_exec_tracker_; }
  SegmentExecTracker* get_segment_exec_tracker() { return seg_exec_tracker_; }

  MasterLoader* get_master_loader() const { return master_loader_; }
  SlaveLoader* get_slave_loader() const { return slave_loader_; }

 private:
  void AnnounceCafMessage();
  void readConfigFile();
  void initializeStorage();
  void initializeResourceManager();
  void initializeBufferManager();
  void initializeIndexManager();
  void initializeClientListener();
  void initializeExpressionSystem();
  void destoryClientListener();
  bool initializeThreadPool();
  void InitMembership();

  bool InitLoader();

  bool InitTxnManager();

  bool InitTxnLog();

  bool AdvancedBindAllPart();

 private:
  static Environment* _instance;
  PortManager* portManager;
  std::string ip;
  unsigned port;
  IteratorExecutorSlave* iteratorExecutorSlave;
  IteratorExecutorMaster* iteratorExecutorMaster;
  ExchangeTracker* exchangeTracker;
  Logging* logging_;
  bool ismaster_;
  ResourceManagerMaster* resourceManagerMaster_;
  InstanceResourceManager* resourceManagerSlave_;
  Catalog* catalog_;
  /* the globally unique node id*/
  NodeID node_id_;
  BlockManagerMaster* blockManagerMaster_;
  BlockManager* blockManager_;
  BufferManager* bufferManager_;
  IndexManager* indexManager_;
  ExpanderTracker* expander_tracker_;
  ClientListener* listener_;

  ThreadPool* thread_pool_;
  MasterLoader* master_loader_;
  SlaveLoader* slave_loader_;
  MasterNode* master_node_;
  SlaveNode* slave_node_;

  StmtExecTracker* stmt_exec_tracker_;
  SegmentExecTracker* seg_exec_tracker_;
  /**
   * TODO: the master and slave pair, such as ResouceManagerMaster and
   * ResourceManagerSlave, should have a
   * base class which provides the access methods and is derived by
   * ResouceManagerMaster and ResourceManagerSlave.
   */
};

#endif /* ENVIRONMENT_H_ */
