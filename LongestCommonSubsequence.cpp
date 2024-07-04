// 1143. 最长公共子序列

#include <string>
#include <vector>
using namespace std;

class LongestCommonSubsequence {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 1; i <= m; i++) {
      char c1 = text1[i - 1];
      for (size_t j = 1; j <= n; j++) {
        char c2 = text2[j - 1];
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};