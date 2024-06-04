// 148. 排序链表

#include"data_structure.h"
using namespace std;

class SortList{
    public:
        /* 
        时间复杂度要求O(N*logN),符合要求的排序方法有归并排序、快速排序、堆排序，快排最坏复杂度是O(N^2)。
        故采用归并排序，分为自顶向下和自底向上两种方式。
         */

        // 自顶向下
        ListNode* sortList_1(ListNode* head){
            return sortList_1(head, nullptr);
        }

        ListNode* sortList_1(ListNode* head, ListNode* tail){
            if(head == nullptr) return nullptr;

            if(head->next == tail){
                head->next = nullptr;
                return head;
            }

            // 定位链表的中间位置
            ListNode *slow = head, *fast = head;
            while(fast != tail){
                slow = slow->next;
                fast = fast->next;
                if(fast != tail){
                    fast = fast->next;
                }
            }
            ListNode *mid = slow;
            return Merge(sortList_1(head, mid), sortList_1(mid, tail));
        }

        // 自底向上
        ListNode* sortList_2(ListNode* head){
            return nullptr;
        }

        // 合并两个有序链表
        ListNode* Merge(ListNode *l1, ListNode *l2){
            ListNode *dummyHead = new ListNode(0);
            ListNode *temp = dummyHead;
            while (l1 && l2)
            {
                if(l1->val < l2->val){
                    temp->next = l1;
                    l1 = l1->next;
                }
                else{
                    temp->next = l2;
                    l2 = l2->next;
                }
            }

            temp->next = l1 == nullptr ? l2 : l1;
            return dummyHead->next;
        }
};