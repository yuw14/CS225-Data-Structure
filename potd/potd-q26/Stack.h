#pragma once

#include <cstddef>
#include<stack>

class Stack {
public:
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
  std::stack<int> s;
};
