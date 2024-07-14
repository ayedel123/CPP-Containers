#include "red_black_tree.h"

void RedBlackTree::Remove(int value)
{
    TreeNode *tmp = (root != nullptr) ? RecursiveSearch(root, value) : nullptr;

    if (!tmp)
    {
        return;
    }

    if (!tmp->parent && !tmp->left && !tmp->right)
    {
        root = nullptr;
        return;
    }

    if (tmp->left && tmp->right)
    {
        tmp = HandleTwoChildren(tmp);
    }
    TreeNode *child = (!tmp->left) ? tmp->left : tmp->right;
    if (!child)
    {
        HandleChildFree(tmp);
    }

    else
    {
        HanldeIfChild(tmp, child);
    }
}

TreeNode *RedBlackTree::HandleTwoChildren(TreeNode *tmp)
{
    TreeNode *removed = tmp->left;
    while (removed->right)
    {
        removed = removed->right;
    }
    tmp->value = removed->value;
    return removed;
}

void RedBlackTree::HandleChildFree(TreeNode *tmp)
{
    if (tmp->color == black_node)
    {
        DelCase1(tmp);
    }
    TreeNode *p = tmp->parent;

    if (p->left == tmp)
    {
        p->left = nullptr;
    }
    else
    {
        p->right = nullptr;
    }
}

void RedBlackTree::HanldeIfChild(TreeNode *tmp, TreeNode *child)
{
    child->parent = tmp->parent;
    TreeNode *p = tmp->parent;

    if (tmp->parent)
    {
        if (tmp == p->left)
        {
            p->left = child;
        }
        else
        {
            p->right = child;
        }
    }
    else
    {
        root = child;
        if (tmp->color == black_node)
        {
            if (child->color == red_node)
            {
                child->color = black_node;
            }
            else
            {
                DelCase1(child);
            }
        }
    }
}

TreeNode *RedBlackTree::Sibling(TreeNode *node)
{
    TreeNode *sibling = nullptr;
    if (node && node->parent)
    {
        sibling = (node->parent->left == node) ? node->parent->right : node->parent->left;
    }
    return sibling;
}

void RedBlackTree::DelCase1(TreeNode *node)
{
    if (node->parent)
    {
        DelCase2(node);
    }
}

void RedBlackTree::DelCase2(TreeNode *node)
{
    TreeNode *s = Sibling(node);
    TreeNode *p = node->parent;
    bool scol = s ? s->color : black_node;

    if (scol == red_node)
    {
        p->color = red_node;
        s->color = black_node;

        if (node == p->left)
        {
            RotateLeft(p);
        }
        else
        {
            RotateRight(p);
        }
    }

    DelCase3(node);
}

void RedBlackTree::DelCase3(TreeNode *node)
{
    TreeNode *s = Sibling(node);
    TreeNode *p = node->parent;

    bool scol = s ? s->color : black_node;
    bool lcol = s && s->left ? s->left->color : black_node;
    bool rcol = s && s->right ? s->right->color : black_node;

    if (p->color == black_node && scol == black_node && lcol == black_node && rcol == black_node)
    {
        if (s)
        {
            s->color = red_node;
        }
        DelCase1(p);
    }
    else
    {
        DelCase4(node);
    }
}

void RedBlackTree::DelCase4(TreeNode *node)
{
    TreeNode *s = Sibling(node);
    TreeNode *p = node->parent;

    bool scol = s ? s->color : black_node;
    bool lcol = s && s->left ? s->left->color : black_node;
    bool rcol = s && s->right ? s->right->color : black_node;

    if (p->color == red_node && scol == black_node && lcol == black_node && rcol == black_node)
    {
        if (s)
        {
            s->color = red_node;
        }
        p->color = black_node;
    }
    else
    {
        DelCase5(node);
    }
}

void RedBlackTree::DelCase5(TreeNode *node)
{
    TreeNode *s = Sibling(node);
    TreeNode *p = node->parent;

    bool lcol = s->left ? s->left->color : black_node;
    bool rcol = s->right ? s->right->color : black_node;

    if (s->color == black_node)
    {
        if (node == p->left && rcol == black_node && lcol == red_node)
        {
            s->color = red_node;
            s->left->color = black_node;
            RotateRight(s);
        }
        else if (node == p->right && lcol == black_node && rcol == red_node)
        {
            s->color = red_node;
            s->right->color = black_node;
            RotateLeft(s);
        }
    }

    DelCase6(node);
}

void RedBlackTree::DelCase6(TreeNode *node)
{
    TreeNode *s = Sibling(node);
    TreeNode *p = node->parent;
    s->color = p->color;
    p->color = black_node;

    if (node == p->left)
    {
        if (s->right)
        {
            s->right->color = black_node;
        }
        RotateLeft(p);
    }
    else
    {
        if (s->left)
        {
            s->left->color = black_node;
        }
        RotateRight(p);
    }
}