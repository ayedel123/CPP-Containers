#ifndef __RED_BLACK_TREE_WALKER__
#define __RED_BLACK_TREE_WALKER__

namespace s21
{

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::GetMin(TreeNode<Key, T> *tmp)
    {
        if (tmp == nullptr)
            tmp = root;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        return tmp;
    }

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::GetMax(TreeNode<Key, T> *tmp)
    {
        if (tmp == nullptr)
            tmp = root;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        return tmp;
    }

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::Next(TreeNode<Key, T> *tmp)
    {
        TreeNode<Key, T> *result = nullptr;

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

    template <typename Key, typename T>
    TreeNode<Key, T> *RedBlackTree<Key, T>::Previous(TreeNode<Key, T> *tmp)
    {
        TreeNode<Key, T> *result = nullptr;

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