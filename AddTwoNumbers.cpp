// 2. 两数相加

#include"data_structure.h"
using namespace std;

class AddTwoNumbers{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = nullptr;
            ListNode *tail = nullptr;
            int carry = 0;

            while(l1 != nullptr || l2 != nullptr){
                int n1 = l1 ? l1->val : 0;
                int n2 = l2 ? l2->val : 0;
                int sum = n1 + n2 + carry;
                if(!head){
                    head = new ListNode(sum % 10);
                    tail = head;
                }
                else{
                    tail->next = new ListNode(sum % 10);
                    tail = tail->next;
                }
                carry = sum / 10;
                if(l1){
                    l1 = l1->next;
                }
                if(l2){
                    l2 = l2->next;
                }
            }
            if(carry){
                tail->next = new ListNode(carry);
            }
            return head;
        }
};