#ifndef CPP2_S21_CONTAINERS_2_STACK_CAPACITY_H_
#define CPP2_S21_CONTAINERS_2_STACK_CAPACITY_H_

#include "stack.h"

namespace s21 {

////Capacity
template <class T>
bool s21::stack<T>::empty() {
  return s21::vector<T>::empty();
}

template <class T>
size_t s21::stack<T>::size() {
  return s21::vector<T>::size();
}

}  // namespace s21

#endif