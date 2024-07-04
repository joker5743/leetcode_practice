// 62. 不同路径

#include <vector>
using namespace std;

class UniquePaths {
 public:
  // 方法一：动态规划
  int uniquePaths_1(int m, int n) {
    // init dp arrays
    vector<vector<int>> dp(m, vector<int>(n));
    for (size_t i = 0; i < m; i++) {
      dp[i][0] = 1;
    }
    for (size_t j = 0; j < n; j++) {
      dp[0][j] = 1;
    }

    for (size_t i = 1; i < m; i++) {
      for (size_t j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }

  // 空间复杂度优化版本
  int uniquePaths_1plus(int m, int n) {
    vector<int> dp(n, 0);
    for (size_t i = 1; i < m; i++) {
      for (size_t j = 1; j < n; j++) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }

  // 方法二：数学理论，组合数C(m-1+n-1, m-1)
  int uniquePaths_2(int m, int n) {
    long long ans = 1;
    for (int x = n, y = 1; y < m; x++, y++) {
      ans = ans * x / y;
    }
    return ans;
  }
};