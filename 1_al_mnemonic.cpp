/*

Problem:

Given a stringified phone number of any non-zero length, write a function that
returns all mnemonics for this phone number, in any order. For this problem, a
valid mnemonic may only contain letters and the digits and 1. In other words, if
a digit is able to be represented by a letter, then it must be. Digits 0 and 1
are the only two digits that don't have letter representations on the keypad.
Note that you should rely on the keypad illustrated above for digit-letter
associations. Sample Input phoneNumber = "1905"

Output= [1w0j
1w0k
1w0l
1x0j
1x0k
1x0l
1y0j
1y0k
1y0l
1z0j
1z0k
1z0l]
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::string> TheGreatGenerator(
    std::vector<std::string> &LatestStrings,
    std::vector<std::string> &LatestChars) {
  std::vector<std::string> GeneratedStrings;
  for (auto &str : LatestStrings) {
    for (auto &c : LatestChars) {
      GeneratedStrings.emplace_back(str + c);
    }
  }
  return GeneratedStrings;
}

std::vector<std::string> phoneNumberMnemonics(std::string phoneNumber) {
  std::unordered_map<char, std::vector<std::string>> keypad;
  keypad.emplace(std::pair('1', std::vector<std::string>{"1"}));
  keypad.emplace(std::pair('2', std::vector<std::string>{"a", "b", "c"}));
  keypad.emplace(std::pair('3', std::vector<std::string>{"d", "e", "f"}));
  keypad.emplace(std::pair('4', std::vector<std::string>{"g", "h", "i"}));
  keypad.emplace(std::pair('5', std::vector<std::string>{"j", "k", "l"}));
  keypad.emplace(std::pair('6', std::vector<std::string>{"m", "n", "o"}));
  keypad.emplace(std::pair('7', std::vector<std::string>{"p", "q", "r", "s"}));
  keypad.emplace(std::pair('8', std::vector<std::string>{"t", "u", "v"}));
  keypad.emplace(std::pair('9', std::vector<std::string>{"w", "x", "y", "z"}));
  keypad.emplace(std::pair('0', std::vector<std::string>{"0"}));

  std::vector<std::string> Mnemonics;
  for (auto item : keypad[phoneNumber.at(0)]) {
    Mnemonics.emplace_back(item);
  }

  for (auto i = phoneNumber.begin() + 1; i != phoneNumber.end(); i++) {
    Mnemonics = TheGreatGenerator(Mnemonics, keypad.at(*i));
  }

  return Mnemonics;
}

int main() {
  auto ans = phoneNumberMnemonics("1905");
  std::cout << "*******" << std::endl;
  std::for_each(ans.begin(), ans.end(),
                [](std::string s) { std::cout << s << std::endl; });
  std::cout << std::endl;
  return 0;
}