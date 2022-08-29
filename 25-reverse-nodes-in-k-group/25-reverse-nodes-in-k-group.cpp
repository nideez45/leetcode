class Solution 
{
public:
    
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        
        ListNode* cur = first;
        while(cur!=last){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* node = head;
        for(int i=0;i<k;i++){
            if(!node){
                return head;
            }
            node = node->next;
        }
        ListNode* newhead = reverse(head,node);
        head->next = reverseKGroup(node,k);
        return newhead;
    }
};