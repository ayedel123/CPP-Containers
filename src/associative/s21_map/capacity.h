#ifndef __S21_MAP_CAPACITY__
#define __S21_MAP_CAPACITY__

#include "s21_map.h"

namespace s21
{
    template <typename Key, typename T>
    typename s21_map<Key, T>::size_type s21_map<Key, T>::size()
    {
        return rbtree_.size();
    }

    template <typename Key, typename T>
    typename s21_map<Key, T>::size_type s21_map<Key, T>::max_size()
    {
        return rbtree_.max_size();
    }

    template <typename Key, typename T>
    bool s21_map<Key, T>::empty()
    {
        return (rbtree_.size_) ? true : false;
    }

}

#endif
