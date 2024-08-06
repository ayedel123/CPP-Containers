#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_ITERATOR_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_ITERATOR_ACCESS_H_

namespace s21 {

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() {
  return rbtree_.Begin();
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::end() {
  return rbtree_.End();
}

template <typename Key>
typename multiset<Key>::const_iterator multiset<Key>::begin() const {
  return rbtree_.cBegin();
}

template <typename Key>
typename multiset<Key>::const_iterator multiset<Key>::end() const {
  return rbtree_.cEnd();
}

}  // namespace s21

#endif