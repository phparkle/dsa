#include "stdafx.h"

#include "../Source/ResizingArrayStack.h"

using namespace std;

TEST_CLASS(TestResizingArrayStack) {
public:
  TEST_METHOD(TestEmpty) {
    ResizingArrayStack<int> stack;
    Assert::IsTrue(stack.empty());
    stack.push(57);
    Assert::IsFalse(stack.empty());
    stack.pop();
    Assert::IsTrue(stack.empty());
    for (int i = 0; i < 12; ++i) {
      stack.push(data[i]);
      Assert::IsFalse(stack.empty());
    }
    for (int i = 0; i < 11; ++i) {
      stack.pop();
      Assert::IsFalse(stack.empty());
    }
    stack.pop();
    Assert::IsTrue(stack.empty());
  }

  TEST_METHOD(TestSize) {
    ResizingArrayStack<int> stack;
    Assert::AreEqual(0, stack.size());
    stack.push(57);
    Assert::AreEqual(1, stack.size());
    stack.pop();
    Assert::AreEqual(0, stack.size());
    for (int i = 0; i < 12; ++i) {
      stack.push(data[i]);
      Assert::AreEqual(i + 1, stack.size());
    }
    for (int i = 11; i >= 0; --i) {
      stack.pop();
      Assert::AreEqual(i, stack.size());
    }
  }

  TEST_METHOD(TestPopThrowsIfEmpty) {
    ResizingArrayStack<int> stack;
    Assert::ExpectException<out_of_range>([&]() {
      stack.pop();
    });
  }

  TEST_METHOD(TestTop) {
    ResizingArrayStack<int> stack;
    stack.push(57);
    Assert::AreEqual(57, stack.top());
    stack.pop();
    for (int i = 0; i < 12; ++i) {
      stack.push(data[i]);
      Assert::AreEqual(data[i], stack.top());
    }
    for (int i = 10; i >= 0; --i) {
      stack.pop();
      Assert::AreEqual(data[i], stack.top());
    }
  }

  TEST_METHOD(TestTopThrowsIfEmpty) {
    ResizingArrayStack<int> stack;
    Assert::ExpectException<out_of_range>([&]() {
      stack.top();
    });
  }

private:
  int data[12] = { 57, 25, 35, 2, 35, 94, 7, 25, 7, 71, 62, 73 };
};
