/*
 * RegisterDerivedClass.cpp
 *
 *  Created on: Aug 7, 2013
 *      Author: wangli
 * NOTE: every class registered should have empty constructor function
 */
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>

#include "../../common/expression/expr_binary.h"
#include "../../common/expression/expr_column.h"
#include "../../common/expression/expr_const.h"
#include "../../common/expression/expr_node.h"
#include "../../common/expression/expr_in.h"
#include "../../common/expression/expr_case_when.h"
#include "../../common/expression/expr_ternary.h"
#include "../../common/expression/expr_date.h"
#include "../../common/expression/expr_unary.h"
#include "../../IndexManager/CSBIndexBuilding.h"
#include "../../IndexManager/IndexScanIterator.h"
#include "../../common/Expression/qnode.h"
#include "../../physical_operator/combine_tuple.h"
#include "../../physical_operator/exchange_merger.h"
#include "../../physical_operator/exchange_sender_materialized.h"
#include "../../physical_operator/exchange_sender_pipeline.h"
#include "../../physical_operator/expander.h"
#include "../../physical_operator/in_operator.h"
#include "../../physical_operator/performance_monitor.h"
#include "../../physical_operator/physical_aggregation.h"
#include "../../physical_operator/physical_filter.h"
#include "../../physical_operator/physical_hash_join.h"
#include "../../physical_operator/physical_limit.h"
#include "../../physical_operator/physical_nest_loop_join.h"
#include "../../physical_operator/physical_project.h"
#include "../../physical_operator/physical_projection_scan.h"
#include "../../physical_operator/result_printer.h"
#include "../../physical_operator/physical_operator.h"
#include "../../physical_operator/physical_sort.h"
#include "../../physical_operator/physical_delete_filter.h"
#include "../../physical_operator/physical_outer_hash_join.h"
using ginkgo::common::ExprBinary;
using ginkgo::common::ExprCaseWhen;
using ginkgo::common::ExprColumn;
using ginkgo::common::ExprConst;
using ginkgo::common::ExprDate;
using ginkgo::common::ExprIn;
using ginkgo::common::ExprNode;
using ginkgo::common::ExprTernary;
using ginkgo::common::ExprUnary;
using ginkgo::physical_operator::CombineTuple;
using ginkgo::physical_operator::ExchangeMerger;
using ginkgo::physical_operator::ExchangeSenderMaterialized;
using ginkgo::physical_operator::ExchangeSenderPipeline;
using ginkgo::physical_operator::Expander;
using ginkgo::physical_operator::InOperator;
using ginkgo::physical_operator::PerformanceMonitor;
using ginkgo::physical_operator::PhysicalAggregation;
using ginkgo::physical_operator::PhysicalFilter;
using ginkgo::physical_operator::PhysicalHashJoin;
using ginkgo::physical_operator::PhysicalLimit;
using ginkgo::physical_operator::PhysicalNestLoopJoin;
using ginkgo::physical_operator::PhysicalOperator;
using ginkgo::physical_operator::PhysicalProject;
using ginkgo::physical_operator::PhysicalProjectionScan;
using ginkgo::physical_operator::ResultPrinter;
using ginkgo::physical_operator::PhysicalSort;
using ginkgo::physical_operator::PhysicalDeleteFilter;
using ginkgo::physical_operator::PhysicalOuterHashJoin;

#pragma auto_inline
template <class Archive>
void Register_Block_Stream_Iterator(Archive& ar) {
  ar.register_type(static_cast<Expander*>(NULL));
  ar.register_type(static_cast<ExchangeMerger*>(NULL));
  ar.register_type(static_cast<ExchangeSenderPipeline*>(NULL));
  ar.register_type(static_cast<PhysicalFilter*>(NULL));
  ar.register_type(static_cast<CombineTuple*>(NULL));
  ar.register_type(static_cast<PhysicalOuterHashJoin*>(NULL));
  ar.register_type(static_cast<PhysicalHashJoin*>(NULL));
  ar.register_type(static_cast<ExchangeSenderMaterialized*>(NULL));
  ar.register_type(static_cast<PhysicalProjectionScan*>(NULL));
  ar.register_type(static_cast<PerformanceMonitor*>(NULL));
  ar.register_type(static_cast<ResultPrinter*>(NULL));
  ar.register_type(static_cast<PhysicalAggregation*>(NULL));
  ar.register_type(static_cast<PhysicalNestLoopJoin*>(NULL));
  ar.register_type(static_cast<PhysicalSort*>(NULL));
  ar.register_type(static_cast<PhysicalLimit*>(NULL));
  ar.register_type(static_cast<PhysicalProject*>(NULL));
  ar.register_type(static_cast<PhysicalOperator*>(NULL));
  ar.register_type(static_cast<PhysicalDeleteFilter*>(NULL));
  ar.register_type(static_cast<InOperator*>(NULL));
  ar.register_type(static_cast<bottomLayerCollecting*>(NULL));
  ar.register_type(static_cast<bottomLayerSorting*>(NULL));
  ar.register_type(static_cast<IndexScanIterator*>(NULL));
  ar.register_type(static_cast<QNode*>(NULL));
  ar.register_type(static_cast<QExpr_binary*>(NULL));
  ar.register_type(static_cast<QColcumns*>(NULL));
  ar.register_type(static_cast<QExpr*>(NULL));
  ar.register_type(static_cast<QExpr_unary*>(NULL));
  ar.register_type(static_cast<QExpr_ternary*>(NULL));
  ar.register_type(static_cast<QExpr_case_when*>(NULL));
  ar.register_type(static_cast<QExpr_in*>(NULL));
  ar.register_type(static_cast<QExpr_date_add_sub*>(NULL));

  ar.register_type(static_cast<ExprNode*>(NULL));
  ar.register_type(static_cast<ExprBinary*>(NULL));
  ar.register_type(static_cast<ExprConst*>(NULL));
  ar.register_type(static_cast<ExprColumn*>(NULL));
  ar.register_type(static_cast<ExprTernary*>(NULL));
  ar.register_type(static_cast<ExprIn*>(NULL));
  ar.register_type(static_cast<ExprDate*>(NULL));
  ar.register_type(static_cast<ExprUnary*>(NULL));
  ar.register_type(static_cast<ExprCaseWhen*>(NULL));
}
void cheat_the_compiler() {
  char buffer[4096 * 2 - sizeof(unsigned)];
  boost::iostreams::basic_array_sink<char> sr(buffer, sizeof(buffer));
  boost::iostreams::stream<boost::iostreams::basic_array_sink<char> > ostr(sr);

  boost::archive::binary_oarchive oa(ostr);
  boost::archive::text_oarchive toa(ostr);
  Register_Block_Stream_Iterator<boost::archive::binary_oarchive>(oa);
  Register_Block_Stream_Iterator<boost::archive::text_oarchive>(toa);
  char a[2];
  boost::iostreams::basic_array_source<char> device(a);
  boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s(
      device);
  boost::archive::binary_iarchive ia(s);
  boost::archive::text_iarchive tia(s);

  Register_Block_Stream_Iterator<boost::archive::binary_iarchive>(ia);
  Register_Block_Stream_Iterator<boost::archive::text_iarchive>(tia);
}
