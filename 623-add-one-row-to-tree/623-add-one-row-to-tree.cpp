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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        while(level<depth-1){
            int sz = q.size();
                for(int i=0;i<sz;i++){
                    auto temp = q.front();
                    q.pop();
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right != NULL) q.push(temp->right);
                }
                level++;
        }
        while(!q.empty()){
            TreeNode*temp = q.front()->left;
            q.front()->left = new TreeNode(val);
            q.front()->left->left = temp;
            temp = q.front()->right;
            q.front()->right = new TreeNode(val);
            q.front()->right->right = temp;
            q.pop();
        }
        return root;
    }
};