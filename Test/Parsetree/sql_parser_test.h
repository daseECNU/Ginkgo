/*
 * sql_parser_test.h
 *
 *  Created on: Jul 7, 2014
 *      Author: wangli
 */

#ifndef SQL_PARSER_TEST_H_
#define SQL_PARSER_TEST_H_
#include "../set_up_environment.h"
#include <stdio.h>

#include "../../logical_operator/logical_operator.h"
#include "../../logical_operator/logical_query_plan_root.h"
#include "../../physical_operator/physical_operator_base.h"

using ginkgo::logical_operator::LogicalOperator;
using ginkgo::logical_operator::LogicalQueryPlanRoot;

char sql[1000];
int sql_parser_test() {
  startup_single_node_environment_of_poc();

  while (true) {
    printf("sql:\n");
    fflush(stdout);
    fgets(sql, 1000, stdin);
    LogicalOperator* logical_tree = convert_sql_to_logical_operator_tree(sql);
    if (logical_tree != 0) {
      LogicalOperator* root = new LogicalQueryPlanRoot(
          0, logical_tree, LogicalQueryPlanRoot::kPrint);
      PhysicalOperatorBase* physical_plan = root->GetPhysicalPlan(64 * 1024);
      physical_plan->Open(0);
      physical_plan->Next(0);
      physical_plan->Close();
    }
  }
}

#endif /* SQL_PARSER_TEST_H_ */
