#pragma once

#include <stack>

template <typename T>
class RPN {
public:
  RPN();
  RPN(const RPN &);
  RPN &operator=(RPN &&) ;
  RPN &operator=(const RPN &);
  ~RPN();


private:
  std::stack<T> _stack;
};

RPN::RPN() {
}

RPN::~RPN() {
}
