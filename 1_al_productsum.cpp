/*

Problem Link:

*/

#include <algorithm>
#include <any>
#include <iostream>
#include <string>
#include <vector>

using namespace ::std;
int computePsum(vector<any> array, int depth) {
  int sum{0};
  for (auto item : array) {
    if (item.type() == typeid(vector<any>)) {
      sum = sum + (depth * computePsum(any_cast<vector<any>>(item), depth + 1));
    } else {
      sum = sum + (depth * any_cast<int>(item));
    }
  }
  return sum;
}
int productSum(vector<any> array) {
  auto result = computePsum(array, 1);
  return result;
}

int main() {
  std::vector<any> v1{5, 2, std::vector<any>{7, -1}, 3,
                      std::vector<any>{6, std::vector<any>{-13, 8}, 4}};
  std::cout << productSum(v1);
  std::cout << std::endl;
  return 0;
}