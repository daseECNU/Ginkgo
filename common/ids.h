/*
 * ids.h
 *	Suggested by Liyongfeng and Zhanglei, all the ids are defined in
 *	this file or better code organization purposes.
 *  Created on: Nov 8, 2013
 *      Author: wangli
 */

#ifndef IDS_H_
#define IDS_H_
#include <boost/unordered_map.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
#include <string>
#ifdef DMALLOC
#include "dmalloc.h"
#endif

#define INTERMEIDATE_TABLEID 100000;

typedef int NodeID;

typedef unsigned TableID;
typedef unsigned AttributeOffset;
typedef int ProjectionOffset;
typedef unsigned ColumnOffset;
typedef unsigned PartitionOffset;
typedef int ChunkOffset;
typedef unsigned long ExpanderID;
/*the following ids are based on the assumption that the TableOffset is globally
 * unique.*/

struct NodeAddress {
  NodeAddress(){};
  NodeAddress(std::string ip, std::string port) : ip(ip), port(port){};
  bool operator==(const NodeAddress& r) const {
    return this->ip == r.ip && this->port == r.port;
  }
  std::string ip;
  std::string port;
};
/* for boost::unordered_map*/
static size_t hash_value(const NodeAddress& node_addr) {
  size_t seed = 0;
  boost::hash_combine(seed, boost::hash_value(node_addr.ip));
  boost::hash_combine(seed, boost::hash_value(node_addr.port));
  return seed;
}

/**
 * AttributeID: an attribute in a table has an unique AttributeID*/
struct AttributeID {
  AttributeID(TableID tid, AttributeOffset off) : table_id(tid), offset(off){};
  AttributeID(){};
  TableID table_id;
  AttributeOffset offset;
  bool operator==(const AttributeID& r) const {
    return table_id == r.table_id && offset == r.offset;
  }
};
/* for boost::unordered_map*/
static size_t hash_value(const AttributeID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, boost::hash_value(key.offset));
  boost::hash_combine(seed, boost::hash_value(key.table_id));
  return seed;
}

/**
 * ProjectionID: a projection has an unique ProjectionID
 */
struct ProjectionID {
  ProjectionID(){};
  ProjectionID(TableID tid, ProjectionOffset off)
      : table_id(tid), projection_off(off){};
  ProjectionID(const ProjectionID& r)
      : table_id(r.table_id), projection_off(r.projection_off){};
  TableID table_id;
  ProjectionOffset projection_off;
  bool operator==(const ProjectionID& r) const {
    return table_id == r.table_id && projection_off == r.projection_off;
  }
  bool operator<(const ProjectionID& r) const {
    if (table_id < r.table_id)
      return true;
    else if (table_id == r.table_id)
      return (projection_off < r.projection_off);
    else
      return false;
  }

  /* for boost::serialization*/
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& table_id& projection_off;
  }
};
/* for boost::unordered_map*/
static size_t hash_value(const ProjectionID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, boost::hash_value(key.table_id));
  boost::hash_combine(seed, boost::hash_value(key.projection_off));
  return seed;
}

/**
 * ColumnID: a Column corresponds to an attribute and is physically stored in
 * one projection.
 */
struct ColumnID {
  ColumnID(){};
  ColumnID(ProjectionID pid, ColumnOffset off)
      : projection_id(pid), column_off(off){};
  ProjectionID projection_id;
  // the index of column in projection, not in table
  ColumnOffset column_off;
  bool operator==(const ColumnID& r) const {
    return projection_id == r.projection_id && column_off == r.column_off;
  }

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    //		ar & projection_id & column_off & partitioner & fileLocations &
    // hdfsFilePath & blkMemoryLocations & Projection_name_;
    ar& projection_id& column_off;
  }
};
/* for boost::unordered_map*/
static size_t hash_value(const ColumnID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, hash_value(key.projection_id));
  boost::hash_combine(seed, boost::hash_value(key.column_off));
  return seed;
}

/**
 * PartitionID: a partition corresponds to one projection.
 */
struct PartitionID {
  PartitionID(ProjectionID projection_id, PartitionOffset off)
      : projection_id(projection_id), partition_off(off){};
  PartitionID(){};
  ProjectionID projection_id;
  PartitionOffset partition_off;
  bool operator==(const PartitionID& r) const {
    return projection_id == r.projection_id && partition_off == r.partition_off;
  }
  bool operator<(const PartitionID& r) const {
    if (projection_id < r.projection_id)
      return true;
    else if (projection_id == r.projection_id)
      return (partition_off < r.partition_off);
    else
      return false;
  }
  PartitionID(const PartitionID& r) {
    projection_id = r.projection_id;
    partition_off = r.partition_off;
  }
  std::string getName() const {
    std::ostringstream str;
    str << "T" << projection_id.table_id << "G" << projection_id.projection_off
        << "P" << partition_off;
    return str.str();
  }
  std::string getPathAndName() const;
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& partition_off& projection_id;
  }
};
/* for boost::unordered_map*/
static size_t hash_value(const PartitionID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, hash_value(key.projection_id));
  boost::hash_combine(seed, boost::hash_value(key.partition_off));
  return seed;
}

/**
 * ToDo: a flag is_rt_ is add to ChunkID,  MemStore need to aware this flag and
 * stick the chunk (is_rt_ == true) in memory.
 *
 */
struct ChunkID {
  ChunkID() {}
  ChunkID(PartitionID partition_id, ChunkOffset chunk_offset)
      : partition_id(partition_id), chunk_off(chunk_offset) {}
  ChunkID(PartitionID partition_id, ChunkOffset chunk_offset, bool is_rt)
      : partition_id(partition_id), chunk_off(chunk_offset), is_rt_(is_rt) {}
  ChunkID(const ChunkID& r) {
    partition_id = r.partition_id;
    chunk_off = r.chunk_off;
    is_rt_ = r.is_rt_;
  }
  bool operator==(const ChunkID& r) const {
    return partition_id == r.partition_id && chunk_off == r.chunk_off &&
           is_rt_ == r.is_rt_;
  }
  bool operator<(const ChunkID& r) const {
    if (is_rt_ < r.is_rt_)
      return true;
    else if (partition_id < r.partition_id)
      return true;
    else if (partition_id == r.partition_id)
      return (chunk_off < r.chunk_off);
    else
      return false;
  }
  PartitionID partition_id;
  ChunkOffset chunk_off;
  bool is_rt_ = false;
};
/* for boost::unordered_map*/
static size_t hash_value(const ChunkID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, hash_value(key.partition_id));
  boost::hash_combine(seed, boost::hash_value(key.chunk_off));
  boost::hash_combine(seed, boost::hash_value(key.is_rt_));
  return seed;
}

struct ExchangeID {
  ExchangeID() : exchange_id(0), partition_offset(0) {}
  ExchangeID(unsigned long long int exchange_id, unsigned partition_offset)
      : exchange_id(exchange_id), partition_offset(partition_offset) {}
  bool operator==(const ExchangeID& r) const {
    return exchange_id == r.exchange_id &&
           partition_offset == r.partition_offset;
  }

  unsigned long long int exchange_id;
  unsigned partition_offset;
};

static size_t hash_value(const ExchangeID& key) {
  size_t seed = 0;
  boost::hash_combine(seed, boost::hash_value(key.exchange_id));
  boost::hash_combine(seed, boost::hash_value(key.partition_offset));
  return seed;
}

#endif /* IDS_H_ */
