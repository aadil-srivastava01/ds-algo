/*

Problem Link:
Write a function that takes in a "special" array and returns its product sum.
A "special" array is a non-empty array that contains either integers or other
"special" arrays. The product sum of a "special" array is the sum of its
elements, where "special" arrays inside it are summed themselves and then
multiplied by their level of depth. The depth of a "special" array is how far
nested it is. For instance, the depth of [] is 1; the depth of the inner array
in [[]] is 2; the depth of the innermost array in [[[]]] is 3 Therefore, the
product sum of [x, y] is x + y; the product sum of [x, [y, z]] is x + 2 * (y +
z); the product sum of [x, [y, [z]]] is x + 2 * (y + 3z).

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