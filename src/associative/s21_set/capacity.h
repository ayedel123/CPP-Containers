#ifndef __S21_SET_CAPACITY__
#define __S21_SET_CAPACITY__

#include "s21_set.h"

namespace s21
{
    template <typename Key>
    typename s21_set<Key>::size_type s21_set<Key>::size()
    {
        return rbtree_.size();
    }

    template <typename Key>
    typename s21_set<Key>::size_type s21_set<Key>::max_size()
    {
        return rbtree_.max_size();
    }

    template <typename Key>
    bool s21_set<Key>::empty()
    {
        return (rbtree_.size_) ? true : false;
    }

}

#endif
