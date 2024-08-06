#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_CAPACITY_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_CAPACITY_H_

#include "multiset.h"

namespace s21 {
template <typename Key>
typename multiset<Key>::size_type multiset<Key>::size() const {
  return rbtree_.Size();
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::max_size() const {
  return rbtree_.MaxSize();
}

template <typename Key>
bool multiset<Key>::empty() const {
  return rbtree_.Empty();
}

}  // namespace s21

#endif
