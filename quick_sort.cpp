/*

Problem Link: Quick Sort

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void quicksort(std::vector<int> &vec, int left, int right, int pivot) {
  if (left >= right) return;

  int i{left - 1};
  for (int j = left; j < right; j++) {
    if (vec[j] < vec[pivot]) {
      i++;
      std::swap(vec[i], vec[j]);
    }
  }
  i++;
  std::swap(vec[i], vec[pivot]);
  pivot = i;
  quicksort(vec, left, pivot - 1, pivot - 1);
  quicksort(vec, pivot + 1, right, right);
}

int main() {
  std::vector<int> v1{10, 80, 30, 90, 40, 50, 70};
  int size = (v1.size() - 1);
  quicksort(v1, 0, size, size);
  std::for_each(v1.begin(), v1.end(), [](int num) { std::cout << num << ' '; });
  std::cout << std::endl;
  return 0;
}