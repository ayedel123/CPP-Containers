#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MAP_LOOKUP_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MAP_LOOKUP_H_

namespace s21 {

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key &key) {
  return rbtree_.Find(key);
}

template <typename Key>
bool multiset<Key>::contains(const Key &key) {
  return (find(key) != end());
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key &key) {
  return std::make_pair(lower_bound(key), upper_bound(key));
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key &key) {
  auto iter = find(key);
  if (iter == end()) return iter;

  while (*iter == key) {
    --iter;
  }
  ++iter;
  return iter;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key &key) {
  auto iter = find(key);
  if (iter == end()) return iter;

  while (*iter == key) {
    ++iter;
  }
  --iter;
  return iter;
}

}  // namespace s21

#endif