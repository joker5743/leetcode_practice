// 3111. 覆盖所有点的最少矩形数目

#include <algorithm>
#include <vector>

using namespace std;

class MinRectanglesToCoverPoints {
 public:
  // 基于贪心算法
  int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    sort(points.begin(), points.end());
    int res = 0, bound = -1;
    for (auto& p : points) {
      if (p[0] > bound) {
        bound = p[0] + w;
        res++;
      }
    }
    return res;
  }
};