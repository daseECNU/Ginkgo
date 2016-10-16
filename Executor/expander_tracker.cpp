/*
 * expander_tracker.cpp
 *
 *  Created on: Mar 12, 2014
 *      Author: wangli
 */

#include "../Executor/expander_tracker.h"
#include <glog/logging.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../IDsGenerator.h"
#include "../Config.h"
#include "../common/ids.h"

#include "./job_expander_tracker.h"
#include "../common/memory_handle.h"

using claims::JobExpanderTracker;
// namespace claims {

#define DECISION_SHRINK 0
#define DECISION_EXPAND 1
#define DECISION_KEEP 2

#define THRESHOLD 0.1
#define THRESHOLD_EMPTY (THRESHOLD)
#define THRESHOLD_FULL (1 - THRESHOLD)
#define Refine 0.05

#define SWITCHER(SWITCH, CAUSE) \
  if (SWITCH) CAUSE;

///**
// * Ideally, this should be guaranteed by resource manager.
// */
//#define MAX_DEGREE_OF_PARALLELISM 6

ExpanderTracker* ExpanderTracker::instance_ = 0;
ExpanderTracker::ExpanderTracker() {
  pthread_create(&monitor_thread_id_, 0, monitoringThread, this);
}

ExpanderTracker::~ExpanderTracker() {
  pthread_cancel(monitor_thread_id_);
  instance_ = 0;
#ifdef OLD_TRACKER
  expander_id_to_status_.clear();
#else
#endif
}

ExpanderTracker* ExpanderTracker::getInstance() {
  if (instance_ == 0) {
    instance_ = new ExpanderTracker();
  }
  return instance_;
}
bool ExpanderTracker::RegisterExpandedThreadStatus(ExpandedThreadId thread_id,
                                                   ExpanderID epd_id) {
  lock_.acquire();
  // new status for the underlying thread
  if (thread_id_to_status_.find(thread_id) != thread_id_to_status_.end()) {
    LOG(ERROR) << "the thread = " << thread_id
               << " is already in thread_id_to_status";
    lock_.release();
    assert(false);
    return false;
  } else {
    ExpandedThreadStatus status;
    status.call_back_ = false;
    thread_id_to_status_[thread_id] = status;
  }
  // make pair of <thread_id,epd_id>
  if (thread_id_to_expander_id_.find(thread_id) !=
      thread_id_to_expander_id_.end()) {
    LOG(ERROR) << "the thread = " << thread_id
               << " is already in thread_id_to_expander_id";
    lock_.release();
    assert(false);
    return false;
  } else {
    thread_id_to_expander_id_[thread_id] = epd_id;
  }
  lock_.release();
  return true;
}
bool ExpanderTracker::DeleteExpandedThreadStatus(ExpandedThreadId thread_id) {
  lock_.acquire();
  if (thread_id_to_status_.find(thread_id) == thread_id_to_status_.end()) {
    LOG(ERROR) << "the thread = " << thread_id
               << " isn't in thread_id_to_status";
    lock_.release();
    assert(false);
    return false;
  } else {
    thread_id_to_status_.erase(thread_id);
  }
  if (thread_id_to_expander_id_.find(thread_id) ==
      thread_id_to_expander_id_.end()) {
    LOG(ERROR) << "the thread = " << thread_id
               << " isn't in thread_id_to_expander_id";
    lock_.release();
    assert(false);
    return false;
  } else {
    thread_id_to_expander_id_.erase(thread_id);
  }
  lock_.release();
  return true;
}
bool ExpanderTracker::isExpandedThreadCallBack(
    ExpandedThreadId thread_id) {  // if this thread want to exit, return true
  lock_.acquire();
  if (thread_id_to_status_.find(thread_id) != thread_id_to_status_.end()) {
    bool ret = thread_id_to_status_[thread_id].call_back_;
    lock_.release();
    return ret;
  } else {
    LOG(ERROR) << "the thread = " << thread_id
               << " isn't in thread_id_to_status_";
    lock_.release();
    return false;
  }
}
bool ExpanderTracker::SetThreadStatusCallback(ExpandedThreadId thread_id) {
  lock_.acquire();
  if (thread_id_to_status_.find(thread_id) != thread_id_to_status_.end()) {
    thread_id_to_status_[thread_id].call_back_ = true;
    lock_.release();
    return true;
  }
  LOG(ERROR) << "the thread = " << thread_id
             << " isn't in thread_id_to_status_";
  lock_.release();
  return false;
}

