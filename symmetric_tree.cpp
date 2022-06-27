/*

Problem Link: https://leetcode.com/problems/symmetric-tree/

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool TestSym(TreeNode *l, TreeNode *r) {
    if (l == NULL && r == NULL)
      return true;
    else if (l == NULL || r == NULL)
      return false;
    else if (l->val != r->val)
      return false;

    return TestSym(l->left, r->right) && TestSym(l->right, r->left);
  }
  bool isSymmetric(TreeNode *root) {
    if (root->left == NULL && root->right == NULL) return true;

    return TestSym(root->left, root->right);
  }
};

int main() {
  TreeNode root{1};
  TreeNode n1{2};
  TreeNode n2{2};
  TreeNode n3{3};
  TreeNode n4{3};
  TreeNode n5{4};
  TreeNode n6{4};

  root.left = &n1;
  root.right = &n2;
  root.left->left = &n3;
  root.left->right = &n5;
  root.right->left = &n6;
  root.right->right = &n4;
  Solution s1;

  std::cout << "Is Tree Symmetric " << s1.isSymmetric(&root) << std::endl;
  std::cout << std::endl;
  return 0;
}