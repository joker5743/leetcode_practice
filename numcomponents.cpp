// 817. 链表组件

#include <unordered_set>
#include <vector>

#include "data_structure.h"

using namespace std;

class NumComponents {
 public:
  int numcomponents(ListNode *head, vector<int> &nums) {
    unordered_set<int> num_set;
    for (auto &i : nums) {
      num_set.emplace(i);
    }

    bool in_set = false;
    int res = 0;
    while (head != nullptr) {
      if (num_set.count(head->val)) {
        if (!in_set) {
          in_set = true;
          res++;
        }
      } else {
        in_set = false;
      }
      head = head->next;
    }
    return res;
  }
};