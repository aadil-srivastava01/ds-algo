/*

Problem Link: https://leetcode.com/problems/sort-array-by-parity/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    std::stable_partition(nums.begin(), nums.end(),
                          [](int x) { return (x % 2 == 0); });
    return nums;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}