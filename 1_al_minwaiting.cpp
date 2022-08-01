/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minimumWaitingTime(std::vector<int> queries) {
  auto size = queries.size();
  if (size < 2) return 0;
  std::sort(queries.begin(), queries.end());
  int minWaitTime{0}, totalWaitTime{0};
  for (size_t i = 1; i < size; i++) {
    minWaitTime += queries.at(i - 1);
    totalWaitTime += minWaitTime;
  };
  return totalWaitTime;
}

int main() {
  std::vector<int> v1{3, 2, 1, 2, 6};
  std::cout << minimumWaitingTime(v1);
  std::cout << std::endl;
  return 0;
}