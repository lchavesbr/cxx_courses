# @Description: CMakefile for Homework 3
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 12/Jul/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#create library "libimage_browser"
add_library(image_browser STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/image_browser.cpp)

target_link_libraries(image_browser PUBLIC html_writer)

#tell cmake where to look for *hpp files for a specific target
target_include_directories(image_browser PUBLIC ${PROJECT_SOURCE_DIR}/api)


