/*

Problem Link: Reverse a string via recursion

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
void rev(std::string &str, int i, int len) {
  if (i >= len) return;
  rev(str, i + 1, len);
  std::cout << str[i];
}

int main() {
  std::string s1{"aadil"};
  rev(s1, 0, s1.length());
  std::cout << std::endl;
  return 0;
}