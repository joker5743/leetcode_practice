// 169. 多数元素

#include <unordered_map>
#include <vector>
using namespace std;

class MajorityElement {
 public:
  // 方法一：哈希表
  int majorityElement_1(vector<int>& nums) {
    unordered_map<int, int> counts;
    int major = 0, cnt = 0;
    for (auto& num : nums) {
      ++counts[num];
      if (counts[num] > cnt) {
        major = num;
        cnt = counts[num];
      }
    }
    return major;
  }

  // 方法二：排序
  int majorityElement_2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }

  // 方法三：分治
  int majorityElement_3(vector<int>& nums) {
    return majority_element_rec(nums, 0, nums.size() - 1);
  }

  int count_in_range(vector<int>& nums, int target, int lo, int hi) {
    int count = 0;
    for (int i = lo; i <= hi; ++i) {
      if (nums[i] == target) {
        ++count;
      }
    }
    return count;
  }

  int majority_element_rec(vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
      return nums[lo];
    }
    int mid = (lo + hi) / 2;
    int left_majority = majority_element_rec(nums, lo, mid);
    int right_majority = majority_element_rec(nums, mid + 1, hi);
    if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2) {
      return left_majority;
    }
    if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2) {
      return right_majority;
    }
    return -1;
  }

  // 方法四：Boyer-Moore 投票算法
  int majorityElement_4(vector<int>& nums) {
    int candidate = -1;
    int count = 0;
    for (const int num : nums) {
      if (count == 0) {
        candidate = num;
      }
      count += (num == candidate) ? 1 : -1;
    }
    return candidate;
  }
};