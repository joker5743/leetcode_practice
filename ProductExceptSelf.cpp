// 238. 除自身以外数组的乘积

#include <vector>
using namespace std;

class ProductExceptSelf {
 public:
  // 方法一：每个位置的左右两侧乘积，用列表存储。类似于接雨水的方法一。
  vector<int> productExceptSelf_1(vector<int>& nums) {
    int length = nums.size();

    vector<int> left(length, 1);
    vector<int> right(length, 1);
    vector<int> ans(length, 1);

    left[0] = 1;
    for (int i = 1; i < length; i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }

    right[length - 1] = 1;
    for (int i = length - 2; i >= 0; i--) {
      right[i] = nums[i + 1] * right[i + 1];
    }

    for (int i = 0; i < length; i++) {
      ans[i] = left[i] * right[i];
    }
    return ans;
  }

  // 方法二：基于方法一，优化空间复杂度。把用于存储左侧累乘的数组用结果数组ans来放置，右侧数组则用一个变量随着反向遍历不断累乘。
  vector<int> productExceptSelf_2(vector<int>& nums) {
    int length = nums.size();
    vector<int> ans(length, 1);

    for (int i = 1; i < length; i++) {
      ans[i] = nums[i - 1] * ans[i - 1];
    }

    int R = 1;
    for (int i = length - 1; i >= 0; i--) {
      ans[i] = ans[i] * R;
      R *= nums[i];
    }
    return ans;
  }
};