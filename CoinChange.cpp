// 322. 零钱对换

#include <vector>
using namespace std;

class CoinChange {
 private:
  vector<int> count;

 public:
  // 方法一：记忆化搜索
  int coinChange_1(vector<int>& coins, int amount) {
    if (amount < 1) return 0;

    count.resize(amount);
    return dp(coins, amount);
  }

  int dp(vector<int>& coins, int rem) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (count[rem - 1] != 0) return count[rem - 1];

    int Min = INT_MAX;
    for (int coin : coins) {
      int res = dp(coins, rem - coin);
      if (res >= 0 && res < Min) Min = res + 1;
    }
    count[rem - 1] = Min == INT_MAX ? -1 : Min;
    return count[rem - 1];
  }

  // 方法二：动态规划
  int coinChange_2(vector<int>& coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] >= 0) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
    return dp[amount] == Max ? -1 : dp[amount];
  }
};