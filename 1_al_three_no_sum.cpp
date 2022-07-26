/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> threeNumberSum(std::vector<int> array,
                                             int targetSum) {
  int size = array.size();
  std::vector<int> triplet(3, 0);
  std::set<std::vector<int>> triplets;

  int remaningSum{0};
  int indexBottom{0};
  int min1{0}, min{0};
  for (int indexTop = 0; indexTop < size; indexTop++) {
    std::unordered_set<int> sumTracker;
    remaningSum = targetSum - array.at(indexTop);
    indexBottom = 0;
    while (indexBottom < size) {
      if (indexBottom == indexTop) {
        indexBottom++;
        continue;
      }
      if (sumTracker.find(remaningSum - array.at(indexBottom)) !=
          sumTracker.end()) {
        triplet.emplace_back(array.at(indexTop));
        triplet.emplace_back(array.at(indexBottom));
        triplet.emplace_back(remaningSum - array.at(indexBottom));
        std::sort(triplet.begin(), triplet.end());
        triplets.emplace(triplet);
        triplet.clear();
      }
      sumTracker.insert(array.at(indexBottom));
    }
  }
  std::vector<std::vector<int>> result(triplets.size());
  for (auto triplet : triplets) {
    result.emplace_back(triplet);
  }
  std::sort(result.begin(), result.end());
  return result;
}

int main() {
  std::cout << std::endl;
  return 0;
}