// 19. 删除链表的倒数第N个节点

#include "data_structure.h"
using namespace std;

class RemoveNthFromEnd
{
public:
    // 方法一：统计整体长度
    ListNode *removeNthFromEnd_1(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1, head);
        int len = getLength(head);
        ListNode *p = dummy;
        for (int i = 1; i < len - n + 1; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    int getLength(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }

    // 方法二：双指针
    ListNode *removeNthFromEnd_2(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        ListNode *q = dummy;
        for (int i = 0; i < n; i++)
        {
            q = q->next;
        }
        while (q->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};