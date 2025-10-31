#Check with cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(test_opencv test_opencv.cpp)
target_include_directories(test_opencv PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(test_opencv PRIVATE ${OpenCV_LIBS} cxx_setup)