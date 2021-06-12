#!/bin/sh

CURRDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $CURRDIR
cd ../
# now in GINKGO_HOME
./build.sh clean
./build.sh init
./build.sh init
mkdir install
cd install
../configure 

gcc --version
make -j all
