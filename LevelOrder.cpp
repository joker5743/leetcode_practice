
#include <queue>

#include "data_structure.h"

class LevelOrder {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int current_size = q.size();
      vector<int> temp;
      for (int i = 0; i < current_size; i++) {
        TreeNode* node = q.front();
        q.pop();
        temp.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};