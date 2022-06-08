/*

Problem Link: https://leetcode.com/problems/rotate-image/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1)
      return;
    else {
      int tmp{0};
      for (int i = 0; i < n / 2; i++) matrix.at(i).swap(matrix.at((n -1) - i));
      for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
          tmp = matrix[i][j];
          matrix[i][j] = matrix[j][i];
          matrix[j][i] = tmp;
        }
      }
    }
  }
};

int main() {
  std::vector<std::vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  Solution s1;
  s1.rotate(matrix);

  std::cout << "[ ";
  for (const auto &row : matrix) {
    std::cout << "[ ";
    for (const auto &col : row) std::cout << col << " ";
    std::cout << " ]";
  }
  std::cout << " ]";

  std::cout << std::endl;
  return 0;
}