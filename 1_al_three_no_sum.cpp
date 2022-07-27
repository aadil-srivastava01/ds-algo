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
  std::vector<int> triplet;
  std::set<std::vector<int>> triplets;

  int remaningSum{0};
  int indexBottom{0};

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
        if (!triplet.empty()) triplets.emplace(triplet);
        triplet.clear();
      }
      sumTracker.insert(array.at(indexBottom));
      indexBottom++;
    }
  }
  std::vector<std::vector<int>> result;
  for (auto triplet : triplets) {
    result.emplace_back(triplet);
  }
  std::sort(result.begin(), result.end());
  return result;
}

int main() {
  std::vector<int> v1{12, 3, 1, 2, -6, 5, -8, 6};
  auto results = threeNumberSum(v1, 0);
  for (const auto &tripet : results) {
    std::cout << "{ ";
    for (const int &item : tripet) std::cout << item << ' ';
    std::cout << " }";
  }
  std::cout << std::endl;
  return 0;
}