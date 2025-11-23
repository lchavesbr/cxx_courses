#Check with clang-format, cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(compute_sift STATIC compute_sift.cpp)
target_include_directories(compute_sift PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(compute_sift PUBLIC ${OpenCV_LIBS} cxx_setup)