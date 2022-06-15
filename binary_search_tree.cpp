/*

Problem Link: Create a Binary Search Tree

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class TreeNode {
 public:
  friend std::ostream &operator<<(std::ostream &os, const TreeNode &obj);
  friend std::ostream &operator<<(std::ostream &os, const TreeNode *obj);
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};

std::ostream &operator<<(std::ostream &os, const TreeNode &obj) {
  os << obj.val;
  return os;
}
std::ostream &operator<<(std::ostream &os, const TreeNode *obj) {
  if (obj == NULL)
    os << "Not_Found";
  else
    os << obj->val;
  return os;
}

class BinarySearchTree {
 private:
  TreeNode *parent;
  void iTraverse(TreeNode *node);
  bool isleaf(TreeNode *node);

 public:
  TreeNode *root;

  BinarySearchTree(int x);
  TreeNode *lookup(int x);
  void insert(int x);
  void remove(int x);
  void inorder_traverse() { iTraverse(root); };
  void bfs(TreeNode *node);
};

BinarySearchTree::BinarySearchTree(int x) { root = new TreeNode{x}; }

TreeNode *BinarySearchTree::lookup(int x) {
  parent = root;
  auto curr = root;

  while (curr != NULL) {
    int curr_val = curr->val;
    if (x == curr_val)
      return curr;
    else if (x < curr_val) {
      parent = curr;
      curr = curr->left;
    } else {
      parent = curr;
      curr = curr->right;
    }
  }
  return NULL;
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

void BinarySearchTree::bfs(TreeNode *node) {
  std::queue<TreeNode *> childs;
  TreeNode *tmp{NULL};
  if (node->left != NULL) childs.push(node->left);
  if (node->right != NULL) childs.push(node->right);
  while (!childs.empty()) {
    tmp = childs.front();
    if (tmp->left != NULL) childs.push(tmp->left);
    if (tmp->right != NULL) childs.push(tmp->right);

    std::cout << tmp << " ";
    childs.pop();
    tmp = childs.front();
  }
  std::cout << std::endl;
}
bool BinarySearchTree::isleaf(TreeNode *node) {
  if (node->left == NULL && node->right == NULL) return true;
  return false;
}

void BinarySearchTree::remove(int x) {
  auto curr = lookup(x);
  if (isleaf(curr)) {
    if (parent->left == curr)
      parent->left = NULL;
    else
      parent->right = NULL;
    curr = NULL;
    delete curr;
  } else if (curr->right == NULL && curr->left != NULL) {
    if (parent->left == curr)
      parent->left = curr->left;
    else
      parent->right = curr->left;
    curr = NULL;
    delete curr;
  } else {
    auto tmp = curr->right;
    while (tmp->left != NULL) tmp = tmp->left;

    if (isleaf(tmp) && curr->right == tmp) {
      tmp->left = curr->left;
      if (parent->left == curr)
        parent->left = tmp;
      else
        parent->right = tmp;

      curr = NULL;
      tmp = NULL;
      delete curr;
      delete tmp;
    } else {
      if (curr->right == tmp) {
        tmp->left = curr->left;
        if (parent->left == curr)
          parent->left = tmp;
        else
          parent->right = tmp;
        curr = NULL;
        tmp = NULL;
        delete curr;
        delete tmp;
      } else {
        curr->right->left = tmp->right;
        if (parent->left == curr)
          parent->left = tmp;
        else
          parent->right = tmp;
        tmp->right = curr->right;
        tmp->left = curr->left;
        tmp = NULL;
        curr = NULL;
        delete curr;
        delete tmp;
      }
    }
  }
}

int main() {
  BinarySearchTree bst(10);
  bst.insert(6);
  bst.insert(7);
  bst.insert(12);
  bst.insert(3);
  bst.insert(5);
  bst.insert(2);
  bst.insert(4);
  std::cout << bst.lookup(21) << std::endl;
  bst.inorder_traverse();
  std::cout << std::endl;
  bst.bfs(bst.root);

  bst.remove(6);
  bst.inorder_traverse();
  std::cout << std::endl;
  return 0;
}