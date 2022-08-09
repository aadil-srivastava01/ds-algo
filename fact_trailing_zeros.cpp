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

class Solution {
 public:
  int trailingZeroes(int n) {
    while (n % 5 != 0) n--;
    int tmp{0};
    int count{0};
    for (int i = n; i >= 5; i -= 5) {
      tmp = i;
      while (tmp % 5 == 0) {
        count++;
        tmp /= 5;
      }
    }
    return count;
  }
};

class SimpleSolution {
 public:
  int trailingZeros(int n) {
    int numZeros{0};
    while (n > 0) {
      numZeros += n / 5;
      n = n / 5;
    }
    return numZeros;
  }
};

int main() {
  Solution s;
  std::cout << s.trailingZeroes(26);
  std::cout << std::endl;
  return 0;
}