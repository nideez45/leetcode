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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;
        
        while(cur!=NULL){
             //cout<<cur->val<<" "<<prev->val<<'\n';
            if(cur->next!=NULL && cur->val == cur->next->val){
                int temp = cur->val;
                while(cur!=NULL && cur->val == temp) cur = cur->next;
            }
            else{
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
        }
        prev->next = NULL;
        return dummy->next;
    }
};