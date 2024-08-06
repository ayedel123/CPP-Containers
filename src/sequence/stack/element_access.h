#ifndef CPP2_S21_CONTAINERS_2_STACK_ELEMENT_ACCESS_H_
#define CPP2_S21_CONTAINERS_2_STACK_ELEMENT_ACCESS_H_

#include "stack.h"

namespace s21 {

//// Element access
template <class T>
typename s21::stack<T>::const_reference s21::stack<T>::top() const {
  return s21::vector<T>::back();
}

}  // namespace s21

#endif