// 72. 编辑距离

#include <string>
#include <vector>
using namespace std;

class MinDistance {
 public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) {
      dp[i][0] = i;
    }
    for (int i = 0; i <= len2; i++) {
      dp[0][i] = i;
    }

    for (size_t i = 1; i <= len1; i++) {
      for (size_t j = 1; j <= len2; j++) {
        int add_1 = dp[i - 1][j] + 1;
        int add_2 = dp[i][j - 1] + 1;
        int edit =
            dp[i - 1][j - 1] + static_cast<int>(word1[i - 1] != word2[j - 1]);
        // 如果word1的第i-1个字母和word2的第j-1个字母不同，则进行编辑操作，否则不操作保持。
        dp[i][j] = min(add_1, min(add_2, edit));
      }
    }
    return dp[len1][len2];
  }
};