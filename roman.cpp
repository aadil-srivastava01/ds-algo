/*

Problem Link: https://leetcode.com/problems/roman-to-integer/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> val_table;
    val_table['I'] = 1;
    val_table['V'] = 5;
    val_table['X'] = 10;
    val_table['L'] = 50;
    val_table['C'] = 100;
    val_table['D'] = 500;
    val_table['M'] = 1000;

    int num{0};
    int size = s.size() - 1;
    for (int i = 0; i <= size; i++) {
      if (s[i] == 'I') {
        if (i + 1 <= size) {
          if (s[i + 1] == 'V') {
            num += 4;
            i++;
            continue;
          } else if (s[i + 1] == 'X') {
            num += 9;
            i++;
            continue;
          }
        }
      }
      if (s[i] == 'X') {
        if (i + 1 <= size) {
          if (s[i + 1] == 'L') {
            num += 40;
            i++;
            continue;
          } else if (s[i + 1] == 'C') {
            num += 90;
            i++;
            continue;
          }
        }
      }
      if (s[i] == 'C') {
        if (i + 1 <= size) {
          if (s[i + 1] == 'D') {
            num += 400;
            i++;
            continue;
          } else if (s[i + 1] == 'M') {
            num += 900;
            i++;
            continue;
          }
        }
      }
      num += val_table[s[i]];
    }
    return num;
  }
};

int main() {
  Solution s1;
  std::string s2{"MCMXCIV"};
  std::cout << s1.romanToInt(s2) << std::endl;
  std::cout << std::endl;
  return 0;
}