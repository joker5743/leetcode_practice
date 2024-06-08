// 141. 环形链表

#include "data_structure.h"
#include <unordered_set>
using namespace std;

class HasCycleV1
{
public:
    // 方法一：哈希表统计
    bool hasCycle_1(ListNode *head)
    {
        unordered_set<ListNode *> seen;
        while (head != nullptr)
        {
            if (seen.count(head))
            {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }

    // 方法二：快慢指针
    bool hasCycle_2(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};