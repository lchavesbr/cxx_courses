# Adapted from https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html

# @Description: CMakefile for Homework 4
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 23/Jul/2024
# @Modified: 08/Set/2024
# Copyright (c) 2024 Leonardo Chaves, all rights reserved

#Mandatory
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.15...3.30)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(homework_4 
        VERSION 1.0
        DESCRIPTION "The C++ STL Library"
        LANGUAGES CXX)

include(CMakePrintHelpers)
# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build Type" FORCE)
endif()
cmake_print_variables(CMAKE_BUILD_TYPE)
        
set(CMAKE_CXX_STANDARD 17)
#strictly requirement of defined cpp compiler standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#export compiler commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#include (cmake/Config.cmake)
#include (cmake/ClangFormat.cmake)
#include (cmake/StaticAnalyzers.cmake)

# Set additional compiler flags.
set( CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wpedantic" CACHE STRING "" FORCE)
#set( CMAKE_CXX_FLAGS_DEBUG "-g" CACHE STRING "" FORCE)
#set( CMAKE_CXX_FLAGS_RELEASE "-O3" CACHE STRING "" FORCE)

#-Wall -Wextra shows all warnings and -Werror makes warnings an error to be treated.
#-g keep debug information in binary
#and -O sets the optimization level: {0,1,2,3}, where 0 means no optimization and 3 full optimization.

# Find packages go here.
find_package(Git QUIET)
if (GIT_FOUND)
include(cmake/UpdateGitSubmodule.cmake) #update googletest as a git submodule during build time. 
endif()

add_subdirectory(src/ipb_algorithm)

# Enable Testing based on GoogleTest Framework, which is added as git submodule. 
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    include(CTest)     #enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()


#set local install directory in projects path, instead of default /usr/bin
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/results)

#install static lib
#install(TARGETS html_writer
#        ARCHIVE DESTINATION lib)

#install static lib
#install(TARGETS image_browser
#        ARCHIVE DESTINATION lib)
#install binary file
#install (TARGETS create_image_browser
#        RUNTIME DESTINATION bin)
