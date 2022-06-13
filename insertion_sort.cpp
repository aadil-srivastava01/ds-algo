/*

Problem Link: Simple Insertion Sort

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void insertion_sort(std::vector<int> &arr) {
  int max{arr[0]};
  for (int i = 1; i < arr.size(); i++) {
    max = arr.at(i);
    if (arr.at(i - 1) > max) {
      std::swap(arr.at(i - 1), arr.at(i));
      for (int j = i - 1; j >= 1; j--) {
        if (arr.at(j - 1) > arr.at(j)) std::swap(arr.at(j - 1), arr.at(j));
      }
    }
  }
}

int main() {
  std::vector<int> v1{3, 1, 4, 2};
  insertion_sort(v1);
  std::for_each(v1.begin(), v1.end(), [](int &item) { std::cout << item; });
  std::cout << std::endl;
  return 0;
}