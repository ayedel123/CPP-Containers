#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_WALKER_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_WALKER_H

namespace s21 {

template <typename Key>
Node<Key> *RBTree<Key>::GetMin(Node<Key> *tmp) const {
  if (root == nullptr) return nullptr;
  if (tmp == nullptr) tmp = root;
  while (tmp->left != nullptr) {
    tmp = tmp->left;
  }
  return tmp;
}

template <typename Key>
Node<Key> *RBTree<Key>::GetMax(Node<Key> *tmp) const {
  if (root == nullptr) return nullptr;
  if (tmp == nullptr) tmp = root;
  while (tmp->right != nullptr) {
    tmp = tmp->right;
  }
  return tmp;
}

template <typename Key>
Node<Key> *RBTree<Key>::Next(Node<Key> *tmp) {
  Node<Key> *result = nullptr;

  if (tmp->right) {
    result = GetMin(tmp->right);
  } else {
    result = tmp->parent;
    while (result && tmp == result->right) {
      tmp = result;
      result = tmp->parent;
    }
  }

  return result;
}

template <typename Key>
Node<Key> *RBTree<Key>::Previous(Node<Key> *tmp) {
  Node<Key> *result = nullptr;

  if (tmp->left) {
    result = GetMax(tmp->right);
  } else {
    result = tmp->parent;
    while (result && tmp == result->left) {
      tmp = result;
      result = tmp->parent;
    }
  }

  return result;
}

}  // namespace s21

#endif