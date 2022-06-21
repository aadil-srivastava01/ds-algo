/*

Problem Link: https://leetcode.com/problems/reverse-string/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    int size = s.size();
    if (size == 1) return;
    int l = size % 2 ==0? (size / 2) - 1 : size / 2;
    for (int i = 0; i <= l; i++) {
      std::swap(s[i], s[size - 1 - i]);
    }
  }
};

int main() {
  std::vector<char> v1{'h','e','l', 'l', 'o'};
  Solution s1;
  s1.reverseString(v1);
  std::for_each(v1.begin(), v1.end(), [](char x) { std::cout << x << " "; });
  std::cout << std::endl;
  return 0;
}