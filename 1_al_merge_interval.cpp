/*

Problem Link:
Write a function that takes in a non-empty array of arbitrary intervals, merges
any overlapping intervals, and returns the new intervals in no particular order.
Each interval interval is an array of two integers, with interval[0] as the
start of the interval and interval [1] as the end of the interval. Note that
back-to-back intervals aren't considered to be overlapping. For example, [1, 5]
and [6, 7] aren't overlapping; however, [1, 6] and [6, 7] are indeed
overlapping. Also note that the start of any particular interval will always be
less than or equal to the end of that interval.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> mergeOverlappingIntervals(
    std::vector<std::vector<int>> intervals) {
  int size = intervals.size();
  std::vector<std::vector<int>> result;
  std::sort(intervals.begin(), intervals.end(),
            [](std::vector<int> &x, std::vector<int> &y) {
              return x.at(0) < y.at(0);
            });
  result.emplace_back(intervals.at(0));
  int resultPointer{0};
  for (int idx = 1; idx < size; idx++) {
    if (result.at(resultPointer).at(1) >= intervals.at(idx).at(0) &&
        result.at(resultPointer).at(1) < intervals.at(idx).at(1)) {
      result.at(resultPointer).at(1) = intervals.at(idx).at(1);
    } else if (result.at(resultPointer).at(1) >= intervals.at(idx).at(0) &&
               result.at(resultPointer).at(1) == intervals.at(idx).at(1)) {
      result.at(resultPointer).at(1) = intervals.at(idx).at(1);
    } else if (result.at(resultPointer).at(1) >= intervals.at(idx).at(0) &&
               result.at(resultPointer).at(1) > intervals.at(idx).at(1)) {
      continue;
    } else {
      result.emplace_back(intervals.at(idx));
      resultPointer++;
    }
  }
  return result;
}

int main() {
  std::vector<std::vector<int>> input{{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
  auto result = mergeOverlappingIntervals(input);
  std::cout << std::endl;
  return 0;
}