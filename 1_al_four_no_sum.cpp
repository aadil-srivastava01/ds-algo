/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

int main() {
  std::vector<int> v1{7, 6, 4, -1, 1, 2};
  auto res = fourNumberSum(v1, 16);
  std::cout << std::endl;
  return 0;
}