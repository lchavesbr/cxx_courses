#@Description : CMakeList file for including GTest framework in Homerowk 4
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 25 / Jul / 2024
#@Modified : 25 / Jul / 2024
#Copyright(c) 2024 Leonardo Chaves, all rights reserved

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG         release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(ipb_algorithm_test ipb_algorithm_test.cpp)
target_link_libraries(ipb_algorithm_test PRIVATE
                        GTest::GTest
                        ipb_algorithm)

add_test(ipb_algorithm_gtest ipb_algorithm_test)