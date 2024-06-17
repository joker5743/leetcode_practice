// 56. 合并区间

#include <vector>
using namespace std;

class Merge {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return {};
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merge;
    for (auto& i : intervals) {
      int l = i[0], r = i[1];
      if (!merge.size() || merge.back()[1] < l) {
        merge.push_back({l, r});
      } else {
        merge.back()[1] = max(merge.back()[1], r);
      }
    }
    return merge;
  }
};