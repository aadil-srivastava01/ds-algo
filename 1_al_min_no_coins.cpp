/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int coinsOfADenom(int amount, int denom, int &noCoins) {
  while (amount >= denom) {
    noCoins++;
    amount -= denom;
  }
  return amount;
}

int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
  // Write your code here.
  std::sort(denoms.begin(), denoms.end(), [](int a, int b) { return a > b; });
  int remaningAmount{n}, noCoins{0};
  for (const int &denom : denoms) {
    if (denom > remaningAmount)
      continue;
    else if (remaningAmount == 0)
      break;
    remaningAmount = coinsOfADenom(remaningAmount, denom, noCoins);
  }
  if (remaningAmount == 0) return noCoins;
  return -1;
}

int main() {
  std::vector<int> v1{3, 5};
  std::cout << minNumberOfCoinsForChange(9, v1);
  std::cout << std::endl;
  return 0;
}