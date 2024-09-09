/**********************************************************
#@Description : Tests for ipb_algorithm Homework 4
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 25 / Jul / 2024
#@Modified : 25 / Jul / 2024
Copyright(c) 2024 Leonardo Chaves, all rights reserved
*/

#include "homework_4/named_vector.h"
#include <cstddef>
#include <gtest/gtest.h>
#include <homework_4/ipb_algorithm.h>

TEST(IPB_AlgorithmTest, Accumulate) {
  std::string test_name{"name"};
  std::vector<int> test_vector{4, 2, 3, 1};
  ipb::named_vector<int> const test_named_vector(test_name, test_vector);

  ASSERT_EQ(10, ipb::accumulate(test_named_vector));
}

TEST(IPB_AlgorithmTest, Count) {
  std::string test_name{"name"};
  std::vector<int> test_vector{4, 2, 3, 1};
  ipb::named_vector<int> const test_named_vector(test_name, test_vector);

  ASSERT_EQ(1, ipb::count(test_named_vector, 1));
}

TEST(IPB_AlgorithmTest, All_Even) {
  std::string test_name{"other name"};
  std::vector<int> test_vector{4, 2, 6, 8};
  ipb::named_vector<int> const test_named_vector(test_name, test_vector);

  ASSERT_EQ(true, ipb::all_even(test_named_vector));
}

TEST(IPB_AlgorithmTest, Clamp) {
  std::string test_name{"Grandote"};
  std::vector<int> test_vector{42, 12, 6, -18};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);

  std::vector<int> exp_vec{15, 12, 6, 0};
  ipb::named_vector<int> expected_named_vector(test_name, exp_vec);

  ipb::clamp(test_named_vector, 0, 15);

  for (std::size_t i = 0; i < exp_vec.size(); i++)
    ASSERT_EQ(test_named_vector.vector(i), expected_named_vector.vector(i));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}