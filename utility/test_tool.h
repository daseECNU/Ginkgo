/*
 * test_tool.h
 *
 *  Created on: Feb 27, 2014
 *      Author: wangli
 */

#ifndef TEST_TOOL_H_
#define TEST_TOOL_H_

#include <string>
inline void print_pass(){
	printf("\033[;32m PASS!\033[0m\n");
}
inline void print_fail(){
	printf("\033[;31m FAIL!\033[0m\n");
}
inline void print_test_result(bool result){
	if(result)
		print_pass();
	else
		print_fail();
}
inline bool print_test_name_result(bool result,std::string test_name=std::string()){
	if(test_name.size()>0){
		printf("Test %s =====>",test_name.c_str());
	}
	if(result){
		print_pass();
		return true;
	}
	else{
		print_fail();
		return false;
	}
}

inline bool is_equal(int x,int y){
	return fabs(x-y)<0.0000001;
}

inline bool is_equal(float x,float b){
	return fabs(x-b)<0.000001;
}

inline bool is_equal(NValue x,NValue y){
	return x.op_equals(y);
}

#endif /* TEST_TOOL_H_ */
