// 623. 在二叉树中增加一行

#include <vector>

#include "data_structure.h"

class AddOneRow {
 public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) return new TreeNode(val, root, nullptr);

    std::vector<TreeNode *> curLevel(1, root);
    for (int i = 1; i < depth - 1; i++) {
      std::vector<TreeNode *> temp;
      for (auto &node : curLevel) {
        if (node->left != nullptr) temp.emplace_back(node->left);
        if (node->right != nullptr) temp.emplace_back(node->right);
      }
      // curLevel = std::move(temp);
      curLevel = temp;
    }
    for (auto &node : curLevel) {
      node->left = new TreeNode(val, node->left, nullptr);
      node->right = new TreeNode(val, nullptr, node->right);
    }
    return root;
  }
};