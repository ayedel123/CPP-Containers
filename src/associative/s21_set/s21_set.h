#ifndef __S21_SET__
#define __S21_SET__
#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key>
    class set
    {
    public:
        using key_type = Key;
        using size_type = typename RedBlackTree<key_type>::size_type;
        using iterator = typename RedBlackTree<key_type>::iterator;
        using value_type = key_type;
        using reference = typename RedBlackTree<key_type>::reference;
        using const_reference = typename RedBlackTree<key_type>::const_reference;
        using const_iterator = typename RedBlackTree<Key>::const_iterator;

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
        ~set() = default;

        set<Key> operator=(set &&s);
        set<Key> &operator=(const set &s);

        // Iterators
        iterator begin();
        const_iterator cbegin() const;
        iterator end();
        const_iterator cend() const;

        // Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

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
