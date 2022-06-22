/*

Problem Link: https://leetcode.com/problems/excel-sheet-column-number/

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int titleToNumber(std::string columnTitle) {
    int val{0};
    int sum{0};
    for (auto i = columnTitle.rbegin(); i != columnTitle.rend(); i++) {
      sum += std::pow(26, val) * (int(*i) - 64);
      val++;
    }
    return sum;
  }
};

int main() {
  Solution s1;
  std::string str{"ZY"};
  std::cout << s1.titleToNumber(str);
  std::cout << std::endl;
  return 0;
}