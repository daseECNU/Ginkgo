##  Ginkgo DDL : CREATE TABLE，CREATE PROJECTION

### CREATE TABLE

(This statement can create new table)

1. Format

    CREATE TABLE [IF NOT EXISTS] table_name (column_name data_type, ...);
1. Data type 

| Data type     |              Explanation            |    Fields   |
| ------------- |:-----------------------------------:| -----------:|
| Boolean       | Yes/No variable true/false/NULL     |        BIT  | 
| SmallInt      | 2 bytes signed integer -2^15~2^15-1   |   SMALLINT   |
| USmallInt     | 2 bytes unsigned integer 0~2^16-1     |   SMALLINT UNSIGNED  |
| Int | 4 bytes signed integer -2^31~2^31-1    |   INT  |
| ULong | 8 bytes unsigned integer 0~2^64-1     |    BIGINT UNSIGNED |
| Float | 4 bytes floating point numbers      |    FLOAT  |
|Double| 8 bytes floating point numbers     |   DOUBLE  |
|Decimal| 16 bytes high precision real number |   DECIMAL|
| String | Variable length strings    |    VARCHAR |
|Date| 4 bytes date from “1400-01-01” to “9999-12-31”|   DATE  |
| Time| 8 bytes time from “00:00:00” to “23:59:59”   |  TIME  |
| DateTime |A combination of date and time type which costs 8 bytes to store. From “1400-01-01 00:00:00.000000” to “9999-12-31 23:59:59.999999 ” ||From “1400-01-01 00:00:00” to “9999-12-31 23:59:59” |  DATETIME |

Example

`create table test1(a int, b float, c varchar(4));`

`CREATE TABLE IF NOT EXIST test2(a int, b smallint, c datetime);`

You can use `show tables;` to check your tables


### CREATE PROJECTION

(This statement can create projection on a table in CLAIMS,After created a table 
        you must execute this statement,otherwise you can not do normal operation on this table.
        you can create one or more projection on a table)

1. Format

    CREATE PROJECTION ON table_name(column_name,…) [NUMBER ＝expr ] PARTITIONED ON column_name;
1. Explanation
    
    (column_name,…)：Create a projection on which the specified attribute.
    
    Expr ：Specifies the number of partitions to create, if not specified, the default is 1.
    
    Column_name：Specifies the projection of the key(only one) and must be included in the (column_name,...).

Example

`CREATE PROJECTION ON test1（a, b, c）partitioned on a;`

`CREATE PROJECTION ON test1(a, b, c) number  = 3 partitioned on a;`


###  DROP TABLE

(This statement can delete one or several tables from database.)

1. Format

   DROP TABLE talbe_name [, table_name] ...

Example

`DROP TABLE Nation, Region; `

