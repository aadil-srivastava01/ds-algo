/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
  size_t size{denoms.size()};
  if (size == 0) return -1;
  std::sort(denoms.begin(), denoms.end(), [](int a, int b) { return a > b; });
  int numCoins{0}, remainingAmount{n}, change{0};
  for (const int &denom : denoms) {
    while (true) {
      if (remainingAmount / denom > 0) {
        change = remainingAmount % denom;
        remainingAmount /= denom;
      }
    }
    return -1;
  }

  int main() {
    std::vector<int> v1{3, 5};
    std::cout << minNumberOfCoinsForChange(9, v1);
    std::cout << std::endl;
    return 0;
  }