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
    
    int target;
    vector<int> path;
    vector<vector<int>> ans;
    
    void rec(TreeNode* root,int sum){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->val);
            if(sum+root->val == target){
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        rec(root->left,sum+root->val);
        rec(root->right,sum+root->val);
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        rec(root,0);
        return ans;
    }
};