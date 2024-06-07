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

        ListNode * Merge(ListNode* head1, ListNode* head2){
            ListNode *dummyHead = new ListNode(0);
            ListNode *temp = dummyHead;
            while(head1 && head2){
                if(head1->val < head2->val){
                    temp->next = head1;
                    head1 = head1->next;
                }
                else{
                    temp->next = head2;
                    head2 = head2->next;
                }
                temp = temp->next;
            }
            if(head1)
                temp->next = head1;
            else if(head2)
                temp->next = head2;
            
            return dummyHead->next;
        }

        // 自底向上
        ListNode* sortList_2(ListNode* head){
            if(head == nullptr)
                return head;

            int length = 0;
            ListNode *node = head;
            while(node){
                length++;
                node = node->next;
            }

            ListNode *dummyHead = new ListNode(0, head);
            for (int subLength = 1; subLength < length; subLength <<=1)
            {
                ListNode *prev = dummyHead, *curr = dummyHead->next;
                while(curr){
                    ListNode *head1 = curr;
                    for(int i = 1; i < subLength && curr->next != nullptr; i++){
                        curr = curr->next;
                    }
                    ListNode *head2 = curr->next;
                    curr->next = nullptr;
                    curr = head2;
                    for(int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++){
                        curr = curr->next;
                    }
                    ListNode *next = nullptr;
                    if(curr){
                        next = curr->next;
                        curr->next = nullptr;
                    }
                    ListNode* merged = Merge(head1, head2);
                    prev->next = merged;
                    while (prev->next != nullptr)
                    {
                        prev = prev->next;
                    }
                    curr = next;
                }
            }
            return dummyHead->next;
        }

};