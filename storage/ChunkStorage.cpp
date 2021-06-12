/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * /CLAIMS/storage/ChunkStorage.cpp
 *
 *  Created on: NOV 14, 2013
 *  Modified on: NOV 29, 2015
 *      Author: Hanzhang,wangli
 *       Email:
 *
 * Description:
 *
 */
#include <hdfs.h>
#include <glog/logging.h>
#include "./BlockManager.h"
#include "./ChunkStorage.h"
#include "../common/error_define.h"
#include "../common/error_no.h"
#include "../common/file_handle/hdfs_connector.h"
#include "../Config.h"
#include "../Debug.h"
#include "../utility/rdtsc.h"
#include "../utility/warmup.h"
#include "../loader/slave_loader.cpp"
using ginkgo::common::CStrError;
using ginkgo::common::rUnkownStroageLevel;
using ginkgo::common::rFailOpenFileInDiskChunkReaderIterator;
using ginkgo::common::rFailReadOneBlockInDiskChunkReaderIterator;
using ginkgo::common::rFailOpenHDFSFileInStorage;
using ginkgo::common::rFailSetStartOffsetInStorage;
using ginkgo::common::HdfsConnector;
using ginkgo::loader::SlaveLoader;
bool ChunkReaderIterator::NextBlock() {
  lock_.acquire();
  if (this->cur_block_ >= this->number_of_blocks_) {
    lock_.release();
    return false;
  }
  cur_block_++;
  lock_.release();
  return true;
}

ChunkStorage::ChunkStorage(const ChunkID& chunk_id, const unsigned block_size,
                           const StorageLevel desirable_storage_level)
    : chunk_id_(chunk_id),
      block_size_(block_size),
      desirable_storage_level_(desirable_storage_level),
      current_storage_level_(HDFS),
      chunk_size_(CHUNK_SIZE) {}

ChunkStorage::ChunkStorage(const ChunkID& chunk_id, const unsigned block_size,
                           const StorageLevel desirable_storage_level,
                           const StorageLevel current_storage_level)
    : chunk_id_(chunk_id),
      block_size_(block_size),
      desirable_storage_level_(desirable_storage_level),
      current_storage_level_(current_storage_level),
      chunk_size_(CHUNK_SIZE) {}

ChunkStorage::~ChunkStorage() {
  // TODO(wangli): Auto-generated destructor  stub
}

// apply memory for chunk size for writing later by slave loader
RetCode ChunkStorage::ApplyMemory() {
  RetCode ret = ginkgo::common::rSuccess;
  HdfsInMemoryChunk chunk_info;
  chunk_info.length = CHUNK_SIZE;
  if (BlockManager::getInstance()->getMemoryChunkStore()->ApplyChunk(
          chunk_id_, chunk_info.hook)) {
    /* there is enough memory storage space, so the storage level can be
     * shifted.*/
    current_storage_level_ = MEMORY;

    /*
     * set each block tail to "zero" in new chunk
     */
    for (auto offset = BLOCK_SIZE; offset <= CHUNK_SIZE; offset += BLOCK_SIZE) {
      *reinterpret_cast<unsigned*>(chunk_info.hook + offset -
                                   sizeof(unsigned)) = 0;
    }

    /*    cout << "Success to apply mem chunk:"
             << chunk_id_.partition_id.partition_off << "," <<
       chunk_id_.chunk_off
             << endl;*/
    /* update the chunk info in the Chunk store in case that the
     * chunk_info is updated.*/
    BlockManager::getInstance()->getMemoryChunkStore()->UpdateChunkInfo(
        chunk_id_, chunk_info);
  } else {
    /*
     * The storage memory is full, some swap algorithm is needed here.
     * TODO: swap algorithm.
     */
    /*    cout << "Failed to apply mem chunk:" <<
       chunk_id_.partition_id.partition_off
             << "," << chunk_id_.chunk_off << endl;*/
    ret = ginkgo::common::rNoMemory;
    assert(false);
  }
  return ret;
}

