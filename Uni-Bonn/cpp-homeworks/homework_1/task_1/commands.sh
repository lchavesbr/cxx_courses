#!/bin/bash
# @file     commands.sh
# @author   Leonardo Chaves     [lchavesbr@gmail.com]
#
# Copyright (c) 2025 Leonardo Chaves, all rights reserved
# Description: Task 1 of Homework 1

echo "Total lines:"
cat data.dat | wc -l

echo "Total lines contains dolor or dalor:"
cat data.dat | grep "d[a-o]lor" | wc -l

echo "Total words:"
cat data.dat | wc -w

echo "Total words starts with mol:"
cat data.dat | grep "mol*" | wc -w