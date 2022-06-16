/*

Problem Link: Used Memoization to implement Fibonacci Number Generator

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Finonacci {
 public:
  std::unordered_map<int, int> lookup_table;
  int generate_fib(int n);
};

int Finonacci::generate_fib(int n) {
  if (n < 2) return n;
  if (lookup_table.contains(n)) {
    std::cout << "Using lookup for n =" << n << std::endl;
    return lookup_table.at(n);
  } else {
    lookup_table[n] = generate_fib(n - 1) + generate_fib(n - 2);
    return lookup_table.at(n);
  }
}

int main() {
  Finonacci fb;

  std::cout << fb.generate_fib(10);
  std::cout << std::endl;
  return 0;
}