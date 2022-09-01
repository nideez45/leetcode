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
    
    vector<int> inorder;
    
    void traverse(TreeNode* root){
        if(root == NULL) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    
    TreeNode* bbst(vector<int>&inorder,int l,int r){
        if(l > r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode();
        root->val = inorder[mid];
        root->left = bbst(inorder,l,mid-1);
        root->right = bbst(inorder,mid+1,r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        int n = inorder.size();
        
        return bbst(inorder,0,n-1);
    }
};