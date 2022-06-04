/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    size_t len = nums.size();
    if (len == 1 | len == 0) return;
    std::rotate(nums.rbegin(), nums.rbegin() + (k % len), nums.rend());
  }
};

class Solution2 {
 public:
  void rotate(std::vector<int>& nums, int k) {
    std::list<int> rlist;
    size_t len = nums.size();
    if (len == 1 | len == 0) return;
    int temp{0};
    for (const auto& item : nums) rlist.emplace_back(item);
    nums.clear();
    // nums.reserve(len);
    for (int i = 1; i <= (k % len); i++) {
      temp = rlist.back();
      rlist.pop_back();
      rlist.push_front(temp);
    }
    for (const auto& item : rlist) nums.push_back(item);
  }
};

int main() {
  //   Solution s1;
  Solution2 s2;
  std::vector<int> v1{-1};
  s2.rotate(v1, 5);

  std::cout << '[' << ' ';
  std::for_each(v1.begin(), v1.end(),
                [](auto& vec) { std::cout << (vec) << ' '; });
  std::cout << ' ' << ']';
  std::cout << std::endl;
  return 0;
}