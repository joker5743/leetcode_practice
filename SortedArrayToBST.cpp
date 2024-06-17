// 108. 有序数组转换为二叉搜索树

#include <vector>

#include "data_structure.h"

class SortedArrayToBST {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }

  TreeNode* helper(vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int mid = left + (right - left) / 2;
    // int mid = (right + left + 1) / 2;
    // int mid = (left + right + rand() % 2) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
  }
};