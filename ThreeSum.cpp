// 15. 三数之和

#include <vector>
using namespace std;

class ThreeSum {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int first = 0; first < n; first++) {
      // 第一个数的遍历
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      // 第二三个数采用双指针遍历
      int third = n - 1;
      int target = -nums[first];
      for (int second = first + 1; second < n; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1]) continue;

        while (second < third && nums[second] + nums[third] > target) {
          third--;
        }
        if (second == third) break;
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};