/*

Problem Link: Write a function that takes in an array of +ve integers and
returns maximum non-adjacent sums of integers

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maxSubsetSumNoAdjacent(std::vector<int> array) {
  int size = array.size();
  int local_max{0};
  if (size == 0) return 0;
  std::vector<int> dp(size + 1, 0);
  dp[1] = array[0];
  //   dp[2] = std::max(dp[1], array[1]);
  for (int i = 2; i <= size; i++) {
    local_max = std::max(dp[i - 1], dp[i - 2] + array[i - 1]);
    dp[i] = local_max;
  }
  return dp.back();
}

int main() {
  std::vector<int> v1{75, 105, 120, 75, 90, 135};
  std::cout << maxSubsetSumNoAdjacent(v1);
  std::cout << std::endl;
  return 0;
}