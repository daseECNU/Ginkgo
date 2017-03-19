/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * physical_operator/expander.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: wangli, fangzhuhe
 *       Email: fzhedu@gmail.com
 *
 * Description:
 */
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <set>
#include <iostream>
#include "../common/Logging.h"
#include "../physical_operator/expander.h"
#include "../Executor/expander_tracker.h"
namespace claims {
namespace physical_operator {
struct ExpanderContext {
  Expander* pthis_;
  semaphore sem_;
};

Expander::Expander(State state)
    : state_(state),
      block_stream_buffer_(NULL),
      finished_thread_count_(0),
      thread_count_(0),
      is_registered_(false) {
  set_phy_oper_type(kphysicalExpander);
}

Expander::Expander()
    : block_stream_buffer_(NULL),
      finished_thread_count_(0),
      thread_count_(0),
      is_registered_(false) {
  set_phy_oper_type(kphysicalExpander);
}

Expander::~Expander() {
  DELETE_PTR(state_.child_);
  DELETE_PTR(state_.schema_);
}

Expander::State::State(Schema* schema, PhysicalOperatorBase* child,
                       unsigned thread_count, unsigned block_size,
                       unsigned block_count_in_buffer)
    : schema_(schema),
      child_(child),
      init_thread_count_(thread_count),
      block_size_(block_size),
      block_count_in_buffer_(block_count_in_buffer) {}
/**
 * @param partitoin_offset means to solve corresponding partition
 * every Expander should register to ExpanderTracker
 */
bool Expander::Open(SegmentExecStatus* const exec_status,
                    const PartitionOffset& partitoin_offset) {
  received_tuples_ = 0;
  state_.partition_offset_ = partitoin_offset;
  input_data_complete_ = false;
  one_thread_finished_ = false;
  finished_thread_count_ = 0;
  block_stream_buffer_ = new BlockStreamBuffer(
      state_.block_size_, state_.block_count_in_buffer_ * 10, state_.schema_);

  in_work_expanded_thread_list_.clear();
  RETURN_IF_CANCELLED(exec_status);

  expander_id_ = exec_status->GetSegmentID();
  ExpanderTracker::getInstance()->RegisterExpander(
      block_stream_buffer_, this, expander_id_, exec_status->is_pivot_);
  is_registered_ = true;
  LOG(INFO) << expander_id_.first << " , " << expander_id_.second
            << "Expander open, thread count= " << state_.init_thread_count_;
  exec_status_ = exec_status;

  // for extra job, init_thread_count_=1
  if (!exec_status->is_pivot_) {
    state_.init_thread_count_ = 1;
  }
  for (unsigned i = 0; i < state_.init_thread_count_;) {
    RETURN_IF_CANCELLED(exec_status);

    if (CreateWorkingThread() == false) {
      LOG(WARNING)
          << "expander_id_ = " << expander_id_.first << " , "
          << expander_id_.second
          << " Failed to create initial expanded thread and will try again"
          << std::endl;
      usleep(1);
    } else {
      ++i;
    }
  }
  return true;
}
/**
 * fetch one block from buffer and return, until it is exhausted.
 */
bool Expander::Next(SegmentExecStatus* const exec_status,
                    BlockStreamBase* block) {
  RETURN_IF_CANCELLED(exec_status);

  while (!block_stream_buffer_->getBlock(*block)) {
    RETURN_IF_CANCELLED(exec_status);

    if (ChildExhausted()) {
      return false;
    } else {
      usleep(1);
    }
  }
  return true;
}

bool Expander::Close(SegmentExecStatus* const exec_status) {
  // for making sure every thread have exited from next()
  if (true == g_thread_pool_used) {
    while (!in_work_expanded_thread_list_.empty() ||
           !being_called_bacl_expanded_thread_list_.empty()) {
      LOG(WARNING) << "there are thread working now when expander close(), so "
                      "waiting!!!";
      usleep(30);
    }
  } else {
    for (std::set<pthread_t>::iterator it =
             in_work_expanded_thread_list_.begin();
         it != in_work_expanded_thread_list_.end(); it++) {
      void* res;
      pthread_join(*it, &res);
      assert(res == 0);
      LOG(WARNING) << "expander_id_ = " << expander_id_.first << " , "
                   << expander_id_.second
                   << " A expander thread is killed before close!" << std::endl;
    }
  }
  if (!exec_status->is_cancelled()) {
    LOG(INFO) << "Expander: "
              << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second << " received "
              << block_stream_buffer_->getReceivedDataSizeInKbytes()
              << " kByte " << received_tuples_ << " tuples!" << std::endl;
  }
  if (is_registered_) {
    ExpanderTracker::getInstance()->UnregisterExpander(expander_id_);
    is_registered_ = false;
  }
  if (!exec_status->is_cancelled()) {
    assert(input_data_complete_);
    input_data_complete_ = false;
    one_thread_finished_ = false;
    assert(in_work_expanded_thread_list_.empty());
    assert(being_called_bacl_expanded_thread_list_.empty());
    finished_thread_count_ = 0;
  }
  /*
   * check if all the information in ExpanderTrack has properly removed
   */
  if (!exec_status->is_cancelled()) {
    assert(!ExpanderTracker::getInstance()->trackExpander(expander_id_));
  }
  if (NULL != block_stream_buffer_) {
    delete block_stream_buffer_;
    block_stream_buffer_ = NULL;
  }
  LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
            << expander_id_.second << " Buffer is freed in Expander!"
            << std::endl;
  state_.child_->Close(exec_status);
  thread_count_ = 0;
  LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
            << expander_id_.second << "<<<<<<<Expander closed!>>>>>>>>>>"
            << std::endl;
  return true;
}
void Expander::Print() {
  std::cout << "-----------------Expander-----------------------" << std::endl;
  printf("Expander: thread num:%d\n", state_.init_thread_count_);
  state_.child_->Print();
}
/**
 * one expander may have many threads, so ExpanderTracker should track each
 * thread's status. call open() and next() of child to start the woke flow,
 * because the close() should called once, so can ignore to call it here. If the
 * work flow is exhausted, the delete some context and return
 */
void* Expander::ExpandedWork(void* arg) {
  Expander* Pthis = (reinterpret_cast<ExpanderContext*>(arg))->pthis_;
  const pthread_t pid = pthread_self();
  LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
            << Pthis->expander_id_.second << " thread " << pid
            << " is created!  BlockStreamExpander address is  " << Pthis
            << std::endl;

  bool expanding = true;
  unsigned block_count = 0;

  Pthis->AddIntoWorkingThreadList(pid);
  ExpanderTracker::getInstance()->RegisterExpandedThreadStatus(
      pid, Pthis->expander_id_);

  (reinterpret_cast<ExpanderContext*>(arg))->sem_.post();
  if (Pthis->ChildExhausted()) {
    ExpanderTracker::getInstance()->DeleteExpandedThreadStatus(pthread_self());
    return NULL;
  }

  LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
            << Pthis->expander_id_.second << ", pid= " << pid
            << " begins to open child!" << std::endl;
  //  ticks start_open = curtick();

  Pthis->state_.child_->Open(Pthis->exec_status_,
                             Pthis->state_.partition_offset_);

  LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
            << Pthis->expander_id_.second << ", pid= " << pid
            << " finished opening child" << std::endl;

  if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(pid)) {
    LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
              << Pthis->expander_id_.second
              << " <<<<<<<<<<<<<<<<Expander detected "
                 "call back signal after open!>>>>>>>" << pthread_self()
              << std::endl;

    //    Pthis->RemoveFromCalledBackThreadList(pid);
    //    Pthis->tid_to_shrink_semaphore_[pid]->post();
  } else {
    if (expanding == true) {
      expanding = false;
    }
    BlockStreamBase* block_for_asking = BlockStreamBase::createBlock(
        Pthis->state_.schema_, Pthis->state_.block_size_);
    block_for_asking->setEmpty();

    while (Pthis->state_.child_->Next(Pthis->exec_status_, block_for_asking)) {
      if (!block_for_asking->Empty()) {
        Pthis->lock_.acquire();
        Pthis->received_tuples_ += block_for_asking->getTuplesInBlock();
        Pthis->lock_.release();
        Pthis->block_stream_buffer_->insertBlock(block_for_asking);
        block_for_asking->setEmpty();
        block_count++;
      }
    }
    /*
     * When the above loop exits, it means that either the stage beginner has
     * exhausted, or it received termination request.
     */
    if (NULL != block_for_asking) {
      delete block_for_asking;
      block_for_asking = NULL;
    }
    if (ExpanderTracker::getInstance()->isExpandedThreadCallBack(
            pthread_self())) {
      LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
                << Pthis->expander_id_.second
                << " <<<<<<<<<<<<<<<<Expander detected "
                   "call back signal after open!>>>>>>>" << pthread_self()
                << std::endl;
      Pthis->lock_.acquire();
      Pthis->input_data_complete_ = false;
      Pthis->lock_.release();
      //      Pthis->RemoveFromCalledBackThreadList(pthread_self());
      //      LOG(INFO) << pthread_self() << " Produced " << block_count
      //                << " block before called-back" << std::endl;
      //      Pthis->tid_to_shrink_semaphore_[pid]->post();
    } else {  // always there are thread that hasn't been callback
      LOG(INFO) << pthread_self() << " Produced " << block_count
                << " block before finished" << std::endl;

      Pthis->lock_.acquire();
      Pthis->finished_thread_count_++;
      Pthis->input_data_complete_ = true;

      /**
       * The finish of one expanded thread does not always mean the complete of
       *input data.
       *
       */
      if (NULL != Pthis->block_stream_buffer_)
        Pthis->block_stream_buffer_->setInputComplete();
      LOG(INFO) << pthread_self() << " Produced " << block_count << "blocks"
                << std::endl;
      Pthis->lock_.release();

      //      if (!Pthis->RemoveFromWorkingThreadList(pthread_self())) {
      //        /* current thread has been called back*/
      //        Pthis->RemoveFromCalledBackThreadList(pthread_self());
      //        Pthis->tid_to_shrink_semaphore_[pid]->post();
      //      }
    }
  }

