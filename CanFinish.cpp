// 207. 课程表

#include <queue>
#include <vector>
using namespace std;

class CanFinish {
 private:
  vector<vector<int>> edges;

  vector<bool> visited;  // 节点是否被访问过
  bool valid;  // 是否有环这种不合理的结构（拓扑排序要求没有节点）

  vector<int> indeg;  // 节点的入度

 public:
  bool canFinish_dfs(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto &info : prerequisites) {
      edges[info[0]].push_back(info[1]);
    }
    for (int i = 0; i < numCourses && valid; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    return valid;
  }

  /*
  0. 未访问
  1. 正在访问中（子节点没有访问完）
  2. 访问完毕
  */
  void dfs(int u) {
    visited[u] = 1;
    for (int v : edges[u]) {
      if (visited[v] == 0) {
        dfs(v);
        if (!valid) {
          return;
        }
      } else if (visited[v] == 1) {
        valid = false;
        return;
      }
    }
    // 子节点访问完毕，该节点才算访问完毕，而不是访问中得状态。
    visited[u] = 2;
  }

  bool canFinish_bfs(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    indeg.resize(numCourses);
    for (const auto &info : prerequisites) {
      // 记录拓扑关系信息
      edges[info[1]].push_back(info[0]);
      // 记录入度信息
      indeg[info[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indeg[i] == 0) q.push(i);
    }

    int visited_times = 0;
    while (!q.empty()) {
      ++visited_times;
      int u = q.front();
      q.pop();
      for (const int v : edges[u]) {
        --indeg[v];
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
    }
    return visited_times == numCourses;
  }
};