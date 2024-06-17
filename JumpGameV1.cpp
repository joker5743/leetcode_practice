// 55. 跳跃游戏I

#include <vector>
using namespace std;

class JumpGameV1 {
 public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int most = 0;
    for (int i = 0; i < n; i++) {
      if (i <= most) {
        most = max(most, i + nums[i]);
        if (most >= n - 1) {
          return true;
        }
      }
    }
    return false;
  }
};