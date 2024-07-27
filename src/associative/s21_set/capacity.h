#ifndef __S21_SET_CAPACITY__
#define __S21_SET_CAPACITY__

#include "set.h"

namespace s21
{
    template <typename Key>
    typename set<Key>::size_type set<Key>::size()
    {
        return rbtree_.size();
    }

    template <typename Key>
    typename set<Key>::size_type set<Key>::max_size()
    {
        return rbtree_.max_size();
    }

    template <typename Key>
    bool set<Key>::empty()
    {
        return (rbtree_.size_) ? true : false;
    }

}

#endif
