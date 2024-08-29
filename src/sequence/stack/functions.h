#ifndef CPP2_S21_CONTAINERS_2_STACK_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_2_STACK_FUNCTIONS_H_

#include "stack.h"

namespace s21 {

//// Modifiers
template <class T>
void s21::stack<T>::push(const_reference value) {
  s21::vector<T>::push_back(value);
}

template <class T>
void s21::stack<T>::pop() {
  s21::vector<T>::pop_back();
}

}  // namespace s21

#endif