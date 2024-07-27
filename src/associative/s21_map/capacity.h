#ifndef __S21_MAP_CAPACITY__
#define __S21_MAP_CAPACITY__

#include "map.h"

namespace s21
{
    template <typename Key, typename T>
    typename map<Key, T>::size_type map<Key, T>::size()
    {
        return rbtree_.size();
    }

    template <typename Key, typename T>
    typename map<Key, T>::size_type map<Key, T>::max_size()
    {
        return rbtree_.max_size();
    }

    template <typename Key, typename T>
    bool map<Key, T>::empty()
    {
        return (rbtree_.size_) ? true : false;
    }

}

#endif
