# @Description: Build ipb_library and executable of ask_2 of HW1
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 11/Oct/2025
# @Modified:
# Copyright (c) 2025 Leonardo Chaves, all rights reserved

# ipb_arithmetic library
add_library(ipb_arithmetic subtract.cpp sum.cpp)
target_include_directories(ipb_arithmetic PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(ipb_arithmetic PUBLIC cxx_setup)

# executables
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ipb_arithmetic cxx_setup)
