#ifndef __RED_BLACK_TREE_REMOVE__
#define __RED_BLACK_TREE_REMOVE__

namespace s21
{

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::Remove(Key key)
    {
        TreeNode<Key, T> *tmp = (root != nullptr) ? RecursiveSearch(root, key) : nullptr;
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
            TreeNode<Key, T> *child = (!tmp->left) ? tmp->left : tmp->right;
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

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::HandleTwoChildren(TreeNode<Key, T> *tmp)
    {
        TreeNode<Key, T> *removed = tmp->left;
        while (removed->right)
        {
            removed = removed->right;
        }
        tmp->key = removed->key;
        return removed;
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::HandleChildFree(TreeNode<Key, T> *tmp)
    {
        if (tmp->color == black_node)
        {
            DelCase1(tmp);
        }
        TreeNode<Key, T> *p = tmp->parent;

        if (p->left == tmp)
        {
            p->left = nullptr;
        }
        else
        {
            p->right = nullptr;
        }
    }
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::HanldeIfChild(TreeNode<Key, T> *tmp, TreeNode<Key, T> *child)
    {
        child->parent = tmp->parent;
        TreeNode<Key, T> *p = tmp->parent;

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
    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::Sibling(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *sibling = nullptr;
        if (node && node->parent)
        {
            sibling = (node->parent->left == node) ? node->parent->right : node->parent->left;
        }
        return sibling;
    }
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase1(TreeNode<Key, T> *node)
    {
        if (node->parent)
        {
            DelCase2(node);
        }
    }
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase2(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *s = Sibling(node);
        TreeNode<Key, T> *p = node->parent;
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
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase3(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *s = Sibling(node);
        TreeNode<Key, T> *p = node->parent;

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
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase4(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *s = Sibling(node);
        TreeNode<Key, T> *p = node->parent;

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
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase5(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *s = Sibling(node);
        TreeNode<Key, T> *p = node->parent;

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
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::DelCase6(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *s = Sibling(node);
        TreeNode<Key, T> *p = node->parent;
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