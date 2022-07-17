/*

Problem Link:
Given an array of distinct positive integers representing coin denominations and
a single non negative integer n representing a target amount of money, write a
function that returns the number of ways to make change for that target amount
using the given coin denominations. Note that an unlimited amount of coins is at
your disposal.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int numberOfWaysToMakeChange(int n, std::vector<int> &denoms) {
  std::vector<int> total_ways(n + 1, 0);
  total_ways[0] = 1;
  for (int &denom : denoms) {
    for (int amount = 1; amount < n + 1; amount++) {
      if (amount >= denom) {
        total_ways[amount] += total_ways[amount - denom];
      }
    }
  }
  return total_ways.back();
}

int main() {
  std::vector<int> v1{1, 2, 3};
  std::cout << numberOfWaysToMakeChange(4, v1);
  std::cout << std::endl;
  return 0;
}