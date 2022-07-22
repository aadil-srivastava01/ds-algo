/*

Problem Link:

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
  if (array.size() == 0 && sequence.size() == 0)
    return true;
  else if (sequence.size() == 0)
    return false;
  auto topPointer = sequence.begin();
  auto lastPointer = sequence.end();
  for (const int &item : array) {
    if (item == *topPointer) topPointer++;
    if (topPointer == lastPointer) return true;
  }
  if (topPointer == lastPointer) return true;
  return false;
}

int main() {
  std::cout << std::endl;
  return 0;
}