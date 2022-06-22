/*

Problem Link: https://leetcode.com/problems/reverse-linked-list/

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class CLinkedList {
 public:
  ListNode* head;
  ListNode* tail;
  size_t length;
  CLinkedList(int val);
  ~CLinkedList();
  void del(int idx);
  void append(int val);
};

CLinkedList::CLinkedList(int val) {
  length = 0;
  auto node = new ListNode{val};
  head = node;
  tail = head;
  length++;
}

CLinkedList::~CLinkedList() {
  int i{0};
  while (i < length) {
    del(0);
    i++;
  }
}

void CLinkedList::append(int val) {
  auto node = new ListNode{val};
  tail->next = node;
  tail = tail->next;
  length++;
}

void CLinkedList::del(int idx) {
  if (idx == 0) {
    auto tmp = head;
    head = head->next;
    delete tmp;
  } else {
    ListNode* curr = head;
    for (int i = 0; i != idx - 1; i++) {
      curr = curr->next;
    }
    if (curr->next->next != NULL) {
      auto tmp = curr->next;
      curr->next = curr->next->next;
      delete tmp;
    }
  }
}

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *nxt_node{NULL}, *prev_node{NULL}, *tmp_node{NULL};
    prev_node;
    nxt_node = head;
    while (nxt_node != NULL) {
      tmp_node = nxt_node;
      nxt_node = nxt_node->next;
      tmp_node->next = prev_node;
      prev_node = tmp_node;
    }
    head = tmp_node;
    return head;
  }
};

int main() {
  std::cout << std::endl;
  return 0;
}