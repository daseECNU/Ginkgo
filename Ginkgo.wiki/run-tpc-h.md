## we provide two ways to run tpc-h in Ginkgo.
### First one is use already loaded data by ourselves.
[Click here to download data](https://pan.baidu.com/s/1skHoR7Z)

**(if you want to save time, you can choose this method)**

1.uncompress sf-1-p4.tar.gz

```
tar -zxvf sf-1-p4.tar.gz
```

2.use this data directly ( fix config file in $GINKGO_HOME/conf/config) 
[Click here to see recommanded configure](http://58.198.176.124/lizhif/Ginkgo/wikis/Configure)
```
data="/home/Ginkgo/../sf-1-p4/"
```
**make sure "local_disk_mode=1" in config  and don't forget the '/' in the end of data directory**

3.run Ginkgo and input "show tables" at client to see tables are loaded successfully 


4.run gtest
```
cd $GINKGO_HOME/sbin/claims-test/

./run-gtest.sh
```
### Second one is do everything by yourself.


1. Install the Ginkgo successfully
1. Learn the DDL and DML of Ginkgo

    **NOTE:** the expressions and functions we supported now are limited!
1. generate tpc-h data according to [manual](http://www.tpc.org/tpc_documents_current_versions/pdf/tpc-h_v2.17.1.pdf) and put the data in _tpc-h-data-dir_
1. create table and load data from _tpc-h-data-dir_ , an example is at appendix0, data sf=1 and partition=1. 

    **NOTE:** Check Ginkgo is in local mode or hdfs mode, and the data_dir of Ginkgo should be a new one
1. run Ginkgo, and input "show tables" at client to see tables are loaded successfully  
1. run SQL of tpc-h, the sql are at appendix1

    **NOTE:** due to lack of some functions and some changes, we just support 1,3,5,6,10,12,17 now.

**Appendix0**
```
create table part(
p_partkey bigint unsigned,
p_name varchar(55),
p_mfgr varchar(25),
p_brand varchar(10),
p_type varchar(25),
p_size int,
p_container varchar(10),
p_retailprice  decimal(4),
p_comment varchar(23)
);
create projection on part(
p_partkey,
p_name,
p_mfgr,
p_brand,
p_type,
p_size,
p_container,
p_retailprice,
p_comment
) number =  1 partitioned on p_partkey;
load table part from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/part.tbl" with '|','\n';

create table supplier(
s_suppkey bigint unsigned,
s_name varchar(25),
s_address varchar(40),
s_nationkey bigint unsigned,
s_phone varchar(15),
s_acctbal decimal(4),
s_comment varchar(101)
);
create projection on supplier(
s_suppkey,
s_name,
s_address,
s_nationkey,
s_phone,
s_acctbal,
s_comment
) number = 1 partitioned on s_suppkey;
load table supplier from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/supplier.tbl" with '|','\n';

create table partsupp(
ps_partkey bigint unsigned,
ps_suppkey bigint unsigned,
ps_availqty int,
ps_supplycost decimal(2),
ps_comment varchar(199)
);



create projection on partsupp(
ps_partkey,
ps_suppkey,
ps_availqty,
ps_supplycost,
ps_comment
) number = 1 partitioned on ps_partkey;
load table partsupp from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/partsupp.tbl" with '|','\n';

create table customer(
c_custkey bigint unsigned,
c_name varchar(25),
c_address varchar(40),
c_nationkey bigint unsigned,
c_phone varchar(15),
c_acctbal decimal(4),
c_mktsegment varchar(10),
c_comment varchar(117)
);
create projection on customer(
c_custkey,
c_name,
c_address,
c_nationkey,
c_phone,
c_acctbal,
c_mktsegment,
c_comment
) number = 1 partitioned on c_custkey;
load table customer from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/customer.tbl" with '|','\n';


create table orders(
o_orderkey bigint unsigned,
o_custkey bigint unsigned,
o_orderstatus varchar(1),
o_totalprice decimal(4),
o_orderdate date,
o_orderpriority varchar(15),
o_clerk varchar(15),
o_shippriority int,
o_comment varchar(79)
);
create projection on orders(
o_orderkey,
o_custkey,
o_orderstatus,
o_totalprice,
o_orderdate,
o_orderpriority,
o_clerk,
o_shippriority,
o_comment
) number = 1 partitioned on o_orderkey;
load table orders from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/orders.tbl" with '|','\n';


create table lineitem(
l_orderkey bigint unsigned,
l_partkey bigint unsigned,
l_suppkey bigint unsigned,
l_linenumber int, 
l_quantity decimal(4),
l_extendedprice decimal(4),
l_discount decimal(4),
l_tax decimal(4),
l_returnflag varchar(1),
l_linestatus varchar(1),
l_shipdate date,
l_commitdate date,
l_receiptdate date,
l_shipinstruct varchar(25),
l_shipmode varchar(10),
l_comment varchar(44)
);

create projection on lineitem(
l_orderkey,
l_partkey,
l_suppkey,
l_linenumber,
l_quantity,
l_extendedprice,
l_discount,
l_tax,
l_returnflag,
l_linestatus,
l_shipdate,
l_commitdate,
l_receiptdate,
l_shipinstruct,
l_shipmode,
l_comment
) number = 1 partitioned on l_orderkey;

load table lineitem from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/lineitem.tbl" with '|','\n';


create table nation(
n_nationkey bigint unsigned,
n_name varchar(25),
n_regionkey bigint unsigned,
n_comment varchar(152)
);

create projection on nation(
n_nationkey,
n_name,
n_regionkey,
n_comment
) number = 1 partitioned on n_nationkey;

load table nation from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/nation.tbl" with '|','\n';




create table region(
r_regionkey bigint unsigned,
r_name varchar(25),
r_comment varchar(152)
);

create projection on region(
r_regionkey,
r_name,
r_comment
) number = 1 partitioned on r_regionkey;
load table region from "/home/imdb/rawData/tpch-raw-data/tpch_sf1/region.tbl" with '|','\n';
```
**Appendix1**

_SQL_1:_
```
select
	l_returnflag,
	l_linestatus,
	sum(l_quantity) as sum_qty,
	sum(l_extendedprice) as sum_base_price,
	sum(l_extendedprice * (1 - l_discount)) as sum_disc_price,
	sum(l_extendedprice * (1 - l_discount) * (1 + l_tax)) as sum_charge,
	avg(l_quantity) as avg_qty,
	avg(l_extendedprice) as avg_price,
	avg(l_discount) as avg_disc,
	count(*) as count_order
from
	lineitem
where
	l_shipdate <= date_sub('1998-12-01', interval 77 day)
group by
	l_returnflag,
	l_linestatus
order by
	l_returnflag,
	l_linestatus;
```
_SQL_3:_
```
select
	l_orderkey,
	sum(l_extendedprice * (1 - l_discount)) as revenue,
	o_orderdate,
	o_shippriority
from
	customer,
	orders,
	lineitem
where
	c_mktsegment = 'HOUSEHOLD'
	and c_custkey = o_custkey
	and l_orderkey = o_orderkey
	and o_orderdate < '1995-03-04'
	and l_shipdate > '1995-03-04'
group by
	l_orderkey,
	o_orderdate,
	o_shippriority
order by
	revenue desc,
	o_orderdate;
```
_SQL_5:_
```
select
	n_name,
	sum(l_extendedprice * (1 - l_discount)) as revenue
from
	customer,
	orders,
	lineitem,
	supplier,
	nation,
	region
where
	c_custkey = o_custkey
	and l_orderkey = o_orderkey
	and l_suppkey = s_suppkey
	and c_nationkey = s_nationkey
	and s_nationkey = n_nationkey
	and n_regionkey = r_regionkey
	and r_name = 'AMERICA'
	and o_orderdate >= '1993-01-01'
	and o_orderdate < date_add('1993-01-01', interval 1 year)
group by
	n_name
order by
	revenue desc;
```
_SQL_6:_
```
select
	sum(l_extendedprice * l_discount) as revenue
from
	lineitem
where
	l_shipdate >= '1993-01-01'
	and l_shipdate < date_add('1993-01-01', interval 1 year)
	and l_discount between 0.04 - 0.01 and 0.04 + 0.01
	and l_quantity < 25;
```
_SQL_10:_
```
select
	c_custkey,
	c_name,
	sum(l_extendedprice * (1 - l_discount)) as revenue,
	c_acctbal,
	n_name,
	c_address,
	c_phone,
	c_comment
from
	customer,
	orders,
	lineitem,
	nation
where
	c_custkey = o_custkey
	and l_orderkey = o_orderkey
	and o_orderdate >=  '1994-09-01'
	and o_orderdate < date_add( '1994-09-01', interval 3 month)
	and l_returnflag = 'R'
	and c_nationkey = n_nationkey
group by
	c_custkey,
	c_name,
	c_acctbal,
	c_phone,
	n_name,
	c_address,
	c_comment
order by
	revenue desc;
```
_SQL_12:_
```
select
	l_shipmode,
	sum(case
		when o_orderpriority = '1-URGENT'
			or o_orderpriority = '2-HIGH'
			then 1
		else 0
	end) as high_line_count,
	sum(case
		when o_orderpriority <> '1-URGENT'
			and o_orderpriority <> '2-HIGH'
			then 1
		else 0
	end) as low_line_count
from
	orders,
	lineitem
where
	o_orderkey = l_orderkey
	and l_shipmode in ('RAIL', 'MAIL')
	and l_commitdate < l_receiptdate
	and l_shipdate < l_commitdate
	and l_receiptdate >=  '1997-01-01'
	and l_receiptdate < date_add( '1997-01-01' , interval '1' year)
group by
	l_shipmode
order by
	l_shipmode;
```
_SQL_17:_
```
select
	sum(l_extendedprice) / 7.0 as avg_yearly
from
	lineitem,
	part,
	(SELECT l_partkey AS agg_partkey, 0.2 * avg(l_quantity) AS avg_quantity FROM lineitem GROUP BY l_partkey) part_agg
where
	p_partkey = l_partkey
	and agg_partkey = l_partkey
	and p_brand = 'Brand#52'
	and p_container = 'JUMBO JAR'
	and l_quantity < avg_quantity;

```