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
    int ans = -1e9;
    int find(TreeNode* root){
        if(root == NULL) return 0;
        
        int mxleft = find(root->left);
        int mxright = find(root->right);
        ans = max(ans,root->val+mxleft);
        ans = max(ans,root->val+mxright);
        ans = max(ans,root->val+mxleft+mxright);
        return max({0,root->val,root->val+mxleft,root->val+mxright});
    }
    
    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
};