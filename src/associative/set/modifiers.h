#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MODIFIERS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_MODIFIERS_H_

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
        return rbtree_.Insert(value);
    }

    template <typename Key>
    void set<Key>::erase(typename set<Key>::iterator pos)
    {
        rbtree_.Remove(*pos);
    }

    template <typename Key>
    void set<Key>::swap(set &other)
    {
        if (this != &other)
        {
            rbtree_.Swap(rbtree_, other.rbtree_);
        }
    }

    template <typename Key>
    void set<Key>::merge(set &other)
    {
        auto tmp = other.begin();
        for (auto it = other.begin(); it != other.end(); ++it)
        {
            tmp = it;
            ++tmp;
            if ((insert(*it)).second)
                other.erase(it);
            --tmp;
            it = tmp;
        }
    }

}

#endif
