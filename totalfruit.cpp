// 904. 水果成篮

#include <unordered_map>
#include <vector>

using namespace std;

class TotalFruit {
 public:
  int totalfruit(vector<int> fruits) {
    int n = fruits.size();
    unordered_map<int, int> cnt;

    int left = 0, ans = 0;
    for (int right = 0; right < n; right++) {
      cnt[fruits[right]]++;
      while (cnt.size() > 2) {
        auto it = cnt.find(fruits[left]);
        --it->second;
        if (it->second == 0) {
          cnt.erase(it);
        }
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};