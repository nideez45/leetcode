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
    void reorderList(ListNode* head) {
        if(head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // need to reverse from slow->next
        ListNode* cur = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
       
        cur = head;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            if(prev == NULL) return;
            ListNode* temp1 = prev->next;
            prev->next = temp;
            prev = temp1;
            cur = temp;
        }
    }
};