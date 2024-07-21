#ifndef __RED_BLACK_TREE_DESTRUCTOR
#define __RED_BLACK_TREE_DESTRUCTOR

namespace s21
{

    template <typename Key, typename T>
    void RedBlackTree<Key, T>::~RedBlackTree()
    {
        LRNdelete(root);
    }

    void RedBlackTree<Key, T>::LRNdelete(TreeNode<Key, T> *tmp)
    {
        if (tmp != nullptr)
        {
            LRNdelete(tmp->left);
            LRNdelete(tmp->right);
            delete tmp;
            tmp = nullptr;
        }
    }

}
#endif