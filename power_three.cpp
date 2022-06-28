/*

Problem Link: https://leetcode.com/problems/power-of-three/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  bool isPowerOfThree(double n) {
    if (n < 1)
      return false;
    else if (n == 1.0)
      return true;
    return isPowerOfThree(n / 3);
  }
};

int main() {
  Solution s;
  std::cout << s.isPowerOfThree(45);
  std::cout << std::endl;
  return 0;
}