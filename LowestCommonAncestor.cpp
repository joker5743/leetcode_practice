// 236. 二叉树的最近公共祖先

#include <unordered_map>

#include "data_structure.h"

class LowestCommonAncestor {
 public:
  TreeNode* ans;
  TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs_1(root, p, q);
    return ans;
  }

  bool dfs_1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return false;

    bool lson = dfs_1(root->left, p, q);
    bool rson = dfs_1(root->right, p, q);
    if ((lson && rson) || ((p->val == q->val) && (lson || rson))) {
      ans = root;
    }
    return lson || rson || (root->val == q->val || root->val == p->val);
  }

  unordered_map<int, TreeNode*> fa;  // 节点值 - 该节点对应的父节点
  unordered_map<int, bool> vis;      // 节点值 - 该节点是否被访问过

  TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
    fa[root->val] = nullptr;
    dfs_2(root);
    // p指针不断向根节点移动，并记录各个节点的父节点
    while (p) {
      vis[p->val] = true;
      p = fa[p->val];
    }
    while (q) {
      // 如果q指向节点的父节点在父节点记录中，则直接返回。
      if (vis[q->val]) {
        return q;
      }
      q = fa[q->val];
    }
    return nullptr;
  }

  void dfs_2(TreeNode* root) {
    if (root->left) {
      fa[root->left->val] = root;
      dfs_2(root->left);
    }
    if (root->right) {
      fa[root->right->val] = root;
      dfs_2(root->right);
    }
  }
};