##  Ginkgo DML : LOAD,INSERT,SELECT

### 1. LOAD

(This statement is used to import data from the disk，and cover old data)

(1) Format

       LOAD TABLE table_name FROM expr_list with STRING, STRING;

(2) Explanation

     expr_list：Specify the import data file path, you can enter multiple file paths, 
     separated by commas. eg."/home/imdb/data/table1","/home/imdb/data/table2".
     
     The first column delimiter STRING specify only a character, if more than one 
     character, take the first character.eg. '\t'.
     
     The second column delimiter STRING specify only a character, if more than one 
     character,take the first character. eg. '\n'。
(3) Example

`LOAD TABLE a from "/home/imdb/table.csv" with '\t','\n';`

### 2. APPEND

(This statement is used to import data from the disk，append new data)

(1) Format

       APPEND TABLE table_name FROM expr_list with STRING, STRING;

(2) Explanation

     expr_list：Specify the import data file path, you can enter only one file path.
     eg."/home/imdb/data/table1".
     
     The first column delimiter STRING specify only a character, if more than one 
     character, take the first character.eg. '\t'.
     
     The second column delimiter STRING specify only a character, if more than one 
     character,take the first character. eg. '\n'。

(3) Example

`APPEND TABLE a from "/home/imdb/table.csv" with '\t','\n';`
    
### 3. INSERT

(This statement is used to insert one or more data within a particular table)

(1) Format

     INSERT [INTO] table_name [(column_name, …)] VALUES (expr, …), …;
(2) Explanation
           
     column_name：Specify the insertion of data for the column, if not,
                    the default insert all columns.
       
     (Expr,…)：Specify the insertion of content, you need to correspond 
                 with the specified column. 
       
     Insert multiple columns of data can use （expr, …）, …，Each data included
     by the parentheses, separated by commas

(3) Example

`insert into test1 values(10,1.11);`

`insert into region values(4,'Middle'),(3,'Europe'),(2,'Asia'),(1,'America'),(0,'Africa');`

### 4. SELECT

(1) Format

         SELECT [ALL | DISTINCT] select_list [AS other_name]  
         FROM table_name | join_table | subquery as other_name
         [WHERE where_conditions]
         [GROUP BY group_by_list]
         [HAVING search_conditions] 
         [ORDER BY order_list [ASC | DESC]]
         [LIMIT [offset,]row_count ];
       
(2) SELECT Clause Description

| Clause     |              Explanation            |notation      |
| :-------------: |:-----------------------------------:| :-----------:|
| ALL \| DISTINCT       | In the database table may contain duplicate values. Designated "DISTINCT", in the same row on the query results show only one line; specify "ALL", then list all of the line; not specified, the default is "ALL".    |Does not support now  | 
| select_list      | Lists the column name or expression to query, use the "," separated,use "*" present all columns   |See more details about expression in 3.3 Expression Support Sheet |
| AS other_name    |Optionally, rename the output field |   Aliases can be used in the having and order by  |
| FROM table_name \| join_table |Required,specify the table which be read data,support join between tables|   Does not support 'using' in join. If table_name is a subquery, then it should be aliased.  |
| WHERE where_conditions |Optional, WHERE clause for filtering condition | Query results only contains the tuple meets the conditions|
| GROUP BY group_by_list  | for Subtotals      |If an expression appears in the select list, ORDER BY or HAVING clause, then it must has aliase in select_list.And ORDER BY, HAVING clause must uses the alias if needed. |
|HAVING search_conditions | HAVING clause is similar to the WHERE clause, but the HAVING clause can use aggregate functions (such as SUM, AVG, etc.), there is the GROUP By clause as prerequisite.|  |
|ORDER BY order_list [ASC \| DESC] |For ascending (ASC) or descending (DESC) display the query results. When you do not specify ASC or DESC, the default is ASC.|   order_list only specific properties, does not support digital|
| [LIMIT [offset,] row_count ] | Forced SELECT statement returns the specified number of records. LIMIT accept one or two digits natural numbers constant parameters, the offset (the default is 0), the maximum number  |  |

  (3)Expression Support Sheet


