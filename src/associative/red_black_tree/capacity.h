#ifndef __RED_BLACK_TREE_CAPACITY__
#define __RED_BLACK_TREE_CAPACITY__

namespace s21
{
    template <typename Key>
    typename RBTree<Key>::size_type RBTree<Key>::size() const
    {
        return size_;
    }

    template <typename Key>
    bool RBTree<Key>::empty() const
    {
        return (size() == 0) ? true : false;
    }

    template <typename Key>
    typename RBTree<Key>::size_type RBTree<Key>::max_size() const
    {
        return std::numeric_limits<difference_type>::max() /
               sizeof(Node<Key>);
    }
}

#endif