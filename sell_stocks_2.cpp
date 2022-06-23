/*

Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.size() == 1) return prices[0];
    int max_profit{0}, min_val = prices[0];
    bool buy{true};
    for (int i = 1; i < prices.size() - 1; i++) {
      if ((prices[i - 1] > prices[i]) && (prices[i + 1] > prices[i])) {
        buy = true;
        min_val = std::min(min_val, prices[i]);
      }
      //   } else if (buy == true && (prices[i + 1] > prices[i]) &&
      //              (prices[i - 1] < prices[i])) {
      //         continue;
      //   }
      else if (buy == true && (prices[i + 1] < prices[i]) &&
               (prices[i - 1] < prices[i])) {
        max_profit += (prices[i] - min_val);
        buy = false;

      } else if (buy == true && (i + 1 == prices.size() - 1)) {
        max_profit += prices[i + 1] - min_val;
        buy = false;
      }
    }
    return max_profit;
  }
};

int main() {
  std::vector<int> v1{1, 2, 3, 4, 5};
  Solution s1;
  std::cout << s1.maxProfit(v1);
  std::cout << std::endl;
  return 0;
}