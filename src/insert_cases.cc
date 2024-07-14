#include "red_black_tree.h"

void RedBlackTree::InsCase1(TreeNode *node)
{
    if (node->parent == nullptr)
    {
        node->color = black_node;
    }
    else
    {
        InsCase2(node);
    }
}

void RedBlackTree::InsCase2(TreeNode *node)
{
    if (node->parent->color == black_node)
    {
        return;
    }
    else
    {
        InsCase3(node);
    }
}

void RedBlackTree::InsCase3(TreeNode *node)
{
    TreeNode *u = GetUncle(node);
    if (u != nullptr && u->color == red_node)
    {
        node->parent->color = black_node;
        u->color = black_node;
        TreeNode *g = GetGrandpa(node);
        g->color = red_node;
        InsCase1(g);
    }
    else
    {
        InsCase4(node);
    }
}

void RedBlackTree::InsCase4(TreeNode *node)
{
    TreeNode *g = GetGrandpa(node);
    TreeNode *tmp = node;
    TreeNode *p = node->parent;

    if (node == p->right && p == g->left)
    {
        RotateLeft(p);
        tmp = node->left;
    }
    else if (node == p->left && p == g->right)
    {
        RotateRight(p);
        tmp = node->right;
    }

    InsCase5(tmp);
}

void RedBlackTree::InsCase5(TreeNode *node)
{
    TreeNode *g = GetGrandpa(node);
    TreeNode *p = node->parent;
    p->color = black_node;
    g->color = red_node;

    if (node == p->left)
    {
        RotateRight(g);
    }
    else
    {
        RotateLeft(g);
    }
}