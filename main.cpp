#include <cassert>
#include <iostream>

#include "binary-tree-playground/binary_tree.h"

using namespace std;

class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    // FIXME
    return nullptr;
  }
};

void TestMergeTrees() {
  Solution s;
  TreeNode *left = stringToTreeNode("[1,3,2,5]"s);
  TreeNode *right = stringToTreeNode("[2,1,3,null,4,null,7]"s);
  assert("[3,4,5,5,4,null,7]"s == treeNodeToString(s.mergeTrees(left, right)));

}

int main() {
  TestMergeTrees();
  std::cout << "Ok!" << std::endl;
  return 0;
}
