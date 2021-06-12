#include <iostream>
#include <string>

#include "../ClaimsServer.h"
#include "../Client.h"
#include "../ClientResponse.h"

#include <unistd.h>
#include <cstdio>
#include <vector>

#include "../../catalog/attribute.h"
#include "../../catalog/catalog.h"
#include "../../catalog/partitioner.h"
#include "../../catalog/table.h"
#include "../../common/data_type.h"
#include "../../Environment.h"
#include "../../Test/set_up_environment.h"

using namespace std;

static int loadData() {
  Environment::getInstance(true);

  ResourceManagerMaster* rmms =
      Environment::getInstance()->getResourceManagerMaster();
  Catalog* catalog = Environment::getInstance()->getCatalog();

  TableDescriptor* table_1 = new TableDescriptor(
      "cj",
      Environment::getInstance()->getCatalog()->allocate_unique_table_id());
  table_1->addAttribute("row_id", data_type(t_u_long), 0, true);  // 0
  table_1->addAttribute("trade_date", data_type(t_int));
  table_1->addAttribute("order_no", data_type(t_u_long), 0, true);
  table_1->addAttribute("sec_code", data_type(t_int));
  table_1->addAttribute("trade_dir", data_type(t_int));
  table_1->addAttribute("order_type", data_type(t_int));  // 5
  table_1->addAttribute("trade_no", data_type(t_int), 0, true);
  table_1->addAttribute("trade_time", data_type(t_int));
  table_1->addAttribute("trade_time_dec", data_type(t_u_long));
  table_1->addAttribute("order_time", data_type(t_int));
  table_1->addAttribute("order_time_dec", data_type(t_u_long));  // 10
  table_1->addAttribute("trade_price", data_type(t_double));
  table_1->addAttribute("trade_amt", data_type(t_double));
  table_1->addAttribute("trade_vol", data_type(t_double));
  table_1->addAttribute("pbu_id", data_type(t_int));
  table_1->addAttribute("acct_id", data_type(t_int));  // 15
  table_1->addAttribute("order_prtfil_code", data_type(t_int));
  table_1->addAttribute("tran_type", data_type(t_int));
  table_1->addAttribute("trade_type", data_type(t_int));
  table_1->addAttribute("proc_type", data_type(t_int));

  vector<ColumnOffset> cj_proj0_index;
  cj_proj0_index.push_back(0);
  cj_proj0_index.push_back(1);
  cj_proj0_index.push_back(2);
  cj_proj0_index.push_back(3);
  cj_proj0_index.push_back(4);
  cj_proj0_index.push_back(5);
  const int partition_key_index_1 = 2;
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",4);
  ////G0
  table_1->createHashPartitionedProjection(cj_proj0_index, "row_id", 1);  // G0
  //		catalog->add_table(table_1);
  vector<ColumnOffset> cj_proj1_index;
  cj_proj1_index.push_back(0);
  cj_proj1_index.push_back(6);
  cj_proj1_index.push_back(7);
  cj_proj1_index.push_back(8);
  cj_proj1_index.push_back(9);
  cj_proj1_index.push_back(10);
  cj_proj1_index.push_back(11);
  cj_proj1_index.push_back(12);
  cj_proj1_index.push_back(13);
  cj_proj1_index.push_back(14);
  cj_proj1_index.push_back(15);
  cj_proj1_index.push_back(16);
  cj_proj1_index.push_back(17);
  cj_proj1_index.push_back(18);
  cj_proj1_index.push_back(18);

  table_1->createHashPartitionedProjection(cj_proj1_index, "row_id", 1);  // G1

  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",8);
  ////G2
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",8);
  ////G3
  //
  //		//1 month
  //		// 4 partitions
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",4);
  ////G4
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",4);
  ////G5
  //		// 18 partitions
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",8);
  ////G6
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",8);
  ////G7
  //
  //		// 5 days
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",4);
  ////G8
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",4);
  ////G9
  //
  //		// 1 month 8 partitions
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",8);
  ////G10
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",8);
  ////G11
  //
  //		// 5 days 8 partitions
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"order_no",8);
  ////G12
  //		table_1->createHashPartitionedProjection(cj_proj1_index,"row_id",8);
  ////G13
  //
  //
  //		// 1 day 4 partitions by row_id
  //		table_1->createHashPartitionedProjection(cj_proj0_index,"row_id",4);
  ////G14
  catalog->add_table(table_1);

  ////////////////////////////////////Create table
  /// right//////////////////////////
  TableDescriptor* table_2 = new TableDescriptor(
      "sb",
      Environment::getInstance()->getCatalog()->allocate_unique_table_id());
  table_2->addAttribute("row_id", data_type(t_u_long));
  table_2->addAttribute("order_no", data_type(t_u_long));
  table_2->addAttribute("entry_date", data_type(t_int));
  table_2->addAttribute("sec_code", data_type(t_int));
  table_2->addAttribute("order_type", data_type(t_int));
  table_2->addAttribute("entry_dir", data_type(t_int));  // 5
  table_2->addAttribute("tran_maint_code", data_type(t_int));
  table_2->addAttribute("Last_upd_date", data_type(t_int));
  table_2->addAttribute("Last_upd_time", data_type(t_int));
  table_2->addAttribute("Last_upd_time_dec", data_type(t_u_long));
  table_2->addAttribute("entry_time", data_type(t_int));  // 10
  table_2->addAttribute("entry_time_dec", data_type(t_double));
  table_2->addAttribute("order_price", data_type(t_double));
  table_2->addAttribute("order_exec_vol", data_type(t_double));
  table_2->addAttribute("order_vol", data_type(t_double));
  table_2->addAttribute("pbu_id", data_type(t_int));  // 15
  table_2->addAttribute("acct_id", data_type(t_int));
  table_2->addAttribute("acct_attr", data_type(t_int));
  table_2->addAttribute("branch_id", data_type(t_int));
  table_2->addAttribute("pbu_inter_order_no", data_type(t_int));
  table_2->addAttribute("pub_inter_txt", data_type(t_int));  // 20
  table_2->addAttribute("aud_type", data_type(t_int));
  table_2->addAttribute("trade_restr_type", data_type(t_int));
  table_2->addAttribute("order_star", data_type(t_int));
  table_2->addAttribute("order_restr_type", data_type(t_int));
  table_2->addAttribute("short_sell_flag", data_type(t_int));  // 25

  vector<ColumnOffset> sb_proj0_index;
  sb_proj0_index.push_back(0);
  sb_proj0_index.push_back(1);
  sb_proj0_index.push_back(2);
  sb_proj0_index.push_back(3);
  sb_proj0_index.push_back(4);
  sb_proj0_index.push_back(5);

  //		table_2->createHashPartitionedProjection(sb_proj0_index,"order_no",4);
  ////G0
  table_2->createHashPartitionedProjection(sb_proj0_index, "row_id", 4);  // G0

  vector<ColumnOffset> sb_proj1_index;
  sb_proj1_index.push_back(0);
  sb_proj1_index.push_back(6);
  sb_proj1_index.push_back(7);
  sb_proj1_index.push_back(8);
  sb_proj1_index.push_back(9);
  sb_proj1_index.push_back(10);
  sb_proj1_index.push_back(11);
  sb_proj1_index.push_back(12);
  sb_proj1_index.push_back(13);
  sb_proj1_index.push_back(14);
  sb_proj1_index.push_back(15);
  sb_proj1_index.push_back(16);
  sb_proj1_index.push_back(17);
  sb_proj1_index.push_back(18);
  sb_proj1_index.push_back(19);
  sb_proj1_index.push_back(20);
  sb_proj1_index.push_back(21);
  sb_proj1_index.push_back(22);
  sb_proj1_index.push_back(23);
  sb_proj1_index.push_back(24);
  sb_proj1_index.push_back(25);

  table_2->createHashPartitionedProjection(sb_proj1_index, "row_id", 4);  // G1

  catalog->add_table(table_2);
  ////////////////////////////////////////
  /* the following codes should be triggered by Load module*/
  //////////////////ONE DAY////////////////////////////////////////////////
  // cj_table
  // 4 partitions partitioned by order_no
  for (unsigned i = 0;
       i < table_1->getProjectoin(0)->getPartitioner()->getNumberOfPartitions();
       i++) {
    catalog->getTable(0)->getProjectoin(0)->getPartitioner()->RegisterPartition(
        i, 2);
  }

  for (unsigned i = 0;
       i < table_1->getProjectoin(1)->getPartitioner()->getNumberOfPartitions();
       i++) {
    catalog->getTable(0)->getProjectoin(1)->getPartitioner()->RegisterPartition(
        i, 6);
  }
  // partitioned by row_id
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(14)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(14)->getPartitioner()->RegisterPartition(i,2);
  //		}
  //
  //		// 8 partitions
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(2)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(2)->getPartitioner()->RegisterPartition(i,1);
  //	}
  //
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(3)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(3)->getPartitioner()->RegisterPartition(i,3);
  //	}

  // sb_table
  for (unsigned i = 0;
       i < table_2->getProjectoin(0)->getPartitioner()->getNumberOfPartitions();
       i++) {
    catalog->getTable(1)->getProjectoin(0)->getPartitioner()->RegisterPartition(
        i, 2);
  }

  for (unsigned i = 0;
       i < table_2->getProjectoin(1)->getPartitioner()->getNumberOfPartitions();
       i++) {
    catalog->getTable(1)->getProjectoin(1)->getPartitioner()->RegisterPartition(
        i, 6);
  }
  //	for(unsigned
  // i=0;i<table_2->getProjectoin(2)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(2)->getPartitioner()->RegisterPartition(i,1);
  //	}

  //	for(unsigned
  // i=0;i<table_2->getProjectoin(3)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(3)->getPartitioner()->RegisterPartition(i,3);
  //	}
  //
  //		//partitioned by row_id
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(14)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(14)->getPartitioner()->RegisterPartition(i,2);
  //		}
  //
  //		////////////////////////////////////////
  //
  //		///////////////////ONE
  // MONTH/////////////////////////////////////////////////////////////
  //		//CJ
  //		// 4 partition
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(4)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(4)->getPartitioner()->RegisterPartition(i,40);
  //	}
  //
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(5)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(5)->getPartitioner()->RegisterPartition(i,104);
  //	}
  //		//8 partitions
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(10)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(10)->getPartitioner()->RegisterPartition(i,20);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(11)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(11)->getPartitioner()->RegisterPartition(i,52);
  //		}
  //		// 18 partitions
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(6)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(6)->getPartitioner()->RegisterPartition(i,10);
  //	}
  //
  //	for(unsigned
  // i=0;i<table_1->getProjectoin(7)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(0)->getProjectoin(7)->getPartitioner()->RegisterPartition(i,24);
  //	}
  //
  //		//SB
  //		// 4 partition
  //	for(unsigned
  // i=0;i<table_2->getProjectoin(4)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(4)->getPartitioner()->RegisterPartition(i,39);
  //	}
  //
  //	for(unsigned
  // i=0;i<table_2->getProjectoin(5)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(5)->getPartitioner()->RegisterPartition(i,131);
  //	}
  //		// 8 partitions
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(10)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(10)->getPartitioner()->RegisterPartition(i,20);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(11)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(11)->getPartitioner()->RegisterPartition(i,66);
  //		}
  //		// 18 partitions
  //	for(unsigned
  // i=0;i<table_2->getProjectoin(6)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(6)->getPartitioner()->RegisterPartition(i,10);
  //	}
  //
  //	for(unsigned
  // i=0;i<table_2->getProjectoin(7)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //		catalog->getTable(1)->getProjectoin(7)->getPartitioner()->RegisterPartition(i,30);
  //	}
  //		////////////////////////////////
  //
  //
  //		///////////// FIVE DAYS //////////////////
  //		//// cj////
  //		// 4 partitions
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(8)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(8)->getPartitioner()->RegisterPartition(i,14);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(9)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(9)->getPartitioner()->RegisterPartition(i,36);
  //		}
  //		// 8 partitions
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(12)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(12)->getPartitioner()->RegisterPartition(i,7);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_1->getProjectoin(13)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(0)->getProjectoin(13)->getPartitioner()->RegisterPartition(i,19);
  //		}
  //
  //		//// sb ////
  //		// 4 partitions//
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(8)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(8)->getPartitioner()->RegisterPartition(i,14);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(9)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(9)->getPartitioner()->RegisterPartition(i,131);
  //		}
  //		// 8 partitions//
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(12)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(12)->getPartitioner()->RegisterPartition(i,7);
  //		}
  //
  //		for(unsigned
  // i=0;i<table_2->getProjectoin(13)->getPartitioner()->getNumberOfPartitions();i++){
  //
  //			catalog->getTable(1)->getProjectoin(13)->getPartitioner()->RegisterPartition(i,23);
  //		}
}

