/*
 * IndexScanIterator.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: scdong
 */

#include "IndexScanIterator.h"
#include "IndexManager.h"
#include "../storage/BlockManager.h"

IndexScanIterator::IndexScanIterator():partition_reader_iterator_(0), chunk_reader_iterator_(0)  {
	// TODO Auto-generated constructor stub
	InitExpandedStatus();
}

IndexScanIterator::IndexScanIterator(State state):state_(state), partition_reader_iterator_(0), chunk_reader_iterator_(0) {
	InitExpandedStatus();
	csb_index_list_.clear();
}

IndexScanIterator::~IndexScanIterator() {
	// TODO Auto-generated destructor stub
}

//IndexScanIterator::State::State(ProjectionID projection_id, Schema* schema, unsigned long index_id, void* value_low, void* value_high, unsigned block_size)
//: projection_id_(projection_id), schema_(schema), index_id_(index_id), value_low_(value_low), value_high_(value_high), block_size_(block_size) {
//
//}

IndexScanIterator::State::State(ProjectionID projection_id, Schema* schema, unsigned long index_id, vector<query_range> query_range__, unsigned block_size)
: projection_id_(projection_id), schema_(schema), index_id_(index_id), query_range_(query_range__), block_size_(block_size) {

}

bool IndexScanIterator::Open(const PartitionOffset& partition_off)
{
	AtomicPushBlockStream(BlockStreamBase::createBlockWithDesirableSerilaizedSize(state_.schema_, state_.block_size_));
	if(TryEntryIntoSerializedSection()){

		/* this is the first expanded thread*/
		csb_index_list_ = IndexManager::getInstance()->getAttrIndex(state_.index_id_);
		PartitionStorage* partition_handle_;
		if((partition_handle_=BlockManager::getInstance()->GetPartitionHandle(PartitionID(state_.projection_id_,partition_off)))==0){
			printf("The partition[%s] does not exists!\n",PartitionID(state_.projection_id_,partition_off).getName().c_str());
			SetReturnStatus(false);
		}
		else{
			partition_reader_iterator_=partition_handle_->CreateAtomicReaderIterator();
//			chunk_reader_iterator_ = partition_reader_iterator_->nextChunk();
		}
		SetReturnStatus(true);
	}
	BarrierArrive();
	return GetReturnStatus();
}

bool IndexScanIterator::Next(BlockStreamBase* block)
{
	remaining_block rb;
	void* tuple_from_index_search;

	// There are blocks which haven't been completely processed
	if (atomicPopRemainingBlock(rb))
	{
		while (rb.block_off == rb.iter_result_map->first)
		{
			const unsigned bytes = state_.schema_->getTupleMaxSize();
			if ((tuple_from_index_search = block->allocateTuple(bytes)) > 0)
			{
				state_.schema_->copyTuple(rb.iterator->getTuple(*rb.iter_result_vector), tuple_from_index_search);
				rb.iter_result_vector++;
				if (rb.iter_result_vector == rb.iter_result_map->second->end())
				{
					rb.iter_result_map++;
					if (rb.iter_result_map == rb.result_set->end())
						break;
					rb.iter_result_vector = rb.iter_result_map->second->begin();
				}
			}
			else
			{
				atomicPushRemainingBlock(rb);
				return true;
			}
		}
		AtomicPushBlockStream(rb.block);
	}
	// When the program arrivals here, it means that there is no remaining block or the remaining block is
	// exhausted. What we should do is to ask a new block from the chunk_reader_iterator (or prartition_reader_iterator)
	BlockStreamBase* block_for_asking = AtomicPopBlockStream();
	block_for_asking->setEmpty();
	rb.block = block_for_asking;
	while (askForNextBlock(rb))
	{
		rb.iterator = rb.block->createIterator();
		while (rb.block_off == rb.iter_result_map->first)
		{
			const unsigned bytes = state_.schema_->getTupleMaxSize();
			if ((tuple_from_index_search = block->allocateTuple(bytes)) > 0)
			{
				state_.schema_->copyTuple(rb.iterator->getTuple(*rb.iter_result_vector), tuple_from_index_search);
////For testing begin
//				cout << "<" << rb.iter_result_map->first << ", " << *rb.iter_result_vector << ">\t";
//				state_.schema_->displayTuple(tuple_from_index_search, "\t");
//				sleep(1);
////For testing end
				rb.iter_result_vector++;
				if (rb.iter_result_vector == rb.iter_result_map->second->end())
				{
					rb.iter_result_map++;
					if (rb.iter_result_map == rb.result_set->end())
						break;
					rb.iter_result_vector = rb.iter_result_map->second->begin();
				}
			}
			else
			{
				atomicPushRemainingBlock(rb);
				return true;
			}
		}
		block_for_asking->setEmpty();
	}
	AtomicPushBlockStream(block_for_asking);
	if (!block->Empty())
		return true;
	return false;
}

