#!/bin/bash

mkdir -p build

c++ -c -Iinclude src/subtract.cpp -o build/subtract.o
c++ -c -Iinclude src/sum.cpp -o build/sum.o

# always start the name of your library with 'lib'
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# build example program
c++ -Iinclude src/main.cpp -Lbuild -lipb_arithmetic -o build/task_2

# copying to resultd subfolder
cp build/task_2 results/bin
cp build/libipb_arithmetic.a results/lib