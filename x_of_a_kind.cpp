/*

Problem Link: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool hasGroupsSizeX(std::vector<int>& deck) {
    if (deck.size() < 2) return false;
    std::unordered_map<int, int> counter;
    for (const int& item : deck) {
      counter[item] += 1;
    }
    int prev = counter[deck.at(0)];
    int curr{0};
    for (auto i = counter.begin(); i != counter.end(); i++) {
      if (prev == 1) return false;
      curr = i->second;
      if (curr != prev) return false;
      prev = curr;
    }
    return true;
  }
};

int main() {
  Solution s1;
  std::vector<int> v{1, 1, 2, 2, 2, 2};
  std::cout << s1.hasGroupsSizeX(v);
  std::cout << std::endl;
  return 0;
}