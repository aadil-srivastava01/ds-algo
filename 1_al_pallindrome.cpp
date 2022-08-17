/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string str) {
  int size = str.size();
  if (size == 1) return true;
  int begin{0}, end{size - 1};
  while (begin <= end) {
    if (str.at(begin) != str.at(end)) return false;
    begin++;
    end--;
  }

  return true;
}

int main() {
  std::cout << std::endl;
  return 0;
}