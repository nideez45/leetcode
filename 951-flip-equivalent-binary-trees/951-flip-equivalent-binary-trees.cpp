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
    
    bool find(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL && root2==NULL) return true;
        if(root1 == NULL && root2!=NULL) return false;
        if(root1 != NULL && root2==NULL) return false;
        if(root1->val == root2->val){
            int val1 = root1->left == NULL ? 0 : root1->left->val;
            int val2 = root1->right == NULL ? 0 : root1->right->val;
            int val3 = root2->left == NULL ? 0 : root2->left->val;
            int val4 = root2->right == NULL ? 0 : root2->right->val;
            if(val1 == val3 && val2 == val4){
                return find(root1->left,root2->left) && find(root1->right,root2->right);
            }
            else if(val1 == val4 && val2 == val3){
                return find(root1->left,root2->right) && find(root1->right,root2->left);
            }
            else return false;
        }
        else{
            return false;
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return find(root1,root2);
    }
};