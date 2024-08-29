#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_ITERATOR_ACCESS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_SET_ITERATOR_ACCESS_H_

namespace s21 {

template <typename Key>
typename set<Key>::iterator set<Key>::begin() {
  return rbtree_.Begin();
}

template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  return rbtree_.End();
}

template <typename Key>
typename set<Key>::const_iterator set<Key>::begin() const {
  return rbtree_.cBegin();
}

template <typename Key>
typename set<Key>::const_iterator set<Key>::end() const {
  return rbtree_.cEnd();
}

}  // namespace s21

#endif