/*

Problem Link:

Given a non-empty string of lowercase letters and a non-negative integer
representing a key, write a function that returns a new string obtained by
shifting every letter in the input string by k positions in the alphabet, where
k is the key. Note that letters should "wrap" around the alphabet; in other
words, the letter z shifted by one returns the letter a

Sample Input:
String: "xyz", key:2
Sample Output: "zab"

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string caesarCypherEncryptor(std::string str, int key) {
  int netShift = (key % 26);
  int tmp;
  for (char &c : str) {
    tmp = c - 97;
    tmp += netShift;
    if (tmp > 25) tmp -= 26;
    c = tmp + 97;
  }
  return str;
}

int main() {
  std::string input{"xyz"};
  std::cout << caesarCypherEncryptor(input, 2);
  std::cout << std::endl;
  return 0;
}