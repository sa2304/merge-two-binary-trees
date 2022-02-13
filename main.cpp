#include <cassert>
#include <iostream>

#include "binary-tree-playground/binary_tree.h"

using namespace std;

class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    TreeNode* result = nullptr;
    if (root1 or root2) {
      result = new TreeNode( (root1 ? root1->val : 0) + (root2 ? root2->val : 0) );
      result->left = mergeTrees( root1 ? root1->left : nullptr,
                                 root2 ? root2->left : nullptr );
      result->right = mergeTrees( root1 ? root1->right : nullptr,
                                  root2 ? root2->right : nullptr );
    }

    return result;
  }
};

void TestMergeTrees() {
  Solution s;
  {
    TreeNode *left = stringToTreeNode("[1,3,2,5]"s);
    TreeNode *right = stringToTreeNode("[2,1,3,null,4,null,7]"s);
    TreeNode *result = s.mergeTrees(left, right);
    prettyPrintTree(result);
    cout << string(80, '-') << endl;
  }
  {
    TreeNode *left = stringToTreeNode("[1,2,null,3]"s);
    TreeNode *right = stringToTreeNode("[1,null,2,null,3]"s);
    TreeNode *result = s.mergeTrees(left, right);
    prettyPrintTree(result);
    cout << string(80, '-') << endl;
  }
  {
    TreeNode *left = stringToTreeNode("[1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]"s);
    TreeNode *right = stringToTreeNode("[1,null,1,null,1,null,1,null,1,null,1,2]"s);
    TreeNode *result = s.mergeTrees(left, right);
    prettyPrintTree(result);
    cout << string(80, '-') << endl;
  }
}

int main() {
  TestMergeTrees();
  std::cout << "Ok!" << std::endl;
  return 0;
}
