#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_CAPACITY_H_

#include "s21_set.h"

namespace s21
{
    template <typename Key>
    typename set<Key>::size_type set<Key>::size() const
    {
        return rbtree_.Size();
    }

    template <typename Key>
    typename set<Key>::size_type set<Key>::max_size() const
    {
        return rbtree_.MaxSize();
    }

    template <typename Key>
    bool set<Key>::empty() const
    {
        return rbtree_.Empty();
    }

}

#endif
