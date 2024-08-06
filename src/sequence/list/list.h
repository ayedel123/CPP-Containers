#ifndef CPP2_S21_CONTAINERS_1_LIST_LIST_H_
#define CPP2_S21_CONTAINERS_1_LIST_LIST_H_

#include "../../s21_containers.h"

namespace s21 {
template <typename T>
class list {
  // List Member type //
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

private:
  struct Node {
    T value_;
    Node *next_;
    Node *prev_;

    explicit Node(const value_type &value)
        : value_(value), next_(nullptr), prev_(nullptr) {}
  };

  Node *head_;
  Node *tail_;
  Node *end_;
  size_type size_;

public:
  // List Functions //
  list() : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {}

  explicit list(size_type count)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    for (size_type i = 0; i < count; ++i) {
      push_back(value_type());
    }
    set_end();
  }

  list(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    end_ = new Node(size_);
    for (const auto &item : items) {
      push_back(item);
      set_end();
    }
  }

  list(const list &other)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    end_ = other.size_;
    copy();
  }

  list(list &&other) noexcept
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    swap(other);
  }

  list &operator=(list &&other) noexcept {
    if (this != &other) {
      clear();
      swap(other);
    }
    return *this;
  }

  list &operator=(const list &other) {
    if (this != &other) {
      clear();
      copy(other);
    }
    return *this;
  }

  ~list() {
    clear();
    delete end_;
  }

  virtual  // List Element access //
      const_reference
      front() {
    return !head_ ? end_->value_ : head_->value_;
  }

  virtual const_reference back() const {
    return !tail_ ? end_->value_ : tail_->value_;
  }

  virtual  // List Capacity //
      bool
      empty() {
    return size_ == 0;
  }

  virtual size_type size() { return size_; }

  size_type max_size() {
    return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
  }

  // List Modifiers //
  void clear() {
    while (!empty()) pop_back();
  }

  void push_back(value_type value) {
    Node *new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev_ = tail_;
      tail_->next_ = new_node;
      tail_ = new_node;
    }
    ++size_;
    set_end();
  }

  void pop_back() {
    if (empty())
      throw std::out_of_range("List is empty.");
    else {
      Node *node = tail_;
      if (size_ == 1) {
        head_ = nullptr;
        tail_ = nullptr;
      } else {
        tail_ = node->prev_;
        tail_->next_ = nullptr;
      }
      delete node;
      --size_;
      set_end();
    }
  }

  void push_front(value_type value) {
    Node *new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_->prev_ = new_node;
      head_ = new_node;
    }
    ++size_;
    set_end();
  }

  void pop_front() {
    if (empty())
      throw std::out_of_range("List is empty.");
    else {
      Node *node = head_;
      if (size_ == 1) {
        head_ = nullptr;
        tail_ = nullptr;
      } else {
        head_ = node->next_;
        head_->prev_ = nullptr;
      }
      delete node;
      --size_;
      set_end();
    }
  }

  void swap(list &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }

  void merge(list &other) {
    if (!this->empty() && !other.empty()) {
      iterator it_this = this->begin();
      iterator it_other = other.begin();

      while (it_this != this->end()) {
        if (it_other != other.end()) {
          if (it_this.current_->value_ >= it_other.current_->value_) {
            this->insert(it_this, it_other.current_->value_);
            it_other++;
          } else
            it_this++;
        } else {
          break;
        }
      }
      while (it_other != other.end()) {
        this->insert(it_this, it_other.current_->value_);
        it_other++;
      }
    } else if (this->empty() && !other.empty()) {
      this->copy(other);
    }
    other.clear();
  }

  void reverse() {
    if (!this->empty()) {
      size_type step = 0;
      for (iterator it = this->begin(); step <= this->size(); ++it) {
        step++;
        std::swap(it.current_->prev_, it.current_->next_);
      }
      std::swap(head_, tail_);
    }
  }

  void unique() {
    if (!this->empty()) {
      for (iterator i = this->begin(); i != this->end(); i++) {
        if (i.current_->value_ == i.current_->prev_->value_) {
          iterator del_it = (i - 1);
          this->erase(del_it);
        }
      }
    }
  }

  void sort() {
    if (head_ == nullptr) return;
    quick_sort(head_, tail_);
  }

  // Tools //
  void set_end() {
    if (end_) {
      end_->value_ = size();
      end_->next_ = head_;
      end_->prev_ = tail_;
      if (head_) {
        head_->prev_ = end_;
      }
      if (tail_) {
        tail_->next_ = end_;
      }
    }
  }

  void copy(const list &other) {
    Node *copy = other.head_;
    for (size_type i = 0; i != other.size_; i++) {
      push_back(copy->value_);
      copy = copy->next_;
    }
  }

  void print() {
    std::cout << "print list:\n{";
    for (iterator it = begin(); it != end(); ++it) {
      std::cout << *it;
      if ((it + 1) != end()) {
        std::cout << ", ";
      }
    }
    std::cout << "}\n";
  }

  Node *partition(Node *low, Node *high) {
    T pivot = high->value_;
    Node *i = low->prev_;

    for (Node *j = low; j != high; j = j->next_) {
      if (j->value_ <= pivot) {
        i = (i == nullptr) ? low : i->next_;
        std::swap(i->value_, j->value_);
      }
    }
    i = (i == nullptr) ? low : i->next_;
    std::swap(i->value_, high->value_);
    return i;
  }

  void quick_sort(Node *low, Node *high) {
    if (high != nullptr && low != high && low != high->next_) {
      Node *p = partition(low, high);
      quick_sort(low, p->prev_);
      quick_sort(p->next_, high);
    }
  }

  // Iterator //
  template <typename value_type>
  class ListIterator {
   public:
    ListIterator() { current_ = nullptr; }
    explicit ListIterator(Node *current) : current_(current) {}

    // Operators //
    reference operator*() {
      if (!current_) {
        throw std::invalid_argument("Value is nullptr");
      }
      return current_->value_;
    }

    ListIterator operator++(int) {
      current_ = current_->next_;
      return *this;
    }

    ListIterator operator--(int) {
      current_ = current_->prev_;
      return *this;
    }

    ListIterator &operator++() {
      current_ = current_->next_;
      return *this;
    }

    ListIterator &operator--() {
      current_ = current_->prev_;
      return *this;
    }

    ListIterator operator+(const size_type value) {
      Node *tmp = current_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->next_;
      }

      ListIterator res(tmp);
      return res;
    }

    ListIterator operator-(const size_type value) {
      Node *tmp = current_;
      for (size_type i = 0; i < value; i++) {
        tmp = tmp->prev_;
      }
      ListIterator res(tmp);
      return res;
    }

    bool operator==(ListIterator other) { return current_ == other.current_; }

    bool operator!=(ListIterator other) { return current_ != other.current_; }

    bool operator<(ListIterator other) { return current_ < other.current_; }

    bool operator<=(ListIterator other) { return current_ <= other.current_; }

    bool operator>(ListIterator other) { return current_ > other.current_; }

    bool operator>=(ListIterator other) { return current_ >= other.current_; }

   private:
    Node *current_ = nullptr;
    friend class list<T>;
  };

  // Const Iterator //
  template <typename value_type>
  class ListConstIterator : ListIterator<T> {
   public:
    explicit ListConstIterator(ListIterator<T> other)
        : ListIterator<T>(other) {}
    const T &operator*() { return ListIterator<T>::operator*(); }
  };

  //  List Member type
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  // List Iterators
  iterator begin() { return !head_ ? iterator(end_) : iterator(head_); }

  iterator end() { return iterator(end_); }

  const_iterator begin() const {
    return !head_ ? const_iterator(end_) : const_iterator(head_);
  }

  const_iterator end() const { return const_iterator(end_); }

  // List Modifiers
  iterator insert(iterator pos, const_reference value) {
    Node *current = pos.current_;
    Node *add = new Node(value);
    if (empty()) {
      add->next_ = end_;
      add->prev_ = end_;
      head_ = add;
      tail_ = add;
    } else {
      if (current == head_) {
        head_ = add;
      } else if (current == end_) {
        tail_ = add;
      }
      add->next_ = current;
      add->prev_ = current->prev_;
      current->prev_->next_ = add;
      current->prev_ = add;
    }
    size_++;
    set_end();
    return iterator(add);
  }

  void erase(iterator pos) {
    Node *current = pos.current_;
    if (!empty() && current != end_) {
      if (current == head_) {
        if (current->next_ && current->next_ != end_) {
          head_ = current->next_;
        } else {
          head_ = end_;
        }
      } else if (current == tail_) {
        if (current->prev_ && current->prev_ != end_) {
          tail_ = current->prev_;
        } else {
          tail_ = end_;
        }
      }
      current->prev_->next_ = current->next_;
      current->next_->prev_ = current->prev_;
      delete current;
      this->size_--;
    } else {
      throw std::invalid_argument("Invalid argument");
    }
    set_end();
  }

  void splice(const_iterator pos, list &other) {
    if (!other.empty()) {
      for (iterator i = other.begin(); i != other.end(); ++i) {
        this->insert(pos, *i);
      }
      other.clear();
    }
  }
};
}  // namespace s21
#endif  // LIST_H
