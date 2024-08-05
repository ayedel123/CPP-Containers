#ifndef CPP2_S21_CONTAINERS_1_VECTOR_MODIFIERS_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_MODIFIERS_H_

#include "vector.h"

class reference;
namespace s21
{

    template <class T>
    void vector<T>::clear()
    {
        delete[] begin_;
        begin_ = nullptr, size_ = 0, capacity_ = 0;
    }

    template <class T>
    typename vector<T>::iterator vector<T>::insert(iterator pos,
                                                   const_reference value)
    {
        if (pos == end())
        {
            push_back(value);
        }
        else if (pos == begin())
        {
            T *temp_ = new T[capacity_ + 1];
            temp_[0] = value;
            std::memcpy(temp_ + 1, begin_, size_ * sizeof(T));
            size_ += 1;
            std::memcpy(begin_, temp_, size_ * sizeof(T));
            delete[] temp_;
        }
        else
        {
            T *temp_ = new T[capacity_ + 1];
            memcpy(temp_, begin_, (pos - begin()) * sizeof(T));
            auto keker = pos - begin();
            temp_[pos - begin_] = value;
            memcpy(temp_, begin_, (end() - pos) * sizeof(T));
            size_ += 1;
            memcpy(begin_, temp_, size_ * sizeof(T));
            delete[] temp_;
        }
        return pos;
    }

    template <class T>
    typename vector<T>::iterator vector<T>::insertt(iterator pos,
                                                    const_reference value)
    {
        size_t index = pos - begin();
        if (size_ >= capacity_)
        {
            resize(capacity_ * 2);
        }
        for (size_t i = size_; i > index; --i)
        {
            begin_[i] = begin_[i - 1];
        }
        begin_[index] = value;
        ++size_;
        return Iterator(begin_ + index);
    }

    template <class T>
    void vector<T>::erase(iterator pos)
    {
        T *temp_ = new T[capacity_ - 1];
        memcpy(temp_, begin_, pos - begin());
        memcpy(temp_, begin_, end() - pos);
        size_--;
        memcpy(begin_, temp_, size_ * sizeof(T));
        delete[] temp_;
    }

    template <class T>
    void vector<T>::push_back(const_reference value)
    {
        reallocator();
        begin_[size_] = value;
        size_ += 1;
    }

    template <class T>
    void vector<T>::pop_back()
    {
        size_--;
    }

    template <class T>
    void vector<T>::swap(vector<T> &other)
    {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(begin_, other.begin_);
    }

    // additional

    template <class T>
    void vector<T>::filling()
    {
        for (size_type i = 0; i < size_; i++)
        {
            begin_[i] = i + 10;
        }
    }

    template <class T>
    void vector<T>::reallocator()
    {
        if (!size_ && !capacity_)
        {
            capacity_ = 1;
        }
        if (size_ == capacity_)
        {
            capacity_ = capacity_ * 2;
        }
        T *temp_ = new T[capacity_];
        memcpy(temp_, begin_, size_ * sizeof(T));
        delete[] begin_;
        begin_ = new T[capacity_];
        memcpy(begin_, temp_, size_ * sizeof(T));
        delete[] temp_;
    }

}

#endif