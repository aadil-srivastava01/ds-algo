/*

Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
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

int main() {
  std::string s1{"leetcode"};
  Solution s;
  std::cout << s.firstUniqChar(s1);
  std::cout << std::endl;
  return 0;
}