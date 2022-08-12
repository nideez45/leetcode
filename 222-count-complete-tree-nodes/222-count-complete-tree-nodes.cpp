/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool exists(int pos,int depth,TreeNode* root){
        
        TreeNode* cur = root;
        for(int i=0;i<depth;i++){
            int bit = depth-i-1;
            if((pos&(1<<bit))){
                cur = cur->right;
            }
            else cur = cur->left;
        }
        return cur!=NULL;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        TreeNode* cur = root;
        while(cur->left != NULL){
            depth++;
            cur = cur->left;
        }
        int lo = 0;
        int hi = (1<<depth)-1;
        int ans;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(exists(mid,depth,root)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return (1<<depth) + ans;
    }
};