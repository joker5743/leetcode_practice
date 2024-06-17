// 543. 二叉树的直径

#include "data_structure.h"

class DiameterOfBinaryTree {
 public:
  int ans;
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    depth(root);
    return ans;
  }

  int depth(TreeNode* root) {
    if (!root) return 0;

    int L = depth(root->left);
    int R = depth(root->right);
    ans = max(ans, L + R);
    return max(L, R) + 1;
  }
};