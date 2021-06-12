#!/bin/sh


CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR
cd ../2-claims-conf
source ./load-config.sh
cd ../../
# now in GINKGO_HOME

while [ 1 ]
do
 procid=`ps x | grep -w ./install/ginkgo | grep -v grep | awk '{print $1}'`
 if [ "$procid" = "" ]; then
  echo "ginkgo is aborted. Try to restart..."
  ./sbin/stop-all.sh
#  if [ "$local_disk_mode" = "1" ]; then
#  rm $data*
#  fi
  if [ -d "install" ]; then
    if [ ! -f "install/ginkgo" ]; then
     ./sbin/1-compile.sh
    fi
  else
    ./sbin/1-compile.sh
  fi
  ./sbin/3-deploy.sh 
  ./sbin/start-all.sh
  sleep 3 
 else
  echo "ginkgo is running..."
  sleep 180
 fi
done
