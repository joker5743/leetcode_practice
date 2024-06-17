// 1615. 最大网络秩
#include <vector>
using namespace std;

class MaximalNetworkRank {
 public:
  // 1. 穷举
  int maximalNetworkRank_1(int n, vector<vector<int>>& roads) {
    vector<vector<bool>> connect(n, vector<bool>(n, false));
    vector<int> degree(n, 0);
    for (auto&& i : roads) {
      connect[i[0]][i[1]] = true;
      connect[i[1]][i[0]] = true;
      degree[i[0]] += 1;
      degree[i[1]] += 1;
    }

    int max_rank = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
        max_rank = max(max_rank, rank);
      }
    }
    return max_rank;
  }
  // 2. 贪心，求最大和次大城市网络秩。
  int maximalNetworkRank_2(int n, vector<vector<int>>& roads) {
    vector<vector<bool>> connect(n, vector<bool>(n, false));
    vector<int> degree(n, 0);
    for (auto&& i : roads) {
      connect[i[0]][i[1]] = true;
      connect[i[1]][i[0]] = true;
      degree[i[0]] += 1;
      degree[i[1]] += 1;
    }
    int first = -1, second = -2;
    vector<int> first_area, second_area;
    for (int i = 0; i < degree.size(); i++) {
      if (degree[i] > first) {
        second = first;
        second_area = first_area;
        first = degree[i];
        first_area.clear();
        first_area.emplace_back(i);
      } else if (degree[i] == first) {
        first_area.emplace_back(i);
      } else if (degree[i] > second) {
        second = degree[i];
        second_area.clear();
        second_area.emplace_back(i);
      } else if (degree[i] == second) {
        second_area.emplace_back(i);
      }
    }

    if (first_area.size() == 1) {
      int u = first_area[0];
      for (int v : second_area) {
        if (!connect[u][v]) return first + second;
      }
      return first + second - 1;
    } else {
      int m = roads.size();
      if (first_area.size() * (first_area.size() - 1) / 2 > m) {
        return first * 2;
      }
      for (int u : first_area) {
        for (int v : first_area) {
          if (u != v && !connect[u][v]) return first * 2;
        }
      }
      return first * 2 - 1;
    }
  }
};