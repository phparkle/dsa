// The stack data structure supports adding and removing items by last in first
// out order (LIFO).
//
// FixedArrayStack is implemented with a fixed-size array of type T.

#pragma once

template<class T>
class FixedArrayStack {
public:
  // Creates a new stack with the given capacity
  FixedArrayStack(int cap) : arr_(new T[cap]), cap_(cap), size_(0) {
  }

  // Creates a new stack with the given stack
  FixedArrayStack(const FixedArrayStack& other) :
    arr_(new T[other.cap_]), cap_(other.cap_), size_(other.size_) {
    for (int i = 0; i < size_; ++i)
      arr_[i] = other.arr_[i];
  }

  // Releases memory for the stack
  ~FixedArrayStack() {
    delete[] arr_;
  }

  // Returns true if the stack is empty
  bool empty() const {
    return size_ == 0;
  }

  // Returns the number of items in the stack
  int size() const {
    return size_;
  }

  // Adds an item to the top of the stack
  void push(T item) {
    if (size_ == cap_)
      throw out_of_range("Stack overflow");
    arr_[size_++] = item;
  }

  // Removes the item at the top of the stack
  void pop() {
    if (size_ == 0)
      throw out_of_range("Stack underflow");
    arr_[--size_].~T();
  }

  // Returns the item at the top of the stack
  T top() const {
    if (size_ == 0)
      throw out_of_range("Stack underflow");
    return arr_[size_ - 1];
  }

private:
  T * const arr_;
  const int cap_;
  int size_;
};
