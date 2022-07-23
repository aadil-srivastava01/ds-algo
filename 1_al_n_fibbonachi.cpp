/*

Problem Link:
Generate nth Fibbonachi Number
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int generateFib(int n, std::unordered_map<int, int>& prevFib) {
  if (n < 2)
    return n;
  else if (prevFib.find(n) != prevFib.end())
    return prevFib.at(n);
  else {
    prevFib[n] = generateFib((n - 1), prevFib) + generateFib((n - 2), prevFib);
    return prevFib[n];
  }
}
int getNthFib(int n) {
  std::unordered_map<int, int> hashTable;
  return generateFib(n - 1, hashTable);
}

int main() {
  std::cout << getNthFib(6);
  std::cout << std::endl;
  return 0;
}