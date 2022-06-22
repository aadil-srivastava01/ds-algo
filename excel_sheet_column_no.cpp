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
    std::unordered_map<char, int> mapper;
    int val{1};
    for (char c = 'A'; c <= 'Z'; c++) {
      mapper[c] = val;
      val++;
    }
    int sum{0};
    val = 0;
    for (auto i = columnTitle.rbegin(); i != columnTitle.rend(); i++) {
      sum += std::pow(26, val) * (mapper.at(*i));
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