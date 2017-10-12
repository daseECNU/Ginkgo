/*
 * ResultSet.h
 *
 *  Created on: Jan 20, 2014
 *      Author: wangli
 */

#ifndef RESULTSET_H_
#define RESULTSET_H_
#ifdef DMALLOC
#include "dmalloc.h"
#endif
#include "DynamicBlockBuffer.h"
#include "../../catalog/table.h"
#include "../../catalog/catalog.h"
class ResultSet :public DynamicBlockBuffer{
public:
	ResultSet():DynamicBlockBuffer(),schema_(0){};
	ResultSet(const ResultSet& r);
	virtual ~ResultSet();
	void print()const;
  void getResult(unsigned int &change_row,
                            vector<string>& sel_result);
  void getResult(unsigned int &change_row,
                   vector<unsigned> insert_index,
                   vector<Attribute> attributes,
                   Schema* table_schema,
                   vector<string>& sel_result);
	Schema* schema_;
	std::vector<std::string> column_header_list_;
	double query_time_;
private:
	void printNChar(int n, char c)const;
};

#endif /* RESULTSET_H_ */
