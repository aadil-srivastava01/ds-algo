/*

Problem :
Merge Sorted Arrays
Write a function that takes in a non-empty list of non-empty sorted arrays of
integers and returns a merged list of all of those arrays. The integers in the
merged list should be in sorted order.
Sample Input arrays = [ [1, 5, 9, 21],
[-1, 0],
[-124, 81, 121],
[3, 6, 12, 20, 150]]
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> merge(std::vector<std::vector<int>> &arrays, int lb, int ub) {
  if (lb >= ub) return arrays.at(lb);

  int mid = {(lb + ub) / 2};
  auto m1 = merge(arrays, lb, mid);
  auto m2 = merge(arrays, mid + 1, ub);

  int s1 = m1.size();
  int s2 = m2.size();
  int total_size{s1 + s2};
  int p1{0}, p2{0}, i{0};

  std::vector<int> merged(s1 + s2, 0);
  while (i < total_size) {
    if (p1 == s1) {
      merged[i] = m2[p2];
      p2++;
    } else if (p2 == s2) {
      merged[i] = m1[p1];
      p1++;
    } else if (m1[p1] > m2[p2]) {
      merged[i] = m2[p2];
      p2++;
    } else {
      merged[i] = m1[p1];
      p1++;
    }
    i++;
  }
  return merged;
}

std::vector<int> mergeSortedArrays(std::vector<std::vector<int>> arrays) {
  return merge(arrays, 0, arrays.size() - 1);
}

int main() {
  std::vector<int> v1{1, 5, 9, 21};
  std::vector<int> v2{-1, 0};
  std::vector<int> v3{-124, 81, 121};
  std::vector<int> v4{3, 6, 12, 20, 150};
  std::vector<std::vector<int>> arrays{v1, v2, v3, v4};

  auto merged = mergeSortedArrays(arrays);

  std::for_each(merged.begin(), merged.end(),
                [](int x) { std::cout << x << ' '; });
  std::cout << std::endl;
  return 0;
}