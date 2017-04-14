#!/bin/sh

CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR
cd ../../2-claims-conf
source ./load-config.sh
cd ../../
# now in GINKGO_HOME
while [ 1 ]
do
 procid=`ps x | grep -w ./install/ginkgo | grep -v grep | awk '{print $1}'`
 if [ "$procid" = "" ]; then
  ((loops++))
  echo "ginkgo is aborted [$(date '+%Y-%m-%d %H:%M:%S')] [$loops] times. Try to restart..." >> guizhoutest.log
  ./sbin/claims-test/claimsforgz.sh > /dev/null 2>&1 & 
  sleep 3 
 else
  echo "ginkgo is running..."
  cd sbin/claims-test/
#  read -p "Hit the ENTER |__>" tempuseless
#  echo $tempuseless
   ./claimstest.sh 1 1 huishuiQ2
  cd ../../
  # now in GINKGO_HOME
 fi
done
