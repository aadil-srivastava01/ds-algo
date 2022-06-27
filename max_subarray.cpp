/*

Problem Link: https://leetcode.com/problems/maximum-subarray/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int global_max{INT_MIN};
    int local_max{0};
    for (int i = 0; i < nums.size(); i++) {
      local_max = std::max(nums[i], local_max + nums[i]);
      if (local_max > global_max) global_max = local_max;
    }
    return global_max;
  }
};

int main() {
  std::vector<int> v1{5,4,-1,7,8};
  Solution s1;
  std::cout << s1.maxSubArray(v1) << std::endl;
  return 0;
}