#ifndef __RED_BLACK_TREE_OPERATIONS
#define __RED_BLACK_TREE_OPERATIONS

namespace s21
{

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::RecursiveSearch(TreeNode<Key, T> *parent, Key key)
    {
        TreeNode<Key, T> *result = nullptr;
        if (parent == nullptr || parent->value == key)
        {
            result = parent;
        }
        else
        {
            result = (key < parent->key) ? RecursiveSearch(parent->left, key) : RecursiveSearch(parent->right, key);
        }

        return result;
    }

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::RotateLeft(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *right = node->right;

        right->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key, T> *p = node->parent;

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
    template <typename Key, typename T>
    void RedBlackTree<Key, T>::RotateRight(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *left = node->left;

        left->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key, T> *p = node->parent;

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
    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::GetGrandpa(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *p = node->parent;
        if (p != nullptr && p->parent != nullptr)
        {
            return p->parent;
        }
        else
        {
            return nullptr;
        }
    }
    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::GetUncle(TreeNode<Key, T> *node)
    {
        TreeNode<Key, T> *tmp = GetGrandpa(node);

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

}

#endif