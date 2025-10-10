#!/bin/bash
#
# @Description: Shell script to build task_2 of HW1
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 10/Oct/2025
# @Modified:
# Copyright (c) 2025 Leonardo Chaves, all rights reserved

mkdir -p build

c++ -c -Iinclude src/subtract.cpp -o build/subtract.o
c++ -c -Iinclude src/sum.cpp -o build/sum.o

# always start the name of your library with 'lib'
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# build example program
c++ -Iinclude src/main.cpp -Lbuild -lipb_arithmetic -o build/task_2