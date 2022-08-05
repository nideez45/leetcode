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
    
    // can use level order traversal
    
    Node* connect(Node* root) {
        // edge case
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            
            // processing current level
            int sz = q.size();
            vector<Node*> v;
            for(int i=0;i<sz;i++){
                v.push_back(q.front());
                q.pop();
            }
            // populating next pointers
            for(int i=1;i<sz;i++){
                v[i-1]->next = v[i];
            }
            v[sz-1]->next = NULL;
            
            // adding next level
            for(int i=0;i<sz;i++){
                if(v[i]->left != NULL){
                    q.push(v[i]->left);
                }
                if(v[i]->right != NULL){
                    q.push(v[i]->right);
                }
            }
        }
        return root;
    }
};