/*

Problem Link:

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

int optFirstDuplicateValue(std::vector<int> array) { return -1; }

int main() {
  std::vector<int> v1{2, 1, 5, 2, 3, 3, 4};
  std::cout << firstDuplicateValue(v1);
  std::cout << std::endl;
  return 0;
}