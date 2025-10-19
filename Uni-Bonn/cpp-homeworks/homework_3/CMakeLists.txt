cmake_minimum_required(VERSION 3.16..3.31)
project(image_browser_webapp  VERSION     0.0.1
                    DESCRIPTION "Image Brower Web Application from Homework 3"
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
target_compile_features(cxx_setup INTERFACE cxx_std_20)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})


include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

add_subdirectory(homework_3)
add_subdirectory(executables)

# Installation
set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/results")
install (TARGETS create_web_app image_browser
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib)