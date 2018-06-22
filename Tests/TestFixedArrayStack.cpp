#include "stdafx.h"

#include "../Source/FixedArrayStack.h"

using namespace std;

TEST_CLASS(TestFixedArrayStack) {
public:
  TEST_METHOD(TestEmpty) {
    FixedArrayStack<int> stack(8);
    Assert::IsTrue(stack.empty());
    stack.push(57);
    Assert::IsFalse(stack.empty());
    stack.pop();
    Assert::IsTrue(stack.empty());
    for (int i = 0; i < 8; ++i) {
      stack.push(data[i]);
      Assert::IsFalse(stack.empty());
    }
    for (int i = 0; i < 7; ++i) {
      stack.pop();
      Assert::IsFalse(stack.empty());
    }
    stack.pop();
    Assert::IsTrue(stack.empty());
  }

  TEST_METHOD(TestSize) {
    FixedArrayStack<int> stack(8);
    Assert::AreEqual(0, stack.size());
    stack.push(57);
    Assert::AreEqual(1, stack.size());
    stack.pop();
    Assert::AreEqual(0, stack.size());
    for (int i = 0; i < 8; ++i) {
      stack.push(data[i]);
      Assert::AreEqual(i + 1, stack.size());
    }
    for (int i = 7; i >= 0; --i) {
      stack.pop();
      Assert::AreEqual(i, stack.size());
    }
  }

  TEST_METHOD(TestPopThrowsIfEmpty) {
    FixedArrayStack<int> stack(8);
    Assert::ExpectException<out_of_range>([&]() {
      stack.pop();
    });
  }

  TEST_METHOD(TestPushThrowsIfFull) {
    FixedArrayStack<int> stack(8);
    for (int i = 0; i < 8; ++i)
      stack.push(data[i]);
    Assert::ExpectException<out_of_range>([&]() {
      stack.push(7);
    });
  }

  TEST_METHOD(TestTop) {
    FixedArrayStack<int> stack(8);
    stack.push(57);
    Assert::AreEqual(57, stack.top());
    stack.pop();
    for (int i = 0; i < 8; ++i) {
      stack.push(data[i]);
      Assert::AreEqual(data[i], stack.top());
    }
    for (int i = 6; i > 0; --i) {
      stack.pop();
      Assert::AreEqual(data[i], stack.top());
    }
  }

  TEST_METHOD(TestTopThrowsIfEmpty) {
    FixedArrayStack<int> stack(8);
    Assert::ExpectException<out_of_range>([&]() {
      stack.top();
    });
  }

private:
  int data[12] = { 57, 25, 35, 2, 35, 94, 7, 25, 7, 71, 62, 73 };
};
