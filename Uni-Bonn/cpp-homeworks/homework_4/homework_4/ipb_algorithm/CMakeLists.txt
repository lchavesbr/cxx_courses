#Check with cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(ipb_algorithm STATIC ipb_algorithm.cpp)
target_link_libraries(ipb_algorithm PUBLIC named_vector cxx_setup)