/*

Problem Link: https://leetcode.com/problems/contains-duplicate/description/

*/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> s1;
    for (auto const& item : nums) {
      if (!s1.insert(item).second) return true;
    }
    return false;
  }
};

int main() {
  Solution s1;
  std::vector<int> v1{1, 2, 3, 4};
  std::cout << s1.containsDuplicate(v1);
  std::cout << std::endl;
  return 0;
}