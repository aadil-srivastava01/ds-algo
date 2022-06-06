/*

Problem Link: https://leetcode.com/problems/majority-element/

*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// O(n) Space and time complexity
class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    int majority = nums.size() / 2;
    std::map<int, int> m1;
    for (auto& item : nums) {
      m1[item] = m1[item] + 1;
      if (m1[item] > majority) return item;
    }
  }
};

int main() {
  std::vector<int> v1{2, 2, 1, 1, 1, 2, 2};
  Solution s1;
  std::cout << s1.majorityElement(v1);
  std::cout << std::endl;
  return 0;
}