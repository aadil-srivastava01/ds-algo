/*

Problem Link: https://leetcode.com/problems/missing-number/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    int size = nums.size();
    int sum_ideal{0}, sum_local{0};
    for (int i = 0; i <= size; i++) {
      if (i < size) sum_local += nums[i];
      sum_ideal += i;
    }
    return sum_ideal - sum_local;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}