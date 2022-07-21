/*

Problem Link:
Write a function that takes in two strings and returns the minimum number of
edit operations that need to be performed on the first string to obtain the
second string. There are three edit operations: insertion of a character,
deletion of a character, and substitution of a character for another.
Sample Input
str1 = "abc"
str2 = "yabd"
Sample Output
2
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(std::string str1, std::string str2) {}

int main() {
  std::cout << levenshteinDistance("abc", "yabd");
  std::cout << std::endl;
  return 0;
}