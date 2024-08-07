// 2961. 双模幂运算

#include <vector>
using namespace std;

class DoublePowWithMod {
 public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ans;
    for (int i = 0; i < variables.size(); i++) {
      auto& v = variables[i];
      if (pow_mod(pow_mod(v[0], v[1], 10), v[2], v[3]) == target) {
        ans.push_back(i);
      }
    }
    return ans;
  }

  // 快速幂可参考leetcode第50题，这里是带取余的mod版本
  int pow_mod(int x, int y, int mod) {
    int res = 1;
    while (y) {
      if (y & 1) {
        res = res * x % mod;
      }

      x = x * x % mod;
      y >>= 1;
    }
    return res;
  }
};