/**
 * The function create the chunk iterator. Meantime, according to the storage
 * level, create the chunk reader iterator in which storage level. It is a
 * optimization that memory store data as a buffer. The granularity of reading
 * file is chunk.
 */
ChunkReaderIterator* ChunkStorage::CreateChunkReaderIterator() {
  lock_.acquire();
  ChunkReaderIterator* ret;

  HdfsInMemoryChunk chunk_info;
  if (current_storage_level_ == MEMORY &&
      !BlockManager::getInstance()->getMemoryChunkStore()->GetChunk(
          chunk_id_, chunk_info)) {
    current_storage_level_ = HDFS;
    DLOG(INFO) << "clean dirty data" << endl;
    DLOG(INFO) << "the chunk has be freed : " << chunk_id_.chunk_off << endl;
  }
  switch (current_storage_level_) {
    case MEMORY: {
      if (BlockManager::getInstance()->getMemoryChunkStore()->GetChunk(
              chunk_id_, chunk_info))
        ret = new InMemoryChunkReaderItetaor(chunk_info.hook, chunk_info.length,
                                             CHUNK_SIZE / BLOCK_SIZE,
                                             block_size_, chunk_id_);
      else
        ret = NULL;
      break;
    }
    case DISK: {
      printf("Currently, current storage level should not be DISK~! -_-\n");
      assert(false);
      break;
    }
    case HDFS: {
      if (desirable_storage_level_ == MEMORY) {
        chunk_info.length = CHUNK_SIZE;
        if (BlockManager::getInstance()->getMemoryChunkStore()->ApplyChunk(
                chunk_id_, chunk_info.hook)) {
          /* there is enough memory storage space, so the storage level can be
           * shifted.*/
          if (Config::local_disk_mode) {
            chunk_info.length = BlockManager::getInstance()->LoadFromDisk(
                chunk_id_, chunk_info.hook, chunk_info.length);
          } else {
            chunk_info.length = BlockManager::getInstance()->LoadFromHdfs(
                chunk_id_, chunk_info.hook, chunk_info.length);
          }
          if (chunk_info.length <= 0) {
            /**
          * chunk_info.length<=0 means that either the file does not exist or
          * the current chunk_id exceeds the actual size of the file.
             */
            BlockManager::getInstance()->getMemoryChunkStore()->ReturnChunk(
                chunk_id_);
            ret = NULL;
            break;
          }
          current_storage_level_ = MEMORY;

          /* update the chunk info in the Chunk store in case that the
           * chunk_info is updated.*/
          BlockManager::getInstance()->getMemoryChunkStore()->UpdateChunkInfo(
              chunk_id_, chunk_info);
          //  printf("%lx current is set to memory!\n");
          ret = new InMemoryChunkReaderItetaor(
              chunk_info.hook, chunk_info.length,
              chunk_info.length / block_size_, block_size_, chunk_id_);
          break;
        } else {
          /*The storage memory is full, some swap algorithm is needed here.
           * TODO: swap algorithm. I finish in applychunk().*/
          LOG(WARNING) << "Failed to get memory chunk budege!" << endl;
          assert(false);
        }
      }

      ret = new DiskChunkReaderIteraror(chunk_id_, chunk_size_, block_size_);
      break;
    }
    default: { WLOG(rUnkownStroageLevel, "current storage level: unknown!"); }
  }
  lock_.release();
  return ret;
}

std::string ChunkStorage::PrintCurrentStorageLevel() const { return ""; }

InMemoryChunkReaderItetaor::InMemoryChunkReaderItetaor(
    void* const& start, const unsigned& chunk_size,
    const unsigned& number_of_blocks, const unsigned& block_size,
    const ChunkID& chunk_id)
    : start_(start),
      ChunkReaderIterator(chunk_id, block_size, chunk_size, number_of_blocks) {}

