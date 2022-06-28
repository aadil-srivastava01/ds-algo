/*

Problem Link: https://leetcode.com/problems/two-sum/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashmap;
    int complement{0};
    std::vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      complement = target - nums[i];
      if (hashmap.find(complement) != hashmap.end()) {
        result.emplace_back(i);
        result.emplace_back(hashmap[complement]);
        return result;
      } else
        hashmap[nums[i]] = i;
    }
    return result;
  }
};

int main() {
  Solution s1;
  std::vector<int> v1{2, 7, 11, 15};
  auto res = s1.twoSum(v1, 9);
  std::for_each(res.begin(), res.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}