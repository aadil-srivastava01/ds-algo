/*

Problem Link: https://leetcode.com/problems/move-zeroes/

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

// Space Complexity O(n) and in-place solution, Time Complexity: O(n)
class Solution {
 public:
  void moveZeroes(std::vector<int> &nums) {
    std::vector<int> v1;
    int zero_count{0};
    v1.reserve(nums.size());
    for (const auto &item : nums) {
      if (item == 0) {
        zero_count++;
        continue;
      }

      else {
        v1.emplace_back(item);
      }
    }
    while (zero_count > 0) {
      v1.emplace_back(0);
      zero_count--;
    }
    nums.swap(v1);
    std::for_each(nums.begin(), nums.end(), [](auto i) { std::cout << i; });
    std::cout << std::endl;
  }
};

// Solution 2 Space: O(1), time: O(n)

class Solution2 {
 public:
  void moveZeroes(std::vector<int> &nums) {
    std::stable_partition(nums.begin(), nums.end(), [](int x) { return x; });
  }
};

int main() {
  std::vector<int> v1{0, 1, 0, 3, 12};
  //   auto l1 = MoveZeros1(v1);
  //   Solution s1;
  Solution2 s2;
  //   s1.moveZeroes(v1);
  s2.moveZeroes(v1);
  std::for_each(v1.begin(), v1.end(), [](auto i) { std::cout << i; });
  std::cout << std::endl;
  return 0;
}