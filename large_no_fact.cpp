/*

Problem Link: Calculate the factorial of a large number

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 500

int multiply(int n, std::vector<int> &mul, int mul_size) {
  int carry{0};
  int temp;
  for (int i = 0; i < mul_size; i++) {
    temp = mul[i] * n + carry;
    mul[i] = temp % 10;
    carry = temp / 10;
  }
  while (carry) {
    mul[mul_size] = carry % 10;
    carry /= 10;
    mul_size++;
  }
  return mul_size;
}
void fact(int n) {
  std::vector<int> fact_vec(MAX, 0);

  fact_vec.at(0) = 1;
  int mul_size{1};
  for (int i = 2; i <= n; i++) {
    mul_size = multiply(i, fact_vec, mul_size);
  }
  for (int i = mul_size - 1; i >= 0; i--) std::cout << fact_vec[i];
}
int main() {
  fact(199);
  std::cout << std::endl;
  return 0;
}