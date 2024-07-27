#ifndef __S21_MAP_MODIFIERS__
#define __S21_MAP_MODIFIERS__

#include "map.h"

namespace s21
{

    template <typename Key, typename T>
    void map<Key, T>::clear()
    {
        rbtree_.Clear();
    }

    template <typename Key, typename T>
    std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const value_type &value)
    {
        return rbtree_.InsertNode(value);
    }

    template <typename Key, typename T>
    std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const Key &key, const T &obj)
    {
        return insert(std::make_pair(key, obj));
    }

    template <typename Key, typename T>
    std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(const Key &key, const T &obj)
    {
        auto pair = std::make_pair(key, obj);
        std::pair<typename map<Key, T>::iterator, bool> tmp = rbtree_.InsertNode(pair);
        if (!*(tmp.second))
        {
            tmp.second->key = pair;
        }
    }

    template <typename Key, typename T>
    void map<Key, T>::erase(typename map<Key, T>::iterator pos)
    {
        rbtree_.Remove(*pos);
    }

    template <typename Key, typename T>
    void map<Key, T>::swap(map &other)
    {
        std::swap(rbtree_, other.tree_);
    }

    template <typename Key, typename T>
    void map<Key, T>::merge(map &other)
    {
        for (auto it = other.begin(); it != other.end(); it++)
        {
            rbtree_.InsertNode(*it);
        }
    }

}

#endif
