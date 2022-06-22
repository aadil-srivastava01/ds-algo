/*

Problem Link: https://leetcode.com/problems/valid-anagram/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    int size_s1 = s.size(), size_s2 = t.size();
    if (size_s1 != size_s2) return false;

    std::unordered_map<char, int> m1, m2;
    for (int i = 0; i < size_s1; i++) {
      m1[s[i]] += 1;
      m2[t[i]] += 1;
    }
    if (m1 == m2) return true;
    return false;
  }
};

int main() {
  std::string s1{"anagram"}, s2{"nagaram"};
  Solution sol;
  std::cout << sol.isAnagram(s1, s2);
  std::cout << std::endl;
  return 0;
}