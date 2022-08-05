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
    // Recursive
    ListNode* new_head = NULL;
    void rev(ListNode* node){
        if(node->next == NULL){
            new_head = node;
            return;
        }
        rev(node->next);
        node->next->next = node;
        node->next = NULL;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        // edge case
        if(head == NULL) return NULL;
        rev(head);
        return new_head;
    }
};