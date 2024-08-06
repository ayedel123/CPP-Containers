#ifndef CPP2_S21_CONTAINERS_1_VECTOR_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_ITERATOR_H_

// #include "vector.h"

class reference;
namespace s21 {
template <class T>
class vector<T>::Iterator {
 public:
  explicit Iterator(T *ptr) : m_ptr(ptr) {}
  T &operator*() const { return *m_ptr; }
  T *operator->() { return m_ptr; }

  Iterator &operator++() {
    ++m_ptr;
    return *this;
  }
  Iterator operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const Iterator &other) const { return m_ptr == other.m_ptr; }
  bool operator!=(const Iterator &other) const { return m_ptr != other.m_ptr; }

  Iterator &operator+=(int offset) {
    m_ptr += offset;
    return *this;
  }

  Iterator operator+(int offset) const { return Iterator(m_ptr + offset); }

  Iterator &operator-=(int offset) {
    m_ptr -= offset;
    return *this;
  }

  Iterator operator-(int offset) const { return Iterator(m_ptr - offset); }

  std::ptrdiff_t operator-(const Iterator &other) const {
    return m_ptr - other.m_ptr;
  }

 private:
  T *m_ptr;
};

template <class T>
class vector<T>::ConstIterator {};
// iterators
template <class T>
typename s21::vector<T>::iterator vector<T>::begin() const {
  return Iterator(begin_);
}

template <class T>
typename s21::vector<T>::iterator vector<T>::end() const {
  return Iterator(begin_ + size_);
}

template <class T>
typename s21::vector<T>::const_iterator vector<T>::cbegin() const {
  return ConstIterator(begin_);
}

template <class T>
typename s21::vector<T>::const_iterator vector<T>::cend() const {
  return ConstIterator(begin_ + size_);
}
}  // namespace s21

#endif