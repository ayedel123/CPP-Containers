#include "test_utils.h"

class MultisetTestCase : public ::testing::Test {};

TEST_F(MultisetTestCase, case_1) {
  s21::multiset<int> s21_multiset = {};
  std::multiset<int> std_multiset = {};
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_2) {
  s21::multiset<int> s21_multiset = {1};
  std::multiset<int> std_multiset = {1};
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_3) {
  s21::multiset<int> s21_multiset = {1, 2, 3};
  std::multiset<int> std_multiset = {1, 2, 3};
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_4) {
  s21::multiset<int> s21_multiset = {1, 2, 3};
  s21_multiset.insert(1);
  std::multiset<int> std_multiset = {1, 2, 3};
  std_multiset.insert(1);
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_5) {
  s21::multiset<int> s21_multiset = {1, 2, 3};
  s21_multiset.insert(1);
  s21_multiset.insert(-1);
  s21_multiset.insert(-2);
  s21_multiset.insert(-3);
  s21_multiset.insert(-4);
  std::multiset<int> std_multiset = {1, 2, 3};
  std_multiset.insert(1);
  std_multiset.insert(-1);
  std_multiset.insert(-2);
  std_multiset.insert(-3);
  std_multiset.insert(-4);
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_6) {
  s21::multiset<int> s21_multiset = {1, 2, 3};

  std::multiset<int> std_multiset = {1, 2, 3};

  AssertContainerEquality(s21_multiset, std_multiset);
  ASSERT_EQ(s21_multiset.contains(2),
            std_multiset.find(2) != std_multiset.end());
}

TEST_F(MultisetTestCase, case_7) {
  s21::multiset<int> s21_multiset = {1, 2, 3};

  s21::multiset<int> s21_multiset2 = s21_multiset;

  AssertContainerEquality(s21_multiset, s21_multiset2);
}

TEST_F(MultisetTestCase, case_8) {
  s21::multiset<int> s21_multiset = {1, 2, 3};

  s21::multiset<int> s21_multiset2;
  s21_multiset = s21_multiset;

  AssertContainerEquality(s21_multiset, s21_multiset2);
}

TEST_F(MultisetTestCase, case_9) {
  s21::multiset<int> s21_multiset = {1, 2, 3};

  auto p1 = s21_multiset.insert(1);
  auto p2 = s21_multiset.insert(4);
  ASSERT_EQ(p1.second, true);
  ASSERT_EQ(*(p1.first), 1);
  ASSERT_EQ(p2.second, true);
  ASSERT_EQ(*(p2.first), 4);
}

TEST_F(MultisetTestCase, case_10) {
  s21::multiset<int> s21_multiset = {1, 2, 3};

  auto i1 = s21_multiset.find(1);
  auto i2 = s21_multiset.find(4);
  auto i3 = s21_multiset.find(3);
  ASSERT_EQ(*i1, 1);
  ASSERT_EQ(*i3, 3);
  ASSERT_EQ(i2 == s21_multiset.end(), true);
}

TEST_F(MultisetTestCase, case_11) {
  s21::multiset<int> s21_multiset = {1, 2, 3, 4, 5, 6};

  std::multiset<int> std_multiset = {1, 2, 3, 4, 5, 6};
  s21_multiset.clear();
  std_multiset.clear();
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_12) {
  s21::multiset<int> s21_multiset = {1, 2, 3, 4, 5, 6};

  std::multiset<int> std_multiset = {1, 2, 3, 4, 5, 6};
  s21_multiset.erase(++(s21_multiset.begin()));
  std_multiset.erase(++(std_multiset.begin()));
  AssertContainerEquality(s21_multiset, std_multiset);
}

TEST_F(MultisetTestCase, case_13) {
  s21::multiset<int> s21_multiset1 = {1, 2, 3, 4, 5, 6};
  s21::multiset<int> s21_multiset2 = {7};
  std::multiset<int> std_multiset1 = {1, 2, 3, 4, 5, 6};
  std::multiset<int> std_multiset2 = {7};
  s21_multiset1.swap(s21_multiset2);
  std_multiset1.swap(std_multiset2);
  AssertContainerEquality(s21_multiset1, std_multiset1);
  AssertContainerEquality(s21_multiset2, std_multiset2);
}

TEST_F(MultisetTestCase, case_14) {
  s21::multiset<int> s21_multiset1 = {1, 2, 3, 4, 5, 6};
  s21::multiset<int> s21_multiset2 = {7, 9, 2};
  std::multiset<int> std_multiset1 = {1, 2, 3, 4, 5, 6};
  std::multiset<int> std_multiset2 = {7, 9, 2};
  s21_multiset1.merge(s21_multiset2);
  std_multiset1.merge(std_multiset2);
  AssertContainerEquality(s21_multiset1, std_multiset1);
  AssertContainerEquality(s21_multiset2, std_multiset2);
}