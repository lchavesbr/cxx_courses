# Adapted from https://github.com/cpp-for-yourself/lectures-and-homeworks/blob/main/lectures/cmake.md

# @Description: CMakeLists file for Homework 6
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 03/Dez/2025
# Copyright (c) 2025 Leonardo Chaves, all rights reserved

cmake_minimum_required(VERSION 3.20..3.31)
project(homework_6  VERSION     0.0.1
                    DESCRIPTION "Intro to Classes C++ for Homework 6"
                    LANGUAGES    CXX)

# Define Built type to RELEASE
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Export compiler commands
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create a fake library to set cxx settings and link to propagate throught targets.
add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_23)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})

#Check with clang-format
include(cmake/ClangFormat.cmake)

#Check with cppcheck and clang-tidy during compile-time
include(cmake/StaticAnalyzers.cmake)

#Update Project Submodules:
include(cmake/UpdateSubmodules.cmake)

# Add external folder for dependencies
add_subdirectory(external)

# Add subdirectories with code
add_subdirectory(homework_6)
add_subdirectory(executables)

# Enable testing for this project
include(CTest)
add_subdirectory(tests)

# Installation
#set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/results")
#install (TARGETS create_web_app image_browser
#        RUNTIME DESTINATION bin
#        ARCHIVE DESTINATION lib)