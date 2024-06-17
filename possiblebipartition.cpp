// 886. 可能的二分法

#include <queue>
#include <vector>

using namespace std;

class PossibleBiPartition {
 public:
  // 1.dfs + 染色问题
  bool possibleBipartition_dfs(int n, vector<vector<int>> &dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);
    // nowcolor标记分到哪一组，（0,1）
    // g表示关系矩阵图
    for (auto &p : dislikes) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    for (int i = 0; i <= n; i++) {
      if (color[i] == 0 && dfs(i, 1, color, g)) {
        return false;
      }
    }
    return true;
  }

  bool dfs(int curnode, int nowcolor, vector<int> &color,
           const vector<vector<int>> &g) {
    color[curnode] = nowcolor;
    for (auto &nextnode : g[curnode]) {
      if (color[nextnode] && color[nextnode] == color[curnode]) {
        return false;
      }
      if (!color[nextnode] && !dfs(nextnode, 3 ^ nowcolor, color, g)) {
        return false;
      }
    }
    return true;
  }

  // 2.bfs + 染色问题
  bool possibleBipartition_bfs(int n, vector<vector<int>> &dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);
    // nowcolor标记分到哪一组，（0,1）
    // g表示关系矩阵图
    for (auto &p : dislikes) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    for (int i = 1; i <= n; i++) {
      if (color[i] == 0) {
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
          auto t = q.front();
          q.pop();
          for (auto &next : g[t]) {
            if (color[next] > 0 && color[next] == color[t]) {
              return false;
            }
            if (color[next] == 0) {
              color[next] = 3 ^ color[t];
              q.push(next);
            }
          }
        }
      }
    }
    return true;
  }

  // 3.并查集
  int findFa(int x, vector<int> &fa) {
    return fa[x] < 0 ? x : fa[x] = findFa(fa[x], fa);
  }

  void unit(int x, int y, vector<int> &fa) {
    x = findFa(x, fa);
    y = findFa(y, fa);
    if (x == y) {
      return;
    }

    if (fa[x] < fa[y]) {
      swap(x, y);
    }

    fa[x] += fa[y];
    fa[y] = x;
  }

  bool isconnect(int x, int y, vector<int> &fa) {
    x = findFa(x, fa);
    y = findFa(y, fa);
    return x == y;
  }

  bool possibleBipartition_union(int n, vector<vector<int>> &dislikes) {
    vector<int> fa(n + 1, -1);
    vector<vector<int>> g(n + 1);

    for (auto &p : dislikes) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 0; i < g[i].size(); i++) {
        unit(g[i][0], g[i][j], fa);
        if (isconnect(i, g[i][j], fa)) {
          return false;
        }
      }
    }
    return true;
  }
};