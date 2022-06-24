/*

Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Inefficient_Solution {
 public:
  int firstUniqChar(std::string s) {
    if (s.size() == 1) return 0;
    std::unordered_map<char, std::pair<int, size_t>> counter;
    for (int i = 0; i < s.size(); i++) {
      if (counter[s[i]].second == 0) counter[s[i]].first = i;
      counter[s[i]].second += counter[s[i]].second + 1;
    }
    bool val_min = false;
    int val_idx = INT_MAX;
    for (const auto &vals : counter) {
      auto val = vals.second;
      if (val.second == 1) {
        if (val.first < val_idx) {
          val_idx = val.first;
          val_min = true;
        }
      }
    }
    if (val_min)
      return val_idx;
    else
      return -1;
  }
};

class Solution {
 public:
  int firstUniqChar(std::string s) {
    std::vector<size_t> v1(26, 0);
    for (const char &c : s) v1[c - 'a'] += 1;
    for (int i = 0; i < s.size(); i++) {
      if (v1.at(s[i] - 'a') == 1) return i;
    }
    return -1;
  }
};

int main() {
  std::string s1{"aabb"};
  Inefficient_Solution s;
  Solution s2;
  std::cout << s.firstUniqChar(s1) << std::endl;
  std::cout << s2.firstUniqChar(s1);
  std::cout << std::endl;
  return 0;
}