# Adapted from https://github.com/cpp-for-yourself/lectures-and-homeworks/blob/main/lectures/cmake.md

# @Description: CMakefile task_1 of HW2
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 11/Oct/2025
# @Modified:
# Copyright (c) 2025 Leonardo Chaves, all rights reserved

cmake_minimum_required(VERSION 3.26..3.31)
project(task_1 VERSION 0.0.1
                    DESCRIPTION "IPB Uni-Bonn Modern C++ Course Task 1 of Homework 2"
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
target_compile_features(cxx_setup INTERFACE cxx_std_20)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})

include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

# executables
add_executable(${CMAKE_PROJECT_NAME} guessing_game.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE cxx_setup)

# 💡 Some things (e.g. tests or installation) are missing here.
# 💡 Stay tuned for these in future lectures!