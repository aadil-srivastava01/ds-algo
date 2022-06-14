/*

Problem Link: Implementation of heapsort

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void heapify(std::vector<int> &vec, int idx) {
  int size = vec.size();
  if (idx >= size) return;
  int l_child = 2 * idx + 1, r_child = 2 * idx + 2;
  int max{};
  if (r_child < size) {
    if (vec.at(r_child) > vec.at(l_child))
      max = r_child;
    else
      max = l_child;

    if (vec.at(max) > vec.at(idx)) std::swap(vec.at(idx), vec.at(max));
  } else if (l_child < size)
    if (vec.at(l_child) > vec.at(idx)) std::swap(vec.at(idx), vec.at(l_child));
}

void build_max_heap(std::vector<int> &vec) {
  for (int i = vec.size() - 1; i >= 0; i--) heapify(vec, i);
}

void heapsort(std::vector<int> &vec) {
  int size = vec.size();
  build_max_heap(vec);
  for (int i = size - 1; i >= 1; i--) {
    std::swap(vec.at(0), vec.at(vec.size() - 1));
    std::cout << vec.back() << " ";
    vec.pop_back();
    build_max_heap(vec);
  }
}

int main() {
  std::vector<int> v1{1, 12, 9, 5, 6, 10};
  heapsort(v1);
  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << ' '; });
  std::cout << std::endl;
  return 0;
}