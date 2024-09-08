# @Description: CMakefile for Homework 3
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 12/Jul/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#create library "libhtml_writer"
add_library(html_writer STATIC
            ${PROJECT_SOURCE_DIR}/api/html_writer.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/html_writer.cpp)

#tell cmake where to look for *hpp files for a specific target
target_include_directories(html_writer PUBLIC ${PROJECT_SOURCE_DIR}/api)