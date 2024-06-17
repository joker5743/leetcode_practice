// 215. 数组中第K大的元素

#include <iostream>
#include <random>
#include <vector>
using namespace std;

class FindKthLargest {
 private:
  /* data */
 public:
  // 快速排序
  int findKthLargest_1(vector<int>& nums, int k) {
    // return quicksort_1(nums, 0, nums.size() - 1, nums.size() - k);
    return quicksort_2(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int quicksort_1(vector<int>& nums, int l, int r, int k) {
    int q = randomPartition(nums, l, r);
    if (q == k) {
      return nums[q];
    } else {
      return q < k ? quicksort_1(nums, q + 1, r, k)
                   : quicksort_1(nums, l, q - 1, k);
    }
  }

  int randomPartition(vector<int>& nums, int l, int r) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(l, r);

    int pivot = dist(gen);
    swap(nums[pivot], nums[r]);
    return partition_1(nums, l, r);
  }

  int partition_1(vector<int>& nums, int l, int r) {
    int x = nums[r], j = l - 1;
    for (int i = l; i < r; i++) {
      if (nums[i] <= x) {
        swap(nums[++j], nums[i]);
      }
    }
    swap(nums[j + 1], nums[r]);
    return j + 1;
  }

  // 双指针快排
  int quicksort_2(vector<int>& nums, int l, int r, int k) {
    if (l == r) return nums[k];

    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j) {
      do {
        i++;
      } while (nums[i] < partition);

      do {
        j--;
      } while (nums[j] > partition);

      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }

    if (k <= j) {
      return quicksort_2(nums, l, j, k);
    } else {
      return quicksort_2(nums, j + 1, r, k);
    }
  }

  // 堆排
  int findKthLargest_2(vector<int>& nums, int k) {
    int heapsize = nums.size();
    buildMaxheap(nums, heapsize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--) {
      swap(nums[0], nums[i]);
      heapsize--;
      maxHeapify(nums, 0, heapsize);
    }
    return nums[0];
  }

  void maxHeapify(vector<int>& a, int i, int heapsize) {
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;
    if (l < heapsize && a[l] > a[largest]) {
      largest = l;
    }
    if (r < heapsize && a[r] > a[largest]) {
      largest = r;
    }

    if (largest != i) {
      swap(a[i], a[largest]);
      maxHeapify(a, largest, heapsize);
    }
  }

  void buildMaxheap(vector<int>& a, int heapsize) {
    for (int i = heapsize / 2 - 1; i >= 0; i--) {
      maxHeapify(a, i, heapsize);
    }
  }
};