bool ExpanderTracker::AddStageEndpoint(ExpandedThreadId thread_id,
                                       LocalStageEndPoint endpoint) {
  lock_.acquire();
  if (thread_id_to_expander_id_.find(thread_id) ==
      thread_id_to_expander_id_.end()) {
    lock_.release();
    return false;
  }
  ExpanderID expender_id = thread_id_to_expander_id_[thread_id];
#ifdef OLD_TRACKER
  if (expander_id_to_status_.find(expender_id) ==
      expander_id_to_status_.end()) {
    lock_.release();
    assert(false);
    return false;
  }
  expander_id_to_status_[expender_id]->AddEndpoint(endpoint);
#else
  auto it = job_id_to_job_epd_tracker_.find(GetJobId(expender_id));
  if (it == job_id_to_job_epd_tracker_.end()) {
    LOG(ERROR) << "thread id= " << thread_id
               << " add stage but couldn't find job= " << GetJobId(expender_id);
    lock_.release();
    return false;
  }
  it->second->AddStageEndpoint(expender_id, endpoint);
#endif
  lock_.release();
  return true;
}
PerformanceInfo* ExpanderTracker::getPerformanceInfo(
    ExpandedThreadId thread_id) {
  lock_.acquire();
  if (thread_id_to_expander_id_.find(thread_id) ==
      thread_id_to_expander_id_.end()) {
    lock_.release();
    assert(false && "thread_id_to_expander_id_ don't have this element");
    //		return false;
  }
  ExpanderID expander_id = thread_id_to_expander_id_[thread_id];
  PerformanceInfo* ret = NULL;
#ifdef OLD_TRACKER

  if (expander_id_to_status_.find(expander_id) ==
      expander_id_to_status_.end()) {
    lock_.release();
    assert(false && "expander_id_to_status_ don't have this element");
    //		return false;
  }
  PerformanceInfo* ret = &expander_id_to_status_[expander_id]->perf_info;
#else
  auto it = job_id_to_job_epd_tracker_.find(GetJobId(expander_id));
  if (it == job_id_to_job_epd_tracker_.end()) {
    LOG(ERROR) << "thread id= " << thread_id
               << " getPerformanceInfo but couldn't find job= "
               << GetJobId(expander_id);
    lock_.release();
    return false;
  }
  ret = it->second->GetPerformance(expander_id);
#endif
  lock_.release();
  return ret;
}
bool ExpanderTracker::RegisterExpander(
    MonitorableBuffer* buffer, ExpandabilityShrinkability* expand_shrink,
    ExpanderID expander_id) {
  lock_.acquire();
  auto it = job_id_to_job_epd_tracker_.find(GetJobId(expander_id));
  if (it != job_id_to_job_epd_tracker_.end()) {
    it->second->RegisterExpander(buffer, expand_shrink, expander_id);
  } else {
    auto job_tracker = new JobExpanderTracker();
    job_id_to_job_epd_tracker_.insert(
        make_pair(GetJobId(expander_id), job_tracker));
    job_tracker->RegisterExpander(buffer, expand_shrink, expander_id);
  }
  lock_.release();
  return true;
}
#ifdef OLD_TRACKER
ExpanderID ExpanderTracker::RegisterExpander(
    MonitorableBuffer* buffer, ExpandabilityShrinkability* expand_shrink) {
  assert(expand_shrink != 0);
  ExpanderID expander_id;
  lock_.acquire();
  expander_id = IDsGenerator::getInstance()->getUniqueExpanderID();
  expander_id_to_status_[expander_id] = new ExpanderStatus(expand_shrink);
  expander_id_to_status_[expander_id]->AddEndpoint(
      LocalStageEndPoint(stage_desc, "Expander", buffer));
  expander_id_to_expander_[expander_id] = expand_shrink;

  lock_.release();
  LOG(INFO) << "New Expander is registered, ID= " << expander_id;
  return expander_id;
}
#endif
void ExpanderTracker::UnregisterExpander(ExpanderID expander_id) {
  lock_adapt_.acquire();
  lock_.acquire();
  // make sure no thread is active in the underlying expander
  for (auto it = thread_id_to_expander_id_.begin();
       it != thread_id_to_expander_id_.end(); ++it) {
    if (it->second == expander_id) {
      LOG(WARNING) << "there are active thread in the expander= "
                   << expander_id.first << " , " << expander_id.second;
      //      assert(false);
    }
  }
#ifdef OLD_TRACKER
  if (expander_id_to_expander_.find(expander_id) ==
      expander_id_to_expander_.end()) {
    LOG(ERROR) << "Unregister expander_id = " << expander_id
               << " doesn't exist in expander_id_to_expander_";
  }
  if (expander_id_to_status_.find(expander_id) ==
      expander_id_to_status_.end()) {
    LOG(ERROR) << "Unregister expander_id = " << expander_id
               << " doesn't exist in expander_id_to_status_ ";
  }
  auto es = expander_id_to_status_.find(expander_id)->second;
  expander_id_to_status_.erase(expander_id);

  LOG(INFO) << "erased expander id:" << expander_id
            << " from expander_id_to_status_" << std::endl;
  expander_id_to_expander_.erase(expander_id);
  DELETE_PTR(es);
#else
  auto it = job_id_to_job_epd_tracker_.find(GetJobId(expander_id));
  if (it == job_id_to_job_epd_tracker_.end()) {
    LOG(ERROR) << "RegisterExpander doesn't have job= "
               << GetJobId(expander_id);
    assert(false);
  }
  it->second->UnRegisterExpander(expander_id);
  if (it->second->IsEmpty()) {
    DELETE_PTR(it->second);
    job_id_to_job_epd_tracker_.erase(it);
  }
#endif
  lock_.release();
  lock_adapt_.release();
}

