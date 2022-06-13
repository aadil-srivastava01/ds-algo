/*

Problem Link: Merge Sort Implementation

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void merge(std::vector<int> &vec, int left, int mid, int right) {
  int curr_left{left}, curr_right{mid + 1};
  int tmp[right - left + 1], idx{0};
  while ((curr_left <= mid) && (curr_right <= right)) {
    if (vec[curr_left] > vec[curr_right]) {
      tmp[idx] = vec[curr_right];
      curr_right++;
    } else if (vec[curr_left] < vec[curr_right]) {
      tmp[idx] = vec[curr_left];
      curr_left++;
    } else {
      tmp[idx] = vec[curr_left];
      idx++;
      tmp[idx] = vec[curr_right];
      curr_right++;
      curr_left++;
    }
    idx++;
  }
  if ((curr_left > mid) && (curr_right <= right))
    while (curr_right <= right) {
      tmp[idx] = vec[curr_right];
      curr_right++;
      idx++;
    }
  else {
    while (curr_left <= mid) {
      tmp[idx] = vec[curr_left];
      curr_left++;
      idx++;
    }
  }

  for (int i = left; i <= right; i++) {
    vec[i] = tmp[i - left];
  }
}

void mergesort(std::vector<int> &vec, int left, int right) {
  if (left >= right) return;

  int mid = ((right - left) / 2) + left;
  mergesort(vec, left, mid);
  mergesort(vec, mid + 1, right);
  merge(vec, left, mid, right);
}

int main() {
  std::vector<int> v1{7, 1, 5, 3, 6, 4, 2};
  mergesort(v1, 0, v1.size() - 1);
  std::for_each(v1.begin(), v1.end(), [](int i) { std::cout << i << " "; });
  std::cout << std::endl;
  return 0;
}