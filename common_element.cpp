/*
Problem Statement: Create a funtion to return a bool value is there is commom
element among two containers. Example: a1 = ['a', 'n', 'c', 'p'] a2 = ['1' ,
'2', '3', '4' ] a3 = ['q', 'w', 'e', 'r', 't', 'y', 'o', 'a']

When a1 & a2 is passed to funtion it should return false.
When a1 & a2 is passed to funtion it should return true.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

bool is_common2(const std::vector<char> &v1, const std::vector<char> &v2) {
  std::unordered_set<char> s1;
  for (const auto &val : v1) {
    s1.insert(val);
  }
  for (const auto &val : v2) {
    if (s1.find(val) != s1.end()) return true;
  }
  return false;
}
int main() {
  std::vector<char> v1{'a', 'b', 'c', 'd'};
  std::vector<char> v2{'e', 'f', 'g', 'h'};
  std::vector<char> v3{'1', '3', 'a', '1'};

  std::cout << is_common2(v1, v2) << '\n' << is_common2(v1, v3) << std::endl;

  return 0;
}