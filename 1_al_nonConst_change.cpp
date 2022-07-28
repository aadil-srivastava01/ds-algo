/*

Problem Link:
Given an array of positive integers representing the values of coins in your
possession, write a function that returns the minimum amount of change (the
minimum sum of money) that you cannot create. The given coins can have any
positive integer value and aren't necessarily unique (i.e., you can have
multiple coins of the same value). For example, if you're given coins = [1, 2,
5], the minimum amount of change that you can't create is 4. If you're given no
coins, the minimum amount of change that you can't create is 1.
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
  return maxValue + 1;
}

int main() {
  //   std::vector<int> v1{5, 7, 1, 1, 2, 3, 22};
  std::vector<int> v1{1, 2, 5};
  std::cout << nonConstructibleChange(v1);
  std::cout << std::endl;
  return 0;
}