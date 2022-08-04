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
    map<pair<TreeNode*,int>,int> dp;
    // either take or dont take
    
    // concept - dynamic programming
    // either take at this value or skip
    
    
    int rec(TreeNode* root,int take){
        // base case
        if(root == NULL) return 0;
        
        if(dp.find({root,take}) != dp.end()) return dp[{root,take}];
        
        int ans = 0;
        if(take){
            ans = root->val+rec(root->right,0)+rec(root->left,0);
            ans = max(ans,rec(root->right,1)+rec(root->left,1));
        }
        else{
            ans = rec(root->left,1)+rec(root->right,1);
        }
        return dp[{root,take}] = ans;
        
    }
    
    
    int rob(TreeNode* root) {
        return max(rec(root,0),rec(root,1));
    }
};