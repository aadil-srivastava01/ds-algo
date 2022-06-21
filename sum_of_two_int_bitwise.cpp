/*

Problem Link: https://leetcode.com/problems/sum-of-two-integers/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  int getSum(int x, int y) {
    while (y != 0) {
      // carry should be unsigned to
      // deal with -ve numbers
      // carry now contains common
      // set bits of x and y
      unsigned carry = x & y;

      // Sum of bits of x and y where at
      // least one of the bits is not set
      x = x ^ y;

      // Carry is shifted by one so that adding
      // it to x gives the required sum
      y = carry << 1;
    }
    return x;
  }
};
int main() {
  Solution s1;
  std::cout << s1.getSum(2, 2);
  std::cout << std::endl;
  return 0;
}