/*

Problem Link:
https://leetcode.com/problems/count-square-submatrices-with-all-ones/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int countSquares(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    int tmp{0};
    int counter{0}, min_v{0};
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (i == 0 || j == 0) {
          counter += matrix[i][j];
          continue;
        }
        tmp = matrix[i][j];
        if (tmp) {
          min_v = std::min(matrix[i - 1][j - 1],
                           std::min(matrix[i - 1][j], matrix[i][j - 1]));
          tmp = min_v + 1;
          counter += tmp;
          matrix[i][j] = tmp;
        } else
          continue;
      }
    }
    return counter;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}