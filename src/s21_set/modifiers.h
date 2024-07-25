#ifndef __S21_SET_MODIFIERS__
#define __S21_SET_MODIFIERS__

#include "s21_set.h"

namespace s21
{

    template <typename Key>
    void s21_set<Key>::clear()
    {
        rbtree_.Clear();
    }

    template <typename Key>
    std::pair<typename s21_set<Key>::iterator, bool> s21_set<Key>::insert(const Key &value)
    {
        return rbtree_.InsertNode(value);
    }

    template <typename Key>
    void s21_set<Key>::erase(typename s21_set<Key>::iterator pos)
    {
        rbtree_.Remove(*pos);
    }

    template <typename Key>
    void s21_set<Key>::swap(s21_set &other)
    {
        std::swap(rbtree_, other.tree_);
    }

    template <typename Key>
    void s21_set<Key>::merge(s21_set &other)
    {
        for (auto it = other.begin(); it != other.end(); it++)
        {
            rbtree_.InsertNode(*it);
        }
    }

}

#endif