static int testServerClient() {
  char cmd;
  std::cin >> cmd;
  if (cmd == 'c') {
    Client client;
    client.connection("127.0.0.1", 8001);
    //		std::cout << "Please input the query cmd!" << std::endl;
    while (1) {
      std::cout << ">";
      std::string query;
      char* args = new char[65535];  // new
      std::cin.getline(args, 65535);
      query.append(args);
      delete args;
      if (query == "exit" || query == "shutdown") {
        break;
      } else if (query.empty()) {
        continue;
      }
      ClientResponse* response = client.submitQuery(query);
      //
      //			if( query == "shutdown" ){
      //				break;
      //			}

      if (response->status == OK) {
        ResultSet rs;
        printf("Client get server response ok: %s\n",
               response->content.c_str());

        while (response->status != ENDED) {
          switch (response->status) {
            case SCHEMASS:
              rs.schema_ = response->getSchema();
              break;
            case HEADER:
              rs.column_header_list_ = response->getAttributeName().header_list;
              break;
            case DATA:
              assert(rs.schema_ != 0);
              rs.appendNewBlock(response->getDataBlock(rs.schema_));
              break;
          }

          response = client.receive();

          printf("Message: %s\n", response->getMessage().c_str());
        }
        rs.query_time_ = atof(response->content.c_str());
        rs.print();

      } else if (response->status == CHANGEDD) {
        printf("Message: %s\n", response->content.c_str());
      } else {
        printf("ERROR: %s\n", response->content.c_str());
      }
    }
    client.shutdown();
  } else if (cmd == 's') {
    //		loadData();	//导致服务器退出是内存泄漏的原因
    Environment::getInstance(true);
    ResourceManagerMaster* rmms =
        Environment::getInstance()->getResourceManagerMaster();
    Catalog* catalog = Environment::getInstance()->getCatalog();
    catalog->restoreCatalog();
    //		startup_multiple_node_environment_of_stock();

    // in Environment.cpp:177, create a ClientListener
    //		ClientListener server(8001);
    //		server.configure();
    //		server.run();
    while (true) {
      sleep(10);
    }
  }

  return 0;
}
