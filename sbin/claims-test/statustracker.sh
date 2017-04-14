#!/bin/sh

CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR

cd ../2-claims-conf/
source ./load-config.sh
cd ../../
# now in GINKGO_HOME

timestr=$(date +%Y-%m-%d)
thisstatus=ginkgo.$timestr.status

while [ 1 ]
do

 if [ -f "$runclaimsprocid" ]; then
  claimspids=`sed '/^ginkgo=/!d;s/.*=//' $runclaimsprocid`
  if [ "$claimspids" != "" ]; then
   echo "track ginkgo pid : [$claimspids]"
   echo "========time:[$(date '+%Y-%m-%d %H:%M:%S')]========" >> $thisstatus
   cat /proc/$claimspids/status >> $thisstatus
   if [ $? -ne 0 ] ; then
     echo "ginkgo is aborted abnormally."
     break
   fi
  fi
  sleep 60
 else
  echo "ginkgo pid file does not exist."
  break
 fi

done

