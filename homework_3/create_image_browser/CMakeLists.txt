# @Description: CMakefile for Homework 3
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 12/Jul/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved

#add executable main
add_executable(create_image_browser ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
#target_include_directories(create_image_browser PUBLIC ${PROJECT_SOURCE_DIR}/include)

#tell the linker to bind these objects
target_link_libraries(create_image_browser image_browser)
