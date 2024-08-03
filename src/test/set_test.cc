#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

#include "test_utils.h"

class SetTestCase : public ::testing::Test
{
};

TEST_F(SetTestCase, case_1)
{
    s21::set<int> s21_set = {};
    std::set<int> std_set = {};
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_2)
{
    s21::set<int> s21_set = {1};
    std::set<int> std_set = {1};
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_3)
{
    s21::set<int> s21_set = {1, 2, 3};
    std::set<int> std_set = {1, 2, 3};
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_4)
{
    s21::set<int> s21_set = {1, 2, 3};
    s21_set.insert(1);
    std::set<int> std_set = {1, 2, 3};
    std_set.insert(1);
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_5)
{
    s21::set<int> s21_set = {1, 2, 3};
    s21_set.insert(1);
    s21_set.insert(-1);
    s21_set.insert(-2);
    s21_set.insert(-3);
    s21_set.insert(-4);
    std::set<int> std_set = {1, 2, 3};
    std_set.insert(1);
    std_set.insert(-1);
    std_set.insert(-2);
    std_set.insert(-3);
    std_set.insert(-4);
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_6)
{
    s21::set<int> s21_set = {1, 2, 3};

    std::set<int> std_set = {1, 2, 3};

    AssertContainerEquality(s21_set, std_set);
    ASSERT_EQ(s21_set.contains(2), std_set.find(2) != std_set.end());
}

TEST_F(SetTestCase, case_7)
{
    s21::set<int> s21_set = {1, 2, 3};

    s21::set<int> s21_set2 = s21_set;

    AssertContainerEquality(s21_set, s21_set2);
}

TEST_F(SetTestCase, case_8)
{
    s21::set<int> s21_set = {1, 2, 3};

    s21::set<int> s21_set2;
    s21_set = s21_set;

    AssertContainerEquality(s21_set, s21_set2);
}

TEST_F(SetTestCase, case_9)
{
    s21::set<int> s21_set = {1, 2, 3};

    auto p1 = s21_set.insert(1);
    auto p2 = s21_set.insert(4);
    ASSERT_EQ(p1.second, false);
    ASSERT_EQ(p1.first == s21_set.find(1), true);
    ASSERT_EQ(*(p1.first), 1);
    ASSERT_EQ(p2.second, true);
    ASSERT_EQ(*(p2.first), 4);
}

TEST_F(SetTestCase, case_10)
{
    s21::set<int> s21_set = {1, 2, 3};

    auto i1 = s21_set.find(1);
    auto i2 = s21_set.find(4);
    auto i3 = s21_set.find(3);
    ASSERT_EQ(*i1, 1);
    ASSERT_EQ(*i3, 3);
    ASSERT_EQ(i2 == s21_set.end(), true);
}

TEST_F(SetTestCase, case_11)
{
    s21::set<int> s21_set = {1, 2, 3, 4, 5, 6};

    std::set<int> std_set = {1, 2, 3, 4, 5, 6};
    s21_set.clear();
    std_set.clear();
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_12)
{
    s21::set<int> s21_set = {1, 2, 3, 4, 5, 6};

    std::set<int> std_set = {1, 2, 3, 4, 5, 6};
    s21_set.erase(++(s21_set.begin()));
    std_set.erase(++(std_set.begin()));
    AssertContainerEquality(s21_set, std_set);
}

TEST_F(SetTestCase, case_13)
{
    s21::set<int> s21_set1 = {1, 2, 3, 4, 5, 6};
    s21::set<int> s21_set2 = {7};
    std::set<int> std_set1 = {1, 2, 3, 4, 5, 6};
    std::set<int> std_set2 = {7};
    s21_set1.swap(s21_set2);
    std_set1.swap(std_set2);
    AssertContainerEquality(s21_set1, std_set1);
    AssertContainerEquality(s21_set2, std_set2);
}

TEST_F(SetTestCase, case_14)
{
    s21::set<int> s21_set1 = {1, 2, 3, 4, 5, 6};
    s21::set<int> s21_set2 = {7, 9, 2};
    std::set<int> std_set1 = {1, 2, 3, 4, 5, 6};
    std::set<int> std_set2 = {7, 9, 2};
    s21_set1.merge(s21_set2);
    std_set1.merge(std_set2);
    AssertContainerEquality(s21_set1, std_set1);
    AssertContainerEquality(s21_set2, std_set2);
}