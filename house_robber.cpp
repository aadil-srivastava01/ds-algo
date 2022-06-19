/*

Problem Link: https://leetcode.com/problems/house-robber/

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// class Solution {
//  public:
//   void stratergise(auto& table, std::vector<int>& nums);
//   int rob(std::vector<int>& nums) { int size = nums.size() - 1; }
// };

int Kadane(std::vector<int>& vec) {
  int local_max{0}, global_max{INT_MIN};
  for (int i = 0; i < vec.size(); i++) {
    local_max = std::max(vec[i], vec[i] + local_max);
    if (local_max > global_max) global_max = local_max;
  }
  return global_max;
}

int main() {
  std::vector<int> v1{-2, -3, 4, -1, -2, 1, 5, -3};
  std::cout << Kadane(v1);
  std::cout << std::endl;

  return 0;
}