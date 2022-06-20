/*

Problem Link: https://leetcode.com/problems/house-robber/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int rob_smartly(std::vector<int>& nums, int size, int idx,
                  std::vector<int>& dp) {
    if (idx >= size)
      return 0;
    else if (dp[idx] != -1)
      return dp[idx];
    else {
      dp[idx] = std::max(nums[idx] + rob_smartly(nums, size, idx + 2, dp),
                         rob_smartly(nums, size, idx + 1, dp));
      return dp[idx];
    }
  }
  int rob(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> dp(size + 1, -1);
    return rob_smartly(nums, size, 0, dp);
  }
};

int main() {
  std::vector<int> v1{8, 9, 3, 1, 1, 2};
  Solution s1;
  std::cout << s1.rob(v1);
  std::cout << std::endl;

  return 0;
}