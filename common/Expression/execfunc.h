/*
 * execfunc.h
 *
 *  Created on: Aug 6, 2014
 *      Author: imdb
 */

#ifndef EXECFUNC_H_
#define EXECFUNC_H_

#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../../catalog/attribute.h"
#include "../../common/Schema/Schema.h"
#include "qnode.h"
using namespace std;
bool ExecEvalQual(vector<QNode *> v_qual, void *tuple, Schema *schema);
void *Exec_cal(Node *cinfo, void *tuple, Schema *schema);
void *Exec_cmp(Node *cinfo, void *tuple, Schema *schema);
void *getConst(Node *cinfo, void *tuple, Schema *schema);
void *getcol(Node *cinfo, void *tuple, Schema *schema);
void *Exec_unary(Node *cinfo, void *tuple, Schema *schema);
void *Exec_ternary(Node *cinfo, void *tuple, Schema *schema);
void *Exec_case_when(Node *cinfo, void *tuple, Schema *schema);
void *Exec_in(Node *cinfo, void *tuple, Schema *schema);
void *Exec_date_add_sub(Node *cinfo, void *tuple, Schema *schema);
void Expr_copy(QNode *node, QNode *&new_node);
#endif /* EXECFUNC_H_ */
