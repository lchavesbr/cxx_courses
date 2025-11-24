#Check with clang-format, cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(convert_dataset STATIC convert_dataset.cpp)
target_include_directories(convert_dataset PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(convert_dataset PUBLIC ${OpenCV_LIBS} mat_serialization compute_sift cxx_setup)