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
    ListNode* swapNodes(ListNode* head, int k) {
        // first find length of list
        int len = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            len++;
            cur = cur->next;
        }
        
        // finding positions to swap
        int left = k;
        int right = len-k+1;
        if(left>right){
            swap(left,right);
        }
        
        // if both are same, directly return
        if(left == right) return head;
        
        // swapping
        ListNode* temp;
        int cnt = 0;
        cur = head;
        while(cur!=NULL){
            cnt++;
            if(cnt == left){
                temp = cur;
            }
            if(cnt == right){
                swap(cur->val,temp->val);
            }
            cur = cur->next;
        }
        
        return head;
    }
};