  /* delete its stauts from expander tracker before exit*/
  ExpanderTracker::getInstance()->DeleteExpandedThreadStatus(pthread_self());
  if (!Pthis->RemoveFromWorkingThreadList(pthread_self())) {
    /* current thread has been called back*/
    Pthis->RemoveFromCalledBackThreadList(pthread_self());
    Pthis->tid_to_shrink_semaphore_[pid]->post();
  }
  LOG(INFO) << "expander_id_ = " << Pthis->expander_id_.first << " , "
            << Pthis->expander_id_.second << ", pid= " << pid
            << " expande thread finished!" << std::endl;
  return NULL;
}

/**
 * first acquire the exclusive lock to prevent creating expanded thread,
 * Otherwise, newly created thread may not be detected by ChildExhausted().
 * but what's coordinate_pid_?(fzh)
 */
bool Expander::ChildExhausted() {
  exclusive_expanding_.acquire();
  lock_.acquire();
  bool ret = input_data_complete_ == true &&
             in_work_expanded_thread_list_.empty() &&
             being_called_bacl_expanded_thread_list_.empty() &&
             this->block_stream_buffer_->Empty();
  lock_.release();
  exclusive_expanding_.release();
  //  if (ret == true && coordinate_pid_ != 0) {
  //    void* res;
  //    pthread_join(coordinate_pid_, &res);
  //    coordinate_pid_ = 0;
  //    return ChildExhausted();
  //  }
  if (ret) {
    LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second << " child iterator is exhausted!"
              << std::endl;
  }
  return ret;
}
/**
 * use thread-pool or pthread_create to create new working thread, the
 * thread-pool way can avoid the cost to create and destroy one new thread
 */
bool Expander::CreateWorkingThread() {
  pthread_t tid = 0;
  if (exec_status_->is_cancelled()) {
    // return false; // for debug
    return -1;
  }
  ExpanderContext para;
  para.pthis_ = this;
  LOG(INFO) << "create thread try to get exclusive_expanding lock";
  if (exclusive_expanding_.try_acquire()) {
    if (true == g_thread_pool_used) {
      Environment::getInstance()->getThreadPool()->AddTask(ExpandedWork, &para);
    } else {
      const int error = pthread_create(&tid, NULL, ExpandedWork, &para);
      if (error != 0) {
        LOG(ERROR) << "cannot create thread!!!!!!!!!!!!!!!" << std::endl;
        return false;
      }
    }
    LOG(INFO) << "create thread get lock and create thread successfully";
    para.sem_.wait();
    exclusive_expanding_.release();
    if (true == g_thread_pool_used) {
    } else {
      LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
                << expander_id_.second << " New expanded thread " << tid
                << " created!" << std::endl;
    }
    LOG(INFO) << "expand on thread successfully";
    lock_.acquire();
    thread_count_++;
    lock_.release();
    return true;
  } else {
    LOG(WARNING) << "Fails to obtain the exclusive lock to expanding!"
                 << std::endl;
    return false;
  }
}
/**
 * in order to guarantee terminating one working thread fast and correctly, just
 * set the status of corresponding call_backed, then try wait(), waiting
 * somewhere at some PhysicalOperator can exit safely and set post()
 */
RetCode Expander::TerminateWorkingThread(const pthread_t thread_id) {
  if (!ExpanderTracker::getInstance()->isExpandedThreadCallBack(thread_id)) {
    semaphore sem;
    tid_to_shrink_semaphore_[thread_id] = &sem;
    RemoveFromWorkingThreadList(thread_id);

    AddIntoCalledBackThreadList(thread_id);
    ExpanderTracker::getInstance()->SetThreadStatusCallback(thread_id);
    tid_to_shrink_semaphore_[thread_id]
        ->wait();  // note waiting post() somewhere
    lock_.acquire();
    tid_to_shrink_semaphore_.erase(thread_id);
    lock_.release();

    lock_.acquire();
    thread_count_--;
    lock_.release();
    LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second
              << " A thread is called back !******** working_thread_count= "
              << this->in_work_expanded_thread_list_.size()
              << " being_called_back_thread_count: "
              << this->being_called_bacl_expanded_thread_list_.size()
              << std::endl;
    return true;
  } else {
    LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second
              << " This thread has already been called back!" << std::endl;
    return false;
  }
}
void Expander::AddIntoWorkingThreadList(pthread_t pid) {
  lock_.acquire();
  in_work_expanded_thread_list_.insert(pid);
  LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
            << expander_id_.second << " pid = " << pid
            << " is added into in working list, whose address is "
            << &in_work_expanded_thread_list_ << std::endl;
  assert(in_work_expanded_thread_list_.find(pid) !=
         in_work_expanded_thread_list_.end());
  lock_.release();
}
bool Expander::RemoveFromWorkingThreadList(pthread_t pid) {
  lock_.acquire();
  if (in_work_expanded_thread_list_.find(pid) !=
      in_work_expanded_thread_list_.end()) {
    in_work_expanded_thread_list_.erase(pid);
    LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second << " pid = " << pid
              << " is removed from in working list!" << std::endl;
    lock_.release();
    return true;
  } else {
    LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
              << expander_id_.second << " pid = " << pid
              << " has already been removed from in working list!" << std::endl;
    lock_.release();
    return false;
  }
}
void Expander::AddIntoCalledBackThreadList(pthread_t pid) {
  lock_.acquire();
  being_called_bacl_expanded_thread_list_.insert(pid);
  LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
            << expander_id_.second << " pid = " << pid
            << " is added into being called back list!" << std::endl;
  lock_.release();
}
// there should add some code to check that the pid exist in the list?
void Expander::RemoveFromCalledBackThreadList(pthread_t pid) {
  lock_.acquire();
  being_called_bacl_expanded_thread_list_.erase(pid);
  LOG(INFO) << "expander_id_ = " << expander_id_.first << " , "
            << expander_id_.second << " pid = " << pid
            << " is removed from being called back list!" << std::endl;
  lock_.release();
}
unsigned Expander::GetDegreeOfParallelism() {
  unsigned ret;
  lock_.acquire();
  ret = in_work_expanded_thread_list_.size();
  lock_.release();
  return ret;
}

unsigned Expander::GetCallBackNum() {
  unsigned ret;
  lock_.acquire();
  ret = being_called_bacl_expanded_thread_list_.size();
  lock_.release();
  return ret;
}
RetCode Expander::Expand() {
  if (input_data_complete_) {
    /*
     * Expander does not expand when at least one expanded thread has completely
     * processed the input data flow. Otherwise the newly created expanded
     * thread might not be able to work properly if the expander's close is
     * called before its creation.
     */
    return -1;
  }
  return CreateWorkingThread();
}

RetCode Expander::Shrink() {
  ticks start = curtick();
  lock_.acquire();
  if (in_work_expanded_thread_list_.empty()) {
    lock_.release();
    return 2;
  } else {
    pthread_t cencel_thread_id = *in_work_expanded_thread_list_.begin();
    lock_.release();
    return this->TerminateWorkingThread(cencel_thread_id);
  }
}
RetCode Expander::GetAllSegments(stack<Segment*>* all_segments) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_) {
    return state_.child_->GetAllSegments(all_segments);
  }
  return ret;
}
RetCode Expander::GetJobDAG(JobContext* const job_cnxt) {
  RetCode ret = rSuccess;
  if (NULL != state_.child_) {
    return state_.child_->GetJobDAG(job_cnxt);
  } else {
    LOG(ERROR) << "the child of expander is NULL";
    ret = rFailure;
  }
  return ret;
}
}  // namespace physical_operator
}  // namespace claims
