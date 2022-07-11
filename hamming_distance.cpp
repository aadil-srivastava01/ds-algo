/*

Problem Link: https://leetcode.com/problems/hamming-distance/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Using Brian Kernighan's Algorithm
class Solution {
 public:
  int hammingDistance(int x, int y) {
    x = x ^ y;
    int count{0};
    while (x > 0) {
      count++;
      x = x & (x - 1);
    }
    return count;
  }
};

int main() {
  Solution s1;
  std::cout << s1.hammingDistance(4, 1);
  std::cout << std::endl;
  return 0;
}