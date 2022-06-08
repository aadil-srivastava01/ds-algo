/*

Problem Link: Create a Binary Search Tree

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class TreeNode {
 public:
  friend std::ostream &operator<<(std::ostream &os, const TreeNode &obj);
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};

std::ostream &operator<<(std::ostream &os, const TreeNode &obj) {
  os << obj.val;
  return os;
}

class BinarySearchTree {
 private:
  TreeNode *parent;
  void iTraverse(TreeNode *node);

 public:
  TreeNode *root;

  BinarySearchTree(int x);
  TreeNode lookup(int x);
  void insert(int x);
  void remove(int x);
  void inorder_traverse() { iTraverse(root); };
};

BinarySearchTree::BinarySearchTree(int x) { root = new TreeNode{x}; }
TreeNode BinarySearchTree::lookup(int x) {
  parent = root;
  auto curr = root;

  while (curr != NULL) {
    int curr_val = curr->val;
    if (x == curr_val)
      return *curr;
    else if (x < curr_val) {
      parent = curr;
      curr = curr->left;
    } else {
      parent = curr;
      curr = curr->right;
    }
  }
  if (curr == NULL) {
    return -1;
  }
}

void BinarySearchTree::insert(int x) {
  lookup(x);
  if (x < parent->val)
    parent->left = new TreeNode(x);
  else
    parent->right = new TreeNode(x);
}

void BinarySearchTree::iTraverse(TreeNode *node) {
  if (node->left != NULL) iTraverse(node->left);
  std::cout << *node << ' ';
  if (node->right != NULL) iTraverse(node->right);
}

int main() {
  BinarySearchTree bst{8};
  bst.insert(5);
  bst.insert(12);
  bst.insert(1);
  bst.insert(6);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);
  bst.insert(10);
  bst.insert(14);
  std::cout << bst.lookup(21) << std::endl;
  bst.inorder_traverse();
  std::cout << std::endl;
  return 0;
}