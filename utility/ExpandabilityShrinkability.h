/*
 * ExpandabilityShrinkability.h
 *
 *  Created on: Mar 27, 2014
 *      Author: wangli
 */

#ifndef EXPANDABILITYSHRINKABILITY_H_
#define EXPANDABILITYSHRINKABILITY_H_
#include "../common/error_define.h"

class ExpandabilityShrinkability {
 public:
  ExpandabilityShrinkability();
  virtual ~ExpandabilityShrinkability();
  virtual RetCode Expand() = 0;
  virtual RetCode Shrink() = 0;
  virtual unsigned GetDegreeOfParallelism() = 0;
};

#endif /* EXPANDABILITYSHRINKABILITY_H_ */
