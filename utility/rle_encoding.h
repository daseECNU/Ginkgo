
#ifndef UTILITY_RLE_ENCODING_H_
#define UTILITY_RLE_ENCODING_H_

#include <math.h>
#include <algorithm>
#include "./bit_stream_utils.h"
#include "./dict_encoding.h"
namespace claims {

class RleDecoder {
 public:
  RleDecoder(uint8_t* buffer, int buffer_len, int bit_width)
      : bit_reader_(buffer, buffer_len),
        bit_width_(bit_width),
        current_value_(0),
        repeat_count_(0),
        literal_count_(0) {
    DCHECK_GE(bit_width_, 0);
    DCHECK_LE(bit_width_, BitReader::MAX_BITWIDTH);
  }

  RleDecoder() : bit_width_(-1) {}

  void Reset(uint8_t* buffer, int buffer_len, int bit_width) {
    DCHECK_GE(bit_width, 0);
    DCHECK_LE(bit_width, BitReader::MAX_BITWIDTH);
    bit_reader_.Reset(buffer, buffer_len);
    bit_width_ = bit_width;
    current_value_ = 0;
    repeat_count_ = 0;
    literal_count_ = 0;
  }

  template <typename T>
  bool Get(T* val);

 protected:
  template <typename T>
  bool NextCounts();

  BitReader bit_reader_;
  int bit_width_;
  uint64_t current_value_;
  uint32_t repeat_count_;
  uint32_t literal_count_;
};

class RleEncoder {
 public:
  RleEncoder(uint8_t* buffer, int buffer_len, int bit_width)
      : bit_width_(bit_width), bit_writer_(buffer, buffer_len) {
    DCHECK_GE(bit_width_, 0);
    DCHECK_LE(bit_width_, 64);
    max_run_byte_size_ = MinBufferSize(bit_width);
    Clear();
  }

  static int MinBufferSize(int bit_width) {
    int max_literal_run_size =
        1 + Ceil(MAX_VALUES_PER_LITERAL_RUN * bit_width, 8);
    int max_repeated_run_size =
        BitReader::MAX_VLQ_BYTE_LEN + Ceil(bit_width, 8);
    return std::max(max_literal_run_size, max_repeated_run_size);
  }

  static int MaxBufferSize(int bit_width, int num_values) {
    int bytes_per_run = Ceil(bit_width * MAX_VALUES_PER_LITERAL_RUN, 8.0);
    int num_runs = Ceil(num_values, MAX_VALUES_PER_LITERAL_RUN);
    int literal_max_size = num_runs + num_runs * bytes_per_run;
    return std::max(MinBufferSize(bit_width), literal_max_size);
  }

  /// Encode value.  Returns true if the value fits in buffer, false otherwise.
  /// This value must be representable with bit_width_ bits.
  bool Put(uint64_t value);

  /// Flushes any pending values to the underlying buffer.
  /// Returns the total number of bytes written
  int Flush();

  /// Resets all the state in the encoder.
  void Clear();

  /// Returns pointer to underlying buffer
  uint8_t* buffer() { return bit_writer_.buffer(); }
  int32_t len() { return bit_writer_.bytes_written(); }
  bool buffer_full() const { return buffer_full_; }

 private:
  void FlushBufferedValues(bool done);

  void FlushLiteralRun(bool update_indicator_byte);

