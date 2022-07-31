/*

Problem Link:

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> smallestDifference(std::vector<int> arrayOne,
                                    std::vector<int> arrayTwo) {
  int smallestDiff{INT_MAX};
  int diff{0};
  std::vector<int> pair;
  if (arrayOne.size() == 0 || arrayTwo.size() == 0) return pair;
  pair.emplace_back(0);
  pair.emplace_back(0);
  for (const int &item : arrayOne) {
    for (const int &item2 : arrayTwo) {
      diff = std::abs(item2 - item);
      if (diff < smallestDiff) {
        smallestDiff = diff;
        pair.at(0) = item;
        pair.at(1) = item2;
      }
    }
  }
  return pair;
}

std::vector<int> optimalSmallestDifference(std::vector<int> arrayOne,
                                           std::vector<int> arrayTwo) {
  int size1 = arrayOne.size(), size2 = arrayTwo.size();
  int smallestDiff{INT_MAX};
  int diff{0};
  std::vector<int> pair(2, 0);
  if (size1 == 0 || size2 == 0) return pair;

  int pointer1{0}, pointer2{0};
  std::sort(arrayOne.begin(), arrayOne.end());
  std::sort(arrayTwo.begin(), arrayTwo.end());
  while (pointer1 < size1 && pointer2 < size2) {
    diff = std::abs(arrayOne.at(pointer1) - arrayTwo.at(pointer2));
    if (diff < smallestDiff) {
      smallestDiff = diff;
      pair.at(0) = arrayOne.at(pointer1);
      pair.at(1) = arrayTwo.at(pointer2);
      if (diff == 0) return pair;
    }
    if (arrayOne.at(pointer1) > arrayTwo.at(pointer2))
      pointer2++;
    else
      pointer1++;
  }
  if (pointer1 == size1) {
    while (pointer2 < size2) {
      diff = std::abs(arrayOne.at(pointer1 - 1) - arrayTwo.at(pointer2));
      if (diff < smallestDiff) {
        smallestDiff = diff;
        pair.at(0) = arrayOne.at(pointer1 - 1);
        pair.at(1) = arrayTwo.at(pointer2);
        if (diff == 0) return pair;
      }
      pointer2++;
    }
    return pair;
  } else {
    while (pointer1 < size1) {
      diff = std::abs(arrayOne.at(pointer1) - arrayTwo.at(pointer2 - 1));
      if (diff < smallestDiff) {
        smallestDiff = diff;
        pair.at(0) = arrayOne.at(pointer1);
        pair.at(1) = arrayTwo.at(pointer2 - 1);
        if (diff == 0) return pair;
      }
      pointer1++;
    }
    return pair;
  }
}

int main() {
  std::vector<int> a1{10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123};
  std::vector<int> a2{-1441, -124, -25, 1014, 1500, 660, 410, 245, 530};
  auto ret = optimalSmallestDifference(a1, a2);
  std::cout << std::endl;
  return 0;
}