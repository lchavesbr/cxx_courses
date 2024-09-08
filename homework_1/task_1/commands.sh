#!/bin/bash
#Author: Leonardo Anjos Chaves  email: lchavesbr@gmail.com
#Date: 26/Jun/2024

#print number of lines in file
wc -l data.dat

#print number of lines containing ´dolor´ or ´dalor´
cat data.dat | grep -e 'd[a|o]lor' | wc -l

#print number of words in data.dat
wc -w data.dat

#print number of words starting with mol
cat data.dat | grep -e 'mol*' | wc -w