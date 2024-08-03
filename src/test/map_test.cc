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
    s21::map<int, int> s21_map = {{1, 2}};
    std::map<int, int> std_map = {{1, 2}};

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_3)
{
    s21::map<int, int> s21_map = {{1, 2}, {3, 2}, {4, 2}};
    std::map<int, int> std_map = {{1, 2}, {3, 2}, {4, 2}};

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_4)
{
    s21::map<int, int> s21_map = {{1, 2}, {3, 2}, {3, 2}};
    std::map<int, int> std_map = {{1, 2}, {3, 2}, {3, 2}};

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_5)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 2}, {3, 2}};
    s21_map.insert(4, 2);
    s21_map.insert(2, 2);
    std::map<int, int> std_map = {{1, 2}, {2, 2}, {3, 2}};
    std_map.insert(std::make_pair(4, 2));
    std_map.insert(std::make_pair(2, 2));

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_6)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 2}, {3, 2}};
    s21_map.insert(std::make_pair(4, 2));
    s21_map.insert(std::make_pair(2, 2));
    std::map<int, int> std_map = {{1, 2}, {2, 2}, {3, 2}};
    std_map.insert(std::make_pair(4, 2));
    std_map.insert(std::make_pair(2, 2));

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_7)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 2}, {3, 2}};
    s21_map.insert(std::make_pair(4, 2));
    s21_map.insert(std::make_pair(2, 2));
    std::map<int, int> std_map = {{1, 2}, {2, 2}, {3, 2}};
    std_map.insert(std::make_pair(2, 2));
    std_map.insert(std::make_pair(4, 2));

    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_8)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 2}, {3, 2}};
    std::map<int, int> std_map = {{1, 2}, {2, 2}, {3, 2}};

    AssertContainerEquality(s21_map, std_map);
    ASSERT_EQ(s21_map.contains(2), true);

    ASSERT_NO_THROW({
        ASSERT_EQ(s21_map.at(2), 2);
    });
}

TEST_F(MapTestCase, case_9)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 5}, {3, 2}};

    ASSERT_EQ(s21_map.at(1), 2);
    ASSERT_EQ(s21_map.at(2), 5);
}

TEST_F(MapTestCase, case_10)
{
    s21::map<int, int> s21_map1 = {{1, 2}, {2, 5}, {3, 2}};

    s21::map<int, int> s21_map2 = s21_map1;

    AssertContainerEquality(s21_map2, s21_map1);
}

TEST_F(MapTestCase, case_11)
{
    s21::map<int, int> s21_map1 = {{1, 2}, {2, 5}, {3, 2}};

    s21::map<int, int> s21_map2;

    s21_map2 = s21_map1;

    AssertContainerEquality(s21_map2, s21_map1);
}

TEST_F(MapTestCase, case_12)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 5}, {3, 2}};

    auto p1 = s21_map.insert({1, 3});
    auto p2 = s21_map.insert({14, 88});
    ASSERT_EQ(p1.second, false);
    ASSERT_EQ((*(p1.first)).first, 1);
    ASSERT_EQ((*(p1.first)).second, 2);
    ASSERT_EQ(p2.second, true);
    ASSERT_EQ((*p2.first).first, 14);
    ASSERT_EQ((*p2.first).second, 88);
}

TEST_F(MapTestCase, case_13)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 5}, {3, 2}};

    auto p1 = s21_map.insert_or_assign(1, 3);
    auto p2 = s21_map.insert_or_assign(14, 88);
    ASSERT_EQ(p1.second, false);
    ASSERT_EQ((*(p1.first)).first, 1);
    ASSERT_EQ((*(p1.first)).second, 3);
    ASSERT_EQ(p2.second, true);
    ASSERT_EQ((*(p2.first)).first, 14);
    ASSERT_EQ((*(p2.first)).second, 88);
}

TEST_F(MapTestCase, case_14)
{
    s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {4, 5}};
    ASSERT_EQ(s21_map.at(1), 2);
    ASSERT_EQ(s21_map.at(3), 4);
    ASSERT_EQ(s21_map.at(4), 5);
    ASSERT_EQ(s21_map[1], 2);
    ASSERT_EQ(s21_map[3], 4);
    ASSERT_EQ(s21_map[4], 5);
}

TEST_F(MapTestCase, case_15)
{
    s21::map<int, int> s21_map = {{1, 2}, {2, 2}, {3, 2}};
    EXPECT_THROW({ s21_map.at(4); }, std::out_of_range);
}

TEST_F(MapTestCase, case_16)
{
    s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {4, 5}};

    ASSERT_TRUE(s21_map.contains(1));
    ASSERT_TRUE(s21_map.contains(3));
    ASSERT_TRUE(s21_map.contains(4));
    ASSERT_FALSE(s21_map.contains(5));
    ASSERT_FALSE(s21_map.contains(6));
    ASSERT_FALSE(s21_map.contains(7));
}

TEST_F(MapTestCase, case_17)
{
    s21::map<int, int> s21_map = {{1, 2}, {3, 2}, {4, 2}};
    std::map<int, int> std_map = {{1, 2}, {3, 2}, {4, 2}};
    s21_map.erase(++(s21_map.begin()));
    std_map.erase(++(std_map.begin()));
    AssertContainerEquality(s21_map, std_map);
}

TEST_F(MapTestCase, case_18)
{
    s21::map<int, int> s21_map1 = {{1, 2}, {3, 2}, {4, 2}};
    s21::map<int, int> s21_map2 = {{14, 88}};
    std::map<int, int> std_map1 = {{1, 2}, {3, 2}, {4, 2}};
    std::map<int, int> std_map2 = {{14, 88}};

    s21_map1.swap(s21_map2);
    std_map1.swap(std_map2);
    AssertContainerEquality(s21_map1, std_map1);
    AssertContainerEquality(s21_map2, std_map2);
}

TEST_F(MapTestCase, case_19)
{
    s21::map<int, int> s21_map1 = {{1, 2}, {3, 2}, {4, 2}};
    s21::map<int, int> s21_map2 = {{14, 88}, {3, 2}, {5, 6}};
    std::map<int, int> std_map1 = {{1, 2}, {3, 2}, {4, 2}};
    std::map<int, int> std_map2 = {{14, 88}, {3, 2}, {5, 6}};

    s21_map1.merge(s21_map2);
    std_map1.merge(std_map2);
    AssertContainerEquality(s21_map1, std_map1);
    AssertContainerEquality(s21_map2, std_map2);
}