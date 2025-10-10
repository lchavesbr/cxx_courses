# Adapted from https://github.com/cpp-for-yourself/lectures-and-homeworks/blob/main/lectures/cmake.md

# @Description: CMakefile task_2 of HW1
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 10/Oct/2025
# @Modified:
# Copyright (c) 2025 Leonardo Chaves, all rights reserved

cmake_minimum_required(VERSION 3.16..3.24)
project(task_2 VERSION 0.0.1
                    DESCRIPTION "IPB Uni-Bonn Modern C++ Course Task 2 of Homework 1"
                    LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

#export compiler commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# create a fake library to set cxx settings and compiler flags
add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_17)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})

# ipb_arithmetic library
add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)
target_include_directories(ipb_arithmetic PUBLIC include)
target_link_libraries(ipb_arithmetic PUBLIC cxx_setup)

# executables
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ipb_arithmetic cxx_setup)

#
# 🚨 Make sure CMakeLists.txt file exists in the subdirectories!
#add_subdirectory(${PROJECT_NAME})
#add_subdirectory(executables)

# 💡 Some things (e.g. tests or installation) are missing here.
# 💡 Stay tuned for these in future lectures!