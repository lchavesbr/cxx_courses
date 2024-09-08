# @Description: CMakefile for Homework 3
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 12/Jul/2024
# @Modified: 21/Jul/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#Mandatory
cmake_minimum_required(VERSION 3.20)
project(homework_3 VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

#export compiler commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CMake will search here for Find<pkg>.cmake files
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
find_package(ClangFormat)
find_package(StaticAnalyzers)

#set CMake build type if it is not set
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Set additional flags.
set( CMAKE_CXX_FLAGS "-Wall -Wextra")
#-Wall - Wextra shows all warnings
set( CMAKE_CXX_FLAGS_DEBUG "-g")
#-g keep debug information in binary and -O sets the optimization level
#{0,1,2,3}, where 0 means no optimization and 3 full optimization.

#create library "libhtml_writer"
add_subdirectory(html_writer)
#create library "libimage_browser"
add_subdirectory(image_browser)

#create executable "create_image_browser"
add_subdirectory(create_image_browser)

#set local install directory in projects path, instead of default /usr/bin
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/results)

#install static lib
install(TARGETS html_writer
        ARCHIVE DESTINATION lib)

#install static lib
install(TARGETS image_browser
        ARCHIVE DESTINATION lib)
#install binary file
install (TARGETS create_image_browser
        RUNTIME DESTINATION bin)