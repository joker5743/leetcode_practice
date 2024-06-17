// 234. 回文链表

#include <vector>

#include "data_structure.h"
using namespace std;

class IsPalindrome {
 public:
  // # 方法一：直接复制链表的内容到数组，用双指针遍历。
  bool isPalindrome_1(ListNode *head) {
    vector<int> val;
    while (head != nullptr) {
      val.emplace_back(head->val);
      head = head->next;
    }
    for (int i = 0, j = val.size() - 1; i > j; i++, j--) {
      if (val[i] != val[j]) return false;
    }
    return true;
  }

  // 方法二：递归
  ListNode *frontPointer;
  bool isPalindrome_2(ListNode *head) {
    frontPointer = head;
    return recursivelycheck(head);
  }

  bool recursivelycheck(ListNode *currentNode) {
    if (currentNode != nullptr) {
      if (!recursivelycheck(currentNode->next)) {
        return false;
      }
      if (currentNode->val != frontPointer->val) {
        return false;
      }
      frontPointer = frontPointer->next;
    }
    return false;
  }

  // 方法三：快慢指针定位链表中间位置 + 后半段反转链表比较（+二次反转复原）
  bool isPalindrome_3(ListNode *head) {
    if (head == nullptr) {
      return true;
    }

    ListNode *firstHalfEnd = endOfFirstHalf(head);
    ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

    bool res = true;
    ListNode *p1 = head;
    ListNode *p2 = secondHalfStart;
    while (res && p2 != nullptr) {
      if (p1->val != p2->val) {
        res = false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    // 二次翻转，恢复后半段链表顺序
    firstHalfEnd->next = reverseList(secondHalfStart);
    return res;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

  ListNode *endOfFirstHalf(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};