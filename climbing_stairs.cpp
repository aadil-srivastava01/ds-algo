/*

Problem Link: https://leetcode.com/problems/climbing-stairs/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int climbStairs(int n) {
    std::vector<int> dp_table(n + 1, -1);
    if (n <= 2) return n;

    dp_table[0] = 1;
    dp_table[1] = 1;
    dp_table[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp_table[i] = dp_table[i - 1] + dp_table[i - 2];
    }
    return dp_table[n];
  }
};

int main() {
  Solution s1;
  std::cout << s1.climbStairs(6);
  std::cout << std::endl;
  return 0;
}