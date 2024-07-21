#ifndef __S21_SET__
#define __S21_SET__

#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename key_type, typename value_type>
    class s21_set
    {
        using size_type = RedBlackTree<T>::size_type;

    private:
        RedBlackTree<key_type, value_type> rbtree_;
        size_type size = 0;

    public:
        size_type size() { return size; }
        bool empty() { return (size) ? true : false; }
        void insert();
        size_type max_siize();
        value_type &reference;
        const value_type &const_reference;

        s21_set();
        s21_set(std::initializer_list<value_type> const &items);
        s21_set(const s21_set &s);
        s21_set(s21_set &&s);
        ~s21_set();

        operator=(s21_set && s);
    };
}

#include "opertots.h"

#endif
