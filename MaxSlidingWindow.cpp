// 239. 滑动窗口最大值

#include <deque>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class MaxSlidingWindow {
 public:
  // 方法一：使用优先队列模拟滑窗并获取最大值
  vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
      pq.emplace(nums[i], i);
    }

    vector<int> ans = {pq.top().first};
    for (int i = k; i < n; i++) {
      pq.emplace(nums[i], i);
      while (pq.top().second <= i - k) {
        pq.pop();
      }
      ans.push_back(pq.top().first);
    }
    return ans;
  }

  // 方法二：基于1的队列优化，单调队列（相对方法三更为理解）
  vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[i] >= nums[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    vector<int> ans = {nums[dq.front()]};
    for (int i = k; i < n; i++) {
      while (!dq.empty() && nums[i] >= nums[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
      while (dq.front() <= i - k) {
        dq.pop_front();
      }
      ans.push_back(nums[dq.front()]);
    }
    return ans;
  }

  // 方法三：稀疏表，分组前后缀最大和
  vector<int> maxSlidingWindow_3(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixMax(n), suffixMax(n);

    for (int i = 0; i < n; i++) {
      if (i % k == 0) {
        prefixMax[i] = nums[i];
      } else {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1 || (i + 1) % k == 0) {
        suffixMax[i] = nums[i];
      } else {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
      }
    }

    vector<int> ans;
    for (int i = 0; i < n - k; i++) {
      ans.push_back(max(prefixMax[i + k - 1], suffixMax[i]));
    }
    return ans;
  }
};