bool InMemoryChunkReaderItetaor::NextBlock(BlockStreamBase*& block) {
  lock_.acquire();
  if (cur_block_ >= number_of_blocks_) {
    lock_.release();
    return false;
  }
  cur_block_++;
  lock_.release();

  /* calculate the block start address.*/
  const char* block_start_address = (char*)start_ + cur_block_ * block_size_;

  /* Create a block, which will not free block_start_address when destructed.*/
  Block temp_block(block_size_, block_start_address);

  /*construct the block stream from temp_block. In the current version, the
   * memory copy is used for simplicity.
   * TODO(wangli): avoid memory copy.*/
  block->constructFromBlock(temp_block);
  return true;
}
InMemoryChunkReaderItetaor::~InMemoryChunkReaderItetaor() {}

DiskChunkReaderIteraror::DiskChunkReaderIteraror(const ChunkID& chunk_id,
                                                 unsigned& chunk_size,
                                                 const unsigned& block_size)
    : ChunkReaderIterator(chunk_id, block_size, chunk_size) {
  block_buffer_ = new Block(block_size_);
  fd_ = FileOpen(chunk_id_.partition_id.getPathAndName().c_str(), O_RDONLY);
  if (fd_ == -1) {
    ELOG(rFailOpenFileInDiskChunkReaderIterator,
         chunk_id_.partition_id.getPathAndName().c_str());
    number_of_blocks_ = 0;
  } else {
    const unsigned start_pos = CHUNK_SIZE * chunk_id_.chunk_off;
    const unsigned long length = lseek(fd_, 0, SEEK_END);

    if (length <= start_pos) {
      printf("fails to set the start offset %d for [%s]\n", start_pos,
             chunk_id.partition_id.getName().c_str());
      number_of_blocks_ = 0;
    } else {
      const unsigned offset = lseek(fd_, start_pos, SEEK_SET);
      printf("The file is set to be %d\n", offset);
      //			sleep(1);
      if (start_pos + CHUNK_SIZE < length) {
        number_of_blocks_ = CHUNK_SIZE / block_size_;
      } else {
        number_of_blocks_ = (length - start_pos) / block_size_;
        LOG(INFO) << "This chunk has only" << number_of_blocks_ << "blocks!"
                  << endl;
      }
    }
  }
}
DiskChunkReaderIteraror::~DiskChunkReaderIteraror() {
  block_buffer_->~Block();
  FileClose(fd_);
}

bool DiskChunkReaderIteraror::NextBlock(BlockStreamBase*& block) {
  lock_.acquire();
  if (cur_block_ >= number_of_blocks_) {
    lock_.release();
    return false;
  }
  const unsigned posistion = lseek(fd_, 0, SEEK_CUR);
  /*
   * the read function will automatically move the read position, so the lseek
   * is not needed here.
   */
  tSize bytes_num =
      read(fd_, block_buffer_->getBlock(), block_buffer_->getsize());
  if (bytes_num == block_size_) {
    cur_block_++;
    block->constructFromBlock(*block_buffer_);
    lock_.release();
    return true;
  } else {
    cur_block_++;
    ELOG(rFailReadOneBlockInDiskChunkReaderIterator,
         "failed to read one block");
    lock_.release();
    return false;
  }
}

