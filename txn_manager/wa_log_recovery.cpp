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
 * /CLAIMS/txn_manager/recovery.cpp
 *
 *  Created on: 2017年2月25日
 *      Author: imdb
 *		   Email:
 *
 * Description:
 *
 */
#include <memory>
#include "../txn_manager/wa_log_recovery.h"
#include "../txn_manager/wa_log_server.h"
using std::dynamic_pointer_cast;
namespace ginkgo {
namespace txn {

shared_ptr<TxnState> LogRecovery::GetTxnState(
    const unordered_set<UInt64> &part_list) {
  shared_ptr<TxnState> txn_state = make_shared<TxnState>();
  auto log_stream = LogServer::GetCmdLogStream();
  auto du_stream = log_stream->GetDurableStream();
  auto iterator = du_stream->GenIterator(DurableStream::Iterator::ForwardMode);
  shared_ptr<BeginLog> begin_log;
  shared_ptr<WriteLog> write_log;
  shared_ptr<CommitLog> commit_log;
  shared_ptr<AbortLog> abort_log;
  shared_ptr<CheckpointLog> cp_log;
  shared_ptr<WALog> log;
  while ((log = iterator->NextLog()) != nullptr) {
    if (dynamic_pointer_cast<CommandLog>(log)->GetTs() > txn_state->max_ts_)
      txn_state->max_ts_ = dynamic_pointer_cast<CommandLog>(log)->GetTs();
    switch (log->GetType()) {
      case kBegin:
        begin_log = dynamic_pointer_cast<BeginLog>(log);
        // cout << "scan begin " << begin_log->GetTs() << endl;
        assert(txn_state->Begin(begin_log->GetTs()) == rSuccess);
        break;
      case kWrite:
        write_log = dynamic_pointer_cast<WriteLog>(log);
        // cout << "scan write " << write_log->GetTs() << endl;
        if (part_list.find(write_log->GetPart()) == part_list.end()) continue;
        assert(txn_state->Write(write_log->GetTs(), write_log->GetPart(),
                                write_log->GetPos(),
                                write_log->GetOffset()) == rSuccess);
        break;
      case kCommit:
        commit_log = dynamic_pointer_cast<CommitLog>(log);
        // cout << "scan commit " << commit_log->GetTs() << endl;
        assert(txn_state->Commit(commit_log->GetTs()) == rSuccess);
        break;
      case kAbort:
        abort_log = dynamic_pointer_cast<AbortLog>(log);
        // cout << "scan abort " << abort_log->GetTs() << endl;
        assert(txn_state->Abort(abort_log->GetTs()) == rSuccess);
        break;
      case kCheckpoint:
        cp_log = dynamic_pointer_cast<CheckpointLog>(log);
        if (part_list.find(cp_log->GetPart()) == part_list.end()) continue;
        assert(txn_state->Checkpoint(cp_log->GetPart(), cp_log->GetHisCP(),
                                     cp_log->GetRtCP()) == rSuccess);
        break;
      default:
        assert(false);
    }
  }
  txn_state->InitPosList();
  return txn_state;
}
}  // namespace txn
}  // namespace ginkgo
