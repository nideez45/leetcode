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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            cur = cur->next;
            len++;
        }
        int i=0;
        cur = head;
        while(i<len/2){
            cur = cur->next;
            i++;
        }
        return cur;
    }
};