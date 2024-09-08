#Mandatory
cmake_minimum_required(VERSION 3.10)
project(homework_1_task_2)
set(CMAKE_CXX_STANDARD 17)

# Set additional flags.
set( CMAKE_CXX_FLAGS "-Wall -Wextra ") 
#-Wall - Wextra shows all warnings
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0")
#-g keep debug information in binary and -O sets the optimization level
#{0,1,2,3}, where 0 means no optimization and 3 full optimization.

#tell cmake where to look for *hpp files
#include_directories(./include)

#create library "libipb_arithmetic"
add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)

target_include_directories(ipb_arithmetic PUBLIC
                            ./include
)
#add executable main
add_executable(main src/main.cpp)

#tell the linker to bind these objects
target_link_libraries(main ipb_arithmetic)

#set local install directory in projects path, instead of default /usr/bin
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

install(TARGETS ipb_arithmetic
        ARCHIVE DESTINATION lib
)
install (DIRECTORY include
        DESTINATION ${CMAKE_INSTALL_PREFIX}
)