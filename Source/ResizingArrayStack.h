// TODO Add description

#pragma once

template<class T>
class ResizingArrayStack {
public:
  // Creates a new empty stack
  ResizingArrayStack() {

  }

  // Destroys the stack
  ~ResizingArrayStack() {

  }

  // Creates a new stack as a copy of the other stack
  ResizingArrayStack(const ResizingArrayStack& other) {

  }

  // Returns true if the stack is empty
  bool empty() const {
    return false;
  }

  // Returns the number of items in the stack
  int size() const {
    return 0;
  }

  // Adds an item to the top of the stack
  void push(T item) {

  }

  // Removes the item at the top of the stack
  void pop() {

  }

  // Returns the item at the top of the stack
  T top() const {
    return T();
  }

private:
  // Resizes the array (doubling the capacity)
  void resize() {

  }

  // TODO Add data members
};
