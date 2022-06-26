/*

Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ptr1{list1};
    ListNode* ptr2{list2};
    if (ptr1 == NULL)
      return list2;
    else if (ptr2 == NULL)
      return list1;

    while (list2 != NULL || ptr1->next != NULL) {
      if (list2 == NULL) {
        return list1;
      } else if ((ptr1->next == NULL && list2 != NULL)) {
        if (ptr1->val > ptr2->val) {
          list2 = list2->next;
          ptr2->next = ptr1;
          list1 = ptr2;
          ptr1 = ptr2;
          ptr2 = list2;
          continue;
        }
        ptr1->next = list2;
        list2 = NULL;
        return list1;

      } else if ((ptr1->val <= ptr2->val) && (ptr1->next->val > ptr2->val)) {
        list2 = list2->next;
        ptr2->next = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr1->next;
        ptr2 = list2;
      } else if (ptr1->val > ptr2->val) {
        list2 = list2->next;
        ptr2->next = ptr1;
        list1 = ptr2;
        ptr1 = ptr2;
        ptr2 = list2;
      } else
        ptr1 = ptr1->next;
    }
    return list1;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}