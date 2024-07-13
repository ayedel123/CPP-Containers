#include "red_black_tree.h"

void RedBlackTree::InsertRecursive(TreeNode *parent, TreeNode *child)
{
    if (child->value < parent->value)
    {
        if (parent->left_node == nullptr)
        {
            parent->left_node = child;
        }
        else
        {
            InsertRecursive(parent->left_node, child);
        }
    }
    else if (child->value > parent->value)
    {
        if (parent->right_node == nullptr)
        {
            parent->right_node = child;
        }
        else
        {
            InsertRecursive(parent->right_node, child);
        }
    }
    else
    {
        std::cout << "same elements";
    }
}

void RedBlackTree::InsertNode(int value)
{
    TreeNode *newNode = new TreeNode(value);

    if (root == nullptr)
    {
        root = newNode;
        root->color = black_node;
    }
    else
    {
        InsertRecursive(root, newNode);
    }
}

TreeNode *RedBlackTree::RecursiveSearch(TreeNode *parent, int value)
{
    TreeNode *result = nullptr;
    if (parent == nullptr || parent->value == value)
    {
        result = parent;
    }
    else if (parent->value < value)
    {
        result = RecursiveSearch(parent->left_node, value);
    }
    else if (parent->value > value)
    {
        result = RecursiveSearch(parent->right_node, value);
    }
    return result;
}

void RedBlackTree::DeleteElement(int value)
{
    TreeNode *node = RecursiveSearch(this->root, value);
    if (node != nullptr)
    {
        if (node->parent->left_node == node)
        {
            node->parent->left_node = nullptr;
        }
        else if (node->parent->right_node == node)
        {
            node->parent->right_node = nullptr;
        }
        node->parent = nullptr;
    }
}

void RedBlackTree::TurnLeft(TreeNode *node)
{
    TreeNode *pivot = node->right_node;

    pivot->parent = node->parent;
    if (node->parent != nullptr)
    {
        if (node->parent->left_node == node)
            node->parent->left_node = pivot;
        else
            node->parent->left_node = pivot;
    }

    node->left_node = pivot->left_node;
    if (pivot->left_node != nullptr)
        pivot->left_node->parent = node;

    node->parent = pivot;
    pivot->left_node = node;
}

void RedBlackTree::TurnRight(TreeNode *node)
{
    TreeNode *pivot = node->left_node;

    pivot->parent = node->parent;
    if (node->parent != nullptr)
    {
        if (node->parent->left_node == node)
            node->parent->left_node = pivot;
        else
            node->parent->right_node = pivot;
    }

    node->left_node = pivot->right_node;
    if (pivot->right_node != nullptr)
        pivot->right_node->parent = node;

    node->parent = pivot;
    pivot->right_node = node;
}

void RedBlackTree::SwapColors()
{
}