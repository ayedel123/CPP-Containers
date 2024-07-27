#ifndef __S21_SET_MODIFIERS__
#define __S21_SET_MODIFIERS__

#include "set.h"

namespace s21
{

    template <typename Key>
    void set<Key>::clear()
    {
        rbtree_.Clear();
    }

    template <typename Key>
    std::pair<typename set<Key>::iterator, bool> set<Key>::insert(const Key &value)
    {
        return rbtree_.InsertNode(value);
    }

    template <typename Key>
    void set<Key>::erase(typename set<Key>::iterator pos)
    {
        rbtree_.Remove(*pos);
    }

    template <typename Key>
    void set<Key>::swap(set &other)
    {
        std::swap(rbtree_, other.tree_);
    }

    template <typename Key>
    void set<Key>::merge(set &other)
    {
        for (auto it = other.begin(); it != other.end(); it++)
        {
            rbtree_.InsertNode(*it);
        }
    }

}

#endif
