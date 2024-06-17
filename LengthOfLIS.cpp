// 300. 最长递增子序列

#include <vector>
using namespace std;

class LengthOfLIS {
 private:
  /* data */
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int maxdist = 0;
    vector<int> dp(n, 0);

    for (size_t i = 0; i < n; i++) {
      dp[i] = 1;
      for (size_t j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxdist = max(maxdist, dp[i]);
    }
    return maxdist;
  }
};