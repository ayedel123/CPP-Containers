#ifndef CPP2_S21_CONTAINERS_1_VECTOR_FUNCTIONS_H_
#define CPP2_S21_CONTAINERS_1_VECTOR_FUNCTIONS_H_

//#include "vector.h"

class reference;
namespace s21 {

// functions
template <class T>
vector<T>::vector() : begin_(nullptr), size_(0), capacity_(0) {}

template <class T>
vector<T>::vector(size_type n) {
  begin_ = new T[n];
  size_ = n, capacity_ = n;
}

template <class T>
vector<T>::vector(const std::initializer_list<value_type> &items) {
  size_ = items.size();
  capacity_ = items.size();
  begin_ = new T[capacity_];
  std::copy(items.begin(), items.end(), begin_);
}

template <class T>
vector<T>::vector(const vector<T> &v) : size_(v.size_), capacity_(v.capacity_) {
  begin_ = new T[capacity_];
  std::copy(v.begin_, v.begin_ + size_, begin_);
}

template <typename T>
vector<T>::vector(vector<T> &&v) noexcept {
  if (this != &v) {
    delete[] begin_;
    size_ = 0;
    capacity_ = 0;
    begin_ = nullptr;
    std::swap(size_, v.size_);
    std::swap(capacity_, v.capacity_);
    std::swap(begin_, v.begin_);
  }
}

template <class T>
vector<T>::~vector() {
  clear();
}

template <class T>
typename s21::vector<T> &s21::vector<T>::operator=(vector<T> &&v) noexcept {
  if (this != &v) {
    delete[] begin_;
    size_ = 0;
    capacity_ = 0;
    begin_ = nullptr;
    std::swap(size_, v.size_);
    std::swap(capacity_, v.capacity_);
    std::swap(begin_, v.begin_);
  }
  return *this;
}

// element_access
template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return begin_[pos];
}

template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return begin_[pos];
}

template <class T>
typename vector<T>::const_reference vector<T>::front() const {
  return *begin_;
}
template <class T>
typename vector<T>::const_reference vector<T>::back() const {
  auto temp_ = begin_;
  std::advance(temp_, size_ - 1);
  return *temp_;
}

template <class T>
typename vector<T>::iterator vector<T>::data() {
  return Iterator(this->begin_);
}

// capacity
template <class T>
bool vector<T>::empty() const {
  return !size_;
}

template <class T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <class T>
void vector<T>::reserve(size_type size) {
  T *new_arr = new T[size];
  capacity_ = size;
  memcpy(new_arr, begin_, size_ * sizeof(T));
  delete[] begin_;
  begin_ = new_arr;
}

template <class T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <class T>
void vector<T>::shrink_to_fit() {
  if (size_ != capacity_) {
    T *temp_ = new T[size_];
    capacity_ = size_;
    memcpy(temp_, begin_, size_ * sizeof(T));
    delete[] begin_;
    begin_ = temp_;
  }
}

// modifiers
template <class T>
void vector<T>::clear() {
  delete[] begin_;
  begin_ = nullptr, size_ = 0, capacity_ = 0;
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  if (pos == end()) {
    push_back(value);
  } else if (pos == begin()) {
    T *temp_ = new T[capacity_ + 1];
    temp_[0] = value;
    std::memcpy(temp_ + 1, begin_, size_ * sizeof(T));
    size_ += 1;
    std::memcpy(begin_, temp_, size_ * sizeof(T));
    delete[] temp_;
  } else {
    T *temp_ = new T[capacity_ + 1];
    memcpy(temp_, begin_, (pos - begin()) * sizeof(T));
    auto keker = pos - begin();
    temp_[pos - begin_] = value;
    memcpy(temp_, begin_, (end() - pos) * sizeof(T));
    size_ += 1;
    memcpy(begin_, temp_, size_ * sizeof(T));
    delete[] temp_;
  }
  return pos;
}

template <class T>
typename vector<T>::iterator vector<T>::insertt(iterator pos,
                                                const_reference value) {
  size_t index = pos - begin();
  if (size_ >= capacity_) {
    resize(capacity_ * 2);
  }
  for (size_t i = size_; i > index; --i) {
    begin_[i] = begin_[i - 1];
  }
  begin_[index] = value;
  ++size_;
  return Iterator(begin_ + index);
}

template <class T>
void vector<T>::erase(iterator pos) {
  T *temp_ = new T[capacity_ - 1];
  memcpy(temp_, begin_, pos - begin());
  memcpy(temp_, begin_, end() - pos);
  size_--;
  memcpy(begin_, temp_, size_ * sizeof(T));
  delete[] temp_;
}

template <class T>
void vector<T>::push_back(const_reference value) {
  reallocator();
  begin_[size_] = value;
  size_ += 1;
}

template <class T>
void vector<T>::pop_back() {
  size_--;
}

template <class T>
void vector<T>::swap(vector<T> &other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(begin_, other.begin_);
}

// iterators
template <class T>
typename s21::vector<T>::iterator vector<T>::begin() const {
  return Iterator(begin_);
}

template <class T>
typename s21::vector<T>::iterator vector<T>::end() const {
  return Iterator(begin_ + size_);
}

template <class T>
typename s21::vector<T>::const_iterator vector<T>::cbegin() const {
  return ConstIterator(begin_);
}

template <class T>
typename s21::vector<T>::const_iterator vector<T>::cend() const {
  return ConstIterator(begin_ + size_);
}

// additional

template <class T>
void vector<T>::filling() {
  for (size_type i = 0; i < size_; i++) {
    begin_[i] = i + 10;
  }
}

template <class T>
void vector<T>::reallocator() {
  if (!size_ && !capacity_) {
    capacity_ = 1;
  }
  if (size_ == capacity_) {
    capacity_ = capacity_ * 2;
  }
  T *temp_ = new T[capacity_];
  memcpy(temp_, begin_, size_ * sizeof(T));
  delete[] begin_;
  begin_ = new T[capacity_];
  memcpy(begin_, temp_, size_ * sizeof(T));
  delete[] temp_;
}
}  // namespace s21

#endif