/*

Problem Link: https://leetcode.com/problems/count-primes/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    bool primes[n + 1];
    std::memset(primes, true, sizeof(primes));
    for (int p = 2; p * p <= n - 1; p++) {
      if (primes[p])
        for (int i = p * p; i <= n - 1; i += p) primes[i] = false;
    }
    int count{0};
    for (int i = 2; i <= n - 1; i++)
      if (primes[i]) count++;
    return count;
  }
};

int main() {
  Solution s;
  std::cout << s.countPrimes(5000000);
  std::cout << std::endl;
  return 0;
}