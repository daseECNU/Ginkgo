# Add gtest
---
## 1. Add header files
Add header files path which has test cases into "./Test/gtest_main.cpp".
```c++
#include "iterator/elastic_iterator_model_test.h"
#include "../common/test/operate_test.h"
#include "iterator/elastic_iterator_model_test.h"
```
## 2. Add test case 

``` c++
TEST_F(ElasticIteratorModelTest, Scan) {
  EXPECT_TRUE(client_.connected());
  ResultSet rs;
  std::string command = "select count(*) from LINEITEM;";
  std::string message;
  client_.submit(command, message, rs);
  DynamicBlockBuffer::Iterator it = rs.createIterator();
  BlockStreamBase::BlockStreamTraverseIterator *b_it =
      it.nextBlock()->createIterator();
  EXPECT_EQ(6001215, *(long *)b_it->nextTuple());
  delete b_it;
}
```