// The stack data structure supports adding and removing items by last in first
// out order (LIFO).
//
// ResizingArrayStack is implemented with an array of type T. The array resizes
// automatically as the stack grows.

#pragma once

template<class T>
class ResizingArrayStack {
public:
  // Creates a new empty stack
  ResizingArrayStack() : arr_(nullptr), cap_(0), size_(0) {
  }

  // Destroys the stack
  ~ResizingArrayStack() {
    if (arr_)
      delete[] arr_;
  }

  // Creates a new stack as a copy of the other stack
  ResizingArrayStack(const ResizingArrayStack& other) :
    arr_(other.arr_ ? new T[other.cap_] : nullptr),
    cap_(other.cap_), size_(other.size_) {
    for (int i = 0; i < size_; ++i)
      arr_[i] = other.arr_[i];
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
      resize();
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
  // Resizes the array (doubling the capacity)
  void resize() {
    cap_ = cap_ ? 2 * cap_ : 1;
    T * const arr = new T[cap_];
    for (int i = 0; i < size_; ++i)
      arr[i] = arr_[i];
    if (arr_)
      delete[] arr_;
    arr_ = arr;
  }

  T * arr_;
  int cap_;
  int size_;
};
