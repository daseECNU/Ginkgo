/*
 * IDsGenerator.h
 *
 *  Created on: Nov 13, 2013
 *      Author: wangli
 */

#ifndef IDSGENERATOR_H_
#define IDSGENERATOR_H_

#include <sys/types.h>
#include "common/ids.h"
#include "utility/lock.h"

class IDsGenerator {
 public:
  static IDsGenerator* getInstance();
  virtual ~IDsGenerator();
  u_int64_t generateUniqueExchangeID();
  u_int64_t getUniqueExpanderID();

 private:
  IDsGenerator();
  u_int64_t exchange_id_cursor_;
  u_int64_t expander_id_cursor_;
  Lock lock_;
  static IDsGenerator* instance_;
};

#endif /* IDSGENERATOR_H_ */
