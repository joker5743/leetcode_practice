// 101. 对称二叉树

#include <queue>

#include "data_structure.h"

class IsSymMetric {
 public:
  bool isSymmetric_1(TreeNode* root) {
    if (!root)
      return true;
    else {
      return check_1(root->left, root->right);
    }
  }

  bool check_1(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return t1->val == t2->val && check_1(t1->left, t2->right) &&
           check_1(t1->right, t2->left);
  }

  bool isSymmetric_2(TreeNode* root) {
    if (!root)
      return true;
    else {
      return check_2(root->left, root->right);
    }
  }

  bool check_2(TreeNode* t1, TreeNode* t2) {
    queue<TreeNode*> q;
    q.push(t1);
    q.push(t2);
    while (!q.empty()) {
      TreeNode* u = q.front();
      q.pop();
      TreeNode* v = q.front();
      q.pop();

      if (!u && !v) continue;
      if ((!u || !v) || (u->val != v->val)) return false;

      q.push(u->left);
      q.push(v->right);

      q.push(u->right);
      q.push(v->left);
    }
    return true;
  }
};