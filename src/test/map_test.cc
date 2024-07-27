#include <gtest/gtest.h>

#include <map>

#include "../s21_containers.h"

#include "test_utils.h"

class MapTestCase : public ::testing::Test
{
};

TEST_F(MapTestCase, case_1)
{
    s21::map<int, int> s21_map = {};
    std::map<int, int> std_map = {};
    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_2)
{
    s21::map<int, int> s21_map = {{1,2}};
    std::map<int, int> std_map = {{1,2}};
    
    AssertContainerEquality(s21_map, std_map);
}