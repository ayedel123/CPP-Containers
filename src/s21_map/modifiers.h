#ifndef __S21_SET_MODIFIERS__
#define __S21_SET_MODIFIERS__

#include "s21_set.h"

namespace s21
{

    // template <typename key_type>
    // void s21_set<key_type>::clear()
    // {
    //     rbtree_.Clear();
    // }

    // template <typename key_type>
    // std::pair<typename s21_set<key_type>::iterator, bool> s21_set<key_type>::insert(const key_type &value)
    // {
    //     return rbtree_.InsertNode(value);
    // }

    // template <typename key_type>
    // void s21_set<key_type>::erase(typename s21_set<key_type>::iterator pos)
    // {
    //     rbtree_.Remove(*pos);
    // }

    // template <typename key_type>
    // void s21_set<key_type>::swap(s21_set &other)
    // {
    //     std::swap(rbtree_, other.tree_);
    // }

    // template <typename key_type>
    // void s21_set<key_type>::merge(s21_set &other)
    // {
    //     for (auto it = other.begin(); it != other.end(); it++)
    //     {
    //         rbtree_.InsertNode(it);
    //     }
    // }

}

#endif
