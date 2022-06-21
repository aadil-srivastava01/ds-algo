/*

Problem Link: https://leetcode.com/problems/single-number/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int xor_result{0};
    for (int i = 0; i < nums.size(); i++) {
      xor_result = xor_result ^ nums[i];
    }
    return xor_result;
  }
};

int main() {
  std::vector<int> v1{4,1,2,1,2};
  Solution s1;
  std::cout << s1.singleNumber(v1);
  std::cout << std::endl;
  return 0;
}