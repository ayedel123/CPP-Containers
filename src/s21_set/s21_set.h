#ifndef __S21_SET__
#define __S21_SET__

#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key>
    class s21_set
    {
        using size_type = RedBlackTree<T>::size_type;

    private:
        RedBlackTree<T> rbtree_;
        size_type size = 0;

    public:
        size_type size() { return size; }
        bool empty() { return (size) ? true : false; }
        void insert();
        size_type max_siize();
    };
}

#endif