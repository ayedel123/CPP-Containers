#ifndef CPP2_S21_CONTAINERS_1_VECTOR_ELEMENT_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_ELEMENT_ACCESS_H_

// #include "vector.h"

class reference;
namespace s21 {

// element_access
template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return begin_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return begin_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::front() const {
  return *begin_;
}
template <class T>
typename vector<T>::const_reference vector<T>::back() const {
  auto temp_ = begin_;
  std::advance(temp_, size_ - 1);
  return *temp_;
}

template <class T>
typename vector<T>::iterator vector<T>::data() {
  return Iterator(this->begin_);
}

}  // namespace s21

#endif