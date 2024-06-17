// 731. 我的日程安排表 II

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto &[l, r] : overlaps) {
      if (l < end && start < r) {
        cout << "预约失败！" << endl;
        return false;
      }
    }

    for (auto &[l, r] : booked) {
      if (l < end && start < r)
        overlaps.emplace_back(max(l, start), min(end, r));
    }
    booked.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> booked;
  vector<pair<int, int>> overlaps;
};