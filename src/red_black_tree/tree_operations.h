#ifndef __RED_BLACK_TREE_OPERATIONS
#define __RED_BLACK_TREE_OPERATIONS

namespace s21
{

    template <typename Key>
    typename RedBlackTree<Key>::iterator RedBlackTree<Key>::Find(const Key &key)
    {
        TreeNode<Key> *tmp = RecursiveSearch(root, key);

        return (tmp)
                   ? RedBlackTree<Key>::iterator(*tmp, this)
                   : end();
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::RecursiveSearch(TreeNode<Key> *parent, Key key)
    {
        TreeNode<Key> *result = nullptr;
        if (parent == nullptr || Equal(parent->key, key))
        {
            result = parent;
        }
        else
        {
            result = (Less(key, parent->key)) ? RecursiveSearch(parent->left, key) : RecursiveSearch(parent->right, key);
        }

        return result;
    }

    template <typename Key>
    void RedBlackTree<Key>::RotateLeft(TreeNode<Key> *node)
    {
        TreeNode<Key> *right = node->right;

        right->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key> *p = node->parent;

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
    template <typename Key>
    void RedBlackTree<Key>::RotateRight(TreeNode<Key> *node)
    {
        TreeNode<Key> *left = node->left;

        left->parent = node->parent;
        if (node->parent)
        {
            TreeNode<Key> *p = node->parent;

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
    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetGrandpa(TreeNode<Key> *node)
    {
        TreeNode<Key> *p = node->parent;
        if (p != nullptr && p->parent != nullptr)
        {
            return p->parent;
        }
        else
        {
            return nullptr;
        }
    }
    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetUncle(TreeNode<Key> *node)
    {
        TreeNode<Key> *tmp = GetGrandpa(node);

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