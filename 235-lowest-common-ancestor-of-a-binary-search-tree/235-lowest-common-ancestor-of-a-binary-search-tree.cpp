/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lca(TreeNode* root,int p,int q){
      
        if((root->val >= p && root->val <= q) || (root->val>=q && root->val <= p)) return root;
        
        if(root->val > p && root->val > q){
            return lca(root->left,p,q);
        }
        else{
            return lca(root->right,p,q);
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p->val,q->val);
    }
};