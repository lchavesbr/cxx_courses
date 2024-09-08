#!/bin/bash
#@file build.sh
#@author: Leonardo Anjos Chaves  @email: lchavesbr@gmail.com
#@date: 26/Jun/2024

#Build by hand

#create ./build directory
echo "Creating a build directory:"
mkdir -p build
#compile manually
echo "Compiling the ipb_arithmetic objects. Objects are in build subdirectory."
c++ -I./include -c src/subtract.cpp -o build/subtract.o
c++ -I./include -c src/sum.cpp -o build/sum.o 

#creating a static library
echo "Now it's time to make an archive (static lib) of these two objects and create your first library."
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

#build the main program
echo "Build the main program."
c++ -I./include -c src/main.cpp -o build/main.o
echo "Linking with the library."
c++ -o build/main build/main.o -L./build -lipb_arithmetic

#copying the artifacts to result folder
cp build/libipb_arithmetic.a results/lib
cp build/main results/bin

echo "Done."