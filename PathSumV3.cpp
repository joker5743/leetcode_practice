// 437. 路径总和III

#include <unordered_map>

#include "data_structure.h"

class PathSumV3 {
 public:
  int pathSum_1(TreeNode* root, int targetSum) {
    if (!root) return 0;

    int res = rootSum(root, targetSum);
    res += pathSum_1(root->left, targetSum);
    res += pathSum_1(root->right, targetSum);
    return res;
  }

  int rootSum(TreeNode* root, int targetSum) {
    if (!root) return 0;

    int ret = 0;
    if (root->val == targetSum) {
      ret += 1;
    }
    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);
    return ret;
  }

  // dfs回溯+前缀和
  unordered_map<long long, int> prefix;

  int dfs(TreeNode* root, long long curr, int targetSum) {
    if (!root) return 0;

    int ret = 0;
    curr += root->val;
    if (prefix.count(curr - targetSum)) {
      ret = prefix[curr - targetSum];
    }

    prefix[curr]++;
    ret += dfs(root->left, curr, targetSum);
    ret += dfs(root->right, curr, targetSum);
    prefix[curr]--;

    return ret;
  }

  int pathSum_2(TreeNode* root, int targetSum) {
    prefix[0] = 1;
    return dfs(root, 0, targetSum);
  }
};