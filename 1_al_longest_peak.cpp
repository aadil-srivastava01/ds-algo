/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPeak(std::vector<int> array) {
  int globalMaxlen{0};
  int localMaxlen{1};
  if (array.empty()) return 0;
  auto size = array.size();
  int lastVal{array.at(0)}, currentVal;
  bool rising{false}, hasPeaked{false}, hasFlatten{false};

  for (int idx = 1; idx < size; idx++) {
    currentVal = array.at(idx);
    if (currentVal == lastVal) {
      localMaxlen = 1;
      rising = false;
      lastVal = currentVal;
      hasFlatten = true;
    } else if (currentVal > lastVal) {
      if (!hasPeaked) localMaxlen++;
      rising = true;
      hasFlatten = false;
    } else {
      if (rising) {
        hasPeaked = true;
      }
      rising = false;
      hasFlatten = false;
    }
    if (hasPeaked && ((!rising) && (!hasFlatten))) {
      localMaxlen++;
      if (localMaxlen >= 3 && globalMaxlen < localMaxlen)
        globalMaxlen = localMaxlen;
    } else if (hasPeaked && (rising || hasFlatten)) {
      if (localMaxlen >= 3 && globalMaxlen <= localMaxlen) {
        globalMaxlen = localMaxlen;
        localMaxlen = 2;
      }
      hasPeaked = false;
    }
    lastVal = currentVal;
  }
  return globalMaxlen;
}

// Time: O(n) -> Nested loops might give of wrong impression about the
// complexity
int optimalLongestPeak(std::vector<int> array) {
  int globalMaxlen{0};
  int localMaxlen{0};
  if (array.empty()) return 0;
  auto size = array.size();
  int tmpIdx;
  for (int idx = 1; idx < size - 1; idx++) {
    if (array.at(idx) > array.at(idx + 1) &&
        array.at(idx) > array.at(idx - 1)) {
      tmpIdx = idx - 1;
      localMaxlen = 3;
      while (tmpIdx > 0) {
        if (array.at(tmpIdx - 1) < array.at(tmpIdx))
          localMaxlen++;
        else
          break;
        tmpIdx--;
      }
      tmpIdx = idx + 1;
      while (tmpIdx < size - 1) {
        if (array.at(tmpIdx + 1) < array.at(tmpIdx))
          localMaxlen++;
        else
          break;
        tmpIdx++;
      }
      if (localMaxlen > globalMaxlen) globalMaxlen = localMaxlen;
    }
  }
  return globalMaxlen;
}

int main() {
  std::vector<int> v1{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
  std::vector<int> v2{5, 4, 3, 2, 1, 2, 1};
  std::vector<int> v3{1, 2, 3, 3, 4, 0, 1};
  std::vector<int> v4{1, 1, 1, 1, 1, 1, 2, 3, 2, 1, 3};
  std::vector<int> v5{1,  1,  1, 2,  3,  10, 12, -3, -3, 2, 3,  45, 800,
                      99, 98, 0, -1, -1, 2,  3,  4,  5,  0, -1, -1};
  std::cout << longestPeak(v3) << std::endl;
  std::cout << optimalLongestPeak(v3) << std::endl;
  std::cout << std::endl;
  return 0;
}