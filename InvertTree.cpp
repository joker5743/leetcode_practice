// 226. 翻转二叉树

#include <queue>
#include <stack>

#include "data_structure.h"

class InvertTree {
 public:
  // 方法一：递归
  TreeNode* invertTree_1(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* left = invertTree_1(root->left);
    TreeNode* right = invertTree_1(root->right);
    root->left = right;
    root->right = left;
  }

  // 方法二：BFS
  TreeNode* invertTree_2(TreeNode* root) {
    if (root == nullptr) return nullptr;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      // 利用第三方变量进行交换
      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;
      // 增加需要交换的下一层节点
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return root;
  }
};