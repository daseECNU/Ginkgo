# Installation steps
0. Requirement

   (1) Compiler Requirement

        GCC >= 4.8 and GCC<=4.9
        clang >= 3.2
        CMAKE >= 2.8.11
        support c++11

   (2) Operating System Requirement
          
        CentOS >= 6.5 （recommend centos 7, development mode） or Fedora 23:

1. Install third party library packages

    (1)  [Download](https://pan.baidu.com/s/1gfbxwFh) third party library packages and put it in your home folder;
    
   
    The thirdparty library packages include following: 
   * hadoop 2.7.1
   * boost 1.53.0
   * libxs 1.2.0
   * libconfig 1.4.9
   * gtest 1.7.0
   * gflags 2.0
   * glog 0.3.3
   * libunwind 1.1
   * gperftools 2.4
   * caf 0.14
   * libsnappy.1.3.1
   * activemq 3.9.3
   * apr 1.5.2 
   * llvm

    (2) uncompression the thirdparty.tar.gz and read the README of the folder
 ```
     tar -xzvf thirdparty_xx.tar.gz    (xx is suffix)
 ```
    (3) run the shell  
        Attention: Install process will ask you to write claims_home. (claims_home means the absolute path of CLAIMS folder)
 ```
    cd thirdparty
  
    ./install

    enter 1
 ```
2. Initialize git and git clone Ginkgo( checkout to latest version)
 ```
     git init

     git clone git@58.198.176.124:lizhif/Ginkgo.git
     git checkout master 

 ```
    Maybe you need to add claims_home in ~/.bashrc file. if you forget enter claims_home in (3) step.
    [click here to see recommanded config and bashrc](http://58.198.176.124/lizhif/Ginkgo/wikis/Configure)
 ``` 
    vi ~/.bashrc

    add "export GINKGO_HOME=/usr/claims/Desktop/git/Ginkgo"
       
    source ~/.bashrc
 ```
3. Compilation and Installation
 ```
    cd $GINKGO_HOME
    
    ./build.sh init
    
    mkdir install
     
    cd install
    
    ../configure

    make -j4    
 ```
4. Configure

    Default configure file at /Ginkgo/conf/config, **please set the path for data and catalog! and do not forget change ip。** please see [[Configure]].
    
     **In standalone mode**
    you just need set data directory.
    
         eg. data="/home/Ginkgo/Desktop/data/"  

    **Do not forget the slash at the end of it.** 
     
         data="/home/Ginkgo/Desktop/data" is wrong example
                                      
5. Run and Test
 ```   
    cd /.../Ginkgo/install
    
    ./ginkgo -c ../conf/config
    
    ./client 127.0.0.1 10000
 ``` 
  if you want to run test, please run (**Under the premise of loaded data successfully**)

 ```
    cd $GINKGO_HOME/sbin/claims-test
    
    ./run-gtest.sh
 ```
    Note: ./ginkgo -h can give you help, ./client ip port


    ./test --ip 127.0.0.1 --port 10000 for test if you have tpc-h sf=1 data 
    and load it with partition=1. please see [[DDL of SQL]].

6. Uninstallation and Clean
 ```
    make distclean (at /.../Ginkgo/install/)

    ./build.sh clean (at /.../Ginkgo/)
 ```
7. FAQ:

    (1) Error: JAVA_HOME is not set.

        1).change /Hadoop/conf/hadoop-env.sh

        2).add export JAVA_HOME="/home/.../thirdparty/jdk1.7.0_71"(the path in your machine)