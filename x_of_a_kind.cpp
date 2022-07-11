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
    std::unordered_map<int, int> counter;
    for (const int& item : deck) {
      counter[item] += 1;
    }
    
  }
};

int main() {
  Solution s1;
  std::vector<int> v{1, 2, 3, 4, 4, 3, 2, 1};
  s1.hasGroupsSizeX(v);
  std::cout << std::endl;
  return 0;
}