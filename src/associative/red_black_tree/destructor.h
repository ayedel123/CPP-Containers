#ifndef CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_DESTRUCTOR_H
#define CPP2_S21_CONTAINERS_1_ASSOCIATIVE_RED_BLACK_TREE_DESTRUCTOR_H

namespace s21 {

template <typename Key>
RBTree<Key>::~RBTree() {
  Clear();
}

template <typename Key>
void RBTree<Key>::Clear() {
  LRNdelete(root);
  root = nullptr;
  size_ = 0;
}

template <typename Key>
void RBTree<Key>::LRNdelete(Node<Key> *tmp) {
  if (tmp != nullptr) {
    LRNdelete(tmp->left);
    LRNdelete(tmp->right);
    delete tmp;
    tmp = nullptr;
  }
}

}  // namespace s21
#endif