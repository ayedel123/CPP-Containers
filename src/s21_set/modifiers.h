#ifndef __S21_SET_MODIFIERS__
#define __S21_SET_MODIFIERS__

#include "s21_set.h"

namespace s21
{
    template <typename key_type>
    std::pair<typename s21_set<key_type>::iterator, bool> s21_set<key_type>::insert(const key_type &value)
    {
        std::pair<typename s21_set<key_type>::iterator, bool> result = rbtree_.InsertNode(value);
        if (result.second)
            size_++;
        return result;
    }
}

#endif
