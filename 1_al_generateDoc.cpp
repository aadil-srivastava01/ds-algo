/*

Problem Link:
You're given a string of available characters and a string representing a
document that you need to generate. Write a function that determines if you can
generate the document using the available characters. If you can generate the
document, your function should return true; otherwise, it should return false.
You're only able to generate the document if the frequency of unique characters
in the characters string is greater than or equal to the frequency of unique
characters in the document string. For example, if you're given characters =
"abcabc" and document = "aabbccc" you cannot generate the document because
you're missing one c. The document that you need to create may contain any
characters, including special characters, capital letters, numbers, and spaces.
Note: you can always generate the empty string ( "" ).

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool generateDocument(std::string characters, std::string document) {
  if (document.empty()) return true;
  std::unordered_map<char, int> charCounter, charCounter2;
  for (char &c : characters) {
    if (charCounter.find(c) != charCounter.end())
      charCounter.at(c) += 1;
    else
      charCounter.emplace(std::make_pair(c, 1));
  }
  for (char &c : document) {
    if (charCounter2.find(c) != charCounter.end())
      charCounter2.at(c) += 1;
    else
      charCounter2.emplace(std::make_pair(c, 1));
  }

  for (auto item : charCounter2) {
    if (charCounter.find(item.first) != charCounter.end() &&
        charCounter.at(item.first) >= item.second)
      continue;
    else
      return false;
  }
  return true;
}

int main() {
  std::cout << std::endl;
  return 0;
}