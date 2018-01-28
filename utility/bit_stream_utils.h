
#ifndef UTILITY_BIT_STREAM_UTILS_H_
#define UTILITY_BIT_STREAM_UTILS_H_
#include <boost/cstdint.hpp>
#include "./dict_encoding.h"

#include <algorithm>
#include <string>
using std::min;
namespace claims {
constexpr static inline int64_t Ceil(int64_t value, int64_t divisor);
static uint64_t TrailingBits(uint64_t v, int num_bits) {
  if (num_bits >= 64) return v;
  return ((1UL << num_bits) - 1) & v;
}
class BitWriter {
 public:
  BitWriter(uint8_t* buffer, int buffer_len)
      : buffer_(buffer), max_bytes_(buffer_len) {
    Clear();
  }

  void Clear() {
    buffered_values_ = 0;
    byte_offset_ = 0;
    bit_offset_ = 0;
  }

  int bytes_written() const { return byte_offset_ + Ceil(bit_offset_, 8); }
  uint8_t* buffer() const { return buffer_; }
  int buffer_len() const { return max_bytes_; }

  bool PutValue(uint64_t v, int num_bits) {
    if (byte_offset_ * 8 + bit_offset_ + num_bits > max_bytes_ * 8)
      return false;

    buffered_values_ |= v << bit_offset_;
    bit_offset_ += num_bits;

    if (bit_offset_ >= 64) {
      memcpy(buffer_ + byte_offset_, &buffered_values_, 8);
      buffered_values_ = 0;
      byte_offset_ += 8;
      bit_offset_ -= 64;
      buffered_values_ = v >> (num_bits - bit_offset_);
    }
    return true;
  }

  template <typename T>
  bool PutAligned(T val, int num_bytes) {
    uint8_t* ptr = GetNextBytePtr(num_bytes);
    if (ptr == NULL) return false;
    memcpy(ptr, &val, num_bytes);
    return true;
  }
  bool PutVlqInt(int32_t v) {
    bool result = true;
    while ((v & 0xFFFFFF80) != 0L) {
      result &= PutAligned<uint8_t>((v & 0x7F) | 0x80, 1);
      v >>= 7;
    }
    result &= PutAligned<uint8_t>(v & 0x7F, 1);
    return result;
  }

  uint8_t* GetNextBytePtr(int num_bytes = 1) {
    Flush(true);
    if (byte_offset_ + num_bytes > max_bytes_) return NULL;
    uint8_t* ptr = buffer_ + byte_offset_;
    byte_offset_ += num_bytes;
    return ptr;
  }

  void Flush(bool align = false) {
    int num_bytes = Ceil(bit_offset_, 8);
    memcpy(buffer_ + byte_offset_, &buffered_values_, num_bytes);
    if (align) {
      buffered_values_ = 0;
      byte_offset_ += num_bytes;
      bit_offset_ = 0;
    }
  }

  static const int MAX_BITWIDTH = 32;

 private:
  uint8_t* buffer_;
  int max_bytes_;
  uint64_t buffered_values_;
  int byte_offset_;
  int bit_offset_;
};

class BitReader {
 public:
  BitReader(const uint8_t* buffer, int buffer_len) {
    Reset(buffer, buffer_len);
  }
  BitReader() : buffer_(NULL), max_bytes_(0) {}
  void Reset(const uint8_t* buffer, int buffer_len) {
    buffer_ = buffer;
    max_bytes_ = buffer_len;
    byte_offset_ = 0;
    bit_offset_ = 0;
    int num_bytes = std::min(8, max_bytes_);
    memcpy(&buffered_values_, buffer_, num_bytes);
  }
  template <typename T>
  bool GetValue(int num_bits, T* v) {
    if (byte_offset_ + sizeof(buffered_values_) + MAX_BITWIDTH / 8 >
        max_bytes_) {
      if (byte_offset_ * 8 + bit_offset_ + num_bits > max_bytes_ * 8) {
        return false;
      }
    }
    *v = TrailingBits(buffered_values_, bit_offset_ + num_bits) >> bit_offset_;
    bit_offset_ += num_bits;
    if (bit_offset_ >= 64) {
      byte_offset_ += 8;
      bit_offset_ -= 64;

      int bytes_remaining = max_bytes_ - byte_offset_;
      if (bytes_remaining >= 8) {
        memcpy(&buffered_values_, buffer_ + byte_offset_, 8);
      } else {
        memcpy(&buffered_values_, buffer_ + byte_offset_, bytes_remaining);
      }

      *v |= TrailingBits(buffered_values_, bit_offset_)
            << (num_bits - bit_offset_);
    }
    return true;
  }
  template <typename T>
  bool GetAligned(int num_bytes, T* v) {
    int bytes_read = Ceil(bit_offset_, 8);
    if (byte_offset_ + bytes_read + num_bytes > max_bytes_) return false;
    byte_offset_ += bytes_read;
    memcpy(v, buffer_ + byte_offset_, num_bytes);
    byte_offset_ += num_bytes;
    bit_offset_ = 0;
    int bytes_remaining = max_bytes_ - byte_offset_;
    if (bytes_remaining >= 8) {
      memcpy(&buffered_values_, buffer_ + byte_offset_, 8);
    } else {
      memcpy(&buffered_values_, buffer_ + byte_offset_, bytes_remaining);
    }
    return true;
  }

  bool GetVlqInt(int32_t* v) {
    *v = 0;
    int shift = 0;
    uint8_t byte = 0;
    do {
      if (shift >= MAX_VLQ_BYTE_LEN * 7) return false;
      if (!GetAligned<uint8_t>(1, &byte)) return false;
      *v |= (byte & 0x7F) << shift;
      shift += 7;
    } while ((byte & 0x80) != 0);
    return true;
  }

  int bytes_left() {
    return max_bytes_ - (byte_offset_ + Ceil(bit_offset_, 8));
  }

  static const int MAX_VLQ_BYTE_LEN = 5;

  static const int MAX_BITWIDTH = 32;

 private:
  const uint8_t* buffer_;
  int max_bytes_;
  uint64_t buffered_values_;
  int byte_offset_;  // Offset in buffer_
  int bit_offset_;   // Offset in buffered_values_
};
}  // namespace claims

#endif  // UTILITY_BIT_STREAM_UTILS_H_