ExpanderTracker::segment_status ExpanderTracker::getSegmentStatus(
    LocalStage& current_stage) {
  switch (current_stage.type_) {
    case LocalStage::incomplete: {
      return seg_no_producing;
    }
    case LocalStage::no_buffer: {
      return seg_under_producing;
    }
    case LocalStage::from_buffer: {
      double utilization_ratio =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      if (utilization_ratio > THRESHOLD_FULL + Refine) {
        return seg_under_producing;
      } else if (utilization_ratio < THRESHOLD_EMPTY - Refine) {
        return seg_over_producing;
      }
      return seg_normal_producing;
    }
    case LocalStage::to_buffer: {
      double utilization_ratio =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      if (utilization_ratio > THRESHOLD_FULL + Refine) {
        return seg_over_producing;
      } else if (utilization_ratio < THRESHOLD_EMPTY - Refine) {
        return seg_under_producing;
      }
      return seg_normal_producing;
    }
    case LocalStage::buffer_to_buffer: {
      double src_ratio =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      double desc_ratio =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      if (src_ratio < THRESHOLD_EMPTY - Refine ||
          desc_ratio > THRESHOLD_FULL + Refine) {
        return seg_over_producing;
      } else if (src_ratio > THRESHOLD_FULL - Refine &&
                 desc_ratio < THRESHOLD_EMPTY + Refine) {
        return seg_under_producing;
      } else {
        return seg_normal_producing;
      }
    }
    default: {
      assert(false);
      return seg_no_producing;
    }
  }
}
int ExpanderTracker::DecideExpandingOrShrinking(
    LocalStage& current_stage, unsigned int current_degree_of_parallelism,
    bool print) {
  /**
   * In the initial implementation, if all expanded threads are shrunk and the
   * condition for expanding will never be triggered due to the exhaust of input
   * data-flow, then the remaining work will never be done.
   *
   *  To avoid this problem, we should first check whether the dataflow is
   * exhausted. If so, we should guarantee that there is at least one expanded
   * threads to process the remaining data in buffer.
   */

  int ret;
  switch (current_stage.type_) {
    case LocalStage::incomplete: {
      ret = DECISION_KEEP;
      break;
    }
    case LocalStage::no_buffer: {
      ret = DECISION_KEEP;
      /**
       * Currently, for the stage without synchronization
       * all_merged_data_buffer_, the workload is not known and hence
       * maximum degree of parallelism is used.
       */
      if (current_degree_of_parallelism == Config::max_degree_of_parallelism) {
        ret = DECISION_KEEP;
        break;
      } else if (current_degree_of_parallelism <
                 Config::max_degree_of_parallelism) {
        ret = DECISION_EXPAND;
        break;
      }
      ret = DECISION_SHRINK;
      break;
    }
    case LocalStage::from_buffer: {
      ret = DECISION_KEEP;
      LOG(INFO)
          << "Buffer usage: "
          << current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage()
          << " =====>N/A ";
      const double current_usage =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      if (current_stage.dataflow_src_.monitorable_buffer_->inputComplete()) {
        if (current_degree_of_parallelism == 0) {
          ret = DECISION_EXPAND;
          break;
        } else {
          ret = DECISION_KEEP;
          break;
        }
      }
      if (current_usage > THRESHOLD_FULL) {
        ret = DECISION_EXPAND;
        break;
      } else if (current_usage < THRESHOLD_EMPTY) {
        ret = DECISION_SHRINK;
        break;
      } else {
        ret = DECISION_KEEP;
        break;
      }
    }
    case LocalStage::to_buffer: {
      LOG(INFO)
          << "Buffer usage:  N/A=====> "
          << current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      const double current_usage =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      if (current_usage > THRESHOLD_FULL) {
        ret = DECISION_SHRINK;
        break;
      } else if (current_usage < THRESHOLD_EMPTY) {
        ret = DECISION_EXPAND;
        break;
      } else {
        ret = DECISION_KEEP;
        break;
      }
    }
    case LocalStage::buffer_to_buffer: {
      LOG(INFO)
          << "Buffer usage: "
          << current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage()
          << " =====> "
          << current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      const double bottom_usage =
          current_stage.dataflow_src_.monitorable_buffer_->getBufferUsage();
      const double top_usage =
          current_stage.dataflow_desc_.monitorable_buffer_->getBufferUsage();
      /* guarantee that there is at least one expanded thread when the input is
       * complete so that the stage can be finished soon.*/
      if (current_stage.dataflow_src_.monitorable_buffer_->inputComplete()) {
        if (current_degree_of_parallelism == 0) {
          ret = DECISION_EXPAND;
          break;
        } else {
          ret = DECISION_KEEP;
          break;
        }
      }

      if (bottom_usage > THRESHOLD_FULL && top_usage < THRESHOLD_EMPTY) {
        ret = DECISION_EXPAND;
        break;
      }
      if (top_usage > THRESHOLD_FULL || bottom_usage < THRESHOLD_EMPTY) {
        ret = DECISION_SHRINK;
        break;
      }
      ret = DECISION_KEEP;
    }
  }

  if (ret == DECISION_EXPAND) {
    return expandeIfNotExceedTheMaxDegreeOfParallelism(
        current_degree_of_parallelism);
  }
  if (ret == DECISION_SHRINK) {
    return shrinkIfNotExceedTheMinDegreeOfParallelims(
        current_degree_of_parallelism);
  }

  return ret;
}
void* ExpanderTracker::monitoringThread(void* arg) {
#ifdef OLD_TRACKER
  if (!Config::enable_expander_adaptivity) {
    return NULL;
  }
  ExpanderTracker* Pthis = (ExpanderTracker*)arg;
  int cur = 0;
  while (true) {
    usleep(Config::expander_adaptivity_check_frequency);
    Pthis->lock_.acquire();
    if (Pthis->expander_id_to_status_.size() <= cur) {
      cur = 0;
      Pthis->lock_.release();
      usleep(1000);
      continue;
    }
    //		Pthis->printStatus();
    auto it = Pthis->expander_id_to_status_.begin();
    for (int tmp = 0; tmp < cur; tmp++) it++;
    ExpanderID id = it->first;
    cur++;
    assert(!Pthis->expander_id_to_expander_.empty());
    LOG(INFO)
        << "Instance throughput: "
        << it->second->perf_info.report_instance_performance_in_millibytes()
        << " Mbytes";
    const unsigned int current_degree_of_parallelism =
        Pthis->expander_id_to_expander_[it->first]->GetDegreeOfParallelism();
    int decision = Pthis->DecideExpandingOrShrinking(
        it->second->current_stage, current_degree_of_parallelism, false);
    LOG(INFO)
        << "^^^ stage  "
        << it->second->current_stage.dataflow_src_.end_point_name_.c_str()
        << " ---->   "
        << it->second->current_stage.dataflow_desc_.end_point_name_.c_str()
        << "  parallelism= " << current_degree_of_parallelism;
    Pthis->lock_.release();
    Pthis->lock_adapt_.acquire();
    if (Pthis->expander_id_to_expander_.find(it->first) ==
        Pthis->expander_id_to_expander_.end()) {
      LOG(WARNING) << "expander_id= " << it->first
                   << " has been erased from expander_id_to_expander_, so "
                      "coundn't expand or shrink it!";
      Pthis->lock_adapt_.release();
      continue;
    }
    switch (decision) {
      case DECISION_EXPAND: {
        if (Pthis->expander_id_to_expander_[it->first]->Expand()) {
          LOG(INFO) << "=========Expanding======== "
                    << current_degree_of_parallelism << " --> "
                    << current_degree_of_parallelism + 1;
        } else {
          LOG(WARNING) << "=========Expanding======== Failed to expand!";
        }
        break;
      }
      case DECISION_SHRINK: {
        if (Pthis->expander_id_to_expander_[it->first]->Shrink()) {
          LOG(INFO) << "=========Shrinking======== "
                    << current_degree_of_parallelism << " --> "
                    << current_degree_of_parallelism - 1;
        } else {
          LOG(WARNING) << "=========Shrinking======== Failed to shrink!";
        }
        break;
      }
      default: {
        LOG(INFO) << "=========KEEP========";
        break;
      }
    }
    Pthis->lock_adapt_.release();
    //		Pthis->lock_.release();
  }
#else
  return NULL;
#endif
}

