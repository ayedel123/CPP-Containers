#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_LOOKUP_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MAP_LOOKUP_H_

namespace s21 {

// template <typename Key, typename T>
// typename map<Key, T>::iterator map<Key, T>::find(const Key &key)
// {
//     return empty() ? end() : rbtree_.Find(MakePhantomPain(key));
// }

template <typename Key, typename T>
bool map<Key, T>::contains(const Key &key) {
  return empty() ? false : rbtree_.Find(MakePhantomPain(key)) != end();
}

}  // namespace s21

#endif