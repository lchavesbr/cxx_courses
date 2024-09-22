# @Description: CMakefile for Homework 4
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 23/Jul/2024
# @Modified: 08/Set/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#Mandatory
cmake_minimum_required(VERSION 3.20)
project(homework_4 
        VERSION 1.0
        DESCRIPTION "The C++ STL Library"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
#strictly requirement of defined cpp compiler standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#export compiler commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include (cmake/Config.cmake)
include (cmake/ClangFormat.cmake)
include (cmake/StaticAnalyzers.cmake)

# Set additional compiler flags.
set( CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wpedantic" CACHE STRING "" FORCE)
set( CMAKE_CXX_FLAGS_DEBUG "-g" CACHE STRING "" FORCE)
set( CMAKE_CXX_FLAGS_RELEASE "-O3" CACHE STRING "" FORCE)

#-Wall -Wextra shows all warnings and -Werror makes warnings an error to be treated.
#-g keep debug information in binary
#and -O sets the optimization level: {0,1,2,3}, where 0 means no optimization and 3 full optimization.

message (STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_subdirectory(src/ipb_algorithm)

#CMake will generate the tests we will create
if(PACKAGE_TESTS)

# CMake will search here for Find<pkg>.cmake files
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
  find_package(Git)   #update googletest as a git submodule during build time. 
  include (CTest)     #enable_testing()
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
