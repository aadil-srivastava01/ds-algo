/*

Problem Link: https://leetcode.com/problems/factorial-trailing-zeroes/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class naiveSolution {
 public:
  size_t fact(size_t val, int n) {
    if (n == 1) return val;
    return fact(val * n, n - 1);
  }
  int trailingZeroes(int n) {
    size_t num = fact(1, n);
    int count{0};
    while (num != 0) {
      if (num % 10 == 0) {
        count++;
        num /= 10;
        continue;
      }
      break;
    }
    return count;
  }
};

int main() {
  naiveSolution s;
  std::cout << s.trailingZeroes(10000);
  std::cout << std::endl;
  return 0;
}