  void FlushRepeatedRun();
  void CheckBufferFull();
  static const int MAX_VALUES_PER_LITERAL_RUN = (1 << 6) * 8;
  const int bit_width_;
  BitWriter bit_writer_;
  bool buffer_full_;
  int max_run_byte_size_;
  int64_t buffered_values_[8];
  int num_buffered_values_;
  int64_t current_value_;
  int repeat_count_;
  int literal_count_;
  uint8_t* literal_indicator_byte_;
};

template <typename T>
inline bool RleDecoder::Get(T* val) {
  DCHECK_GE(bit_width_, 0);
  if (repeat_count_ == 0) {
    if (literal_count_ == 0) {
      if (!NextCounts<T>()) return false;
    }
  }

  if (repeat_count_ > 0) {
    *val = current_value_;
    --repeat_count_;
  } else {
    DCHECK_GT(literal_count_, 0);
    if (!bit_reader_.GetValue(bit_width_, val)) return false;
    --literal_count_;
  }

  return true;
}

template <typename T>
bool RleDecoder::NextCounts() {
  int32_t indicator_value = 0;
  if (!bit_reader_.GetVlqInt(&indicator_value)) return false;
  bool is_literal = indicator_value & 1;
  if (is_literal) {
    literal_count_ = (indicator_value >> 1) * 8;
    if (literal_count_ == 0) return false;
  } else {
    repeat_count_ = indicator_value >> 1;
    bool result = bit_reader_.GetAligned<T>(
        Ceil(bit_width_, 8), reinterpret_cast<T*>(&current_value_));
    if (!result || repeat_count_ == 0) return false;
  }
  return true;
}
inline bool RleEncoder::Put(uint64_t value) {
  DCHECK(bit_width_ == 64 || value < (1LL << bit_width_));
  if (buffer_full_) return false;

  if (current_value_ == value) {
    ++repeat_count_;
    if (repeat_count_ > 8) {
      return true;
    }
  } else {
    if (repeat_count_ >= 8) {
      DCHECK_EQ(literal_count_, 0);
      FlushRepeatedRun();
    }
    repeat_count_ = 1;
    current_value_ = value;
  }

  buffered_values_[num_buffered_values_] = value;
  if (++num_buffered_values_ == 8) {
    DCHECK_EQ(literal_count_ % 8, 0);
    FlushBufferedValues(false);
  }
  return true;
}

inline void RleEncoder::FlushLiteralRun(bool update_indicator_byte) {
  if (literal_indicator_byte_ == NULL) {
    literal_indicator_byte_ = bit_writer_.GetNextBytePtr();
    DCHECK(literal_indicator_byte_ != NULL);
  }

  for (int i = 0; i < num_buffered_values_; ++i) {
    bool success = bit_writer_.PutValue(buffered_values_[i], bit_width_);
    DCHECK(success) << "There is a bug in using CheckBufferFull()";
  }
  num_buffered_values_ = 0;

  if (update_indicator_byte) {
    DCHECK_EQ(literal_count_ % 8, 0);
    int num_groups = literal_count_ / 8;
    int32_t indicator_value = (num_groups << 1) | 1;
    DCHECK_EQ(indicator_value & 0xFFFFFF00, 0);
    *literal_indicator_byte_ = indicator_value;
    literal_indicator_byte_ = NULL;
    literal_count_ = 0;
    CheckBufferFull();
  }
}

inline void RleEncoder::FlushRepeatedRun() {
  DCHECK_GT(repeat_count_, 0);
  bool result = true;
  // The lsb of 0 indicates this is a repeated run
  int32_t indicator_value = repeat_count_ << 1 | 0;
  result &= bit_writer_.PutVlqInt(indicator_value);
  result &= bit_writer_.PutAligned(current_value_, Ceil(bit_width_, 8));
  DCHECK(result);
  num_buffered_values_ = 0;
  repeat_count_ = 0;
  CheckBufferFull();
}

inline void RleEncoder::FlushBufferedValues(bool done) {
  if (repeat_count_ >= 8) {
    // Clear the buffered values.  They are part of the repeated run now and we
    // don't want to flush them out as literals.
    num_buffered_values_ = 0;
    if (literal_count_ != 0) {
      // There was a current literal run.  All the values in it have been
      // flushed
      // but we still need to update the indicator byte.
      DCHECK_EQ(literal_count_ % 8, 0);
      DCHECK_EQ(repeat_count_, 8);
      FlushLiteralRun(true);
    }
    DCHECK_EQ(literal_count_, 0);
    return;
  }

  literal_count_ += num_buffered_values_;
  DCHECK_EQ(literal_count_ % 8, 0);
  int num_groups = literal_count_ / 8;
  if (num_groups + 1 >= (1 << 6)) {
    // We need to start a new literal run because the indicator byte we've
    // reserved
    // cannot store more values.
    DCHECK(literal_indicator_byte_ != NULL);
    FlushLiteralRun(true);
  } else {
    FlushLiteralRun(done);
  }
  repeat_count_ = 0;
}

inline int RleEncoder::Flush() {
  if (literal_count_ > 0 || repeat_count_ > 0 || num_buffered_values_ > 0) {
    bool all_repeat =
        literal_count_ == 0 &&
        (repeat_count_ == num_buffered_values_ || num_buffered_values_ == 0);
    // There is something pending, figure out if it's a repeated or literal run
    if (repeat_count_ > 0 && all_repeat) {
      FlushRepeatedRun();
    } else {
      DCHECK_EQ(literal_count_ % 8, 0);
      // Buffer the last group of literals to 8 by padding with 0s.
      for (; num_buffered_values_ != 0 && num_buffered_values_ < 8;
           ++num_buffered_values_) {
        buffered_values_[num_buffered_values_] = 0;
      }
      literal_count_ += num_buffered_values_;
      FlushLiteralRun(true);
      repeat_count_ = 0;
    }
  }
  bit_writer_.Flush();
  DCHECK_EQ(num_buffered_values_, 0);
  DCHECK_EQ(literal_count_, 0);
  DCHECK_EQ(repeat_count_, 0);

  return bit_writer_.bytes_written();
}

inline void RleEncoder::CheckBufferFull() {
  int bytes_written = bit_writer_.bytes_written();
  if (bytes_written + max_run_byte_size_ > bit_writer_.buffer_len()) {
    buffer_full_ = true;
  }
}

inline void RleEncoder::Clear() {
  buffer_full_ = false;
  current_value_ = 0;
  repeat_count_ = 0;
  num_buffered_values_ = 0;
  literal_count_ = 0;
  literal_indicator_byte_ = NULL;
  bit_writer_.Clear();
}
}  // namespace claims
#endif  // UTILITY_RLE_ENCODING_H_
