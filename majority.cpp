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

// O(n) time and O(1)Space complexity(Using Boyre Moore Algorithm)
class Solution2 {
 public:
  int majorityElement(std::vector<int>& nums) {
    int candidate{nums[0]}, vote{1};
    int size = nums.size();
    if (size == 1) return candidate;

    for (int i = 1; i < size; i++) {
      if (nums[i] == candidate)
        vote++;
      else
        vote--;
      if (vote == 0) {
        candidate = nums[i];
        vote = 1;
      }
    }
    // Since it is granteed in the problem that there will be a
    // majority element, hence not running the second loop
    return candidate;
    // int counter{0};
    // for (int i = 0; i < nums.size(); i++) {
    //   if (nums[i] == candidate) counter++;
    // }
    // if (counter > nums.size() / 2) return candidate;
    // return SIZE_MAX;
  }
};

int main() {
  std::vector<int> v1{3, 1, 3, 2, 3, 4, 3};
  Solution2 s1;
  std::cout << s1.majorityElement(v1);
  std::cout << std::endl;
  return 0;
}