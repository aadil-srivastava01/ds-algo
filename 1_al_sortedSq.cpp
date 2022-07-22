/*

Problem Link:
Write a function that takes in a non-empty array of integers that are sorted in
ascending order and returns a new array of the same length with the squares of
the original integers also sorted in ascending order.

*/

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> sortedSquaredArray(std::vector<int> array) {
  std::deque<int> absSortedArray;
  std::vector<int> answer(array.size(), 0);
  int pointer1{0}, pointer2 = array.size() - 1;

  while (pointer1 <= pointer2) {
    if (std::abs(array[pointer1]) >= array[pointer2]) {
      absSortedArray.emplace_front(array[pointer1]);
      pointer1++;
      continue;
    } else {
      absSortedArray.emplace_front(array[pointer2]);
      pointer2--;
      continue;
    }
  }
  int trackidx{0};
  for (const int &item : absSortedArray) {
    answer[trackidx] = item * item;
    trackidx++;
  }
  return answer;
}

int main() {
  std::vector<int> v1{-5, -4, -2, -1, 1, 2, 3, 6, 8, 9};
  auto ans = sortedSquaredArray(v1);
  std::for_each(ans.begin(), ans.end(), [](int &i) { std::cout << i << ' '; });
  std::cout << std::endl;
  return 0;
}