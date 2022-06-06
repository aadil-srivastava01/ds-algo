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
  ~CLinkedList();
  void append(int val);
  void prepend(int val);
  void insert(int idx, int val);
  void del(int idx);
  void reverse();
  void efficient_reverse();
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

void CLinkedList::reverse() {
  if (length == 1) return;
  auto temp = new CLinkedList{head->val};
  auto curr = head->next;
  while (curr != NULL) {
    temp->prepend(curr->val);
    curr = curr->next;
  }
  int i{0};
  while (i < length) {
    del(0);
    i++;
  }
  head = temp->head;
  tail = temp->tail;
  length = temp->length;
  temp = NULL;
  delete temp;
}
// O(1):Space, O(n) Time
void CLinkedList::efficient_reverse() {
  auto first = head;
  auto second = head->next;
  auto tmp = second;
  while (second != NULL) {
    tmp = second->next;
    second->next = first;
    first = second;
    second = tmp;
  }
  tail = head;
  head->next = NULL;
  head = first;
}

void traverse(ListNode *head) {
  ListNode *curr = head;
  while (curr != NULL) {
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
  l1.efficient_reverse();
  traverse(l1.head);
  l1.append(17);
  traverse(l1.head);

  std::cout << std::endl;
  return 0;
}