/*

Problem Link: https://leetcode.com/problems/happy-number/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  size_t digit_sq_sum(int num) {
    int sum{0};
    short digit{0};
    while (num != 0) {
      digit = num % 10;
      sum = sum + (digit * digit);
      num = num / 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    int sum;
    std::unordered_set<int> past_sums;
    while (n != 1) {
      sum = digit_sq_sum(n);
      if (!past_sums.insert(sum).second) return false;
      n = sum;
    }
    return true;
  }
};

int main() {
  Solution s1;
  std::cout << s1.isHappy(19);
  std::cout << std::endl;
  return 0;
}