/*

Problem Link: https://leetcode.com/problems/add-digits/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
Applyting Congruence Formula
 digit_sum = {

                0 is n = 0
                1 + (n-1) mod (base-1) of n!=0
 }
 */
class Solution {
 public:
  int addDigits(int num) {
    if (num == 0) return 0;
    return (1 + ((num - 1) % (9)));
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}