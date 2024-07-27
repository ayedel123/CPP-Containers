#ifndef __S21_SET_CAPACITY__
#define __S21_SET_CAPACITY__

#include "s21_set.h"

namespace s21
{
    template <typename Key>
    typename set<Key>::size_type set<Key>::size() const
    {
        return rbtree_.size();
    }

    template <typename Key>
    typename set<Key>::size_type set<Key>::max_size() const
    {
        return rbtree_.max_size();
    }

    template <typename Key>
    bool set<Key>::empty() const
    {
        return rbtree_.empty();
    }

}

#endif
