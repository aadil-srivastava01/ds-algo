/*

Problem Link:
Find the closesest value to the target variable in a BST.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class BST {
 public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  BST *currentNode = tree;
  int minDistance{INT_MAX};
  int closesVal{0};
  int currValue{0};
  int currentDist{0};
  while (currentNode != NULL) {
    currValue = currentNode->value;
    if (currValue > target) {
      currentDist = std::abs(target - currValue);
      if (minDistance > currentDist) {
        minDistance = currentDist;
        closesVal = currValue;
      }
      currentNode = currentNode->left;
    } else if (currValue <= target) {
      currentDist = std::abs(target - currValue);
      if (minDistance > currentDist) {
        minDistance = currentDist;
        closesVal = currValue;
      }
      currentNode = currentNode->right;
    }
  }
  return closesVal;
}

int main() {
  std::cout << std::endl;
  return 0;
}