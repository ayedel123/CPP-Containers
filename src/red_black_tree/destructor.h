#ifndef __RED_BLACK_TREE_DESTRUCTOR
#define __RED_BLACK_TREE_DESTRUCTOR

namespace s21
{

    template <typename Key>
    RedBlackTree<Key>::~RedBlackTree()
    {
        Clear();
    }

    template <typename Key>
    void RedBlackTree<Key>::Clear()
    {
        LRNdelete(root);
    }

    template <typename Key>
    void RedBlackTree<Key>::LRNdelete(TreeNode<Key> *tmp)
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