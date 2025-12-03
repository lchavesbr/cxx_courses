#Check with cppcheck and clang-tidy during compile-time
include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(serialize serialize.cpp)
target_include_directories(serialize PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(serialize PRIVATE ${OpenCV_LIBS} mat_serialization compute_sift cxx_setup)

add_executable(deserialize deserialize.cpp)
target_include_directories(deserialize PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(deserialize PRIVATE ${OpenCV_LIBS} mat_serialization compute_sift cxx_setup)

add_executable(convert convert.cpp)
target_link_libraries(convert PRIVATE convert_dataset cxx_setup)

add_executable(load_dataset load_dataset.cpp)
target_link_libraries(load_dataset PRIVATE convert_dataset cxx_setup)