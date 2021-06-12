#include "../../exec_tracker/segment_exec_status.h"

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
 * /Claims/sql_parser/test_/test_new_sql.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: fzh
 *		   Email: fzhedu@gmail.com
 *
 * Description:
 *
 */
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <iostream>  //NOLINT
#include <string>
#include <stdio.h>  //NOLINT
#include "../parser/parser.h"
#include "../ast_node/ast_node.h"
#include "../../logical_operator/logical_query_plan_root.h"
#include "../../physical_operator/physical_operator_base.h"
using ginkgo::logical_operator::LogicalQueryPlanRoot;
using ginkgo::physical_operator::PhysicalOperatorBase;
using ginkgo::SegmentExecStatus;
using std::endl;
using std::cout;

int TestNewSql() {
  int flag = 1;
  while (flag) {
    Parser* my_parser = new Parser();
    AstNode* raw_ast = my_parser->GetRawAST();
    if (raw_ast != NULL) {
#ifdef PRINTCONTEXT
      raw_ast->Print();
      cout << "--------------begin semantic analysis---------------" << endl;
#endif
      SemanticContext sem_cnxt;
      RetCode ret = raw_ast->SemanticAnalisys(&sem_cnxt);
      if (rSuccess != ret) {
        cout << "semantic analysis error result= : " << ret << endl;
        continue;
      }
#ifdef PRINTCONTEXT
      raw_ast->Print();
      cout << "--------------begin push down condition ------------" << endl;
#endif
      PushDownConditionContext pdccnxt;
      raw_ast->PushDownCondition(pdccnxt);
#ifdef PRINTCONTEXT
      raw_ast->Print();
      cout << "--------------begin logical plan -------------------" << endl;
#endif

      LogicalOperator* logic_plan = NULL;
      raw_ast->GetLogicalPlan(logic_plan);

      logic_plan =
          new LogicalQueryPlanRoot(0, logic_plan, my_parser->get_sql_stmt(),
                                   LogicalQueryPlanRoot::kResultCollector);
      logic_plan->GetPlanContext();
#ifdef PRINTCONTEXT
      logic_plan->Print();
      cout << "--------------begin physical plan -------------------" << endl;
#endif

      PhysicalOperatorBase* physical_plan =
          logic_plan->GetPhysicalPlan(64 * 1024);
#ifdef PRINTCONTEXT
      physical_plan->Print();
      cout << "--------------begin output result -------------------" << endl;
#endif
      SegmentExecStatus* exec_status = new SegmentExecStatus(make_pair(0, 0));
      physical_plan->Open(exec_status);
      while (physical_plan->Next(exec_status, NULL)) {
      }
      ResultSet* result_set = physical_plan->GetResultSet();
      physical_plan->Close(exec_status);

      result_set->print();

      delete logic_plan;
      delete physical_plan;
      delete result_set;

    } else {
      LOG(WARNING) << "the raw ast is null" << endl;
    }
    delete my_parser;
    printf("continue 1 or not 0!\n");
    scanf("%d", &flag);
  }
  return 0;
}
