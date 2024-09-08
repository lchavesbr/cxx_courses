#!/bin/bash
#@file install.sh
#@author: Leonardo Anjos Chaves  @email: lchavesbr@gmail.com
#@date: 26/Jun/2024

#Install script

#create ./install directory
echo "Creating a install directory:"
mkdir -p install
echo "Copying the built library and API files to install directory."
cp -R results/lib install
cp -R include install
echo "Done"