/*

Problem Link:

Given {"X"->"1", "Y"->"2"}

generate %X%_%Y% as "1_2"
%X%X%Y%->"1X2"
_%X%X%Y%->"_1X2"

length can vary.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

void useFormatter(std::unordered_map<char, char> charMap,
                  std::string formatter) {
  bool resolveFlag{false};
  for (char &c : formatter) {
    if (c == '%' && !resolveFlag) {
      resolveFlag = true;
      continue;
    } else if (c != '%' && resolveFlag) {
      std::cout << charMap[c];
    } else if (c == '%' && resolveFlag) {
      resolveFlag = false;
      continue;
    } else {
      std::cout << c;
    }
  }
}

int main() {
  std::unordered_map<char, char> charMap;
  charMap.insert(std::pair('X', '1'));
  charMap.insert(std::pair('Y', '2'));

  std::string formatter{"_%X%X%Y%"};
  useFormatter(charMap, formatter);

  std::cout << std::endl;
  return 0;
}