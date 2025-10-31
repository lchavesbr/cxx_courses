#Check with cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(hw4_example hw4_example.cpp)
target_link_libraries(hw4_example PRIVATE ipb_algorithm named_vector cxx_setup)