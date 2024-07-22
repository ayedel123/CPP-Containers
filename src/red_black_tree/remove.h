#ifndef __RED_BLACK_TREE_REMOVE__
#define __RED_BLACK_TREE_REMOVE__

namespace s21
{

    template <typename Key>
    void RedBlackTree<Key>::Remove(Key key)
    {
        TreeNode<Key> *tmp = (root != nullptr) ? RecursiveSearch(root, key) : nullptr;
        bool end = false;
        if (!tmp)
        {
            end = true;
        }
        size_--;
        if (!end && !tmp->parent && !tmp->left && !tmp->right)
        {

            root = nullptr;
            end = true;
        }
        if (!end)
        {
            if (tmp->left && tmp->right)
            {
                tmp = HandleTwoChildren(tmp);
            }
            TreeNode<Key> *child = (!tmp->left) ? tmp->left : tmp->right;
            if (!child)
            {
                HandleChildFree(tmp);
            }

            else
            {
                HanldeIfChild(tmp, child);
            }
        }
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::HandleTwoChildren(TreeNode<Key> *tmp)
    {
        TreeNode<Key> *removed = tmp->left;
        while (removed->right)
        {
            removed = removed->right;
        }
        tmp->key = removed->key;
        return removed;
    }

    template <typename Key>
    void RedBlackTree<Key>::HandleChildFree(TreeNode<Key> *tmp)
    {
        if (tmp->color == black_node)
        {
            DelCase1(tmp);
        }
        TreeNode<Key> *p = tmp->parent;

        if (p->left == tmp)
        {
            p->left = nullptr;
        }
        else
        {
            p->right = nullptr;
        }
    }
    template <typename Key>
    void RedBlackTree<Key>::HanldeIfChild(TreeNode<Key> *tmp, TreeNode<Key> *child)
    {
        child->parent = tmp->parent;
        TreeNode<Key> *p = tmp->parent;

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
    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::Sibling(TreeNode<Key> *node)
    {
        TreeNode<Key> *sibling = nullptr;
        if (node && node->parent)
        {
            sibling = (node->parent->left == node) ? node->parent->right : node->parent->left;
        }
        return sibling;
    }
    template <typename Key>
    void RedBlackTree<Key>::DelCase1(TreeNode<Key> *node)
    {
        if (node->parent)
        {
            DelCase2(node);
        }
    }
    template <typename Key>
    void RedBlackTree<Key>::DelCase2(TreeNode<Key> *node)
    {
        TreeNode<Key> *s = Sibling(node);
        TreeNode<Key> *p = node->parent;
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
    template <typename Key>
    void RedBlackTree<Key>::DelCase3(TreeNode<Key> *node)
    {
        TreeNode<Key> *s = Sibling(node);
        TreeNode<Key> *p = node->parent;

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
    template <typename Key>
    void RedBlackTree<Key>::DelCase4(TreeNode<Key> *node)
    {
        TreeNode<Key> *s = Sibling(node);
        TreeNode<Key> *p = node->parent;

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
    template <typename Key>
    void RedBlackTree<Key>::DelCase5(TreeNode<Key> *node)
    {
        TreeNode<Key> *s = Sibling(node);
        TreeNode<Key> *p = node->parent;

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
    template <typename Key>
    void RedBlackTree<Key>::DelCase6(TreeNode<Key> *node)
    {
        TreeNode<Key> *s = Sibling(node);
        TreeNode<Key> *p = node->parent;
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

}

#endif