/*

Problem Link: Implement Selection Sort Algorithm

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> selectionSort(std::vector<int> array) {
  auto size = array.size();
  int max, maxIdx{0};
  for (int idx = 0; idx < size; idx++) {
    max = INT16_MIN;
    maxIdx = -1;
    for (int i = 0; i < size - idx; i++) {
      if (array.at(i) > max) {
        max = array.at(i);
        maxIdx = i;
      }
    }
    std::swap(array.at(maxIdx), array.at(size - idx - 1));
  }

  return array;
}

int main() {
  std::cout << std::endl;
  return 0;
}