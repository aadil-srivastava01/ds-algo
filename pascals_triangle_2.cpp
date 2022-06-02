/*

Problem : https://leetcode.com/problems/pascals-triangle-ii/

*/
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<int> generate(int numRows) {
    std::vector<int> tmp, tmp2;
    int sum{0};
    tmp = {1};

    if (numRows == 0) {
      return tmp;
    }
    tmp = {1, 1};
    if (numRows == 1) {
      return tmp;
    }

    else {
      for (int i = 2; i <= numRows; i++) {
        for (int j = 0; j < tmp.size() - 1; j++) {
          if (j == 0) tmp2.emplace_back(1);
          sum = tmp[j] + tmp[j + 1];
          tmp2.emplace_back(sum);
        }
        tmp2.emplace_back(1);
        tmp = tmp2;
        tmp2.clear();
      }
      return tmp;
    }
  }
};

void print_vec(const std::vector<int> &v1) {
  std::cout << '[';
  for (auto &item : v1) {
    std::cout << item << ' ';
  }
  std::cout << ']';
}
int main() {
  Solution s1;
  auto ans = s1.generate(1);
  print_vec(ans);
  std::cout << std::endl;
  return 0;
}