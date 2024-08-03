#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

#include "test_utils.h"

class RBTreeTest : public ::testing::Test
{
};

TEST_F(RBTreeTest, insert_case_0)
{
    using namespace s21;
    RBTree<int> rbtree1 = RBTree<int>();
    std::set<Node<int>> set = std::set<Node<int>>();

    AssertTreeEquality(rbtree1, set);
}

TEST_F(RBTreeTest, insert_case_1)
{
    using namespace s21;
    RBTree<int> rbtree1 = RBTree<int>();
    std::set<Node<int>> set = std::set<Node<int>>();
    rbtree1.InsertNode(1);
    int rbtree2_val[1] = {1};
    set.insert(Node<int>{&(rbtree2_val[0]), nullptr, nullptr, nullptr});
    AssertTreeEquality(rbtree1, set);
}

TEST_F(RBTreeTest, insert_case_2)
{
    using namespace s21;
    RBTree<int> rbtree1 = RBTree<int>();
    std::set<Node<int>> set = std::set<Node<int>>();
    rbtree1.InsertNode(1);
    rbtree1.InsertNode(2);
    int rbtree2_val[2] = {1, 2};
    Node<int> nodes[2];
    nodes[0] = Node<int>{&(rbtree2_val[0]), nullptr, nullptr, nullptr, black_node};
    nodes[1] = Node<int>{&(rbtree2_val[1]), nullptr, nullptr, &(nodes[0]), red_node};
    nodes[0].right = &(nodes[1]);
    set.insert(nodes[0]);
    set.insert(nodes[1]);
    AssertTreeEquality(rbtree1, set);
}

TEST_F(RBTreeTest, insert_case_3)
{
    using namespace s21;
    RBTree<int> rbtree1 = RBTree<int>();
    std::set<Node<int>> set = std::set<Node<int>>();
    rbtree1.InsertNode(10);
    rbtree1.InsertNode(9);
    rbtree1.InsertNode(11);
    rbtree1.InsertNode(8);
    int rbtree2_val[4] = {8, 9, 10, 11};
    Node<int> nodes[4];
    nodes[0] = Node<int>{&(rbtree2_val[0]), nullptr, nullptr, &(nodes[1]), red_node};
    nodes[1] = Node<int>{&(rbtree2_val[1]), &(nodes[0]), nullptr, &(nodes[2]), black_node};
    nodes[2] = Node<int>{&(rbtree2_val[2]), nullptr, nullptr, &(nodes[3]), black_node};
    nodes[3] = Node<int>{&(rbtree2_val[3]), &(nodes[1]), &(nodes[2]), nullptr, black_node};

    set.insert(nodes[0]);
    set.insert(nodes[1]);
    set.insert(nodes[2]);
    set.insert(nodes[3]);
    AssertTreeEquality(rbtree1, set);
}