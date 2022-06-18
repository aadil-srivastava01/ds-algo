/*

Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SlowSolution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int size = prices.size();
    if (size == 1) return 0;
    int max{0};
    int base{0}, tmp{0};
    for (int i = 0; i < size; i++) {
      base = prices[i];
      for (int j = i + 1; j < size; j++) {
        tmp = prices[j] - base;
        if (tmp > max) max = tmp;
      }
    }
    return max;
  }
};

class DPSolution {
 public:
  int maxProfit(std::vector<int>& prices) {}
};

int main() {
  SlowSolution s1;
  std::vector<int> v1{2, 4, 1};
  std::cout << s1.maxProfit(v1);
  std::cout << std::endl;

  return 0;
}