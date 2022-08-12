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
    int ans = 0;
    
    int rec(TreeNode* root,int target){
        if(root == NULL) return 0;
        
        int left = rec(root->left,root->val);
        int right = rec(root->right,root->val);
        //cout<<root->val<<" "<<left<<" "<<right<<" "<<target<<'\n';
        if(target == root->val){
            ans = max(ans,1+left+right);
            return 1+max(left,right);
        }
        else{
            ans = max(ans,1+left+right);
            return 0;
        }
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        rec(root,root->val);
        return ans-1;
    }
};