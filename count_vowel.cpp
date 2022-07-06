/*

Problem Link: https://leetcode.com/problems/count-sorted-vowel-strings/

*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  int countVowelStrings(int n) {
    if (n == 1) return 5;
    std::vector<int> v1(5, 1), v2(5, 0);
    int curr_sum = std::accumulate(v1.begin(), v1.end(), 0);
    for (int i = 2; i <= n; i++) {
      v2.at(0) = curr_sum;
      for (int j = 1; j < 5; j++) {
        v2.at(j) = v2.at(j - 1) - v1.at(j - 1);
      }
      v1 = v2;
      curr_sum = std::accumulate(v2.begin(), v2.end(), 0);
    }
    return curr_sum;
  }
};

int main() {
  Solution s;
  std::cout << s.countVowelStrings(5);
  std::cout << std::endl;
  return 0;
}