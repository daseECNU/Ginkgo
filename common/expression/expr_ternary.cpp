/*
 * expr_ternary.cpp
 *  Created on: May 30, 2015
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#include "./expr_ternary.h"

#include <malloc.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

#include "./data_type_oper.h"
#include "./expr_type_cast.h"
namespace ginkgo {
namespace common {
ExprTernary::ExprTernary(ExprNodeType expr_node_type, data_type actual_type,
                         string alias, OperType oper_type, ExprNode* arg0,
                         ExprNode* arg1, ExprNode* arg2)
    : ExprNode(expr_node_type, actual_type, alias),
      oper_type_(oper_type),
      arg0_(arg0),
      arg1_(arg1),
      arg2_(arg2),
      data_type_oper_func_(NULL) {}
ExprTernary::ExprTernary(ExprTernary* expr)
    : ExprNode(expr),
      oper_type_(expr->oper_type_),
      data_type_oper_func_(expr->data_type_oper_func_),
      arg0_(expr->arg0_->ExprCopy()),
      arg1_(expr->arg1_->ExprCopy()),
      arg2_(expr->arg2_->ExprCopy()) {}

void* ExprTernary::ExprEvaluate(ExprEvalCnxt& eecnxt) {
  OperFuncInfoData oper_info;
  oper_info.args_[0] = arg0_->ExprEvaluate(eecnxt);
  oper_info.args_[1] = arg1_->ExprEvaluate(eecnxt);
  oper_info.args_[2] = arg2_->ExprEvaluate(eecnxt);
  oper_info.args_num_ = 3;
  oper_info.result_ = value_;
  data_type_oper_func_(&oper_info);
  return type_cast_func_(oper_info.result_, value_);
}

void ExprTernary::InitExprAtLogicalPlan(LogicInitCnxt& licnxt) {
  return_type_ = licnxt.return_type_;
  licnxt.return_type_ = arg0_->actual_type_;
  arg0_->InitExprAtLogicalPlan(licnxt);
  licnxt.return_type_ = arg1_->actual_type_;
  arg1_->InitExprAtLogicalPlan(licnxt);
  licnxt.return_type_ = arg2_->actual_type_;
  arg2_->InitExprAtLogicalPlan(licnxt);
  value_size_ = std::max(arg0_->value_size_,
                         std::max(arg1_->value_size_, arg2_->value_size_));
  is_null_ = (arg0_->is_null_ || arg1_->is_null_ || arg2_->is_null_);
}

void ExprTernary::InitExprAtPhysicalPlan() {
  arg0_->InitExprAtPhysicalPlan();
  arg1_->InitExprAtPhysicalPlan();
  arg2_->InitExprAtPhysicalPlan();
  data_type_oper_func_ =
      DataTypeOper::data_type_oper_func_[actual_type_][oper_type_];
  type_cast_func_ = ExprTypeCast::type_cast_func_[actual_type_][return_type_];
  value_ = memalign(cacheline_size, value_size_);
}

ExprNode* ExprTernary::ExprCopy() { return new ExprTernary(this); }

void ExprTernary::GetUniqueAttr(set<string>& attrs) {
  arg0_->GetUniqueAttr(attrs);
  arg1_->GetUniqueAttr(attrs);
  arg2_->GetUniqueAttr(attrs);
}

}  // namespace common
}  // namespace ginkgo
