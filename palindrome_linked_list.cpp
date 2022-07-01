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

// Exploiting a common fact used by Flyod's Cycle detection algorithm
class SmartSolution {
 public:
  bool isPalindrome(ListNode *head) {
    if (head->next == NULL) return true;
    auto *fast{head};
    auto *slow{head};
    // Idea: When fast reaches END, slow will be at mid
    while (fast->next != NULL) {
      fast = fast->next;
      if (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
      }
    }
    // Reversing the 2nd half of the list
    auto prev{slow};
    auto mid{slow};
    auto tmp{slow};
    bool mark_end{false};
    slow = slow->next;
    while (slow != NULL) {
      prev = slow;
      slow = slow->next;
      prev->next = tmp;
      tmp = prev;
      if (!mark_end) {
        prev->next = NULL;
        mid->next = NULL;
        mark_end = true;
      }
    }
    tmp = head;
    std::cout << mid->val << "$$$$" << std::endl;

    while (prev != NULL) {
      std::cout << tmp->val << " " << prev->val << std::endl;
      if (tmp->val != prev->val) return false;
      tmp = tmp->next;
      prev = prev->next;
    }
    return true;
  }
};

int main() {
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l6(1);
  ListNode l5(2);
  ListNode l4(3);

  //   l5.next = &l6;
  l4.next = &l5;
  l3.next = &l4;
  l2.next = &l3;
  l1.next = &l2;

  SmartSolution s1;
  std::cout << s1.isPalindrome(&l1);

  std::cout << std::endl;
  return 0;
}