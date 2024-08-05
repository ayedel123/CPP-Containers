#ifndef CPP2_S21_CONTAINERS_1_ARRAY_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_MEMBER_FUNCTIONS_H_

#include "array.h"

class reference;
namespace s21
{

    template <class T, std::size_t N>
    array<T, N>::array()
    {
        fill({});
    }

    template <typename T, std::size_t N>
    array<T, N>::array(std::initializer_list<value_type> const &items)
    {
        std::copy(items.begin(), items.end(), arr_);
    }

    template <class T, std::size_t N>
    array<T, N>::array(const array &a)
    {
        std::copy(a.arr_, a.arr_ + size_, arr_);
    }

    template <typename T, std::size_t N>
    array<T, N>::array(array &&a) noexcept
    {
        std::move(a.arr_, a.arr_ + size_, arr_);
    }

    template <class T, std::size_t N>
    array<T, N>::~array()
    {
        clear();
    }

    template <class T, std::size_t N>
    typename s21::array<T, N> &s21::array<T, N>::operator=(
        array<T, N> &&v) noexcept
    {
        if (this != &v)
        {
            for (std::size_t i = 0; i < size_; ++i)
            {
                arr_[i] = std::move(v.arr_[i]);
            }
        }
        return *this;
    }

}

#endif