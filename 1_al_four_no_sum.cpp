/*

Problem Link:


Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. The function should find all quadruplets in
the array that sum up to the target sum and return a two-dimensional array of
all these quadruplets in no particular order. If no four numbers sum up to the
target sum, the function should return an empty array.
Sample Input
array = [7, 6, 4, −1, 1, 2]
targetSum = 16
Sample Output
[[7,6,4,-1], [6,4,1,2]]

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// O(n^3) Time, O(n) Space
std::vector<std::vector<int>> fourNumberSum(std::vector<int> array,
                                            int targetSum) {
  std::vector<std::vector<int>> result;
  std::vector<int> temp;
  std::unordered_set<int> alreadySeen;
  if (array.empty()) return result;
  int size = array.size();
  int remSum1{0}, remSum2{0}, remaning{0};
  for (int num1 = 0; num1 < size; num1++) {
    remSum1 = targetSum - array.at(num1);
    for (int num2 = num1 + 1; num2 < size; num2++) {
      remSum2 = remSum1 - array.at(num2);
      for (int idx = num2 + 1; idx < size; idx++) {
        remaning = remSum2 - array.at(idx);
        if (alreadySeen.find(remaning) != alreadySeen.end()) {
          temp.emplace_back(array.at(num1));
          temp.emplace_back(array.at(num2));
          temp.emplace_back(array.at(idx));
          temp.emplace_back(remaning);
          result.emplace_back(temp);
          temp.clear();
        }
        alreadySeen.emplace(array.at(idx));
      }
      alreadySeen.clear();
    }
  }

  return result;
}

// Optimised Solution
// Space: O(n^2)
// Time: Average: O(n^2), Worst: O(n^3)
std::vector<std::vector<int>> fourNumberSumOpt(std::vector<int> array,
                                               int targetSum) {
  std::vector<std::vector<int>> result;
  std::vector<int> temp;
  auto size = array.size();
  std::unordered_map<int, std::vector<std::vector<int>>> foundTable;
  int sum{0};
  if (array.empty()) return result;
  for (int outIdx = 0; outIdx < size; outIdx++) {
    for (int inIdx1 = outIdx + 1; inIdx1 < size; inIdx1++) {
      if (foundTable.find(targetSum - (array.at(outIdx) + array.at(inIdx1))) !=
          foundTable.end()) {
        for (auto &item :
             foundTable.at(targetSum - (array.at(outIdx) + array.at(inIdx1)))) {
          temp.emplace_back(item.at(0));
          temp.emplace_back(item.at(1));
          temp.emplace_back(array.at(outIdx));
          temp.emplace_back(array.at(inIdx1));
          result.emplace_back(temp);
          temp.clear();
        }
      }
    }
    for (int inIdx2 = 0; inIdx2 < outIdx; inIdx2++) {
      sum = array.at(outIdx) + array.at(inIdx2);
      if (foundTable.find(sum) != foundTable.end())
        foundTable.at(sum).emplace_back(
            std::vector<int>{array.at(outIdx), array.at(inIdx2)});
      else {
        foundTable.emplace(
            std::make_pair(sum, std::vector<std::vector<int>>{
                                    {array.at(outIdx), array.at(inIdx2)}}));
      }
    }
  }
  return result;
}

int main() {
  std::vector<int> v1{7, 6, 4, -1, 1, 2};
  //   auto res = fourNumberSum(v1, 16);
  auto res = fourNumberSumOpt(v1, 16);
  std::cout << std::endl;
  return 0;
}