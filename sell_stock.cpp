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
    int size = prices.size();
    if (size == 1) return 0;
    std::vector<int> profit_vec;
    profit_vec.reserve(size);
    int base = prices.at(0);
    int max(0);
    int tmp{0};
    for (int i = 0; i < size; i++) {
      tmp = prices[i] - base;
      if (tmp > max) {
        max = tmp;
        profit_vec.push_back(prices[i] - base);
      }
    }
    int curr_ptr{1};
    int relative_size{0};
    for (int i = 0; i < size; i++) {
      if (i < curr_ptr) {
        profit_vec[i] = -1;
        continue;
      }
      relative_size = -1 * (base - prices[curr_ptr]);
        }
  }
};

int main() {
  Solution s1;
  std::vector<int> v1{7, 6, 4, 3, 1};
  std::cout << s1.maxProfit(v1);
  std::cout << std::endl;

  return 0;
}