// 88. 合并两个有序数组

#include <algorithm>
#include <vector>

using namespace std;

class MergeTwoVectors {
 public:
  // 1. 算法库直接调用，快排
  void merge_1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = 0; i < n; i++) {
      nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums2.end());
  }

  // 2. 头部双指针
  void merge_2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = 0, p2 = 0;
    int sorted[m + n];
    int cur;

    while (p1 < m || p2 < n) {
      if (p1 == m) {
        cur = nums2[p2++];
      } else if (p2 = n) {
        cur = nums2[p1++];
      } else if (nums1[p1] < nums2[p2]) {
        cur = nums1[p1++];
      } else {
        cur = nums2[p2++];
      }
      sorted[p1 + p2 - 1] = cur;
    }

    for (int i = 0; i < m + n; i++) {
      nums1[i] = sorted[i];
    }
  }

  // 3. 双指针，从尾遍历
  void merge_3(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = m - 1, p2 = n - 1;
    int tail = m + n - 1;
    int cur;
    while (p1 >= 0 || p2 >= 0) {
      if (p1 == -1) {
        cur = nums2[p2--];
      } else if (p2 == -1) {
        cur = nums1[p1--];
      } else if (nums1[p1] > nums2[p2]) {
        cur = nums1[p1--];
      } else {
        cur = nums2[p2--];
      }
      nums1[tail--] = cur;
    }
  }
};