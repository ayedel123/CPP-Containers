#ifndef __S21_SET__
#define __S21_SET__
#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename key_type>
    class s21_set
    {
        using size_type = typename RedBlackTree<key_type>::size_type;
        using iterator = typename RedBlackTree<key_type>::iterator;

    private:
        RedBlackTree<key_type> rbtree_;

    public:
        // key_type &reference;
        // const key_type &const_reference;

        // Member functions
        s21_set() = default;
        s21_set(std::initializer_list<key_type> const &items);
        s21_set(const s21_set &s);
        s21_set(s21_set &&s);
        ~s21_set();

        s21_set<key_type> operator=(s21_set &&s);

        // Iterators
        iterator begin();
        iterator end();

        // Capacity
        bool empty();
        size_type size();
        size_type max_size();

        // Modifiers
        void clear();
        std::pair<iterator, bool> insert(const key_type &value);
        void erase(iterator pos);
        void swap(s21_set &other);
        void merge(s21_set &other);

        // Lookup
        iterator find(const key_type &key);
        bool contains(const key_type &key);
    };
}

#include "member_functions.h"
#include "modifiers.h"
#include "capacity.h"

#endif
