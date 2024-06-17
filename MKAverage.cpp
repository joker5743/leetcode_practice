// 1825. 求出 MK 平均值
#include <queue>
#include <set>
#include <vector>
using namespace std;

class MKAverage {
 private:
  int m, k;
  queue<int> q;
  multiset<int> s1, s2, s3;
  long long sum2;

 public:
  MKAverage(int m, int k) {
    this->m = m;
    this->k = k;
    this->sum2 = 0;
  }

  void addElement(int num) {
    q.push(num);
    if (q.size() <= m) {
      s2.insert(num);
      sum2 += num;
      if (q.size() == m) {
        while (s1.size() < k) {
          s1.insert(*s2.begin());
          sum2 -= *s2.begin();
          s2.erase(s2.begin());
        }
        while (s3.size() < k) {
          s3.insert(*s2.rbegin());
          sum2 -= *s2.rbegin();
          s2.erase(prev(s2.end()));
        }
      }
      return;
    }
  }

  int calculateMKAverage() {
    if (q.size() < m) return -1;
    return sum2 / (m - 2 * k);
  }
};
