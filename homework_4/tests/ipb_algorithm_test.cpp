/**********************************************************
#@Description : Tests for ipb_algorithm Homework 4
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 25 / Jul / 2024
#@Modified : 25 / Jul / 2024
Copyright(c) 2024 Leonardo Chaves, all rights reserved
*/

#include <homework_4/named_vector.h>
#include <homework_4/ipb_algorithm.h>

#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
#include <string>

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

TEST(IPB_AlgorithmTest, Fill) {
  std::string test_name{"Grandote"};
  std::vector<int> test_vector{42, 12, 6, -18};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);

  std::vector<int> exp_vec{-99, -99, -99, -99};
  ipb::named_vector<int> expected_named_vector(test_name, exp_vec);

  ipb::fill(test_named_vector, -99);

  for (std::size_t i = 0; i < exp_vec.size(); i++)
    ASSERT_EQ(test_named_vector.vector(i), expected_named_vector.vector(i));
}

TEST(IPB_AlgorithmTest, Find) {
  std::string test_name{"name"};
  std::vector<int> test_vector{4, 2, 1, 3};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);

  ASSERT_EQ(ipb::find(test_named_vector, 1), true);
}

TEST(IPB_AlgorithmTest, Print) {
  std::string test_name{"Jose Luis"};
  std::vector<int> test_vector{1, 2, 3, 4};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);
  //ASSERT_EQ(ipb::print(test_named_vector), "Jose Luis, 1, 2, 3, 4\n");
}

TEST(IPB_AlgorithmTest, TOUPPER) {
  std::string test_name{"Jose Luis"};
  std::vector<int> test_vector{1, 2, 3, 4};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);
  ASSERT_EQ(ipb::toupper(test_named_vector), "JOSE LUIS");
}

TEST(IPB_AlgorithmTest, SORT) {
  std::string test_name{"any name"};
  std::vector<int> test_vector{15, 12, 6, 0};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);
  test_named_vector.set_vector(ipb::sort(test_named_vector));

  std::vector<int> expected_vector{0,6,12,15};
  for (std::size_t i = 0; i < expected_vector.size(); i++)
    ASSERT_EQ(test_named_vector.vector(i), expected_vector[i]);
}

TEST(IPB_AlgorithmTest, ROTATE) {
  std::string test_name{"any name"};
  std::vector<int> test_vector{0, 6, 12, 15};
  ipb::named_vector<int> test_named_vector(test_name, test_vector);
  test_named_vector.set_vector(ipb::rotate(test_named_vector));
  //ipb::print(test_named_vector);
  std::vector<int> expected_vector{12,15,0,6};
  for (std::size_t i = 0; i < expected_vector.size(); i++)
    ASSERT_EQ(test_named_vector.vector(i), expected_vector[i]);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}