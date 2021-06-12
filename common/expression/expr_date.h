/*
 * expr_date.h
 *  Created on: May 30, 2015
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef COMMON_EXPRESSION_EXPR_DATE_H_
#define COMMON_EXPRESSION_EXPR_DATE_H_

#include "./expr_node.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "../../common/Schema/Schema.h"
#include "./expr_type_cast.h"
namespace ginkgo {
namespace common {
class ExprDate : public ExprNode {
 public:
  OperType oper_type_;
  ExprNode* arg0_;
  ExprNode* arg1_;
  data_type arg1_return_type_;
  DataTypeOperFunc DataTypeOperFunc_;
  ExprDate(ExprNodeType expr_node_type, data_type actual_type,
           data_type arg1_return_type, string alias, OperType oper_type,
           ExprNode* arg0, ExprNode* arg1);
  explicit ExprDate(ExprDate* expr_date);
  ExprDate() {}
  ~ExprDate() {
    delete arg0_;
    delete arg1_;
  }
  void* ExprEvaluate(ExprEvalCnxt& eecnxt);

  void InitExprAtLogicalPlan(LogicInitCnxt& licnxt);

  void InitExprAtPhysicalPlan();
  ExprNode* ExprCopy();

 private:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(const Archive& ar, const unsigned int version) {
    ar& boost::serialization::base_object<ExprNode>(*this) & oper_type_ &
        arg0_ & arg1_ & arg1_return_type_;
  }
};
}  // namespace common
}  // namespace ginkgo
#endif  // COMMON_EXPRESSION_EXPR_DATE_H_
