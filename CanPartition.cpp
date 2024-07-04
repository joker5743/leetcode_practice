// 416. 分割等和子集

#include <numeric>
#include <vector>
using namespace std;

class CanPartition {
 public:
  bool canPartition_1(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maxNum = *max_element(nums.begin(), nums.end());

    if (sum % 2 != 0) return false;

    int target = sum / 2;
    if (maxNum > target) return false;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (size_t i = 0; i < n; i++) {
      dp[i][0] = true;
    }
    dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
      int num = nums[i];
      for (int j = 0; j <= target; j++) {
        if (j >= num) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n - 1][target];
  }

  // 上述方法的空间复杂度优化，结果只与i-1行有关，可以用单独变量代替整个dp数组。
  bool canPartition_2(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maxNum = *max_element(nums.begin(), nums.end());

    if (sum % 2 != 0) return false;

    int target = sum / 2;
    if (maxNum > target) return false;

    vector<int> dp(target + 1, 0);
    dp[0] = true;
    for (size_t i = 0; i < n; i++) {
      int num = nums[i];
      // 倒序遍历，保持新的一轮结果没有因为由于本次的更新影响
      for (int j = target; j >= num; j--) {
        dp[j] = dp[j] || dp[j - num];
      }
    }
    return dp[target];
  }
};