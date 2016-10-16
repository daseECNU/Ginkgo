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
#include "../common/Block/MonitorableBuffer.h"
#include "../utility/ExpandabilityShrinkability.h"
#include "../utility/lock.h"
#include "../common/Logging.h"
#include "../common/ids.h"
#include "../common/ExpandedThreadTracker.h"
#include "./job_expander_tracker.h"
#include "../exec_tracker/stmt_exec_tracker.h"
#include "../scheduler/stage_task.h"

using claims::JobExpanderTracker;
using claims::LocalStage;
using claims::LocalStageEndPoint;
// namespace claims {
typedef pthread_t ExpandedThreadId;

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

 public:
  static ExpanderTracker* getInstance();
  virtual ~ExpanderTracker();
  /*
   * Call this method when a new expanded thread is created, and the
   * expander tracker will maintain a status of this thread.
   */
  bool RegisterExpandedThreadStatus(ExpandedThreadId id, ExpanderID exp_id);

  /*
   * Call this method just before a expanded thread finishes its work
   * such that the expander tracker could delete its status.
   */
  bool DeleteExpandedThreadStatus(ExpandedThreadId id);

  /*
   * Check whether an expanded thread specified by expanded_thread_id
   * has callback request. Return false when the given expanded thread
   * id is not in the list.
   */
  bool isExpandedThreadCallBack(ExpandedThreadId id);

  /*
   * Call this method if you want to callback the expanded thread specified
   * by the expanded thread id. Return false if the thread id does not exists
   * in expander tracker or the thread has be called back.
   */
  bool SetThreadStatusCallback(ExpandedThreadId id);

  bool AddStageEndpoint(ExpandedThreadId, LocalStageEndPoint);

  PerformanceInfo* getPerformanceInfo(ExpandedThreadId);
#ifdef OLD_TRACKER
  ExpanderID RegisterExpander(MonitorableBuffer* buffer,
                              ExpandabilityShrinkability* expand_shrink);
#else
  bool RegisterExpander(MonitorableBuffer* buffer,
                        ExpandabilityShrinkability* expand_shrink,
                        ExpanderID epd_id);
#endif
  void UnregisterExpander(ExpanderID expander_id);

  /*
   * return true if ExpanderTrack has any record regarding to the
   *  expander with specified id.
   */
  bool trackExpander(ExpanderID id);

  static segment_status getSegmentStatus(LocalStage&);

  JobExpanderTracker* GetJobExpanderTracker(u_int16_t job_id);

 private:
  ExpanderTracker();
  static void* monitoringThread(void* arg);

  /*
   * The access of current_stage might cause bug if thread-safe is not
   * concerned.
   */
  int DecideExpandingOrShrinking(LocalStage& current_stage,
                                 unsigned int current_degree_of_parallelism,
                                 bool print = true);

  int expandeIfNotExceedTheMaxDegreeOfParallelism(
      int current_degree_of_parallelism) const;
  int shrinkIfNotExceedTheMinDegreeOfParallelims(
      int current_degree_of_parallelism) const;

  void printStatus();
  // even through it overflow, it doesn't matter because there shouldn't be so
  // much active query
  u_int64_t GetJobId(ExpanderID epd_id) {
    return epd_id.first * kMaxJobIdNum +
           (epd_id.second / kMaxNodeNum / kMaxPartNum / kMaxTaskIdNum) %
               kMaxJobIdNum;
  }

 private:
  static ExpanderTracker* instance_;
  Lock lock_, lock_adapt_;
  boost::unordered_map<ExpandedThreadId, ExpanderID> thread_id_to_expander_id_;
#ifdef OLD_TRACKER

  std::unordered_map<ExpanderID, ExpanderStatus*> expander_id_to_status_;

  boost::unordered_map<ExpanderID, ExpandabilityShrinkability*>
      expander_id_to_expander_;
#else
  std::unordered_map<u_int64_t, JobExpanderTracker*> job_id_to_job_epd_tracker_;
#endif
  /*
   * A unordered map from expanded thread id to expanded thread status
   */
  pthread_t monitor_thread_id_;

 public:  // for debug, this should be private!
  std::map<ExpandedThreadId, ExpandedThreadStatus> thread_id_to_status_;
};
//}  // namespace claims
#endif /* EXPANDERTRACKER_H_ */
