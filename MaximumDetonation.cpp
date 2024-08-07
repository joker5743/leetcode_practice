// 2101. 引爆最多的炸弹

#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class MaximumDetonation {
 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();

    // 炸弹u能否引爆炸弹v
    auto is_connected = [&](int u, int v) -> bool {
      long long dx = bombs[u][0] - bombs[v][0];
      long long dy = bombs[u][1] - bombs[v][1];
      return (long long)bombs[u][2] * bombs[u][2] >= dx * dx + dy * dy;
    };

    // 构建图关系
    vector<vector<int>> edges(
        n);  // 使用二维vector记录拓扑关系，需要进行初始化。
    // unordered_map<int, vector<int>> edges;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; i++) {
        if (i != j && is_connected(i, j)) {
          edges[i].push_back(j);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
      vector<int> visited(n, 0);
      int cnt = 1;
      queue<int> q;
      q.push(i);
      visited[i] = 1;
      while (!q.empty()) {
        int idx_bomb = q.front();
        q.pop();
        for (const int nei_idx : edges[idx_bomb]) {
          if (visited[nei_idx]) {
            // 已经被引爆，不计入计算
            continue;
          }
          ++cnt;
          q.push(nei_idx);
          visited[nei_idx] = 1;
        }
      }
      res = max(res, cnt);
    }
    return res;
  }
};