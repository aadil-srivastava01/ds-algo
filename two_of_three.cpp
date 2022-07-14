/*

Problem Link: https://leetcode.com/problems/two-out-of-three/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> twoOutOfThree(std::vector<int>& nums1,
                                 std::vector<int>& nums2,
                                 std::vector<int>& nums3) {
    std::vector<int> ref1(101, 0);
    std::vector<int> ref2(101, 0);
    std::vector<int> ref3(101, 0);
    std::vector<int> res;

    for (int i = 0; i < nums1.size(); i++) {
      ref1[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2.size(); i++) {
      ref2[nums2[i]] = 1;
    }
    for (int i = 0; i < nums3.size(); i++) {
      ref3[nums3[i]] = 1;
    }
    for (int i = 0; i < 101; i++) {
      if ((ref1[i] + ref2[i] + ref3[i]) >= 2) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}