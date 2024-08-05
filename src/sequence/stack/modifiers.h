#ifndef CPP2_S21_CONTAINERS_2_STACK_MODIFIERS_H_
#define CPP2_S21_CONTAINERS_2_STACK_MODIFIERS_H_

#include "stack.h"

namespace s21
{

    template <class T>
    void s21::stack<T>::push(const_reference value)
    {
        s21::vector<T>::push_back(value);
    }

    template <class T>
    void s21::stack<T>::pop()
    {
        s21::vector<T>::pop_back();
    }

}

#endif