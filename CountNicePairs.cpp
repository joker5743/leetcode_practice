// 1814. 统计一个数组中好对子的数目

#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
class CountNicePairs {
 public:
  // 转化f[i] == num[i] - rev(num[i])相同的值有多少对。
  int countNiceParis(vector<int> &nums) {
    int ans = 0;
    const int MOD = int(1e9 + 7);
    unordered_map<int, int> h;
    for (auto &&i : nums) {
      int temp = i, j = 0;
      while (temp > 0) {
        j = j * 10 + temp % 10;
        temp /= 10;
      }
      ans =
          (ans + h[i - j]) %
          MOD;  // h[i-j]表示f[x]的值为i-j，且可以与当前的num[i]配对的对数。此对数随着遍历到新的索引不断更新。
      h[i - j]++;
    }
    return ans;
  }
};