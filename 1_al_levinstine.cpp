/*

Problem Link:
Write a function that takes in two strings and returns the minimum number of
edit operations that need to be performed on the first string to obtain the
second string. There are three edit operations: insertion of a character,
deletion of a character, and substitution of a character for another.
Sample Input
str1 = "abc"
str2 = "yabd"
Sample Output
2
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(std::string str1, std::string str2) {
  auto size1 = str1.size();
  auto size2 = str2.size();
  std::vector<std::vector<int>> operationsTable(size1 + 1,
                                                std::vector<int>(size2 + 1));
  for (int i = 0; i < size2 + 1; i++) operationsTable[0][i] = i;
  for (int i = 0; i < size1 + 1; i++) operationsTable[i][0] = i;
  for (int rowIndex = 1; rowIndex < size1 + 1; rowIndex++) {
    for (int colIndex = 1; colIndex < size2 + 1; colIndex++) {
      if (str1.at(rowIndex - 1) == str2.at(colIndex - 1))
        operationsTable.at(rowIndex).at(colIndex) =
            operationsTable.at(rowIndex - 1).at(colIndex - 1);
      else {
        operationsTable.at(rowIndex).at(colIndex) =
            1 +
            std::min(std::min(operationsTable.at(rowIndex - 1).at(colIndex - 1),
                              operationsTable.at(rowIndex).at(colIndex - 1)),
                     operationsTable.at(rowIndex - 1).at(colIndex));
      }
    }
  };
  return operationsTable.back().back();
}

int spaceOptlevenshteinDistance(std::string str1, std::string str2) {
  auto small = str1.size() > str2.size() ? str2 : str1;
  auto large = str1.size() > str2.size() ? str1 : str2;
  auto small_size = small.size();
  auto large_size = large.size();
  int rowFlagindex = 1;

  std::vector<std::vector<int>> operationsTable(
      2, std::vector<int>(small_size + 1));

  for (int colIndex = 0; colIndex < small_size + 1; colIndex++)
    operationsTable[0][colIndex] = colIndex;

  for (int rowIndex = 1; rowIndex < large_size + 1; rowIndex++) {
    for (int colIndex = 0; colIndex < small_size + 1; colIndex++) {
      if (colIndex == 0) {
        operationsTable.at(rowFlagindex).at(colIndex) = rowIndex;
        continue;
      }
      if (large.at(rowIndex - 1) == small.at(colIndex - 1))
        operationsTable.at(rowFlagindex).at(colIndex) =
            operationsTable.at(rowFlagindex - 1).at(colIndex - 1);
      else {
        operationsTable.at(rowFlagindex).at(colIndex) =
            1 +
            std::min(
                std::min(operationsTable.at(rowFlagindex - 1).at(colIndex - 1),
                         operationsTable.at(rowFlagindex).at(colIndex - 1)),
                operationsTable.at(rowFlagindex - 1).at(colIndex));
      }
    }
    operationsTable[0] = operationsTable[1];
  }
  return operationsTable.front().back();
}

int main() {
  std::cout << levenshteinDistance("aabddy", "abc") << std::endl;
  std::cout << spaceOptlevenshteinDistance("aabddy", "abc") << std::endl;
  std::cout << std::endl;
  return 0;
}