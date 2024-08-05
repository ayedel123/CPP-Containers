#ifndef CPP2_S21_CONTAINERS_1_ARRAY_MODIFIERS_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_MODIFIERS_H_

#include "array.h"

class reference;
namespace s21
{

    // modifiers
    template <class T, std::size_t N>
    void array<T, N>::clear()
    {
        //  delete[] arr_;
    }

    template <class T, std::size_t N>
    void array<T, N>::swap(array<T, N> &other)
    {
        std::swap(arr_, other.arr_);
        std::swap(size_, other.size_);
    }

    template <class T, std::size_t N>
    void array<T, N>::fill(const_reference value)
    {
        for (size_type i = 0; i < size_; i++)
        {
            arr_[i] = value;
        }
    }
}

#endif