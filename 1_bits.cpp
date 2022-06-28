/*

Problem Link: https://leetcode.com/problems/number-of-1-bits/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    unsigned int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
};

int main() {
  Solution s;
  std::cout << s.hammingWeight(111);
  std::cout << std::endl;
  return 0;
}