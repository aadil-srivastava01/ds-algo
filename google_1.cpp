/*

Problem Link:
You are given a function :-

f(n) = 3*n + 1, when n is odd,
f(n) = n/2, when n is even.

You are given a range of numbers from 1 to N, find the number which will give
maximum minimum number of steps using the above function.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int countstep(std::unordered_map<int, int> &dp, int n) {
  if (n == 2)
    return 1;
  else if (dp.find(n) != dp.end())
    return dp[n];

  else {
    if (n % 2 != 0) {
      dp.insert({n, 1 + countstep(dp, 3 * n + 1)});
      return dp[n];
    } else {
      dp.insert({n, 1 + countstep(dp, n / 2)});
      return dp[n];
    }
  }
}

std::vector<int> countMaxMin(int n) {
  if (n == 1) return std::vector<int>{0, 0};
  std::unordered_map<int, int> dp;
  dp.insert({1, 0});
  dp.insert({2, 1});
  int tmp;
  int max{INT_MIN};
  std::vector<int> v{0, 0};
  for (int i = 2; i <= n; i++) {
    countstep(dp, i);
    tmp = dp.at(i);
    if (max < tmp) {
      max = tmp;
      v[0] = i;
      v[1] = max;
    };
  }
  return v;
}

int main() {
  auto v = countMaxMin(5);
  std::cout << v[0] << ' ' << v[1];
  std::cout << std::endl;
  return 0;
}