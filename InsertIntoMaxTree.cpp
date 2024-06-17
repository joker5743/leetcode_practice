// 998. 最大二叉树 II
#include "data_structure.h"

class InsertIntoMaxTree {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    TreeNode* parent = nullptr;
    TreeNode* cur = root;
    while (cur) {
      if (val > cur->val) {
        if (!parent) {
          return new TreeNode(val, root, nullptr);
        }
        TreeNode* node = new TreeNode(val, cur, nullptr);
        parent->right = node;
        return root;
      } else {
        parent = cur;
        cur = cur->right;
      }
    }
    parent->right = new TreeNode(val);
    return root;
  }
};