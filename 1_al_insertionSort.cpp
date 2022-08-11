/*

Problem Link: Implement Insertion Sort

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> insertionSort(std::vector<int> &array) {
  auto size = array.size();
  int ptr1{0};
  for (int i = 0; i < size - 1; i++) {
    if (array.at(i) > array.at(i + 1)) {
      std::swap(array.at(i), array.at(i + 1));
      for (int j = ptr1; j >= 1; j--) {
        if (array.at(j - 1) > array.at(j))
          std::swap(array.at(j - 1), array.at(j));
      }
      ptr1++;
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