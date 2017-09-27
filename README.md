
# Ginkgo

**Ginkgo** is an in-memory distributed data management and processing system for big data processing applications, which runs on clusters of commodity servers and aims to provide real-time data analytics on relational dataset. 

#### Highlights

##### 1. Fast massively parallel execution engine.

Ginkgo relies on highly parallel query processing engine to dramatically accelerate data analysis speed. Query evaluations are not only distributed across the cluster to leverage the computation power of the cluster, but are also executed in a multi-threaded fashion to unleash the power of modern many-core hardware.

##### 2. Real-time data ingestion without blocking.

The majority of analytic systems usually perform data loading with a days’ delay. This imperfection makes query scan stale data. Ginkgo employs a real-time data ingestion engine, which continuously fetches records from external data sources and then shuffles to update partitions among cluster. Incoming data is inserted into memory to be scanned and then asynchronously flushed to HDFS for persistence. To solve obvious read/write conflicts, Ginkgo produces a lightweight snapshot for each query execution.

##### 3. Efficient in-memory data processing.

Ginkgo employs a large set of optimization techniques to achieve efficient in-memory data processing, including batch-at-a-time processing, cache-sensitive operators, SIMD-based optimization, code generation, lock-free and concurrent processing structures. These optimizations work collaborately and enable Ginkgo to process up to gigabytes data per second per thread.


Currently, we are developing Ginkgo at East China Normal University. If you have any problems about this project, please contact us.

Email: ginkgo.bigdata@gmail.com

#### Quick Start
Try our Ginkgo, please follow [Quick Start](https://github.com/daseECNU/Ginkgo/wiki/Installation-steps).
Learn more information, please go to [Wiki](https://github.com/daseECNU/Ginkgo/wiki/home).

#### Current Team Members

Chuliang Weng, Professor.

Zhuhe Fang, Ph.D. Student.

Zhifang Li, Ph.D. Student.

Zhenhui Zhao, Postgraduate Student.

Tingting Sun, Postgraduate Student.

Zeyu He, Postgraduate Student.

Qiuli Huang, Postgraduate Student.

Beicheng Peng, Undergraduate Student.

#### Former Team Members
Minqi Zhou, Li Wang, Lei Zhang, Shaochan Dong, Xinzhou Zhang, Yu Kai, Yongfeng Li, Lin Gu



