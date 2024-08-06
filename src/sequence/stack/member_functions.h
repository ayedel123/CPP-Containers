#ifndef CPP2_S21_CONTAINERS_2_STACK_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_2_STACK_MEMBER_FUNCTIONS_H_

#include "stack.h"

namespace s21 {
//// Constructors

template <class T>
s21::stack<T>::stack() : vector<T>() {}

template <class T>
s21::stack<T>::stack(size_type n) : vector<T>(n) {}

template <class T>
s21::stack<T>::stack(std::initializer_list<value_type> const &items)
    : vector<T>(items) {}

template <class T>
s21::stack<T>::stack(const stack<T> &s) : vector<T>(s) {}

template <class T>
s21::stack<T>::stack(stack<T> &&s)

    noexcept
    :

      vector<T>(std::move(s)) {}

//// Operator

template <class T>
typename s21::stack<T> &s21::stack<T>::operator=(stack<T> &&s)

    noexcept {
  s21::vector<T>::operator=(std::move(s));
  return *this;
}

}  // namespace s21

#endif