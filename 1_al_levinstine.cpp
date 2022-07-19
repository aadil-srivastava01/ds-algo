/*

Problem Link:

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(std::string str1, std::string str2) {
  std::vector<int> givenStringMap(26, 0);
  std::vector<int> finalStringMap(26, 0);
  int totalSubstitution{0};
  totalSubstitution = std::abs(int(str2.size() - str1.size()));

  for (const char &c : str1) {
    givenStringMap.at(c - 97)++;
  }
  for (const char &c : str2) finalStringMap.at(c - 97)++;

  for (int index = 0; index < 26; index++) {
    if (finalStringMap.at(index) - givenStringMap.at(index) == 0) continue;
    totalSubstitution++;
  }
  return totalSubstitution;
}

int main() {
  std::cout << levenshteinDistance("abc", "yabd");
  std::cout << std::endl;
  return 0;
}