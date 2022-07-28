/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int nonConstructibleChange(std::vector<int> coins) {
  int size = coins.size();
  if (size == 0) return 1;
  std::sort(coins.begin(), coins.end());
  int maxValue{0};
  for (const int &coin : coins) {
    if (coin <= maxValue + 1)
      maxValue += coin;
    else
      return maxValue + 1;
  }
}

int main() {
  std::vector<int> v1{5, 7, 1, 1, 2, 3, 22};
  std::cout << nonConstructibleChange(v1);
  std::cout << std::endl;
  return 0;
}