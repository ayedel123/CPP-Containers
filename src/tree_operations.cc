#include "red_black_tree.h"

void RedBlackTree::InsertRecursive(TreeNode *parent, TreeNode *child)
{
    TreeNode **tmp = (child->value < parent->value) ? &parent->left : &parent->right;

    if (*tmp == nullptr)
    {
        *tmp = child;
        child->parent = parent;
        InsCase1(child);
    }
    else if ((*tmp)->value != child->value)
    {
        InsertRecursive(*tmp, child);
    }
    return;
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

    return;
}

TreeNode *RedBlackTree::RecursiveSearch(TreeNode *parent, int value)
{
    TreeNode *result = nullptr;
    if (parent == nullptr || parent->value == value)
    {
        result = parent;
    }
    else
    {
        result = (parent->value > value) ? RecursiveSearch(parent->left, value) : RecursiveSearch(parent->right, value);
    }

    return result;
}

void RedBlackTree::DeleteElement(int value)
{
    TreeNode *node = RecursiveSearch(this->root, value);
    if (node != nullptr)
    {
        if (node->parent->left == node)
        {
            node->parent->left = nullptr;
        }
        else if (node->parent->right == node)
        {
            node->parent->right = nullptr;
        }
        node->parent = nullptr;
    }
}

void RedBlackTree::RotateLeft(TreeNode *node)
{
    TreeNode *right = node->right;

    right->parent = node->parent;
    if (node->parent)
    {
        TreeNode *p = node->parent;

        if (p->left == node)
        {
            p->left = right;
        }
        else
        {
            p->right = right;
        }
    }
    else
    {
        root = right;
    }

    node->right = right->left;
    if (right->left)
    {
        right->left->parent = node;
    }

    node->parent = right;
    right->left = node;
}

void RedBlackTree::RotateRight(TreeNode *node)
{
    TreeNode *left = node->left;

    left->parent = node->parent;
    if (node->parent)
    {
        TreeNode *p = node->parent;

        if (p->left == node)
        {
            p->left = left;
        }
        else
        {
            p->right = left;
        }
    }
    else
    {
        root = left;
    }

    node->left = left->right;
    if (left->right)
    {
        left->right->parent = node;
    }

    node->parent = left;
    left->right = node;
}

TreeNode *RedBlackTree::GetGrandpa(TreeNode *node)
{
    TreeNode *p = node->parent;
    if (p != nullptr && p->parent != nullptr)
    {
        return p->parent;
    }
    else
    {
        return nullptr;
    }
}

TreeNode *RedBlackTree::GetUncle(TreeNode *node)
{
    TreeNode *tmp = GetGrandpa(node);

    if (tmp != nullptr)
    {
        if (tmp->left == node->parent)
        {
            return tmp->right;
        }
        else
        {
            return tmp->left;
        }
    }
    else
    {
        return nullptr;
    }
}

void RedBlackTree::SwapColors()
{
}