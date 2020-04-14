#!/bin/sh

CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR
cd ../../2-claims-conf
source ./load-config.sh
cd ../../
# now in GINKGO_HOME
while [ 1 ]
do
 procid=`ps x | grep -w ./install/ ginkgoserver | grep -v grep | awk '{print $1}'`
 if [ "$procid" = "" ]; then
  ((loops++))
  echo " ginkgoserver is aborted [$(date '+%Y-%m-%d %H:%M:%S')] [$loops] times. Try to restart..." >> ./sbin/claims-test/gtestfor.loops
  echo " ginkgoserver is aborted [$(date '+%Y-%m-%d %H:%M:%S')] [$loops] times. Try to restart..." >> ./sbin/claims-test/gtestfor.log
#  ./sbin/claims-test/claimsforgz.sh > /dev/null 2>&1 & 
  ./sbin/stop-all.sh
  sleep 3
  ./sbin/start-all.sh
  sleep 3 
  ttimes=0
 else
  ((ttimes++))
  echo "[$ttimes][$(date '+%Y-%m-%d %H:%M:%S')]  ginkgoserver is running..."
  echo "[$ttimes][$(date '+%Y-%m-%d %H:%M:%S')]  ginkgoserver is running..." >> ./sbin/claims-test/gtestfor.loops
  cd sbin/claims-test/
#  read -p "Hit the ENTER |__>" tempuseless
#  echo $tempuseless
   ./claimstestnr.sh 1 20 gtestfor >> gtestfor.log
  cd ../../
  # now in GINKGO_HOME
 fi
done
