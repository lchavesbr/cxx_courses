# @Description: Configuration for CMake
# @Author: Leonardo Anjos Chaves        [lchavesbr@gmail.com]
# @Date: 09/Set/2024
# @Modified: 09/Set/2024
#  Copyright (c) 2024 Leonardo Chaves, all rights reserved



option (ENABLE_BUILDTYPE_MODE "Selects which mode the build is based: Debug or Release." ON)
set(MY_BUILD_TYPE "Release") #Options: Debug or Release

#set CMake build type if it is not set
if (NOT CMAKE_BUILD_TYPE)
if(ENABLE_BUILDTYPE_MODE)    
set(CMAKE_BUILD_TYPE ${MY_BUILD_TYPE} CACHE STRING "" FORCE)  
endif()
endif()

#Enable testing framework
option(PACKAGE_TESTS "Build the tests" ON)