/*

Problem Link: https://leetcode.com/problems/is-subsequence/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  bool isSubsequence(std::string s, std::string t) {
    if (s.size() == 0 && t.size() != 0)
      return true;
    else if (s.size() != 0 && t.size() == 0)
      return false;
    else if (s.size() == 0 && t.size() == 0)
      return true;

    int ptr_s{0};
    for (const char &c : t) {
      if (s.at(ptr_s) == c) ptr_s++;
      if (ptr_s == s.size()) return true;
    }
    return false;
  }
};

int main() {
  Solution s1;
  std::cout << s1.isSubsequence("abc", "ahbgdc");
  std::cout << std::endl;
  return 0;
}