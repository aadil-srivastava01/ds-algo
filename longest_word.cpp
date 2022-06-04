/*

Problem Link: https://coderbyte.com/editor/Longest%20Word:Cpp

*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

std::string LongestWord(std::string sen) {
  std::istringstream stream(sen);
  std::string word;
  std::pair<int, std::string> longest_word{0, ""};
  size_t len_word{0};

  while (stream >> word) {
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    len_word = word.size();
    if (len_word > longest_word.first) {
      longest_word.first = len_word;
      longest_word.second = word;
    }
  }
  return longest_word.second;
}

int main() {
  std::cout << LongestWord("fun&!! time");
  std::cout << std::endl;
  return 0;
}