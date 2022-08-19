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
    
    int find(TreeNode* root){
        
        if(root->left == NULL && root->right == NULL) return 1;
        int temp = 1e9;
        if(root->left != NULL) temp = min(temp,find(root->left));
        if(root->right != NULL) temp = min(temp,find(root->right));
        if(temp == 1e9) temp = 0;
        return 1+temp;
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return find(root);
    }
};