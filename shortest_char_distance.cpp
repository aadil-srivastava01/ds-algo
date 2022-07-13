/*

Problem Link: https://leetcode.com/problems/shortest-distance-to-a-character/

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> shortestToChar(std::string s, char c) {
    if (s.size() == 1) return std::vector(1, 0);
    std::vector<int> tracker(s.size(), 0), tracker2;
    for (int i = 0; i < s.size(); i++) {
      if (c == s.at(i)) tracker2.emplace_back(i);
    }
    int curr{0}, prev{0};

    for (int i = 0; i < s.size(); i++) {
      if (i <= tracker2.at(prev)) {
        tracker.at(i) = std::abs(tracker2.at(prev) - i);
      } else if (i >= tracker2.at(prev) && i < tracker2.at(curr)) {
        tracker.at(i) = std::min(std::abs(tracker2.at(prev) - i),
                                 std::abs(tracker2.at(curr) - i));
      } else if (i >= tracker2.at(curr))
        tracker.at(i) = std::abs(tracker2.at(curr) - i);
      if (curr < tracker2.size() - 1 && i >= tracker2.at(curr)) {
        prev = curr;
        curr++;
      }
    }
    return tracker;
  }
};

int main() {
  Solution s1;
  s1.shortestToChar("aaba", 'b');
  std::cout << std::endl;
  return 0;
}