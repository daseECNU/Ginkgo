
**Ginkgo** is a parallel in-memory database prototype, which runs on clusters of commodity servers and aims to provide real-time data analytics on relational dataset. 

#### Highlights

##### 1. Fast massively parallel execution engine.

Ginkgo relies on highly parallel query processing engine to dramatically accelerate data analysis speed. Query evaluations are not only distributed across the cluster to leverage the computation power of the cluster, but are also executed in a multi-threaded fashion to unleash the power of modern multi-core hardware.

##### 2. Real-time data ingestion without blocking.
The majority of analytic systems perform long running bulk load data with days delay. This imperfection makes query scan stale tables. Ginkgo employs a real-time data ingestion engine, which continuously fetches records from external data sources and then shuffle to update partitions among cluster. Incoming data is inserted into memory to be scanned and then asynchronously flush to HDFS for persistence. To solve obvious read/write conflicts, Ginkgo produces very lightweight snapshot for each query instance, containing up-to-date view, allowing data ingestion and query are able to concurrently execute without blocking.

##### 3. Smart intra-node parallelism. 

Pipelining the query execution among nodes in the cluster effectively reduces the response time and dramatically saves storage space for intermediate query results. However, its benefits degrade tremendously when the workloads are imbalanced among execution partitions due to the improperly generated query execution plan. To tackle this problem, a novel elastic query processing framework, i.e., *elastic pipelining*, is proposed in Ginkgo, which adjusts the intra-node parallelism according to the runtime workload based on elaborate performance model. Beneficial from elastic pipelining query processing, the parallelism of different execution fragments in a pipelined is self-adaptive, resulting in an optimal intra-node parallelism assignment. Please refer to our SIGMOD paper for more details about the elastic pipelining framework.


##### 4. Efficient in-memory data processing.

Ginkgo employs a large set of optimization techniques to achieve efficient in-memory data processing, including batch-at-a-time processing, cache-sensitive operators, SIMD-based optimization, code generation, lock-free and concurrent processing structures. These optimizations work collaborately and enable Ginkgo to process up to gigabytes data per second per thread.

##### 5. Network communication optimization. 
Parallel query processing imposes high burdens on network communication, which usually becomes performance bottleneck of the in-memory parallel databases due to the relatively slow network bandwidth. When compiling a user query into an execution plan, Ginkgo’s query optimizer leverages a sophisticated selectivity propagation system and cost model to generate physical query plans with minimized network communication cost. Furthermore, Ginkgo deploys a new data exchange implementation, which offers efficient, scalable and skew-resilient network data transfer among Ginkgo instances. These optimizations greatly reduce the response time for a large variety of queries.



#### Quick Start
Try our Ginkgo, please follow [Quick Start](http://58.198.176.124/lizhif/Ginkgo/wikis/Installation-steps).

#### More 
Learn more information, please go to [Wiki](http://58.198.176.124/lizhif/Ginkgo/wikis/home).

