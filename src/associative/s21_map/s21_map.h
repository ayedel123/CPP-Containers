#ifndef __S21_MAP__
#define __S21_MAP__

#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key, typename T>
    class map
    {
        using key_type = Key;
        using mapped_type = T;
        using size_type = typename RedBlackTree<key_type>::size_type;
        using iterator = typename RedBlackTree<key_type>::iterator;
        using value_type = std::pair<const key_type, mapped_type>;
        using reference = typename RedBlackTree<key_type>::reference;
        using const_reference = typename RedBlackTree<key_type>::const_reference;
        using const_iterator = typename RedBlackTree<Key>::const_iterator;

    private:
        RedBlackTree<value_type> rbtree_;

    public:
        // key_type &reference;
        // const key_type &const_reference;

        // Member functions
        map();
        map(std::initializer_list<value_type> const &items);
        map(const map &s);
        map(map &&s);
        ~map() = default;

        map<Key, T> operator=(map &&s);

        // Element access
        T &at(const Key &key);
        T &operator[](const Key &key);

        // Iterators
        iterator begin();
        iterator end();

        // Capacity
        bool empty();
        size_type size();
        size_type max_size();

        // Modifiers
        void clear();

        std::pair<iterator, bool> insert(const value_type &value);
        std::pair<iterator, bool> insert(const Key &key, const T &obj);
        std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

        void erase(iterator pos);
        void swap(map &other);
        void merge(map &other);

        // Lookup
        iterator find(const key_type &key);
        bool contains(const key_type &key);

        // Secret

    private:
        bool PairLess(value_type v1, value_type v2)
        {
            return v1->first < v2->first;
        }

        bool PairEqual(value_type v1, value_type v2)
        {
            return v1->first == v2->first;
        }
    };
}

#include "member_functions.h"
#include "modifiers.h"
#include "capacity.h"
#include "element_access.h"
#include "lookup.h"

#endif