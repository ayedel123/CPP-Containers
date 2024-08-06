#ifndef CPP2_S21_CONTAINERS_1_ARRAY_ELEMENT_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_ELEMENT_ACCESS_H_

#include "array.h"

class reference;
namespace s21 {

// Element_access

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) const {
  return arr_[pos];
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return arr_[pos];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return arr_[0];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return arr_[N - 1];
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return arr_;
}

}  // namespace s21

#endif