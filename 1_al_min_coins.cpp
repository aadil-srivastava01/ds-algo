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
  std::vector<int> minCoins(n + 1, -1);
  minCoins[0] = 0;
  for (const int &denom : denoms) {
    for (int amount = 1; amount < n + 1; amount++) {
      if (denom <= amount && minCoins[amount - denom] >= 0) {
        if (minCoins[amount] >= 0) {
          minCoins[amount] =
              std::min(minCoins[amount], 1 + minCoins[amount - denom]);
          continue;
        }
        minCoins[amount] = 1 + minCoins[amount - denom];
      }
    }
  }
  return minCoins.back();
}

int main() {
  std::vector<int> v1{1,2 };
  std::cout << minNumberOfCoinsForChange(3, v1);
  std::cout << std::endl;
  return 0;
}