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