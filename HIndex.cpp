// 274. H 指数

#include <algorithm>
#include <vector>

using namespace std;

class HIndex {
 public:
  // 1.直接排序，按照定义完成
  int hIndex_1(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int h = 0, i = citations.size() - 1;
    while (i >= 0 && citations[i] > h) {
      h++;
      i--;
    }
  }

  // 2. 使用额外空间，记录各个引用次数的论文篇数，避免排序
  int hIndex_2(vector<int>& citations) {
    int n = citations.size(), tot = 0;
    vector<int> counter(n + 1, 0);

    for (int i = 0; i < n; i++) {
      // 引用次数大于所有论文篇数，则计数到引用次数为总论文发表数中去
      if (citations[i] >= n) {
        counter[n]++;
      } else {
        counter[citations[i]]++;
      }
    }

    for (int i = n; i >= 0; i--) {
      tot += counter[i];
      if (tot >= i) {
        return i;
      }
    }
    return 0;
  }

  // 3. 二分查找，目标值所在区间为[0, n]，n为文章总数
  int hIndex_3(vector<int>& citations) {
    int left = 0, right = citations.size();
    int mid, cnt;  // 分别是二分查找定位的索引位置，根据不同mid统计得到的h值

    while (left < right) {
      mid = (left + right + 1) >> 1;
      // 假设h的值是mid的条件下，符合条件的实际h（cnt）范围
      cnt = 0;
      for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= mid) {
          cnt++;
        }
      }

      if (cnt >= mid) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};