/*

Problem : Merge Two Sorted arrays in 1 sorted array.

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> MergeSortArr(std::vector<int> &v1, std::vector<int> &v2) {
  size_t l1 = v1.size();
  size_t l2 = v2.size();

  if (!l1)
    return v2;
  else if (!l2)
    return v1;
  else {
    std::vector<int> v_com;
    v_com.reserve(l1 + l2);
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while (it1 != v1.end() & it2 != v2.end()) {
      if (*it1 > *it2) {
        v_com.push_back((*it2));
        it2++;
        continue;
      } else if (*it1 < *it2) {
        v_com.push_back((*it1));
        it1++;
        continue;
      }
    }
    if (it1 == v1.end()) {
      std::copy(it2, v2.end(), std::back_inserter(v_com));
    } else {
      std::copy(it1, v1.end(), std::back_inserter(v_com));
    }
    return v_com;
  }
}

int main() {
  std::vector<int> v1{7, 8, 9, 10};
  std::vector<int> v2{1, 2, 3, 11};
  auto v3 = MergeSortArr(v1, v2);
  std::cout << v3.capacity() << std::endl;
  std::for_each(v3.begin(), v3.end(), [](auto i) { std::cout << i; });
  std::cout << std::endl;
  return 0;
}