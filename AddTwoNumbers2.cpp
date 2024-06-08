// 445. 两数相加2

#include"data_structure.h"
#include<stack>
using namespace std;


class AddTwoNumbers2{
  public:
  // 利用栈的反序特性，从低位开始取出并计算
  ListNode*  AddTwoNumbers2_1(ListNode * l1, ListNode * l2){
    stack<int> s1, s2;
    while(l1){
      s1.push(l1->val);
      l1 = l1->next;
    }

    while(l2){
      s2.push(l2->val);
      l2 = l2->next;
    }

    int carry = 0;
    ListNode* ans = nullptr;

    while (!s1.empty() || !s2.empty() || carry != 0){
      int a = s1.empty() ? 0 : s1.top();
      int b = s2.empty() ? 0 : s2.top();
      // C++ stack的弹出操作pop()不返回栈顶元素，只执行删除操作。
      if(!s1.empty()) s1.pop();
      if(!s2.empty()) s2.pop();
      int cur = a + b + carry;
      carry = cur / 10;
      cur %= 10;
      auto curnode = new ListNode(cur);
      curnode->next = ans;
      ans = curnode;
    }
    return ans;
  }

  // 反转链表为基础的直接相加
  ListNode*  AddTwoNumbers2_2(ListNode * l1, ListNode * l2){
    l1 = reverse_list(l1);
    l2 = reverse_list(l2);
    auto re_l3 = addTwo(l1, l2);
    return reverse_list(re_l3);
  }

  ListNode* reverse_list(ListNode *head){
    ListNode *prev = nullptr, *cur = head;
    while (cur)
    {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
  return prev;
  }

  ListNode* addTwo(ListNode *l1, ListNode *l2){
    auto dummy = new ListNode();
    auto cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
      if(l1) carry += l1->val;
      if(l2) carry += l2->val;
      cur->next = new ListNode(carry % 10);
      cur = cur->next;
      carry /= 10;
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next;
    }
    return dummy->next;
  }
};