/*

Problem Link:
The distance between a node in a Binary Tree and the tree's root is called the
node's depth. Write a function that takes in a Binary Tree and returns the sum
of its nodes' depths. Each BinaryTree node has an integer value, a left child
node, and a right child node. Children nodes can either be BinaryTree nodes
themselves or None / null.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class BinaryTree {
 public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void DepthCalc(BinaryTree *node, int currentHeight, int &sumHeight) {
  if (node == nullptr) return;
  DepthCalc(node->left, currentHeight + 1, sumHeight);
  DepthCalc(node->right, currentHeight + 1, sumHeight);
  sumHeight += currentHeight;
}

int nodeDepths(BinaryTree *root) {
  int sumHeight{0}, currentHeight{0};
  DepthCalc(root, currentHeight, sumHeight);
  return sumHeight;
}

int main() {
  std::cout << std::endl;
  return 0;
}