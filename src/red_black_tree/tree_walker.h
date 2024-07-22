#ifndef __RED_BLACK_TREE_WALKER__
#define __RED_BLACK_TREE_WALKER__

namespace s21
{

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetMin(TreeNode<Key> *tmp)
    {
        if (tmp == nullptr)
            tmp = root;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        return tmp;
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::GetMax(TreeNode<Key> *tmp)
    {
        if (tmp == nullptr)
            tmp = root;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }
        return tmp;
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::Next(TreeNode<Key> *tmp)
    {
        TreeNode<Key> *result = nullptr;

        if (tmp->right)
        {
            result = GetMin(tmp->right);
        }
        else
        {
            result = tmp->parent;
            while (result && tmp == result->right)
            {
                tmp = result;
                result = tmp->parent;
            }
        }

        return result;
    }

    template <typename Key>
    TreeNode<Key> *RedBlackTree<Key>::Previous(TreeNode<Key> *tmp)
    {
        TreeNode<Key> *result = nullptr;

        if (tmp->left)
        {
            result = GetMax(tmp->right);
        }
        else
        {
            result = tmp->parent;
            while (result && tmp == result->left)
            {
                tmp = result;
                result = tmp->parent;
            }
        }

        return result;
    }

}

#endif