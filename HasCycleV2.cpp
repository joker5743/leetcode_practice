// 141. 环形链表

#include <unordered_set>

#include "data_structure.h"
using namespace std;

class HasCycleV2 {
 public:
  // 方法一：哈希表统计
  ListNode *detectCycle_1(ListNode *head) {
    unordered_set<ListNode *> visited;
    while (head != nullptr) {
      if (!visited.count(head)) {
        return head;
      }
      visited.insert(head);
      head = head->next;
    }
    return nullptr;
  }

  // 方法二：快慢指针
  ListNode *detectCycle_2(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};