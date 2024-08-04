#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_CAPACITY_H_

namespace s21
{
    template <typename Key>
    typename RBTree<Key>::size_type RBTree<Key>::Size() const
    {
        return size_;
    }

    template <typename Key>
    bool RBTree<Key>::Empty() const
    {
        return (Size() == 0) ? true : false;
    }

    template <typename Key>
    typename RBTree<Key>::size_type RBTree<Key>::MaxSize() const
    {
        return std::numeric_limits<difference_type>::max() /
               sizeof(Node<Key>);
    }
}

#endif