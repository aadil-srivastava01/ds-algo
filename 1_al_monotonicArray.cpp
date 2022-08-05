/*

Problem Link:

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
  bool eqlFlag{false};
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