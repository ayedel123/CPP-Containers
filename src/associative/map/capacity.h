#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_CAPACITY_H_

#include "map.h"

namespace s21
{
    template <typename Key, typename T>
    typename map<Key, T>::size_type map<Key, T>::size() const
    {
        return rbtree_.Size();
    }

    template <typename Key, typename T>
    typename map<Key, T>::size_type map<Key, T>::max_size() const
    {
        return rbtree_.MaxSize();
    }

    template <typename Key, typename T>
    bool map<Key, T>::empty() const
    {
        return rbtree_.Empty();
    }

}

#endif
