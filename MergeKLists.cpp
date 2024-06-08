// 23. 合并K个升序链表

#include"data_structure.h"
#include<queue>

class MergeKLists{
    public:
        // 方法一：基于合并两个有序链表，循环执行。时间复杂度O(K^2*N),空间复杂度O(1)
        ListNode* mergeKLists_1(vector<ListNode*>& lists) {
            ListNode *ans = nullptr;
            for (size_t i = 0; i < lists.size(); i++)
            {
                ans = mergeTwoLists(ans, lists[i]);
            }
            return ans;
        }

        // 方法二：基于分治，两两一组合并，最后合并成完整的一个链表。
        ListNode* mergeKLists_2(vector<ListNode*>& lists) {
            return mergeKLists_2(lists, 0, lists.size() - 1);
        }

        ListNode* mergeKLists_2(vector<ListNode*>& lists, int l, int r) {
            if(l == r)
                return lists[l];

            if(l > r)
                return nullptr;

            int mid = l + (r - l) / 2;
            // int mid = (l + r) >> 1;
            return mergeTwoLists(mergeKLists_2(lists, l, mid), mergeKLists_2(lists, mid + 1, r));
        }

        // 方法三：利用优先队列
        struct comp
        {
            bool operator()(const ListNode* a, const ListNode* b){
                return a->val > b->val;
            }
        };
        

        ListNode* mergeKLists_3(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, comp> q;
            for(auto node: lists){
                if(node){
                    q.push(node);
                }
            }

            ListNode *dummyHead = new ListNode(0);
            ListNode *tail = dummyHead;
            while(!q.empty()){
                ListNode *node = q.top();
                q.pop();
                tail->next = node;
                tail = tail->next;
                if(node->next){
                    q.push(node->next);
                }
            }
            return dummyHead->next;
        }

        ListNode * mergeTwoLists(ListNode* head1, ListNode* head2){
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
};