| Expression Type     |              Parameters required           |    Example   |Remark|
| ------------- |:---------------------------:| :-----------:| :-----------:|
| expr + expr   , expr - expr   , expr * expr   , expr / expr   , expr % expr| Compatible     |1+2 , 2-1 , 3*4 , 4/2 , 4%2 | do not boolean type data | 
| expr AND expr , expr OR expr | Numeric, logic  |   1 and 0 , 1 or 0  ||
| expr CMP (=,!=,>,<,>=,<=) expr| Compatible |  a>b ||
| Expr[NOT] IN const_list | Corresponding parameter type is compatible   | a in (2,4,5) |IN=(=ANY)|
| expr_row [NOT] IN const_row_list| Corresponding parameter type is compatible   | (a,b) in ((1,'a'),(2,'b'))||
|- expr(negative expression) | the type has negative  | -a ||
|NOT expr(Negative logic)  ,  ! expr(Negative logic)=NOT expr| logic    |  not a , ! a ||
|SUBSTRING(expr,start_position,length)|start_position,length is Non-negative integer|substring('string',2,4)||
| TRIM([{BOTH \| LEADING \| TRAILING} [remstr] FROM] str) |remstr is a string which length is 1 | trim(' abc  '); , trim(BOTH 'a' FROM 'abca');|LEADING Start from the head , TRAILING Start from the tail|
|UPPER(expr)| String| upper('abc') ||
| expr [NOT]LIKE expr1| String|  'abc' like '_b%' |"_" present one char，"%" present any chars|
|CASE WHEN expr1 then expr2 [WHEN expr1 then expr2 else expr3]  END| The return type of expr1 is logical, expr2 is String|case when a%2=0 then 'even'   when a%2=1 then 'odd' else  'none'  end | |
| CASE expr1 WHEN expr2 THEN expr3 [WHEN expr2 THEN expr3 else expr4] END|"=" is compatible in expr1 and expr2 ,expr3 and expr4 is  string| case sex when 1 then ‘male’ else ‘female’ end|it means expr1=expr2，so present expr3|
|expr BETWEEN expr1 AND expr2| expr1 and expr2 's compare operation is compatible with the expr|  a between 2 and 4||
|DATE_ADD(date,INTERVAL expr type)/ DATE_SUB(date,INTERVAL expr type)|date : Date type String , expr : non-negative Integer ,type : day,month,year|DATE_ADD('2014-9-7',INTERVAL 3 day)|Date constants must be delimited as 2010-10-05|



  (4)Special Case Description

*          Region Table

| regionkey (bigint unsigned) |        name(varchar(30))    |
| :-------------: |:-----------------------------------------:|
| 0|Africa|
| 1|America| 
| 2|Asia| 
| 3|Europe|
| 4|Middle|
*          Nation table

|nationkey (bigint unsigned) |  name(varchar(30)) |  regionkey (bigint unsigned) |
| :-------------: |:-----------------------------------:| :-----------:|
| 0|CHINA|2|
| 1|UNITED STATES|1| 
| 2|RUSSIA|3| 
| 3|KENYA|0| 
| 4|JORDAN|4| 
| 5|INDIA|2|   
  

**(1) aggregation function and group by** 
       
If aggregation function（SUM()，COUNT()，AVG()，MAX()，MIN() and COUNT(*)) appears in "select_list".
Then the non-aggregation function expression which also exists in "select_list" is a subset of 
the expressions in "groupby_list".

`"select count(*) from nation group by nationkey;" is OK`

`"select count(*), name from nation group by nationkey;" isn't OK, because 'name' doesn't appear in "group by"`


If there is a expression (not a single column) in "groupby_list", and it also appears in "select_list", "ordeyby", or in "having", then the expression must be aliased in "select_list", and use the alias in "orderby"
and "having" if the expression is referred here. 

`select max(nationkey),regionkey%3 as region from nation group by region order by region;`

**Result**

|max(nationkey)|region |
| :-------------: |:-----------------------------------:|
| 3|0|
| 4|1|
| 5|2|

Explanation:  regionkey%3 must be aliased in select_list (region), and refer to the alias in group by and order by.

**(2) join**

There are two kinds of join -- inner join and outer join. And outer join includes left, right and full outer join.
You can use "ON" to specify join condition. Currently ,CLAIMS supports " Table1 [LEFT | RIGHT | FULL [OUTER]] join Table2  [ON condition]" . 
> **Note:** CLAIMS only supports outer join under equal join condition.

`select nation.name,region.name  
from nation join region on nation.regionkey = region.regionkey;` 

**Result**

|nation.name|region.name |
| :--------: |:----------:|
| CHINA|Asia|
| UNITED STATES|America|
| RUSSIA|Europe|
|KENYA|Africa|
| JORDAN|Middle|
|INDIA|Asia|

**(3) SUBQUERY**

Just support subquery in FROM clause now.

### 4.DELETE
(This statement is used to delete one or several records from a table. And it will return how many records have been deleted.)

(1) Format

    DELETE FROM table_name WHERE where_clause; 

(2) Example

     DELETE FROM REGION WHERE region.name = ‘Asia’; 

