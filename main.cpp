#include <cassert>
#include <iostream>
#include <optional>

#include "binary-tree-playground/binary_tree.h"

using namespace std;

class TreeReadIterator {
 public:
  explicit TreeReadIterator(TreeNode* root) {
    q_.push(root);
  }

  bool atEnd() const {
    return q_.empty();
  }

  TreeNode* current() const {
    return (not q_.empty()) ? q_.front() : nullptr;
  }

  void next() {
    if (not q_.empty()) {
      TreeNode* node = q_.front();
      if (node) {
        q_.push(node->left);
        q_.push(node->right);
      }
      q_.pop();
    }
  }

 private:
  queue<TreeNode*> q_;
};

class Solution {
  TreeNode* takeValue(queue<optional<int>>& values) {
    TreeNode *node = nullptr;
    if (not values.empty()) {
      node = values.front().has_value() ? new TreeNode(*values.front()) : nullptr;
      values.pop();
    }
    return node;
  }

  TreeNode* buildTree(queue<optional<int>>& values) {
    queue<TreeNode*> nodes;
    TreeNode* root = new TreeNode(*values.front());
    values.pop();
    nodes.push(root);
    while (not nodes.empty()) {
      TreeNode* node = nodes.front();
      if (node) {
        node->left = takeValue(values);
        nodes.push(node->left);
        node->right = takeValue(values);
        nodes.push(node->right);
      }

      nodes.pop();
    }

    return root;
  }

 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (nullptr == root1 and nullptr == root2) return nullptr;

    TreeReadIterator iter_left{root1};
    TreeReadIterator iter_right{root2};
    queue<optional<int>> values;
    while (not iter_left.atEnd() || not iter_right.atEnd()) {
      TreeNode* node_left = iter_left.current();
      TreeNode* node_right = iter_right.current();
      if (node_left or node_right) {
        int left = node_left ? node_left->val : 0;
        int right = node_right ? node_right->val: 0;
        values.push(left + right);
      } else {
        values.push(nullopt);
      }
      iter_left.next();
      iter_right.next();
    }

    return buildTree(values);
  }
};

void TestMergeTrees() {
  Solution s;
  {
    TreeNode *left = stringToTreeNode("[1,3,2,5]"s);
    TreeNode *right = stringToTreeNode("[2,1,3,null,4,null,7]"s);
//    prettyPrintTree(s.mergeTrees(left, right));
//    assert("[3,4,5,5,4,null,7]"s == treeNodeToString(s.mergeTrees(left, right)));
  }
  {
    TreeNode *left = stringToTreeNode("[1,2,null,3]"s);
    prettyPrintTree(left);
    cout << string(80, '-') << endl;
    TreeNode *right = stringToTreeNode("[1,null,2,null,3]"s);
    prettyPrintTree(right);
    cout << string(80, '-') << endl;
    prettyPrintTree(s.mergeTrees(left, right));
    cout << string(80, '-') << endl;
    assert(false);
//    assert("[2,2,2,3,null,null,3]"s == treeNodeToString(s.mergeTrees(left, right)));
  }
}

int main() {
  TestMergeTrees();
  std::cout << "Ok!" << std::endl;
  return 0;
}
