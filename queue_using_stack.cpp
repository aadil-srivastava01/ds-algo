/*

Problem Link:
https://leetcode.com/problems/implement-queue-using-stacks/description/

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

// naive approach
class MyQueue {
 public:
  std::stack<int> s1;
  std::stack<int> s2;
  MyQueue() {}

  void push(int x) {
    if (s2.empty())
      s1.push(x);
    else if (s1.empty() && !s2.empty()) {
      while (s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }
  }

  int pop() {
    if (s2.empty() && !s1.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      int tmp = s2.top();
      s2.pop();
      return tmp;
    } else if (s2.empty() && s1.empty()) {
      return -1;
    } else {
      int tmp = s2.top();
      s2.pop();
      return tmp;
    }
  }

  int peek() {
    if (s2.empty() && !s1.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      return s2.top();
    }

    else if (s2.empty() && s1.empty())
      return -1;

    else
      return s2.top();
  }

  bool empty() {
    if (s2.empty() && s1.empty())
      return true;
    else
      return false;
  }
};

int main() {
  // ["MyQueue", "push", "push", "peek", "pop", "empty"]

  MyQueue q1;
  q1.push(1);
  q1.push(2);
  std::cout << q1.peek() << std::endl;
  q1.pop();
  std::cout << q1.empty() << std::endl;

  std::cout << std::endl;
  return 0;
}