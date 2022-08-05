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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        
        // edge cases
        if(head == NULL || head->next == NULL) return head;
        
        // head of new list will be next of original head
        ListNode* ans = head->next;
        
        // to join previous group of 2 with current
        ListNode* prev = NULL;
        
        while(cur!=NULL && cur->next != NULL){
            ListNode* temp = cur->next->next;
            if(prev!=NULL){
                prev->next = cur->next;
            }
            cur->next->next = cur;
            cur->next = temp;
            prev = cur;
            cur = cur->next;
        }
        return ans;
    }
};