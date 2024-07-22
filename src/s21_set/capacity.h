#ifndef __S21_SET_CAPACITY__
#define __S21_SET_CAPACITY__

#include "s21_set.h"

namespace s21
{
    template <typename key_type>
    typename s21_set<key_type>::size_type s21_set<key_type>::size()
    {
        return size_;
    }
}

#endif
