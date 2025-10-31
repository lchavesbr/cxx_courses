#find_package(Catch2 REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/catch2/extras)
include(CTest)
include(Catch)

enable_testing()

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_named_vector.cpp
               test_ipb_algorithm.cpp
               test_main.cpp)
target_include_directories(${TEST_BINARY} PRIVATE ${PROJECT_SOURCE_DIR}/external/catch2/extras ${PROJECT_SOURCE_DIR}/external/boost/libs/core/include/ )
target_link_libraries(${TEST_BINARY} PRIVATE ipb_algorithm Catch2::Catch2WithMain Boost::core)
catch_discover_tests(${TEST_BINARY})
