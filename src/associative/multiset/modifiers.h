#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MODIFIERS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MODIFIERS_H_

#include "multiset.h"

namespace s21 {

template <typename Key>
void multiset<Key>::clear() {
  rbtree_.Clear();
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(
    const Key &value) {
  return rbtree_.Insert(value);
}

template <typename Key>
void multiset<Key>::erase(typename multiset<Key>::iterator pos) {
  rbtree_.Remove(*pos);
}

template <typename Key>
void multiset<Key>::swap(multiset &other) {
  if (this != &other) {
    rbtree_.Swap(rbtree_, other.rbtree_);
  }
}

template <typename Key>
void multiset<Key>::merge(multiset &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
  other.clear();
}

}  // namespace s21

#endif
