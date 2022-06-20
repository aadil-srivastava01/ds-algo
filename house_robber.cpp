/*

Problem Link: https://leetcode.com/problems/house-robber/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Memoization
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
// Dynamic Programming

class Solution2 {
 public:
  int rob(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> dp(size + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= size; i++) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[size];
  }
};

int main() {
  std::vector<int> v1{8, 9, 3, 1, 1, 2};
  Solution s1;
  Solution2 s2;
  std::cout << s1.rob(v1) << std::endl;
  std::cout << s2.rob(v1);
  std::cout << std::endl;

  return 0;
}