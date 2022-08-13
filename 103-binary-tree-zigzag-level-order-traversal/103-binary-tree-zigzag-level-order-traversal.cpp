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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   
        queue<TreeNode*> q;
        vector<vector<int>> ans1;
        if(root == NULL) return ans1;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> ans;
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                ans.push_back(cur->val);
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            if(level%2) reverse(ans.begin(),ans.end());
            level++;
            ans1.push_back(ans);
        }
        
        return ans1;
    }
};