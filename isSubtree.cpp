// 572. 另一棵树的子树

#include <numeric>
#include <unordered_map>
#include <vector>

#include "data_structure.h"

using namespace std;

class IsSubtree {
 public:
  //  1. 暴力递归，逐个比对
  bool isSubtree_1(TreeNode *root, TreeNode *subRoot) {
    return dfs_1(root, subRoot);
  }

  // 检查两棵树是否一致
  bool check(TreeNode *o, TreeNode *t) {
    if (!o && !t) {
      return true;
    }

    if ((!o && t) || (o && !t) || (o->val != t->val)) {
      return false;
    }

    return check(o->left, t->left) && check(o->right, t->right);
  }

  bool dfs_1(TreeNode *o, TreeNode *t) {
    if (!o) {
      return false;
    }

    return check(o, t) || dfs_1(o->left, t) || dfs_1(o->right, t);
  }

  // 2. 利用遍历的值构成的串进行匹配比较
  vector<int> sOrder, tOrder;
  int maxElement, lNull, rNull;

  void getMaxElement(TreeNode *o) {
    if (!o) {
      return;
    }

    maxElement = max(maxElement, o->val);
    getMaxElement(o->left);
    getMaxElement(o->right);
  }

  // 先序遍历
  void getDfsOrder(TreeNode *o, vector<int> &tar) {
    if (!o) {
      return;
    }

    tar.push_back(o->val);
    if (o->left) {
      getDfsOrder(o->left, tar);
    } else {
      tar.push_back(lNull);
    }

    if (o->right) {
      getDfsOrder(o->right, tar);
    } else {
      tar.push_back(rNull);
    }
  }

  // 匹配算法，这里使用KMP进行模式匹配。
  bool kmp() {
    int sLen = sOrder.size(), tLen = tOrder.size();
    vector<int> fail(tOrder.size() - 1);

    for (int i = 1, j = -1; i < tLen; i++) {
      while (j != -1 && tOrder[i] != tOrder[j + 1]) {
        j = fail[j];
      }

      if (tOrder[i] == tOrder[j]) {
        ++j;
      }

      fail[i] = j;
    }

    for (int i = 0, j = -1; i < sLen; i++) {
      while (j != -1 && sOrder[i] != tOrder[j + 1]) {
        j = fail[j];
      }

      if (sOrder[i] == tOrder[j + 1]) {
        j++;
      }

      if (j == tLen - 1) {
        return true;
      }
    }
    return false;
  }

  bool isSubtree_2(TreeNode *root, TreeNode *subRoot) {
    maxElement = numeric_limits<int>::min();
    getMaxElement(root);
    getMaxElement(subRoot);
    lNull = maxElement + 1;
    rNull = maxElement + 2;

    getDfsOrder(root, sOrder);
    getDfsOrder(subRoot, tOrder);

    return kmp();
  }

  // 3. 树哈希
  static constexpr int MAX_N = 1000 + 5;
  static constexpr int MOD = int(1e9) + 7;

  bool vis[MAX_N];
  int p[MAX_N], tot;

  void getPrime() {
    vis[0] = vis[1] = 1;
    tot = 0;
    for (int i = 2; i < MAX_N; ++i) {
      if (!vis[i]) {
        p[++tot] = i;
      }
      for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
        vis[i * p[j]] = 1;
        if (i % p[j] == 0) {
          break;
        }
      }
    }
  }

  struct Status {
    int f, s;  // f为哈希值，s为子树大小
    Status(int f_ = 0, int s_ = 0) : f(f_), s(s_) {}
  };

  unordered_map<TreeNode *, Status> hS, hT;

  void dfs_3(TreeNode *o, unordered_map<TreeNode *, Status> &h) {
    h[o] = Status(o->val, 1);
    if (!o->left && !o->right) {
      return;
    }

    if (o->left) {
      dfs_3(o->left, h);
      h[o].s += h[o->left].s;
      h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
    }

    if (o->right) {
      dfs_3(o->right, h);
      h[o].s += h[o->right].s;
      h[o].f = (h[o].f + (31LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
    }
  }

  bool isSubtree_3(TreeNode *root, TreeNode *subRoot) {
    getPrime();
    dfs_3(root, hS);
    dfs_3(subRoot, hT);

    int tHash = hT[subRoot].f;
    for (const auto &[k, v] : hS) {
      if (v.f == tHash) {
        return true;
      }
    }
    return false;
  }
};