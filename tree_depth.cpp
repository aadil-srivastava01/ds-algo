#include <iostream>

// Definition for a binary tree node.
struct BTreeNode {
  int val;
  BTreeNode *left;
  BTreeNode *right;
  BTreeNode() : val(0), left(nullptr), right(nullptr) {}
  BTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  BTreeNode(int x, BTreeNode *left, BTreeNode *right)
      : val(x), left(left), right(right) {}
};

int Depth(BTreeNode *t) {
  if (t == NULL) {
    return 0;
  }
  int depth_l = Depth(t->left);
  int depth_r = Depth(t->right);
  if (depth_l > depth_r) {
    return (depth_l + 1);
  } else {
    return (depth_r + 1);
  }
}

int main() {
  BTreeNode root{1};
  BTreeNode n1{2};
  BTreeNode n2{3};
  BTreeNode n3{4};
  BTreeNode n4{4};

  root.left = &n1;
  root.right = &n2;
  root.left->left = &n3;
  root.right->right = &n4;
  std::cout << "Height of tree is " << Depth(&root) << std::endl;

  //       //   root.val = 1;

  //       // root->left = &BTreeNode(2);
  //       // root->right = &BTreeNode(3);
  //       // root->left->left = &BTreeNode(4);
  //       // root->left->right = &BTreeNode(5);

  //       std::cout
  //   << "Height of tree is " << Depth(root);
  return 0;
}
