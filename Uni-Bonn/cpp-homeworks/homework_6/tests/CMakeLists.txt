#find_package(GTest REQUIRED)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    set(TEST_BINARY ${PROJECT_NAME}_test)

    add_executable(${TEST_BINARY}
                   test_init.cpp
                   test_histogram.cpp
                   test_from_file.cpp
                   test_resize.cpp)

    target_link_libraries(${TEST_BINARY} image GTest::Main)
    
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                         ${CMAKE_CURRENT_SOURCE_DIR})
endif()