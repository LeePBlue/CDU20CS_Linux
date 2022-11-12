#!/bin/bash
gcc ./*.c  -fPIC -shared -o libdirtest2.so
cp libdirtest2.so /usr/lib
make
./main $1 $2

