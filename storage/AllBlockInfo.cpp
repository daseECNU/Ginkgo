/*
 * AllBlockInfo.cpp
 *
 *  Created on: 2013-10-26
 *      Author: casa
 */

#include "AllBlockInfo.h"

AllBlockInfo *AllBlockInfo::abi_ = 0;

AllBlockInfo::AllBlockInfo() {}

AllBlockInfo::~AllBlockInfo() {}

bool AllBlockInfo::put(string blockmanagerId, string blockId) {
  lock_.acquire();
  string block = blockmanagerId + blockId;
  vv_.push_back(block.c_str());
  lock_.release();
  return true;
}

// not used in my program . I need  consider if it is useful  -han
