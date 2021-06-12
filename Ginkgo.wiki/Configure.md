Ginkgo runs on clusters of shared-nothing servers, where each server hosts a single Ginkgo instance. One instance actors as the mater, while others are slavers. On each of the server, follow the instructions below to install and execute Ginkgo. Without otherwise specification, the operators on the master node and the slave nodes are the same (This allow you to use tools like [cssh](http://cssh.sourceforge.net) to facilitate your work).

### 1.  ~/.bashrc file under Ginkgo user
you can refer to this file.
```
# .bashrc
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi
 
###############Ginkgo ENVIRONMENT BEGIN###############
CLASSPATH=
export JAVA_HOME=/home/Ginkgo/Desktop/thirdparty/jdk1.7.0_71
export JRE_HOME=$JAVA_HOME/jre
export PATH=$JAVA_HOME/bin:$JRE_HOME/bin:$PATH
export CLASSPATH=.:$JAVA_HOME/lib:$JRE_HOME/lib:$CLASSPATH
export LD_LIBRARY_PATH=$JAVA_HOME/jre/lib/amd64/server:$LD_LIBRARY_PATH
export HADOOP_HOME=/home/Ginkgo/Desktop/thirdparty/hadoop-2.7.1
export PATH=$HADOOP_HOME/bin:$PATH
export CLASSPATH=`sudo $HADOOP_HOME/bin/hadoop classpath --glob`:$CLASSPATH
export LD_LIBRARY_PATH=$HADOOP_HOME/lib/native:$LD_LIBRARY_PATH
export BOOST_HOME=/home/Ginkgo/Desktop/thirdparty/boost_1_53_0
export LD_LIBRARY_PATH=$BOOST_HOME/stage/lib:$LD_LIBRARY_PATH
export GTEST_HOME=/home/Ginkgo/Desktop/thirdparty/gtest-1.7.0
export GLOG_HOME=/home/Ginkgo/Desktop/thirdparty/glog-0.3.3
export GINKGO_HOME=/home/Ginkgo/git/Ginkgo
export PATH=$GINKGO_HOME/install/bin/:$PATH
export CAF_HOME=/home/Ginkgo/Desktop/thirdparty/actor-framework
export LD_LIBRARY_PATH=$CAF_HOME/build/lib:$LD_LIBRARY_PATH
###############Ginkgo ENVIRONMENT END###############
```
### 2. config file

```
#local node ip
ip = "127.0.0.1";

#port range
PortManager:
{
    start = 19000;
    end   = 19500;
}

#the ip and port of master
coordinator:
{
    ip="127.0.0.1"
    port="11001"
}

#this node is master (master=1) of not (master=0)
master=1

client_listener_port = 10000

#the path for data and catalog
data="Your Path"

hdfs_master_ip="127.0.0.1"
hdfs_master_port=9000

#max degree of parallelism of this node
max_degree_of_parallelism=4

#initial degree of parallelism of this node
initial_degree_of_parallelism=1

expander_adaptivity_check_frequency=5000

enable_expander_adaptivity=0

#pipelined exchange or materialized 
pipelined_exchange=1

#run at local node or Hdfs
local_disk_mode=1

scan_batch=100

#enable llvm codegen or not
enable_codegen=0

```

## Notation:
If you have any questions, welcome to start a issue about your problem on Ginkgo github homepage, we are very appreciate that.