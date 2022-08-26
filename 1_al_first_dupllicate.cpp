/*

Problem Link:

Given an array of integers between 1 and n, inclusive, where n is the length of
the array, write a function that returns the first integer that appears more
than once (when the array is read from left to right). In other words, out of
all the integers that might occur more than once in the input array, your
function should return the one whose first duplicate value has the minimum
index. If no integer appears more than once, your function should return -1.
Note that you're allowed to mutate the input array.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

// O(n): Time & Space
int firstDuplicateValue(std::vector<int> array) {
  std::unordered_set<int> haveSeen;
  for (const int &val : array) {
    if (haveSeen.find(val) != haveSeen.end())
      return val;
    else
      haveSeen.insert(val);
  }
  return -1;
}
// O(n) Time & O(1) Space
int optFirstDuplicateValue(std::vector<int> array) {
  int absVal;
  for (int &val : array) {
    absVal = std::abs(val);
    if (array.at(absVal - 1) < 0)
      return absVal;
    else
      array.at(absVal - 1) *= -1;
  }
  return -1;
}

int main() {
  std::vector<int> v1{2, 1, 5, 2, 3, 3, 4};
  std::cout << firstDuplicateValue(v1) << std::endl;
  std::cout << optFirstDuplicateValue(v1);
  std::cout << std::endl;
  return 0;
}