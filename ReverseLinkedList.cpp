// 206. 反转链表

#include "data_structure.h"

class RevisedLinkedList {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};