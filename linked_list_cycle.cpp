/*

Problem Link: https://leetcode.com/problems/linked-list-cycle/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// O(n) Time and O(n) Space Complexity Solution
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> check_cycle;
    ListNode *curr{head};
    while (curr != nullptr) {
      if (check_cycle.find(curr) != check_cycle.end()) return true;
      check_cycle.emplace(curr);
      curr = curr->next;
    }
    return false;
  }
};

// O(n) Time and O(1) Space Complexity Solution
// Exploiting the input constraints
class Solution2 {
 public:
  bool hasCycle(ListNode *head) {
    size_t node_count{0};
    ListNode *curr{head};
    while (curr != nullptr) {
      node_count++;
      curr = curr->next;
      if (node_count > 10000) return true;
    }
    return false;
  }
};

class Solution3 {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *ptr_slow{head};
    ListNode *ptr_fast{head};
    if (ptr_slow == NULL) return false;
    while (ptr_fast != NULL && ptr_fast->next != NULL) {
      ptr_fast = ptr_fast->next->next;
      ptr_slow = ptr_slow->next;
      if (ptr_fast == ptr_slow) return true;
    }
    return false;
  }
};

// Even Better Solution: Floyd's Cycle-Finding Algorithm

int main() {
  std::cout << std::endl;
  return 0;
}