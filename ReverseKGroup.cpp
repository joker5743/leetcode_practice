// 25. k个一组翻转链表

#include "data_structure.h"
#include <utility>
using namespace std;

class ReverseKGroup
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;

        while (head)
        {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                    return hair->next;
            }
            ListNode *nex = tail->next;
            pair<ListNode *, ListNode *> sublist = myReverse(head, tail);
            head = sublist.first;
            tail = sublist.second;
            pre->next = head;
            tail->next = nex;

            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }

    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *prev = tail->next; // prev指向的是翻转后的head前一个节点，所以是在tail之后的位置
        ListNode *p = head;
        while (prev != tail)
        {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return make_pair(tail, head);
    }
};