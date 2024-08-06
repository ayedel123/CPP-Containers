#ifndef CPP2_S21_CONTAINERS_1_QUEUE_QUEUE_H_
#define CPP2_S21_CONTAINERS_1_QUEUE_QUEUE_H_

#include "../list/list.h"

namespace s21
{
  template <typename T>
  class queue : private list<T>
  {
  public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t;

    queue() : list<T>() {}
    queue(std::initializer_list<value_type> const &items) : list<T>(items) {}
    queue(const queue &other) : list<T>(other) {}
    queue(queue &&other) noexcept : list<T>(std::move(other)) {}
    ~queue() {}

    const_reference front() { return list<T>::front(); }
    const_reference back() { return list<T>::back(); }

    bool empty() { return list<T>::empty(); }
    size_type size() { return list<T>::size(); }

    void push(const_reference value) { this->push_back(value); }
    void pop() { this->pop_front(); }

    void swap(queue &other) { list<T>::swap(other); }

    queue &operator=(const queue &other)
    {
      if (this != &other)
      {
        list<T>::operator=(other);
      }
      return *this;
    }
    queue &operator=(queue &&other) noexcept
    {
      if (this != &other)
      {
        list<T>::operator=(std::move(other));
      }
      return *this;
    }
  };
} //  namespace s21
#endif // QUEUE_H