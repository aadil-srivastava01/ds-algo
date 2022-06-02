/*

Problem : Reverse a string

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s1;
  std::cout << "Enter a string: ";
  std::getline(std::cin, s1);

  auto it = s1.rbegin();
  while (it != s1.rend()) {
    std::cout << *it;
    it++;
  }
  std::cout << std::endl;
  return 0;
}