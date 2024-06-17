// 1631. 最小体力消耗路径
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

// 并查集定义
class UnionFind {
 private:
  vector<int> parent;
  vector<int> size;
  int n;
  int setcount;  // 连通分量
 public:
  UnionFind(int _n) : n(_n), setcount(_n), parent(_n), size(_n - 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int findset(int x) {
    return parent[x] == x ? x : parent[x] = findset(parent[x]);
  }

  bool unite(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x == y) {
      return false;
    }
    if (size[x] < size[y]) {
      swap(x, y);
    }
    parent[y] = x;
    size[x] += size[y];
    --setcount;
    return true;
  }

  bool connected(int x, int y) {
    x = findset(x);
    y = findset(y);
    return x == y;
  }
};

class MinimumEffortPath {
 private:
  static constexpr int dirs[4][2] = {
      {-1, 0},
      {1, 0},
      {0, 1},
      {0, -1},
  };

 public:
  MinimumEffortPath(/* args */) {}
  ~MinimumEffortPath() {}

  // 1.二分查找
  int minimumEffortPath_1(vector<vector<int>> heights) {
    int m = heights.size();
    int n = heights[0].size();
    int left = 0, right = 999999, ans = 0;
    while (left <= right) {
      int mid = (left + right) / 2;
      queue<pair<int, int>> q;  // 二元组存储坐标位置
      q.emplace(0, 0);
      vector<int> seen(m * n);  // 记录是否已经访问过
      seen[0] = 1;
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = x + dirs[i][0];
          int ny = y + dirs[i][1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] &&
              abs(heights[x][y] - heights[nx][ny]) <= mid) {
            q.emplace(nx, ny);
            seen[nx * n + ny] = 1;
          }
        }
      }
      if (seen[m * n - 1]) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

  // 2. 并查集
  int minimumEffortPath_2(vector<vector<int>> heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; i++) {
        int id = i * n + j;
        if (i > 0) {
          edges.emplace_back(id - n, id,
                             abs(heights[i][j] - heights[i - 1][j]));
        }
        if (j > 0) {
          edges.emplace_back(id - n, id,
                             abs(heights[i][j] - heights[i][j - 1]));
        }
      }
    }
    sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
      auto&& [x1, y1, d1] = e1;
      auto&& [x2, y2, d2] = e2;
      return d1 < d2;
    });

    UnionFind uf(m * n);
    int ans = 0;
    for (const auto [x, y, d] : edges) {
      uf.unite(x, y);
      if (uf.connected(0, m * n - 1)) {
        ans = d;
        break;
      }
    }
    return ans;
  }

  // 3. dijkstra算法变种
  int minimumEffortPath_3(vector<vector<int>> heights) {
    int m = heights.size();
    int n = heights[0].size();
    auto tupleCmp = [](const auto& e1, const auto& e2) {
      auto&& [x1, y1, d1] = e1;
      auto&& [x2, y2, d2] = e2;
      return d1 < d2;
    };
    // 定义优先队列
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   decltype(tupleCmp)>
        q(tupleCmp);
    q.emplace(0, 0, 0);

    vector<int> dist(m * n, INT_MAX);
    dist[0] = 0;
    vector<int> seen(m * n);

    while (!q.empty()) {
      auto [x, y, d] = q.top();
      q.pop();
      int id = x * n + y;
      if (seen[id]) {
        continue;
      }
      if (x == m - 1 && y == n - 1) {
        break;
      }
      seen[id] = 1;
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            max(d, abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
          dist[nx * n + ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
          q.emplace(nx, ny, dist[nx * n + ny]);
        }
      }
    }
    return dist[m * n - 1];
  }
};
