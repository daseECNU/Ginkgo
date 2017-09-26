
# Ginkgo

**Ginkgo** is a parallel in-memory database prototype, which runs on clusters of commodity servers and aims to provide real-time data analytics on relational dataset. 

#### Highlights

##### 1. Fast massively parallel execution engine.

Ginkgo relies on highly parallel query processing engine to dramatically accelerate data analysis speed. Query evaluations are not only distributed across the cluster to leverage the computation power of the cluster, but are also executed in a multi-threaded fashion to unleash the power of modern multi-core hardware.

##### 2. Real-time data ingestion without blocking.
The majority of analytic systems perform long running bulk load data with days delay. This imperfection makes query scan stale tables. Ginkgo employs a real-time data ingestion engine, which continuously fetches records from external data sources and then shuffle to update partitions among cluster. Incoming data is inserted into memory to be scanned and then asynchronously flush to HDFS for persistence. To solve obvious read/write conflicts, Ginkgo produces very lightweight snapshot for each query execution instance, containing up-to-date view to allow data ingestion and query concurrently execution without blocking.

##### 3. Smart intra-node parallelism. 

Pipelining the query execution among nodes in the cluster effectively reduces the response time and dramatically saves storage space for intermediate query results. However, its benefits degrade tremendously when the workloads are imbalanced among execution partitions due to the improperly generated query execution plan. To tackle this problem, a novel elastic query processing framework, i.e., *elastic pipelining*, is proposed in Ginkgo, which adjusts the intra-node parallelism according to the runtime workload based on elaborate performance model. Beneficial from elastic pipelining query processing, the parallelism of different execution fragments in a pipelined is self-adaptive, resulting in an optimal intra-node parallelism assignment. Please refer to our SIGMOD paper for more details about the elastic pipelining framework.


##### 4. Efficient in-memory data processing.

Ginkgo employs a large set of optimization techniques to achieve efficient in-memory data processing, including batch-at-a-time processing, cache-sensitive operators, SIMD-based optimization, code generation, lock-free and concurrent processing structures. These optimizations work collaborately and enable Ginkgo to process up to gigabytes data per second per thread.

##### 5. Network communication optimization. 
Parallel query processing imposes high burdens on network communication, which usually becomes performance bottleneck of the in-memory parallel databases due to the relatively slow network bandwidth. When compiling a user query into an execution plan, Ginkgo’s query optimizer leverages a sophisticated selectivity propagation system and cost model to generate physical query plans with minimized network communication cost. Furthermore, Ginkgo deploys a new data exchange implementation, which offers efficient, scalable and skew-resilient network data transfer among Ginkgo instances. These optimizations greatly reduce the response time for a large variety of queries.

Currently, we are developing Ginkgo at East China Normal University. If you have any problems about this project, please contact us.

Email: ginkgo.bigdata@gmail.com

#### Team Members

[Chuliang Weng]() , Professor in East China Normal University, is the person in charge of this project.

[Zhuhe Fang]()  is mainly responsible for designing and implementing SQL query optimization.

[Zhifang Li]()  is mainly responsible for data ingestion.

[Zhenhui Zhao]()  is mainly responsible for improving system stability.

[Tingting Sun]()  is mainly responsible for data format.

[Zeyu He]()  is mainly responsible for transaction management.

[QiuLi Huang]()  is mainly responsible for data migration.

[BeiCheng Peng]()  is mainly responsible for testing.

#### Former Team Members
[Aoying Zhou](http://case.ecnu.edu.cn), Professor in East China Normal University, is the person in charge of this project.

[Minqi Zhou](https://github.com/polpo1980), Associate Professor in East China Normal University, is the person in charge of this project.

[Li Wang](https://github.com/wangli1426), Ph.D. student in East China Normal University, manages the master students in this team and is responsible for designing and implementing the key components, including query optimizer, catalog, physical operators, distributed communication infrastructure, storage layout, etc.

[Lei Zhang](https://github.com/egraldlo) is responsible for designing and implementing the key components, including query optimizer, physical operators, persistent data exchange, storage management, etc.

[Shaochan Dong](https://github.com/scdong) is responsible for designing and implementing in-memory index and index management, data types, as well as data loading and importing.

[Xinzhou Zhang]() is mainly responsible for web UI design and implementing data importing model.

[Zhuhe Fang](https://github.com/fzhedu) is mainly responsible for designing and implementing SQL DML parser and physical operators.

[Yu Kai](https://github.com/yukai2014) is mainly responsible for designing and implementing SQL DDL parser, catalog persistence.

[Yongfeng Li](https://github.com/NagamineLee) was a formal member of CLAIMS, who participated in designing and implementing catalog model.

[Lin Gu]() is responsible for designing the demo cases.

#### Quick Start
Try our Ginkgo, please follow [Quick Start](https://github.com/daseECNU/Ginkgo/wiki/Installation-steps).

#### More 
Learn more information, please go to [Wiki](https://github.com/daseECNU/Ginkgo/wiki/home).

