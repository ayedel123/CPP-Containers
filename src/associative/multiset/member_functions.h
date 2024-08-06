#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MEMBER_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_MEMBER_FUNCTIONS_H_

namespace s21 {

template <typename Key>
multiset<Key>::multiset() : rbtree_(true) {}

template <typename Key>
multiset<Key>::multiset(const multiset &s) : multiset() {
  for (auto it = s.begin(); it != s.end(); ++it) {
    insert(*it);
  }
}

template <typename Key>
multiset<Key>::multiset(std::initializer_list<Key> const &items) : multiset() {
  for (auto it = items.begin(); it != items.end(); it++) {
    insert(*it);
  }
}

template <typename Key>
multiset<Key>::multiset(multiset &&s) {
  this->rbtree_ = std::move(s.rbtree_);
}

template <typename Key>
multiset<Key> multiset<Key>::operator=(multiset &&s) {
  this->rbtree_ = std::move(s.rbtree_);
  return *this;
}

template <typename Key>
multiset<Key> &multiset<Key>::operator=(const multiset &s) {
  clear();
  this->rbtree_ = RBTree<Key>();
  auto iter = s.begin();
  while (iter != s.end()) {
    insert(*iter);
    ++iter;
  }
  return *this;
}

}  // namespace s21

#endif