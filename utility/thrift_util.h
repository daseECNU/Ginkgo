#ifndef THRIFT_UTIL_H_
#define THRIFT_UTIL_H_
#include <boost/shared_ptr.hpp>
#include <thrift/protocol/TBinaryProtocol.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TDebugProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransportException.h>
#include <thrift/protocol/TCompactProtocol.h>
#include "../common/parquet_types.h"
using namespace apache::thrift;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace parquet;
using namespace claims::common;
namespace claims {

class TColumnValue;
class TNetworkAddress;
class ThriftServer;
/// Utility class to serialize thrift objects to a binary format.  This object
/// should be reused if possible to reuse the underlying memory.
/// Note: thrift will encode NULLs into the serialized buffer so it is not valid
/// to treat it as a string.
class ThriftSerializer {
 public:
  /// If compact, the objects will be serialized using the Compact Protocol.
  /// Otherwise,
  /// we'll use the binary protocol.
  /// Note: the deserializer must be matching.
  ThriftSerializer(bool compact, int initial_buffer_size)
      : mem_buffer_(new TMemoryBuffer(initial_buffer_size)) {
    if (compact) {
      TCompactProtocolFactoryT<TMemoryBuffer> factory;
      protocol_ = factory.getProtocol(mem_buffer_);
    } else {
      TBinaryProtocolFactoryT<TMemoryBuffer> factory;
      protocol_ = factory.getProtocol(mem_buffer_);
    }
  }

  /// Serializes obj into result.  Result will contain a copy of the memory.
  template <class T>
  int Serialize(T* obj, std::vector<uint8_t>* result) {
    uint32_t len = 0;
    uint8_t* buffer = NULL;
    RETURN_IF_ERROR(Serialize<T>(obj, &len, &buffer));
    result->resize(len);
    memcpy(&((*result)[0]), buffer, len);
    return 0;
  }

  /// Serialize obj into a memory buffer.  The result is returned in buffer/len.
  /// The
  /// memory returned is owned by this object and will be invalid when another
  /// object
  /// is serialized.
  template <class T>
  int Serialize(T* obj, uint32_t* len, uint8_t** buffer) {
    try {
      mem_buffer_->resetBuffer();
      obj->write(protocol_.get());
    } catch (std::exception& e) {
      std::stringstream msg;
      msg << "Couldn't serialize thrift object:\n" << e.what();
      return -1;
    }
    mem_buffer_->getBuffer(buffer, len);
    return 0;
  }

  template <class T>
  int Serialize(T* obj, std::string* result) {
    try {
      mem_buffer_->resetBuffer();
      obj->write(protocol_.get());
    } catch (std::exception& e) {
      std::stringstream msg;
      msg << "Couldn't serialize thrift object:\n" << e.what();
      return -1;
    }
    *result = mem_buffer_->getBufferAsString();
    return 0;
  }

 private:
  boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> mem_buffer_;
  boost::shared_ptr<apache::thrift::protocol::TProtocol> protocol_;
};

class ThriftDeserializer {
 public:
  ThriftDeserializer(bool compact);

 private:
  boost::shared_ptr<apache::thrift::protocol::TProtocolFactory> factory_;
  boost::shared_ptr<apache::thrift::protocol::TProtocol> tproto_;
};

/// Utility to create a protocol (deserialization) object for 'mem'.
static boost::shared_ptr<apache::thrift::protocol::TProtocol>
CreateDeserializeProtocol(
    boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> mem,
    bool compact) {
  if (compact) {
    TCompactProtocolFactoryT<TMemoryBuffer> tproto_factory;
    return tproto_factory.getProtocol(mem);
  } else {
    TBinaryProtocolFactoryT<TMemoryBuffer> tproto_factory;
    return tproto_factory.getProtocol(mem);
  }
}

/// Deserialize a thrift message from buf/len.  buf/len must at least contain
/// all the bytes needed to store the thrift message.  On return, len will be
/// set to the actual length of the header.
template <class T>
int DeserializeThriftMsg(const uint8_t* buf, uint32_t* len, bool compact,
                         T* deserialized_msg) {
  /// Deserialize msg bytes into c++ thrift msg using memory
  /// transport. TMemoryBuffer is not const-safe, although we use it in
  /// a const-safe way, so we have to explicitly cast away the const.
  boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> tmem_transport(
      new apache::thrift::transport::TMemoryBuffer(const_cast<uint8_t*>(buf),
                                                   *len));
  boost::shared_ptr<apache::thrift::protocol::TProtocol> tproto =
      CreateDeserializeProtocol(tmem_transport, compact);
  try {
    deserialized_msg->read(tproto.get());
  } catch (std::exception& e) {
    std::stringstream msg;
    msg << "couldn't deserialize thrift msg:\n" << e.what();
    return -1;
  } catch (...) {
    return -1;
  }
  uint32_t bytes_left = tmem_transport->available_read();
  *len = *len - bytes_left;
  return 0;
}
}  // namespace claims

#endif
