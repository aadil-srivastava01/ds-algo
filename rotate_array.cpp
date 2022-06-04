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

class Solution3 {
 public:
  void reverse(std::vector<int>& nums, int begin_idx, int end_idx) {
    while (begin_idx < end_idx) {
      std::swap(nums.at(begin_idx), nums.at(end_idx));
      begin_idx++;
      end_idx--;
    }
  }
  void rotate(std::vector<int>& nums, int k) {
    int arr_size = nums.size();
    int end_idx = arr_size - (k % arr_size) - 1;
    if (arr_size == 1 | arr_size == 0) return;
    reverse(nums, 0, end_idx);
    reverse(nums, end_idx + 1, arr_size - 1);
    reverse(nums, 0, arr_size - 1);
  }
};

int main() {
  //   Solution s1;
  Solution3 s2;
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
  s2.rotate(v1, 3);

  std::cout << '[' << ' ';
  std::for_each(v1.begin(), v1.end(),
                [](auto& vec) { std::cout << (vec) << ' '; });
  std::cout << ' ' << ']';
  std::cout << std::endl;
  return 0;
}