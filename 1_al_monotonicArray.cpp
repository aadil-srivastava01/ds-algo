/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isMonotonic(std::vector<int> array) {
  if (array.empty()) return true;
  auto size = array.size() - 1;
  if (size < 1) return true;
  bool last, current;
  if (array.at(1) == array.at(0))
    last = (array.at(2) > array.at(1));
  else
    last = (array.at(1) > array.at(0));
  for (int idx = 1; idx <= size - 1; idx++) {
    current = (array.at(idx + 1) >= array.at(idx));
    if (array.at(idx + 1) == array.at(idx)) current = last;
    if (last != current) return false;
    last = current;
  }
  return true;
}

int main() {
  std::vector<int> v1{-1, -1, -2, -3, -4, -5,  -5, -5,
                      -6, -7, -8, -8, -9, -10, -11};
  std::cout << isMonotonic(v1);
  std::cout << std::endl;
  return 0;
}