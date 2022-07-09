/*

Problem Link: https://leetcode.com/problems/power-of-two/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return ((n & (n - 1)) == 0);
  }
};

int main() {
  Solution s1;
  std::cout << s1.isPowerOfTwo(5);
  std::cout << std::endl;
  return 0;
}