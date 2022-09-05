/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int sm = 0;
            if(l1!=NULL){
                sm+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sm+=l2->val;
                l2 = l2->next;
            }
            sm+=carry;
            carry = sm/10;
            sm%=10;
            cur->val = sm;
            if(l1!=NULL || l2!=NULL){
                cur->next = new ListNode();
                cur = cur->next;
            }
            else{
                if(carry){
                    cur->next = new ListNode(carry,NULL);
                }
                else cur->next = NULL;
            }
        }
        return head;
    }
};