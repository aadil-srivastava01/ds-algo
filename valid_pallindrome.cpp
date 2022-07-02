/*

Problem Link: https://leetcode.com/problems/valid-palindrome/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    int size = s.size();
    if (size == 0 || size == 1) return true;

    size = s.size() / 2;
    s.erase(std::remove_if(s.begin(), s.end(),
                           [](char &c) -> bool { return !std::isalnum(c); }),
            s.end());
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c) { return std::tolower(c); });

    auto it1 = s.begin();
    auto it2 = s.rbegin();
    int i{0};
    size = s.size();
    while (i < size) {
      if (*it1 != *it2) {
        return false;
      }
      i++;
      it1++;
      it2++;
    }

    return true;
  }
};

int main() {
  Solution s;
  std::cout << s.isPalindrome("......a.....");
  std::cout << std::endl;
  return 0;
}