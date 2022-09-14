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
    
    int count(TreeNode* root,int mask){
        if(root == NULL) return 0;
        mask^=(1<<(root->val));
        int score = 0;
        if(__builtin_popcount(mask) <= 1 && root->left == NULL && root->right == NULL) score = 1;
        return score+count(root->left,mask)+count(root->right,mask);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        return count(root,0);
    }
};