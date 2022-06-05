/*

Problem:
Google Question
Given an array = [2,5,1,2,3,5,1,2,4]
It should return 2

Given an array = [2,1,1,2,3,5,1,2,4]
It should return 1

Given an array = [1,2,3,4]
It should return undefinded
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

auto RecurrChar(std::vector<int> &v1) {
  std::unordered_set<int> lookup;
  for (auto &item : v1) {
    if (lookup.find(item) != lookup.end())
      return item;
    else
      lookup.emplace(item);
  }
  return INT_MAX;
}

int main() {
  std::vector<int> v1{2, 5, 1, 2, 3, 5, 1, 2, 4};

  std::cout << RecurrChar(v1) << std::endl;
  v1 = {2, 1, 1, 2, 3, 5, 1, 2, 4};
  std::cout << RecurrChar(v1) << std::endl;
  v1 = {1, 2, 3, 4};
  std::cout << RecurrChar(v1) << std::endl;
  std::cout << std::endl;
  return 0;
}