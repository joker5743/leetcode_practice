#include "function.h"

void printListNode(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

ListNode *createNodeList(vector<int> &array) {
  ListNode *dummyHead = new ListNode(-1);
  if (array.size() == 0) return nullptr;

  ListNode *cur = dummyHead;
  for (int i = 0; i < array.size(); i++) {
    cur->next = new ListNode(array[i]);
    cur = cur->next;
  }
  return dummyHead->next;
}