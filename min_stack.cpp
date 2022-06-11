/*

Problem Link: https://leetcode.com/problems/min-stack/

*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

class MinStack {
 public:
  std::deque<int> stack;

  void push(int val);
  void pop();
  int top();
  int getMin();
};

void MinStack::push(int val) { stack.emplace_front(val); }
void MinStack::pop() { stack.pop_front(); }
int MinStack::top() { return stack.at(0); }

int main() {
  std::cout << std::endl;
  return 0;
}