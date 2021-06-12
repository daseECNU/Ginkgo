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
 * /Claims/loader/test/data_injestion_test.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: yukai
 *		   Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#include <vector>
#include <string>

#include "../../catalog/table.h"
#include "../../catalog/attribute.h"
#include "../../common/Block/ResultSet.h"
#include "data_ingestion_test.h"
using ginkgo::catalog::TableDescriptor;
using ginkgo::catalog::Attribute;
using std::string;
using std::vector;

namespace ginkgo {
namespace loader {

TEST_F(DataIngestionTest, Load) {
  //  EXPECT_TRUE(client_.connected());
  ResultSet rs;
  string command = "";
  std::cout << "it is load" << std::endl;
}

TEST_F(DataIngestionTest, Append) {}

TEST_F(DataIngestionTest, Insert) {}

} /* namespace loader */
} /* namespace ginkgo */
