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
    
    vector<int> nums;
    
    TreeNode* construct(int l,int r){
        if(l>r) return NULL;
        
        TreeNode* node = new TreeNode(nums[(l+r)/2]);
        node->left = construct(l,(l+r)/2-1);
        node->right = construct((l+r)/2+1,r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& _nums) {
        nums = _nums;
        int n = nums.size();
        return construct(0,n-1);
    }
};