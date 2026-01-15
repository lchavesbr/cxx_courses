
# Avoid Static Analyzes (cppcheck and clang-tidy) into test folder.
unset (CMAKE_CXX_CPPCHECK)
unset (CMAKE_CXX_CLANG_TIDY)

# find_package(GTest REQUIRED)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)

#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/googletest/googletest/cmake)
#enable_testing()

set(TEST_BINARY ${PROJECT_NAME}_test)

    add_executable(${TEST_BINARY}
                   test_init.cpp
                   test_histogram.cpp
                   test_from_file.cpp
                   test_resize.cpp)

#    target_include_directories(${TEST_BINARY} PRIVATE ${PROJECT_SOURCE_DIR}/external/googletest/include )
    #target_link_libraries(${TEST_BINARY} PRIVATE libimage GTest::Main)
    target_link_libraries(${TEST_BINARY} PRIVATE GTest::gtest_main libimage cxx_setup)
    
    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                         ${CMAKE_CURRENT_SOURCE_DIR})
endif()