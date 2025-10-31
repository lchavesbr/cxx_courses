#Check with clang-format, cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(mat_serialization STATIC mat_serialization.cpp)
target_include_directories(mat_serialization PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(mat_serialization PUBLIC ${OpenCV_LIBS} cxx_setup)