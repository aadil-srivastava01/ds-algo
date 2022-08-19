/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string runLengthEncoding(std::string str) {
  if (str.empty()) return str;
  std::string output;
  int currCounter{0};
  int size = str.size();
  char c, lastChar{str.at(0)};

  for (int idx = 0; idx < size; idx++) {
    c = str.at(idx);
    if (c == lastChar) {
      lastChar = c;
      currCounter++;
    } else {
      if (currCounter) {
        output += (std::to_string(currCounter));
        output.push_back(lastChar);
      }
      currCounter = 1;
    }
    if (currCounter == 9) {
      output += (std::to_string(9) + lastChar);
      currCounter = 0;
    }
    lastChar = c;
  }
  output += (std::to_string(currCounter));
  output.push_back(lastChar);
  return output;
}
int main() {
  std::cout << runLengthEncoding("AAAAAAAAABBCCCCDD");
  std::cout << std::endl;
  return 0;
}