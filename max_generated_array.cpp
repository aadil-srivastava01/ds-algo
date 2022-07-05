/*

Problem Link: https://leetcode.com/problems/get-maximum-in-generated-array/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int getMaximumGenerated(int n) {
    int max{0};
    int mod, quo;
    if (n < 2) return n;
    std::vector<int> v(n + 1, 0);
    v.at(0) = 0;
    v.at(1) = 1;
    for (int i = 2; i < v.size(); i++) {
      mod = i % 2;
      quo = i / 2;
      if (mod == 0)
        v.at(i) = v.at(quo);
      else
        v.at(i) = v.at(quo) + v.at(quo + 1);

      if (max < v.at(i)) max = v.at(i);
    }
    return max;
  }
};

int main() {
  Solution s;
  std::cout << s.getMaximumGenerated(2);
  std::cout << std::endl;
  return 0;
}