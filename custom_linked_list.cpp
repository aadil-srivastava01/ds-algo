/*

Problem Link: Create a Singly Linked List

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class CLinkedList {
 public:
  ListNode *head;
  ListNode *tail;
  size_t length;

  CLinkedList(int val);
  void append(int val);
  void prepend(int val);
  void insert(int idx, int val);
  void del(int idx);
};

CLinkedList::CLinkedList(int val) {
  length = 0;
  auto node = new ListNode{val};
  head = node;
  tail = head;
  length++;
}

void CLinkedList::append(int val) {
  auto node = new ListNode{val};
  tail->next = node;
  tail = tail->next;
  length++;
}

void CLinkedList::prepend(int val) {
  auto node = new ListNode{val};
  node->next = head;
  head = node;
  length++;
}

void CLinkedList::insert(int idx, int val) {
  if (idx >= length)
    append(val);
  else if (idx == 0)
    prepend(val);
  else {
    auto node = new ListNode{val};
    ListNode *curr = head;
    for (int i = 0; i != idx - 1; i++) {
      curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
  }
}

void CLinkedList::del(int idx) {
  if (idx == 0) {
    auto tmp = head;
    head = head->next;
    delete tmp;
  } else {
    ListNode *curr = head;
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

void traverse(ListNode *head) {
  ListNode *curr = head;
  while (curr->next != NULL) {
    std::cout << curr->val << ' ';
    curr = curr->next;
  }
  std::cout << std::endl;
}

int main() {
  CLinkedList l1{1};
  l1.append(2);
  l1.append(3);
  l1.append(4);
  l1.prepend(9);
  traverse(l1.head);
  l1.insert(2, 11);
  traverse(l1.head);
  l1.del(2);
  traverse(l1.head);

  std::cout << std::endl;
  return 0;
}