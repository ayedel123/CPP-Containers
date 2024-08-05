#ifndef CPP2_S21_CONTAINERS_1_VECTOR_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_MEMBER_FUNCTIONS_H_

// #include "vector.h"

class reference;
namespace s21
{

    // functions
    template <class T>
    vector<T>::vector() : begin_(nullptr), size_(0), capacity_(0) {}

    template <class T>
    vector<T>::vector(size_type n)
    {
        begin_ = new T[n];
        size_ = n, capacity_ = n;
    }

    template <class T>
    vector<T>::vector(const std::initializer_list<value_type> &items)
    {
        size_ = items.size();
        capacity_ = items.size();
        begin_ = new T[capacity_];
        std::copy(items.begin(), items.end(), begin_);
    }

    template <class T>
    vector<T>::vector(const vector<T> &v) : size_(v.size_), capacity_(v.capacity_)
    {
        begin_ = new T[capacity_];
        std::copy(v.begin_, v.begin_ + size_, begin_);
    }

    template <typename T>
    vector<T>::vector(vector<T> &&v) noexcept
    {
        if (this != &v)
        {
            delete[] begin_;
            size_ = 0;
            capacity_ = 0;
            begin_ = nullptr;
            std::swap(size_, v.size_);
            std::swap(capacity_, v.capacity_);
            std::swap(begin_, v.begin_);
        }
    }

    template <class T>
    vector<T>::~vector()
    {
        clear();
    }

    template <class T>
    typename s21::vector<T> &s21::vector<T>::operator=(vector<T> &&v) noexcept
    {
        if (this != &v)
        {
            delete[] begin_;
            size_ = 0;
            capacity_ = 0;
            begin_ = nullptr;
            std::swap(size_, v.size_);
            std::swap(capacity_, v.capacity_);
            std::swap(begin_, v.begin_);
        }
        return *this;
    }

} // namespace s21

#endif