/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int tandemBicycle(std::vector<int> redShirtSpeeds,
                  std::vector<int> blueShirtSpeeds, bool fastest) {
  int size = redShirtSpeeds.size() - 1;
  if (size == -1) return 0;
  std::sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  int fast{0}, slow{0};

  for (int idx = 0; idx <= size; idx++) {
    slow += std::max(redShirtSpeeds.at(idx), blueShirtSpeeds.at(idx));
    fast += std::max(redShirtSpeeds.at(size - idx), blueShirtSpeeds.at(idx));
  }
  if (fastest)
    return fast;
  else
    return slow;
}

int main() {
  std::vector<int> red{5, 5, 3, 9, 2};
  std::vector<int> blue{3, 6, 7, 2, 1};
  std::cout << tandemBicycle(red, blue, false);
  std::cout << std::endl;
  return 0;
}