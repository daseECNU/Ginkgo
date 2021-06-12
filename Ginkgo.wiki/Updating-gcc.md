c++11 and llvm require gcc version later than 4.7. 

There are three ways to do this:

1. install later version of gcc manually

2. or, install devtoolset-1.1

3. or, install devtoolset-2
 
Since updating gcc directly usually causes nightmare, we highly recommend you to install devtoolset instead. By using devtoolsets, you can freely switch the gcc version between high version and the original version without any effects to the system.

### Install devtoolset-1.1
```
$ sudo wget http://people.centos.org/tru/devtools-1.1/devtools-1.1.repo -P /etc/yum.repos.d
$ sudo sh -c 'echo "enabled=1" >> /etc/yum.repos.d/devtools-1.1.repo'
$ sudo yum install devtoolset-1.1 
```
You can change the gcc version for a terminal by running the following command.
```
$ scl enable devtoolset-1.1 bash
```
If you want to switch back to the original version, just open a new terminal.

The command for checking gcc version is 
``` $ gcc -v ```

## Install devtoolset-2
```
cd /etc/yum.repos.d
sudo wget http://people.centos.org/tru/devtools-2/devtools-2.repo
sudo yum install devtoolset-2
```
You can change the gcc version for a terminal by running the following command.
```
$ scl enable devtoolset-1.1 bash
```
If you want to switch back to the original version, just open a new terminal.

The command for checking gcc version is 
``` $ gcc -v ```