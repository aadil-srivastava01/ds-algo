/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    size_t len = nums.size();
    if (len == 1 | len == 0) return;
    std::rotate(nums.rbegin(), nums.rbegin() + (k % len), nums.rend());
  }
};

int main() {
  Solution s1;
  std::vector<int> v1{-1, 2};
  s1.rotate(v1, 5);
  std::cout << '[' << ' ';
  std::for_each(v1.begin(), v1.end(),
                [](auto& vec) { std::cout << (vec) << ' '; });
  std::cout << ' ' << ']';
  std::cout << std::endl;
  return 0;
}