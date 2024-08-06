#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_S21_MAP_H_

#include "../red_black_tree/red_black_tree.h"

namespace s21
{
    template <typename Key, typename T>
    class map
    {
    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using size_type = typename RBTree<key_type>::size_type;
        using iterator = typename RBTree<value_type>::iterator;

        using reference = typename RBTree<value_type>::reference;
        using const_reference = typename RBTree<value_type>::const_reference;
        using const_iterator = typename RBTree<value_type>::const_iterator;

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
        map<Key, T> &operator=(const map &s);

        // Element access
        T &at(const Key &key);
        T &operator[](const Key &key);

        // Iterators
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        // Capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // Modifiers
        void clear();

        std::pair<iterator, bool> insert(const value_type &value);
        std::pair<iterator, bool> insert(const Key &key, const T &obj);
        std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

        void erase(iterator pos);
        void swap(map &other);
        void merge(map &other);

        // Lookup
        // iterator find(const key_type &key);
        bool contains(const key_type &key);

    private:
        RBTree<std::pair<const key_type, mapped_type>> rbtree_;

        // Secret

    private:
        value_type MakePhantomPain(Key key)
        {
            value_type phantom = std::make_pair(key, (*begin()).second);
            return phantom;
        }

        static bool PairLess(const value_type &v1, const value_type &v2)
        {
            // std::cout << v1.first << " < " << v2.first << " = " << (v1.first < v2.first) << std::endl;
            return v1.first < v2.first;
        }

        static bool PairEqual(const value_type &v1, const value_type &v2)
        {
            // std::cout << v1.first << v2.first << (v1.first == v2.first) << std::endl;
            return v1.first == v2.first ? true : false;
        }
    };
}

#include "member_functions.h"
#include "modifiers.h"
#include "capacity.h"
#include "element_access.h"
#include "lookup.h"
#include "iterator.h"

#endif