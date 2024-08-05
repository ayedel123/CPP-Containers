#ifndef CPP2_S21_CONTAINERS_1_ARRAY_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_ARRAY_ARRAY_H_

#include "../../s21_containers.h"

namespace s21
{

    template <typename T, std::size_t N>
    class array
    {
    public:
        // Member type
        class Iterator;
        class ConstIterator;

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = Iterator;
        using const_iterator = ConstIterator;
        using size_type = size_t;

        // Functions
        array();
        array(std::initializer_list<T> const &items);
        array(const array &a);
        array(array &&a) noexcept;
        ~array();

        class Iterator
        {
        public:
            explicit Iterator(T *ptr) : m_ptr(ptr) {}
            T &operator*() const { return *m_ptr; }
            T *operator->() { return m_ptr; }

            Iterator &operator++()
            {
                ++m_ptr;
                return *this;
            }
            Iterator operator++(int)
            {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }
            bool operator==(const Iterator &other) const
            {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const Iterator &other) const
            {
                return m_ptr != other.m_ptr;
            }

            Iterator &operator+=(int offset)
            {
                m_ptr += offset;
                return *this;
            }

            Iterator operator+(int offset) const { return Iterator(m_ptr + offset); }

            Iterator &operator-=(int offset)
            {
                m_ptr -= offset;
                return *this;
            }

            Iterator operator-(int offset) const { return Iterator(m_ptr - offset); }

            std::ptrdiff_t operator-(const Iterator &other) const
            {
                return m_ptr - other.m_ptr;
            }

        private:
            T *m_ptr;
        };

        class ConstIterator
        {
        public:
            explicit ConstIterator(T *ptr) : m_ptr(ptr) {}
            T &operator*() const { return *m_ptr; }
            T *operator->() { return m_ptr; }

            ConstIterator &operator++()
            {
                ++m_ptr;
                return *this;
            }
            ConstIterator operator++(int)
            {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }
            bool operator==(ConstIterator &other) const { return m_ptr == other.m_ptr; }
            bool operator!=(ConstIterator &other) const { return m_ptr != other.m_ptr; }

            ConstIterator &operator+=(int offset)
            {
                m_ptr += offset;
                return *this;
            }

            ConstIterator operator+(int offset) const
            {
                return ConstIterator(m_ptr + offset);
            }

            ConstIterator &operator-=(int offset)
            {
                m_ptr -= offset;
                return *this;
            }

            ConstIterator operator-(int offset) const
            {
                return ConstIterator(m_ptr - offset);
            }

            std::ptrdiff_t operator-(ConstIterator &other) const
            {
                return m_ptr - other.m_ptr;
            }

        private:
            T *m_ptr;
        };

        // Operators
        array &operator=(array &&v) noexcept;

        // Element_access
        reference at(size_type pos) const;
        reference operator[](size_type pos);
        const_reference front() const;
        const_reference back() const;
        iterator data();

        // iterators
        iterator begin() const;
        iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        // capacity
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // modifier
        void clear();
        void swap(array &other);
        void fill(const_reference value);

    private:
        size_type size_ = N;
        value_type arr_[N];
    };
} // namespace s21

#include "member_functions.h"
#include "element_access.h"
#include "iterator.h"
#include "capacity.h"
#include "modifiers.h"

#endif // CPP2_S21_CONTAINERS_1_ARRAY_H
