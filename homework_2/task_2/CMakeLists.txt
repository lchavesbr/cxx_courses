# @Description: CMakefile for Homework 2 Task 2
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 10/Jul/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#Mandatory
cmake_minimum_required(VERSION 3.10)
project(homework_2_task_2)
set(CMAKE_CXX_STANDARD 20)

# CMake will search here for Find<pkg>.cmake files
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
find_package(ClangFormat)
find_package(StaticAnalyzers)

#set CMake build type if it is not set
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Set additional flags.
set( CMAKE_CXX_FLAGS "-Wall -Wextra ") 
#-Wall - Wextra shows all warnings
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#-g keep debug information in binary and -O sets the optimization level
#{0,1,2,3}, where 0 means no optimization and 3 full optimization.

#tell cmake where to look for *hpp files for a specific target
#target_include_directories(ipb_arithmetic PUBLIC
#                            ./include
#)

#create library "libipb_arithmetic"
#add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)


#add executable main
add_executable(task_2 ${PROJECT_SOURCE_DIR}/src/main.cpp)

#tell the linker to bind these objects
#target_link_libraries(main ipb_arithmetic)

#set local install directory in projects path, instead of default /usr/bin
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

#install static lib
#install(TARGETS ipb_arithmetic
#        ARCHIVE DESTINATION lib
#)
#install include directory
#install (DIRECTORY include
#        DESTINATION ${CMAKE_INSTALL_PREFIX}
#)
#install binary file
install (TARGETS task_2
        RUNTIME DESTINATION bin)