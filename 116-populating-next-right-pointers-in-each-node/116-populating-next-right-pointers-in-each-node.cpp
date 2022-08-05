/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    // constant space
    // we only need start node of each level if we have already populated the next
    // right pointers in that level
    // node->left->next = node->right
    // if node->next != NULL , node->right->next = node->next=>left
    
    Node* connect(Node* root) {
        Node* temp = root;
        while(temp != NULL){
            Node* start = temp;
            temp = start->left;
            if(temp!=NULL){
                while(start != NULL){
                    start->left->next = start->right;
                    if(start->next != NULL){
                        start->right->next = start->next->left;
                    }
                    start = start->next;
                }
            }
        }
        return root;
    }
};