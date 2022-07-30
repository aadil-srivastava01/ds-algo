/*

Problem Link:

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> smallestDifference(std::vector<int> arrayOne,
                                    std::vector<int> arrayTwo) {
  int smallestDiff{INT_MAX};
  int diff{0};
  std::vector<int> pair;
  if (arrayOne.size() == 0 || arrayTwo.size() == 0) return pair;
  pair.emplace_back(0);
  pair.emplace_back(0);
  for (const int &item : arrayOne) {
    for (const int &item2 : arrayTwo) {
      diff = std::abs(item2 - item);
      if (diff < smallestDiff) {
        smallestDiff = diff;
        pair.at(0) = item;
        pair.at(1) = item2;
      }
    }
  }
  return pair;
}

int main() {
  std::cout << std::endl;
  return 0;
}