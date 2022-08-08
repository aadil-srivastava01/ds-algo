/*

Problem Link:
IMplement Kadan'e algorithm
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int kadanesAlgorithm(std::vector<int> array) {
  int maxSum{INT_MIN};
  int local_max{0};
  for (int idx = 0; idx < array.size(); idx++) {
    local_max = std::max(local_max + array.at(idx), array.at(idx));
    if (maxSum < local_max) maxSum = local_max;
  }
  return maxSum;
}

int main() {
  std::vector<int> v1{3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4};
  std::cout << kadanesAlgorithm(v1);
  std::cout << std::endl;
  return 0;
}