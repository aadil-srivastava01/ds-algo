/*

Problem Link:
perform bubble sort
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> array) {
  if (array.empty()) return array;
  int size = array.size() - 1;
  for (int topIdx = 0; topIdx < size; topIdx++) {
    for (int inIdx = 0; inIdx < size - topIdx; inIdx++) {
      if (array.at(inIdx) > array.at(inIdx + 1))
        std::swap(array.at(inIdx), array.at(inIdx + 1));
    }
  }
  return array;
}

int main() {
  std::cout << std::endl;
  return 0;
}