HDFSChunkReaderIterator::HDFSChunkReaderIterator(const ChunkID& chunk_id,
                                                 unsigned& chunk_size,
                                                 const unsigned& block_size)
    : ChunkReaderIterator(chunk_id, block_size, chunk_size) {
  block_buffer_ = new Block(block_size_);
  //  fs_ = hdfsConnect(Config::hdfs_master_ip.c_str(),
  //  Config::hdfs_master_port);

  fs_ = HdfsConnector::Instance();
  hdfs_fd_ = hdfsOpenFile(fs_, chunk_id.partition_id.getName().c_str(),
                          O_RDONLY, 0, 0, 0);
  if (!hdfs_fd_) {
    ELOG(rFailOpenHDFSFileInStorage, chunk_id.partition_id.getName().c_str());
    number_of_blocks_ = 0;
  }

  const unsigned start_pos = start_pos + CHUNK_SIZE * chunk_id_.chunk_off;
  if (hdfsSeek(fs_, hdfs_fd_, start_pos) == -1) {
    LOG(WARNING) << "[" << rFailSetStartOffsetInStorage << " , "
                 << CStrError(rFailSetStartOffsetInStorage) << "]"
                 << "fails to set the start offset" << start_pos << "for "
                 << chunk_id.partition_id.getName().c_str() << endl;
    number_of_blocks_ = 0;
  }
  hdfsFileInfo* file_info = hdfsGetPathInfo(
      fs_, "/imdb/");  // to be refined after communicating with Zhang Lei
  if (start_pos + CHUNK_SIZE < file_info->mSize) {
    number_of_blocks_ = CHUNK_SIZE / block_size_;
  } else {
    number_of_blocks_ = (file_info->mSize - start_pos) / block_size_;
  }
  hdfsFreeFileInfo(file_info, 1);
}
HDFSChunkReaderIterator::~HDFSChunkReaderIterator() {
  block_buffer_->~Block();
  hdfsCloseFile(fs_, hdfs_fd_);
  //  hdfsDisconnect(fs_);
}
bool HDFSChunkReaderIterator::NextBlock(BlockStreamBase*& block) {
  if (cur_block_ >= number_of_blocks_) {
    lock_.acquire();
    return false;
  }
  tSize bytes_num = hdfsPread(fs_, hdfs_fd_, cur_block_ * block_size_,
                              block_buffer_->getBlock(), CHUNK_SIZE);
  if (bytes_num == block_size_) {
    printf("cur block=%d\n", cur_block_);
    cur_block_++;
    block->constructFromBlock(*block_buffer_);
    lock_.release();
    return true;
  } else {
    cur_block_++;
    lock_.release();
    return false;
  }
}
/**
 * Generate the block_accessor and get information from block_accessor to
 * acquire blocks.
 */
bool InMemoryChunkReaderItetaor::GetNextBlockAccessor(block_accessor*& ba) {
  lock_.acquire();
  if (cur_block_ >= number_of_blocks_) {
    lock_.release();
    return false;
  }
  const unsigned cur_block = cur_block_;
  cur_block_++;
  lock_.release();
  ba = new InMemeryBlockAccessor();
  InMemeryBlockAccessor* imba = (InMemeryBlockAccessor*)ba;

  imba->SetBlockSize(block_size_);

  imba->SetTargetBlockStartAddress((char*)start_ + cur_block * block_size_);
  return true;
}

/**
 * Generate the block_accessor and get information from block_accessor to
 * acquire blocks.
 */
bool DiskChunkReaderIteraror::GetNextBlockAccessor(block_accessor*& ba) {
  lock_.acquire();
  if (cur_block_ >= number_of_blocks_) {
    lock_.release();
    return false;
  }
  const unsigned cur_block = cur_block_;
  cur_block_++;
  lock_.release();
  ba = new InDiskBlockAccessor();
  InDiskBlockAccessor* idba = (InDiskBlockAccessor*)ba;
  idba->SetBlockCur(cur_block);

  idba->SetBlockSize(block_size_);
  idba->SetChunkId(chunk_id_);
  idba->SetBlockSize(chunk_size_);

  return true;
}

/**
 * Generate the block_accessor and get information from block_accessor to
 * acquire blocks.
 */
bool HDFSChunkReaderIterator::GetNextBlockAccessor(block_accessor*& ba) {
  lock_.acquire();
  if (cur_block_ >= number_of_blocks_) {
    lock_.release();
    return false;
  }
  const unsigned cur_block = cur_block_;
  cur_block_++;
  lock_.release();
  ba = new InHDFSBlockAccessor();
  InHDFSBlockAccessor* ihba = (InHDFSBlockAccessor*)ba;
  ihba->SetBlockCur(cur_block);
  ihba->SetBlockSize(block_size_);
  ihba->SetChunkId(chunk_id_);
  ihba->SetBlockSize(chunk_size_);
  return true;
}

