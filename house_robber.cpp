/*

Problem Link: https://leetcode.com/problems/house-robber/

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  void stratergise(auto& table, std::vector<int>& nums);
  int rob(std::vector<int>& nums) {
    int size = nums.size() - 1;
    std::unordered_map<std::vector<int>, size_t> rob_table;
    }
};

int main() {
  std::cout << std::endl;

  return 0;
}