#ifndef CPP2_S21_CONTAINERS_1_ARRAY_MEMBER_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_MEMBER_ITERATOR_H_

#include "array.h"

class reference;
namespace s21
{

    // iterators
    template <class T, std::size_t N>
    typename s21::array<T, N>::iterator array<T, N>::begin() const
    {
        return Iterator(arr_);
    }

    template <class T, std::size_t N>
    typename s21::array<T, N>::iterator array<T, N>::end() const
    {
        return Iterator(arr_ + size_);
    }

    template <class T, std::size_t N>
    typename s21::array<T, N>::const_iterator array<T, N>::cbegin() const
    {
        return ConstIterator(arr_ + size_);
    }

    template <class T, std::size_t N>
    typename s21::array<T, N>::const_iterator array<T, N>::cend() const
    {
        return ConstIterator(arr_ + size_);
    }

}

#endif