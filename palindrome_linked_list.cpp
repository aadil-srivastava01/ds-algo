/*

Problem Link: https://leetcode.com/problems/palindrome-linked-list/

*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    ListNode *ptr{head};
    if (head->next == NULL) return true;
    std::vector<int> val;
    while (ptr != NULL) {
      val.emplace_back(ptr->val);
      ptr = ptr->next;
    }
    int i = 0;
    int j = val.size() - 1;
    while (i <= j) {
      if (val.at(i) == val.at(j)) {
        i++;
        j--;
        continue;
      } else
        return false;
    }
    return true;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}