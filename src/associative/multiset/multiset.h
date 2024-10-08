#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_S21_MULTISET_S21_SET_H_

#include "../red_black_tree/red_black_tree.h"

namespace s21 {
template <typename Key>
class multiset {
 public:
  using key_type = Key;
  using size_type = typename RBTree<key_type>::size_type;
  using iterator = typename RBTree<key_type>::iterator;
  using value_type = key_type;
  using reference = typename RBTree<key_type>::reference;
  using const_reference = typename RBTree<key_type>::const_reference;
  using const_iterator = typename RBTree<Key>::const_iterator;

 public:
  // Key &reference;
  // const Key &const_reference;

  // Member functions
  multiset();
  multiset(std::initializer_list<Key> const &items);
  multiset(const multiset &s);
  multiset(multiset &&s);
  ~multiset() = default;

  multiset<Key> operator=(multiset &&s);
  multiset<Key> &operator=(const multiset &s);

  // Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Modifiers
  void clear();
  std::pair<iterator, bool> insert(const Key &value);
  void erase(iterator pos);
  void swap(multiset &other);
  void merge(multiset &other);

  // Lookup
  iterator find(const Key &key);
  bool contains(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);

 private:
  RBTree<Key> rbtree_;
};

}  // namespace s21

#include "capacity.h"
#include "iterator.h"
#include "lookup.h"
#include "member_functions.h"
#include "modifiers.h"

#endif