bool IndexScanIterator::Close()
{
	InitExpandedStatus();
	delete partition_reader_iterator_																																										;
	remaining_block_list_.clear();
	block_stream_list_.clear();
	return true;
}

void IndexScanIterator::AtomicPushBlockStream(BlockStreamBase* block)
{
	lock_.acquire();
	block_stream_list_.push_back(block);
	lock_.release();
}

BlockStreamBase* IndexScanIterator::AtomicPopBlockStream()
{
	assert(!block_stream_list_.empty());
	lock_.acquire();
	BlockStreamBase* block = block_stream_list_.front();
	block_stream_list_.pop_front();
	lock_.release();
	return block;
}

void IndexScanIterator::atomicPushRemainingBlock(remaining_block rb)
{
	lock_.acquire();
	remaining_block_list_.push_back(rb);
	lock_.release();
}

bool IndexScanIterator::atomicPopRemainingBlock(remaining_block& rb)
{
	lock_.acquire();
	if (remaining_block_list_.size() > 0)
	{
		rb = remaining_block_list_.front();
		remaining_block_list_.pop_front();
		lock_.release();
		return true;
	}
	lock_.release();
	return false;
}

bool IndexScanIterator::askForNextBlock(remaining_block& rb)
{
	if (chunk_reader_iterator_ == 0 || chunk_reader_iterator_->NextBlock(rb.block) == false || rb.iter_result_map == rb.result_set->end())
	{
		chunk_reader_iterator_ = partition_reader_iterator_->NextChunk();
		if (chunk_reader_iterator_ == 0)
			return false;

		chunk_reader_iterator_->NextBlock(rb.block);
		rb.block_off = 0;

		//search the CSB+-Tree index to get the new chunk's search-result
		data_type type = IndexManager::getInstance()->getIndexType(state_.index_id_);
		switch (type)
		{
		case t_smallInt:
		{
			assert(false);
			return true;
		}
		case t_int:
		{
			map<ChunkID, void*>::iterator iter = csb_index_list_.begin();
			CSBPlusTree<int>* csb_tree = (CSBPlusTree<int>*)iter->second;
			csb_index_list_.erase(iter++);

			rb.result_set->clear();
			map<index_offset, vector<index_offset>* >* result_set;
			for (vector<query_range>::iterator iter = state_.query_range_.begin(); iter != state_.query_range_.end(); iter++)
			{
//				result_set = csb_tree->rangeQuery(*(int*)iter->value_low, iter->comp_low, *(int*)iter->value_high, iter->comp_high);
				if (result_set->size() != 0)
				{
					for (map<index_offset, vector<index_offset>* >::iterator iter_map = result_set->begin(); iter_map != result_set->end(); iter_map++)
					{
						if (rb.result_set->find(iter_map->first) == rb.result_set->end())
							(*rb.result_set)[iter_map->first] = new vector<index_offset>;
						(*rb.result_set)[iter_map->first]->insert((*rb.result_set)[iter_map->first]->end(), iter_map->second->begin(), iter_map->second->end());
					}
				}
			}

			if (rb.result_set->size() == 0)
			{
				chunk_reader_iterator_ = 0;
				return askForNextBlock(rb);
			}
///*for testing*/			unsigned long count = 0;
			for (rb.iter_result_map = rb.result_set->begin(); rb.iter_result_map != rb.result_set->end(); rb.iter_result_map++)
			{
				for (rb.iter_result_vector = rb.iter_result_map->second->begin(); rb.iter_result_vector != rb.iter_result_map->second->end(); rb.iter_result_vector++)
				{
///*for testing*/					count++;
///*for testing*/					cout << "<" << rb.iter_result_map->first << ", " << *rb.iter_result_vector << ">\t";
					assert(*rb.iter_result_vector<2047);
				}
			}
///*for testing*/			cout << "Total count: " << count << endl;
			rb.iter_result_map = rb.result_set->begin();
			rb.iter_result_vector = rb.iter_result_map->second->begin();
			assert(*rb.iter_result_vector<2047);
			return true;
		}
		case t_u_long:
		{
			assert(false);
			return true;
		}
		case t_float:
		{
			assert(false);
			return true;
		}
		case t_double:
		{
			assert(false);
			return true;
		}
		case t_string:
		{
			assert(false);
			return true;
		}
		case t_date:
		{
			assert(false);
			return true;
		}
		case t_time:
		{
			assert(false);
			return true;
		}
		case t_datetime:
		{
			assert(false);
			return true;
		}
		case t_decimal:
		{
			assert(false);
			return true;
		}
		case t_boolean:
		{
			assert(false);
			return true;
		}
		case t_u_smallInt:
		{
			assert(false);
			return true;
		}
		default:
		{
			cout << "[ERROR: (IndexScanIterator.cpp->askForNextBlock()]: The data type is not defined!\n";
			assert(false);
			return false;
		}
		}
	}
	else
	{
		rb.block_off++;
		return true;
	}

}


