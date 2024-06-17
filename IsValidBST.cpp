// 98. 验证二叉树

#include <limits>
#include <stack>

#include "data_structure.h"

class IsValidBST {
  bool isValidBST_1(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }

  bool helper(TreeNode* root, long long min, long long max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return helper(root->left, min, root->val) &&
           helper(root->right, root->val, max);
  }

  bool isValidBST_2(TreeNode* root) {
    stack<TreeNode*> stack;
    int inorder = std::numeric_limits<int>::max() - 1;

    while (!stack.empty() || root != nullptr) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      if (root->val <= inorder) return false;
      inorder = root->val;
      root = root->right;
    }
    return true;
  }
};