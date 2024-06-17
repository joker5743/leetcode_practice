// 124. 二叉树中的最大路径和

#include <limits>

#include "data_structure.h"

class MaxPathSum {
 public:
  int maxSum = numeric_limits<int>::min();

  int maxGain(TreeNode *root) {
    if (!root) return 0;

    int left = max(0, maxGain(root->left));
    int right = max(0, maxGain(root->right));

    int priceNewpath = root->val + left + right;

    maxSum = max(maxSum, priceNewpath);
    return root->val + max(left, right);
  }

  int maxPathSum(TreeNode *root) {
    maxGain(root);
    return maxSum;
  }
};