/*
 * expr_node.cpp
 *  Created on: May 29, 2015 11:28:14 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#include "./expr_node.h"

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

#include "../../common/expression/expr_column.h"
#include "../../common/ids.h"
namespace claims {
namespace common {
ExprNode::ExprNode(ExprNodeType expr_node_type, data_type actual_type,
                   string alias)
    : expr_node_type_(expr_node_type),
      actual_type_(actual_type),
      alias_(alias),
      type_cast_func_(NULL),
      return_type_(actual_type),
      get_type_(actual_type),
      value_(NULL),
      value_size_(0),
      is_null_(false) {}
ExprNode::ExprNode(ExprNodeType expr_node_type, data_type actual_type,
                   data_type get_type, string alias)
    : expr_node_type_(expr_node_type),
      actual_type_(actual_type),
      alias_(alias),
      type_cast_func_(NULL),
      return_type_(actual_type),
      get_type_(get_type),
      value_(NULL),
      value_size_(0),
      is_null_(false) {}
ExprNode::ExprNode(ExprNode* expr)
    : expr_node_type_(expr->expr_node_type_),
      actual_type_(expr->actual_type_),
      return_type_(expr->return_type_),
      get_type_(expr->get_type_),
      alias_(expr->alias_),
      is_null_(expr->is_null_),
      value_size_(expr->value_size_),
      type_cast_func_(expr->type_cast_func_),
      value_(NULL) {}

bool ExprNode::MoreExprEvaluate(vector<ExprNode*> thread_condi,
                                ExprEvalCnxt& eecnxt) {
  for (int i = 0; i < thread_condi.size(); ++i) {
    bool result =
        *reinterpret_cast<bool*>(thread_condi[i]->ExprEvaluate(eecnxt));
    if (!result) return false;
  }
  return true;
}

bool ExprNode::IsEqualAttr(const Attribute& attr) {
  if (expr_node_type_ == t_qcolcumns) {
    ExprColumn* column = reinterpret_cast<ExprColumn*>(this);
    if (attr.attrName == column->column_name_ &&
        attr.attrType->type == column->actual_type_) {
      return true;
    }
  }
  return false;
}
Attribute ExprNode::ExprNodeToAttr(const int id, const unsigned table_id) {
  column_type* column = NULL;
  unsigned size=0;

  if (t_string == this->return_type_ || t_decimal == this->return_type_) {
    column = new column_type(this->return_type_, this->value_size_);
  } else {
    column = new column_type(this->return_type_);
  }
  // set TableID
  string attr_name = "NULL_MID." + alias_;
  if (t_qcolcumns == expr_node_type_) {
    ExprColumn* column = reinterpret_cast<ExprColumn*>(this);
    if (alias_ == column->column_name_ ||
        alias_ == column->table_name_ + "." + column->column_name_) {
      attr_name = column->table_name_ + "." + column->column_name_;
    }  // else is for the case it's aliased
  }
  // other data types convert to string,schema's attribute size changed
  switch (get_type_){
    case t_smallInt:
    	size=8;
    	break;
    case t_u_smallInt:
    	size=8;
    	break;
    case t_int:
    	size=16;
    	break;
    case t_u_long:
    	size=24;
    	break;
    case t_float:
    	size=48;
    	break;
    case t_double:
    	size=48;
    	break;
    case t_date:
    	size=16;
    	break;
    case t_time:
    	size=16;
    	break;
    case t_datetime:
    	size=24;
    	break;
    case t_decimal:
    	size=column->size;
    	break;
    case t_boolean:
    	size=4;
    	break;
    case t_string:
    	size=column->size;
  }
  if(return_type_ == t_string){
	  Attribute attr_alais(table_id, id, attr_name, t_string, size);
	  return attr_alais;
  }else{
	  Attribute attr_alais(table_id, id, attr_name, column->type, column->size);
	  return attr_alais;
  }



}
}  // namespace common
}  // namespace claims
