/*

Problem Link:
Write a function that takes in a non-empty array of distinct integers and an
integer representing a target sum. If any two numbers in the input array sum up
to the target sum, the function should return them in an array, in any order. If
no two numbers sum up to the target sum, the function should return an empty
array. Note that the target sum has to be obtained by summing two different
integers in the array; you can't add a single integer to itself in order to
obtain the target sum. You can assume that there will be at most one pair of
numbers summing up to the target sum.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
  std::unordered_set<int> trackerTable;
  int remain{0};
  std::vector<int> answer;
  for (const int &item : array) {
    remain = targetSum - item;
    if (trackerTable.find(remain) != trackerTable.end()) {
      answer.emplace_back(remain);
      answer.emplace_back(item);
      return answer;
    } else {
      trackerTable.insert(item);
    }
  }
  return answer;
}

int main() {
  std::vector<int> v1{3, 5, -4, 8, 11, 1, -1, 6};
  auto answer = twoNumberSum(v1, 10);

  std::for_each(answer.begin(), answer.end(),
                [](int &x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}