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
    
    map<TreeNode*,int> mp;
    
    int cnt(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int score = 0;
        if(root->val == 1) score++;
        score+=cnt(root->left);
        score+=cnt(root->right);
        mp[root] = score;
        return score;
    }
    
    void traverse(TreeNode* root){
        if(root->left != NULL){
            if(mp[root->left] == 0){
                root->left = NULL;
            }
            else{
                traverse(root->left);
            }
        }
        if(root->right!=NULL){
            if(mp[root->right] == 0){
                root->right = NULL;
            }
            else{
                traverse(root->right);
            }
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        cnt(root);
        if(mp[root] == 0) return NULL;
        traverse(root);
        return root;
    }
};