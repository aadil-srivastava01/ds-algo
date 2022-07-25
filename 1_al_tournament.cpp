/*

Problem Link:


*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::string tournamentWinner(std::vector<std::vector<std::string>> competitions,
                             std::vector<int> results) {
  std::unordered_map<std::string, int> winnerCounter;
  std::vector<std::string> competetion;
  for (int index = 0; index < results.size(); index++) {
    competetion = competitions.at(index);
    if (results.at(index) == 1)
      winnerCounter[competetion.at(0)] += 1;
    else
      winnerCounter[competetion.at(1)] += 1;
  }
  std::pair<std::string, int> max;
  max.first = "";
  max.second = -1;
  for (auto iter = winnerCounter.begin(); iter != winnerCounter.end(); iter++) {
    if (iter->second > max.second) {
      max.first = iter->first;
      max.second = iter->second;
    };
  }
  return max.first;
}

int main() {
  std::cout << std::endl;
  return 0;
}