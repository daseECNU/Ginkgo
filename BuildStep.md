setup steps:

1. ./build.sh init
2. mkdir build
3. cd build
4. ../configure --prefix=/your/install/path 
5. make -j8
6. make install

cleanup steps:

1  make distclean
2  ./build.sh clean

Claims info:
