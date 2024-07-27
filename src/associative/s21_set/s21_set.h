#ifndef __S21_SET__
#define __S21_SET__
#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key>
    class set
    {
        using size_type = typename RedBlackTree<Key>::size_type;
        using iterator = typename RedBlackTree<Key>::iterator;

    private:
        RedBlackTree<Key> rbtree_;

    public:
        // Key &reference;
        // const Key &const_reference;

        // Member functions
        set() = default;
        set(std::initializer_list<Key> const &items);
        set(const set &s);
        set(set &&s);
        ~set();

        set<Key> operator=(set &&s);

        // Iterators
        iterator begin();
        iterator end();

        // Capacity
        bool empty();
        size_type size();
        size_type max_size();

        // Modifiers
        void clear();
        std::pair<iterator, bool> insert(const Key &value);
        void erase(iterator pos);
        void swap(set &other);
        void merge(set &other);

        // Lookup
        iterator find(const Key &key);
        bool contains(const Key &key);
    };
}

#include "member_functions.h"
#include "modifiers.h"
#include "capacity.h"
#include "lookup.h"
#include "iterator.h"

#endif
