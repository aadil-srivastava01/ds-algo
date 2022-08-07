/*

Problem Link:
Write a function that takes in a string of lowercase English-alphabet letters
and returns the index of the string's first non-repeating character. The first
non-repeating character is the first character in a string that occurs only
once. If the input string doesn't have any non-repeating characters, your
function should return -1.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int firstNonRepeatingCharacter(std::string string) {
  std::vector<int> charCount(26, 0);
  for (char &c : string) {
    charCount[c - 97] += 1;
  }
  int idx{0};
  for (char c : string) {
    if (charCount[c - 97] == 1) return idx;
    idx++;
  }
  return -1;
}

int main() {
  std::cout << firstNonRepeatingCharacter("abcdcaf");
  std::cout << std::endl;
  return 0;
}