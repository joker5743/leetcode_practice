// 24. 两两交换链表中的节点。

#include "data_structure.h"
using namespace std;

class SwapPairs {
 public:
  // 方法一：递归
  ListNode* swapPairs_1(ListNode* head) {
    if (head->next == nullptr || head == nullptr) return head;

    ListNode* newHead = head->next;
    head->next = swapPairs_1(newHead->next);
    newHead->next = head;
    return newHead;
  }

  // 方法二：迭代
  ListNode* swapPairs_2(ListNode* head) {
    ListNode* dummyHead = new ListNode(-1, head);
    ListNode* temp = dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr) {
      ListNode* first = temp->next;
      ListNode* second = temp->next->next;
      temp->next = second;
      first->next = second->next;
      second->next = first;
      temp = first;
    }
    return dummyHead->next;
  }
};