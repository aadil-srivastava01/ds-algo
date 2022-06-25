/*

Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> intersection;
    int size_1 = nums1.size(), size_2 = nums2.size();
    std::vector<int> count_table(1001, 0);
    for (const int& item : nums1) {
      count_table[item] += 1;
    }
    for (const int& item : nums2) {
      if (count_table[item] != 0) {
        count_table[item] -= 1;
        intersection.emplace_back(item);
      }
    }
    return intersection;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}