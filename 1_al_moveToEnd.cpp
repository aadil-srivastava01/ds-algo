/*

Problem Link:
You're given an array of integers and an integer. Write a function that moves
all instances of that integer in the array to the end of the array and returns
the array. The function should perform this in place (i.e., it should mutate the
input array) and doesn't need to maintain the order of the other integers.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> moveElementToEnd(std::vector<int> array, int toMove) {
  std::stable_partition(array.begin(), array.end(),
                        [&toMove](int x) { return x != toMove; });
  return array;
}

std::vector<int> customMoveElementToEnd(std::vector<int> array, int toMove) {
  int size = array.size();
  if (size == 0) return array;
  int ptrBeg{0}, ptrEnd{size - 1};
  while (ptrBeg <= ptrEnd) {
    if (array.at(ptrEnd) != toMove) {
      if (array.at(ptrBeg) == toMove) {
        std::swap(array.at(ptrBeg), array.at(ptrEnd));
        ptrEnd--;
        ptrBeg++;
      } else {
        ptrBeg++;
      }
    } else {
      ptrEnd--;
    }
  }
  return array;
}

int main() {
  std::vector<int> v1{2, 4, 2, 5, 6, 2, 2};
  auto res = moveElementToEnd(v1, 2);
  std::for_each(res.begin(), res.end(), [](int &x) { std::cout << x << " "; });
  std::cout << std::endl;
  res = customMoveElementToEnd(v1, 2);
  std::for_each(res.begin(), res.end(), [](int &x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}