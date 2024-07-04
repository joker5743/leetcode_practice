// 152. 乘积最大子数组

#include <vector>
using namespace std;

class MaxProduct {
 public:
  // 方法一：动态规划，但是考虑政府性质的2重迭代版本
  int maxProduct_1(vector<int> &nums) {
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); i++) {
      maxF[i] = max(max(maxF[i - 1] * nums[i], minF[i - 1] * nums[i]), nums[i]);
      minF[i] = min(min(maxF[i - 1] * nums[i], minF[i - 1] * nums[i]), nums[i]);
    }
    return *max_element(maxF.begin(), maxF.end());
  }

  // 方法二：对方法一的空间复杂度进一步优化版本
  int maxProduct_2(vector<int> &nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int mx = maxF, mn = minF;
      maxF = max(max(mx * nums[i], mn * nums[i]), nums[i]);
      minF = min(min(mx * nums[i], mn * nums[i]), nums[i]);
      ans = max(ans, maxF);
    }
    return ans;
  }
};