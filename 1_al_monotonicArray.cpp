/*

Problem Link:
Write a function that takes in an array of integers and returns a boolean
representing whether the array is monotonic. An array is said to be monotonic if
its elements, from left to right, are entirely non-increasing or entirely
non-decreasing. Non-increasing elements aren't necessarily exclusively
decreasing; they simply don't increase. Similarly, non-decreasing elements
aren't necessarily exclusively increasing; they simply don't decrease. Note that
empty arrays and arrays of one element are monotonic.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isMonotonic(std::vector<int> array) {
  if (array.empty()) return true;
  auto size = array.size();
  if (size < 2) return true;

  bool last, current;
  bool eqlFlag{
      false};  // for handling the cases where first 2 elements are identical
  if (array.at(0) == array.at(1))
    eqlFlag = true;
  else
    last = (array.at(1) > array.at(0));
  size -= 1;
  for (int idx = 1; idx < size; idx++) {
    if (eqlFlag) {
      if (array.at(idx + 1) != array.at(idx)) {
        last = array.at(idx + 1) > array.at(idx);
        eqlFlag = false;
      }
    } else {
      current = (array.at(idx + 1) > array.at(idx));
      if (array.at(idx + 1) == array.at(idx)) {
        current = last;
        continue;
      }
      if (last != current) return false;
      last = current;
    }
  }
  return true;
}

int main() {
  std::vector<int> v1{1, 1, 1, 2};
  std::cout << isMonotonic(v1);
  std::cout << std::endl;
  return 0;
}