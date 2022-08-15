/*

Problem Link:
Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. The function should find all triplets in the
array that sum up to the target sum and return a two-dimensional array of all
these triplets. The numbers in each triplet should be ordered in ascending
order, and the triplets themselves should be ordered in ascending order with
respect to the numbers they hold. If no three numbers sum up to the target sum,
the function should return an empty array.

Sample input: Array: [12, 3, 1, 2,
-6, 5, -8, 6]
TargetSum: 0
Sample Output: { -8, 2, 6 },{ -8, 3, 5  },{ -6, 1, 5
}
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
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

std::vector<std::vector<int>> threeNumberSum(std::vector<int> array,
                                             int targetSum) {
  auto size = array.size();
  int sum{0};
  std::unordered_map<int, std::vector<std::vector<int>>> haveSeen;
  std::vector<std::vector<int>> results;
  std::vector<int> temp;
  for (int outIdx = 0; outIdx < size; outIdx++) {
    for (int inIdx = outIdx + 1; inIdx < size; inIdx++) {
      sum = array.at(outIdx) + array.at(inIdx);
      if (haveSeen.find(sum) != haveSeen.end()) {
        temp.emplace_back(array.at(outIdx));
        temp.emplace_back(array.at(inIdx));
      }
    }
  }
  return {};
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