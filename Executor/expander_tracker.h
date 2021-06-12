/*
 * expander_tracker.h
 *
 *  Created on: Mar 12, 2014
 *      Author: wangli
 */

#ifndef EXPANDERTRACKER_H_
#define EXPANDERTRACKER_H_

#include <pthread.h>
//#include <boost/unordered_map.hpp>
#include <map>
#include <unordered_map>
#include <stack>
#ifdef DMALLOC
#include "dmalloc.h"
#endif
#include "../common/Block/MonitorableBuffer.h"
#include "../utility/ExpandabilityShrinkability.h"
#include "../utility/lock.h"
#include "../common/Logging.h"
#include "../common/ids.h"
#include "../common/ExpandedThreadTracker.h"
typedef pthread_t expanded_thread_id;

enum endpoint_type { stage_src, stage_desc };
/**
 * Local local_stage endpoint refers to the start or the end of a stage within a
 * segment.
 * It could be either exchange, state, or expander.
 */
struct LocalStageEndPoint {
  LocalStageEndPoint(endpoint_type tp, std::string name = "Not Given",
                     MonitorableBuffer* buffer_handle = 0)
      : type(tp), monitorable_buffer(buffer_handle), end_point_name(name) {}
  LocalStageEndPoint()
      : monitorable_buffer(0), end_point_name("Initial"), type(stage_src) {}
  LocalStageEndPoint(const LocalStageEndPoint& r) {
    this->type = r.type;
    this->monitorable_buffer = r.monitorable_buffer;
    this->end_point_name = r.end_point_name;
  }
  endpoint_type type;
  MonitorableBuffer* monitorable_buffer;
  std::string end_point_name;
};

// typedef std::pair<LocalStageEndPoint,LocalStageEndPoint> local_stage;

struct local_stage {
  enum type { from_buffer, buffer_to_buffer, to_buffer, no_buffer, incomplete };
  local_stage() : type_(incomplete) {}
  local_stage(const local_stage& r) {
    this->type_ = r.type_;
    this->dataflow_src_ = r.dataflow_src_;
    this->dataflow_desc_ = r.dataflow_desc_;
  }
  //	operator=(const local_stage &r){
  //
  //	}
  local_stage(LocalStageEndPoint start, LocalStageEndPoint end)
      : dataflow_src_(start), dataflow_desc_(end) {
    bool start_buffer = dataflow_src_.monitorable_buffer != 0;
    bool end_buffer = dataflow_desc_.monitorable_buffer != 0;
    if (start_buffer) {
      if (end_buffer) {
        type_ = buffer_to_buffer;
      } else {
        type_ = from_buffer;
      }
    } else {
      if (end_buffer) {
        type_ = to_buffer;
      } else {
        type_ = no_buffer;
      }
    }
  }
  LocalStageEndPoint dataflow_src_;
  LocalStageEndPoint dataflow_desc_;
  type type_;
  std::string get_type_name(type tp) const {
    switch (tp) {
      case from_buffer: {
        return std::string("from_buffer");
      }
      case buffer_to_buffer: {
        return std::string("buffer_to_buffer");
      }
      case to_buffer: {
        return std::string("to_buffer");
      }
      case no_buffer: {
        return std::string("no_buffer");
      }
      default: { return std::string("invalid type!"); }
    }
    //		return std::string();
  }
  void print() {
    if (type_ == incomplete) {
      printf("Incomplete!\n");
      return;
    }
    printf("%s----->%s, type: %s\n", dataflow_src_.end_point_name.c_str(),
           dataflow_desc_.end_point_name.c_str(), get_type_name(type_).c_str());
  }
};

class ExpanderTracker {
  enum segment_status {
    seg_no_producing,
    seg_normal_producing,
    seg_over_producing,
    seg_under_producing
  };

  struct ExpandedThreadStatus {
    bool call_back_;
  };

  /*
   * This structure maintains the status of current expander in terms of running
   * stage.
   */
  struct ExpanderStatus {
    ExpanderStatus(ExpandabilityShrinkability* expand_shrink)
        : perf_info(expand_shrink) {}
    //		ExpanderStatus(){};
    ~ExpanderStatus();
    PerformanceInfo perf_info;
    local_stage current_stage;
    std::stack<LocalStageEndPoint> pending_endpoints;
    void addNewEndpoint(LocalStageEndPoint);
    Lock lock;
  };

 public:
  static ExpanderTracker* getInstance();
  virtual ~ExpanderTracker();
  /*
   * Call this method when a new expanded thread is created, and the
   * expander tracker will maintain a status of this thread.
   */
  bool registerNewExpandedThreadStatus(expanded_thread_id id,
                                       ExpanderID exp_id);

  /*
   * Call this method just before a expanded thread finishes its work
   * such that the expander tracker could delete its status.
   */
  bool deleteExpandedThreadStatus(expanded_thread_id id);

  /*
   * Check whether an expanded thread specified by expanded_thread_id
   * has callback request. Return false when the given expanded thread
   * id is not in the list.
   */
  bool isExpandedThreadCallBack(expanded_thread_id id);

  /*
   * Call this method if you want to callback the expanded thread specified
   * by the expanded thread id. Return false if the thread id does not exists
   * in expander tracker or the thread has be called back.
   */
  bool callbackExpandedThread(expanded_thread_id id);

  bool addNewStageEndpoint(expanded_thread_id, LocalStageEndPoint);

  PerformanceInfo* getPerformanceInfo(expanded_thread_id);

  ExpanderID registerNewExpander(MonitorableBuffer* buffer,
                                 ExpandabilityShrinkability* expand_shrink);
  void unregisterExpander(ExpanderID expander_id);

  /*
   * return true if ExpanderTrack has any record regarding to the
   *  expander with specified id.
   */
  bool trackExpander(ExpanderID id) const;

  static segment_status getSegmentStatus(local_stage&);

 private:
  ExpanderTracker();
  static void* monitoringThread(void* arg);

  /*
   * The access of current_stage might cause bug if thread-safe is not
   * concerned.
   */
  int decideExpandingOrShrinking(local_stage& current_stage,
                                 unsigned int current_degree_of_parallelism,
                                 bool print = true);

  int expandeIfNotExceedTheMaxDegreeOfParallelism(
      int current_degree_of_parallelism) const;
  int shrinkIfNotExceedTheMinDegreeOfParallelims(
      int current_degree_of_parallelism) const;

  void printStatus();

 private:
  static ExpanderTracker* instance_;

  Lock lock_;

  boost::unordered_map<expanded_thread_id, ExpanderID>
      thread_id_to_expander_id_;

  std::unordered_map<ExpanderID, ExpanderStatus*> expander_id_to_status_;

  boost::unordered_map<ExpanderID, ExpandabilityShrinkability*>
      expander_id_to_expand_shrink_;

  /*
   * A unordered map from expanded thread id to expanded thread status
   */
 public:  // for debug, this should be private!
  std::map<expanded_thread_id, ExpandedThreadStatus> id_to_status_;

  Logging* log_;

  pthread_t monitor_thread_id_;
};

#endif /* EXPANDERTRACKER_H_ */
