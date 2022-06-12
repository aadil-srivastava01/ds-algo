/*

Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int min = prices.at(0);
    int min_idx{0};
    int max = prices.at(0);
    int size = prices.size();
    if (size == 0) return 0;
    for (int i = 0; i < size; i++) {
      if (prices.at(i) < min) {
        min_idx = i;
        min = prices.at(i);
      }
    }
    if (min_idx == size - 1) return 0;
    max = prices.at(min_idx + 1);
    for (int j = min_idx + 2; j < size; j++) {
      if (prices.at(j) > max) {
        max = prices.at(j);
      }
    }
    return max > min ? (max - min) : 0;
  }
};

int main() {
  Solution s1;
  std::vector<int> v1{7,6,4,3,1};
  std::cout << s1.maxProfit(v1);
  std::cout << std::endl;

  return 0;
}