void ChunkReaderIterator::InMemeryBlockAccessor::GetBlock(

    BlockStreamBase*& block) const {
//#define MEMORY_COPY
#ifdef MEMORY_COPY

  /* Create a block, which will not free block_start_address when destructed.*/
  Block temp_block(block_size, target_block_start_address);

  block->constructFromBlock(temp_block);
#else

  /* According to my experiment, the performance can by improved by 2x by
   * avoiding the memory copy here */

  block->setIsReference(true);
  block->setBlock(target_block_start_address_);
  int tuple_count =
      *(unsigned*)((char*)target_block_start_address_ +
                   block->getSerializedBlockSize() - sizeof(unsigned));
  DLOG(INFO) << "Get Block whose tuple counts is:" << tuple_count
             << ", start address is:" << target_block_start_address_;
  dynamic_cast<BlockStreamFix*>(block)->setTuplesInBlock(tuple_count);
//  ((BlockStreamFix*)block)->free_ =
//      (char*)block->getBlock() +
//      tuple_count * ((BlockStreamFix*)block)->tuple_size_;

#endif
}

void ChunkReaderIterator::InDiskBlockAccessor::GetBlock(
    BlockStreamBase*& block) const {
  printf("InDiskBlockAccessor::getBlock() is not implemented!\n");
  assert(false);
}

void ChunkReaderIterator::InHDFSBlockAccessor::GetBlock(

    BlockStreamBase*& block) const {
  printf("InHDFSBlockAccessor::getBlock() is not implemented!\n");
  assert(false);
}

uint64_t InMemoryChunkWriterIterator::Write(const void* const buffer_to_write,
                                            uint64_t length_to_write) {
  DLOG(INFO) << "current block id is:" << block_id_
             << ", block size is:" << block_size_;
  void* block_offset = chunk_offset_ + block_id_ * block_size_;
  assert(block_offset < chunk_offset_ + CHUNK_SIZE &&
         "this block is not in this chunk");

  unsigned* tuple_count_in_block = reinterpret_cast<unsigned*>(
      block_offset + block_size_ - sizeof(unsigned));
  int left_space = block_size_ - sizeof(unsigned) - pos_in_block_;
  int can_store_tuple_count = left_space / tuple_size_;

  //  int can_store_tuple_count =
  //      (block_size_ - sizeof(unsigned)) / tuple_size_ -
  //      *tuple_count_in_block;
  assert(can_store_tuple_count >= 0);
  DLOG(INFO) << "block whose id is " << block_id_ << " stored "
             << *tuple_count_in_block << " tuple and leaf "
             << can_store_tuple_count
             << " tuple space. and tuple size is:" << tuple_size_;

  /// there are space to store data
  if (can_store_tuple_count > 0) {
    int actual_written_tuple_count = length_to_write > left_space
                                         ? can_store_tuple_count
                                         : length_to_write / tuple_size_;
    DLOG(INFO) << "memcpy " << actual_written_tuple_count
               << " tuples to memory whose start pos is "
               << block_offset + pos_in_block_
               << ". buffer to write: " << buffer_to_write;
    memcpy(block_offset + pos_in_block_, buffer_to_write,
           actual_written_tuple_count * tuple_size_);
    /*    for (auto p = 0; p < actual_written_tuple_count; p++) {
          for (auto c = 1; c < schema_->getncolumns(); c++)
            SlaveLoader::logfile
                << schema_->getColumnValue(buffer_to_write + p * tuple_size_, c)
                << "|";
          SlaveLoader::logfile << schema_->getTupleMaxSize() << endl;
        }*/
    /*
        SlaveLoader::logfile << block_id_ << "," << pos_in_block_ << ","
                             << pos_in_block_ +
                                    actual_written_tuple_count* tuple_size_ <<
       endl;
    */

    DLOG(INFO) << "copy " << actual_written_tuple_count * tuple_size_
               << " bytes into block:" << block_id_;

    __sync_add_and_fetch(tuple_count_in_block, actual_written_tuple_count);
    return actual_written_tuple_count * tuple_size_;
  }
  return 0;
}
