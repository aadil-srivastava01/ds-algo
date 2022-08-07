/*

Problem Link:

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int performBinarySearch(std::vector<int> &array, int lower, int upper,
                        int &target) {
  if (lower > upper) return -1;
  int midIdx = (upper + lower) / 2;
  int midVal = array.at(midIdx);
  if (midVal == target)
    return midIdx;
  else if (target < midVal)
    return performBinarySearch(array, lower, midIdx - 1, target);
  else
    return performBinarySearch(array, midIdx + 1, upper, target);
}

int binarySearch(std::vector<int> &array, int target) {
  if (array.empty()) return -1;

  return performBinarySearch(array, 0, array.size() - 1, target);
}

int main() {
  std::vector<int> v1{0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
  std::cout << binarySearch(v1, 33);
  std::cout << std::endl;
  return 0;
}