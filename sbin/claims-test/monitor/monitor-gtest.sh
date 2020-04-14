#!/bin/sh

CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR
cd ../../2-claims-conf
source ./load-config.sh
cd ../../
# now in GINKGO_HOME

while [ 1 ]
do
 procid=`ps x | grep -w ./install/claimsserver | grep -v grep | awk '{print $1}'`
 if [ "$procid" = "" ]; then
  echo "claimsserver is aborted. Try to restart..."
  ./sbin/stop-all.sh
  if [ "$local_disk_mode" = "1" ]; then
  rm $data*
  fi
  if [ -d "install" ]; then
    if [ ! -f "install/claimsserver" ]; then
     ./sbin/1-compile.sh
    fi
  else
    ./sbin/1-compile.sh
  fi
  ./sbin/3-deploy.sh 
  ./sbin/start-all.sh
  sleep 3 
  cd sbin/claims-test
  ./claimstest.sh 1 1 load_tpch_sf1_1p
  cd ../../
 else
  echo "claimsserver is running..."
  ./install/test --ip $master --port $client_listener_port
 fi
done
