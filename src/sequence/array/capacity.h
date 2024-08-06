#ifndef CPP2_S21_CONTAINERS_1_ARRAY_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_CAPACITY_H_

#include "array.h"

class reference;
namespace s21 {

// capacity

template <class T, std::size_t N>
bool array<T, N>::empty() const {
  return !size_;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

}  // namespace s21

#endif