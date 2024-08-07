// 64. 最小路径和

#include <vector>
using namespace std;

class MinPathSum {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (rows == 0 || cols == 0) return 0;

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = grid[0][0];
    for (size_t i = 1; i < rows; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (size_t j = 1; j < cols; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (size_t i = 1; i < rows; i++) {
      for (size_t j = 1; j < cols; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[rows - 1][cols - 1];
  }
};