int ExpanderTracker::expandeIfNotExceedTheMaxDegreeOfParallelism(
    int current_degree_of_parallelism) const {
  if (current_degree_of_parallelism < Config::max_degree_of_parallelism) {
    return DECISION_EXPAND;
  } else {
    return DECISION_KEEP;
  }
}

int ExpanderTracker::shrinkIfNotExceedTheMinDegreeOfParallelims(
    int current_degree_of_parallelism) const {
  if (current_degree_of_parallelism > 0) {
    return DECISION_SHRINK;
  }
  return DECISION_KEEP;
}

void ExpanderTracker::printStatus() {
#ifdef OLD_TRACKER
  printf("Num. of Expanders: %d\n", expander_id_to_status_.size());
  printf("expanded_thread_id : ExpanderID\n");
  for (boost::unordered_map<ExpandedThreadId, ExpanderID>::iterator it =
           thread_id_to_expander_id_.begin();
       it != thread_id_to_expander_id_.end(); it++) {
    printf("(%llx,%ld) ", it->first, it->second);
  }
  printf("\n");
  printf("ExpanderID : ExpanderStatus*\n");
  for (std::unordered_map<ExpanderID, ExpanderStatus*>::iterator it =
           expander_id_to_status_.begin();
       it != expander_id_to_status_.end(); it++) {
    printf("(%ld,%llx) ", it->first, it->second);
  }
  printf("\n");

  printf("ExpanderID : ExpandabilitySrinkability*\n");
  for (boost::unordered_map<ExpanderID, ExpandabilityShrinkability*>::iterator
           it = expander_id_to_expander_.begin();
       it != expander_id_to_expander_.end(); it++) {
    printf("(%ld,%llx) ", it->first, it->second);
  }
  printf("\n");

  printf("expanded thread id: ExpandedThreadStatus\n");
  for (auto it = thread_id_to_status_.begin(); it != thread_id_to_status_.end();
       it++) {
    printf("(%ld, %llx)", it->first, &it->second);
  }
  printf("\n");
#endif
}

bool ExpanderTracker::trackExpander(ExpanderID id) {
#ifdef OLD_TRACKER
  lock_.acquire();
  if (expander_id_to_expander_.find(id) != expander_id_to_expander_.end()) {
    lock_.release();
    return true;
  }
  if (expander_id_to_status_.find(id) != expander_id_to_status_.end()) {
    lock_.release();
    return true;
  }
  lock_.release();
  return false;
#else
  return false;
#endif
}

JobExpanderTracker* ExpanderTracker::GetJobExpanderTracker(u_int16_t job_id) {
  lock_.acquire();
  auto it = job_id_to_job_epd_tracker_.find((u_int64_t)job_id);
  if (job_id_to_job_epd_tracker_.end() != it) {
    lock_.release();
    return it->second;
  }
  LOG(WARNING) << "couldn't find job expander tracker for job " << job_id;
  lock_.release();
  return NULL;
}
//}  // namespace claims
