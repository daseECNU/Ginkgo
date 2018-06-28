
#ifndef UTILITY_DICT_ENCODING_H_
#define UTILITY_DICT_ENCODING_H_

#include <glog/logging.h>
#include <boost/pool/pool.hpp>
#include <boost/unordered_map.hpp>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include "./rle_encoding.h"
#include "../common/types/decimal.h"

using std::endl;
using std::max;
using claims::common::Decimal;
using boost::pool;
namespace claims {
static const uint64_t MURMUR_PRIME = 0xc6a4a7935bd1e995;
static const int MAX_VALUES_PER_LITERAL_RUN = (1 << 6) * 8;
static const int MURMUR_R = 47;
static const int MAX_VLQ_BYTE_LEN = 5;
static int MaxBufferSize(int bit_width, int num_values);
constexpr static inline int64_t Ceil(int64_t value, int64_t divisor);
static inline int Log2Floor64(uint64_t n);
static inline int Log2Ceiling64(uint64_t n);
static int MinBufferSize(int bit_width);
static uint64_t MurmurHash2_64(const void* input, int len, uint64_t seed);

class DictEncoderBase {
 public:
  virtual ~DictEncoderBase() {
    //    assert(buffered_indices_.empty());
  }

  /// Writes out the encoded dictionary to buffer. buffer must be preallocated
  /// to
  /// dict_encoded_size() bytes.
  virtual void WriteDict(uint8_t* buffer) = 0;

  /// The number of entries in the dictionary.
  virtual int num_entries() const = 0;

  /// Clears all the indices (but leaves the dictionary).
  void ClearIndices() { buffered_indices_.clear(); }

  /// Returns a conservative estimate of the number of bytes needed to encode
  /// the buffered
  /// indices. Used to size the buffer passed to WriteData().
  int EstimatedDataEncodedSize() {
    return 1 + MaxBufferSize(bit_width(), buffered_indices_.size());
  }

  /// The minimum bit width required to encode the currently buffered indices.
  int bit_width() const {
    if (num_entries() == 0) return 0;
    if (num_entries() == 1) return 1;
    return Log2Ceiling64(num_entries());
  }
  //  virtual int Put(void* value);
  /// Writes out any buffered indices to buffer preceded by the bit width of
  /// this data.
  /// Returns the number of bytes written.
  /// If the supplied buffer is not big enough, returns -1.
  /// buffer must be preallocated with buffer_len bytes. Use
  /// EstimatedDataEncodedSize()
  /// to size buffer.
  int WriteData(uint8_t* buffer, int buffer_len);

  int dict_encoded_size() { return dict_encoded_size_; }

 protected:
  explicit DictEncoderBase(pool<>* pool) : dict_encoded_size_(0), pool_(pool) {}

  /// Indices that have not yet be written out by WriteData().
  std::vector<int> buffered_indices_;

  /// The number of bytes needed to encode the dictionary.
  int dict_encoded_size_;
  pool<>* pool_;
};

template <typename T>
class DictEncoder : public DictEncoderBase {
 public:
  explicit DictEncoder(pool<>* pool, int encoded_value_size)
      : DictEncoderBase(pool),
        buckets_(HASH_TABLE_SIZE, Node::INVALID_INDEX),
        encoded_value_size_(encoded_value_size) {}

  int Put(void* value);
  virtual void WriteDict(uint8_t* buffer) {
    for (const Node& node : nodes_) {
      memcpy(buffer, &node.value, encoded_value_size_);
      buffer += encoded_value_size_;
    }
  }

  virtual int num_entries() const { return nodes_.size(); }

 private:
  /// Size of the table. Must be a power of 2.
  enum { HASH_TABLE_SIZE = 1 << 16 };

  typedef uint16_t NodeIndex;

  std::vector<NodeIndex> buckets_;

  struct Node {
    explicit Node(const NodeIndex& n) : next(n) {}
    Node(const T& v, const NodeIndex& n) : value(v), next(n) {}
    T value;
    NodeIndex next;
    enum { INVALID_INDEX = 40000 };
  };

  std::vector<Node> nodes_;
  // the length of column value
  int encoded_value_size_;

