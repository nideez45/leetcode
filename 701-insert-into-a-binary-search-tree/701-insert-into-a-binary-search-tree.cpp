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
    
    
    // always insertion will take place at leaf node
    
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur!=NULL){
            prev = cur;
            if(cur->val > target) cur = cur->left;
            else cur = cur->right;
        }
        // if the bst was empty
        if(prev == NULL){
            TreeNode* ans = new TreeNode(target);
            return ans;
        }
        else{
            // have to find whether should insert in left or right
            if(prev->val>target){
                prev->left = new TreeNode(target);
            }
            else{
                prev->right = new TreeNode(target);
            }
            return root;
        }
    }
};