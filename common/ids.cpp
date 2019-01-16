/*
 * ids.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: wangli
 */

#include "ids.h"
#include "../Config.h"
#include "string.h"
std::string PartitionID::getPathAndName() const {
  std::ostringstream str;
  std::string str1;
  if (node_id == -1) {
    str << Config::data_dir << "T" << projection_id.table_id << "G"
        << projection_id.projection_off << "P" << partition_off;
  } else {
    str << Config::data_dir << "T" << projection_id.table_id << "G"
        << projection_id.projection_off << "P" << partition_off << "N"
        << node_id;
  }
  str1 = str.str();
  str.clear();
  return str1;
}
