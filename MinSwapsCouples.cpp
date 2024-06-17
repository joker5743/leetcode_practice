// 765. 情侣牵手
#include "queue"
#include "unordered_map"
#include "vector"
using namespace std;

class MinSwapsCouples {
 public:
  // 1. 并查集
  int minSwapsCouples_1(vector<int> &row) {
    int n = row.size();
    int tot = n / 2;
    vector<int> f(tot, 0);

    for (int i = 0; i < tot; i++) {
      f[i] = i;
    }

    // 两两一组合并为集合
    for (int i = 0; i < n; i += 2) {
      int l = row[i] / 2;
      int r = row[i + 1] / 2;
      add(f, l, r);
    }

    unordered_map<int, int> m;
    for (int i = 0; i < tot; i++) {
      int fx = getf(f, i);
      m[fx]++;
    }

    int ret = 0;
    for (const auto &[f, sz] : m) {
      ret += sz - 1;
    }
    return ret;
  }

  // 并查集的查询
  int getf(vector<int> &f, int x) {
    if (f[x] == x) return x;

    int newf = getf(f, f[x]);
    f[x] = newf;  // 压缩路径，节约合并操作需要的资源
    return newf;
  }

  // 集合的合并,包含找到是同一组节点（一对情侣）所需要的交换连接。
  void add(vector<int> &f, int x, int y) {
    int fx = getf(f, x);
    int fy = getf(f, y);

    f[fx] = fy;  // 需要交换的两对情侣
  }

  // 2. 广度优先遍历BFS
  int minSwapsCouples_2(vector<int> &row) {
    int n = row.size();
    int tot = n / 2;

    vector<vector<int>> graph(tot);
    for (int i = 0; i < n; i += 2) {
      int l = row[i] / 2;
      int r = row[i + 1] / 2;
      if (l != r) {
        graph[l].push_back(r);
        graph[l].push_back(l);
      }
    }
    vector<int> visited(tot, 0);
    int ret = 0;
    for (int i = 0; i < tot; i++) {
      if (visited[i] == 0) {
        queue<int> q;
        visited[i] = 1;
        q.push(i);
        int cnt = 0;

        while (!q.empty()) {
          int x = q.front();
          q.pop();
          cnt += 1;

          for (int y : graph[x]) {
            if (visited[y] == 0) {
              visited[y] = 1;
            }
            q.push(y);
          }
        }
        ret += cnt - 1;
      }
    }
    return ret;
  }
};