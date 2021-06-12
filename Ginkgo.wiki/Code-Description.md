we will describe the function of several primary folders.

+ stmt_handler
    
    The XXX_exec is the executor of each DDL or DML statement. The "stmt_handler" receive every SQL statement, and then parse it to AST, create corresponding XXX executor, and execute. 

+ sql_parser
 
    parse every SQL statement into AST.

+ logical_operator

    logical expression for every operator of query , like filter, join etc..

+ physical_operator
 
    physical expression for every operator of query, besides, including *exchange* operator for shuffling.

+ loader
 
    load data into system, like insert and load statement.
 
+ node_manager
 
    manage state of every node in cluster, master-slave architecture, every slave node connects to master node periodically.

+ storage

    manage data in memory.

+ common

    auxiliary function.


    