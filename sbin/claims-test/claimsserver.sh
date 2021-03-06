#!/bin/sh
set -e
CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR

cd ../2-claims-conf/
source ./load-config.sh
cd ../../
# now in GINKGO_HOME

# for debug begin #####
cd install
ulimit -c unlimited
cd ../
# for debug end #######
serverpath=`pwd`
echo $serverpath
$serverpath/install/ginkgo -c $serverpath/sbin/2-claims-conf/config-$master
