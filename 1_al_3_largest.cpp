/*

Problem Link:
Write a function that takes in an array of at least three integers and, without
sorting the input array, returns a sorted array of the three largest integers in
the input array. The function should return duplicate integers if necessary; for
example, it should return [10, 10, 12] for an input array of [10, 5, 9, 10, 12].
Sample Input
array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
Output:
[8,141,541]

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findThreeLargestNumbers(std::vector<int> array) {
  if (array.size() == 3) {
    std::sort(array.begin(), array.end());
    return array;
  }
  std::unordered_map<int, int> threeTracker;
  int max{0}, max_idx{-1};
  std::vector<int> maxThree;

  for (int i = 0; i < 3; i++) {
    max = INT_MIN;
    max_idx = -1;
    for (int idx = 0; idx < array.size(); idx++) {
      if (max < array.at(idx) && threeTracker.find(idx) == threeTracker.end()) {
        max = array.at(idx);
        max_idx = idx;
      }
    }
    threeTracker[max_idx] = max;
  }
  for (auto &items : threeTracker) maxThree.emplace_back(items.second);
  std::sort(maxThree.begin(), maxThree.end());
  return maxThree;
}

int main() {
  std::vector<int> v1{141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
  auto res = findThreeLargestNumbers(v1);
  std::cout << std::endl;
  return 0;
}