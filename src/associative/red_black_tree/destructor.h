#ifndef __RED_BLACK_TREE_DESTRUCTOR
#define __RED_BLACK_TREE_DESTRUCTOR

namespace s21
{

    template <typename Key>
    RBTree<Key>::~RBTree()
    {
        Clear();
    }

    template <typename Key>
    void RBTree<Key>::Clear()
    {
        LRNdelete(root);
        root = nullptr;
        size_ = 0;
    }

    template <typename Key>
    void RBTree<Key>::LRNdelete(Node<Key> *tmp)
    {
        if (tmp != nullptr)
        {
            LRNdelete(tmp->left);
            LRNdelete(tmp->right);
            DeleteNode(tmp);
            tmp = nullptr;
        }
    }

}
#endif