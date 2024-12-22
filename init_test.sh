#!bin/bash

rm -rf build
mkdir build
cd build

cmake ../tests
make

cd ..

./build/initTest