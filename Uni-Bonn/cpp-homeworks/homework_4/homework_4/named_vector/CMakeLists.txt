#Check with cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(named_vector INTERFACE named_vector.h)
target_link_libraries(named_vector INTERFACE cxx_setup)