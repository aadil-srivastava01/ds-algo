/*

Problem Link:
Write a function that takes in a Binary Tree and returns a list of its branch
sums ordered from leftmost branch sum to rightmost branch sum. A branch sum is
the sum of all values in a Binary Tree branch. A Binary Tree branch is a path of
nodes in a tree that starts at the root node and ends at any leaf node. Each
BinaryTree node has an integer value, a left child node, and a right child node.
Children nodes can either be BinaryTree nodes themselves or None / null.
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

void traverseTree(BinaryTree *node, int currSum, std::vector<int> &sums) {
  if (node == nullptr) return;
  if (node->left == nullptr && node->right == nullptr) {
    sums.emplace_back(currSum + node->value);
    return;
  }
  traverseTree(node->left, currSum + (node->value), sums);
  traverseTree(node->right, currSum + (node->value), sums);
  return;
}

std::vector<int> branchSums(BinaryTree *root) {
  std::vector<int> sums;
  if (root == nullptr) return sums;
  traverseTree(root, 0, sums);
  return sums;
}

int main() {
  BinaryTree root{1};

  std::cout << std::endl;
  return 0;
}