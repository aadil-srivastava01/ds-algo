/*

Problem Link:
Class photos
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool classPhotos(std::vector<int> redShirtHeights,
                 std::vector<int> blueShirtHeights) {
  std::sort(redShirtHeights.begin(), redShirtHeights.end());
  std::sort(blueShirtHeights.begin(), blueShirtHeights.end());

  if (redShirtHeights.at(0) == blueShirtHeights.at(0)) return false;

  if (redShirtHeights.at(0) == blueShirtHeights.at(0))
    redShirtHeights.at(0) = 0;
  else if (redShirtHeights.at(0) > blueShirtHeights.at(0))
    redShirtHeights.at(0) = 1;
  else
    redShirtHeights.at(0) = -1;

  for (int idx = 1; idx < redShirtHeights.size(); idx++) {
    if (redShirtHeights.at(idx) == blueShirtHeights.at(idx))
      redShirtHeights.at(idx) = 0;
    else if (redShirtHeights.at(idx) > blueShirtHeights.at(idx))
      redShirtHeights.at(idx) = 1;
    else
      redShirtHeights.at(idx) = -1;

    if (redShirtHeights.at(idx) != redShirtHeights.at(idx - 1))
      return false;
    else
      continue;
  }
  return true;
}

int main() {
  std::vector<int> v1{1, 1, 1, 1, 1, 1, 1, 1};
  std::vector<int> v2{5, 6, 7, 2, 3, 1, 2, 3};
  std::cout << classPhotos(v1, v2);
  std::cout << std::endl;
  return 0;
}