/*

Problem Link: Implement Insertion Sort

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> insertionSort(std::vector<int> &array) {
  auto size = array.size();
  int inIdx;
  for (int outIdx = 1; outIdx < size; outIdx++) {
    if (array.at(outIdx - 1) > array.at(outIdx)) {
      inIdx = outIdx;
      while (inIdx > 0) {
        if (array.at(inIdx - 1) < array.at(inIdx)) {
          break;
        } else {
          std::swap(array.at(inIdx), array.at(inIdx - 1));
        }
        inIdx--;
      }
    }
  }
  return array;
}

int main() {
  std::vector<int> v1{5, 3, 7, 1, 8, 2, 9, 0};
  auto res = insertionSort(v1);
  std::cout << std::endl;
  return 0;
}