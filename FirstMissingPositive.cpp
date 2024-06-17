// 41. 缺失的第一个正数

#include <vector>
using namespace std;

class FirstMissingPositive {
 public:
  // 方法一：数组哈希+负数标记
  int firstMissingPositive_1(vector<int>& nums) {
    int n = nums.size();
    for (auto& num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }
    // 用负数标记符合范围且已经经过哈希映射的元素
    for (int i = 0; i < n; i++) {
      int num = abs(nums[i]);
      if (num <= n) {
        nums[num - 1] = -abs(nums[num - 1]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }

  // 方法二：数组哈希+交换
  int firstMissingPositive_2(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        swap(nums[nums[i] - 1], nums[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};