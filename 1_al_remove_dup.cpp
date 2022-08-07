/*

Problem Link:
You're given the head of a Singly Linked List whose nodes are in sorted order
with respect to their values. Write a function that returns a modified version
of the Linked List that doesn't contain any nodes with duplicate values. The
Linked List should be modified in place (i.e., you shouldn't create a brand new
list), and the modified Linked List should still have its nodes sorted with
respect to their values. Each LinkedList node has an integer value as well as a
next node pointing to the next node in the list or to None / null if it's the
tail of the list.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class LinkedList {
 public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  if (linkedList == nullptr) return nullptr;
  LinkedList *currPtr = linkedList;
  LinkedList *nextPtr = currPtr->next;
  while (nextPtr != NULL) {
    if (currPtr->value == nextPtr->value) {
      currPtr->next = nextPtr->next;
      nextPtr = currPtr->next;
      continue;
    }
    currPtr = nextPtr;
    nextPtr = nextPtr->next;
  }
  return linkedList;
}

int main() {
  std::cout << std::endl;
  return 0;
}