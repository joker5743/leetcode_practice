// 5. 最长回文子串

#include <string>
#include <utility>
#include <vector>
using namespace std;

class LongestPalindrome {
 public:
  // 方法一：动态规划
  string longestPalindrome_1(string s) {
    int n = s.size();
    if (n < 2) return s;

    int maxLen = 1;
    int begin = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (size_t i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    for (int L = 2; L <= n; L++) {
      for (int i = 0; i < n; i++) {
        int j = i + L - 1;
        if (j >= n) {
          break;
        }

        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          if (j - i < 3) {
            dp[i][j] =
                true;  // 字符s[i,j]整个的长度小于4，且两端的字符一致，因此整段字符是回文字符
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // 更新最大长度
        if (dp[i][j] && j - i + 1 > maxLen) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }
    return s.substr(begin, maxLen);
  }

  // 方法二：中心扩散法
  string longestPalindrome_2(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
      auto p1 = expandAroundCenter(s, i, i);
      auto p2 = expandAroundCenter(s, i, i + 1);
      if (p1.second - p1.first > end - start) {
        start = p1.first;
        end = p1.second;
      }
      if (p2.second - p2.first > end - start) {
        start = p2.first;
        end = p2.second;
      }
    }
    return s.substr(start, end - start + 1);
  }

  pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return {left + 1, right - 1};
  }
};