/*

Problem Link:
Write a function that takes in a non-empty string and returns its run-length
encoding. From Wikipedia, "run-length encoding is a form of lossless data
compression in which runs of data are stored as a single data value and count,
rather than as the original run." For this problem, a run of data is any
sequence of consecutive, identical characters. So the run "AAA" would be run
length-encoded as "3A". To make things more complicated, however, the input
string can contain all sorts of special characters, including numbers. And since
encoded data must be decodable, this means that we can't naively
run-length-encode long runs. For example, the run "AAAAAAAAAAAA" (12 A s), can't
naively be encoded as "12A", since this string can be decoded as either
"AAAAAAAAAAAA" or "1AA". Thus, long runs (runs of 10 or more characters) should
be encoded in a split fashion; the aforementioned run should be encoded as
"9A3A"

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