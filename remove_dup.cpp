/*

Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return 1;
    int ptr1{0};
    for (int i = 1; i < size; i++) {
      if (nums[ptr1] == nums[i])
        continue;
      else {
        std::swap(nums[ptr1 + 1], nums[i]);
        ptr1++;
      }
    }
    return ptr1 + 1;
  }
};

int main() {
  std::vector<int> v1{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution s1;
  std::cout << s1.removeDuplicates(v1) << std::endl;
  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}