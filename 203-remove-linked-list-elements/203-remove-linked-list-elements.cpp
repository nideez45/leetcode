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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = dummy->next;
        while(cur!=NULL){
            if(cur->val == val){
                ListNode* temp = cur->next;
                delete cur;
                prev->next = temp;
                cur = temp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};