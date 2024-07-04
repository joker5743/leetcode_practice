// 75 颜色分类（荷兰国旗问题）

#include <vector>
using namespace std;

class SortColors {
 public:
  // 方法一：单指针遍历
  void sortColors_1(vector<int>& nums) {
    int n = nums.size();
    int ptr = 0;
    // 将所有值为0的元素交换到数组最前方
    for (size_t i = 0; i < n; i++) {
      if (nums[i] == 0) {
        swap(nums[ptr++], nums[i]);
      }
    }

    for (size_t i = ptr; i < n; i++) {
      if (nums[i] == 1) {
        swap(nums[ptr++], nums[i]);
      }
    }
  }

  // 方法二：双指针（0,1）。
  void sortColors_2(vector<int>& nums) {
    int n = nums.size();
    int p0 = 0, p1 = 0;
    for (size_t i = 0; i < n; i++) {
      if (nums[i] == 1) {
        swap(nums[i], nums[p1]);
      }
      if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        if (p0 < p1) {
          /* p0,p1都是正向遍历，分别是0区域的右边界和1区域的右边界。
          如果有p0 <
          p1，则p0位置其实是数字1，交换完之后还需要i和p1（指向的是2）再次交换 */
          swap(nums[i], nums[p1]);
        }
        p0++;
        p1++;
      }
    }
  }

  // 方法三：双指针（0,2）
  void sortColors_3(vector<int>& nums) {
    int n = nums.size();
    int p0 = 0, p2 = n - 1;
    for (int i = 0; i <= p2; i++) {
      while (i <= p2 && nums[i] == 2) {
        swap(nums[i], nums[p2]);
        p2--;
      }

      if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        p0++;
      }
    }
  }
};