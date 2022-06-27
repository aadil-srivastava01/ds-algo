/*

Problem : https://leetcode.com/problems/pascals-triangle/

*/
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> v1;
    std::vector<int> tmp, tmp2;
    int sum{0};

    v1 = {{1}};
    if (numRows == 1) {
      return v1;
    }
    tmp = {1, 1};
    v1.emplace_back(tmp);

    if (numRows == 2) {
      return v1;
    }

    else {
      for (int i = 3; i <= numRows; i++) {
        tmp.clear();
        tmp2.clear();
        tmp = v1.back();
        tmp2.emplace_back(1);
        for (int j = 0; j < tmp.size() - 1; j++) {
          sum = tmp[j] + tmp[j + 1];
          tmp2.emplace_back(sum);
        }
        tmp2.emplace_back(1);
        v1.emplace_back(tmp2);
      }
      return v1;
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
  auto ans = s1.generate(5);
  std::for_each(ans.begin(), ans.end(), [](auto &vec) {
    std::cout << '[';
    print_vec(vec);
    std::cout << ']';
  });
  std::cout << std::endl;
  return 0;
}