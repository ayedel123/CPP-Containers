#ifndef CPP2_S21_CONTAINERS_1_VECTOR_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_CAPACITY_H_

// #include "vector.h"

class reference;
namespace s21
{

    // capacity
    template <class T>
    bool vector<T>::empty() const
    {
        return !size_;
    }

    template <class T>
    typename vector<T>::size_type vector<T>::size() const
    {
        return size_;
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::max_size() const
    {
        return std::numeric_limits<size_type>::max() / sizeof(value_type);
    }

    template <class T>
    void vector<T>::reserve(size_type size)
    {
        T *new_arr = new T[size];
        capacity_ = size;
        memcpy(new_arr, begin_, size_ * sizeof(T));
        delete[] begin_;
        begin_ = new_arr;
    }

    template <class T>
    typename vector<T>::size_type vector<T>::capacity() const
    {
        return capacity_;
    }

    template <class T>
    void vector<T>::shrink_to_fit()
    {
        if (size_ != capacity_)
        {
            T *temp_ = new T[size_];
            capacity_ = size_;
            memcpy(temp_, begin_, size_ * sizeof(T));
            delete[] begin_;
            begin_ = temp_;
        }
    }

}

#endif