  inline uint32_t Hash(const T& value) const;
  int AddToTable(const T& value, NodeIndex* bucket);
};

template <typename T>
inline int DictEncoder<T>::Put(void* value) {
  NodeIndex* bucket =
      &buckets_[Hash(*reinterpret_cast<T*>(value)) & (HASH_TABLE_SIZE - 1)];
  NodeIndex i = *bucket;
  // Look for the value in the dictionary.
  while (i != Node::INVALID_INDEX) {
    const Node* n = &nodes_[i];
    if (n->value == *reinterpret_cast<T*>(value)) {
      // Value already in dictionary.
      buffered_indices_.push_back(i);
      return 0;
    }
    i = n->next;
  }
  // Value not found. Add it to the dictionary if there's space.
  i = nodes_.size();
  if (i >= Node::INVALID_INDEX) return -1;
  buffered_indices_.push_back(i);
  return AddToTable(*reinterpret_cast<T*>(value), bucket);
}

template <typename T>
inline int DictEncoder<T>::AddToTable(const T& value, NodeIndex* bucket) {
  nodes_.push_back(Node(value, *bucket));
  *bucket = nodes_.size() - 1;
  dict_encoded_size_ += encoded_value_size_;
  return encoded_value_size_;
}

template <typename T>
inline uint32_t DictEncoder<T>::Hash(const T& value) const {
  return MurmurHash2_64(&value, sizeof(value), 0);
}

inline int DictEncoderBase::WriteData(uint8_t* buffer, int buffer_len) {
  // Write bit width in first byte
  *buffer = bit_width();
  ++buffer;
  --buffer_len;

  RleEncoder encoder(buffer, buffer_len, bit_width());
  for (int index : buffered_indices_) {
    if (!encoder.Put(index)) return -1;
  }
  encoder.Flush();
  return 1 + encoder.len();
}
class DictDecoderBase {
 public:
  int SetData(uint8_t* buffer, int buffer_len) {
    if (buffer_len == 0) {
      LOG(ERROR) << "Dictionary cannot be 0 bytes\n";
      return -1;
    }

    uint8_t bit_width = *buffer;
    if ((bit_width < 0) || (bit_width > 32)) {
      LOG(ERROR) << "Dictionary has invalid or unsupported bit " << bit_width
                 << endl;
      return -1;
    }
    ++buffer;
    --buffer_len;
    data_decoder_.Reset(buffer, buffer_len, bit_width);
    return 0;
  }
  virtual ~DictDecoderBase() {}
  virtual int num_entries() const = 0;
  virtual void GetValue(int index, void* buffer) = 0;

 protected:
  RleDecoder data_decoder_;
};

template <typename T>
class DictDecoder : public DictDecoderBase {
 public:
  DictDecoder() {}
  bool Reset(uint8_t* dict_buffer, int dict_len, int fixed_len_size);

  virtual int num_entries() const { return dict_.size(); }

  virtual void GetValue(int index, void* buffer) {
    T* val_ptr = reinterpret_cast<T*>(buffer);
    *val_ptr = dict_[index];
  }
  bool GetNextValue(T* value) {
    int index = -1;
    bool result = data_decoder_.Get(&index);
    // Use & to avoid branches.
    if ((result & (index >= 0) & (index < dict_.size()))) {
      *value = dict_[index];
      return true;
    }
    return false;
  }

 private:
  std::vector<T> dict_;
};

template <typename T>
inline bool DictDecoder<T>::Reset(uint8_t* dict_buffer, int dict_len,
                                  int fixed_len_size) {
  dict_.clear();
  uint8_t* end = dict_buffer + dict_len;
  while (dict_buffer < end) {
    T value;
    if ((end - dict_buffer) < fixed_len_size) return false;
    memcpy(&value, dict_buffer, fixed_len_size);
    dict_buffer += fixed_len_size;
    dict_.push_back(value);
  }
  return true;
}

static inline int Log2Floor64(uint64_t n) {
  return n == 0 ? -1 : 63 ^ __builtin_clzll(n);
}
static inline int Log2Ceiling64(uint64_t n) {
  int floor = Log2Floor64(n);
  if (0 == (n & (n - 1))) {
    return floor;
  } else {
    return floor + 1;
  }
}

constexpr static inline int64_t Ceil(int64_t value, int64_t divisor) {
  return value / divisor + (value % divisor != 0);
}
static int MinBufferSize(int bit_width) {
  int max_literal_run_size =
      1 + Ceil(MAX_VALUES_PER_LITERAL_RUN * bit_width, 8);
  int max_repeated_run_size = MAX_VLQ_BYTE_LEN + Ceil(bit_width, 8);
  return std::max(max_literal_run_size, max_repeated_run_size);
}
static int MaxBufferSize(int bit_width, int num_values) {
  int bytes_per_run = Ceil(bit_width * MAX_VALUES_PER_LITERAL_RUN, 8.0);
  int num_runs = Ceil(num_values, MAX_VALUES_PER_LITERAL_RUN);
  int literal_max_size = num_runs + num_runs * bytes_per_run;
  return std::max(MinBufferSize(bit_width), literal_max_size);
}

/// Murmur2 hash implementation returning 64-bit hashes.
static uint64_t MurmurHash2_64(const void* input, int len, uint64_t seed) {
  uint64_t h = seed ^ (len * MURMUR_PRIME);

  const uint64_t* data = reinterpret_cast<const uint64_t*>(input);
  const uint64_t* end = data + (len / sizeof(uint64_t));

  while (data != end) {
    uint64_t k = *data++;
    k *= MURMUR_PRIME;
    k ^= k >> MURMUR_R;
    k *= MURMUR_PRIME;
    h ^= k;
    h *= MURMUR_PRIME;
  }

  const uint8_t* data2 = reinterpret_cast<const uint8_t*>(data);
  switch (len & 7) {
    case 7:
      h ^= uint64_t(data2[6]) << 48;
    case 6:
      h ^= uint64_t(data2[5]) << 40;
    case 5:
      h ^= uint64_t(data2[4]) << 32;
    case 4:
      h ^= uint64_t(data2[3]) << 24;
    case 3:
      h ^= uint64_t(data2[2]) << 16;
    case 2:
      h ^= uint64_t(data2[1]) << 8;
    case 1:
      h ^= uint64_t(data2[0]);
      h *= MURMUR_PRIME;
  }

  h ^= h >> MURMUR_R;
  h *= MURMUR_PRIME;
  h ^= h >> MURMUR_R;
  return h;
}

}  // namespace claims
#endif  // UTILITY_DICT_ENCODING_H_
