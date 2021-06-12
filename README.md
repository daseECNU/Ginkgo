
# Ginkgo

**Ginkgo** is an in-memory distributed data management and processing system for big data applications, which runs on clusters of commodity servers and aims to provide real-time data analytics on relational dataset. 

#### Highlights

##### 1. Fast massively parallel execution engine.

Ginkgo relies on highly parallel query processing engine to dramatically accelerate data analysis speed. Query evaluations are not only distributed across the cluster to leverage the computation power of the cluster, but are also executed in a multi-threaded fashion to unleash the power of modern many-core hardware. Due to unpredictable data distributions, the static schduling ploicy could idle computing resouces of cluster.
To maximize the resource utilization on the cluster, it employs elastic execution on the pipelines of query DAG, which fills the resource bubbles by resizing the pipelining width on the fly.

##### 2. Real-time and transactional data ingestion.

Many analytical systems usually perform bulk loading with a long delay. This imperfection makes the query scan stale data. Ginkgo employs a real-time data ingestion module, which continuously ingests external fresh data into the partitions among the in-memory cluster and then asynchronously flushed to HDFS for persistence. To solve obvious read/write conflicts on the cluster, it introduces a metadata-based protocol, which converts each distributed transcation into multiple single-site transactions for rawdata and metadata respectively. As a result, it is enabled to produce a lightweight snapshot for query execution.

##### 3. Efficient in-memory data processing.

Ginkgo employs a large set of optimization techniques to achieve efficient in-memory data processing, including batch-at-a-time processing, cache-sensitive operators, column pruning, data compression, SIMD-based optimization, code generation, lock-free and concurrent processing structures. These optimizations work collaborately and enable Ginkgo to process up to gigabytes data per second per thread.


Currently, we are developing Ginkgo at East China Normal University. If you have any problems about this project, please contact us.

Email: ginkgo.bigdata@gmail.com

#### Quick Start
Try our Ginkgo, please follow [Quick Start](https://github.com/daseECNU/Ginkgo/wiki/Installation-steps).
Learn more information, please go to [Wiki](https://github.com/daseECNU/Ginkgo/wiki/home).

#### Current Team Members

Chuliang Weng, Professor. 
<br /> 
Zhifang Li, Ph.D. Student. 
<br /> 
Shangwei Wu, Ph.D. Student. 
<br /> 
Xiaopeng Fan, Ph.D. Student. 
<br /> 
Zeyu He, Postgraduate Student.
<br /> 
Beicheng Peng, Postgraduate Student.
<br /> 
Xiaoshuang Peng, Postgraduate Student. 

#### Former Team Members
Qiuli Huang, Zhuhe Fang, Zhenhui Zhao, Tingting Sun, Minqi Zhou, Li Wang, Lei Zhang, Shaochan Dong, Xinzhou Zhang, Yu Kai, Yongfeng Li, Lin Gu
 
